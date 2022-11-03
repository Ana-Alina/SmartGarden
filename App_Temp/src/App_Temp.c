#include<App_Temp_external.h>
#include<App_Temp_internal.h>
#include<App_main_external.h>
#include<App_Stubs_external.h>
#include<AppDatatypes.h>

tApp_Temp_HistoryType App_Temp_History[APP_CONFIG_NR_SENSORS] = {0};

static tApp_Temp_Main_CounterType App_Temp_Main_CounterStruct[APP_CONFIG_NR_SENSORS];

/**
 * @brief This variable is used to give a specific sensor state when sensor recives (TRUE) or not (FALSE) a temperature
 */
static bool Exec_Flag_Sensor[APP_CONFIG_NR_SENSORS];
static uint8 numberHistory;

tApp_Temp_SetTemperatureType result_SetTemperature;

/**
 * @brief Storing a group of constant variables whitch define the maximum value for a specific counter 
 */
const tApp_Temp_Main_Const_StructType App_Temp_Main_ConstStruct[APP_CONFIG_NR_SENSORS] =
{
    {
        APP_TEMP_MAX_COUNTER_5S,
        APP_TEMP_MAX_COUNTER_5S,
        APP_TEMP_MAX_COUNTER_10S,
        APP_TEMP_MAX_COUNTER_10M,
    },
    {
        APP_TEMP_MAX_COUNTER_10S,
        APP_TEMP_MAX_COUNTER_10S,
        APP_TEMP_MAX_COUNTER_20S,
        APP_TEMP_MAX_COUNTER_10M,
    }
};

extern void App_Temp_init(void)
{
    uint8 i = 0;
    
    for(i = 0; i < APP_CONFIG_NR_SENSORS; i++)
    {
        App_Temp_Main_Struct[i].sensor_status = 0;
        Exec_Flag_Sensor[i] = 0;

        App_Temp_Main_CounterStruct[i].history_sensor_counter = 0;
        numberHistory = 0;

        uint8 j = 0;
        for(j = 0; j < APP_TEMP_MAXLEN; j ++)
        {
            App_Temp_Main_Struct[i].temp_history[j].day = 0;
            App_Temp_Main_Struct[i].temp_history[j].Hour = 0;
            App_Temp_Main_Struct[i].temp_history[j].minutes = 0;
            App_Temp_Main_Struct[i].temp_history[j].month = 0;
            App_Temp_Main_Struct[i].temp_history[j].seconds = 0;
            App_Temp_Main_Struct[i].temp_history[j].temperature = 0;
            App_Temp_Main_Struct[i].temp_history[j].year = 0;
        }
    }
}

extern void App_Temp_main(void)
{
    uint8 i = 0;

    for(i = 0; i < APP_CONFIG_NR_SENSORS; ++i)
    {
        if(AppConfig_Garden[i].temperatureMonitoring == true)
        {
            switch(App_Temp_Main_Struct[i].sensor_status)
            {
                case APP_TEMP_SENSOR_WAITING:
                {
                    if(Exec_Flag_Sensor[i] == false)
                    {
                        if(App_Temp_Main_CounterStruct[i].Waiting_Counter == App_Temp_Main_ConstStruct[i].State_Waiting_Max_Counter)
                        {
                            App_Temp_Main_Struct[i].sensor_status = APP_TEMP_SENSOR_IDLE;
                        }
                        else
                        {
                            App_Temp_Main_CounterStruct[i].Waiting_Counter++;
                        }
                    }
                    else
                    {
                        App_Temp_Main_CounterStruct[i].Waiting_Counter = 0;
                        App_Temp_Main_Struct[i].sensor_status = APP_TEMP_SENSOR_STATUS_OK;
                        Exec_Flag_Sensor[i] = false;
                    }

                    break;
                }

                case APP_TEMP_SENSOR_IDLE:
                {
                    if(Exec_Flag_Sensor[i] == true)
                    {
                        App_Temp_Main_Struct[i].sensor_status = APP_TEMP_SENSOR_WAKING;
                        Exec_Flag_Sensor[i] = false;
                    }

                    break;               
                }

                case APP_TEMP_SENSOR_WAKING:
                {
                    if(Exec_Flag_Sensor[i] == true)
                    {
                        App_Temp_Main_CounterStruct[i].Waking_NewTemp_Counter++;
                        Exec_Flag_Sensor[i] = false;
                    }

                    if(App_Temp_Main_CounterStruct[i].Waking_Counter == App_Temp_Main_ConstStruct[i].State_Waking_Max_Counter)
                    {
                        if(App_Temp_Main_CounterStruct[i].Waking_NewTemp_Counter == APP_TEMP_MAX_NEWTEMP)
                        {
                            App_Temp_Main_Struct[i].sensor_status = APP_TEMP_SENSOR_STATUS_OK;
                        }
                        else
                        {
                            App_Temp_Main_Struct[i].sensor_status = APP_TEMP_SENSOR_NOK;
                        }
                    }
                    else
                    {
                        App_Temp_Main_CounterStruct[i].Waking_Counter++;
                    }

                    break;        
                }

                case APP_TEMP_SENSOR_STATUS_OK:
                {
                    if(Exec_Flag_Sensor[i] == false)
                    {
                        if(App_Temp_Main_CounterStruct[i].Counter== App_Temp_Main_ConstStruct[i].State_Ok_Max_Counter)
                        {
                            App_Temp_Main_Struct[i].sensor_status = APP_TEMP_SENSOR_WAITING;
                        }
                        else
                        {
                            App_Temp_Main_CounterStruct[i].Counter ++;
                        }
                    }
                    else
                    {
                        Exec_Flag_Sensor[i] = false;
                        App_Temp_Main_CounterStruct[i].Counter = 0;
                    }

                    break;
                }

                case APP_TEMP_SENSOR_NOK:
                default:
                {
                    App_Temp_Main_CounterStruct[i].Counter = 0;
                    App_Temp_Main_CounterStruct[i].Waiting_Counter = 0;
                    App_Temp_Main_CounterStruct[i].Waking_Counter = 0;
                    App_Temp_Main_CounterStruct[i].Waking_NewTemp_Counter = 0;
                    break;
                }
            };
            // Check SensorStatus is ok
            // Save temperature, date and time in temp_history
            // Check temperature value using gradient functionality
            if(App_Temp_Main_Struct[i].sensor_status == APP_TEMP_SENSOR_STATUS_OK)
            {
                
                if((result_SetTemperature == APP_TEMP_VALID_TEMPERATURE_VALUE) && (App_Temp_Main_CounterStruct[i].history_sensor_counter == App_Temp_Main_ConstStruct[i].History_Max_Counter))
                {
                    // Shift all the values to the right and increment numberHistory with 1 position from 5
                    if(numberHistory < APP_TEMP_MAXLEN)
                    {
                        numberHistory ++;
                    }
                    uint8 j = 0;
                    for(j = numberHistory - 1; j >= 1; j --)
                    {
                        App_Temp_Main_Struct[i].temp_history[j] = App_Temp_Main_Struct[i].temp_history[j - 1];
                    }

                    App_Temp_Main_Struct[i].temp_history[0].temperature = App_Temp_Main_Struct[i].current_temp;
                    App_Time_GetCurrentDate(&App_Temp_Main_Struct[i].temp_history[0].year, &App_Temp_Main_Struct[i].temp_history[0].month, &App_Temp_Main_Struct[i].temp_history[0].day);
                    App_Time_GetCurrentTime(&App_Temp_Main_Struct[i].temp_history[0].Hour, &App_Temp_Main_Struct[i].temp_history[0].minutes, &App_Temp_Main_Struct[i].temp_history[0].seconds);

                    App_Temp_Main_CounterStruct[i].history_sensor_counter = 0;
        
                }
                else
                {
                    App_Temp_Main_CounterStruct[i].history_sensor_counter ++;
                }
            }        
        }
    }       
}

tApp_Temp_SetTemperatureType App_Temp_SetTemperature(float32 temp, uint8 sensorID)
{
    tApp_Temp_SetTemperatureType result;
    static float32 previous_temp0 = 150;
    static float32 previous_temp1 = 150;

    if(AppConfig_Garden[sensorID].temperatureMonitoring == true)
    {
        if(sensorID < APP_CONFIG_NR_SENSORS)
        {
            if((temp - previous_temp0) >= 0)
            {
                if(((temp - previous_temp0) < 1) || (previous_temp0 == 150))
                {
                    result_SetTemperature = APP_TEMP_VALID_TEMPERATURE_VALUE;
                    Exec_Flag_Sensor[sensorID] = true;   
                }
                else
                {
                    result_SetTemperature = APP_TEMP_INVALID_TEMPERATURE_VALUE;
                    App_Temp_Main_Struct[sensorID].sensor_status = APP_TEMP_SENSOR_NOK;
                }
            }
            else
            {
                if(((temp - previous_temp0) > -1) || (previous_temp0 == 150))
                {
                    result_SetTemperature = APP_TEMP_VALID_TEMPERATURE_VALUE;
                    Exec_Flag_Sensor[sensorID] = true;
                }
                else
                {
                    result_SetTemperature = APP_TEMP_INVALID_TEMPERATURE_VALUE;
                    App_Temp_Main_Struct[sensorID].sensor_status = APP_TEMP_SENSOR_NOK;
                }
            }
                
            App_Temp_Main_Struct[sensorID].current_temp = temp;
            previous_temp0 = temp;
        }
        else
        {
            result_SetTemperature = APP_TEMP_SENSOR_ID_INVALID;
        }

    }
    return result_SetTemperature;
}

void App_Temp_GetTemperature(float32 *temp, uint8 sensorID)
{
    if(AppConfig_Garden[sensorID].temperatureMonitoring == true)
    {
        if(sensorID < APP_CONFIG_NR_SENSORS)
        {
            *temp = App_Temp_Main_Struct[sensorID].current_temp;
        }
        else 
        {
            printf("\n Sensor ID invalid! \n");
        }
    }
}

void App_Temp_GetSensorStatus(tApp_Temp_SensorStatusType *sensorState, uint8 sensorID)
{
    if(AppConfig_Garden[sensorID].temperatureMonitoring == true)
    {
        if(sensorID < APP_CONFIG_NR_SENSORS)
        {
            *sensorState = App_Temp_Main_Struct[sensorID].sensor_status;
        }
        else 
        {
            printf("\n Sensor ID invalid! \n");
        }
    }
}

void App_Temp_GetTempHistory(tApp_Temp_HistoryType *history, uint8 sensorID, tApp_Temp_HistoryPositionType historyPosition)
{
    if(AppConfig_Garden[sensorID].temperatureMonitoring == true)
    {
        if(sensorID < APP_CONFIG_NR_SENSORS)
        {
            *history = App_Temp_Main_Struct[sensorID].temp_history[historyPosition];
        }
        else 
        {
            printf("\n Sensor ID invalid! \n");
        }
    }
}

void App_Temp_GetNumberTempHistory(uint8 *Number_History, uint8 sensorID)
{
    if(AppConfig_Garden[sensorID].temperatureMonitoring == true)
    {
        if(sensorID < APP_CONFIG_NR_SENSORS)
        {
            *Number_History =  numberHistory; 
        }
        else
        {
            printf("\n Sensor ID invalid! \n");
        }
    }
}




#ifndef APP_TEMP_EXTERNAL_H
#define APP_TEMP_EXTERNAL_H

#include<stdio.h>
#include<AppDatatypes.h>
#include<App_main_external.h>
#include<App_Temp_internal.h>

typedef enum{
    APP_TEMP_SENSOR_STATUS_OK = 0x00,
    APP_TEMP_SENSOR_WAKING	 = 0x01,
    APP_TEMP_SENSOR_WAITING	= 0x02,
    APP_TEMP_SENSOR_IDLE = 0x03,
    APP_TEMP_SENSOR_NOK	= 0x04
}tApp_Temp_SensorStatusType;

typedef enum{
    APP_TEMP_SENSOR_ID_INVALID,
    APP_TEMP_SENSOR_ID_OK,
    APP_TEMP_INVALID_TEMPERATURE_VALUE,
    APP_TEMP_VALID_TEMPERATURE_VALUE
}tApp_Temp_SetTemperatureType;

typedef struct
{
    float32 temperature;
    uint16 year;
    uint8 month;
    uint8 day;
    uint8 Hour;
    uint8 minutes;
    uint8 seconds;

}tApp_Temp_HistoryType;

typedef enum{
    APP_TEMP_HISTORY_POS0 = 0x00,
    APP_TEMP_HISTORY_POS1 = 0x01,
    APP_TEMP_HISTORY_POS2 = 0x02,
    APP_TEMP_HISTORY_POS3 = 0x03,
    APP_TEMP_HISTORY_POS4 = 0x04,
}tApp_Temp_HistoryPositionType;

/**
 * @brief Groups variables sensor status and current temperature
 * @param sensor_status used for storing different status for sensors\n
 * @param current_temp used for storing current temperature\n\n
 */
typedef struct
{
    tApp_Temp_SensorStatusType sensor_status;
    float32 current_temp;
    tApp_Temp_HistoryType temp_history[APP_TEMP_MAXLEN];

}tApp_Temp_Main_StructType;


/**
 * @brief The main function of App_Temp
 * @return void
 */
extern void App_Temp_main(void);

/**
 * @brief Initializing the status and the status of the sensor for each garden
 * @return void
 */
extern void App_Temp_init(void);

/**
 * @brief Set a temperature in temp variable for sensor sensorID
 * @param temp used for setting the current temparature\n
 * @param sensorID used for setting the ID of the sensor\n\n
 */
extern tApp_Temp_SetTemperatureType App_Temp_SetTemperature(float32 temp, uint8 sensorID);

/**
 * @brief This variable describes the types of status that the sensor can have during use\n\n
 */
extern tApp_Temp_SensorStatusType App_Temp_SensorState[APP_CONFIG_NR_SENSORS];

/**
 * @brief This variable describes the types of status and the temperature that the sensor can have\n\n
 */
tApp_Temp_Main_StructType App_Temp_Main_Struct[APP_CONFIG_NR_SENSORS];

/**
 * @brief This variable describesthe history of temperature for a specific sensor\n
 * 
 */
extern tApp_Temp_HistoryType App_Temp_History[APP_CONFIG_NR_SENSORS];

extern tApp_Temp_HistoryPositionType App_Temp_HistoryPosition[APP_CONFIG_NR_SENSORS];

/**
 * @brief Store a recieved temperature in temp variable for sensor sensorID
 * @param temp [out] used for providing the current temparature\n
 * @param sensorID [in] used for getting the ID of the sensor\n\n
 */
extern void App_Temp_GetTemperature(float32 *temp, uint8 sensorID);

/**
 * @brief Store a recived sensor state in sensorState variable for sensorID
 * @param sensorState [out] used for providing the curent sensor state\n
 * @param sensorID [in] used for getting the ID of the sensor\n\n
 */
extern void App_Temp_GetSensorStatus(tApp_Temp_SensorStatusType *sensorState, uint8 sensorID);

/**
 * @brief Store a recived temperature in history variable for sensorID
 * @param history [out] used for providing temperature history for a sensor\n
 * @param sensorID [in] used for getting the ID of the sensor\n\n
 * 
 */
extern void App_Temp_GetTempHistory(tApp_Temp_HistoryType *history, uint8 sensorID, tApp_Temp_HistoryPositionType historyPosition);

extern void App_Temp_GetNumberTempHistory(uint8 *Number_History, uint8 sensorID);

#endif


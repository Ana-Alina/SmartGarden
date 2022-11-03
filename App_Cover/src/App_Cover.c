#include <App_Cover_external.h>
#include <App_Cover_internal.h>
#include <App_main_external.h>
#include <App_Temp_external.h>
#include <App_Stubs_external.h>

static tAppCover_CoverPositionType App_Cover_Previous_CoverPosition[APP_CONFIG_NR_GARDENS];
tAppCover_CoverPositionType App_Cover_CoverPosition[APP_CONFIG_NR_GARDENS];
tAppCover_MovementType App_Cover_Movement[APP_CONFIG_NR_GARDENS];
tAppMotor_ErrorCodeType AppMotor_Error_Code[APP_CONFIG_NR_GARDENS];
tAppError_DefectsType AppError_Defects_Type[APP_CONFIG_NR_GARDENS];
    

extern void App_Cover_Init(void)
{
    uint8 i;

    for(i = 0; i < APP_CONFIG_NR_GARDENS; i++)
    {
        AppCover_sensorStatusGarden[i].sensorStatus = 0;
        AppCover_sensorStatusGarden[i].temp = 0;
        App_Cover_CoverPosition[i] = APP_COVER_COVER_OPEN;
    }
    
    coverCounter = 0;
    closedCounter = 0;
    movementAttempts = 0;
    STUB_GetErrorErrorCode = 0;
    STUB_SetDefectDefects = 0;
    
}

extern void App_Cover_Main(void)
{   
    static uint8 coverCounter;
    static uint8 movementAttempts;
    static uint16 closedCounter;
    tAppMotor_MotorStatusType motorStatus;
    bool result;

        if(coverCounter == MAX_COUNTER_COVER)
        {
            App_Temp_GetSensorStatus (&AppCover_sensorStatusGarden[0].sensorStatus, 0);
            App_Temp_GetSensorStatus (&AppCover_sensorStatusGarden[1].sensorStatus, 1);
            App_Temp_GetTemperature (&AppCover_sensorStatusGarden[0].temp, 0);
            App_Temp_GetTemperature (&AppCover_sensorStatusGarden[1].temp, 1);

            coverCounter = 0;
        }
        else
        {
            coverCounter++;
        }
       

    uint8 i = 0;

    for (i = 0; i < APP_CONFIG_NR_GARDENS; i++)
    {
        if(AppConfig_Garden[i].cover_motor == true)
        {
            App_Motor_GetMotorStatus(&motorStatus, i);
            switch(App_Cover_CoverPosition[i])
            {
                // State open
                // Check if the garden has cover and motor
                // Check if sensor status is OK and temperature is lower than MAX_TEMP_COVER
                // Check if the motor starts opening the cover
                // If all the checks have passed then we switch to the moving state
                case APP_COVER_COVER_OPEN:
                    if(AppConfig_Garden[i].cover_motor == true)
                    {
                        App_Temp_GetSensorStatus (&AppCover_sensorStatusGarden[i].sensorStatus, i);
                        App_Temp_GetTemperature (&AppCover_sensorStatusGarden[i].temp, i);

                        if ((AppCover_sensorStatusGarden[i].sensorStatus == APP_TEMP_SENSOR_STATUS_OK) && (AppCover_sensorStatusGarden[i].temp < MAX_TEMP_COVER))
                        {
                            result = App_Motor_StartOpeningCover(true, 0);

                            if (result == true)
                            {
                                App_Cover_Previous_CoverPosition[i] = App_Cover_CoverPosition[i];
                                App_Cover_CoverPosition[i] = APP_COVER_COVER_MOVING;
                            }
                        }
                        else
                        {
                            result = App_Motor_StartOpeningCover(false, 0);
                        }
                    }
                    break;
                // State moving
                // Check if motor status is FINISHED or ERROR
                // If the motor status is FINISHED and previous cover position is closed, then we switch to open state
                // If the motor status is FINISHED and previous cover position is open, then we switch to closed state
                // If the motor status is ERROR, we record the movement type inside a variable named App_Cover_Movement
                // The reason we do this is to know which state we should go back after error
                // Then we switch to error state
                case APP_COVER_COVER_MOVING:
                    if(motorStatus == APP_MOTOR_FINISHED)
                    {
                        if(App_Cover_Previous_CoverPosition[i] == APP_COVER_CLOSED)
                        {
                            App_Cover_Previous_CoverPosition[i] = App_Cover_CoverPosition[i];
                            App_Cover_CoverPosition[i] = APP_COVER_COVER_OPEN;
                        }
                        else if(App_Cover_Previous_CoverPosition[i] == APP_COVER_COVER_OPEN)
                        {
                            App_Cover_Previous_CoverPosition[i] = App_Cover_CoverPosition[i];
                            App_Cover_CoverPosition[i] = APP_COVER_CLOSED;
                        }
                    }
                    else if(motorStatus == APP_MOTOR_ERROR)
                    {
                        if(App_Cover_Previous_CoverPosition[i] == APP_COVER_CLOSED)
                        {
                            App_Cover_Movement[i] = APP_MOVE_CLOSING;
                        }
                        else if(App_Cover_Previous_CoverPosition[i] == APP_COVER_COVER_OPEN)
                        {
                            App_Cover_Movement[i] = APP_MOVE_OPENING;
                        }

                        App_Cover_Previous_CoverPosition[i] = App_Cover_CoverPosition[i];
                        App_Cover_CoverPosition[i] = APP_COVER_ERROR;
                    }
                    break;
                // State error
                // Check App_Cover_Movement whether it is in OPENING or CLOSING
                // If the cover is opening before 3 attempts then we switch to the open state
                // If the cover is not opening after 3 attempts then we get the motor error code and show the deffection type
                // If the cover is closing before 3 attempts then we switch to the closed state
                // If the cover is not closing after 3 attempts then we get the motor error code and show the deffection type
                case APP_COVER_ERROR:
                        if(App_Cover_Movement[i] == APP_MOVE_OPENING)
                        {
                            if(movementAttempts > 0)
                            {
                                App_Cover_Previous_CoverPosition[i] = App_Cover_CoverPosition[i];
                                App_Cover_CoverPosition[i] = APP_COVER_COVER_OPEN; 

                                movementAttempts--;
                            }
                            else
                            {
                                App_Motor_GetError(&AppMotor_Error_Code[i], i);

                                if(AppMotor_Error_Code[i] == APP_MOTOR_STATUS_OK)
                                {
                                    AppError_Defects_Type[i] = APP_ERROR_MOTOR_UNKNOWN_ERROR;
                                }
                                else if(AppMotor_Error_Code[i] == APP_MOTOR_BLOCKED_STATUS)
                                {
                                    AppError_Defects_Type[i] = APP_ERROR_MOTOR_BLOCKED;
                                }
                                else if(AppMotor_Error_Code[i] == APP_MOTOR_UNKNOWN_ERROR)
                                {
                                    AppError_Defects_Type[i] = APP_ERROR_MOTOR_UNKNOWN_ERROR;
                                }
                                else
                                {
                                    AppError_Defects_Type[i] = APP_ERROR_MOTOR_NOT_RESPONDING;
                                }

                                App_ErrorMngt_SetDefect(AppError_Defects_Type[i], true);
                                movementAttempts = 3;
                            }
                        }
                        else if(App_Cover_Movement[i] == APP_MOVE_CLOSING)
                        {
                            if(movementAttempts > 0)
                            {
                                App_Cover_Previous_CoverPosition[i] = App_Cover_CoverPosition[i];
                                App_Cover_CoverPosition[i] = APP_COVER_CLOSED;

                                movementAttempts--;
                            }
                            else
                            {                        
                                App_Motor_GetError(&AppMotor_Error_Code[i], i);
                                
                                if(AppMotor_Error_Code[i]== APP_MOTOR_STATUS_OK)
                                {
                                    AppError_Defects_Type[i] = APP_ERROR_MOTOR_UNKNOWN_ERROR;
                                }
                                else if(AppMotor_Error_Code[i] == APP_MOTOR_BLOCKED_STATUS)
                                {
                                    AppError_Defects_Type[i] = APP_ERROR_MOTOR_BLOCKED;
                                }
                                else if(AppMotor_Error_Code[i] == APP_MOTOR_UNKNOWN_ERROR)
                                {
                                    AppError_Defects_Type[i] = APP_ERROR_MOTOR_UNKNOWN_ERROR;
                                }
                                else
                                {
                                    AppError_Defects_Type[i] = APP_ERROR_MOTOR_NOT_RESPONDING;
                                }

                                App_ErrorMngt_SetDefect(AppError_Defects_Type[i], true);
                                movementAttempts = 3;
                            }
                        }
                        break;
                // State closed
                // Check if sensor status is OK and temperature is higher than MAX_TEMP_COVER_CLOSED for more than 1 minute
                // Check if the motor starts opening the cover
                // If all the checks have passed then we switch to the moving state
                case APP_COVER_CLOSED:
                    if ((AppCover_sensorStatusGarden[i].sensorStatus == APP_TEMP_SENSOR_STATUS_OK) && (AppCover_sensorStatusGarden[i].temp > MAX_TEMP_COVER_CLOSED))
                    {
                        if(closedCounter == MAX_COUNTER_COVER_CLOSED)
                        {
                            result = App_Motor_StartOpeningCover(true, 0);

                            if(result == true)
                            {
                                App_Cover_Previous_CoverPosition[i] = App_Cover_CoverPosition[i];
                                App_Cover_CoverPosition[i] = APP_COVER_COVER_MOVING;
                            }
                            
                            closedCounter = 0;
                        }
                        else
                        {
                            closedCounter ++;
                        }
                    }
                    break;
                default:
                {
                    closedCounter = 0;
                    coverCounter = 0;
                    movementAttempts = 3;
                    break;
                }
            }
        }  
    }
}


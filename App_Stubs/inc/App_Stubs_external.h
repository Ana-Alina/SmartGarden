#ifndef APP_STUBS_EXTERNAL_H
#define APP_STUBS_EXTERNAL_H

#include<stdio.h>
#include<AppDatatypes.h>
#include<App_main_external.h>
#include<App_Temp_external.h>


typedef enum
{
    APP_MOTOR_IDLE_STATUS = 0x00,
    APP_MOTOR_MOVING = 0x01,
    APP_MOTOR_FINISHED = 0x02,
    APP_MOTOR_ERROR = 0x03
}tAppMotor_MotorStatusType;

typedef enum
{
    APP_ERROR_MOTOR_BLOCKED = 0x12,
    APP_ERROR_MOTOR_UNKNOWN_ERROR = 0x33,
    APP_ERROR_MOTOR_NOT_RESPONDING = 0x45
}tAppError_DefectsType;

typedef enum
{
    APP_MOTOR_STATUS_OK = 0x00,
    APP_MOTOR_BLOCKED_STATUS = 0x01,
    APP_MOTOR_UNKNOWN_ERROR = 0x02,
    APP_MOTOR_MOTOR_NOT_RESPONDING = 0x03

}tAppMotor_ErrorCodeType;



/**
 * @brief The variable AppMotor_MotorStatus set an error that can occur as a result of the malfunction of the motor\n\n 
 */
extern tAppMotor_MotorStatusType AppMotor_MotorStatus[APP_CONFIG_NR_GARDENS];

/**
 * @brief Receive data to start opening the cover of a specific garden 
 * @retval TRUE request [in] used for recieving the request for opening the cover\n
 * @retval FALSE request [in] used for recieving the request for not opening the cover\n
 * @param garden [in] used for storing the ID of the garden that should be opened\n
 * @retval TRUE return the result if the garden shall start opening the cover\n
 * @retval FALSE return the result if the garden shall not start opening the cover\n\n
 */
extern bool App_Motor_StartOpeningCover(bool request, uint8 garden);

/**
 * @brief Set and receive the status of the motor for a specific garden  
 * @param motorstatus [out] used for setting a motor status\n
 * @param garden [in] used for setting the ID of the garden\n\n
 */
extern void App_Motor_GetMotorStatus(tAppMotor_MotorStatusType *motorstatus, uint8 garden);

/**
 * @brief Send a Mngt error and a bool status for it  
 * @param error [in] used for setting an error of the motor\n
 * @param garden [in] used for setting the ID of the garden\n\n
 */
extern void App_ErrorMngt_SetDefect(tAppError_DefectsType error, bool status);

/**
 * @brief Set and receive the error of the motor for a specific garden and count the numbers of errors 
 * @param error [out] used for setting an error code of the motor\n
 * @param garden [in] used for setting the ID of the garden\n\n
 */
extern void App_Motor_GetError(tAppMotor_ErrorCodeType *error, uint8 garden);

/**
 * @brief Store the current date
 * 
 * @param year [out] used for providing the current year\n
 * @param month [out] used for providing the current month\n
 * @param day [out] used for providing the current day\n\n
 */
extern void App_Time_GetCurrentDate(uint16 *year, uint8 *month, uint8 *day);

/**
 * @brief Store the current time
 * 
 * @param hour [out] used for providing the current hour\n
 * @param min [out] used for providing the current minutes\n
 * @param seconds [out] used for providing the current seconds\n\n
 */
extern void App_Time_GetCurrentTime(uint8 *hour, uint8 *min, uint8 *seconds);

extern void App_IrrigSystem_CheckSprinklerStatus(bool *sprinklerStatus, uint8 sprinklerID, uint8 gardenID);

extern void App_IrrigSystem_SetSprinklerStatus(bool *sprinkerStatus, uint8 sprinklerID, uint8 gardenID);


/**
 * @brief used for recieving the request for opening the cover
 */
bool STUB_StartOpeningCoverRequest;

/**
 * @brief used for storing the ID of the garden that should be opened
 */
uint8 STUB_StartOpeningCoverGarden;

/**
 * @brief bool used to return the result that indicates whether the garden will start opening or not 
 */
bool STUB_StartOpeningCoverResult;

/**
 * @brief variable used for setting a motor status from a set of predefined statuses
 */
tAppMotor_MotorStatusType STUB_GetMotorStatusMotorStatus;

/**
 * @brief used for setting the ID of the garden which need to be tested
 */
uint8 STUB_GetMotorStatusGarden;

/**
 * @brief used for settting an error of the motor from a set of predefined defects 
 */
tAppError_DefectsType STUB_SetDefectDefects;

/**
 * @brief used to specify if an error of the motor occured
 * @retval TRUE an error occured
 * @retval FALSE an error did not occured
 */
bool STUB_SetDefectStatus;

/**
 * @brief used for setting an error code of the motor from a set of predefined code errors
 */
tAppMotor_ErrorCodeType STUB_GetErrorErrorCode;

/**
 * @brief used for setting the ID of the garden
 */
uint8 STUB_GetErrorGarden;

/**
 * @brief used for counting the number of times an error has occured
 */
uint8 STUB_GetErrorErrorCounter;

uint16 STUB_Temp_History_year;
uint8 STUB_Temp_History_month;
uint8 STUB_Temp_History_day;
uint8 STUB_Temp_History_Hour;
uint8 STUB_Temp_History_minutes;
uint8 STUB_Temp_History_seconds;

bool STUB_Irrig_System_Check_Sprinkler_Status[25];
uint8 STUB_Irrig_System_Check_Sprinkler_ID;
uint8 STUB_Irrig_System_Check_Sprinkler_Garden;

bool STUB_Irrig_System_Set_Sprinkler_Status;
uint8 STUB_Irrig_System_Set_Sprinkler_ID;
uint8 STUB_Irrig_System_Set_Sprinkler_Garden;

#endif
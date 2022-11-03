#include<App_Stubs_external.h>
#include<App_Temp_external.h>
#include<App_Cover_external.h>
#include<App_Irrigation_external.h>
#include<AppDatatypes.h>

uint8 STUB_GetErrorErrorCounter;
bool STUB_StartOpeningCoverRequest;
uint8 STUB_StartOpeningCoverGarden;
bool STUB_StartOpeningCoverResult;
tAppMotor_MotorStatusType STUB_GetMotorStatusMotorStatus;
uint8 STUB_GetMotorStatusGarden;

tAppError_DefectsType STUB_SetDefectDefects;
bool STUB_SetDefectStatus;
tAppMotor_ErrorCodeType STUB_GetErrorErrorCode;
uint8 STUB_GetErrorGarden;

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

bool App_Motor_StartOpeningCover(bool request, uint8 garden)
{
    STUB_StartOpeningCoverRequest = request;
    STUB_StartOpeningCoverGarden = garden;

    return STUB_StartOpeningCoverResult;
};

extern void App_Motor_GetMotorStatus(tAppMotor_MotorStatusType *motorstatus, uint8 garden)
{
    *motorstatus = STUB_GetMotorStatusMotorStatus;
    STUB_GetMotorStatusGarden = garden;
}

extern void App_ErrorMngt_SetDefect(tAppError_DefectsType error, bool status)
{
    STUB_SetDefectDefects = error;
    STUB_SetDefectStatus = status;
}

extern void App_Motor_GetError(tAppMotor_ErrorCodeType *error, uint8 garden)
{
    *error = STUB_GetErrorErrorCode;
    STUB_GetErrorGarden = garden;
    STUB_GetErrorErrorCounter ++;
}

extern void App_Time_GetCurrentDate(uint16 *year, uint8 *month, uint8 *day)
{
    *year = STUB_Temp_History_year;
    *month = STUB_Temp_History_month;
    *day = STUB_Temp_History_day;
};

extern void App_Time_GetCurrentTime(uint8 *hour, uint8 *min, uint8 *seconds)
{
    *hour = STUB_Temp_History_Hour;
    *min = STUB_Temp_History_minutes;
    *seconds = STUB_Temp_History_seconds;
};

//Function that allows to check the status of a sprinkler ID.
extern void App_IrrigSystem_CheckSprinklerStatus(bool *sprinklerStatus, uint8 sprinklerID, uint8 gardenID)
{
    sprinklerID = STUB_Irrig_System_Check_Sprinkler_ID;
    gardenID = STUB_Irrig_System_Check_Sprinkler_Garden;
    sprinklerStatus[sprinklerID] = STUB_Irrig_System_Check_Sprinkler_Status[sprinklerID]; 
};

//Function that allows to set the status of a sprinkler ID.
extern void App_IrrigSystem_SetSprinklerStatus(bool *sprinkerStatus, uint8 sprinklerID, uint8 gardenID)
{
    STUB_Irrig_System_Set_Sprinkler_Status = *sprinkerStatus;
    STUB_Irrig_System_Set_Sprinkler_ID = sprinklerID;
    STUB_Irrig_System_Set_Sprinkler_Garden = gardenID;
};
#ifndef APP_TEMP_INTERNAL_H
#define APP_TEMP_INTERNAL_H

#include<AppDatatypes.h>

#define APP_TEMP_MAX_COUNTER_5S 500
#define APP_TEMP_MAX_COUNTER_10S 1000
#define APP_TEMP_MAX_COUNTER_20S 2000
#define APP_TEMP_MAX_NEWTEMP 5

#define APP_TEMP_MAXLEN 5
#define APP_TEMP_MAX_COUNTER_10M 60000

/**
 * @brief Storing a group of variables which define the order in which counters are defined
 */
typedef struct
{
    uint16 State_Ok_Max_Counter;
    uint16 State_Waking_Max_Counter;
    uint16 State_Waiting_Max_Counter;
    uint16 History_Max_Counter;
}tApp_Temp_Main_Const_StructType;

/**
 * @brief Counters for the time of reciving the temperature for the sensors which will help determine the sensor status
 */
typedef struct 
{
    uint16 Counter;
    uint16 Waiting_Counter;
    uint8 Waking_NewTemp_Counter;
    uint16 Waking_Counter;
    uint16 history_sensor_counter;
}tApp_Temp_Main_CounterType;

#endif
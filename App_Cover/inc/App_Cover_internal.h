#ifndef APP_COVER_INTERNAL_H
#define APP_COVER_INTERNAL_H
#include <App_Cover_external.h>
#include <App_main_external.h>
#include <App_Temp_external.h>
#include <App_Stubs_external.h>

/**
 * @brief This variable describes the counter for getting sensor status and temperature from every 10s
 */
uint8 coverCounter;

/**
 * @brief This variable describes the counter for closing the cover 
 */
uint16 closedCounter;

/**
 * @brief This variable describes how many attepts should the program have when it is in the error state before showing an error message
 * 
 */
uint8 movementAttempts;

/**
 * @brief Groups variables sensor status and temperature
 * @param sensorStatus for storing different status for sensors\n
 * @param temp used for storing current temperature\n\n
 */
typedef struct 
{
    tApp_Temp_SensorStatusType sensorStatus;
    float32 temp;
    
}tAppCover_sensorStatusType;

/**
 * @brief This variable describes the sensor status or the temperature for a specific garden 
 */
tAppCover_sensorStatusType AppCover_sensorStatusGarden[APP_CONFIG_NR_GARDENS];

/**
 * @brief The main function for initializing the main function 
 */
extern void App_Cover_Init(void);

#endif 
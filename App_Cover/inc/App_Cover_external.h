#ifndef APP_COVER_EXTERNAL_H
#define APP_COVER_EXTERNAL_H
#include<App_main_external.h>

#define MAX_TEMP_COVER 5
#define MAX_COUNTER_COVER 200
#define MAX_TEMP_COVER_CLOSED 10
#define MAX_COUNTER_COVER_CLOSED 1200

typedef enum
{
    APP_COVER_COVER_OPEN = 0x00,
    APP_COVER_COVER_MOVING = 0x01,
    APP_COVER_ERROR = 0x02,
    APP_COVER_CLOSED = 0x03,

}tAppCover_CoverPositionType;

typedef enum
{
    APP_GARDEN_INVALID,
    
}tAppCover_CoverType;

typedef enum
{
    APP_MOVE_OPENING,
    APP_MOVE_CLOSING

}tAppCover_MovementType;

/**
 * @brief This variable describes a position that the cover can have\n\n 
 */
extern tAppCover_CoverPositionType App_Cover_CoverPosition[APP_CONFIG_NR_GARDENS];

/**
 * @brief This variable describes the type of movement that cover can have (opening/closing)\n\n
 */
extern tAppCover_MovementType App_Cover_Movement[APP_CONFIG_NR_GARDENS];

/**
 * @brief The main function for App_Temp
 * @return void
 */
void App_Cover_Main(void);

#endif

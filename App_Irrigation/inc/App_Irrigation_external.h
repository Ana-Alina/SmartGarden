#ifndef APP_IRRIGATION_EXTERNAL_H
#define APP_IRRIGATION_EXTERNAL_H

#include <App_main_external.h>

#define APPIRRIG_NUMBER_GARDEN1_SPRINKLERS 16
#define APPIRRIG_NUMBER_GARDEN2_SPRINKLERS 25
#define APPIRRIG_MAX_NUMBER_OF_SAVED_CONF 4
#define APPIRRIG_CHECK_COUNTER 6000

typedef enum
{
    APP_IRRIG_POS0 = 0x00,
    APP_IRRIG_POS1 = 0x01,
    APP_IRRIG_POS2 = 0x02,
    APP_IRRIG_POS3 = 0x03,
    APP_IRRIG_CLEAR_ALL = 0x04,
}tAppIrrig_ConfigurationPositionType;

typedef enum
{
    APP_IRRIG_SAVE_DONE = 0x00,
    APP_IRRIG_SAVE_CONF_FULL = 0x01,
}tAppIrrig_SaveRequestStatusType;

typedef enum
{
    APP_IRRIG_POS_EMPTY	= 0x00,
    APP_IRRIG_POS_FULL = 0x01,
}tAppIrrig_SavedConfInstanceStatus_Type;

typedef enum
{
    APP_IRRIG_STATUS_IDLE = 0x00,
    APP_IRRIG_STATUS_OK = 0x01,
    APP_IRRIG_STATUS_NOK = 0x02,
}tAppIrrig_SprinklerGeneralStatusType;

/**
 * @brief Contains the configuration for a sprinkler
 * @retval TRUE - the sprinkler is functional
 * @etval FALSE - the sprinker is not functional
 * 
 */
typedef struct
{
    bool *sprinkler;
    tAppIrrig_SprinklerGeneralStatusType generalStatus;

}tAppIrrig_GardenSprinkler_ConfType;

/**
 * @brief Contains the configuration for a specific garden
 * @param gardenConf is a vector used for storing the bool values that contain the functionality of sprinklers\n
 * 
 */
typedef struct 
{
    tAppIrrig_GardenSprinkler_ConfType *gardenConf;
}tAppIrrig_GardenSprinkler_Type;

/**
 * @brief Contains the status and the saved configuration for each garden
 * @param savedConfInstance is a vector used for storing the garden configurations\n
 * @param status used for storing the status of a configuration slot\n
 * 
 */
typedef struct 
{
    uint8 *savedConfInstance;
    tAppIrrig_SavedConfInstanceStatus_Type status;
}tAppIrrig_SavedGardenConf_Type;

/**
 * @brief Contains the saved configurations and their number
 * @param savedConf used for storing the status and the saved garden configuration\n
 * @param nrOfSavedConf used for storing the number of saved configurations\n
 */
typedef struct 
{
    tAppIrrig_SavedGardenConf_Type *savedConf;
    uint8 nrOfSavedConf;

}tAppIrrig_GardenMain_Type ;

/**
 * @brief The variable AppIrrig_CurrentConfiguration indicates the current configuration \n
 * 
 */
extern tAppIrrig_GardenSprinkler_Type AppIrrig_CurrentConfiguration[APP_CONFIG_NR_GARDENS];

/**
 * @brief The variable AppIrrig_CurrentConfGarden1 indicates the current configuration of sprinklers for garden 1 \n
 * 
 */
extern tAppIrrig_GardenSprinkler_ConfType AppIrrig_CurrentConfGarden1[APPIRRIG_NUMBER_GARDEN1_SPRINKLERS];

/**
 * @brief The variable AppIrrig_CurrentConfGarden2 indicates the current configuration of sprinklers for garden 2 \n
 * 
 */
extern tAppIrrig_GardenSprinkler_ConfType AppIrrig_CurrentConfGarden2[APPIRRIG_NUMBER_GARDEN2_SPRINKLERS];

/**
 * @brief The variable AppIrrig_GardenSprinkler indicates the garden configuration \n
 * 
 */
// extern tAppIrrig_GardenSprinkler_Type AppIrrig_GardenSprinkler [APP_CONFIG_NR_GARDENS];

/**
 * @brief  The variable AppIrrig_GardenMain indicates the saved configuration and the number of saved configurations for a garden\n
 * 
 */
extern tAppIrrig_GardenMain_Type AppIrrig_GardenMain[APP_CONFIG_NR_GARDENS];

extern tAppIrrig_SprinklerGeneralStatusType tAppIrrig_SprinklerGeneralStatus[APP_CONFIG_NR_GARDENS];

/**
 * @brief This function is used to initialize the temperature and the number of saved configurations for each garden \n
 * 
 */
extern void App_Irrig_init(void);

extern void App_Irrig_Main(void);

/**
 * @brief This function sets the current sprinkler configuration for a specific garden
 * 
 * @param sprinkler_conf [in] used for setting the current sprinkler configuration\n
 * @param garden [in] used for selecting the ID of the garden\n
 */
extern void App_Irrig_Set_Sprinklers (bool *sprinkler_conf, uint8 garden);

/**
 * @brief This function gets the total number of saved configurations
 * 
 * @param nrOfConfSaved [out] used for providing the number of saved configurations\n
 * @param garden [in]  used for setting the ID of the garden\n
 */
extern void App_Irrig_Get_Nr_Configurations (uint8 *nrOfConfSaved, uint8 garden);

/**
 * @brief This function is receiving the request to store the current sprinkler configuration for a specific garden.  
 * 
 * @retval TRUE saveReq [in] used for sending the request to save the current configuration\n
 * @retval FALSE saveReq [in] used for sending the request not to save the current configuration\n
 * @param garden [in] used for setting the ID of the garden\n
 * @return tAppIrrig_SaveRequestStatusType return the result from a set of predefined statuses of saved (or not) configurations\n
 */
extern tAppIrrig_SaveRequestStatusType App_Irrig_Save_Configuration (bool saveReq, uint8 garden);

/**
 * @brief Function gets the saved configuration for a specific position from a specific garden
 * 
 * @param configuration [out] used for providing the saved configuration
 * @param position [out] used for providing the current position
 * @param garden [in] used for setting the ID of the garden\n
 */
extern void App_Irrig_Get_Saved_Configuration (uint8 configuration[], tAppIrrig_ConfigurationPositionType *position, uint8 garden);

/**
 * @brief This function deletes the saved configuration from a specific position 
 * 
 * @param position [in] used for setting the possition from a set of predifined statuses from where the configuration will be deleted\n
 * @param garden [in] used for setting the ID of the garden\n
 */
extern void App_Irrig_Delete_Saved_Configuration (tAppIrrig_ConfigurationPositionType position, uint8 garden);

/**
 * @brief This function sets a saved configuration as the current one
 * 
 * @param position [in] used for setting the possition from a set of predifined statuses from where the configuration will be set\n
 * @param garden [in] used for setting the ID of the garden\n
 */
extern void App_Irrig_Set_Saved_Configuration (tAppIrrig_ConfigurationPositionType position, uint8 garden);

#endif
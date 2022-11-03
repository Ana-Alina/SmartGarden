#include <AppDatatypes.h>
#include <App_Irrigation_external.h>
#include <App_Irrigation_internal.h>
#include <App_Stubs_external.h>

bool currentConfigFlag1 = false;
bool currentConfigFlag2 = false;

bool AppIrrig_SprinklerConfGarden1_SP1;
bool AppIrrig_SprinklerConfGarden1_SP2;
bool AppIrrig_SprinklerConfGarden1_SP3;
bool AppIrrig_SprinklerConfGarden1_SP4;
bool AppIrrig_SprinklerConfGarden1_SP5;
bool AppIrrig_SprinklerConfGarden1_SP6;
bool AppIrrig_SprinklerConfGarden1_SP7;
bool AppIrrig_SprinklerConfGarden1_SP8;
bool AppIrrig_SprinklerConfGarden1_SP9;
bool AppIrrig_SprinklerConfGarden1_SP10;
bool AppIrrig_SprinklerConfGarden1_SP11;
bool AppIrrig_SprinklerConfGarden1_SP12;
bool AppIrrig_SprinklerConfGarden1_SP13;
bool AppIrrig_SprinklerConfGarden1_SP14;
bool AppIrrig_SprinklerConfGarden1_SP15;
bool AppIrrig_SprinklerConfGarden1_SP16;

bool AppIrrig_SprinklerConfGarden2_SP1;
bool AppIrrig_SprinklerConfGarden2_SP2;
bool AppIrrig_SprinklerConfGarden2_SP3;
bool AppIrrig_SprinklerConfGarden2_SP4;
bool AppIrrig_SprinklerConfGarden2_SP5;
bool AppIrrig_SprinklerConfGarden2_SP6;
bool AppIrrig_SprinklerConfGarden2_SP7;
bool AppIrrig_SprinklerConfGarden2_SP8;
bool AppIrrig_SprinklerConfGarden2_SP9;
bool AppIrrig_SprinklerConfGarden2_SP10;
bool AppIrrig_SprinklerConfGarden2_SP11;
bool AppIrrig_SprinklerConfGarden2_SP12;
bool AppIrrig_SprinklerConfGarden2_SP13;
bool AppIrrig_SprinklerConfGarden2_SP14;
bool AppIrrig_SprinklerConfGarden2_SP15;
bool AppIrrig_SprinklerConfGarden2_SP16;
bool AppIrrig_SprinklerConfGarden2_SP17;
bool AppIrrig_SprinklerConfGarden2_SP18;
bool AppIrrig_SprinklerConfGarden2_SP19;
bool AppIrrig_SprinklerConfGarden2_SP20;
bool AppIrrig_SprinklerConfGarden2_SP21;
bool AppIrrig_SprinklerConfGarden2_SP22;
bool AppIrrig_SprinklerConfGarden2_SP23;
bool AppIrrig_SprinklerConfGarden2_SP24;
bool AppIrrig_SprinklerConfGarden2_SP25;

tAppIrrig_GardenSprinkler_ConfType AppIrrig_CurrentConfGarden1[APPIRRIG_NUMBER_GARDEN1_SPRINKLERS] = 
{
    {&AppIrrig_SprinklerConfGarden1_SP1, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP2, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP3, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP4, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP5, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP6, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP7, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP8, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP9, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP10, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP11, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP12, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP13, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP14, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP15, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden1_SP16, APP_IRRIG_STATUS_IDLE},
};
tAppIrrig_GardenSprinkler_ConfType AppIrrig_CurrentConfGarden2[APPIRRIG_NUMBER_GARDEN2_SPRINKLERS] = 
{
    {&AppIrrig_SprinklerConfGarden2_SP1, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP2, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP3, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP4, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP5, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP6, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP7, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP8, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP9, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP10, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP11, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP12, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP13, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP14, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP15, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP16, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP17, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP18, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP19, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP20, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP21, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP22, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP23, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP24, APP_IRRIG_STATUS_IDLE},
    {&AppIrrig_SprinklerConfGarden2_SP25, APP_IRRIG_STATUS_IDLE},
};

uint8 AppIrrig_Saved_Garden1_Conf_POS0[16] = {0};
uint8 AppIrrig_Saved_Garden1_Conf_POS1[16] = {0};
uint8 AppIrrig_Saved_Garden1_Conf_POS2[16] = {0};
uint8 AppIrrig_Saved_Garden1_Conf_POS3[16] = {0};

uint8 AppIrrig_Saved_Garden2_Conf_POS0[25] = {0};
uint8 AppIrrig_Saved_Garden2_Conf_POS1[25] = {0};
uint8 AppIrrig_Saved_Garden2_Conf_POS2[25] = {0};
uint8 AppIrrig_Saved_Garden2_Conf_POS3[25] = {0};

tAppIrrig_GardenSprinkler_Type AppIrrig_CurrentConfiguration[APP_CONFIG_NR_GARDENS] = 
{
    AppIrrig_CurrentConfGarden1,
    AppIrrig_CurrentConfGarden2,
};

tAppIrrig_SavedGardenConf_Type AppIrrig_Saved_Garden1_Conf [APPIRRIG_MAX_NUMBER_OF_SAVED_CONF] =
{
    {
        &AppIrrig_Saved_Garden1_Conf_POS0[0], 
        APP_IRRIG_POS_EMPTY,
    },
    {
        &AppIrrig_Saved_Garden1_Conf_POS1[0], 
        APP_IRRIG_POS_EMPTY,
    },
    {
        &AppIrrig_Saved_Garden1_Conf_POS2[0], 
        APP_IRRIG_POS_EMPTY,
    },
    {
        &AppIrrig_Saved_Garden1_Conf_POS3[0], 
        APP_IRRIG_POS_EMPTY,
    },

};

tAppIrrig_SavedGardenConf_Type AppIrrig_Saved_Garden2_Conf [APPIRRIG_MAX_NUMBER_OF_SAVED_CONF] =
{
    {
        &AppIrrig_Saved_Garden2_Conf_POS0[0], 
        APP_IRRIG_POS_EMPTY,
    },
    {
        &AppIrrig_Saved_Garden2_Conf_POS1[0], 
        APP_IRRIG_POS_EMPTY,
    },
    {
        &AppIrrig_Saved_Garden2_Conf_POS2[0], 
        APP_IRRIG_POS_EMPTY,
    },
    {
        &AppIrrig_Saved_Garden2_Conf_POS3[0], 
        APP_IRRIG_POS_EMPTY,
    },
};

tAppIrrig_GardenMain_Type AppIrrig_GardenMain[APP_CONFIG_NR_GARDENS] = 
{
    {
        AppIrrig_Saved_Garden1_Conf,
        0,
    },
        {
        AppIrrig_Saved_Garden2_Conf,
        0,
    },
};

    static uint8 current_position = 0;
    static uint8 counter_position = 0;
    static uint16 checkCounter1 = 0;
    static uint16 checkCounter2 = 0;
    bool sprinklerStatus = true;

 void App_Irrig_init(void)
{
    uint8 garden = 0;
    uint8 i = 0;
    
    current_position = 0;
    counter_position = 0;

    for(garden = 0; garden < APP_CONFIG_NR_GARDENS; garden ++)
    {
        for(i = 0; i < APPIRRIG_MAX_NUMBER_OF_SAVED_CONF; i ++ )
        {
            AppIrrig_GardenMain[0].savedConf[i].status = APP_IRRIG_POS_EMPTY;
            AppIrrig_GardenMain[1].savedConf[i].status = APP_IRRIG_POS_EMPTY;
        }
        AppIrrig_GardenMain[0].nrOfSavedConf = 0;
        AppIrrig_GardenMain[1].nrOfSavedConf = 0;

        switch (garden)
        {
        case 0:
            for (i = 0; i < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; i ++)
            {
                STUB_Irrig_System_Check_Sprinkler_Status[i] = 0;
                AppIrrig_CurrentConfiguration[0].gardenConf[i].generalStatus = APP_IRRIG_STATUS_IDLE;
                currentConfigFlag1 = false;                  
            }
            break;
                
        case 1:
            for (i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
            {
                STUB_Irrig_System_Check_Sprinkler_Status[i] = 0;
                AppIrrig_CurrentConfiguration[1].gardenConf[i].generalStatus = APP_IRRIG_STATUS_IDLE;
                currentConfigFlag2 = false;
            }
            break;

        default:
            break;
        }
        
    }
}

void App_Irrig_Main(void)
{
    bool verifystatusFlag = true;
    uint8 i = 0;
    char buffer[100];
    uint8 buff_size = sizeof(buffer);
    char *str1;
    char *str2;
    char *str3;
    char *str4;
    char *str5;

    if(currentConfigFlag1 == true)
    {
        for (i = 0; i < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; i ++)
        {      
            App_IrrigSystem_SetSprinklerStatus(&sprinklerStatus, i, 0);                 
        }

        if(checkCounter1 == APPIRRIG_CHECK_COUNTER)
        {
            str1 = "Sprinkler verification for garden";
            str2 = "1";
            str3 = "has started!";
            (void)snprintf(buffer, buff_size, "%s %s %s", str1, str2, str3);
            App_Config_Log_Message(buffer, APP_LOG_INFO);

            for (i = 0; i < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; i ++)
            {      
                App_IrrigSystem_CheckSprinklerStatus(&sprinklerStatus, i, 0);

                if(sprinklerStatus != *AppIrrig_CurrentConfiguration[0].gardenConf[i].sprinkler)
                {
                    AppIrrig_CurrentConfiguration[0].gardenConf[i].generalStatus = APP_IRRIG_STATUS_NOK;
                    verifystatusFlag = false;
                    str1 = "Garden";
                    str2 = "1:";
                    str3 = "Sprinkler";
                    str5 = "is NOK!";
                    (void)snprintf(buffer, buff_size, "%s %s %s %i %s", str1, str2, str3, i, str5);
                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                }
                else
                {
                    AppIrrig_CurrentConfiguration[0].gardenConf[i].generalStatus = APP_IRRIG_STATUS_OK;
                }   
            }
                            
            if(verifystatusFlag == true)
            {
                str1 = "All sprinkler for garden";
                str2 = "1";
                str3 = "are ok!";
                (void)snprintf(buffer, buff_size, "%s %s %s", str1, str2, str3);
                App_Config_Log_Message(buffer, APP_LOG_INFO);
            }

            checkCounter1 = 0;
            App_Config_Log_Message("Sprinklers verification complete!", APP_LOG_INFO);
        }
        else
        {
            checkCounter1 ++;
        }
    }

    if(currentConfigFlag2 == true)
    {
        for (i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
        {      
            App_IrrigSystem_SetSprinklerStatus(&sprinklerStatus, i, 1);                    
        }
        
        if(checkCounter2 == APPIRRIG_CHECK_COUNTER)
        {
            str1 = "Sprinkler verification for garden";
            str2 = "2";
            str3 = "has started!";
            (void)snprintf(buffer, buff_size, "%s %s %s", str1, str2, str3);
            App_Config_Log_Message(buffer, APP_LOG_INFO);

            for (i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
            {      
                App_IrrigSystem_CheckSprinklerStatus(&sprinklerStatus, i, 1);

                if(sprinklerStatus != *AppIrrig_CurrentConfiguration[1].gardenConf[i].sprinkler)
                {
                    AppIrrig_CurrentConfiguration[1].gardenConf[i].generalStatus = APP_IRRIG_STATUS_NOK;
                    verifystatusFlag = false;
                }
                else
                {
                    AppIrrig_CurrentConfiguration[1].gardenConf[i].generalStatus = APP_IRRIG_STATUS_OK;
                }
            }

            if(verifystatusFlag == true)
            {
                str1 = "All sprinkler for garden";
                str2 = "2";
                str3 = "are ok!";
                (void)snprintf(buffer, buff_size, "%s %s %s", str1, str2, str3);
                App_Config_Log_Message(buffer, APP_LOG_INFO);
            }
            else
            {
                for (i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
                {
                    if(sprinklerStatus != *AppIrrig_CurrentConfiguration[1].gardenConf[i].sprinkler)
                    {
                        str1 = "Garden";
                        str2 = "2:";
                        str3 = "Sprinkler";
                        str5 = "is NOK!";
                        (void)snprintf(buffer, buff_size, "%s %s %s %i %s", str1, str2, str3, i, str5);
                        App_Config_Log_Message(buffer, APP_LOG_INFO);
                    }
                }  
            } 
            checkCounter2 = 0;
            App_Config_Log_Message("Sprinklers verification complete!", APP_LOG_INFO);
        }
        else
        {
            checkCounter2 ++;
        }
    }
}

void App_Irrig_Set_Sprinklers(bool *sprinkler_conf, uint8 garden)
{
    uint8 i = 0;
    char buffer[50];
    uint8 buff_size = sizeof(buffer);
    char *str1 = "A new Configuration for garden";
    char *str2;
    char *str3 = "is received!";
    
    if(garden < APP_CONFIG_NR_GARDENS)
    {
        if(AppConfig_Garden[garden].irrigation == true)
        {
            switch (garden)
            {
                case 0: 
                    for (i = 0; i < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; i ++)
                    {
                        *AppIrrig_CurrentConfiguration[garden].gardenConf[i].sprinkler = sprinkler_conf[i];
                        App_IrrigSystem_SetSprinklerStatus(&sprinkler_conf[i], i, garden);                    
                    }

                    currentConfigFlag1 = true;

                    str2 = "1";
                    (void)snprintf(buffer, buff_size, "%s %s %s", str1, str2, str3);
                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                    break;
                
                case 1:
                    for (i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
                    {
                        *AppIrrig_CurrentConfiguration[garden].gardenConf[i].sprinkler = sprinkler_conf[i];
                        App_IrrigSystem_SetSprinklerStatus(&sprinkler_conf[i], i, garden);
                    }

                    currentConfigFlag2 = true;

                    str2 = "2";
                    (void)snprintf(buffer, buff_size, "%s %s %s", str1, str2, str3);
                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                    
                    break;

                default:
                    break;
            }    
        }
        else
        {
            printf("Configuration error!");
        }
    }
    else
    {
        printf("\n Invalid garden! \n");
    }
};

void App_Irrig_Get_Nr_Configurations(uint8 *nrOfConfSaved, uint8 garden)
{
    if(garden < APP_CONFIG_NR_GARDENS)
    {
        if(AppConfig_Garden[garden].irrigation == true)
        {
            *nrOfConfSaved = AppIrrig_GardenMain[garden].nrOfSavedConf;
        }
        else
        {
            printf("Configuration error!");
        }
    }
    else
    {
        printf("\n Invalid garden! \n");
    }
};

tAppIrrig_SaveRequestStatusType App_Irrig_Save_Configuration(bool saveReq, uint8 garden)
{
    tAppIrrig_SaveRequestStatusType result;
    uint8 i = 0;
    uint8 k = 0;
    uint8 gardenConfigSize = 0;
    
    char buffer[100];
    uint8 buff_size = sizeof(buffer);
    char *str1;
    char *str2;
    char *str3;
    char *str4;

    if(garden < APP_CONFIG_NR_GARDENS)
    {
        if(AppConfig_Garden[garden].irrigation == true)
        {
            if (saveReq == true)
            {
                if (AppIrrig_GardenMain[garden].nrOfSavedConf == APPIRRIG_MAX_NUMBER_OF_SAVED_CONF)
                {
                    str1 = "The configuration for garden";
                    str3 = "is FULL!";

                    if(garden == 0)
                    {
                        str2 = "1";
                        (void)snprintf(buffer, buff_size, "%s %s %s", str1, str2, str3);
                        App_Config_Log_Message(buffer, APP_LOG_ERROR);
                    }
                    else
                    {
                        str2 = "2";
                        (void)snprintf(buffer, buff_size, "%s %s %s", str1, str2, str3);
                        App_Config_Log_Message(buffer, APP_LOG_ERROR);
                    }

                    result = APP_IRRIG_SAVE_CONF_FULL;
                }
                else
                {
                    str1 = "The configuration is saved at";
                    str3 = "position for garden";
                    for (k = 0; k < APPIRRIG_MAX_NUMBER_OF_SAVED_CONF; k ++)
                    {
                        if(AppIrrig_GardenMain[garden].savedConf[k].status == APP_IRRIG_POS_EMPTY)
                        {    
                            switch (garden)
                            {
                            case 0:
                                gardenConfigSize = APPIRRIG_NUMBER_GARDEN1_SPRINKLERS;
                                break;
                            
                            case 1:
                                gardenConfigSize = APPIRRIG_NUMBER_GARDEN2_SPRINKLERS;
                                break;
                            
                            default:
                                break;
                            }

                            for (i = 0; i < gardenConfigSize; i ++)
                            {              
                                AppIrrig_GardenMain[garden].savedConf[k].savedConfInstance[i] = *AppIrrig_CurrentConfiguration[garden].gardenConf[i].sprinkler;
                            }

                            if(AppIrrig_GardenMain[garden].nrOfSavedConf < 255)
                            {
                                AppIrrig_GardenMain[garden].nrOfSavedConf ++;
                            }

                            AppIrrig_GardenMain[garden].savedConf[k].status = APP_IRRIG_POS_FULL;

                            if(garden == 0)
                            {
                                if(k == 0)
                                {
                                    str2 = "0";
                                    str4 = "1";
                                    (void)snprintf(buffer, buff_size, "%s %s %s %s", str1, str2, str3, str4);
                                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                                    
                                }
                                else if(k == 1)
                                {
                                    str2 = "1";
                                    str4 = "1";
                                    (void)snprintf(buffer, buff_size, "%s %s %s %s", str1, str2, str3, str4);
                                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                                    
                                }
                                else if(k == 2)
                                {
                                    str2 = "2";
                                    str4 = "1";
                                    (void)snprintf(buffer, buff_size, "%s %s %s %s", str1, str2, str3, str4);
                                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                                    
                                }
                                else if(k == 3)
                                {
                                    str2 = "3";
                                    str4 = "1";
                                    (void)snprintf(buffer, buff_size, "%s %s %s %s", str1, str2, str3, str4);
                                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                                    
                                }
                            }
                            else if(garden == 1)
                            {
                                if(k == 0)
                                {
                                    str2 = "0";
                                    str4 = "2";
                                    (void)snprintf(buffer, buff_size, "%s %s %s %s", str1, str2, str3, str4);
                                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                                    
                                }
                                else if(k == 1)
                                {
                                    str2 = "1";
                                    str4 = "2";
                                    (void)snprintf(buffer, buff_size, "%s %s %s %s", str1, str2, str3, str4);
                                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                                    
                                }
                                else if(k == 2)
                                {
                                    str2 = "2";
                                    str4 = "2";
                                    (void)snprintf(buffer, buff_size, "%s %s %s %s", str1, str2, str3, str4);
                                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                                    
                                }
                                else if(k == 3)
                                {
                                    str2 = "3";
                                    str4 = "2";
                                    (void)snprintf(buffer, buff_size, "%s %s %s %s", str1, str2, str3, str4);
                                    App_Config_Log_Message(buffer, APP_LOG_INFO);
                                    
                                } 
                            }
                            
                            break;
                        }
                    }

                    result = APP_IRRIG_SAVE_DONE;                        
                }
            }
            else
            {
                printf("Configuration error!");
            }    
        }
        else
        {
            printf("\n Could not save configuration! \n");
        }
    }
    else
    {
       printf("\n Invalid garden! \n"); 
    }        
    return result;
};

void App_Irrig_Get_Saved_Configuration (uint8 configuration[], tAppIrrig_ConfigurationPositionType *position, uint8 garden)
{
    uint8 i = 0;
    uint8 j = 0;
    uint8 gardenConfigSize = 0;
    uint8 checkCounter = 0;
    
    switch (garden)
    {
        case 0:
            gardenConfigSize = APPIRRIG_NUMBER_GARDEN1_SPRINKLERS;
            break;
                            
        case 1:
            gardenConfigSize = APPIRRIG_NUMBER_GARDEN2_SPRINKLERS;
            break;
                            
        default:
            break;
    }

    if(garden < APP_CONFIG_NR_GARDENS)
    {
        if(AppConfig_Garden[garden].irrigation == true)
        {          
            for (i = current_position ; i < APPIRRIG_MAX_NUMBER_OF_SAVED_CONF; i ++)
            {
                if(AppIrrig_GardenMain[garden].savedConf[i].status == APP_IRRIG_POS_FULL)
                {
                    for(j = 0; j < gardenConfigSize; j ++)
                    {
                        configuration[j] = AppIrrig_GardenMain[garden].savedConf[i].savedConfInstance[j];
                    }
                    *position = current_position;

                    if (current_position < 255)
                    {
                        current_position ++;
                    }

                    if (current_position < 255)
                    {
                        counter_position ++;
                    }
                    break;
                }        
                else
                {
                    if (current_position < 255)
                    {
                        current_position ++;
                    }
                }
            }

            if(AppIrrig_GardenMain[garden].nrOfSavedConf == counter_position)
            {
                counter_position = 0;
                current_position = 0;
            }
        }
    }
    else
    {
        printf("\n Invalid garden! \n");
    }
};

void App_Irrig_Delete_Saved_Configuration (tAppIrrig_ConfigurationPositionType position, uint8 garden)
{
    uint8 i = 0;
    uint8 k = 0;
    uint8 gardenConfigSize = 0;

    char buffer[50];
    uint8 buff_size = sizeof(buffer);
    char *str1 = "The configuration";
    char *str2;
    char *str3 = "for garden";
    char *str4;
    char *str5 = "is cleared";
        
    if(garden < APP_CONFIG_NR_GARDENS)
    {
        if(AppConfig_Garden[garden].irrigation == true)
        { 
            if (position != APP_IRRIG_CLEAR_ALL)
            {
                //Deleting just a position from configuration
                switch (garden)
                {
                    case 0:
                    gardenConfigSize = APPIRRIG_NUMBER_GARDEN1_SPRINKLERS;
                    break;
                            
                    case 1:
                    gardenConfigSize = APPIRRIG_NUMBER_GARDEN2_SPRINKLERS;
                    break;
                            
                    default:
                    break;
                }

                for (i = 0; i < gardenConfigSize; i ++)
                {
                    AppIrrig_GardenMain[garden].savedConf[position].savedConfInstance[i] = 0;       
                }

                if ( AppIrrig_GardenMain[garden].nrOfSavedConf != 0)
                {
                    AppIrrig_GardenMain[garden].nrOfSavedConf --;
                }

                AppIrrig_GardenMain[garden].savedConf[position].status = APP_IRRIG_POS_EMPTY;

                if(garden == 0)
                {
                    if(position == 0)
                    {
                        str2 = "0";
                        str4 = "1";
                        (void)snprintf(buffer, buff_size, "%s %s %s %s %s", str1, str2, str3, str4, str5);
                        App_Config_Log_Message(buffer, APP_LOG_INFO);
                    }
                    else if(position == 1)
                    {
                        str2 = "1";
                        str4 = "1";
                        (void)snprintf(buffer, buff_size, "%s %s %s %s %s", str1, str2, str3, str4, str5);
                        App_Config_Log_Message(buffer, APP_LOG_INFO);
                    }
                    else if(position == 2)
                    {
                        str2 = "2";
                        str4 = "1";
                        (void)snprintf(buffer, buff_size, "%s %s %s %s %s", str1, str2, str3, str4, str5);
                        App_Config_Log_Message(buffer, APP_LOG_INFO);
                    }
                    else if(position == 3)
                    {
                        str2 = "3";
                        str4 = "1";
                        (void)snprintf(buffer, buff_size, "%s %s %s %s %s", str1, str2, str3, str4, str5);
                        App_Config_Log_Message(buffer, APP_LOG_ERROR);
                    }
                }
                else if(garden == 1)
                {
                    if(position == 0)
                    {
                        str2 = "0";
                        str4 = "2";
                        (void)snprintf(buffer, buff_size, "%s %s %s %s %s", str1, str2, str3, str4, str5);
                        App_Config_Log_Message(buffer, APP_LOG_ERROR);
                    }
                    else if(position == 1)
                    {
                        str2 = "1";
                        str4 = "2";
                        (void)snprintf(buffer, buff_size, "%s %s %s %s %s", str1, str2, str3, str4, str5);
                        App_Config_Log_Message(buffer, APP_LOG_ERROR);
                    }
                    else if(position == 2)
                    {
                        str2 = "2";
                        str4 = "2";
                        (void)snprintf(buffer, buff_size, "%s %s %s %s %s", str1, str2, str3, str4, str5);
                        App_Config_Log_Message(buffer, APP_LOG_ERROR);
                    }
                    else if(position == 3)
                    {
                        str2 = "3";
                        str4 = "2";
                        (void)snprintf(buffer, buff_size, "%s %s %s %s %s", str1, str2, str3, str4, str5);
                        App_Config_Log_Message(buffer, APP_LOG_ERROR);
                    }             
                }
            }
            else
            {
                //Deleting all positions from configuration
                switch (garden)
                {
                    case 0:
                    gardenConfigSize = APPIRRIG_NUMBER_GARDEN1_SPRINKLERS;
                    break;
                                
                    case 1:
                    gardenConfigSize = APPIRRIG_NUMBER_GARDEN2_SPRINKLERS;
                    break;
                                
                    default:
                    break;
                }

                for (k = 0; k < APPIRRIG_MAX_NUMBER_OF_SAVED_CONF; k ++)
                {
                    for (i = 0; i < gardenConfigSize; i ++)
                    {
                        AppIrrig_GardenMain[garden].savedConf[k].savedConfInstance[i] = 0;      
                    }
                }

                if(garden == 0)
                {
                    str2 = "1";
                    (void)snprintf(buffer, buff_size, "%s %s %s %s", str1, str3, str2, str5);
                    App_Config_Log_Message(buffer, APP_LOG_ERROR);
                }
                else if(garden == 1)
                {
                    str2 = "2";
                    (void)snprintf(buffer, buff_size, "%s %s %s %s", str1, str3, str2, str5);
                    App_Config_Log_Message(buffer, APP_LOG_ERROR);
                }

                AppIrrig_GardenMain[garden].nrOfSavedConf = 0;
                AppIrrig_GardenMain[garden].savedConf[position].status = APP_IRRIG_POS_EMPTY;
            }
        }
    }
    else
    {
        printf("\n Invalid garden! \n");
    }
}

void App_Irrig_Set_Saved_Configuration (tAppIrrig_ConfigurationPositionType position, uint8 garden)
{
    uint8 i = 0;
    uint8 gardenConfigSize = 0;

    if(garden < APP_CONFIG_NR_GARDENS)
    {
        if(AppConfig_Garden[garden].irrigation == true)
        {  
            switch (garden)
            {
                case 0:
                gardenConfigSize = APPIRRIG_NUMBER_GARDEN1_SPRINKLERS;
                break;
                            
                case 1:
                gardenConfigSize = APPIRRIG_NUMBER_GARDEN2_SPRINKLERS;
                break;
                            
                default:
                break;
            }   

            if (position != APP_IRRIG_CLEAR_ALL)
            {
                if(garden == 0)
                {
                    for (i = 0; i < gardenConfigSize; i ++)
                    {             
                        *AppIrrig_CurrentConfiguration[garden].gardenConf[i].sprinkler = AppIrrig_GardenMain[garden].savedConf[position].savedConfInstance[i];
                        App_IrrigSystem_SetSprinklerStatus(&sprinklerStatus, i, garden); 
                    }
                    currentConfigFlag1 = true;
                }
                else if(garden == 1)
                {
                    for (i = 0; i < gardenConfigSize; i ++)
                    {             
                        *AppIrrig_CurrentConfiguration[garden].gardenConf[i].sprinkler = AppIrrig_GardenMain[garden].savedConf[position].savedConfInstance[i];
                        App_IrrigSystem_SetSprinklerStatus(&sprinklerStatus, i, garden); 
                    }
                    currentConfigFlag2 = true;
                }                
            }
            else
            {
                printf("\n Configurations is set! \n");
            }
        }
    }
    else
    {
        printf("\n Invalid garden! \n");
    }
};














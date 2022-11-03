#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<App_main_external.h>
#include<App_Temp_external.h>
#include<App_Stubs_external.h>
#include<App_Irrigation_external.h>
#include<App_Cover_external.h>
#include<string.h>

#define MAX_SINLE_LINE 150
tApp_Temp_HistoryType log_info;

tAppConfig_Type AppConfig_Garden[APP_CONFIG_NR_GARDENS] = 
{
    {
        true,
        true,
        true,
        true,
        true
    },
    {
        false,
        true,
        true,
        false,
        true
    }
};

// Reading the configuration file and obtaining the current configuration for the software
void App_Config_Init (const char fileSource[])
{
    // open the file
    FILE *configuration;
    configuration = fopen(fileSource, "r");

    // store all the character that we read
    char singleLine[MAX_SINLE_LINE];
    char token[] = "=";
    uint8 gardenID = 0;

    if (configuration != NULL) 
    {
        while (!feof(configuration))
        {
            // read the file line by line
            fgets(singleLine, MAX_SINLE_LINE, configuration);
            //for(int x = 0; x < strlen(fileSource); ++ x)
            //    printf("%c", fileSource[x]);
            //printf("\n");
            char *ptr = strtok(singleLine, token);
            if(ptr != NULL)
            {
                // The return value from strcmp is 0 if the two strings are equal, less than 0 if str1 compares less than str2 , and greater than 0 if str1 compares greater than str2 .
                if(strcmp(ptr, "GardenID") == 0)
                {
                    ptr = strtok(NULL, "\n");
                    if (ptr != NULL)
                    {
                        if (strcmp(ptr, "0") == 0)
                        {
                            gardenID = 0;
                            App_Config_Log_Message("Garden 1 new configuration!", APP_LOG_INFO);
                        }
                        else if (strcmp(ptr, "1") == 0)
                        {
                            gardenID = 1;
                            App_Config_Log_Message("Garden 2 new configuration!", APP_LOG_INFO);
                        }
                        else
                        {
                            for(gardenID = 0; gardenID < APP_CONFIG_NR_GARDENS; gardenID ++)
                            {
                                AppConfig_Garden[gardenID].cover_motor = false;
                                AppConfig_Garden[gardenID].humidityMonitoring = false;
                                AppConfig_Garden[gardenID].irrigation = false;
                                AppConfig_Garden[gardenID].lightMonitoring = false;
                                AppConfig_Garden[gardenID].temperatureMonitoring = false;
                            }
                            App_Config_Log_Message("All modules are deactivated! Nonexistent garden!", APP_LOG_ERROR);
                            break; 
                        } 
                    }                  
                }
                
                else if (strcmp(ptr, "Cover_Motor") == 0)
                {
                    ptr = strtok(NULL, "\n");
                    if (ptr != NULL)
                    {
                        if(strcmp(ptr,"Yes") == 0)
                        {
                            AppConfig_Garden[gardenID].cover_motor = true;
                            App_Config_Log_Message("Cover module activated!", APP_LOG_INFO);
                        }
                        else if(strcmp(ptr,"No") == 0)
                        {
                            AppConfig_Garden[gardenID].cover_motor = false;
                            App_Config_Log_Message("Cover module deactivated!", APP_LOG_INFO);
                        }
                        else
                        {
                            AppConfig_Garden[gardenID].cover_motor = false;
                            App_Config_Log_Message("Cover module deactivated!", APP_LOG_INFO);
                        }
                    }
                }
                
                else if (strcmp(ptr, "Temperature Monitoring") == 0)
                {
                    ptr = strtok(NULL, "\n");
                    if (ptr != NULL)
                    {
                        if(strcmp(ptr,"Yes") == 0)
                        {
                            AppConfig_Garden[gardenID].temperatureMonitoring = true;
                            App_Config_Log_Message("Temperature module activated!", APP_LOG_INFO);
                        }
                        else if(strcmp(ptr,"No") == 0)
                        {
                            AppConfig_Garden[gardenID].temperatureMonitoring = false;
                            App_Config_Log_Message("Temperature module deactivated!", APP_LOG_INFO);
                        }
                        else
                        {
                            AppConfig_Garden[gardenID].temperatureMonitoring = false;
                            App_Config_Log_Message("Temperature module deactivated!", APP_LOG_INFO);
                        }  
                    }
                }

                else if(strcmp(ptr, "Humidity Monitoring") == 0)
                {
                    ptr = strtok(NULL, "\n");
                    if (ptr != NULL)
                    {
                        if(strcmp(ptr,"Yes") == 0)
                        {
                            AppConfig_Garden[gardenID].humidityMonitoring = true;
                            App_Config_Log_Message("Humidity module activated!", APP_LOG_INFO);
                        }
                        else if(strcmp(ptr,"No") == 0)
                        {
                            AppConfig_Garden[gardenID].humidityMonitoring = false;
                            App_Config_Log_Message("Humidity module deactivated!", APP_LOG_INFO);
                        }
                        else
                        {
                            AppConfig_Garden[gardenID].humidityMonitoring = false;
                            App_Config_Log_Message("Humidity module deactivated!", APP_LOG_INFO);
                        }    
                    } 
                }

                else if(strcmp(ptr, "Light Monitoring") == 0)
                {
                    ptr = strtok(NULL, "\n");
                    if (ptr != NULL)
                    {
                        if(strcmp(ptr,"Yes") == 0)
                        {
                            AppConfig_Garden[gardenID].lightMonitoring = true;
                            App_Config_Log_Message("Light module activated!", APP_LOG_INFO);
                        }
                        else if(strcmp(ptr,"No") == 0)
                        {
                            AppConfig_Garden[gardenID].lightMonitoring = false;
                            App_Config_Log_Message("Light module deactivated!", APP_LOG_INFO);
                        }
                        else
                        {
                            AppConfig_Garden[gardenID].lightMonitoring = false;
                            App_Config_Log_Message("Light module deactivated!", APP_LOG_INFO);
                        }    
                    }                    
                }

                else if (strcmp(ptr, "Irrigation") == 0)
                {
                    ptr = strtok(NULL, "\n");
                    if (ptr != NULL)
                    {
                        if(strcmp(ptr,"Yes") == 0)
                        {
                            AppConfig_Garden[gardenID].irrigation = true;
                            App_Config_Log_Message("Irrigation module activated!", APP_LOG_INFO);
                        }
                        else if(strcmp(ptr,"No") == 0)
                        {
                            AppConfig_Garden[gardenID].irrigation = false;
                            App_Config_Log_Message("Irrigation module deactivated!", APP_LOG_INFO);
                        }
                        else
                        {
                            AppConfig_Garden[gardenID].irrigation = false;
                            App_Config_Log_Message("Irrigation module deactivated!", APP_LOG_INFO);
                        }
                    }
                }

                else if ((strcmp(ptr, "///////////////\n") == 0) || (strcmp(ptr, "///////////////") == 0))
                {
                    ptr = strtok(NULL, "\n");
                    App_Config_Log_Message("----------------------------", APP_LOG_INFO);
                }

                else
                {
                    for(gardenID = 0; gardenID < APP_CONFIG_NR_GARDENS; gardenID ++)
                    {
                        AppConfig_Garden[gardenID].cover_motor = false;
                        AppConfig_Garden[gardenID].humidityMonitoring = false;
                        AppConfig_Garden[gardenID].irrigation = false;
                        AppConfig_Garden[gardenID].lightMonitoring = false;
                        AppConfig_Garden[gardenID].temperatureMonitoring = false;
                    }
                    App_Config_Log_Message("All modules are deactivated! Configuration error!", APP_LOG_ERROR); 
                    break;
                }
            }        
        }
    }
    else
    {
        for(gardenID = 0; gardenID < APP_CONFIG_NR_GARDENS; gardenID ++)
        {
            AppConfig_Garden[gardenID].cover_motor = false;
            AppConfig_Garden[gardenID].humidityMonitoring = false;
            AppConfig_Garden[gardenID].irrigation = false;
            AppConfig_Garden[gardenID].lightMonitoring = false;
            AppConfig_Garden[gardenID].temperatureMonitoring = false;
        }
        App_Config_Log_Message("All modules are deactivated! Can not open the file!", APP_LOG_ERROR);     
    }
    
    fclose(configuration);

}

void App_Config_Log_Message(const char message[], tAppMain_LogMessageType messageType)
{
    FILE *newConfig;
    newConfig = fopen("D:/Internship_Benoli/FarmingSimulator/App_main/src/log.txt", "a");
    App_Time_GetCurrentDate(&log_info.year, &log_info.month, &log_info.day);
    App_Time_GetCurrentTime(&log_info.Hour, &log_info.minutes, &log_info.seconds);
    
    if (newConfig != NULL) 
    {   
        if(messageType == APP_LOG_INFO)
        {
            fprintf(newConfig,"[%i/%i/%i %i:%i:%i][INFO]%s\n",log_info.year,log_info.month,log_info.day,log_info.Hour, log_info.minutes, log_info.seconds, message);
            printf("[%i/%i/%i %i:%i:%i][INFO]%s\n",log_info.year,log_info.month,log_info.day,log_info.Hour, log_info.minutes, log_info.seconds, message);
        } 
        else if(messageType == APP_LOG_ERROR)
        {
            fprintf(newConfig,"[%i/%i/%i %i:%i:%i][ERROR]%s\n",log_info.year,log_info.month,log_info.day,log_info.Hour, log_info.minutes, log_info.seconds, message);
            printf("[%i/%i/%i %i:%i:%i][INFO]%s\n",log_info.year,log_info.month,log_info.day,log_info.Hour, log_info.minutes, log_info.seconds, message);
        }
    }

    fclose(newConfig);
}
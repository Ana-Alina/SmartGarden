#ifndef APP_MAIN_EXTERNAL_H
#define APP_MAIN_EXTERNAL_H

#include<stdio.h>
#include<stdbool.h>

#define APP_CONFIG_NR_GARDENS 2
#define APP_CONFIG_NR_SENSORS 2

extern char source_file[64];

typedef struct{
    
    bool cover_motor;
    bool temperatureMonitoring;
    bool humidityMonitoring;
    bool lightMonitoring;
    bool irrigation;

}tAppConfig_Type;

typedef enum{
    APP_LOG_INFO = 0x00,
    APP_LOG_ERROR = 0x01,
}tAppMain_LogMessageType;

extern tAppMain_LogMessageType AppMain_LogMessage[APP_CONFIG_NR_GARDENS];
extern tAppConfig_Type AppConfig_Garden[APP_CONFIG_NR_GARDENS];
extern void App_Main_Init(void);
extern void App_Config_Init(const char fileSource[]);
extern void App_Config_Log_Message(const char message[], tAppMain_LogMessageType messageType);

#endif




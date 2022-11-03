#include <App_Temp_external.h>
#include<App_Temp_external.h>

bool App_Main_Init_Flag;

void App_Main_Init (void)
{
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config.txt");
    App_Temp_init();
}

#define GOOGLE_TEST_FRAMEWORK 

#ifndef GOOGLE_TEST_FRAMEWORK 

int main()
{

}

#endif

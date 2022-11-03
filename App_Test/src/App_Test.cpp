
#include<gtest/gtest.h>

extern "C"{
#include"AppDatatypes.h"
#include"App_Temp_external.h"
#include"App_Cover_external.h"
#include"App_Cover_internal.h"
#include"App_Stubs_external.h"
#include"App_Irrigation_external.h"
#include"App_main_external.h"

}

void App_Test_InitVariables(void)
{
    // For Sensor1
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, 0);

    // For Sensor2n
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, 0);
}

TEST(App_Temp, Test_1)
{
    tApp_Temp_SetTemperatureType tempReturn;
    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    printf("Test invalid Sensor ID\n");
    tempReturn = App_Temp_SetTemperature(20, 2);

    EXPECT_EQ(tempReturn, APP_TEMP_SENSOR_ID_INVALID);
}


TEST(App_Temp, Test_2)
{
    uint16 counter = 0;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    printf("Verify the sensor 1 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Verify the sensor 1 state and the counter at 2s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Verify the sensor 1 state and the counter at 3s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Verify the sensor 1 state and the counter at 4s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Verify the sensor 1 state and the counter at exact 5s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Verify the sensor 1 state and the counter after 5s\n");
    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_WAITING
    printf("Sensor status is in waiting\n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAITING);
}

TEST(App_Temp, Test_3)
{
    printf("\n Test 3 - App_Temp \n \n");
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_NOK;

    App_Temp_main();
    
    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    printf("Verify the sensor 1 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 1 status is APP_TEMP_SENSOR_STATUS_OK and the counter initialized\n");

    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
}

TEST(App_Temp, Test_6)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    printf("Verify the sensor 1 state and the counter at 4s\n");
    //ACTION: Call App_Temp_Main for 5 second
    for(counter = 0; counter < 400; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 1 status is APP_TEMP_SENSOR_STATUS_OK and the counter initialized\n");

    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
}

TEST(App_Temp, Test_7)
{
    uint16 counter = 0;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    printf("Verify the sensor 2 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Verify the sensor 2 state and the counter at exact 10s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 900; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_OK and sensor 2 counter is 1000
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Verify the sensor 2 state and the counter after 10s\n");
    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_WAITING and sensor 2 counter is 1000
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAITING);
}

TEST(App_Temp, Test_8)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    printf("Verify the sensor 2 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    App_Temp_main();
    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_OK and sensor 2 counter is 0
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
}

TEST(App_Temp, Test_16)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    printf("Verify the sensor 2 state and the counter at 9s\n");
    //ACTION: Call App_Temp_Main for 9 second
    for(counter = 0; counter < 900; counter++)
    {
        App_Temp_main();
    }
    
    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_OK and sensor 2 counter is 900
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

}

TEST(App_Temp, Test_17)
{
    uint16 counter = 0;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_WAITING;

    printf("Verify the sensor 1 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK and sensor 1 counter is 100
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAITING);

    printf("Verify the sensor 1 state and the counter at exact 10s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 900; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK and sensor 1 counter is 1000
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAITING);

    printf("Verify the sensor 1 state and the counter after 10s - Sensor idle\n");
    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_IDLE and sensor 1 counter is 1000
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_IDLE);

}

TEST(App_Temp, Test_18)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_WAITING;

    printf("Verify the sensor 1 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_WAITING and sensor 1 counter is 100
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAITING);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 1 status is APP_TEMP_SENSOR_STATUS_OK and the counter initialized\n");

    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK and sensor 1 counter is 0
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
}

TEST(App_Temp, Test_26)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_WAITING;

    printf("Verify the sensor 1 state and the counter at 9s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 900; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_WAITING and sensor 1 counter is 900
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAITING);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 1 status is APP_TEMP_SENSOR_STATUS_OK and the counter initialized\n");

    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK and sensor 1 counter is 0
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
}

TEST(App_Temp, Test_27)
{
    uint16 counter = 0;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_WAITING;

    printf("Verify the sensor 2 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 2 state is APP_TEMP_SENSOR_WAITING and sensor 2 counter is 100
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAITING);

    printf("Verify the sensor 2 state and the counter at exact 10s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 1900; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 2 state is APP_TEMP_SENSOR_WAITING and sensor 2 counter is 2000
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAITING);

    printf("Verify the sensor 2 state and the counter after 10s\n");
    App_Temp_main();
    // Result: Sensor 2 state is APP_TEMP_SENSOR_IDLE and sensor 2 counter is 2000
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_IDLE);
}

TEST(App_Temp, Test_28)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_WAITING;

    printf("Verify the sensor 2 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAITING);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 2 status is APP_TEMP_SENSOR_STATUS_OK and the counter initialized\n");
    App_Temp_main();
    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_OK and sensor 2 counter is 0
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
}

TEST(App_Temp, Test_46)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_WAITING;

    printf("Verify the sensor 2 state and the counter at 19s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 1900; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_WAITING and sensor 2 counter is 1900
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAITING);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 2 status is APP_TEMP_SENSOR_STATUS_OK and the counter initialized\n");

    App_Temp_main();
    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_OK and sensor 2 counter is 0
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
}

TEST(App_Temp, Test_47)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_IDLE;

    printf("Verify the sensor 1 state\n");

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_IDLE 

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_IDLE);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 1 status is APP_TEMP_SENSOR_STATUS_WAKING\n");

    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_WAKING
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);
}

TEST(App_Temp, Test_48)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_IDLE;

    printf("Verify the sensor 2 state\n");

    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_IDLE 

    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_IDLE);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 2 status is APP_TEMP_SENSOR_STATUS_WAKING\n");

    App_Temp_main();
    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_WAKING
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAKING);
}

TEST(App_Temp, Test_49)
{
    uint16 counter = 0;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_WAKING;

    printf("Verify the sensor 1 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_WAKING and sensor 1 counter is 100
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Verify the sensor 1 state and the counter at 2s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_WAKING and sensor 1 counter is 200
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Verify the sensor 1 state and the counter at 3s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_WAKING and sensor 1 counter is 300
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Verify the sensor 1 state and the counter at 4s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_WAKING and sensor 1 counter is 400
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Verify the sensor 1 state and the counter at exact 5s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_WAKING and sensor 1 counter is 500
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);
    
    printf("Verify the sensor 1 state and the counter after 5s\n");
    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_NOK and sensor 1 counter is 500
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_NOK);
}

TEST(App_Temp, Test_50)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_WAKING;

    printf("Verify the sensor 1 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_WAKING and sensor 1 counter is 100
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 1 status is APP_TEMP_SENSOR_WAKING and the counter initialized\n");

    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_WAKING and sensor 1 counter is 100
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);
}

TEST(App_Temp, Test_51)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_NOK;

    App_Temp_main();

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_WAKING;

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);
    
    for(counter = 0; counter < 100; counter++)
    {
        //if(counter = 99)
        //{
        //    printf("");
        //}
        App_Temp_main();
    }

    tempReturn = App_Temp_SetTemperature(20, 0);
    App_Temp_main();

    for(counter = 0; counter < 100; counter++)
    {
        //if(counter = 99)
        //{
        //    printf("");
        //}
        App_Temp_main();
    }

    tempReturn = App_Temp_SetTemperature(20, 0);
    App_Temp_main();

    for(counter = 0; counter < 100; counter++)
    {
        //if(counter = 99)
        //{
         //   printf("");
        //}
        App_Temp_main();
    }

    tempReturn = App_Temp_SetTemperature(20, 0);
    App_Temp_main();

    for(counter = 0; counter < 96; counter++)
    {

        App_Temp_main();
    }

    tempReturn = App_Temp_SetTemperature(20, 0);
    
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);
 
    App_Temp_main();

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

}

TEST(App_Temp, Test_53)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_WAKING;

    printf("Verify the sensor 1 state and the counter at 4s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 400; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_WAKING and sensor 1 counter is 400
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 1 status is APP_TEMP_SENSOR_WAKING and the counter initialized\n");

    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_WAKING and sensor 1 counter is 100
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_WAKING);
}

TEST(App_Temp, Test_54)
{
    uint16 counter = 0;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_WAKING;

    printf("Verify the sensor 2 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_WAKING and sensor 2 counter is 100
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Verify the sensor 2 state and the counter at 2s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_WAKING and sensor 2 counter is 200
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Verify the sensor 2 state and the counter at 3s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_WAKING and sensor 2 counter is 300
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Verify the sensor 2 state and the counter at 4s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 2 state is APP_TEMP_SENSOR_STATUS_WAKING and sensor 2 counter is 400
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Verify the sensor 2 state and the counter at exact 10s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 600; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_WAKING and sensor 1 counter is 1000
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Verify the sensor 1 state and the counter after 10s\n");
    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_NOK and sensor 1 counter is 1000
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_NOK);
}

TEST(App_Temp, Test_55)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_WAKING;

    printf("Verify the sensor 2 state and the counter at 1s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 100; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 1 state is APP_TEMP_SENSOR_WAKING and sensor 1 counter is 100
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 2 status is APP_TEMP_SENSOR_WAKING and the counter initialized\n");

    App_Temp_main();
    // Result: Sensor 2 state is APP_TEMP_SENSOR_WAKING and sensor 2 counter is 101
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAKING);
}


TEST(App_Temp, Test_63)
{
    uint16 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[1].sensor_status = APP_TEMP_SENSOR_WAKING;

    printf("Verify the sensor 2 state and the counter at 9s\n");
    //ACTION: Call App_Temp_Main for 1 second
    for(counter = 0; counter < 900; counter++)
    {
        App_Temp_main();
    }

    // Result: Sensor 2 state is APP_TEMP_SENSOR_WAKING and sensor 2 counter is 900
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAKING);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 2 status is APP_TEMP_SENSOR_WAKING and the counter initialized\n");

    App_Temp_main();
    // Result: Sensor 2 state is APP_TEMP_SENSOR_WAKING and sensor 2 counter is 901
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_WAKING);
}

TEST(App_Temp, Test_64)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    printf("Verify the sensor 1 state \n");

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 1 status is APP_TEMP_SENSOR_STATUS_OK\n");


    App_Temp_main(); 

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20.5, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 1 status is APP_TEMP_SENSOR_STATUS_OK\n"); 

    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

}

TEST(App_Temp, Test_65)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    printf("Verify the sensor 2 state \n");

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

   printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 2 status is APP_TEMP_SENSOR_STATUS_OK\n");


    App_Temp_main(); 

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(20.5, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Sensor 2 status is APP_TEMP_SENSOR_STATUS_OK\n"); 

    App_Temp_main();
    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

}

TEST(App_Temp, Test_66)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    tempReturn = App_Temp_SetTemperature(20, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(19.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(19, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(18.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(18, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(17.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(17, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(16.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(16, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(15.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(15, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(14.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(14, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(13.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(13, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(12.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(12, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(11.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(11, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(3.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(3, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(2.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(2, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(1.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(1, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(0.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(0, 0);
    App_Cover_Main();

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    App_Temp_main();

    tempReturn = App_Temp_SetTemperature(-1, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_INVALID_TEMPERATURE_VALUE);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_INVALID_TEMPERATURE_VALUE\n");

    printf("Sensor 1 status is APP_TEMP_SENSOR_NOK\n");
    App_Temp_main();
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_NOK);
}

TEST(App_Temp, Test_67)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    tempReturn = App_Temp_SetTemperature(-1, 1);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(-1.5, 0);
    App_Cover_Main();

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    App_Temp_main();

    tempReturn = App_Temp_SetTemperature(0, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_INVALID_TEMPERATURE_VALUE);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_INVALID_TEMPERATURE_VALUE\n");

    printf("Sensor 2 status is APP_TEMP_SENSOR_OK\n");
    App_Temp_main();
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_NOK);
}

TEST(App_Temp, Test_68)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    printf("Verify the sensor 1 state \n");
    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(-1, 0);
    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_STATUS_OK;
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(-0.5, 0);
    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_STATUS_OK;
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(0, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    printf("Sensor 1 status is APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    App_Temp_main();

    tempReturn = App_Temp_SetTemperature(-0.5, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    printf("Sensor 1 status is APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    printf("Sensor 1 status is APP_TEMP_SENSOR_STATUS_OK\n");
    App_Temp_main();
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
}

TEST(App_Temp, Test_69)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    printf("Verify the sensor 2 state \n");
    // Result: Sensor 1 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    tempReturn = App_Temp_SetTemperature(0, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    printf("Sensor 2 status is APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    App_Temp_main();

    tempReturn = App_Temp_SetTemperature(0.5, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    printf("Sensor 2 status is APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    printf("Sensor 2 status is APP_TEMP_SENSOR_STATUS_OK\n");
    App_Temp_main();
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
}

TEST(App_Temp, Test_70)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    tempReturn = App_Temp_SetTemperature(0, 1);

    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    App_Temp_main();

    tempReturn = App_Temp_SetTemperature(-1, 1);

    EXPECT_EQ(tempReturn, APP_TEMP_INVALID_TEMPERATURE_VALUE);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_INVALID_TEMPERATURE_VALUE\n");

    printf("Sensor 1 status is APP_TEMP_SENSOR_NOK\n");
    App_Temp_main();
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_NOK);
}

TEST(App_Temp, Test_71)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();

    tempReturn = App_Temp_SetTemperature(-0.5, 0);
    App_Temp_main();
    tempReturn = App_Temp_SetTemperature(0, 0);

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");

    App_Temp_main();

    tempReturn = App_Temp_SetTemperature(1, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_INVALID_TEMPERATURE_VALUE);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_INVALID_TEMPERATURE_VALUE\n");

    printf("Sensor 1 status is APP_TEMP_SENSOR_NOK\n");
    App_Temp_main();
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_NOK);
}


void App_Test_Init_Cover(void)
{
    //For Sensor 0
        EXPECT_EQ(AppCover_sensorStatusGarden[0].sensorStatus, 0);
        EXPECT_EQ(AppCover_sensorStatusGarden[0].temp, 0);

    //For Sensor 1
        EXPECT_EQ(AppCover_sensorStatusGarden[1].sensorStatus, 0);
        EXPECT_EQ(AppCover_sensorStatusGarden[1].temp, 0);
}

TEST(App_Cover, Test_1)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_NOK;
    App_Temp_main();
    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    STUB_StartOpeningCoverRequest = false;

    tempReturn = App_Temp_SetTemperature(1, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(1.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(2, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(2.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(3, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(3.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with invalid temperature, result should be STUB_StartOpeningCoverRequest is false\n");
    
    App_Cover_Main();
    EXPECT_EQ(STUB_StartOpeningCoverRequest, false);
    EXPECT_EQ(STUB_StartOpeningCoverGarden, 0);

}

TEST(App_Cover, Test_2)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature, result should be STUB_StartOpeningCoverRequest is true\n");
    
    App_Cover_Main();
    EXPECT_EQ(STUB_StartOpeningCoverRequest, true);
    EXPECT_EQ(STUB_StartOpeningCoverGarden, 0);

}

TEST(App_Cover, Test_3)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    STUB_StartOpeningCoverResult = true;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature, result should be STUB_StartOpeningCoverRequest is true\n");
    
    App_Cover_Main();
    EXPECT_EQ(STUB_StartOpeningCoverRequest, true);
    EXPECT_EQ(STUB_StartOpeningCoverGarden, 0);

    printf("Set STUB_StartOpeningCoverResult true, result should be STUB_StartOpeningCoverResult is true\n");
    EXPECT_EQ(STUB_StartOpeningCoverResult, true);

    printf("App_Cover_CoverPosition, result should be APP_COVER_COVER_MOVING\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

}

TEST(App_Cover, Test_4)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    STUB_StartOpeningCoverResult = true;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature, result should be STUB_StartOpeningCoverRequest is true\n");
    
    App_Cover_Main();

    EXPECT_EQ(STUB_StartOpeningCoverRequest, true);
    EXPECT_EQ(STUB_StartOpeningCoverGarden, 0);

    printf("Check STUB_GetMotorStatusMotorStatus\n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_IDLE_STATUS);

    printf("App_Cover_CoverPosition, result should be APP_COVER_COVER_MOVING\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

}

TEST(App_Cover, Test_5)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_MOVING;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("STUB_GetMotorStatusMotorStatus shall be APP_MOTOR_MOVING \n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_MOVING);

    printf("App_Cover_CoverPosition, result should be APP_COVER_COVER_MOVING\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

}

TEST(App_Cover, Test_6)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    App_Cover_CoverPosition[0] = APP_COVER_COVER_MOVING;

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_FINISHED;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("STUB_GetMotorStatusMotorStatus  shall be APP_ MOTOR_FINISHED \n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_FINISHED);

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_CLOSED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_CLOSED);
    
}

TEST(App_Cover, Test_7)
{
    tApp_Temp_SetTemperatureType tempReturn;
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    App_Cover_CoverPosition[0] = APP_COVER_COVER_MOVING;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("STUB_GetMotorStatusMotorStatus  shall be APP_MOTOR_ERROR \n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_ERROR);

    printf("App_Cover_CoverPosition, result should be APP_COVER_ERROR\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_ERROR);

}

/*
void App_Test_Case_8_Cover(void)
{
    UT_SET_TEST("Test case 8 - Cover");

    uint8 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_IDLE_STATUS;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    UT_CHECK_RESULT(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4, 0);
    UT_CHECK_RESULT(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Verify the sensor 0 counter, at every 10s\n");
    for(counter = 0; counter < 100; counter++)
    {
        App_Cover_Main();
    }

    for(counter = 0; counter < 100; counter++)
    {
        App_Cover_Main();
    }

    App_Temp_GetSensorStatus (&AppCover_sensorStatusGarden[0].sensorStatus, 0);
    App_Temp_GetTemperature (&AppCover_sensorStatusGarden[0].temp, 0);
    
    UT_CHECK_RESULT(coverCounter, 200);

    App_Cover_Main();

    UT_CHECK_RESULT(coverCounter, 0);

    for(counter = 0; counter < 100; counter++)
    {
        App_Cover_Main();
    }

    UT_CHECK_RESULT(coverCounter, 100);

}*/

/*void App_Test_Case_9_Cover(void)
{
    UT_SET_TEST("Test case 9 - Cover");

    uint8 counter = 0;
    tApp_Temp_SetTemperatureType tempReturn;
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_IDLE_STATUS;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    printf("Verify the sensor 1 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    UT_CHECK_RESULT(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4, 1);
    UT_CHECK_RESULT(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Verify the sensor 0 counter, at every 10s\n");
    for(counter = 0; counter < 100; counter++)
    {
        App_Cover_Main();
    }

    for(counter = 0; counter < 100; counter++)
    {
        App_Cover_Main();
    }

    App_Temp_GetSensorStatus (&AppCover_sensorStatusGarden[1].sensorStatus, 0);
    App_Temp_GetTemperature (&AppCover_sensorStatusGarden[1].temp, 0);
    
    UT_CHECK_RESULT(coverCounter, 200);

    App_Cover_Main();

    UT_CHECK_RESULT(coverCounter, 0);

    for(counter = 0; counter < 100; counter++)
    {
        App_Cover_Main();
    }

    UT_CHECK_RESULT(coverCounter, 100);
}*/


TEST(App_Cover, Test_10)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    STUB_StartOpeningCoverResult = true;

    printf("Verify the sensor 0 state, resoul should be APP_TEMP_SENSOR_STATUS_OK\n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    
    App_Cover_Main();

    printf("Current temperature should be 4");

    EXPECT_EQ(AppCover_sensorStatusGarden[0].temp, 4);

}

TEST(App_Cover, Test_11)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    STUB_StartOpeningCoverResult = true;
    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_NOK;

    printf("Verify the sensor 0 state, resoul should be APP_TEMP_SENSOR_STATUS_OK\n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_NOK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    
    App_Cover_Main();

    printf("Current temperature should be APP_TEMP_SENSOR_STATUS_NOK");

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_NOK);
}

TEST(App_Cover, Test_12)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    App_Cover_Main();

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_MOVING;

    printf("Verify the sensor 1 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[1].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(-1, 1);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(-0.5, 1);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(1, 1);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(1.5, 1);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(2, 1);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(2.5, 1);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(3, 1);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(3.5, 1);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 1);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("STUB_GetMotorStatusMotorStatus shall be APP_MOTOR_MOVING \n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_MOVING);

    printf("App_Cover_CoverPosition, result should be APP_COVER_COVER_OPEN\n");
    EXPECT_EQ(App_Cover_CoverPosition[1], APP_COVER_COVER_OPEN);

}

TEST(App_Cover, Test_13)
{
    tApp_Temp_SetTemperatureType tempReturn;
    
    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    App_Cover_CoverPosition[0] = APP_COVER_CLOSED; 
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_MOVING; 
    AppCover_sensorStatusGarden[0].sensorStatus = APP_TEMP_SENSOR_STATUS_OK;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Call App_Cover_Main with valid temperature\n");
    tempReturn = App_Temp_SetTemperature(4, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();    
    tempReturn = App_Temp_SetTemperature(11, 0);
    AppCover_sensorStatusGarden[0].temp = 11;

    uint16 loop = 0;

    for(loop = 0; loop < 1200; loop++)
    {
        App_Cover_Main();
    }

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);  

    App_Cover_Main();

    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_MOVING);
    printf("STUB_StartOpeningCoverRequest should be true and cover position should be in moving\n");
    EXPECT_EQ(STUB_StartOpeningCoverRequest, true);
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
}

TEST(App_Cover, Test_14)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    App_Cover_CoverPosition[0] = APP_COVER_CLOSED;
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_MOVING; 
    AppCover_sensorStatusGarden[0].sensorStatus = APP_TEMP_SENSOR_STATUS_OK;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    tempReturn = App_Temp_SetTemperature(11, 0);
    AppCover_sensorStatusGarden[0].temp = 11;

    uint16 loop;
    
    for(loop = 0; loop < 1200; loop++)
    {
        App_Cover_Main();
    }

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    App_Cover_Main();

    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_MOVING);
    printf("App_Cover_CoverPosition, result should be APP_COVER_COVER_MOVING\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
}

TEST(App_Cover, Test_15)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();


    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(11, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    App_Cover_Main();

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_FINISHED;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();    
    tempReturn = App_Temp_SetTemperature(11, 0);

    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    
    App_Cover_Main();

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_CLOSED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_CLOSED);

    AppCover_sensorStatusGarden[0].sensorStatus = APP_TEMP_SENSOR_STATUS_OK;

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_CLOSED);
    
    uint16 loop;
    
    for(loop = 0; loop < 1293; loop++)
    {

        App_Cover_Main();
    }

    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    App_Cover_Main();

    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

    
}

TEST(App_Cover, Test_16)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    //App_Cover_Previous_CoverPosition[0] = APP_COVER_COVER_OPEN;
    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(11, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    App_Cover_Main();

    printf("Motor status is in ERROR and Cover position in ERROR \n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_ERROR);
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_ERROR);

    App_Cover_Main();   
    App_Cover_Main();

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_OPENED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_OPEN);
    
}

TEST(App_Cover, Test_17)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    //App_Cover_Previous_CoverPosition[0] = APP_COVER_COVER_OPEN;
    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    App_Cover_Main();

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    App_Cover_Main();

    printf("Motor status is in ERROR and Cover position in ERROR \n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_ERROR);
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_ERROR);
    
    App_Cover_Main();

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_OPENED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_OPEN);
    
}

TEST(App_Cover, Test_18)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    //App_Cover_Previous_CoverPosition[0] = APP_COVER_COVER_OPEN;
    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    App_Cover_Main();

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    App_Cover_Main();

    printf("Motor status is in ERROR and Cover position in ERROR \n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_ERROR);
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_ERROR);

    uint8 loop = 0;
    for(loop = 0; loop < 2; loop++)
    {
        App_Cover_CoverPosition[0] = APP_COVER_ERROR;
        STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
        App_Cover_Movement[0] = APP_MOVE_OPENING;
        STUB_GetErrorErrorCode = APP_MOTOR_STATUS_OK;   
        App_Cover_Main();
    }

    printf("APP_ERROR_MOTOR_UNKNOWN_ERROR\n");
    EXPECT_EQ(STUB_SetDefectDefects, APP_ERROR_MOTOR_UNKNOWN_ERROR);

}

TEST(App_Cover, Test_19)
{
    tApp_Temp_SetTemperatureType tempReturn;

 // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    //App_Cover_Previous_CoverPosition[0] = APP_COVER_COVER_OPEN;
    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    App_Cover_Main();

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    App_Cover_Main();

    printf("Motor status is in ERROR and Cover position in ERROR \n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_ERROR);
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_ERROR);

    uint8 loop = 0;

    for(loop = 0; loop < 4; loop++)
    {
        App_Cover_CoverPosition[0] = APP_COVER_ERROR;
        STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
        App_Cover_Movement[0] = APP_MOVE_OPENING;
        STUB_GetErrorErrorCode = APP_MOTOR_BLOCKED_STATUS;
        App_Cover_Main();
    }

    printf("APP_ERROR_MOTOR_BLOCKED\n");
    EXPECT_EQ(STUB_SetDefectDefects, APP_ERROR_MOTOR_BLOCKED);

}

TEST(App_Cover, Test_21)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    STUB_GetErrorErrorCounter = 0;

    //App_Cover_Previous_CoverPosition[0] = APP_COVER_COVER_OPEN;
    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    App_Cover_Main();

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    App_Cover_Main();

    printf("Motor status is in ERROR and Cover position in ERROR \n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_ERROR);
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_ERROR);

    App_Cover_Movement[0] = APP_MOVE_OPENING;
    STUB_GetErrorErrorCode = APP_MOTOR_MOTOR_NOT_RESPONDING;

    uint8 loop = 0;

    for (loop = 0; loop < 4; loop ++)
    {   
        App_Cover_CoverPosition[0] = APP_COVER_ERROR;
        STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
        App_Cover_Movement[0] = APP_MOVE_OPENING;
        STUB_GetErrorErrorCode = APP_MOTOR_MOTOR_NOT_RESPONDING;
        App_Cover_Main();
    }
           
    printf("APP_ERROR_MOTOR_NOT_RESPONDING\n");
    EXPECT_EQ(STUB_SetDefectDefects, APP_ERROR_MOTOR_NOT_RESPONDING);

    EXPECT_EQ(STUB_GetErrorErrorCounter, 1);
}

TEST(App_Cover, Test_22)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    STUB_GetErrorErrorCounter = 0;

    //App_Cover_Previous_CoverPosition[0] = APP_COVER_COVER_OPEN;
    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    App_Cover_Main();

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    App_Cover_Main();

    printf("Motor status is in ERROR and Cover position in ERROR \n");
    EXPECT_EQ(STUB_GetMotorStatusMotorStatus, APP_MOTOR_ERROR);
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_ERROR);

    App_Cover_Movement[0] = APP_MOVE_OPENING;
    STUB_GetErrorErrorCode = APP_MOTOR_UNKNOWN_ERROR;

    uint8 loop = 0;

    for (loop = 0; loop < 4; loop ++)
    {   
        App_Cover_CoverPosition[0] = APP_COVER_ERROR;
        STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
        App_Cover_Movement[0] = APP_MOVE_OPENING;
        STUB_GetErrorErrorCode = APP_MOTOR_UNKNOWN_ERROR;
        App_Cover_Main();
    }
           
    printf("APP_ERROR_MOTOR_NOT_RESPONDING\n");
    EXPECT_EQ(STUB_SetDefectDefects, APP_ERROR_MOTOR_UNKNOWN_ERROR);
    printf("\n\n\n");
}

TEST(App_Cover, Test_23)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    App_Cover_Main();

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_FINISHED;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();    
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_CLOSED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_CLOSED);

    AppCover_sensorStatusGarden[0].sensorStatus = APP_TEMP_SENSOR_STATUS_OK;

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    tempReturn = App_Temp_SetTemperature(11, 0);
    AppCover_sensorStatusGarden[0].temp = 11;

    uint16 loop;
    
    for(loop = 0; loop < 1201; loop++)
    {
        App_Cover_Main();
    }

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;


    uint8 loop2 = 0;

    for(loop2 = 0; loop2 < 3; loop2++)
    { 
        App_Cover_CoverPosition[0] = APP_COVER_ERROR;
        STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
        App_Cover_Movement[0] = APP_MOVE_CLOSING;
        STUB_GetErrorErrorCode = APP_MOTOR_STATUS_OK;
        App_Cover_Main();
    }

    App_Cover_CoverPosition[0] = APP_COVER_ERROR;
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
    App_Cover_Movement[0] = APP_MOVE_CLOSING;
    STUB_GetErrorErrorCode = APP_MOTOR_STATUS_OK;
    App_Cover_Main();
    EXPECT_EQ(STUB_SetDefectDefects, APP_ERROR_MOTOR_UNKNOWN_ERROR);

    printf("\n\n\n");

}

TEST(App_Cover, Test_24)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(11, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_FINISHED;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();    
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_CLOSED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_CLOSED);

    AppCover_sensorStatusGarden[0].sensorStatus = APP_TEMP_SENSOR_STATUS_OK;

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    tempReturn = App_Temp_SetTemperature(11, 0);
    AppCover_sensorStatusGarden[0].temp = 11;

    uint16 loop;
    
    for(loop = 0; loop < 1201; loop++)
    {
        App_Cover_Main();
    }

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    uint8 loop2 = 0;

    for(loop2 = 0; loop2 < 3; loop2++)
    {
        App_Cover_CoverPosition[0] = APP_COVER_ERROR;
        STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
        App_Cover_Movement[0] = APP_MOVE_CLOSING;
        STUB_GetErrorErrorCode = APP_MOTOR_BLOCKED_STATUS;   
        App_Cover_Main();
    }

    App_Cover_CoverPosition[0] = APP_COVER_ERROR;
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
    App_Cover_Movement[0] = APP_MOVE_CLOSING;
    STUB_GetErrorErrorCode = APP_MOTOR_BLOCKED_STATUS;

    App_Cover_Main();

    printf("APP_ERROR_MOTOR_UNKNOWN_ERROR\n");
    EXPECT_EQ(STUB_SetDefectDefects, APP_ERROR_MOTOR_BLOCKED);

}

TEST(App_Cover, Test_25)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(11, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_FINISHED;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();    
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_CLOSED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_CLOSED);

    AppCover_sensorStatusGarden[0].sensorStatus = APP_TEMP_SENSOR_STATUS_OK;

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    tempReturn = App_Temp_SetTemperature(11, 0);
    AppCover_sensorStatusGarden[0].temp = 11;

    uint16 loop;
    
    for(loop = 0; loop < 1201; loop++)
    {
        App_Cover_Main();
    }

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    uint8 loop2 = 0;

    for(loop2 = 0; loop2 < 3; loop2++)
    {
        App_Cover_CoverPosition[0] = APP_COVER_ERROR;
        STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
        App_Cover_Movement[0] = APP_MOVE_CLOSING;
        STUB_GetErrorErrorCode = APP_MOTOR_UNKNOWN_ERROR;   
        App_Cover_Main();
    }

    App_Cover_CoverPosition[0] = APP_COVER_ERROR;
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
    App_Cover_Movement[0] = APP_MOVE_CLOSING;
    STUB_GetErrorErrorCode = APP_MOTOR_UNKNOWN_ERROR;

    App_Cover_Main();

    printf("APP_ERROR_MOTOR_UNKNOWN_ERROR\n");
    EXPECT_EQ(STUB_SetDefectDefects, APP_ERROR_MOTOR_UNKNOWN_ERROR);

}

TEST(App_Cover, Test_26)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

        App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(11, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_FINISHED;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();    
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_CLOSED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_CLOSED);

    AppCover_sensorStatusGarden[0].sensorStatus = APP_TEMP_SENSOR_STATUS_OK;

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    tempReturn = App_Temp_SetTemperature(11, 0);
    AppCover_sensorStatusGarden[0].temp = 11;

    uint16 loop;
    
    for(loop = 0; loop < 1201; loop++)
    {
        App_Cover_Main();
    }

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    uint8 loop2 = 0;

    for(loop2 = 0; loop2 < 3; loop2++)
    {
        App_Cover_CoverPosition[0] = APP_COVER_ERROR;
        STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
        App_Cover_Movement[0] = APP_MOVE_CLOSING;
        STUB_GetErrorErrorCode = APP_MOTOR_BLOCKED_STATUS;   
        App_Cover_Main();
    }

    App_Cover_CoverPosition[0] = APP_COVER_ERROR;
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
    App_Cover_Movement[0] = APP_MOVE_CLOSING;
    STUB_GetErrorErrorCode = APP_MOTOR_BLOCKED_STATUS;

    App_Cover_Main();

    printf("APP_ERROR_MOTOR_UNKNOWN_ERROR\n");
    EXPECT_EQ(STUB_SetDefectDefects, APP_ERROR_MOTOR_BLOCKED);

}

TEST(App_Cover, Test_27)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

        App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(11, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_FINISHED;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();    
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_CLOSED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_CLOSED);

    AppCover_sensorStatusGarden[0].sensorStatus = APP_TEMP_SENSOR_STATUS_OK;

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    tempReturn = App_Temp_SetTemperature(11, 0);
    AppCover_sensorStatusGarden[0].temp = 11;

    uint16 loop;
    
    for(loop = 0; loop < 1201; loop++)
    {
        App_Cover_Main();
    }

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    uint8 loop2 = 0;

    for(loop2 = 0; loop2 < 3; loop2++)
    {
        App_Cover_CoverPosition[0] = APP_COVER_ERROR;
        STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
        App_Cover_Movement[0] = APP_MOVE_CLOSING;
        STUB_GetErrorErrorCode = APP_MOTOR_MOTOR_NOT_RESPONDING;   
        App_Cover_Main();
    }

    App_Cover_CoverPosition[0] = APP_COVER_ERROR;
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;
    App_Cover_Movement[0] = APP_MOVE_CLOSING;
    STUB_GetErrorErrorCode = APP_MOTOR_MOTOR_NOT_RESPONDING;

    App_Cover_Main();

    printf("APP_ERROR_MOTOR_UNKNOWN_ERROR\n");
    EXPECT_EQ(STUB_SetDefectDefects, APP_ERROR_MOTOR_NOT_RESPONDING);

}

TEST(App_Cover, Test_28)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

        App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(11, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_FINISHED;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();    
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_CLOSED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_CLOSED);

    AppCover_sensorStatusGarden[0].sensorStatus = APP_TEMP_SENSOR_STATUS_OK;

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    tempReturn = App_Temp_SetTemperature(11, 0);
    AppCover_sensorStatusGarden[0].temp = 11;

    uint16 loop;
    
    for(loop = 0; loop < 1201; loop++)
    {
        App_Cover_Main();
    }

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_FINISHED;

    App_Cover_Main();

    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_OPEN);

}

TEST(App_Cover, Test_29)
{
    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    App_Cover_CoverPosition[0] = APP_COVER_COVER_OPEN;

    tempReturn = App_Temp_SetTemperature(11, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(4, 0);
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);
    STUB_StartOpeningCoverResult = true;
    printf("Verify the sensor 0 state \n");
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    printf("Previous position is OPEN and curent position is MOVING \n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);

    STUB_GetMotorStatusMotorStatus = APP_MOTOR_FINISHED;

    printf("Verify the sensor 0 state \n");
    // Result: Sensor 0 state is APP_TEMP_SENSOR_STATUS_OK 
    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);
    
    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    
    tempReturn = App_Temp_SetTemperature(4.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(5.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(6.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(7.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(8.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(9.5, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10, 0);
    App_Cover_Main();
    tempReturn = App_Temp_SetTemperature(10.5, 0);
    App_Cover_Main();    
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    printf("Call App_Cover_Main with valid temperature\n");
    
    App_Cover_Main();

    printf("App_Cover_CoverPosition, result should be APP_APP_COVER_CLOSED\n");
    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_CLOSED);

    AppCover_sensorStatusGarden[0].sensorStatus = APP_TEMP_SENSOR_STATUS_OK;

    EXPECT_EQ(App_Temp_Main_Struct[0].sensor_status, APP_TEMP_SENSOR_STATUS_OK);

    tempReturn = App_Temp_SetTemperature(11, 0);
    AppCover_sensorStatusGarden[0].temp = 11;

    uint16 loop;
    
    for(loop = 0; loop < 1201; loop++)
    {
        App_Cover_Main();
    }

    printf("Call App_Temp_SetTemperature with valid temperature, result should be APP_TEMP_VALID_TEMPERATURE_VALUE\n");
    tempReturn = App_Temp_SetTemperature(11, 0);
    EXPECT_EQ(tempReturn, APP_TEMP_VALID_TEMPERATURE_VALUE);

    EXPECT_EQ(App_Cover_CoverPosition[0], APP_COVER_COVER_MOVING);
    STUB_GetMotorStatusMotorStatus = APP_MOTOR_ERROR;

    App_Cover_Main();

    EXPECT_EQ(App_Cover_Movement[0], APP_MOVE_CLOSING);

}


 TEST(App_Temp, Test_73)
{
    printf("\n\n\n Test 73 - App_Temp \n\n\n");

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();

    tApp_Temp_SetTemperatureType tempReturn;
    uint8 setTempcounter;
    
    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 8;
    STUB_Temp_History_day = 17;
    STUB_Temp_History_Hour = 11;
    STUB_Temp_History_minutes = 59;
    STUB_Temp_History_seconds = 50;
    
    tempReturn = App_Temp_SetTemperature(11, 0);
    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    uint16 loop = 0;
    for(loop = 0;loop < 60000; loop++)
    {
        if(setTempcounter == 100)
        {
            tempReturn = App_Temp_SetTemperature(10.5, 0);
            setTempcounter = 0;
        }
        else
        {
            setTempcounter++;
        }

        App_Temp_main();
    }
    
    App_Temp_main();

    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].temperature, 10.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].year, 2022);
 
}

TEST(App_Temp, Test_74)
{
    printf("\n\n\n Test 74 - App_Temp \n\n\n");

    tApp_Temp_SetTemperatureType tempReturn;
    uint16 loop;
    uint8 setTempcounter = 0;
    tApp_Temp_HistoryType historyReturn[APP_TEMP_MAXLEN];
    uint8 nrPosition = 0;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    
    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 8;
    STUB_Temp_History_day = 17;
    STUB_Temp_History_Hour = 11;
    STUB_Temp_History_minutes = 59;
    STUB_Temp_History_seconds = 50;
    tempReturn = App_Temp_SetTemperature(11, 0);

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    for(loop = 0;loop < 60000; loop++)
    {
        if(setTempcounter == 100)
        {
            tempReturn = App_Temp_SetTemperature(10.5, 0);
            setTempcounter = 0;
        }
        else
        {
            setTempcounter++;
        }

        App_Temp_main();
    }

    App_Temp_main();

    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].temperature, 10.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].year, 2022);

    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 8;
    STUB_Temp_History_day = 23;
    STUB_Temp_History_Hour = 11;
    STUB_Temp_History_minutes = 11;
    STUB_Temp_History_seconds = 23;
    tempReturn = App_Temp_SetTemperature(11, 0);

    App_Temp_Main_Struct[0]. sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    for(loop = 0;loop < 60000; loop++)
    {
        if(setTempcounter == 100)
        {
            tempReturn = App_Temp_SetTemperature(11.5, 0);
            setTempcounter = 0;
        }
        else
        {
            setTempcounter++;
        }

        App_Temp_main();
    }

    App_Temp_main();

    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].temperature, 11.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].year, 2022);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].temperature, 10.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].year, 2022);


    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 8;
    STUB_Temp_History_day = 12;
    STUB_Temp_History_Hour = 11;
    STUB_Temp_History_minutes = 12;
    STUB_Temp_History_seconds = 23;
    tempReturn = App_Temp_SetTemperature(12, 0);

    App_Temp_Main_Struct[0]. sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    for(loop = 0;loop < 60000; loop++)
    {
        if(setTempcounter == 100)
        {
            tempReturn = App_Temp_SetTemperature(12.5, 0);
            setTempcounter = 0;
        }
        else
        {
            setTempcounter++;
        }

        App_Temp_main();
    }

    App_Temp_main();

    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].temperature, 12.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].year, 2022);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].day, 12);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].temperature, 11.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].year, 2022);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[2].temperature, 10.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[2].year, 2022);

    App_Temp_GetNumberTempHistory(&nrPosition, 0);
    
    EXPECT_EQ(nrPosition, 3);
    App_Temp_GetTempHistory(historyReturn, 0, APP_TEMP_HISTORY_POS1);

    App_Temp_main();  
}

TEST(App_Temp, Test_75)
{
    printf("\n\n\n Test 75 - App_Temp \n\n\n");

    tApp_Temp_SetTemperatureType tempReturn;
    uint16 loop;
    uint8 setTempcounter = 0;
    tApp_Temp_HistoryType historyReturn;
    uint8 nrPosition = 0;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    
    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 8;
    STUB_Temp_History_day = 17;
    STUB_Temp_History_Hour = 11;
    STUB_Temp_History_minutes = 59;
    STUB_Temp_History_seconds = 50;

    tempReturn = App_Temp_SetTemperature(12, 0);
    App_Temp_main();
    tempReturn = App_Temp_SetTemperature(11.5, 0);
    App_Temp_main();
    tempReturn = App_Temp_SetTemperature(11, 0); 

    App_Temp_Main_Struct[0].sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    for(loop = 2;loop < 60000; loop++)
    {
        if(setTempcounter == 100)
        {
            tempReturn = App_Temp_SetTemperature(10.5, 0);
            setTempcounter = 0;
        }
        else
        {
            setTempcounter++;
        }

        App_Temp_main();
    }

    App_Temp_main();

/*     EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].temperature, 10.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].year, 2022); */

/*     App_Temp_GetNumberTempHistory(&nrPosition, 0);
    EXPECT_EQ(nrPosition, 1);

    App_Temp_GetTempHistory(historyReturn, 0, APP_TEMP_HISTORY_POS0);
    EXPECT_EQ(historyReturn, 0); */

    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 8;
    STUB_Temp_History_day = 23;
    STUB_Temp_History_Hour = 11;
    STUB_Temp_History_minutes = 11;
    STUB_Temp_History_seconds = 23;
    tempReturn = App_Temp_SetTemperature(11, 0);

    App_Temp_Main_Struct[0]. sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    for(loop = 0;loop < 60000; loop++)
    {
        if(setTempcounter == 100)
        {
            tempReturn = App_Temp_SetTemperature(11.5, 0);
            setTempcounter = 0;
        }
        else
        {
            setTempcounter++;
        }

        App_Temp_main();
    }

    App_Temp_main();

    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].temperature, 11.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].year, 2022);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].temperature, 10.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].year, 2022);


    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 8;
    STUB_Temp_History_day = 12;
    STUB_Temp_History_Hour = 11;
    STUB_Temp_History_minutes = 12;
    STUB_Temp_History_seconds = 23;
    tempReturn = App_Temp_SetTemperature(12, 0);

    App_Temp_Main_Struct[0]. sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    for(loop = 0;loop < 60000; loop++)
    {
        if(setTempcounter == 100)
        {
            tempReturn = App_Temp_SetTemperature(12.5, 0);
            setTempcounter = 0;
        }
        else
        {
            setTempcounter++;
        }

        App_Temp_main();
    }

    App_Temp_main();

    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].temperature, 12.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].year, 2022);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].day, 12);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].temperature, 11.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].year, 2022);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[2].temperature, 10.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[2].year, 2022);

    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 8;
    STUB_Temp_History_day = 12;
    STUB_Temp_History_Hour = 11;
    STUB_Temp_History_minutes = 12;
    STUB_Temp_History_seconds = 23;
    tempReturn = App_Temp_SetTemperature(13, 0);

    App_Temp_Main_Struct[0]. sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    for(loop = 0;loop < 60000; loop++)
    {
        if(setTempcounter == 100)
        {
            tempReturn = App_Temp_SetTemperature(13.5, 0);
            setTempcounter = 0;
        }
        else
        {
            setTempcounter++;
        }

        App_Temp_main();
    }

    App_Temp_main();

    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[0].temperature, 13.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].temperature, 12.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].year, 2022);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[1].day, 12);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[2].temperature, 11.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[2].year, 2022);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[3].temperature, 10.5);
    EXPECT_EQ(App_Temp_Main_Struct[0].temp_history[3].year, 2022);
    
    
    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 8;
    STUB_Temp_History_day = 12;
    STUB_Temp_History_Hour = 11;
    STUB_Temp_History_minutes = 12;
    STUB_Temp_History_seconds = 23;
    tempReturn = App_Temp_SetTemperature(14, 0);

    App_Temp_Main_Struct[0]. sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    for(loop = 0;loop < 60000; loop++)
    {
        if(setTempcounter == 100)
        {
            tempReturn = App_Temp_SetTemperature(14.5, 0);
            setTempcounter = 0;
        }
        else
        {
            setTempcounter++;
        }

        App_Temp_main();
    }

    App_Temp_main();

    App_Temp_GetNumberTempHistory(&nrPosition, 0);
    EXPECT_EQ(nrPosition, 5);
    App_Temp_GetTempHistory(&historyReturn, 0, APP_TEMP_HISTORY_POS0);
    EXPECT_EQ(historyReturn.temperature, 14.5);
    App_Temp_GetTempHistory(&historyReturn, 0, APP_TEMP_HISTORY_POS1);
    EXPECT_EQ(historyReturn.temperature, 13.5);
    App_Temp_GetTempHistory(&historyReturn, 0, APP_TEMP_HISTORY_POS2);
    EXPECT_EQ(historyReturn.temperature, 12.5);
    App_Temp_GetTempHistory(&historyReturn, 0, APP_TEMP_HISTORY_POS3);
    EXPECT_EQ(historyReturn.temperature, 11.5);
    App_Temp_GetTempHistory(&historyReturn, 0, APP_TEMP_HISTORY_POS4);
    EXPECT_EQ(historyReturn.temperature, 10.5);

    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 8;
    STUB_Temp_History_day = 12;
    STUB_Temp_History_Hour = 11;
    STUB_Temp_History_minutes = 12;
    STUB_Temp_History_seconds = 23;
    tempReturn = App_Temp_SetTemperature(15, 0);

    App_Temp_Main_Struct[0]. sensor_status = APP_TEMP_SENSOR_STATUS_OK;

    for(loop = 0;loop < 60000; loop++)
    {
        if(setTempcounter == 100)
        {
            tempReturn = App_Temp_SetTemperature(15.5, 0);
            setTempcounter = 0;
        }
        else
        {
            setTempcounter++;
        }

        App_Temp_main();
    }

    App_Temp_main();

    App_Temp_GetNumberTempHistory(&nrPosition, 0);
    EXPECT_EQ(nrPosition, 5);
    App_Temp_GetTempHistory(&historyReturn, 0, APP_TEMP_HISTORY_POS0);
    EXPECT_EQ(historyReturn.temperature, 15.5);
    App_Temp_GetTempHistory(&historyReturn, 0, APP_TEMP_HISTORY_POS1);
    EXPECT_EQ(historyReturn.temperature, 14.5);
    App_Temp_GetTempHistory(&historyReturn, 0, APP_TEMP_HISTORY_POS2);
    EXPECT_EQ(historyReturn.temperature, 13.5);
    App_Temp_GetTempHistory(&historyReturn, 0, APP_TEMP_HISTORY_POS3);
    EXPECT_EQ(historyReturn.temperature, 12.5);
    App_Temp_GetTempHistory(&historyReturn, 0, APP_TEMP_HISTORY_POS4);
    EXPECT_EQ(historyReturn.temperature, 11.5);
       
}

void App_Test_Init_Irrigation(void)
{
    //For Sensor 0
        EXPECT_EQ(AppIrrig_GardenMain[0].savedConf->status, APP_IRRIG_POS_EMPTY);

    //For Sensor 1
        EXPECT_EQ(AppIrrig_GardenMain[1].savedConf->status, APP_IRRIG_POS_EMPTY);
        
}

TEST(App_Irrigation, Test_1)
{
    printf("\n\n Test 1 - Irrigation \n\n");

    App_Config_Log_Message("\nTest 1 - Irrigation START\n", APP_LOG_INFO);

    tApp_Temp_SetTemperatureType tempReturn;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_G1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};

    App_Irrig_Set_Sprinklers(sprinklers_G1, 0);

    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[0].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[1].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[2].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[3].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[4].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[5].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[6].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[7].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[8].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[9].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[10].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[11].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[12].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[13].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[14].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[15].sprinkler, true);
}

TEST(App_Irrigation, Test_2)
{
    printf("\n\n Test 2 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 2 - Irrigation START\n", APP_LOG_INFO);

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_G2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};

    App_Irrig_Set_Sprinklers(sprinklers_G2, 1);

    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[0].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[1].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[2].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[3].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[4].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[5].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[6].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[7].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[8].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[9].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[10].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[11].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[12].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[13].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[14].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[15].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[16].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[17].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[18].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[19].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[20].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[21].sprinkler, false);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[22].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[23].sprinkler, true);
    EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[24].sprinkler, false);
}

TEST(App_Irrigation, Test_3)
{
    printf("\n\n Test 3 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 3 - Irrigation START\n", APP_LOG_INFO);

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_G1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};

    App_Irrig_Set_Sprinklers(sprinklers_G1, 3);
}

TEST(App_Irrigation, Test_4)
{
    printf("\n\n Test 4 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 4 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;

    uint8 saved_configuration = 0;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_c1g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};  
    bool sprinklers_c2g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c3g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c4g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c5g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};

    App_Irrig_Set_Sprinklers(sprinklers_c1g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    App_Irrig_Get_Nr_Configurations(&saved_configuration, 0);
    EXPECT_EQ(saved_configuration, 1);

}

TEST(App_Irrigation, Test_5)
{
    printf("\n\n Test 5 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 5 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_c1g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};  
    bool sprinklers_c2g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c3g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c4g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c5g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};

    App_Irrig_Set_Sprinklers(sprinklers_c1g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c2g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c3g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c4g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Set_Sprinklers(sprinklers_c5g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(result, APP_IRRIG_SAVE_CONF_FULL);
}

 TEST(App_Irrigation, Test_6)
{
    printf("\n\n Test 6 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 6 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_c1g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};  
    bool sprinklers_c2g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c3g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c4g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c5g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};

    App_Irrig_Set_Sprinklers(sprinklers_c1g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c2g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c3g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c4g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Set_Sprinklers(sprinklers_c5g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_CONF_FULL);
}

TEST(App_Irrigation, Test_7)
{
    printf("\n\n Test 7 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 7 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;
    tAppIrrig_ConfigurationPositionType position;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    uint8 saved_conf_instance[16] = {0};
    uint8 loop = 0;

    bool sprinklers_c1g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};  
    bool sprinklers_c2g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c3g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c4g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c5g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};

    App_Irrig_Set_Sprinklers(sprinklers_c1g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 0);
    
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c1g1[loop]);
    }
    
    App_Irrig_Set_Sprinklers(sprinklers_c2g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 0);
    
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c2g1[loop]);
    }
    
    App_Irrig_Set_Sprinklers(sprinklers_c3g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 0);
    
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c3g1[loop]);
    }
    
    App_Irrig_Set_Sprinklers(sprinklers_c4g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 0);
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c1g1[loop]);
    }
    
    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 0);   
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c2g1[loop]);
    }

    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 0);   
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c2g1[loop]);
    }

    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 0);   
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c2g1[loop]);
    }

    App_Irrig_Set_Sprinklers(sprinklers_c5g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(result, APP_IRRIG_SAVE_CONF_FULL);
}

TEST(App_Irrigation, Test_8)
{
    printf("\n\n Test 8 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 8 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;
    tAppIrrig_ConfigurationPositionType position;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    uint8 saved_conf_instance[25] = {0};
    uint8 loop = 0;

    bool sprinklers_c1g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};  
    bool sprinklers_c2g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c3g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c4g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c5g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};

    App_Irrig_Set_Sprinklers(sprinklers_c1g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 1);
    
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c1g2[loop]);
    }
    
    App_Irrig_Set_Sprinklers(sprinklers_c2g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 1);
    
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c2g2[loop]);
    }

    App_Irrig_Set_Sprinklers(sprinklers_c3g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 1);
    
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c3g2[loop]);
    }

    App_Irrig_Set_Sprinklers(sprinklers_c4g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Get_Saved_Configuration(saved_conf_instance, &position, 1);
    
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(saved_conf_instance[loop], sprinklers_c4g2[loop]);
    }

    App_Irrig_Set_Sprinklers(sprinklers_c5g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_CONF_FULL);
}

TEST(App_Irrigation, Test_9)
{
    printf("\n\n Test 9 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 9 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;
    tAppIrrig_ConfigurationPositionType position;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_c1g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};  
    bool sprinklers_c2g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c3g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c4g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c5g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};

    App_Irrig_Set_Sprinklers(sprinklers_c1g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
   
    App_Irrig_Set_Sprinklers(sprinklers_c2g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c3g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Set_Sprinklers(sprinklers_c4g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_POS3, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 3);
    EXPECT_EQ(AppIrrig_GardenMain[0].savedConf[APP_IRRIG_POS3].status, APP_IRRIG_POS_EMPTY);
}

TEST(App_Irrigation, Test_10)
{
    printf("\n\n Test 10 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 10 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;
    tAppIrrig_ConfigurationPositionType position;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_c1g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};  
    bool sprinklers_c2g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c3g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c4g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c5g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};

    App_Irrig_Set_Sprinklers(sprinklers_c1g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
   
    App_Irrig_Set_Sprinklers(sprinklers_c2g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c3g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Set_Sprinklers(sprinklers_c4g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_CLEAR_ALL, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].savedConf[APP_IRRIG_CLEAR_ALL].status, APP_IRRIG_POS_EMPTY);
}

TEST(App_Irrigation, Test_11)
{
    printf("\n\n Test 11 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 11 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_c1g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};  
    bool sprinklers_c2g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c3g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c4g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c5g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};

    App_Irrig_Set_Sprinklers(sprinklers_c1g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c2g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c3g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c4g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_POS3, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 3);
    EXPECT_EQ(AppIrrig_GardenMain[1].savedConf[APP_IRRIG_POS3].status, APP_IRRIG_POS_EMPTY);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_POS0, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 2);
    EXPECT_EQ(AppIrrig_GardenMain[1].savedConf[APP_IRRIG_POS0].status, APP_IRRIG_POS_EMPTY);
    
    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_POS1, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].savedConf[APP_IRRIG_POS1].status, APP_IRRIG_POS_EMPTY);
    
    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_POS2, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 0);
    EXPECT_EQ(AppIrrig_GardenMain[1].savedConf[APP_IRRIG_POS2].status, APP_IRRIG_POS_EMPTY);
}

TEST(App_Irrigation, Test_12)
{
    printf("\n\n Test 12 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 12 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_c1g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};  
    bool sprinklers_c2g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c3g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c4g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c5g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};

    App_Irrig_Set_Sprinklers(sprinklers_c1g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c2g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c3g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c4g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_CLEAR_ALL, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 0);
    EXPECT_EQ(AppIrrig_GardenMain[1].savedConf[APP_IRRIG_CLEAR_ALL].status, APP_IRRIG_POS_EMPTY);
}

TEST(App_Irrigation, Test_13)
{
    printf("\n\n Test 13 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 13 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;
    tAppIrrig_ConfigurationPositionType position;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();
    uint8 loop = 0;

    bool sprinklers_c1g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};  
    bool sprinklers_c2g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c3g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c4g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c5g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};

    App_Irrig_Set_Sprinklers(sprinklers_c1g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Set_Saved_Configuration (APP_IRRIG_POS0, 0);
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(*AppIrrig_CurrentConfiguration[0].gardenConf[loop].sprinkler, sprinklers_c1g1[loop]);
    }
   
    App_Irrig_Set_Sprinklers(sprinklers_c2g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c3g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Set_Sprinklers(sprinklers_c4g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_CLEAR_ALL, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].savedConf[APP_IRRIG_CLEAR_ALL].status, APP_IRRIG_POS_EMPTY);
}

TEST(App_Irrigation, Test_14)
{
    printf("\n\n Test 11 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 14 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    uint8 loop = 0;

    bool sprinklers_c1g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};  
    bool sprinklers_c2g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c3g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c4g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c5g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};

    App_Irrig_Set_Sprinklers(sprinklers_c1g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Set_Saved_Configuration (APP_IRRIG_POS0, 1);
    for (loop = 0; loop < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; loop ++)
    {
        EXPECT_EQ(*AppIrrig_CurrentConfiguration[1].gardenConf[loop].sprinkler, sprinklers_c1g2[loop]);
    } 
}

TEST(App_Configuration, Test_1)
{
    printf("\n\n Test 1 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config.txt");

    //Verify garden 1
    EXPECT_EQ(AppConfig_Garden[0].cover_motor, true);
    EXPECT_EQ(AppConfig_Garden[0].humidityMonitoring, true);
    EXPECT_EQ(AppConfig_Garden[0].irrigation, true);
    EXPECT_EQ(AppConfig_Garden[0].lightMonitoring, true);
    EXPECT_EQ(AppConfig_Garden[0].temperatureMonitoring, true);
}

TEST(App_Configuration, Test_2)
{
    printf("\n\n Test 2 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config2.txt");

    //Verify garden 1
    EXPECT_EQ(AppConfig_Garden[0].cover_motor, false);
    EXPECT_EQ(AppConfig_Garden[0].humidityMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].irrigation, false);
    EXPECT_EQ(AppConfig_Garden[0].lightMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].temperatureMonitoring, false);
}

TEST(App_Configuration, Test_3)
{
    printf("\n\n Test 3 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config2.txt");

    //Verify garden 1
    EXPECT_EQ(AppConfig_Garden[1].cover_motor, false);
    EXPECT_EQ(AppConfig_Garden[1].humidityMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[1].irrigation, false);
    EXPECT_EQ(AppConfig_Garden[1].lightMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[1].temperatureMonitoring, false);
}

TEST(App_Configuration, Test_4)
{
    printf("\n\n Test 4 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config3.txt");

    //Verify garden 1
    EXPECT_EQ(AppConfig_Garden[0].cover_motor, false);
    EXPECT_EQ(AppConfig_Garden[0].humidityMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].irrigation, false);
    EXPECT_EQ(AppConfig_Garden[0].lightMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].temperatureMonitoring, false);
}

TEST(App_Configuration, Test_5)
{
    printf("\n\n Test 5 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config3.txt");

    //Verify garden 2
    EXPECT_EQ(AppConfig_Garden[1].cover_motor, false);
    EXPECT_EQ(AppConfig_Garden[1].humidityMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[1].irrigation, false);
    EXPECT_EQ(AppConfig_Garden[1].lightMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[1].temperatureMonitoring, false);
}

TEST(App_Configuration, Test_6)
{
    printf("\n\n Test 6 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config4.txt");

    //Verify garden 1
    EXPECT_EQ(AppConfig_Garden[0].cover_motor, false);
    EXPECT_EQ(AppConfig_Garden[0].humidityMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].irrigation, false);
    EXPECT_EQ(AppConfig_Garden[0].lightMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].temperatureMonitoring, false);
}

TEST(App_Configuration, Test_7)
{
    printf("\n\n Test 7 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config4.txt");

    //Verify garden 2
    EXPECT_EQ(AppConfig_Garden[1].cover_motor, false);
    EXPECT_EQ(AppConfig_Garden[1].humidityMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[1].irrigation, false);
    EXPECT_EQ(AppConfig_Garden[1].lightMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[1].temperatureMonitoring, false);
} 

TEST(App_Configuration, Test_8)
{
    printf("\n\n Test 8 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config5.txt");

    //Verify garden 1
    EXPECT_EQ(AppConfig_Garden[0].cover_motor, false);
    EXPECT_EQ(AppConfig_Garden[0].humidityMonitoring, true);
    EXPECT_EQ(AppConfig_Garden[0].irrigation, true);
    EXPECT_EQ(AppConfig_Garden[0].lightMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].temperatureMonitoring, true);
}

TEST(App_Configuration, Test_9)
{
    printf("\n\n Test 9 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config6.txt");

    //Verify garden 1
    EXPECT_EQ(AppConfig_Garden[0].cover_motor, false);
    EXPECT_EQ(AppConfig_Garden[0].humidityMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].irrigation, false);
    EXPECT_EQ(AppConfig_Garden[0].lightMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].temperatureMonitoring, false);
}

TEST(App_Configuration, Test_10)
{
    printf("\n\n Test 10 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config7.txt");

    //Verify garden 1
    EXPECT_EQ(AppConfig_Garden[0].cover_motor, false);
    EXPECT_EQ(AppConfig_Garden[0].humidityMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].irrigation, false);
    EXPECT_EQ(AppConfig_Garden[0].lightMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].temperatureMonitoring, false);

}

TEST(App_Configuration, Test_11)
{
    printf("\n\n Test 11 - Config \n\n");

    // ACTION: Initialization
    App_Main_Init();
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config8.txt");

    //Verify garden 1
    EXPECT_EQ(AppConfig_Garden[0].cover_motor, false);
    EXPECT_EQ(AppConfig_Garden[0].humidityMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].irrigation, false);
    EXPECT_EQ(AppConfig_Garden[0].lightMonitoring, false);
    EXPECT_EQ(AppConfig_Garden[0].temperatureMonitoring, false);

}

TEST(App_Main, Test_1)
{
    printf("\n\n Test 1 - Config \n\n");

    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 2;
    STUB_Temp_History_day = 12;
    STUB_Temp_History_Hour = 6;
    STUB_Temp_History_minutes = 26;
    STUB_Temp_History_seconds = 15;

    App_Config_Log_Message("First date and time", APP_LOG_INFO);

    STUB_Temp_History_year = 2022;
    STUB_Temp_History_month = 12;
    STUB_Temp_History_day = 22;
    STUB_Temp_History_Hour = 16;
    STUB_Temp_History_minutes = 6;
    STUB_Temp_History_seconds = 1;

    App_Config_Log_Message("First date and time", APP_LOG_ERROR);
}

TEST(App_Main, Test_2)
{
    App_Config_Init("D:/Internship_Benoli/FarmingSimulator/App_main/src/config.txt");
}

TEST(App_Irrigation, Test_15)
{
    printf("\n\n Test 15 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 15 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;
    tAppIrrig_ConfigurationPositionType position;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_c1g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};  
    bool sprinklers_c2g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c3g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c4g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    bool sprinklers_c5g1[16] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};

    App_Irrig_Set_Sprinklers(sprinklers_c1g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
   
    App_Irrig_Set_Sprinklers(sprinklers_c2g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c3g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Set_Sprinklers(sprinklers_c4g1, 0);
    result = App_Irrig_Save_Configuration(true, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_POS0, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 3);
    EXPECT_EQ(AppIrrig_GardenMain[0].savedConf[APP_IRRIG_POS0].status, APP_IRRIG_POS_EMPTY);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_POS1, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 2);
    EXPECT_EQ(AppIrrig_GardenMain[0].savedConf[APP_IRRIG_POS1].status, APP_IRRIG_POS_EMPTY);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_POS2, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 1);
    EXPECT_EQ(AppIrrig_GardenMain[0].savedConf[APP_IRRIG_POS2].status, APP_IRRIG_POS_EMPTY);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_POS3, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].nrOfSavedConf, 0);
    EXPECT_EQ(AppIrrig_GardenMain[0].savedConf[APP_IRRIG_POS3].status, APP_IRRIG_POS_EMPTY);
}

TEST(App_Irrigation, Test_16)
{
    printf("\n\n Test 16 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 16 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;
    tAppIrrig_ConfigurationPositionType position;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();
    uint16 i = 0;

    bool sprinklers_c1g1[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  

    App_Irrig_Set_Sprinklers(sprinklers_c1g1, 0);
    for(i = 0; i < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; i ++)
    {
        STUB_Irrig_System_Check_Sprinkler_Status[i] = true;
    }

    App_Irrig_Main();

    for(i = 0; i < 5999; i ++)
    {   if(i == 5995)
        {
            printf("");
        }
       App_Irrig_Main();
    }

    for(i = 0; i < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; i ++)
    {
        EXPECT_EQ(AppIrrig_CurrentConfiguration[0].gardenConf[i].generalStatus, APP_IRRIG_STATUS_IDLE);
    }

    App_Irrig_Main();

    for(i = 0; i < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; i ++)
    {
        EXPECT_EQ(AppIrrig_CurrentConfiguration[0].gardenConf[i].generalStatus, APP_IRRIG_STATUS_OK);
    }
}

TEST(App_Irrigation, Test_17)
{
    printf("\n\n Test 17 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 17 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    uint16 i = 0;

    bool sprinklers_c1g2[25] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    App_Irrig_Set_Sprinklers(sprinklers_c1g2, 1);
    for (i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
    {
        STUB_Irrig_System_Check_Sprinkler_Status[i] = true;
    }

    App_Irrig_Main();

    for(i = 0; i < 5999; i ++)
    {   if(i == 5997)
        {
            printf("");
        }
       App_Irrig_Main();
    }
    for(i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
    {
    EXPECT_EQ(AppIrrig_CurrentConfiguration[1].gardenConf[i].generalStatus, APP_IRRIG_STATUS_IDLE);
    }

    App_Irrig_Main();

    for(i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
    {
        EXPECT_EQ(AppIrrig_CurrentConfiguration[1].gardenConf[i].generalStatus, APP_IRRIG_STATUS_OK);
    }
}

TEST(App_Irrigation, Test_18)
{
    printf("\n\n Test 18 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 18 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;
    tAppIrrig_ConfigurationPositionType position;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();
    uint16 i = 0;

    bool sprinklers_c1g1[16] = {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  

    App_Irrig_Set_Sprinklers(sprinklers_c1g1, 0);
    for(i = 0; i < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; i ++)
    {
        STUB_Irrig_System_Check_Sprinkler_Status[i] = true;
    }
    App_Irrig_Main();

    for(i = 0; i < 5999; i ++)
    {   /* if(i == 5997)
        {
            printf("");
        } */
       App_Irrig_Main();
    }

    for(i = 0; i < APPIRRIG_NUMBER_GARDEN1_SPRINKLERS; i ++)
    {
    EXPECT_EQ(AppIrrig_CurrentConfiguration[0].gardenConf[i].generalStatus, APP_IRRIG_STATUS_IDLE);
    }

    App_Irrig_Main();

    EXPECT_EQ(AppIrrig_CurrentConfiguration[0].gardenConf[0].generalStatus, APP_IRRIG_STATUS_OK);
    EXPECT_EQ(AppIrrig_CurrentConfiguration[0].gardenConf[1].generalStatus, APP_IRRIG_STATUS_OK);
    EXPECT_EQ(AppIrrig_CurrentConfiguration[0].gardenConf[2].generalStatus, APP_IRRIG_STATUS_NOK);

    for(i = 3; i < 16; i ++)
    {
        EXPECT_EQ(AppIrrig_CurrentConfiguration[0].gardenConf[i].generalStatus, APP_IRRIG_STATUS_OK);
    }
}

TEST(App_Irrigation, Test_19)
{
    printf("\n\n Test 19 - Irrigation \n\n");
    App_Config_Log_Message("\nTest 19 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    uint16 i = 0;

    bool sprinklers_c1g2[25] = {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    App_Irrig_Set_Sprinklers(sprinklers_c1g2, 1);
    for (i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
    {
        STUB_Irrig_System_Check_Sprinkler_Status[i] = true;
    }

    App_Irrig_Main();

    for(i = 0; i < 5999; i ++)
    {   if(i == 5997)
        {
            printf("");
        }
       App_Irrig_Main();
    }
    for(i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
    {
    EXPECT_EQ(AppIrrig_CurrentConfiguration[1].gardenConf[i].generalStatus, APP_IRRIG_STATUS_IDLE);
    }

    App_Irrig_Main();

    EXPECT_EQ(AppIrrig_CurrentConfiguration[1].gardenConf[0].generalStatus, APP_IRRIG_STATUS_OK);
    EXPECT_EQ(AppIrrig_CurrentConfiguration[1].gardenConf[1].generalStatus, APP_IRRIG_STATUS_NOK);

    for(i = 2; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
    {
        EXPECT_EQ(AppIrrig_CurrentConfiguration[1].gardenConf[i].generalStatus, APP_IRRIG_STATUS_OK);
    }
}

TEST(App_Irrigation, Test_20)
{
    printf("\n\n Test 20 - Irrigation \n\n");
    App_Config_Log_Message("\n Test 20 - Irrigation START\n", APP_LOG_INFO);

    tAppIrrig_SaveRequestStatusType result;
    uint8 i = 0;

    // ACTION: Initialization
    App_Temp_init();
    App_Cover_Init();
    App_Irrig_init();
    // RESULT: Check that all variables are initialized 
    App_Test_InitVariables();
    App_Test_Init_Cover();
    App_Test_Init_Irrigation();

    bool sprinklers_c1g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};  
    bool sprinklers_c2g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c3g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c4g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};
    bool sprinklers_c5g2[25] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0};

    App_Irrig_Set_Sprinklers(sprinklers_c1g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 1);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    for (i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
    {
        STUB_Irrig_System_Check_Sprinkler_Status[i] = true;
    }

    App_Irrig_Main();

    for(i = 0; i < 5999; i ++)
    {   if(i == 5997)
        {
            printf("");
        }
       App_Irrig_Main();
    }
    for(i = 0; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
    {
    EXPECT_EQ(AppIrrig_CurrentConfiguration[1].gardenConf[i].generalStatus, APP_IRRIG_STATUS_IDLE);
    }

    App_Irrig_Main();

    EXPECT_EQ(AppIrrig_CurrentConfiguration[1].gardenConf[0].generalStatus, APP_IRRIG_STATUS_OK);
    EXPECT_EQ(AppIrrig_CurrentConfiguration[1].gardenConf[1].generalStatus, APP_IRRIG_STATUS_NOK);

    for(i = 2; i < APPIRRIG_NUMBER_GARDEN2_SPRINKLERS; i ++)
    {
        EXPECT_EQ(AppIrrig_CurrentConfiguration[1].gardenConf[i].generalStatus, APP_IRRIG_STATUS_OK);
    }
    
    App_Irrig_Set_Sprinklers(sprinklers_c2g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 2);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c3g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 3);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);
    
    App_Irrig_Set_Sprinklers(sprinklers_c4g2, 1);
    result = App_Irrig_Save_Configuration(true, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 4);
    EXPECT_EQ(result, APP_IRRIG_SAVE_DONE);

    App_Irrig_Delete_Saved_Configuration (APP_IRRIG_CLEAR_ALL, 1);
    EXPECT_EQ(AppIrrig_GardenMain[1].nrOfSavedConf, 0);
    EXPECT_EQ(AppIrrig_GardenMain[1].savedConf[APP_IRRIG_CLEAR_ALL].status, APP_IRRIG_POS_EMPTY);
}




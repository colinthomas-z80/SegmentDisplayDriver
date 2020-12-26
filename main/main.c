#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "display.h"
 

void app_main(void)
{
    DISPLAY_PINS myPins;
    display_select_gpio(&myPins, 19, 21, 4, 2, 15, 18, 5);

    while(1)
    {
        display(myPins, num0);
        vTaskDelay(100);
        display(myPins, num1);
        vTaskDelay(100);
        display(myPins, num2);
        vTaskDelay(100);
        display(myPins, num3);
        vTaskDelay(100);
        display(myPins, num4);
        vTaskDelay(100);
        display(myPins, num5);
        vTaskDelay(100);
    }
}
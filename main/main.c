#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "display.h"

/*
    Create a struct of the DISPLAY_PINS type, then call display_select_gpio on it.
    Each number argument corresponds to segment A, B, C, D, E, F, G respectively.
    You can see which segments these are on the datasheet. 
 */

void app_main(void)
{
    DISPLAY_PINS myPins;
    display_select_gpio(&myPins, 19, 21, 4, 2, 15, 18, 5);

    while(1)
    {
        display_write_number(myPins, 0);
        vTaskDelay(100);
        display_write_number(myPins, 1);
        vTaskDelay(100);
    }
}
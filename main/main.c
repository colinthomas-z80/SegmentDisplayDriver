#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "display.h"
 

void gpio_init(void)
{
    gpio_pad_select_gpio(SEGMENT_A);
    gpio_pad_select_gpio(SEGMENT_B);
    gpio_pad_select_gpio(SEGMENT_C);
    gpio_pad_select_gpio(SEGMENT_D);
    gpio_pad_select_gpio(SEGMENT_E);
    gpio_pad_select_gpio(SEGMENT_F);
    gpio_pad_select_gpio(SEGMENT_G);

    gpio_set_direction(SEGMENT_A, GPIO_MODE_OUTPUT);
    gpio_set_direction(SEGMENT_B, GPIO_MODE_OUTPUT);
    gpio_set_direction(SEGMENT_C, GPIO_MODE_OUTPUT);
    gpio_set_direction(SEGMENT_D, GPIO_MODE_OUTPUT);
    gpio_set_direction(SEGMENT_E, GPIO_MODE_OUTPUT);
    gpio_set_direction(SEGMENT_F, GPIO_MODE_OUTPUT);
    gpio_set_direction(SEGMENT_G, GPIO_MODE_OUTPUT);
}

void display(unsigned int c)
{
    gpio_set_level(SEGMENT_A, (c>>6) & 1);
    gpio_set_level(SEGMENT_B, (c>>5) & 1);
    gpio_set_level(SEGMENT_C, (c>>4) & 1);
    gpio_set_level(SEGMENT_D, (c>>3) & 1);
    gpio_set_level(SEGMENT_E, (c>>2) & 1);
    gpio_set_level(SEGMENT_F, (c>>1) & 1);
    gpio_set_level(SEGMENT_G, c & 1);
}

void app_main(void)
{
    gpio_init();
    while(1)
    {
        display(num0);
        vTaskDelay(100);
        display(num1);
        vTaskDelay(100);
        display(num2);
        vTaskDelay(100);
        display(num3);
        vTaskDelay(100);
        display(num4);
        vTaskDelay(100);
        display(num5);
        vTaskDelay(100);
        printf("displaying\n");
    }
}
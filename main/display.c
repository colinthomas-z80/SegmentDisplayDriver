#include "display.h"
#include "driver/gpio.h"

void display_select_gpio(DISPLAY_PINS *pins, int segA, int segB, int segC, int segD, int segE, int segF, int segG)
{
    pins->SEGMENT_A = segA;
    pins->SEGMENT_B = segB;
    pins->SEGMENT_C = segC;
    pins->SEGMENT_D = segD;
    pins->SEGMENT_E = segE;
    pins->SEGMENT_F = segF;
    pins->SEGMENT_G = segG;

    display_gpio_init(*pins);
}

static void display_gpio_init(DISPLAY_PINS pins)
{
    gpio_pad_select_gpio(pins.SEGMENT_A);
    gpio_pad_select_gpio(pins.SEGMENT_B);
    gpio_pad_select_gpio(pins.SEGMENT_C);
    gpio_pad_select_gpio(pins.SEGMENT_D);
    gpio_pad_select_gpio(pins.SEGMENT_E);
    gpio_pad_select_gpio(pins.SEGMENT_F);
    gpio_pad_select_gpio(pins.SEGMENT_G);

    gpio_set_direction(pins.SEGMENT_A, GPIO_MODE_OUTPUT);
    gpio_set_direction(pins.SEGMENT_B, GPIO_MODE_OUTPUT);
    gpio_set_direction(pins.SEGMENT_C, GPIO_MODE_OUTPUT);
    gpio_set_direction(pins.SEGMENT_D, GPIO_MODE_OUTPUT);
    gpio_set_direction(pins.SEGMENT_E, GPIO_MODE_OUTPUT);
    gpio_set_direction(pins.SEGMENT_F, GPIO_MODE_OUTPUT);
    gpio_set_direction(pins.SEGMENT_G, GPIO_MODE_OUTPUT);
}

void display(DISPLAY_PINS myPins, unsigned int c)
{
    gpio_set_level(myPins.SEGMENT_A, (c>>6) & 1);
    gpio_set_level(myPins.SEGMENT_B, (c>>5) & 1);
    gpio_set_level(myPins.SEGMENT_C, (c>>4) & 1);
    gpio_set_level(myPins.SEGMENT_D, (c>>3) & 1);
    gpio_set_level(myPins.SEGMENT_E, (c>>2) & 1);
    gpio_set_level(myPins.SEGMENT_F, (c>>1) & 1);
    gpio_set_level(myPins.SEGMENT_G, c & 1);
}
#include "display.h"
#include "driver/gpio.h"

static void display_gpio_init(DISPLAY_PINS);

static const unsigned int num0 = 0b0000001;
static const unsigned int num1 = 0b1001111;
static const unsigned int num2 = 0b0010010;
static const unsigned int num3 = 0b0000110;
static const unsigned int num4 = 0b1001100;
static const unsigned int num5 = 0b0100100;
static const unsigned int num6 = 0b0100000;
static const unsigned int num7 = 0b0001111;
static const unsigned int num8 = 0b0000000;
static const unsigned int num9 = 0b0001100;

static const unsigned int numbers[10] = {num0, num1, num2, num3, num4, 
                                   num5, num6, num7, num8, num9};

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


void display_write_number(DISPLAY_PINS myPins, int i)
{
    display_write_ll(myPins, numbers[i]);
}

void display_write_ll(DISPLAY_PINS myPins, unsigned int c)
{
    gpio_set_level(myPins.SEGMENT_A, (c>>6) & 1);
    gpio_set_level(myPins.SEGMENT_B, (c>>5) & 1);
    gpio_set_level(myPins.SEGMENT_C, (c>>4) & 1);
    gpio_set_level(myPins.SEGMENT_D, (c>>3) & 1);
    gpio_set_level(myPins.SEGMENT_E, (c>>2) & 1);
    gpio_set_level(myPins.SEGMENT_F, (c>>1) & 1);
    gpio_set_level(myPins.SEGMENT_G, c & 1);
}
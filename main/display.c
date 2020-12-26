#include "display.h"
#include "driver/gpio.h"


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
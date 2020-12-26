#ifndef DISPLAY_DOT_H
#define DISPLAY_DOT_H

typedef struct gpio_pins{
    int SEGMENT_A;
    int SEGMENT_B;
    int SEGMENT_C;
    int SEGMENT_D;
    int SEGMENT_E;
    int SEGMENT_F;
    int SEGMENT_G;
} DISPLAY_PINS;


void display_select_gpio(DISPLAY_PINS*, int, int, int, int, int, int, int);
void display_write_number(DISPLAY_PINS, int);
void display_write_ll(DISPLAY_PINS, unsigned int);

#endif
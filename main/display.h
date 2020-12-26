
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

static unsigned int num0 = 0b0000001;
static unsigned int num1 = 0b1001111;
static unsigned int num2 = 0b0010010;
static unsigned int num3 = 0b0000110;
static unsigned int num4 = 0b1001100;
static unsigned int num5 = 0b0100100;
static unsigned int num6 = 0b0100000;
static unsigned int num7 = 0b0001111;
static unsigned int num8 = 0b0000000;
static unsigned int num9 = 0b0001100;

static void display_gpio_init(DISPLAY_PINS);

void display_select_gpio(DISPLAY_PINS*, int, int, int, int, int, int, int);
void display(DISPLAY_PINS, unsigned int);

#endif
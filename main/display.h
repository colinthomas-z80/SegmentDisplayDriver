
#ifndef DISPLAY_DOT_H
#define DISPLAY_DOT_H

#define SEGMENT_E 15
#define SEGMENT_D 2
#define SEGMENT_C 4
#define SEGMENT_G 5
#define SEGMENT_F 18
#define SEGMENT_A 19
#define SEGMENT_B 21

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

void display(unsigned int);

#endif
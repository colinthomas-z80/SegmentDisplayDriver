# 7 Segment Display Driver

ESP-IDF Compatible driver for a single 7-Segment display

Create a struct of the DISPLAY_PINS type, then call display_select_gpio on it.


Each number argument corresponds to segment A, B, C, D, E, F, G respectively.
You can see which segments these are on the datasheet.

Use display_write_number with your pin handle and an integer to display the number. 
#ifndef HD44780_H_
#define HD44780_H_

#include <stdint.h>

enum COMMAND {
    CLEAR_SCREEN         = 0x01,
    CURSOR_HOME          = 0x02,
    ENTRY_MODE           = 0x04,
    ENTRY_CURSOR_RIGHT   = 0x02,
    ENTRY_CURSOR_LEFT    = 0x00,
    DISPLAY_CONTROLL     = 0x08,
    DISPLAY_ON           = 0x04,
    DISPLAY_OFF          = 0x00,
    DISPLAY_CURSOR       = 0x02,
    DISPLAY_CURSOR_BLINK = 0x01,
    FUNCTION_SET         = 0x20,
    FUNCTION_8_BIT       = 0x10,
    FUNCTION_4_BIT       = 0x00,
    FUNCTION_2_LINES     = 0x08,
    FUNCTION_1_LINE      = 0x00,
    FUNCTION_5x10        = 0x04,
    FUNCTION_5x8         = 0x00,
    SET_CGRAM_ADDRESS    = 0x40,
    SET_DDRAM_ADDRESS    = 0x80,
};

void hd44780_write_string(char * str);
void hd44780_command(enum COMMAND cmd);
void hd44780_init(void);
void hd44780_set_cursor_position(uint8_t line, uint8_t collumn);

#endif

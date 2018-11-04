#include "display/hd44780.h"
#include "registers.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <stdio.h>

int
main(void)
{
    hd44780_init();
    hd44780_set_cursor_position(0, 3);
    hd44780_write_string("linia 1");
    hd44780_set_cursor_position(1, 4);
    hd44780_write_string("linia 2");
    hd44780_set_cursor_position(2, 5);
    hd44780_write_string("linia 3");
    hd44780_set_cursor_position(3, 6);
    hd44780_write_string("linia 4");
    wdt_enable(WDTO_1S);
    while (1) {
        wdt_reset();
    }
}

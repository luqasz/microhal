#include "display/hd44780.h"

#include <stdio.h>
#include <util/delay.h>

int
main(void)
{
    auto lcd = HD44780::LCD({
        GPIO::PortC,
        GPIO::PA0.output(),
        GPIO::PA1.output(),
        GPIO::PA2.output(),
    });
    // all command must be sent
    // hd44780_command(DISPLAY_CONTROLL | DISPLAY_CURSOR | DISPLAY_ON);
    uint8_t line = 0;
    uint8_t row  = 0;
    while (true) {
        if (row > 3) {
            row = 0;
        }
        if (line > 1) {
            line = 0;
        }
        lcd.set({ line, row });
        lcd.write("linia ABC 123");
        _delay_ms(500);
        lcd.set(HD44780::ClearScreen);
        row++;
        line++;
    }
}

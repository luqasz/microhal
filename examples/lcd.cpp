#include <display/hd44780.h>
#include <gpio.h>
#include <irq.h>
#include <printer.h>
#include <sfr.h>
#include <stdio.h>
#include <util/delay.h>

int
main(void)
{
    auto lcd = HD44780::LCD(GPIO::PortC, GPIO::PA0, GPIO::PA1, GPIO::PA2);
    auto out = Printer(lcd, LineEnd::None);
    while (true) {
        out.printLn("First line");
        _delay_ms(1000);
    }
}


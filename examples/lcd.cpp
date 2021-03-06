#include <display/hd44780.h>
#include <gpio.h>
#include <printer.h>

int
main(void)
{
    auto const rs  = GPIO::Output(GPIO::PA0);
    auto const rw  = GPIO::Output(GPIO::PA1);
    auto const e   = GPIO::Output(GPIO::PA2);
    auto       lcd = HD44780::LCD(GPIO::Bus8Bit(GPIO::PortC), rs, rw, e);
    auto       out = Printer(lcd, LineEnd::None);
    out.printLn("First line");
    while (true) {
    }
}


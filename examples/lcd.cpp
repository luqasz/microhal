#include <display/hd44780.h>
#include <gpio.h>
#include <printer.h>

int
main(void)
{
    auto const rs  = GPIO::Output(GPIO::PA0);
    auto const rw  = GPIO::Output(GPIO::PA1);
    auto const e   = GPIO::Output(GPIO::PA2);
    auto const lcd = HD44780::LCD(GPIO::PortBus(GPIO::PortC), rs, rw, e);
    auto const out = Printer(lcd, LineEnd::None);
    out.printLn("First line");
    lcd.set(HD44780::Position { 1, 0 });
    out.printLn("Second line");
    while (true) {
    }
}

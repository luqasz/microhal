#include <drivers/hd44780.hpp>
#include <gpio.hpp>
#include <printer.hpp>

int
main(void)
{
    auto const rs  = gpio::Output(gpio::PA0);
    auto const rw  = gpio::Output(gpio::PA1);
    auto const e   = gpio::Output(gpio::PA2);
    auto       lcd = HD44780::LCD(gpio::Bus8Bit(gpio::PortC), rs, rw, e);
    auto       out = Printer(lcd, LineEnd::None);
    out.printLn("First line");
    lcd.set(HD44780::Position { 1, 0 });
    out.printLn("Second line");
    while (true) {
    }
}

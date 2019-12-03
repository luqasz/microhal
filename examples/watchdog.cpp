#include <irq.h>
#include <printer.h>
#include <stdio.h>
#include <usart.h>
#include <util/delay.h>
#include <watchdog.h>

auto constexpr baud = USART::get_baud<BAUD, 2>();
auto usart          = USART::Async<USART::USART0>();
auto serial         = Printer<USART::Async<USART::USART0>, RN>(usart);

int
main(void)
{
    Irq::enable();
    Watchdog::enable(Watchdog::Clock::s1, Watchdog::Mode::Reset);
    usart.set(baud);
    usart.enable(USART::Channel::TX);
    serial.printLn("Starting.");
    uint8_t counter = 4;
    while (counter != 0) {
        serial.printLn("This string will print 4 times.");
        counter--;
        Watchdog::reset();
        _delay_ms(500);
    }
    serial.printLn("Turning off watchdog.");
    Watchdog::disable();
    _delay_ms(10000);
    serial.printLn("Turning on watchdog.");
    Watchdog::enable(Watchdog::Clock::s1, Watchdog::Mode::Reset);
    serial.printLn("After this string prints, watchdog will reset MCU.");
    _delay_ms(2000);
}

#include <irq.hpp>
#include <printer.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>
#include <watchdog.hpp>

auto constexpr baud = USART::get_baud(11059200_Hz, 115200, 2);
static_assert(baud.is_ok, "Calculated error rate too high");

using USART_0 = USART::Async<USART::usart0>;

int
main(void)
{
    auto usart = USART_0();
    usart.set(baud);
    usart.enable_tx();
    auto serial = Printer(usart, LineEnd::CRLF);
    IRQ::enable();
    watchdog::enable(watchdog::Clock::s1);
    serial.printLn("Starting.");
    uint8_t counter = 4;
    while (counter != 0) {
        serial.printLn("This string will print 4 times.");
        counter--;
        watchdog::reset();
        _delay_ms(500);
    }
    serial.printLn("Turning off watchdog.");
    watchdog::disable();
    _delay_ms(10000);
    serial.printLn("Turning on watchdog.");
    watchdog::enable(watchdog::Clock::s1);
    serial.printLn("After this string prints, watchdog will reset MCU.");
    _delay_ms(2000);
}

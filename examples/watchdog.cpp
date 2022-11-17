#include <irq.hpp>
#include <printer.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>
#include <watchdog.hpp>

constexpr units::Frequency fcpu = units::Hz * 11059200;
constexpr auto             baud = USART::baud_rate_async<fcpu, 115200, 2>();

using USART_0 = USART::Async<USART::usart0>;

int
main(void)
{
    auto usart = USART_0();
    usart.set(baud);
    usart.enable_tx();
    auto serial = Printer(usart, LineEnd::CRLF);
    IRQ::enable();
    serial.printLn("Enabling watchdog.");
    watchdog::enable(watchdog::Clock::s1);
    serial.printLn("Resetting watchdog.");
    watchdog::reset();
    _delay_ms(500);
    serial.printLn("After this string prints, watchdog will reset MCU.");
    _delay_ms(2000);
}

#include <interface.hpp>
#include <irq.hpp>
#include <printer.hpp>
#include <sfr.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>
#include <gpio.hpp>

auto constexpr baud = USART::get_baud(11059200_Hz, 115200u, 2);
static_assert(baud.is_ok, "Calculated error rate too high");

using USART_0 = USART::Async<USART::usart0>;

int
main(void)
{
    auto usart = USART_0();
    usart.set(baud);
    usart.set(USART::CharacterSize::Bit8);
    usart.set(USART::Parity::None);
    usart.set(USART::StopBits::One);
    usart.enable_tx();
    auto serial = Printer(usart, LineEnd::CRLF);
    while (true) {
        serial.printLn("This string will repeat every second.");
        _delay_ms(1000);
    }
}

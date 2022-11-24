#include <irq.hpp>
#include <printer.hpp>
#include <sfr.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>
#include <gpio.hpp>

constexpr units::Frequency fcpu = units::Hz * 11059200;
constexpr auto             baud = USART::baud_rate_async<fcpu, 115200, 2>();

constexpr auto config = USART::Config {
    .char_size = USART::CharacterSize::Bit8,
    .parity    = USART::Parity::None,
    .stop_bits = USART::StopBits::One,
};

using USART_0 = USART::Async<USART::usart0>;

int
main(void)
{
    auto usart = USART_0().set(config);
    usart.set(baud);
    usart.enable_tx();
    auto serial = Printer(usart, LineEnd::CRLF);
    while (true) {
        serial.printLn("This string will repeat every second.");
        _delay_ms(1000);
    }
}

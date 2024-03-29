#include <adc.hpp>
#include <printer.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>

constexpr units::Frequency fcpu = units::Hz * 11059200;

constexpr auto config = USART::Config {
    .char_size = USART::CharacterSize::Bit8,
    .parity    = USART::Parity::None,
    .stop_bits = USART::StopBits::One,
    .ubrr      = USART::ubrr<fcpu, 115200, 2>(),
};

using USART_0 = USART::Async<USART::usart0>;

int
main(void)
{
    auto usart  = USART_0().set(config).enable(USART::Channel::TX);
    auto serial = Printer(usart, LineEnd::CRLF);
    adc::set(adc::Clock::ClockDiv_2);
    adc::set(adc::Vref::AVCC);
    while (true) {
        serial.printLn("Reading ADC");
        adc::set(adc::Channel::ADC0);
        adc::start();
        while (adc::pending()) { };
        const u16 value = adc::read();
        serial.printLn(value);
        _delay_ms(1000);
    }
}

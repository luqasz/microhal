#include <adc.hpp>
#include <printer.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>

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
    adc::set(adc::Clock::_2);
    adc::set(adc::Vref::AVCC);
    while (true) {
        serial.printLn("Reading ADC");
        serial.printLn(adc::read(adc::Channel::ADC0));
        _delay_ms(1000);
    }
}

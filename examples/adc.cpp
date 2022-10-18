#include <adc.hpp>
#include <printer.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>

auto constexpr baud = USART::get_baud(11059200_Hz, 115200, 2);
static_assert(baud.is_ok, "Calculated error rate too high");
auto usart  = USART::Async<USART::USART0>();
auto serial = Printer(usart, LineEnd::CRLF);

int
main(void)
{
    usart.set(baud);
    usart.enable(USART::Channel::TX);
    adc::set(adc::Clock::_2);
    adc::set(adc::Vref::AVCC);
    while (true) {
        serial.printLn("Reading ADC");
        serial.printLn(adc::read(adc::Channel::ADC0));
        _delay_ms(1000);
    }
}

#include <adc.h>
#include <printer.h>
#include <stdio.h>
#include <units.h>
#include <usart.h>
#include <util/delay.h>

auto constexpr baud = USART::get_baud(11059200_Hz, 115200, 2);
static_assert(baud.is_ok, "Calculated error rate too high");
auto usart  = USART::Async<USART::USART0>();
auto serial = Printer<RN>(usart);

int
main(void)
{
    usart.set(baud);
    usart.enable(USART::Channel::TX);
    ADC::set(ADC::Clock::_2);
    ADC::set(ADC::Vref::AVCC);
    while (true) {
        serial.printLn("Reading ADC");
        serial.printLn(ADC::read(ADC::Channel::ADC0));
        _delay_ms(1000);
    }
}

#include <adc.h>
#include <printer.h>
#include <stdio.h>
#include <usart.h>
#include <util/delay.h>

auto constexpr baud = USART::get_baud<BAUD, 2>();
auto usart          = USART::Async<USART::USART0>();
auto serial         = Printer<USART::Async<USART::USART0>, RN>(usart);

int
main(void)
{
    usart.set(baud);
    usart.enable(USART::Channel::TX);
    ADC::set(ADC::Prescaler::DIV_2);
    ADC::set(ADC::Vref::AVCC);
    while (true) {
        serial.printLn("Reading ADC");
        serial.printLn(ADC::read(ADC::Channel::ADC0));
        _delay_ms(1000);
    }
}

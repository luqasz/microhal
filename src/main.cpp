#include "adc.h"
#include "display/hd44780.h"
#include "irq.h"
#include "printer.h"
#include "usart.h"

#include <stdlib.h>
#include <util/delay.h>

int
main(void)
{
    Irq::enable();

    auto usart = USART::Master();
    usart.set(USART::BaudRate_2x::x2_115200);
    usart.enable(USART::Channel::TX);
    auto serial = Printer<USART::Master, None>(usart);

    auto const lcd = HD44780::LCD(
        GPIO::PortC,
        GPIO::PA0,
        GPIO::PA1,
        GPIO::PA2);
    lcd.set(HD44780::Cmd::CursorHome);
    auto display = Printer(lcd);

    ADC::set(ADC::Prescaler::DIV_32);
    ADC::set(ADC::Channel::ADC7);
    ADC::set(ADC::Vref::AVCC);
    ADC::set(ADC::TriggerSource::FreeRunning);
    ADC::start();

    display.print("ADC: ");
    serial.printLn("starting");
    while (true) {
        _delay_ms(1000);
        lcd.set({ 0, 5 });
        uint16_t val = ADC::read();
        display.print(val);
        serial.printLn(val);
    }
}

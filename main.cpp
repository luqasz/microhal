#include <adc.h>
#include <display/hd44780.h>
#include <eeprom.h>
#include <gpio.h>
#include <irq.h>
#include <pin_irq.h>
#include <printer.h>
#include <stdlib.h>
#include <usart.h>

auto constexpr baud = USART::get_baud<115200, 2>();
auto usart          = USART::Async<USART::USART0>();
auto serial         = Printer<USART::Async<USART::USART0>, RN>(usart);

int
main(void)
{
    auto lcd     = HD44780::LCD(GPIO::PortA, GPIO::PB1, GPIO::PB2, GPIO::PB3);
    auto display = Printer<HD44780::LCD<GPIO::Port>, None>(lcd);
    display.print("napis");
    Irq::enable();
    usart.set(baud);
    usart.enable(USART::Channel::TX);
    serial.printLn("starting");
    uint16_t eeaddress = EEPROM::start;
    uint8_t  read      = EEPROM::read(eeaddress);
    serial.printLn(read);
    PinIRQ::set(PinIRQ::INT0, PinIRQ::Trigger::Rising);
    PinIRQ::enable(PinIRQ::INT0);
    while (true) {
    }
}

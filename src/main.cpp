#include "adc.h"
#include "display/hd44780.h"
#include "eeprom.h"
#include "gpio.h"
#include "irq.h"
#include "printer.h"
#include "usart.h"

#include <stdlib.h>

auto usart  = USART::Async<USART::USART0>();
auto serial = Printer<USART::Async<USART::USART0>, RN>(usart);

int
main(void)
{
    auto lcd     = HD44780::LCD(GPIO::PortA, GPIO::PB1, GPIO::PB2, GPIO::PB3);
    auto display = Printer<HD44780::LCD<GPIO::Port>, None>(lcd);
    display.print("napis");
    Irq::enable();
    usart.set(USART::BaudRate_2x::x2_115200);
    usart.enable(USART::Channel::TX);
    serial.printLn("starting");
    uint16_t eeaddress = EEPROM::start;
    uint8_t  read      = EEPROM::read(eeaddress);
    serial.printLn(read);
    while (true) {
    }
}

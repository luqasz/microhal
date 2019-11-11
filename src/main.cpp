#include "adc.h"
#include "eeprom.h"
#include "irq.h"
#include "printer.h"
#include "usart.h"

#include <stdlib.h>

auto usart  = USART::Async();
auto serial = Printer<USART::Async, RN>(usart);

int
main(void)
{
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

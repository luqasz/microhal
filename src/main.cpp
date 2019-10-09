#include "adc.h"
#include "eeprom.h"
#include "irq.h"
#include "printer.h"
#include "usart.h"

#include <stdlib.h>

auto usart  = USART::Master();
auto serial = Printer<USART::Master, RN>(usart);

int
main(void)
{
    Irq::enable();

    usart.set(USART::BaudRate_2x::x2_115200);
    usart.enable(USART::Channel::TX);
    serial.printLn("starting");
    uint16_t eeaddress = EEPROM::start;
    EEPROM::write(value, eeaddress);
    uint8_t read = EEPROM::read(eeaddress);
    serial.printLn(read);
    while (true) {
    }
}
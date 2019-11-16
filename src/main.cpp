#include "adc.h"
#include "eeprom.h"
#include "gpio.h"
#include "irq.h"
#include "printer.h"
#include "usart.h"

#include <stdlib.h>

auto usart  = USART::Async(USART::USART0);
auto serial = Printer<USART::Async, RN>(usart);

int
main(void)
{
    auto pin = GPIO::OutputPin(GPIO::PA1);
    pin.set(GPIO::PinState::High);
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

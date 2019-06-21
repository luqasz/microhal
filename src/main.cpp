#include "adc.h"
#include "eeprom.h"
#include "irq.h"
#include "printer.h"
#include "timer.h"
#include "usart.h"

#include <stdlib.h>
#include <util/delay.h>

uint8_t val    = 0;
auto    usart  = USART::Master();
auto    serial = Printer<USART::Master, RN>(usart);

int
main(void)
{
    Irq::enable();

    usart.set(USART::BaudRate_2x::x2_115200);
    usart.enable(USART::Channel::TX);

    Timer0::set(Timer0::Clock::_1024);
    Timer0::set(Timer0::Mode::Normal);
    Timer0::enable(Timer0::Irq::OnOverflow);

    serial.printLn("starting");
    serial.printLn(EEPROM::read(0x00));
    while (true) {
    }
}

void
Irq::Timer0_Overflow()
{
    val++;
    serial.printLn(val);
}
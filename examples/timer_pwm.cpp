#include "adc.h"
#include "eeprom.h"
#include "gpio.h"
#include "irq.h"
#include "pin_irq.h"
#include "printer.h"
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
    serial.printLn("starting");
    GPIO::OutputPin(GPIO::PD5);
    GPIO::OutputPin(GPIO::PD4);
    auto top    = Register<SFR::ICR1, uint16_t>();
    auto duty_a = Register<SFR::OCR1A, uint16_t>();
    auto duty_b = Register<SFR::OCR1B, uint16_t>();
    auto tccra  = Register<SFR::TCCR1A, uint8_t>();
    auto tccrb  = Register<SFR::TCCR1B, uint8_t>();
    // Set non-inverting mode
    tccra.setBit(tccra.COM1A1);
    tccra.setBit(tccra.COM1B1);
    // Set fast PWM mode, ICR1 as TOP
    tccra.setBit(tccra.WGM11);
    tccrb.setBit(tccrb.WGM12);
    tccrb.setBit(tccrb.WGM13);
    // Prescaler /1
    tccrb.setBit(tccrb.CS10);

    top    = 11058;
    duty_a = 4000;
    duty_b = 6000;
    while (true) {
    }
}

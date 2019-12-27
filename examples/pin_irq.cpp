#include <gpio.h>
#include <irq.h>
#include <pin_irq.h>
#include <sfr.h>
#include <stdio.h>

const auto TOGGLE_PIN = GPIO::PA0;

int
main(void)
{
    GPIO::set(TOGGLE_PIN, GPIO::Output);
    GPIO::write(TOGGLE_PIN, GPIO::High);

    auto pinInterrupt = PinIRQ::INT<PinIRQ::INT0>();
    pinInterrupt.set(PinIRQ::Trigger::Rising);
    pinInterrupt.enable();

    Irq::enable();
    while (true) {
    }
}

void
Irq::INT0()
{
    GPIO::toggle(TOGGLE_PIN);
}

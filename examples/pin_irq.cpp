#include <gpio.h>
#include <irq.h>
#include <pin_irq.h>

const auto TOGGLE_PIN = GPIO::Output(GPIO::PA0);

int
main(void)
{

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
    TOGGLE_PIN.toggle();
}

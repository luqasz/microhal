#include <gpio.hpp>
#include <irq.hpp>
#include <pin_irq.hpp>

const auto TOGGLE_PIN = gpio::Output(gpio::PA0);

int
main(void)
{

    auto pinInterrupt = PinIRQ::INT<PinIRQ::INT0>();
    pinInterrupt.set(PinIRQ::Trigger::Rising);
    pinInterrupt.enable();

    IRQ::enable();
    while (true) {
    }
}

void
IRQ::INT0()
{
    TOGGLE_PIN.toggle();
}

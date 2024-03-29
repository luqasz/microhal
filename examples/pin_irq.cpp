#include <gpio.hpp>
#include <irq.hpp>
#include <pin_irq.hpp>

const auto TOGGLE_PIN = gpio::PA0;

int
main(void)
{
    gpio::Input(gpio::PD2);
    PinIRQ::set(PinIRQ::INT0, PinIRQ::Rising);
    PinIRQ::enable(PinIRQ::INT0);

    irq::global_enable();
    while (true) {
    }
}

void
irq::INT0::handler()
{
    static const auto pin = gpio::Output(TOGGLE_PIN);
    pin.toggle();
}

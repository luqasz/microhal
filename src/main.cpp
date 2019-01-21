#include "gpio.h"

int
main(void)
{
    GPIO::PC0.output() = GPIO::PinState::Low;
    while (true) {
    }
}

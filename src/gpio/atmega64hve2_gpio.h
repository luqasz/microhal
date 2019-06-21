#ifndef atmega64hve2_gpio_h
#define atmega64hve2_gpio_h

#include "../gpio.h"

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega64HVE2
*/

namespace GPIO {

    auto const PortA = GPIO::Port {
        0x22,
        0x20,
        0x21,
    };

    auto const PA0 = GPIO::Pin {
        PortA,
        GPIO::Pin0,
    };

    auto const PA1 = GPIO::Pin {
        PortA,
        GPIO::Pin1,
    };

    auto const PA2 = GPIO::Pin {
        PortA,
        GPIO::Pin2,
    };

    auto const PA3 = GPIO::Pin {
        PortA,
        GPIO::Pin3,
    };

    auto const PA4 = GPIO::Pin {
        PortA,
        GPIO::Pin4,
    };

    auto const PA5 = GPIO::Pin {
        PortA,
        GPIO::Pin5,
    };

    auto const PA6 = GPIO::Pin {
        PortA,
        GPIO::Pin6,
    };

    auto const PA7 = GPIO::Pin {
        PortA,
        GPIO::Pin7,
    };

    auto const PortB = GPIO::Port {
        0x25,
        0x23,
        0x24,
    };

    auto const PB0 = GPIO::Pin {
        PortB,
        GPIO::Pin0,
    };

    auto const PB1 = GPIO::Pin {
        PortB,
        GPIO::Pin1,
    };

    auto const PB2 = GPIO::Pin {
        PortB,
        GPIO::Pin2,
    };

    auto const PB3 = GPIO::Pin {
        PortB,
        GPIO::Pin3,
    };

    auto const PB4 = GPIO::Pin {
        PortB,
        GPIO::Pin4,
    };

    auto const PB5 = GPIO::Pin {
        PortB,
        GPIO::Pin5,
    };

    auto const PB6 = GPIO::Pin {
        PortB,
        GPIO::Pin6,
    };

    auto const PB7 = GPIO::Pin {
        PortB,
        GPIO::Pin7,
    };

}

#endif

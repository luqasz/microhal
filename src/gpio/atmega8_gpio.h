#ifndef atmega8_gpio_h
#define atmega8_gpio_h

#include "../gpio.h"

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega8
*/

namespace GPIO {

    auto const PortC = GPIO::Port {
        0x35,
        0x33,
        0x34,
    };

    auto const PC0 = GPIO::Pin {
        PortC,
        GPIO::Pin0,
    };

    auto const PC1 = GPIO::Pin {
        PortC,
        GPIO::Pin1,
    };

    auto const PC2 = GPIO::Pin {
        PortC,
        GPIO::Pin2,
    };

    auto const PC3 = GPIO::Pin {
        PortC,
        GPIO::Pin3,
    };

    auto const PC4 = GPIO::Pin {
        PortC,
        GPIO::Pin4,
    };

    auto const PC5 = GPIO::Pin {
        PortC,
        GPIO::Pin5,
    };

    auto const PC6 = GPIO::Pin {
        PortC,
        GPIO::Pin6,
    };

    auto const PC7 = GPIO::Pin {
        PortC,
        GPIO::Pin7,
    };

    auto const PortB = GPIO::Port {
        0x38,
        0x36,
        0x37,
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

    auto const PortD = GPIO::Port {
        0x32,
        0x30,
        0x31,
    };

    auto const PD0 = GPIO::Pin {
        PortD,
        GPIO::Pin0,
    };

    auto const PD1 = GPIO::Pin {
        PortD,
        GPIO::Pin1,
    };

    auto const PD2 = GPIO::Pin {
        PortD,
        GPIO::Pin2,
    };

    auto const PD3 = GPIO::Pin {
        PortD,
        GPIO::Pin3,
    };

    auto const PD4 = GPIO::Pin {
        PortD,
        GPIO::Pin4,
    };

    auto const PD5 = GPIO::Pin {
        PortD,
        GPIO::Pin5,
    };

    auto const PD6 = GPIO::Pin {
        PortD,
        GPIO::Pin6,
    };

    auto const PD7 = GPIO::Pin {
        PortD,
        GPIO::Pin7,
    };

}

#endif

#ifndef atmega3250p_gpio_h
#define atmega3250p_gpio_h

#include "../gpio.h"

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega3250P
*/

namespace GPIO {

    auto const PortF = GPIO::Port {
        0x31,
        0x2f,
        0x30,
    };

    auto const PF0 = GPIO::Pin {
        PortF,
        GPIO::Pin0,
    };

    auto const PF1 = GPIO::Pin {
        PortF,
        GPIO::Pin1,
    };

    auto const PF2 = GPIO::Pin {
        PortF,
        GPIO::Pin2,
    };

    auto const PF3 = GPIO::Pin {
        PortF,
        GPIO::Pin3,
    };

    auto const PF4 = GPIO::Pin {
        PortF,
        GPIO::Pin4,
    };

    auto const PF5 = GPIO::Pin {
        PortF,
        GPIO::Pin5,
    };

    auto const PF6 = GPIO::Pin {
        PortF,
        GPIO::Pin6,
    };

    auto const PF7 = GPIO::Pin {
        PortF,
        GPIO::Pin7,
    };

    auto const PortG = GPIO::Port {
        0x34,
        0x32,
        0x33,
    };

    auto const PG0 = GPIO::Pin {
        PortG,
        GPIO::Pin0,
    };

    auto const PG1 = GPIO::Pin {
        PortG,
        GPIO::Pin1,
    };

    auto const PG2 = GPIO::Pin {
        PortG,
        GPIO::Pin2,
    };

    auto const PG3 = GPIO::Pin {
        PortG,
        GPIO::Pin3,
    };

    auto const PG4 = GPIO::Pin {
        PortG,
        GPIO::Pin4,
    };

    auto const PG5 = GPIO::Pin {
        PortG,
        GPIO::Pin5,
    };

    auto const PG6 = GPIO::Pin {
        PortG,
        GPIO::Pin6,
    };

    auto const PG7 = GPIO::Pin {
        PortG,
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

    auto const PortE = GPIO::Port {
        0x2e,
        0x2c,
        0x2d,
    };

    auto const PE0 = GPIO::Pin {
        PortE,
        GPIO::Pin0,
    };

    auto const PE1 = GPIO::Pin {
        PortE,
        GPIO::Pin1,
    };

    auto const PE2 = GPIO::Pin {
        PortE,
        GPIO::Pin2,
    };

    auto const PE3 = GPIO::Pin {
        PortE,
        GPIO::Pin3,
    };

    auto const PE4 = GPIO::Pin {
        PortE,
        GPIO::Pin4,
    };

    auto const PE5 = GPIO::Pin {
        PortE,
        GPIO::Pin5,
    };

    auto const PE6 = GPIO::Pin {
        PortE,
        GPIO::Pin6,
    };

    auto const PE7 = GPIO::Pin {
        PortE,
        GPIO::Pin7,
    };

    auto const PortH = GPIO::Port {
        0xda,
        0xd8,
        0xd9,
    };

    auto const PH0 = GPIO::Pin {
        PortH,
        GPIO::Pin0,
    };

    auto const PH1 = GPIO::Pin {
        PortH,
        GPIO::Pin1,
    };

    auto const PH2 = GPIO::Pin {
        PortH,
        GPIO::Pin2,
    };

    auto const PH3 = GPIO::Pin {
        PortH,
        GPIO::Pin3,
    };

    auto const PH4 = GPIO::Pin {
        PortH,
        GPIO::Pin4,
    };

    auto const PH5 = GPIO::Pin {
        PortH,
        GPIO::Pin5,
    };

    auto const PH6 = GPIO::Pin {
        PortH,
        GPIO::Pin6,
    };

    auto const PH7 = GPIO::Pin {
        PortH,
        GPIO::Pin7,
    };

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

    auto const PortC = GPIO::Port {
        0x28,
        0x26,
        0x27,
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

    auto const PortD = GPIO::Port {
        0x2b,
        0x29,
        0x2a,
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

    auto const PortJ = GPIO::Port {
        0xdd,
        0xdb,
        0xdc,
    };

    auto const PJ0 = GPIO::Pin {
        PortJ,
        GPIO::Pin0,
    };

    auto const PJ1 = GPIO::Pin {
        PortJ,
        GPIO::Pin1,
    };

    auto const PJ2 = GPIO::Pin {
        PortJ,
        GPIO::Pin2,
    };

    auto const PJ3 = GPIO::Pin {
        PortJ,
        GPIO::Pin3,
    };

    auto const PJ4 = GPIO::Pin {
        PortJ,
        GPIO::Pin4,
    };

    auto const PJ5 = GPIO::Pin {
        PortJ,
        GPIO::Pin5,
    };

    auto const PJ6 = GPIO::Pin {
        PortJ,
        GPIO::Pin6,
    };

    auto const PJ7 = GPIO::Pin {
        PortJ,
        GPIO::Pin7,
    };

}

#endif

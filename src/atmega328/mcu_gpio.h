#pragma once

#include "../gpio.h"
#include "mcu_sfr.h"

#include <stdint.h>

namespace GPIO {

    auto constexpr PortC = GPIO::Port {
        SFR::PORTC::address,
        SFR::PINC::address,
        SFR::DDRC::address,
    };

    auto constexpr PC0 = GPIO::Pin {
        PortC,
        GPIO::Pin0,
    };
    auto constexpr PC1 = GPIO::Pin {
        PortC,
        GPIO::Pin1,
    };
    auto constexpr PC2 = GPIO::Pin {
        PortC,
        GPIO::Pin2,
    };
    auto constexpr PC3 = GPIO::Pin {
        PortC,
        GPIO::Pin3,
    };
    auto constexpr PC4 = GPIO::Pin {
        PortC,
        GPIO::Pin4,
    };
    auto constexpr PC5 = GPIO::Pin {
        PortC,
        GPIO::Pin5,
    };
    auto constexpr PC6 = GPIO::Pin {
        PortC,
        GPIO::Pin6,
    };
    auto constexpr PC7 = GPIO::Pin {
        PortC,
        GPIO::Pin7,
    };

    auto constexpr PortB = GPIO::Port {
        SFR::PORTB::address,
        SFR::PINB::address,
        SFR::DDRB::address,
    };

    auto constexpr PB0 = GPIO::Pin {
        PortB,
        GPIO::Pin0,
    };
    auto constexpr PB1 = GPIO::Pin {
        PortB,
        GPIO::Pin1,
    };
    auto constexpr PB2 = GPIO::Pin {
        PortB,
        GPIO::Pin2,
    };
    auto constexpr PB3 = GPIO::Pin {
        PortB,
        GPIO::Pin3,
    };
    auto constexpr PB4 = GPIO::Pin {
        PortB,
        GPIO::Pin4,
    };
    auto constexpr PB5 = GPIO::Pin {
        PortB,
        GPIO::Pin5,
    };
    auto constexpr PB6 = GPIO::Pin {
        PortB,
        GPIO::Pin6,
    };
    auto constexpr PB7 = GPIO::Pin {
        PortB,
        GPIO::Pin7,
    };

    auto constexpr PortD = GPIO::Port {
        SFR::PORTD::address,
        SFR::PIND::address,
        SFR::DDRD::address,
    };

    auto constexpr PD0 = GPIO::Pin {
        PortD,
        GPIO::Pin0,
    };
    auto constexpr PD1 = GPIO::Pin {
        PortD,
        GPIO::Pin1,
    };
    auto constexpr PD2 = GPIO::Pin {
        PortD,
        GPIO::Pin2,
    };
    auto constexpr PD3 = GPIO::Pin {
        PortD,
        GPIO::Pin3,
    };
    auto constexpr PD4 = GPIO::Pin {
        PortD,
        GPIO::Pin4,
    };
    auto constexpr PD5 = GPIO::Pin {
        PortD,
        GPIO::Pin5,
    };
    auto constexpr PD6 = GPIO::Pin {
        PortD,
        GPIO::Pin6,
    };
    auto constexpr PD7 = GPIO::Pin {
        PortD,
        GPIO::Pin7,
    };

}

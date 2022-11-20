#pragma once

#include "../common/atmega/gpio.hpp"
#include "../../gpio.hpp"
#include "sfr.hpp"

#include <stdint.h>

namespace gpio {

    auto constexpr PortD = Port {
        SFR::PORTD::address,
        SFR::PIND::address,
        SFR::DDRD::address,
    };

    auto constexpr PD0 = Pin {
        PortD,
        Pin0,
    };
    auto constexpr PD1 = Pin {
        PortD,
        Pin1,
    };
    auto constexpr PD2 = Pin {
        PortD,
        Pin2,
    };
    auto constexpr PD3 = Pin {
        PortD,
        Pin3,
    };
    auto constexpr PD4 = Pin {
        PortD,
        Pin4,
    };
    auto constexpr PD5 = Pin {
        PortD,
        Pin5,
    };
    auto constexpr PD6 = Pin {
        PortD,
        Pin6,
    };
    auto constexpr PD7 = Pin {
        PortD,
        Pin7,
    };

    auto constexpr PortB = Port {
        SFR::PORTB::address,
        SFR::PINB::address,
        SFR::DDRB::address,
    };

    auto constexpr PB0 = Pin {
        PortB,
        Pin0,
    };
    auto constexpr PB1 = Pin {
        PortB,
        Pin1,
    };
    auto constexpr PB2 = Pin {
        PortB,
        Pin2,
    };
    auto constexpr PB3 = Pin {
        PortB,
        Pin3,
    };
    auto constexpr PB4 = Pin {
        PortB,
        Pin4,
    };
    auto constexpr PB5 = Pin {
        PortB,
        Pin5,
    };
    auto constexpr PB6 = Pin {
        PortB,
        Pin6,
    };
    auto constexpr PB7 = Pin {
        PortB,
        Pin7,
    };

    auto constexpr PortA = Port {
        SFR::PORTA::address,
        SFR::PINA::address,
        SFR::DDRA::address,
    };

    auto constexpr PA0 = Pin {
        PortA,
        Pin0,
    };
    auto constexpr PA1 = Pin {
        PortA,
        Pin1,
    };
    auto constexpr PA2 = Pin {
        PortA,
        Pin2,
    };
    auto constexpr PA3 = Pin {
        PortA,
        Pin3,
    };
    auto constexpr PA4 = Pin {
        PortA,
        Pin4,
    };
    auto constexpr PA5 = Pin {
        PortA,
        Pin5,
    };
    auto constexpr PA6 = Pin {
        PortA,
        Pin6,
    };
    auto constexpr PA7 = Pin {
        PortA,
        Pin7,
    };

    auto constexpr PortC = Port {
        SFR::PORTC::address,
        SFR::PINC::address,
        SFR::DDRC::address,
    };

    auto constexpr PC0 = Pin {
        PortC,
        Pin0,
    };
    auto constexpr PC1 = Pin {
        PortC,
        Pin1,
    };
    auto constexpr PC2 = Pin {
        PortC,
        Pin2,
    };
    auto constexpr PC3 = Pin {
        PortC,
        Pin3,
    };
    auto constexpr PC4 = Pin {
        PortC,
        Pin4,
    };
    auto constexpr PC5 = Pin {
        PortC,
        Pin5,
    };
    auto constexpr PC6 = Pin {
        PortC,
        Pin6,
    };
    auto constexpr PC7 = Pin {
        PortC,
        Pin7,
    };

}

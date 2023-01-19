#pragma once

#include "../common/atmega/gpio.hpp"
#include "../../gpio.hpp"
#include "sfr.hpp"

#include <stdint.h>

namespace gpio {

    auto constexpr PortG = Port {
        SFR::PORTG::address,
        SFR::PING::address,
        SFR::DDRG::address,
    };

    auto constexpr PG0 = Pin {
        PortG,
        Pin0,
    };
    auto constexpr PG1 = Pin {
        PortG,
        Pin1,
    };
    auto constexpr PG2 = Pin {
        PortG,
        Pin2,
    };
    auto constexpr PG3 = Pin {
        PortG,
        Pin3,
    };
    auto constexpr PG4 = Pin {
        PortG,
        Pin4,
    };
    auto constexpr PG5 = Pin {
        PortG,
        Pin5,
    };
    auto constexpr PG6 = Pin {
        PortG,
        Pin6,
    };
    auto constexpr PG7 = Pin {
        PortG,
        Pin7,
    };

    auto constexpr PortL = Port {
        SFR::PORTL::address,
        SFR::PINL::address,
        SFR::DDRL::address,
    };

    auto constexpr PL0 = Pin {
        PortL,
        Pin0,
    };
    auto constexpr PL1 = Pin {
        PortL,
        Pin1,
    };
    auto constexpr PL2 = Pin {
        PortL,
        Pin2,
    };
    auto constexpr PL3 = Pin {
        PortL,
        Pin3,
    };
    auto constexpr PL4 = Pin {
        PortL,
        Pin4,
    };
    auto constexpr PL5 = Pin {
        PortL,
        Pin5,
    };
    auto constexpr PL6 = Pin {
        PortL,
        Pin6,
    };
    auto constexpr PL7 = Pin {
        PortL,
        Pin7,
    };

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

    auto constexpr PortK = Port {
        SFR::PORTK::address,
        SFR::PINK::address,
        SFR::DDRK::address,
    };

    auto constexpr PK0 = Pin {
        PortK,
        Pin0,
    };
    auto constexpr PK1 = Pin {
        PortK,
        Pin1,
    };
    auto constexpr PK2 = Pin {
        PortK,
        Pin2,
    };
    auto constexpr PK3 = Pin {
        PortK,
        Pin3,
    };
    auto constexpr PK4 = Pin {
        PortK,
        Pin4,
    };
    auto constexpr PK5 = Pin {
        PortK,
        Pin5,
    };
    auto constexpr PK6 = Pin {
        PortK,
        Pin6,
    };
    auto constexpr PK7 = Pin {
        PortK,
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

    auto constexpr PortF = Port {
        SFR::PORTF::address,
        SFR::PINF::address,
        SFR::DDRF::address,
    };

    auto constexpr PF0 = Pin {
        PortF,
        Pin0,
    };
    auto constexpr PF1 = Pin {
        PortF,
        Pin1,
    };
    auto constexpr PF2 = Pin {
        PortF,
        Pin2,
    };
    auto constexpr PF3 = Pin {
        PortF,
        Pin3,
    };
    auto constexpr PF4 = Pin {
        PortF,
        Pin4,
    };
    auto constexpr PF5 = Pin {
        PortF,
        Pin5,
    };
    auto constexpr PF6 = Pin {
        PortF,
        Pin6,
    };
    auto constexpr PF7 = Pin {
        PortF,
        Pin7,
    };

    auto constexpr PortE = Port {
        SFR::PORTE::address,
        SFR::PINE::address,
        SFR::DDRE::address,
    };

    auto constexpr PE0 = Pin {
        PortE,
        Pin0,
    };
    auto constexpr PE1 = Pin {
        PortE,
        Pin1,
    };
    auto constexpr PE2 = Pin {
        PortE,
        Pin2,
    };
    auto constexpr PE3 = Pin {
        PortE,
        Pin3,
    };
    auto constexpr PE4 = Pin {
        PortE,
        Pin4,
    };
    auto constexpr PE5 = Pin {
        PortE,
        Pin5,
    };
    auto constexpr PE6 = Pin {
        PortE,
        Pin6,
    };
    auto constexpr PE7 = Pin {
        PortE,
        Pin7,
    };

    auto constexpr PortJ = Port {
        SFR::PORTJ::address,
        SFR::PINJ::address,
        SFR::DDRJ::address,
    };

    auto constexpr PJ0 = Pin {
        PortJ,
        Pin0,
    };
    auto constexpr PJ1 = Pin {
        PortJ,
        Pin1,
    };
    auto constexpr PJ2 = Pin {
        PortJ,
        Pin2,
    };
    auto constexpr PJ3 = Pin {
        PortJ,
        Pin3,
    };
    auto constexpr PJ4 = Pin {
        PortJ,
        Pin4,
    };
    auto constexpr PJ5 = Pin {
        PortJ,
        Pin5,
    };
    auto constexpr PJ6 = Pin {
        PortJ,
        Pin6,
    };
    auto constexpr PJ7 = Pin {
        PortJ,
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

    auto constexpr PortH = Port {
        SFR::PORTH::address,
        SFR::PINH::address,
        SFR::DDRH::address,
    };

    auto constexpr PH0 = Pin {
        PortH,
        Pin0,
    };
    auto constexpr PH1 = Pin {
        PortH,
        Pin1,
    };
    auto constexpr PH2 = Pin {
        PortH,
        Pin2,
    };
    auto constexpr PH3 = Pin {
        PortH,
        Pin3,
    };
    auto constexpr PH4 = Pin {
        PortH,
        Pin4,
    };
    auto constexpr PH5 = Pin {
        PortH,
        Pin5,
    };
    auto constexpr PH6 = Pin {
        PortH,
        Pin6,
    };
    auto constexpr PH7 = Pin {
        PortH,
        Pin7,
    };

}

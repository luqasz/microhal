#pragma once

#include "../gpio.h"
#include "mcu_sfr.h"

#include <stdint.h>

namespace GPIO {

    auto constexpr PortG = GPIO::Port {
        SFR::PORTG::address,
        SFR::PING::address,
        SFR::DDRG::address,
    };

    auto constexpr PG0 = GPIO::Pin {
        PortG,
        GPIO::Pin0,
    };
    auto constexpr PG1 = GPIO::Pin {
        PortG,
        GPIO::Pin1,
    };
    auto constexpr PG2 = GPIO::Pin {
        PortG,
        GPIO::Pin2,
    };
    auto constexpr PG3 = GPIO::Pin {
        PortG,
        GPIO::Pin3,
    };
    auto constexpr PG4 = GPIO::Pin {
        PortG,
        GPIO::Pin4,
    };
    auto constexpr PG5 = GPIO::Pin {
        PortG,
        GPIO::Pin5,
    };
    auto constexpr PG6 = GPIO::Pin {
        PortG,
        GPIO::Pin6,
    };
    auto constexpr PG7 = GPIO::Pin {
        PortG,
        GPIO::Pin7,
    };

    auto constexpr PortL = GPIO::Port {
        SFR::PORTL::address,
        SFR::PINL::address,
        SFR::DDRL::address,
    };

    auto constexpr PL0 = GPIO::Pin {
        PortL,
        GPIO::Pin0,
    };
    auto constexpr PL1 = GPIO::Pin {
        PortL,
        GPIO::Pin1,
    };
    auto constexpr PL2 = GPIO::Pin {
        PortL,
        GPIO::Pin2,
    };
    auto constexpr PL3 = GPIO::Pin {
        PortL,
        GPIO::Pin3,
    };
    auto constexpr PL4 = GPIO::Pin {
        PortL,
        GPIO::Pin4,
    };
    auto constexpr PL5 = GPIO::Pin {
        PortL,
        GPIO::Pin5,
    };
    auto constexpr PL6 = GPIO::Pin {
        PortL,
        GPIO::Pin6,
    };
    auto constexpr PL7 = GPIO::Pin {
        PortL,
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

    auto constexpr PortK = GPIO::Port {
        SFR::PORTK::address,
        SFR::PINK::address,
        SFR::DDRK::address,
    };

    auto constexpr PK0 = GPIO::Pin {
        PortK,
        GPIO::Pin0,
    };
    auto constexpr PK1 = GPIO::Pin {
        PortK,
        GPIO::Pin1,
    };
    auto constexpr PK2 = GPIO::Pin {
        PortK,
        GPIO::Pin2,
    };
    auto constexpr PK3 = GPIO::Pin {
        PortK,
        GPIO::Pin3,
    };
    auto constexpr PK4 = GPIO::Pin {
        PortK,
        GPIO::Pin4,
    };
    auto constexpr PK5 = GPIO::Pin {
        PortK,
        GPIO::Pin5,
    };
    auto constexpr PK6 = GPIO::Pin {
        PortK,
        GPIO::Pin6,
    };
    auto constexpr PK7 = GPIO::Pin {
        PortK,
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

    auto constexpr PortF = GPIO::Port {
        SFR::PORTF::address,
        SFR::PINF::address,
        SFR::DDRF::address,
    };

    auto constexpr PF0 = GPIO::Pin {
        PortF,
        GPIO::Pin0,
    };
    auto constexpr PF1 = GPIO::Pin {
        PortF,
        GPIO::Pin1,
    };
    auto constexpr PF2 = GPIO::Pin {
        PortF,
        GPIO::Pin2,
    };
    auto constexpr PF3 = GPIO::Pin {
        PortF,
        GPIO::Pin3,
    };
    auto constexpr PF4 = GPIO::Pin {
        PortF,
        GPIO::Pin4,
    };
    auto constexpr PF5 = GPIO::Pin {
        PortF,
        GPIO::Pin5,
    };
    auto constexpr PF6 = GPIO::Pin {
        PortF,
        GPIO::Pin6,
    };
    auto constexpr PF7 = GPIO::Pin {
        PortF,
        GPIO::Pin7,
    };

    auto constexpr PortE = GPIO::Port {
        SFR::PORTE::address,
        SFR::PINE::address,
        SFR::DDRE::address,
    };

    auto constexpr PE0 = GPIO::Pin {
        PortE,
        GPIO::Pin0,
    };
    auto constexpr PE1 = GPIO::Pin {
        PortE,
        GPIO::Pin1,
    };
    auto constexpr PE2 = GPIO::Pin {
        PortE,
        GPIO::Pin2,
    };
    auto constexpr PE3 = GPIO::Pin {
        PortE,
        GPIO::Pin3,
    };
    auto constexpr PE4 = GPIO::Pin {
        PortE,
        GPIO::Pin4,
    };
    auto constexpr PE5 = GPIO::Pin {
        PortE,
        GPIO::Pin5,
    };
    auto constexpr PE6 = GPIO::Pin {
        PortE,
        GPIO::Pin6,
    };
    auto constexpr PE7 = GPIO::Pin {
        PortE,
        GPIO::Pin7,
    };

    auto constexpr PortJ = GPIO::Port {
        SFR::PORTJ::address,
        SFR::PINJ::address,
        SFR::DDRJ::address,
    };

    auto constexpr PJ0 = GPIO::Pin {
        PortJ,
        GPIO::Pin0,
    };
    auto constexpr PJ1 = GPIO::Pin {
        PortJ,
        GPIO::Pin1,
    };
    auto constexpr PJ2 = GPIO::Pin {
        PortJ,
        GPIO::Pin2,
    };
    auto constexpr PJ3 = GPIO::Pin {
        PortJ,
        GPIO::Pin3,
    };
    auto constexpr PJ4 = GPIO::Pin {
        PortJ,
        GPIO::Pin4,
    };
    auto constexpr PJ5 = GPIO::Pin {
        PortJ,
        GPIO::Pin5,
    };
    auto constexpr PJ6 = GPIO::Pin {
        PortJ,
        GPIO::Pin6,
    };
    auto constexpr PJ7 = GPIO::Pin {
        PortJ,
        GPIO::Pin7,
    };

    auto constexpr PortA = GPIO::Port {
        SFR::PORTA::address,
        SFR::PINA::address,
        SFR::DDRA::address,
    };

    auto constexpr PA0 = GPIO::Pin {
        PortA,
        GPIO::Pin0,
    };
    auto constexpr PA1 = GPIO::Pin {
        PortA,
        GPIO::Pin1,
    };
    auto constexpr PA2 = GPIO::Pin {
        PortA,
        GPIO::Pin2,
    };
    auto constexpr PA3 = GPIO::Pin {
        PortA,
        GPIO::Pin3,
    };
    auto constexpr PA4 = GPIO::Pin {
        PortA,
        GPIO::Pin4,
    };
    auto constexpr PA5 = GPIO::Pin {
        PortA,
        GPIO::Pin5,
    };
    auto constexpr PA6 = GPIO::Pin {
        PortA,
        GPIO::Pin6,
    };
    auto constexpr PA7 = GPIO::Pin {
        PortA,
        GPIO::Pin7,
    };

    auto constexpr PortH = GPIO::Port {
        SFR::PORTH::address,
        SFR::PINH::address,
        SFR::DDRH::address,
    };

    auto constexpr PH0 = GPIO::Pin {
        PortH,
        GPIO::Pin0,
    };
    auto constexpr PH1 = GPIO::Pin {
        PortH,
        GPIO::Pin1,
    };
    auto constexpr PH2 = GPIO::Pin {
        PortH,
        GPIO::Pin2,
    };
    auto constexpr PH3 = GPIO::Pin {
        PortH,
        GPIO::Pin3,
    };
    auto constexpr PH4 = GPIO::Pin {
        PortH,
        GPIO::Pin4,
    };
    auto constexpr PH5 = GPIO::Pin {
        PortH,
        GPIO::Pin5,
    };
    auto constexpr PH6 = GPIO::Pin {
        PortH,
        GPIO::Pin6,
    };
    auto constexpr PH7 = GPIO::Pin {
        PortH,
        GPIO::Pin7,
    };

}

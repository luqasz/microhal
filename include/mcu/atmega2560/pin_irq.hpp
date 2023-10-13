#pragma once

#include "../common/atmega/pin_irq.hpp"
#include "sfr.hpp"
#include "../../types.hpp"
#include "../../pin_irq.hpp"

namespace PinIRQ {

    using IRQ_ENABLE_REG = SFR::EIMSK;

    constexpr INT INT0 = INT {
        .reg = SFR::EICRA::address,
        .bit_pos = SFR::EICRA::ISC00,
        .irq_bit = IRQ_ENABLE_REG::INT0,
    };

    constexpr INT INT1 = INT {
        .reg = SFR::EICRA::address,
        .bit_pos = SFR::EICRA::ISC10,
        .irq_bit = IRQ_ENABLE_REG::INT1,
    };

    constexpr INT INT2 = INT {
        .reg = SFR::EICRA::address,
        .bit_pos = SFR::EICRA::ISC20,
        .irq_bit = IRQ_ENABLE_REG::INT2,
    };

    constexpr INT INT3 = INT {
        .reg = SFR::EICRA::address,
        .bit_pos = SFR::EICRA::ISC30,
        .irq_bit = IRQ_ENABLE_REG::INT3,
    };

    constexpr INT INT4 = INT {
        .reg = SFR::EICRB::address,
        .bit_pos = SFR::EICRB::ISC40,
        .irq_bit = IRQ_ENABLE_REG::INT4,
    };

    constexpr INT INT5 = INT {
        .reg = SFR::EICRB::address,
        .bit_pos = SFR::EICRB::ISC50,
        .irq_bit = IRQ_ENABLE_REG::INT5,
    };

    constexpr INT INT6 = INT {
        .reg = SFR::EICRB::address,
        .bit_pos = SFR::EICRB::ISC60,
        .irq_bit = IRQ_ENABLE_REG::INT6,
    };

    constexpr INT INT7 = INT {
        .reg = SFR::EICRB::address,
        .bit_pos = SFR::EICRB::ISC70,
        .irq_bit = IRQ_ENABLE_REG::INT7,
    };

}

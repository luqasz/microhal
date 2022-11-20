#pragma once

#include "../common/atmega/pin_irq.hpp"
#include "sfr.hpp"
#include "../../types.hpp"
#include "../../pin_irq.hpp"

namespace PinIRQ {

    using IRQ_ENABLE_REG = SFR::EIMSK;

    constexpr INT INT0 = INT {
        .reg     = SFR::EICRA::address,
        .bit_pos = SFR::EICRA::ISC00,
        .irq_bit = IRQ_ENABLE_REG::INT0,
    };

    constexpr INT INT1 = INT {
        .reg     = SFR::EICRA::address,
        .bit_pos = SFR::EICRA::ISC10,
        .irq_bit = IRQ_ENABLE_REG::INT1,
    };

}

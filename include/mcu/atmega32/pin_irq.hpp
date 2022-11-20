#pragma once

#include "sfr.hpp"
#include "../../types.hpp"
#include "../../pin_irq.hpp"

namespace PinIRQ {

    using IRQ_ENABLE_REG = SFR::GICR;

    constexpr INT INT0 = INT {
        .reg     = SFR::MCUCR::address,
        .bit_pos = SFR::MCUCR::ISC00,
        .irq_bit = IRQ_ENABLE_REG::INT0,
    };

    constexpr INT INT1 = INT {
        .reg     = SFR::MCUCR::address,
        .bit_pos = SFR::MCUCR::ISC10,
        .irq_bit = IRQ_ENABLE_REG::INT1,
    };

}

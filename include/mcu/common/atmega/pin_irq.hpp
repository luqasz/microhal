#pragma once

#include "../../../types.hpp"

namespace PinIRQ {

    struct INT {
        const usize reg;     // Trigger register address.
        const u8    bit_pos; // First bit postition of trigger bits.
        const u8    irq_bit; // IRQ bit in IRQ enable register.
    };

}
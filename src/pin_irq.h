#pragma once

#include "sfr.h"
#include "utils.h"

#include <mcu_pin_irq.h>
#include <stdint.h>

namespace PinIRQ {

    enum Trigger {
        Low     = 0x00,
        Change  = 0x01,
        Falling = 0x02,
        Rising  = 0x03,
    };

    template <typename PIN>
    class INT {

    public:
        void
        set(const Trigger trigger) const
        {
            const uint8_t bit_position = firstLSBBitPos(PIN::EDGE_REG_BIT) - 1;
            uint8_t       reg_value    = PIN::EDGE_REG.read();
            reg_value &= PIN::MASK;
            reg_value |= static_cast<uint8_t>(trigger << bit_position);
            PIN::EDGE_REG = reg_value;
        }

        void
        enable() const
        {
            PIN::ENABLE_REG.setBit(PIN::ENABLE_REG_BIT);
        }

        void
        disable() const
        {
            PIN::ENABLE_REG.clearBit(PIN::ENABLE_REG_BIT);
        }
    };
}

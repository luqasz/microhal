#pragma once

#include "sfr.hpp"
#include "utils.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "atmega32/mcu_pin_irq.hpp"
#    elif MCU == atmega328
#        include "atmega328/mcu_pin_irq.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif
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
            const uint8_t bit_position = firstLSBBitPos(PIN::EDGE_REG_BIT);
            const uint8_t bits         = static_cast<uint8_t>(trigger << bit_position);
            const uint8_t TRIGGER_MASK = static_cast<uint8_t>(0x03 << bit_position);
            PIN::EDGE_REG.setBit(bits, TRIGGER_MASK);
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

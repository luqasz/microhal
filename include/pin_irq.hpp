#pragma once

#include "sfr.hpp"
#include "types.hpp"
#include "utils.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/pin_irq.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/pin_irq.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/pin_irq.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

#include "types.hpp"

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
            const u8 bit_position = firstLSBBitPos(PIN::EDGE_REG_BIT);
            const u8 bits         = static_cast<u8>(trigger << bit_position);
            const u8 TRIGGER_MASK = static_cast<u8>(0x03 << bit_position);
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

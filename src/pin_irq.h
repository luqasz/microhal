#ifndef pin_irq_h
#define pin_irq_h

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

    enum Pin {
        INT0 = 0,
        INT1,
    };

    void
    set_int_edge(const uint8_t value, const uint8_t mask)
    {
        uint8_t reg_value = INT_EDGE_REG.read();
        reg_value &= mask;
        reg_value |= value;
        INT_EDGE_REG = reg_value;
    }

    void
    set(Pin pin, Trigger trigger)
    {
        uint8_t reg_value;
        uint8_t bit_position;
        switch (pin) {
            case Pin::INT0:
                bit_position = firstLSBBitPos(static_cast<uint8_t>(INT_EDGE_REG.ISC00)) - 1;
                reg_value    = static_cast<uint8_t>(trigger << bit_position);
                set_int_edge(reg_value, INT0_TRIGGER_MASK);
                break;
            case Pin::INT1:
                bit_position = firstLSBBitPos(static_cast<uint8_t>(INT_EDGE_REG.ISC01)) - 1;
                reg_value    = static_cast<uint8_t>(trigger << bit_position);
                set_int_edge(reg_value, INT1_TRIGGER_MASK);
                break;
        }
    }

    void
    enable(Pin pin)
    {
        switch (pin) {
            case Pin::INT0:
                INT_IRQ_ENABLE_REG.setBit(INT_IRQ_ENABLE_REG.INT0);
                break;
            case Pin::INT1:
                INT_IRQ_ENABLE_REG.setBit(INT_IRQ_ENABLE_REG.INT1);
                break;
        }
    }

    void
    disable(Pin pin)
    {
        switch (pin) {
            case Pin::INT0:
                INT_IRQ_ENABLE_REG.clearBit(INT_IRQ_ENABLE_REG.INT0);
                break;
            case Pin::INT1:
                INT_IRQ_ENABLE_REG.clearBit(INT_IRQ_ENABLE_REG.INT1);
                break;
        }
    }
}

#endif

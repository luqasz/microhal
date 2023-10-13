#pragma once

#include "sfr.hpp"
#include "types.hpp"
#include "utils.hpp"
#include "iomem.hpp"
#include "gpio.hpp"

#if MCU_ATMEGA32
#    include "mcu/atmega32/pin_irq.hpp"
#elif MCU_ATMEGA328
#    include "mcu/atmega328/pin_irq.hpp"
#elif MCU_ATMEGA2560
#    include "mcu/atmega2560/pin_irq.hpp"
#else
#    error "Unknown MCU."
#endif

namespace PinIRQ {

    enum Trigger {
        Low = 0x00,    // Low level must be held until the completion of the currently executing instruction to generate an interrupt.
        Change = 0x01, // Any logical change will trigger irq.
        Any = Change,
        Falling = 0x02, // Falling edge will trigger irq.
        Rising = 0x03,  // Rising edge will trigger irq.
    };

    inline void
    set(const INT & pin, const Trigger & trigger)
    {
        // TODO
        // When changing the ISCn1/ISCn0 bits, the interrupt must be disabled by clearing its Interrupt Enable bit in the EIMSK Register.
        // Otherwise an interrupt can occur when the bits are changed.
        constexpr u8 TRIGGER_BITS = 0b11;
        const u8 bits = static_cast<u8>(trigger << pin.bit_pos);
        const u8 MASK = static_cast<u8>(TRIGGER_BITS << pin.bit_pos);
        iomem::set_bit<u8>(pin.reg, bits, MASK);
    }

    inline void
    enable(const INT & pin)
    {
        iomem::set_bit<u8>(IRQ_ENABLE_REG::address, pin.irq_bit);
    }

    inline void
    disable(const INT & pin)
    {
        iomem::clear_bit<u8>(IRQ_ENABLE_REG::address, pin.irq_bit);
    }

}

#pragma once

#include "types.hpp"
#include "sfr.hpp"
#include "iomem.hpp"

#if MCU_ATMEGA32
#    include "mcu/atmega32/adc.hpp"
#elif MCU_ATMEGA328
#    include "mcu/atmega328/adc.hpp"
#elif MCU_ATMEGA2560
#    include "mcu/atmega2560/adc.hpp"
#else
#    error "Unknown MCU."
#endif

namespace adc {

    enum class Setting {
        // When Auto Triggering is used, the prescaler is reset when the trigger event occurs.
        AutoTrigger = SFR::ADCSRA::ADATE,
        Irq         = SFR::ADCSRA::ADIE,
        Trigger_Irq = AutoTrigger | Irq,
    };

    enum class Clock {
        Stopped      = 0,
        ClockDiv_2   = SFR::ADCSRA::ADEN | SFR::ADCSRA::ADPS0,
        ClockDiv_4   = SFR::ADCSRA::ADEN | SFR::ADCSRA::ADPS1,
        ClockDiv_8   = SFR::ADCSRA::ADEN | SFR::ADCSRA::ADPS0 | SFR::ADCSRA::ADPS1,
        ClockDiv_16  = SFR::ADCSRA::ADEN | SFR::ADCSRA::ADPS2,
        ClockDiv_32  = SFR::ADCSRA::ADEN | SFR::ADCSRA::ADPS0 | SFR::ADCSRA::ADPS2,
        ClockDiv_64  = SFR::ADCSRA::ADEN | SFR::ADCSRA::ADPS1 | SFR::ADCSRA::ADPS2,
        ClockDiv_128 = SFR::ADCSRA::ADEN | SFR::ADCSRA::ADPS0 | SFR::ADCSRA::ADPS1 | SFR::ADCSRA::ADPS2,
    };

    inline void
    enable(const Setting setting)
    {
        iomem::set_bit<u8>(SFR::ADCSRA::address, static_cast<u8>(setting));
    }

    inline void
    disable(const Setting setting)
    {
        iomem::clear_bit<u8>(SFR::ADCSRA::address, static_cast<u8>(setting));
    }

    inline u16
    read()
    {
        return iomem::read<u16>(SFR::ADC::address);
    }

    inline bool
    pending()
    {
        return iomem::is_set_bit<u8>(SFR::ADCSRA::address, SFR::ADCSRA::ADSC);
    }

    inline void
    set(const Clock value)
    {
        iomem::set_bit<u8>(SFR::ADCSRA::address, static_cast<u8>(value), u8 { PRESCALER_MASK | SFR::ADCSRA::ADEN });
    }

    inline void
    set(const Vref ref)
    {
        iomem::set_bit<u8>(SFR::ADMUX::address, static_cast<u8>(ref), VREF_MASK);
    }

    inline void
    set(const Channel ch)
    {
        const u8 mux = static_cast<u8>(ch);
        iomem::set_bit<u8>(SFR::ADMUX::address, mux & MUX_MASK, MUX_MASK);
        if constexpr (MUX5 != 0) {
            if (mux & MUX5) {
                iomem::set_bit<u8>(MUX5_REG, MUX5);
            }
            else {
                iomem::clear_bit<u8>(MUX5_REG, MUX5);
            }
        }
    }

    inline void
    start()
    {
        // Start conversion
        iomem::set_bit<u8>(SFR::ADCSRA::address, SFR::ADCSRA::ADSC);
    }

    inline void
    set(const Trigger trig)
    {
        iomem::set_bit<u8>(TRIGGER_REG, static_cast<u8>(trig), TRIGGER_MASK);
    }

}

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

    enum class Trigger {
        FreeRunning      = 0,
        AnalogComparator = SFR::ADCSRB::ADTS0,
        ExternalIRQ0     = SFR::ADCSRB::ADTS1,
        Timer0CompareA   = SFR::ADCSRB::ADTS1 | SFR::ADCSRB::ADTS1,
        Timer0Overflow   = SFR::ADCSRB::ADTS2,
        Timer1CompareB   = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS2,
        Timer1Overflow   = SFR::ADCSRB::ADTS1 | SFR::ADCSRB::ADTS2,
        Timer1Capture    = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS1 | SFR::ADCSRB::ADTS2,
    };

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
        if constexpr (SFR::ADCSRB::MUX5 != 0) {
            if (mux & MUX5) {
                iomem::set_bit<u8>(SFR::ADCSRB::address, SFR::ADCSRB::MUX5);
            }
            else {
                iomem::clear_bit<u8>(SFR::ADCSRB::address, SFR::ADCSRB::MUX5);
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
        constexpr static u8 TRIG_MASK = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS1 | SFR::ADCSRB::ADTS2;
        iomem::set_bit<u8>(SFR::ADCSRB::address, static_cast<u8>(trig), TRIG_MASK);
    }

}

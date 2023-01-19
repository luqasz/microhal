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

    inline void
    enable()
    {
        iomem::set_bit<u8>(SFR::ADCSRA::address, SFR::ADCSRA::ADEN);
    }

    inline void
    disable()
    {
        iomem::clear_bit<u8>(SFR::ADCSRA::address, SFR::ADCSRA::ADEN);
    }

    inline u16
    read(const Channel ch)
    {
        enable();
        iomem::set_bit<u8>(SFR::ADCSRA::address, static_cast<u8>(ch), MUX_MASK);
        // Start conversion
        iomem::set_bit<u8>(SFR::ADCSRA::address, SFR::ADCSRA::ADSC);
        // Wait untill conversion is ready
        iomem::clear_bit_wait<u8>(SFR::ADCSRA::address, SFR::ADCSRA::ADSC);
        return iomem::read<u16>(SFR::ADC::address);
    }

    inline void
    set(const Clock value)
    {
        iomem::set_bit(SFR::ADCSRA::address, static_cast<u8>(value), MUX_MASK);
    }

    inline void
    set(const Vref ref)
    {
        iomem::set_bit(SFR::ADMUX::address, static_cast<u8>(ref), VREF_MASK);
    }

}

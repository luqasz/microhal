#pragma once

#include "sfr.hpp"
#include "../../types.hpp"

namespace adc {

    constexpr u8 PRESCALER_MASK = SFR::ADCSRA::ADPS0 | SFR::ADCSRA::ADPS1 | SFR::ADCSRA::ADPS2;
    constexpr u8 MUX_MASK       = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3 | SFR::ADMUX::MUX4;
    constexpr u8 VREF_MASK      = SFR::ADMUX::REFS0 | SFR::ADMUX::REFS1;

    enum class Vref {
        Internal_2_56 = SFR::ADMUX::REFS0 | SFR::ADMUX::REFS1,
        AVCC          = SFR::ADMUX::REFS0,
        AREF          = 0,
    };

    enum class Channel {
        ADC0    = 0,
        ADC1    = SFR::ADMUX::MUX0,
        ADC2    = SFR::ADMUX::MUX1,
        ADC3    = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1,
        ADC4    = SFR::ADMUX::MUX2,
        ADC5    = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX2,
        ADC6    = SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2,
        ADC7    = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2,
        BandGap = SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3 | SFR::ADMUX::MUX4,
        GND     = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3 | SFR::ADMUX::MUX4,
    };

    enum class Clock {
        _2   = SFR::ADCSRA::ADPS0,
        _4   = SFR::ADCSRA::ADPS1,
        _8   = SFR::ADCSRA::ADPS0 | SFR::ADCSRA::ADPS1,
        _16  = SFR::ADCSRA::ADPS2,
        _32  = SFR::ADCSRA::ADPS0 | SFR::ADCSRA::ADPS2,
        _64  = SFR::ADCSRA::ADPS1 | SFR::ADCSRA::ADPS2,
        _128 = SFR::ADCSRA::ADPS0 | SFR::ADCSRA::ADPS1 | SFR::ADCSRA::ADPS2,
    };
}
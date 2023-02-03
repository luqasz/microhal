#pragma once

#include "sfr.hpp"
#include "../../types.hpp"

namespace adc {

    constexpr u8  PRESCALER_MASK = SFR::ADCSRA::ADPS0 | SFR::ADCSRA::ADPS1 | SFR::ADCSRA::ADPS2;
    constexpr u8  MUX_MASK       = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3 | SFR::ADMUX::MUX4;
    constexpr u8  VREF_MASK      = SFR::ADMUX::REFS0 | SFR::ADMUX::REFS1;
    constexpr u8  TRIGGER_MASK   = SFR::SFIOR::ADTS0 | SFR::SFIOR::ADTS1 | SFR::SFIOR::ADTS2;
    constexpr u16 TRIGGER_REG    = SFR::SFIOR::address;
    constexpr u8  MUX5           = 0;
    constexpr u16 MUX5_REG       = SFR::ADMUX::address;

    enum class Trigger {
        FreeRunning      = 0,
        AnalogComparator = SFR::SFIOR::ADTS0,
        ExternalIRQ0     = SFR::SFIOR::ADTS1,
        Timer0CompareA   = SFR::SFIOR::ADTS0 | SFR::SFIOR::ADTS1,
        Timer0Overflow   = SFR::SFIOR::ADTS2,
        Timer1CompareB   = SFR::SFIOR::ADTS0 | SFR::SFIOR::ADTS2,
        Timer1Overflow   = SFR::SFIOR::ADTS1 | SFR::SFIOR::ADTS2,
        Timer1Capture    = SFR::SFIOR::ADTS0 | SFR::SFIOR::ADTS1 | SFR::SFIOR::ADTS2,
    };

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
}

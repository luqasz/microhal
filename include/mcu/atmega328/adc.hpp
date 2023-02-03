#pragma once

#include "sfr.hpp"
#include "../../types.hpp"

namespace adc {

    constexpr u8  PRESCALER_MASK = SFR::ADCSRA::ADPS0 | SFR::ADCSRA::ADPS1 | SFR::ADCSRA::ADPS2;
    constexpr u8  MUX_MASK       = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3;
    constexpr u8  VREF_MASK      = SFR::ADMUX::REFS0 | SFR::ADMUX::REFS1;
    constexpr u8  TRIGGER_MASK   = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS1 | SFR::ADCSRB::ADTS2;
    constexpr u16 TRIGGER_REG    = SFR::ADCSRB::address;
    constexpr u8  MUX5           = 0;
    constexpr u16 MUX5_REG       = SFR::ADMUX::address;

    enum class Trigger {
        FreeRunning      = 0,
        AnalogComparator = SFR::ADCSRB::ADTS0,
        ExternalIRQ0     = SFR::ADCSRB::ADTS1,
        Timer0CompareA   = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS1,
        Timer0Overflow   = SFR::ADCSRB::ADTS2,
        Timer1CompareB   = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS2,
        Timer1Overflow   = SFR::ADCSRB::ADTS1 | SFR::ADCSRB::ADTS2,
        Timer1Capture    = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS1 | SFR::ADCSRB::ADTS2,
    };

    enum class Vref {
        Internal_1_1 = SFR::ADMUX::REFS1 | SFR::ADMUX::REFS0,
        AVCC         = SFR::ADMUX::REFS0,
        AREF         = 0,
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
        Temp    = SFR::ADMUX::MUX3,
        BandGap = SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3,
        GND     = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3,
    };

}

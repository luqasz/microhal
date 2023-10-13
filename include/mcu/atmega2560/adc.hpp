#pragma once

#include "sfr.hpp"
#include "../../types.hpp"

namespace adc {

    constexpr u8 PRESCALER_MASK = SFR::ADCSRA::ADPS0 | SFR::ADCSRA::ADPS1 | SFR::ADCSRA::ADPS2;
    constexpr u8 MUX_MASK = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3 | SFR::ADMUX::MUX4;
    constexpr u8 VREF_MASK = SFR::ADMUX::REFS0 | SFR::ADMUX::REFS1;
    constexpr u8 TRIGGER_MASK = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS1 | SFR::ADCSRB::ADTS2;
    constexpr u16 TRIGGER_REG = SFR::ADCSRB::address;
    constexpr u8 MUX5 = SFR::ADCSRB::MUX5;
    constexpr u16 MUX5_REG = SFR::ADCSRB::address;

    enum class Trigger {
        FreeRunning = 0,
        AnalogComparator = SFR::ADCSRB::ADTS0,
        ExternalIRQ0 = SFR::ADCSRB::ADTS1,
        Timer0CompareA = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS1,
        Timer0Overflow = SFR::ADCSRB::ADTS2,
        Timer1CompareB = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS2,
        Timer1Overflow = SFR::ADCSRB::ADTS1 | SFR::ADCSRB::ADTS2,
        Timer1Capture = SFR::ADCSRB::ADTS0 | SFR::ADCSRB::ADTS1 | SFR::ADCSRB::ADTS2,
    };

    enum class Vref {
        Internal_2_56 = SFR::ADMUX::REFS0 | SFR::ADMUX::REFS1,
        Internal_1_1 = SFR::ADMUX::REFS1,
        AVCC = SFR::ADMUX::REFS0,
        AREF = 0,
    };

    enum class Channel {
        ADC0 = 0,
        ADC1 = SFR::ADMUX::MUX0,
        ADC2 = SFR::ADMUX::MUX1,
        ADC3 = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1,
        ADC4 = SFR::ADMUX::MUX2,
        ADC5 = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX2,
        ADC6 = SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2,
        ADC7 = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2,
        BandGap = SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3 | SFR::ADMUX::MUX4,
        GND = SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3 | SFR::ADMUX::MUX4,
        Internal_1_1 = SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX3 | SFR::ADMUX::MUX4,
        ADC8 = MUX5,
        ADC9 = MUX5 | SFR::ADMUX::MUX0,
        ADC10 = MUX5 | SFR::ADMUX::MUX1,
        ADC11 = MUX5 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX0,
        ADC12 = MUX5 | SFR::ADMUX::MUX2,
        ADC13 = MUX5 | SFR::ADMUX::MUX2 | SFR::ADMUX::MUX0,
        ADC14 = MUX5 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2,
        ADC15 = MUX5 | SFR::ADMUX::MUX0 | SFR::ADMUX::MUX1 | SFR::ADMUX::MUX2,
    };

}

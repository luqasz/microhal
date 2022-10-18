#pragma once

namespace adc {

    using ADCSRA_REG    = SFR::ADCSRA;
    using TRIGGER_REG   = SFR::SFIOR;
    using ADMUX_REG     = SFR::ADMUX;
    using VREF_REG      = SFR::ADMUX;
    using CTL_REG       = SFR::ADCSRA;
    using PRESCALER_REG = SFR::ADCSRA;

    enum Vref {
        Internal_2_56 = VREF_REG::REFS0 | VREF_REG::REFS1,
        AVCC          = VREF_REG::REFS0,
        AREF          = 0,
    };

    enum TriggerSource {
        FreeRunning                  = 0,
        AnalogComparator             = TRIGGER_REG::ADTS0,
        ExternalInterrupt0           = TRIGGER_REG::ADTS1,
        TimerCounter0_CompareMatch_A = TRIGGER_REG::ADTS0 | TRIGGER_REG::ADTS1,
        TimerCounter1_CompareMatch_B = TRIGGER_REG::ADTS0 | TRIGGER_REG::ADTS2,
        TimerCounter0_Overflow       = TRIGGER_REG::ADTS2,
        TimerCounter1_Overflow       = TRIGGER_REG::ADTS0 | TRIGGER_REG::ADTS2,
        TimerCounter1_CaptureEvent   = TRIGGER_REG::ADTS0 | TRIGGER_REG::ADTS1 | TRIGGER_REG::ADTS2,
    };

    enum Channel {
        ADC0    = 0,
        ADC1    = ADMUX_REG::MUX0,
        ADC2    = ADMUX_REG::MUX1,
        ADC3    = ADMUX_REG::MUX0 | ADMUX_REG::MUX1,
        ADC4    = ADMUX_REG::MUX2,
        ADC5    = ADMUX_REG::MUX0 | ADMUX_REG::MUX2,
        ADC6    = ADMUX_REG::MUX1 | ADMUX_REG::MUX2,
        ADC7    = ADMUX_REG::MUX0 | ADMUX_REG::MUX1 | ADMUX_REG::MUX2,
        BandGap = ADMUX_REG::MUX1 | ADMUX_REG::MUX2 | ADMUX_REG::MUX3 | ADMUX_REG::MUX4,
        GND     = ADMUX_REG::MUX0 | ADMUX_REG::MUX1 | ADMUX_REG::MUX2 | ADMUX_REG::MUX3 | ADMUX_REG::MUX4,
    };

    enum Clock {
        _2   = PRESCALER_REG::ADPS0,
        _4   = PRESCALER_REG::ADPS1,
        _8   = PRESCALER_REG::ADPS0 | PRESCALER_REG::ADPS1,
        _16  = PRESCALER_REG::ADPS2,
        _32  = PRESCALER_REG::ADPS0 | PRESCALER_REG::ADPS2,
        _64  = PRESCALER_REG::ADPS1 | PRESCALER_REG::ADPS2,
        _128 = PRESCALER_REG::ADPS0 | PRESCALER_REG::ADPS1 | PRESCALER_REG::ADPS2,
    };
}
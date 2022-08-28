#pragma once

#include "../sfr.hpp"

namespace ADC {

    typedef SFR::ADCSRA ADCSRA_REG;
    typedef SFR::ADCSRB TRIGGER_REG;
    typedef SFR::ADMUX  ADMUX_REG;
    typedef SFR::ADMUX  VREF_REG;
    typedef SFR::ADCSRA CTL_REG;
    typedef SFR::ADCSRA PRESCALER_REG;

    constexpr uint8_t PRESCALER_MASK = ADCSRA_REG::ADPS0 | ADCSRA_REG::ADPS1 | ADCSRA_REG::ADPS2;
    constexpr uint8_t MUX_MASK       = ADMUX_REG::MUX0 | ADMUX_REG::MUX1 | ADMUX_REG::MUX2 | ADMUX_REG::MUX3;
    constexpr uint8_t VREF_MASK      = ADMUX_REG::REFS0 | ADMUX_REG::REFS1;
    constexpr uint8_t TRIGGER_MASK   = TRIGGER_REG::ADTS0 | TRIGGER_REG::ADTS1 | TRIGGER_REG::ADTS2;

    auto ControllRegister  = SFR::RegisterRW<CTL_REG, uint8_t>();
    auto TriggerRegister   = SFR::RegisterRW<TRIGGER_REG, uint8_t>();
    auto ChannelRegister   = SFR::RegisterRW<ADMUX_REG, uint8_t>();
    auto VrefRegister      = SFR::RegisterRW<VREF_REG, uint8_t>();
    auto PrescalerRegister = SFR::RegisterRW<PRESCALER_REG, uint8_t>();
    auto DataRegister      = SFR::RegisterRO<SFR::ADC, uint16_t>();

    enum Vref {
        Internal_1_1 = VREF_REG::REFS1 | VREF_REG::REFS0,
        AVCC         = VREF_REG::REFS0,
        AREF         = 0,
    };

    enum TriggerSource {
        FreeRunning                  = 0,
        AnalogComparator             = TRIGGER_REG::ADTS0,
        ExternalInterrupt0           = TRIGGER_REG::ADTS1,
        TimerCounter0_CompareMatch_A = TRIGGER_REG::ADTS0 | TRIGGER_REG::ADTS1,
        TimerCounter0_Overflow       = TRIGGER_REG::ADTS2,
        TimerCounter1_CompareMatch_B = TRIGGER_REG::ADTS0 | TRIGGER_REG::ADTS2,
        TimerCounter1_Overflow       = TRIGGER_REG::ADTS1 | TRIGGER_REG::ADTS2,
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
        Temp    = ADMUX_REG::MUX3,
        BandGap = ADMUX_REG::MUX1 | ADMUX_REG::MUX2 | ADMUX_REG::MUX3,
        GND     = ADMUX_REG::MUX0 | ADMUX_REG::MUX1 | ADMUX_REG::MUX2 | ADMUX_REG::MUX3,
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

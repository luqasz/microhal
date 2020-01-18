#pragma once

#include "../sfr.h"

namespace ADC {
    typedef SFR::ADCSRA ADCSRA_REG;
    typedef SFR::ADCSRB TRIGGER_REG;
    typedef SFR::ADMUX  ADMUX_REG;
    typedef SFR::ADMUX  VREF_REG;
    typedef SFR::ADCSRA CTL_REG;
    typedef SFR::ADCSRA PRESCALER_REG;

    const uint8_t PRESCALER_BITS = (ADCSRA_REG::ADPS0 | ADCSRA_REG::ADPS1 | ADCSRA_REG::ADPS2);
    const uint8_t MUX_BITS       = (ADMUX_REG::MUX0 | ADMUX_REG::MUX1 | ADMUX_REG::MUX2 | ADMUX_REG::MUX3 | ADMUX_REG::MUX4);
    const uint8_t VREF_BITS      = (ADMUX_REG::REFS0 | ADMUX_REG::REFS1);
    const uint8_t TRIGGER_BITS   = (TRIGGER_REG::ADTS0 | TRIGGER_REG::ADTS1 | TRIGGER_REG::ADTS2);

    auto ControllRegister  = SFR::BitRegisterRW<CTL_REG, uint8_t>();
    auto TriggerRegister   = SFR::BitRegisterRW<TRIGGER_REG, uint8_t>();
    auto ChannelRegister   = SFR::BitRegisterRW<ADMUX_REG, uint8_t>();
    auto VrefRegister      = SFR::BitRegisterRW<VREF_REG, uint8_t>();
    auto PrescalerRegister = SFR::BitRegisterRW<PRESCALER_REG, uint8_t>();
    auto DataRegister      = SFR::DataRegisterRO<SFR::ADC, uint16_t>();

    enum Vref {
        Internal_2_56 = VREF_REG::REFS0 | VREF_REG::REFS1,
        Internal_1_1  = VREF_REG::REFS1,
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
        ADC0 = 0,
        ADC1 = ADMUX_REG::MUX0,
        ADC2 = ADMUX_REG::MUX1,
        ADC3 = ADMUX_REG::MUX0 | ADMUX_REG::MUX1,
        ADC4 = ADMUX_REG::MUX2,
        ADC5 = ADMUX_REG::MUX0 | ADMUX_REG::MUX2,
        ADC6 = ADMUX_REG::MUX1 | ADMUX_REG::MUX2,
        ADC7 = ADMUX_REG::MUX0 | ADMUX_REG::MUX1 | ADMUX_REG::MUX2,
    };

    enum Prescaler {
        DIV_2   = PRESCALER_REG::ADPS0,
        DIV_4   = PRESCALER_REG::ADPS1,
        DIV_8   = PRESCALER_REG::ADPS0 | PRESCALER_REG::ADPS1,
        DIV_16  = PRESCALER_REG::ADPS2,
        DIV_32  = PRESCALER_REG::ADPS0 | PRESCALER_REG::ADPS2,
        DIV_64  = PRESCALER_REG::ADPS1 | PRESCALER_REG::ADPS2,
        DIV_128 = PRESCALER_REG::ADPS0 | PRESCALER_REG::ADPS1 | PRESCALER_REG::ADPS2,
    };

}

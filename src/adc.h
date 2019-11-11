#ifndef adc_h
#define adc_h

#include "sfr.h"

#include <mcu_adc.h>
#include <stdint.h>

namespace ADC {

    enum class Channel {
        ADC0 = 0,
        ADC1 = ADC::ADMUX_REG::MUX0,
        ADC2 = ADC::ADMUX_REG::MUX1,
        ADC3 = ADC::ADMUX_REG::MUX0 | ADC::ADMUX_REG::MUX1,
        ADC4 = ADC::ADMUX_REG::MUX2,
        ADC5 = ADC::ADMUX_REG::MUX0 | ADC::ADMUX_REG::MUX2,
        ADC6 = ADC::ADMUX_REG::MUX1 | ADC::ADMUX_REG::MUX2,
        ADC7 = ADC::ADMUX_REG::MUX0 | ADC::ADMUX_REG::MUX1 | ADC::ADMUX_REG::MUX2,
    };

    enum class Vref {
        Internal = ADC::VREF_REG::REFS0 | ADC::VREF_REG::REFS1,
        AVCC     = ADC::VREF_REG::REFS0,
        AREF     = 0,
    };

    enum class Prescaler {
        DIV_2   = ADC::PRESCALER_REG::ADPS0,
        DIV_4   = ADC::PRESCALER_REG::ADPS1,
        DIV_8   = ADC::PRESCALER_REG::ADPS0 | ADC::PRESCALER_REG::ADPS1,
        DIV_16  = ADC::PRESCALER_REG::ADPS2,
        DIV_32  = ADC::PRESCALER_REG::ADPS0 | ADC::PRESCALER_REG::ADPS2,
        DIV_64  = ADC::PRESCALER_REG::ADPS1 | ADC::PRESCALER_REG::ADPS2,
        DIV_128 = ADC::PRESCALER_REG::ADPS0 | ADC::PRESCALER_REG::ADPS1 | ADC::PRESCALER_REG::ADPS2,
    };

    enum class TriggerSource {
        FreeRunning                  = 0,
        AnalogComparator             = ADC::TRIGGER_REG::ADTS0,
        ExternalInterrupt0           = ADC::TRIGGER_REG::ADTS1,
        TimerCounter0_CompareMatch_A = ADC::TRIGGER_REG::ADTS0 | ADC::TRIGGER_REG::ADTS1,
        TimerCounter0_Overflow       = ADC::TRIGGER_REG::ADTS2,
        TimerCounter1_CompareMatch_B = ADC::TRIGGER_REG::ADTS0 | ADC::TRIGGER_REG::ADTS2,
        TimerCounter1_Overflow       = ADC::TRIGGER_REG::ADTS0 | ADC::TRIGGER_REG::ADTS2,
        TimerCounter1_CaptureEvent   = ADC::TRIGGER_REG::ADTS0 | ADC::TRIGGER_REG::ADTS1 | ADC::TRIGGER_REG::ADTS2,
    };

    uint16_t read();
    void     start();
    void     enable();
    void     disable();
    void     set(Prescaler);
    void     set(Channel);
    void     set(Vref);
    void     set(TriggerSource);
}

#endif

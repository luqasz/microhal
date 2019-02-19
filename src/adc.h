#ifndef adc_h
#define adc_h

#include "sfr.h"

#include <stdint.h>

namespace ADC {
#if defined(__AVR_ATmega328P__)
#    include "adc/atmega328_adc.h"
#elif defined(__AVR_ATmega328__)
#    include "adc/atmega328_adc.h"
#elif defined(__AVR_ATmega32__)
#    include "adc/atmega32_adc.h"
#elif defined(__AVR_ATmega32A__)
#    include "adc/atmega32_adc.h"
#else
#    error "MCU does not have ADC or is not yet supported."
#endif
}

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

}

class Adc {
public:
    uint16_t read();
    void     start(void);
    void     enable(void);
    void     disable(void);
    void     set(enum ADC::Prescaler);
    void     set(enum ADC::Channel);
    void     set(enum ADC::Vref);
    void     set(enum ADC::TriggerSource);
};

#endif

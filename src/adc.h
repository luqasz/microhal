#ifndef ADC_H_
#define ADC_H_

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>

enum ADC_CHANNEL {
    ADC0 = ((0 << MUX0) | (0 << MUX1) | (0 << MUX2) | (0 << MUX3) | (0 << MUX4)),
    ADC1 = ((1 << MUX0) | (0 << MUX1) | (0 << MUX2) | (0 << MUX3) | (0 << MUX4)),
    ADC2 = ((0 << MUX0) | (1 << MUX1) | (0 << MUX2) | (0 << MUX3) | (0 << MUX4)),
    ADC3 = ((1 << MUX0) | (1 << MUX1) | (0 << MUX2) | (0 << MUX3) | (0 << MUX4)),
    ADC4 = ((0 << MUX0) | (0 << MUX1) | (1 << MUX2) | (0 << MUX3) | (0 << MUX4)),
    ADC5 = ((1 << MUX0) | (0 << MUX1) | (1 << MUX2) | (0 << MUX3) | (0 << MUX4)),
    ADC6 = ((0 << MUX0) | (1 << MUX1) | (1 << MUX2) | (0 << MUX3) | (0 << MUX4)),
    ADC7 = ((1 << MUX0) | (1 << MUX1) | (1 << MUX2) | (0 << MUX3) | (0 << MUX4)),
};

enum ADC_VREF {
    INTERNAL = ((1 << REFS0) | (1 << REFS1)),
    AVCC     = ((1 << REFS0) | (0 << REFS1)),
    AREF     = ((0 << REFS0) | (0 << REFS1)),
};

enum ADC_PRESCALER_DIVISOR {
    DIV_2   = ((1 << ADPS0) | (0 << ADPS1) | (0 << ADPS2)),
    DIV_4   = ((0 << ADPS0) | (1 << ADPS1) | (0 << ADPS2)),
    DIV_8   = ((1 << ADPS0) | (1 << ADPS1) | (0 << ADPS2)),
    DIV_16  = ((0 << ADPS0) | (0 << ADPS1) | (1 << ADPS2)),
    DIV_32  = ((1 << ADPS0) | (0 << ADPS1) | (1 << ADPS2)),
    DIV_64  = ((0 << ADPS0) | (1 << ADPS1) | (1 << ADPS2)),
    DIV_128 = ((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2)),
};

static const uint8_t ADC_PRESCALER_MASK      = (uint8_t) ~((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
static const uint8_t ADC_MUX_MASK            = (uint8_t) ~((1 << MUX0) | (1 << MUX1) | (1 << MUX2) | (1 << MUX3) | (1 << MUX4) | (1 << MUX4));
static const uint8_t ADC_VREF_MASK           = (uint8_t) ~((1 << REFS0) | (1 << REFS1));
static const uint8_t ADC_TRIGGER_SOURCE_MASK = (uint8_t) ~((1 << ADTS0) | (1 << ADTS1) | (1 << ADTS2));

enum ADC_TRIGGER_SOURCE {
    FREE_RUNNING                    = ((0 << ADTS0) | (0 << ADTS1) | (0 << ADTS2)),
    ANALOG_COMPARATOR               = ((1 << ADTS0) | (0 << ADTS1) | (0 << ADTS2)),
    EXTERNAL_INTERRUPT_0            = ((0 << ADTS0) | (1 << ADTS1) | (0 << ADTS2)),
    TIMER_COUNTER_0_COMPARE_MATCH_A = ((1 << ADTS0) | (1 << ADTS1) | (0 << ADTS2)),
    TIMER_COUNTER_0_OVERFLOW        = ((0 << ADTS0) | (0 << ADTS1) | (1 << ADTS2)),
    TIMER_COUNTER_1_COMPARE_MATCH_B = ((1 << ADTS0) | (0 << ADTS1) | (1 << ADTS2)),
    TIMER_COUNTER_1_OVERFLOW        = ((1 << ADTS0) | (1 << ADTS1) | (0 << ADTS2)),
    TIMER_COUNTER_1_CAPTURE_EVENT   = ((1 << ADTS0) | (2 << ADTS1) | (1 << ADTS2)),
};

void set_adc_trigger_source(enum ADC_TRIGGER_SOURCE);
void set_adc_prescaler(enum ADC_PRESCALER_DIVISOR);
void set_adc_channel(enum ADC_CHANNEL);
void set_adc_vref(enum ADC_VREF);
void adc_start(void);
uint16_t get_adc_value(void);

#endif
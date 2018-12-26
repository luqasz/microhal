#include "adc.h"

#include "registers.h"

#include <avr/interrupt.h>
#include <stdint.h>

static volatile uint16_t adc_value           = 0;
static const uint8_t ADC_PRESCALER_MASK      = (uint8_t) ~((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
static const uint8_t ADC_MUX_MASK            = (uint8_t) ~((1 << MUX0) | (1 << MUX1) | (1 << MUX2) | (1 << MUX3) | (1 << MUX4) | (1 << MUX4));
static const uint8_t ADC_VREF_MASK           = (uint8_t) ~((1 << REFS0) | (1 << REFS1));
static const uint8_t ADC_TRIGGER_SOURCE_MASK = (uint8_t) ~((1 << ADTS0) | (1 << ADTS1) | (1 << ADTS2));

uint16_t
Adc::value(void)
{
    return adc_value;
}

void
Adc::start(void)
{
    ADCSRA |= _BV(ADIE); // Enable interrupt
    ADCSRA |= _BV(ADEN); // Enable ADC
    ADCSRA |= _BV(ADSC); // Start conversion
}

void
Adc::stop(void)
{
    ADCSRA &= ~(1 << ADEN); // Disable ADC
}

void
Adc::prescaler(enum ADC_PRESCALER_DIVISOR prescaler)
{
    ADCSRA &= ADC_PRESCALER_MASK;
    ADCSRA |= prescaler;
}

void
Adc::channel(enum ADC_CHANNEL channel)
{
    ADMUX &= ADC_MUX_MASK;
    ADMUX |= channel;
}

void
Adc::vref(enum ADC_VREF vref)
{
    ADMUX &= ADC_VREF_MASK;
    ADMUX |= vref;
}

void
Adc::trigger(enum ADC_TRIGGER_SOURCE source)
{
    ADC_TRIGGER_SOURCE_REGISTER &= ADC_TRIGGER_SOURCE_MASK;
    ADC_TRIGGER_SOURCE_REGISTER |= source;
}

ISR(ADC_vect)
{
    /* IMPORTANT !!!!
    When reading ADCL, ADCH ADCL must be read first, then ADCH.
    Otherwise, ADC behavior is undefined.

    adc_value = (uint16_t)ADCL;
    adc_value |= (uint16_t)(ADCH << 8);

    Simplest way is to read ADCW directly.
    */
    adc_value = ADCW;
}
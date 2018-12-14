#include "adc.h"

#include "registers.h"

#include <avr/interrupt.h>
#include <stdint.h>

static volatile uint16_t adc_value = 0;

void
adc_start(void)
{
    ADCSRA |= _BV(ADIE); // Enable interrupt
    ADCSRA |= _BV(ADEN); // Enable ADC
    ADCSRA |= _BV(ADSC); // Start conversion
}

void
set_adc_prescaler(enum ADC_PRESCALER_DIVISOR prescaler)
{
    ADCSRA &= ADC_PRESCALER_MASK;
    ADCSRA |= prescaler;
}

void
set_adc_channel(enum ADC_CHANNEL channel)
{
    ADMUX &= ADC_MUX_MASK;
    ADMUX |= channel;
}

void
set_adc_vref(enum ADC_VREF vref)
{
    ADMUX &= ADC_VREF_MASK;
    ADMUX |= vref;
}

uint16_t
get_adc_value(void)
{
    return adc_value;
}

void
set_adc_trigger_source(enum ADC_TRIGGER_SOURCE source)
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
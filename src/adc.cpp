#include "adc.h"

#include "irq.h"
#include "sfr.h"
#include "utils.h"

#include <stdint.h>

static volatile uint16_t adc_value = 0;

static const uint8_t PRESCALER_MASK = inverted<uint8_t>(ADC::ADCSRA_REG::ADPS0 | ADC::ADCSRA_REG::ADPS1 | ADC::ADCSRA_REG::ADPS2);
static const uint8_t MUX_MASK       = inverted<uint8_t>(ADC::ADMUX_REG::MUX0 | ADC::ADMUX_REG::MUX1 | ADC::ADMUX_REG::MUX2 | ADC::ADMUX_REG::MUX3 | ADC::ADMUX_REG::MUX4);
static const uint8_t VREF_MASK      = inverted<uint8_t>(ADC::ADMUX_REG::REFS0 | ADC::ADMUX_REG::REFS1);
static const uint8_t TRIGGER_MASK   = inverted<uint8_t>(ADC::TRIGGER_REG::ADTS0 | ADC::TRIGGER_REG::ADTS1 | ADC::TRIGGER_REG::ADTS2);

auto CTL_REG       = Register<ADC::CTL_REG>();
auto TRIGGER_REG   = Register<ADC::TRIGGER_REG>();
auto ADMUX_REG     = Register<ADC::ADMUX_REG>();
auto VREF_REG      = Register<ADC::VREF_REG>();
auto PRESCALER_REG = Register<ADC::PRESCALER_REG>();

template <typename VALUE_T, typename REG_T>
void
set_reg(VALUE_T value, REG_T reg, uint8_t mask)
{
    uint8_t reg_value = reg;
    reg_value &= mask;
    reg_value |= static_cast<uint8_t>(value);
    reg = reg_value;
}

uint16_t
Adc::read(void)
{
    return adc_value;
}

void
Adc::start(void)
{
    enable();
    CTL_REG.setBit(CTL_REG.ADSC); // Start conversion
}

void
Adc::enable(void)
{
    CTL_REG.setBit(CTL_REG.ADEN); // Enable ADC
    CTL_REG.setBit(CTL_REG.ADIE); // Enable interrupt
}

void
Adc::disable(void)
{
    CTL_REG.clearBit(CTL_REG.ADEN); // Disable ADC
}

void
Adc::set(enum ADC::Prescaler value)
{
    set_reg(value, PRESCALER_REG, PRESCALER_MASK);
}

void
Adc::set(enum ADC::Channel chan)
{
    set_reg(chan, ADMUX_REG, MUX_MASK);
}

void
Adc::set(enum ADC::Vref reference)
{
    set_reg(reference, VREF_REG, VREF_MASK);
}

void
Adc::set(enum ADC::TriggerSource source)
{
    CTL_REG.setBit(CTL_REG.ADATE); // Enable auto trigger
    set_reg(source, TRIGGER_REG, TRIGGER_MASK);
}

void
Irq::ADC(void)
{
    /*
    When reading directly as uint16_t, ADCL must be read first, then ADCH.
    Otherwise, ADC behavior is undefined.
    */
    adc_value = Register<SFR::ADC, uint16_t>();
}
#include "adc.h"

#include "irq.h"
#include "sfr.h"
#include "utils.h"

#include <stdint.h>

static volatile uint16_t adc_value = 0;

namespace ADC {

    static const uint8_t PRESCALER_MASK = inverted<uint8_t>(ADCSRA_REG::ADPS0 | ADCSRA_REG::ADPS1 | ADCSRA_REG::ADPS2);
    static const uint8_t MUX_MASK       = inverted<uint8_t>(ADMUX_REG::MUX0 | ADMUX_REG::MUX1 | ADMUX_REG::MUX2 | ADMUX_REG::MUX3 | ADMUX_REG::MUX4);
    static const uint8_t VREF_MASK      = inverted<uint8_t>(ADMUX_REG::REFS0 | ADMUX_REG::REFS1);
    static const uint8_t TRIGGER_MASK   = inverted<uint8_t>(TRIGGER_REG::ADTS0 | TRIGGER_REG::ADTS1 | TRIGGER_REG::ADTS2);

    auto ControllRegister  = Register<CTL_REG>();
    auto TriggerRegister   = Register<TRIGGER_REG>();
    auto ChannelRegister   = Register<ADMUX_REG>();
    auto VrefRegister      = Register<VREF_REG>();
    auto PrescalerRegister = Register<PRESCALER_REG>();

    template <typename VALUE_T, typename REG_T>
    constexpr void
    set_reg(VALUE_T value, REG_T reg, uint8_t mask)
    {
        uint8_t reg_value = reg;
        reg_value &= mask;
        reg_value |= static_cast<uint8_t>(value);
        reg = reg_value;
    }

    uint16_t
    read()
    {
        return adc_value;
    }

    void
    start()
    {
        enable();
        ControllRegister.setBit(ControllRegister.ADSC); // Start conversion
    }

    void
    enable()
    {
        ControllRegister.setBit(ControllRegister.ADEN); // Enable ADC
        ControllRegister.setBit(ControllRegister.ADIE); // Enable interrupt
    }

    void
    disable()
    {
        ControllRegister.clearBit(ControllRegister.ADEN); // Disable ADC
    }

    void
    set(Prescaler value)
    {
        set_reg(value, PrescalerRegister, PRESCALER_MASK);
    }

    void
    set(Channel chan)
    {
        set_reg(chan, ChannelRegister, MUX_MASK);
    }

    void
    set(Vref reference)
    {
        set_reg(reference, VrefRegister, VREF_MASK);
    }

    void
    set(TriggerSource source)
    {
        ControllRegister.setBit(ControllRegister.ADATE); // Enable auto trigger
        set_reg(source, TriggerRegister, TRIGGER_MASK);
    }

}

void
Irq::ADC(void)
{
    adc_value = SFR::DataRegisterRO<SFR::ADC, uint16_t>().read();
}

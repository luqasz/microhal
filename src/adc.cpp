#include <adc.hpp>

namespace ADC {

    auto ControllRegister  = SFR::RegisterRW<CTL_REG, u8>();
    auto TriggerRegister   = SFR::RegisterRW<TRIGGER_REG, u8>();
    auto ChannelRegister   = SFR::RegisterRW<ADMUX_REG, u8>();
    auto VrefRegister      = SFR::RegisterRW<VREF_REG, u8>();
    auto PrescalerRegister = SFR::RegisterRW<PRESCALER_REG, u8>();
    auto DataRegister      = SFR::RegisterRO<SFR::ADC, u16>();

    constexpr u8 PRESCALER_MASK = ADCSRA_REG::ADPS0 | ADCSRA_REG::ADPS1 | ADCSRA_REG::ADPS2;
    constexpr u8 MUX_MASK       = ADMUX_REG::MUX0 | ADMUX_REG::MUX1 | ADMUX_REG::MUX2 | ADMUX_REG::MUX3 | ADMUX_REG::MUX4;
    constexpr u8 VREF_MASK      = ADMUX_REG::REFS0 | ADMUX_REG::REFS1;
    constexpr u8 TRIGGER_MASK   = TRIGGER_REG::ADTS0 | TRIGGER_REG::ADTS1 | TRIGGER_REG::ADTS2;

    void
    enable()
    {
        ControllRegister.setBit(ControllRegister.ADEN);
    }

    void
    disable()
    {
        ControllRegister.clearBit(ControllRegister.ADEN);
    }

    u16
    read(const Channel ch)
    {
        enable();
        ChannelRegister.setBit(ch, MUX_MASK);
        ControllRegister.setBit(ControllRegister.ADSC);            // Start conversion
        ControllRegister.waitForClearedBit(ControllRegister.ADSC); // Wait untill conversion is ready
        return DataRegister.read();
    }

    void
    set(const Clock value)
    {
        PrescalerRegister.setBit(value, PRESCALER_MASK);
    }

    void
    set(const Vref ref)
    {
        VrefRegister.setBit(ref, VREF_MASK);
    }

    void
    set(const TriggerSource src)
    {
        ControllRegister.setBit(ControllRegister.ADIE | ControllRegister.ADIE | ControllRegister.ADSC);
        TriggerRegister.setBit(src, TRIGGER_MASK);
    }

}

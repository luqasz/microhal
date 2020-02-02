#pragma once

#include <mcu_adc.h>
#include <stdint.h>

namespace ADC {

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

    uint16_t
    read(const Channel ch)
    {
        enable();
        ChannelRegister.setBit(ch, MUX_MASK);
        ControllRegister.setBit(ControllRegister.ADSC);         // Start conversion
        while (ControllRegister.isSet(ControllRegister.ADSC)) { // Wait untill conversion is ready
        }
        return DataRegister.read();
    }

    void
    set(const Prescaler value)
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
        ControllRegister.setBit(ControllRegister.ADIE);  // Enable interrupt
        ControllRegister.setBit(ControllRegister.ADATE); // Enable auto trigger
        ControllRegister.setBit(ControllRegister.ADSC);  // Start conversion
        TriggerRegister.setBit(src, TRIGGER_MASK);
    }

}


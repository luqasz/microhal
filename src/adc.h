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
        ChannelRegister.clearBit(MUX_BITS);
        ChannelRegister.setBit(ch);
        ControllRegister.setBit(ControllRegister.ADSC);         // Start conversion
        while (ControllRegister.isSet(ControllRegister.ADSC)) { // Wait untill conversion is ready
        }
        return DataRegister.read();
    }

    void
    set(const Prescaler value)
    {
        PrescalerRegister.clearBit(PRESCALER_BITS);
        PrescalerRegister.setBit(value);
    }

    void
    set(const Vref ref)
    {
        VrefRegister.clearBit(VREF_BITS);
        VrefRegister.setBit(ref);
    }

    void
    set(const TriggerSource src)
    {
        ControllRegister.setBit(ControllRegister.ADIE);  // Enable interrupt
        ControllRegister.setBit(ControllRegister.ADATE); // Enable auto trigger
        ControllRegister.setBit(ControllRegister.ADSC);  // Start conversion
        TriggerRegister.clearBit(TRIGGER_BITS);
        TriggerRegister.setBit(src);
    }

}

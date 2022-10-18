#pragma once

#include "types.hpp"
#include "sfr.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/adc.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/adc.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/adc.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

namespace adc {

    void
    enable();

    void
    disable();

    u16
    read(const Channel ch);

    void
    set(const Clock value);

    void
    set(const Vref ref);

    void
    set(const TriggerSource src);

}

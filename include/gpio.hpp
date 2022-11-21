#pragma once

#include "sfr.hpp"
#include "types.hpp"

namespace gpio {

    enum State {
        Low  = 0,
        High = 1,
    };

}

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/gpio.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/gpio.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/gpio.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif
#pragma once

#include "sfr.hpp"
#include "types.hpp"

namespace gpio {

    enum State {
        Low,
        High,
    };

}

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/avr_gpio_common.hpp"
#        include "mcu/atmega32/gpio.hpp"
#    elif MCU == atmega328
#        include "mcu/avr_gpio_common.hpp"
#        include "mcu/atmega328/gpio.hpp"
#    elif MCU == atmega2560
#        include "mcu/avr_gpio_common.hpp"
#        include "mcu/atmega2560/gpio.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif
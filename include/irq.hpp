#pragma once

#include "sfr.hpp"
#include "types.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/irq.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/irq.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/irq.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

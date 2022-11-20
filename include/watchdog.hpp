#pragma once

#include "sfr.hpp"
#include "types.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/watchdog.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/watchdog.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/watchdog.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

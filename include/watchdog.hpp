#pragma once

#include "sfr.hpp"
#include "types.hpp"

#if MCU_ATMEGA32
#    include "mcu/atmega32/watchdog.hpp"
#elif MCU_ATMEGA328
#    include "mcu/atmega328/watchdog.hpp"
#elif MCU_ATMEGA2560
#    include "mcu/atmega2560/watchdog.hpp"
#else
#    error "Unknown MCU."
#endif

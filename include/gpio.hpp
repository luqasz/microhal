#pragma once

#include "sfr.hpp"
#include "types.hpp"

#if MCU_ATMEGA32
#    include "mcu/atmega32/gpio.hpp"
#elif MCU_ATMEGA328
#    include "mcu/atmega328/gpio.hpp"
#elif MCU_ATMEGA2560
#    include "mcu/atmega2560/gpio.hpp"
#else
#    error "Unknown MCU."
#endif

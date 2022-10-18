#pragma once

#include "sfr.hpp"
#include "types.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/eeprom.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/eeprom.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/eeprom.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

namespace eeprom {

    void
    write(const u8 byte, const u16 address);

    u8
    read(const u16 address);

}

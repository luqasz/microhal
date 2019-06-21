#ifndef eeprom_h
#define eeprom_h

#include MCU_EEPROM_HEADER
#include <stdint.h>

namespace EEPROM {

    void
    write(const uint8_t, const uint16_t);

    uint8_t
    read(const uint16_t);

}

#endif
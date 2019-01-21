#ifndef eeprom_h
#define eeprom_h

#include <stdint.h>

namespace EEPROM {

    void
    write(const uint8_t, const uint16_t);

    uint8_t
    read(const uint16_t);

}

#endif
#ifndef atmega649p_eeprom_h
#define atmega649p_eeprom_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega649P
*/

namespace EEPROM {

    constexpr uint16_t start     = 0x00;
    constexpr uint16_t end       = 0x7ff;
    constexpr uint16_t size      = 0x800;
    constexpr uint8_t  page_size = 0x08;

}

#endif
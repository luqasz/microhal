#ifndef atmega8a_eeprom_h
#define atmega8a_eeprom_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega8A
*/

namespace EEPROM {

    constexpr uint16_t start     = 0x00;
    constexpr uint16_t end       = 0x1ff;
    constexpr uint16_t size      = 0x200;
    constexpr uint8_t  page_size = 0x04;

}

#endif
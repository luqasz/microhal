#ifndef at90can32_eeprom_h
#define at90can32_eeprom_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       AT90CAN32
*/

namespace EEPROM {

    constexpr uint16_t start     = 0x00;
    constexpr uint16_t end       = 0x3ff;
    constexpr uint16_t size      = 0x400;
    constexpr uint8_t  page_size = 0x08;

}

#endif
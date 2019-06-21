#ifndef at90usb1287_eeprom_h
#define at90usb1287_eeprom_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       AT90USB1287
*/

namespace EEPROM {

    constexpr uint16_t start     = 0x00;
    constexpr uint16_t end       = 0xfff;
    constexpr uint16_t size      = 0x1000;
    constexpr uint8_t  page_size = 0x08;

}

#endif
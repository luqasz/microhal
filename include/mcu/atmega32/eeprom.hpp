#pragma once

#include "../../sfr.hpp"
#include "../../types.hpp"

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega32
*/

namespace eeprom {

    constexpr uint16_t start     = 0x00;
    constexpr uint16_t end       = 0x3ff;
    constexpr uint16_t size      = 0x400;
    constexpr uint8_t  page_size = 0x04;

    constexpr u8 RE  = SFR::EECR::EERE;
    constexpr u8 WE  = SFR::EECR::EEWE;
    constexpr u8 MWE = SFR::EECR::EEMWE;
    constexpr u8 RIE = SFR::EECR::EERIE;

}
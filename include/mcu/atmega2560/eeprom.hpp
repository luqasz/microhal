#pragma once

#include "sfr.hpp"
#include "../../types.hpp"

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega32
*/

namespace eeprom {

    constexpr u16 START = 0x00;
    constexpr u16 END = 0xfff;
    constexpr u16 SIZE = 0x1000;
    constexpr u8 PAGE_SIZE = 0x04;

    using REG_CTRL = SFR::EECR;
    using REG_ADDR = SFR::EEAR;
    using REG_DATA = SFR::EEDR;

    constexpr u8 RE = REG_CTRL::EERE;
    constexpr u8 WE = REG_CTRL::EEPE;
    constexpr u8 MWE = REG_CTRL::EEMPE;
    constexpr u8 IE = REG_CTRL::EERIE;
    constexpr u8 OP_ATOMIC = REG_CTRL::EEPM0 | REG_CTRL::EEPM1;
    constexpr u8 OP_ERASE = REG_CTRL::EEPM0;
    constexpr u8 OP_WRITE = REG_CTRL::EEPM1;

}
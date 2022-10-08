#pragma once

#include "sfr.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "atmega32/mcu_eeprom.hpp"
#    elif MCU == atmega328
#        include "atmega328/mcu_eeprom.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

#include <stdint.h>

namespace EEPROM {

    auto ControllRegister = SFR::RegisterRW<SFR::EECR, uint8_t>();
    auto AddressRegister  = SFR::RegisterRW<SFR::EEAR, uint16_t>();
    auto DataRegister     = SFR::RegisterRW<SFR::EEDR, uint8_t>();

    void
    write(const uint8_t byte, const uint16_t address)
    {
        ControllRegister.waitForClearedBit(ControllRegister.EEWE); // Wait untill ready.
        AddressRegister = address;
        DataRegister    = byte;
        ControllRegister.setBit(ControllRegister.EEMWE);
        ControllRegister.setBit(ControllRegister.EEWE);
    }

    uint8_t
    read(const uint16_t address)
    {
        ControllRegister.waitForClearedBit(ControllRegister.EEWE); // Wait untill ready.
        AddressRegister = address;
        ControllRegister.setBit(ControllRegister.EERE);
        return DataRegister.read();
    }

}

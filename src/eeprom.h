#pragma once

#include "sfr.h"

#include <mcu_eeprom.h>
#include <stdint.h>

namespace EEPROM {

    auto ControllRegister = SFR::RegisterRW<SFR::EECR, uint8_t>();
    auto AddressRegister  = SFR::RegisterRW<SFR::EEAR, uint16_t>();
    auto DataRegister     = SFR::RegisterRW<SFR::EEDR, uint8_t>();

    /*
    Return if EEPROM is still pending read/write operation.
    */
    bool
    is_busy()
    {
        return ControllRegister.isSet(ControllRegister.EEWE);
    }

    void
    write(const uint8_t byte, const uint16_t address)
    {
        while (is_busy()) {
        }
        AddressRegister = address;
        DataRegister    = byte;
        ControllRegister.setBit(ControllRegister.EEMWE);
        ControllRegister.setBit(ControllRegister.EEWE);
    }

    uint8_t
    read(const uint16_t address)
    {
        while (is_busy()) {
        }
        AddressRegister = address;
        ControllRegister.setBit(ControllRegister.EERE);
        return DataRegister.read();
    }

}

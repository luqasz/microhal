#ifndef eeprom_h
#define eeprom_h

#include "sfr.h"

#include <mcu_eeprom.h>
#include <stdint.h>

namespace EEPROM {

    auto ControllRegister = Register<SFR::EECR>();
    auto AddressRegister  = Register<SFR::EEAR, uint16_t>();
    auto DataRegister     = Register<SFR::EEDR>();

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

#endif

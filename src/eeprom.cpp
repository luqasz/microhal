#include "eeprom.h"

#include "buffer.h"
#include "irq.h"
#include "sfr.h"

auto ControllRegister = Register<SFR::EECR>();
auto AddressRegister  = Register<SFR::EEAR, uint16_t>();
auto DataRegister     = Register<SFR::EEDR>();

bool
is_busy()
{
    /*
    Return if EEPROM is still pending operation.
    */
    return ControllRegister.isSet(ControllRegister.EEWE);
}

void
EEPROM::write(const uint8_t byte, const uint16_t address)
{
    while (is_busy()) {
    }
    AddressRegister = address;
    DataRegister    = byte;
    ControllRegister.setBit(ControllRegister.EEMWE);
    ControllRegister.setBit(ControllRegister.EEWE);
}

uint8_t
EEPROM::read(const uint16_t address)
{
    while (is_busy()) {
    }
    AddressRegister = address;
    ControllRegister.setBit(ControllRegister.EERE);
    return DataRegister.read();
}

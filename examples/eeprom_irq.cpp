#include "eeprom.h"

#include "buffer.h"
#include "irq.h"
#include "sfr.h"

volatile auto buffer = Buffer::CircularPowerOf2<8>();

auto ControllRegister = Register<SFR::EECR>();
auto AddressRegister  = Register<SFR::EEAR, uint16_t>();
auto DataRegister     = Register<SFR::EEDR>();

bool
isBufferEmpty()
{
    return buffer.size() == 0;
}

bool
isReady()
{
    /*
    If pending write is in progress, EEPROM Write enable bit.
    */
    return isBufferEmpty() && !(ControllRegister.EEWE & ControllRegister);
}

void
enable_irq()
{
    ControllRegister.setBit(ControllRegister.EERIE);
}

void
disable_irq()
{
    ControllRegister.clearBit(ControllRegister.EERIE);
}

void
EEPROM::write(const uint8_t byte, const uint16_t address)
{
    while (!isReady()) {
    }
    {
        Irq::atomicRestore();
        buffer.write(byte);
    }
    AddressRegister = address;
    enable_irq();
}

uint8_t
EEPROM::read(const uint16_t address)
{
    while (!isReady()) {
    }
    AddressRegister = address;
    ControllRegister.setBit(ControllRegister.EERE);
    return DataRegister;
}

void
Irq::EEPROM()
{
    DataRegister = buffer.read();
    /* Bits must be set in order. See datasheet for more information. */
    ControllRegister.setBit(ControllRegister.EEMWE); // Master write enable.
    ControllRegister.setBit(ControllRegister.EEWE);  // Strobe eeprom write.
    if (isBufferEmpty()) {
        disable_irq();
    }
}

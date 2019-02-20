#include "eeprom.h"

#include "buffer.h"
#include "irq.h"
#include "sfr.h"

const uint16_t END_ADDRESS  = 0x3FF;
const uint16_t STAR_ADDRESS = 0x00;
const uint8_t  PAGE_SIZE    = 4;

volatile auto buffer = Buffer::Circular<8>();

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
        buffer.put(byte);
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
    DataRegister = buffer.get();
    /* Bits must be set in order. See datasheet for more information. */
    ControllRegister.setBit(ControllRegister.EEMWE); // Master write enable.
    ControllRegister.setBit(ControllRegister.EEWE);  // Strobe eeprom write.
    if (isBufferEmpty()) {
        disable_irq();
    }
}
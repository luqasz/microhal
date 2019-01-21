#include "spi.h"

#include "sfr.h"

auto SPCR = Register<SFR::SPCR>();
auto SPSR = Register<SFR::SPSR>();
auto SPDR = Register<SFR::SPDR>();

SPI::Master::Master()
{
    /*
    Set MOSI SCK SS as outputs only.
    For more information why, see "SPI Pin Overrides" in datasheet.
    */
    SPI::SCK.output();
    SPI::MOSI.output();
    SPI::SS.output();
    SPCR.setBit(SPCR.MSTR);
    enable();
}

// In slave mode user must provide MISO with either output or output

void
SPI::Master::enable()
{
    SPCR.setBit(SPCR.SPE);
}

void
SPI::Master::disable()
{
    SPCR.clearBit(SPCR.SPE);
}

void
SPI::Master::set(const SPI::Master::Speed speed)
{
    switch (speed) {
        case SPI::Master::Speed::d2:
            SPSR.setBit(SPSR.SPI2X);
            SPCR.clearBit(SPCR.SPR0);
            SPCR.clearBit(SPCR.SPR1);
            break;
        case SPI::Master::Speed::d4:
            SPSR.clearBit(SPSR.SPI2X);
            SPCR.clearBit(SPCR.SPR0);
            SPCR.clearBit(SPCR.SPR1);
            break;
        case SPI::Master::Speed::d8:
            SPSR.setBit(SPSR.SPI2X);
            SPCR.setBit(SPCR.SPR0);
            SPCR.clearBit(SPCR.SPR1);
            break;
        case SPI::Master::Speed::d16:
            SPSR.clearBit(SPSR.SPI2X);
            SPCR.setBit(SPCR.SPR0);
            SPCR.clearBit(SPCR.SPR1);
            break;
        case SPI::Master::Speed::d32:
            SPSR.setBit(SPSR.SPI2X);
            SPCR.clearBit(SPCR.SPR0);
            SPCR.setBit(SPCR.SPR1);
            break;
        case SPI::Master::Speed::d64:
            SPSR.setBit(SPSR.SPI2X);
            SPCR.setBit(SPCR.SPR0);
            SPCR.setBit(SPCR.SPR1);
            break;
        case SPI::Master::Speed::d128:
            SPSR.clearBit(SPSR.SPI2X);
            SPCR.setBit(SPCR.SPR0);
            SPCR.setBit(SPCR.SPR1);
            break;
    }
}

void
SPI::Master::set(const SPI::DataOrder order)
{
    switch (order) {
        case SPI::DataOrder::LSB_First:
            SPCR.setBit(SPCR.DORD);
            break;
        case SPI::DataOrder::MSB_First:
            SPCR.clearBit(SPCR.DORD);
            break;
    }
}

void
SPI::Master::set(const SPI::Mode mode)
{
    switch (mode) {
        case SPI::Mode::m0:
            SPCR.clearBit(SPCR.CPHA);
            SPCR.clearBit(SPCR.CPOL);
            break;
        case SPI::Mode::m1:
            SPCR.clearBit(SPCR.CPOL);
            SPCR.setBit(SPCR.CPHA);
            break;
        case SPI::Mode::m2:
            SPCR.setBit(SPCR.CPOL);
            SPCR.clearBit(SPCR.CPHA);
            break;
        case SPI::Mode::m3:
            SPCR.setBit(SPCR.CPOL);
            SPCR.setBit(SPCR.CPHA);
            break;
    }
}

uint8_t
SPI::Master::communicate(const uint8_t byte)
{
    SPDR = byte;
    // Wait for transmission complete
    while (!(SPSR & SPSR.SPIF)) {
    }
    return SPDR;
}

uint16_t
SPI::Master::communicate(const uint16_t bytes)
{
    uint8_t b1 = static_cast<uint8_t>(bytes >> 8);
    uint8_t b2 = static_cast<uint8_t>(bytes);
    b1         = communicate(b1);
    b2         = communicate(b2);
    return static_cast<uint16_t>(b1 << 8) | b2;
}

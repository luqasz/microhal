#include "sfr.h"

#include <stdint.h>

template <typename UINT>
UINT volatile &
iomem_impl(UINT address)
{
    return *reinterpret_cast<UINT volatile *>(address);
}

template <typename UINT>
void
setBit_impl(UINT address, uint8_t bit)
{
    iomem_impl(address) |= bit;
}

template <typename UINT>
void
clearBit_impl(UINT address, uint8_t bit)
{
    iomem_impl(address) &= static_cast<uint8_t>(~bit);
}

uint8_t volatile &
SFR::iomem(uint8_t address)
{
    return iomem_impl(address);
}

uint16_t volatile &
SFR::iomem(uint16_t address)
{
    return iomem_impl(address);
}

void
SFR::setBit(uint8_t address, uint8_t bit)
{
    setBit_impl(address, bit);
}

void
SFR::setBit(uint16_t address, uint8_t bit)
{
    setBit_impl(address, bit);
}

void
SFR::clearBit(uint8_t address, uint8_t bit)
{
    clearBit_impl(address, bit);
}

void
SFR::clearBit(uint16_t address, uint8_t bit)
{
    clearBit_impl(address, bit);
}
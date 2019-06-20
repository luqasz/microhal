#ifndef bcd_h
#define bcd_h

#include <stdint.h>

constexpr uint8_t
dec_to_bcd(const uint8_t dec)
{
    return static_cast<uint8_t>(((dec / 10) << 4) | (dec % 10));
}

constexpr uint8_t
bcd_to_dec(const uint8_t bcd)
{
    return static_cast<uint8_t>((((bcd & 0xF0) >> 4) * 10) + (bcd & 0x0F));
}

#endif

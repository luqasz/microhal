#include <stdint.h>

uint8_t
dec_to_bcd(uint8_t dec)
{
    return static_cast<uint8_t>(((dec / 10) << 4) | (dec % 10));
}

uint8_t
bcd_to_dec(uint8_t bcd)
{
    return static_cast<uint8_t>((((bcd & 0xF0) >> 4) * 10) + (bcd & 0x0F));
}

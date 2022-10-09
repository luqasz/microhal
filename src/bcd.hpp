#pragma once
#include "types.hpp"

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

struct BCD {
    const u8 value;

    static constexpr BCD
    from_u8(const u8 & dec)
    {
        return BCD { static_cast<u8>(((dec / 10) << 4) | (dec % 10)) };
    }

    static constexpr u8
    into_u8(const BCD & bcd)
    {
        return static_cast<u8>((((bcd.value & 0xF0) >> 4) * 10) + (bcd.value & 0x0F));
    }

    constexpr bool
    operator==(const BCD & other) const
    {
        return value == other.value;
    }
};
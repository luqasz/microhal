#pragma once
#include "types.hpp"

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
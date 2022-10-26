#pragma once
#include "types.hpp"

namespace encoder {

    constexpr u8
    dec_to_bcd(const u8 & dec)
    {
        return static_cast<u8>(((dec / 10) << 4) | (dec % 10));
    }

    constexpr u8
    bcd_to_dec(const u8 & bcd)
    {
        return static_cast<u8>((((bcd & 0xF0) >> 4) * 10) + (bcd & 0x0F));
    }
}

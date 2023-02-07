#pragma once

#include <types.hpp>

namespace spi {

    // Dummy SPI2X bit. Doesn't point to any bit in order, clock, mode bits.
    constexpr u8 SPI2X = 0x80;
}

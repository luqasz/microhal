#pragma once

#include <stdint.h>
#include <stdlib.h>

using usize = size_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

template <typename T>
struct limits {
    static constexpr usize bits = 0;
    static constexpr usize max = 0;
    static constexpr usize min = 0;
};

template <>
struct limits<unsigned char> {
    static constexpr unsigned char bits = 8;
    static constexpr unsigned char max = 255;
    static constexpr unsigned char min = 0;
};

template <>
struct limits<unsigned short> {
    static constexpr unsigned short bits = 8 * (sizeof(unsigned short) / sizeof(u8));
    static constexpr unsigned short max = static_cast<unsigned short>(UINT64_MAX);
    static constexpr unsigned short min = 0;
};

template <>
struct limits<unsigned int> {
    static constexpr unsigned int bits = 8 * (sizeof(unsigned int) / sizeof(u8));
    static constexpr unsigned int max = static_cast<unsigned int>(UINT64_MAX);
    static constexpr unsigned int min = 0;
};

template <>
struct limits<unsigned long> {
    static constexpr unsigned long bits = 8 * (sizeof(unsigned long) / sizeof(u8));
    static constexpr unsigned long max = static_cast<unsigned long>(UINT64_MAX);
    static constexpr unsigned long min = 0;
};

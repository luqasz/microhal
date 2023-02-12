#pragma once

#include <stdint.h>
#include <stdlib.h>

using usize = size_t;
using u8    = uint8_t;
using u16   = uint16_t;
using u32   = uint32_t;
using u64   = uint64_t;

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

template <typename T>
struct limits;

template <>
struct limits<u8> {
    static constexpr u8 max = 255;
    static constexpr u8 min = 0;
};

template <>
struct limits<u16> {
    static constexpr u16 max = 65535;
    static constexpr u16 min = 0;
};

template <>
struct limits<u32> {
    static constexpr u32 max = 4294967295;
    static constexpr u32 min = 0;
};

template <>
struct limits<u64> {
    static constexpr u64 max = 18446744073709551615UL;
    static constexpr u64 min = 0;
};

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

template <typename T>
struct limits<const T> : public limits<T> {
};

template <>
struct limits<u8> {
    static constexpr usize max  = UINT8_MAX;
    static constexpr usize min  = 0;
    static constexpr usize bits = 8;
};

template <>
struct limits<u16> {
    static constexpr usize max  = UINT16_MAX;
    static constexpr usize min  = 0;
    static constexpr usize bits = 16;
};

template <>
struct limits<u32> {
    static constexpr usize max  = UINT32_MAX;
    static constexpr usize min  = 0;
    static constexpr usize bits = 32;
};

template <>
struct limits<u64> {
    static constexpr usize max  = UINT64_MAX;
    static constexpr usize min  = 0;
    static constexpr usize bits = 64;
};

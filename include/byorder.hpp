#pragma once

#include "defs.hpp"
#include "types.hpp"
#include "concepts.hpp"
#include "buffer.hpp"

enum class endian : usize {
    little  = __ORDER_LITTLE_ENDIAN__,
    big     = __ORDER_BIG_ENDIAN__,
    native  = __BYTE_ORDER__,
    network = __ORDER_BIG_ENDIAN__,
};

namespace byorder {

    constexpr u16 PUREFN
    swap(const u16 val)
    {
        return __builtin_bswap16(val);
    }

    constexpr u32 PUREFN
    swap(const u32 val)
    {
        return __builtin_bswap32(val);
    }

    constexpr u64 PUREFN
    swap(const u64 val)
    {
        return __builtin_bswap64(val);
    }

    template <endian INTO, Unsigned SRC>
    constexpr SRC PUREFN
    into(const SRC val)
    {
        if constexpr (endian::native == INTO) {
            return val;
        }
        else {
            return swap(val);
        }
    }

    template <endian INTO, Unsigned SRC>
    constexpr SRC PUREFN
    from(const SRC val)
    {
        if constexpr (endian::native == INTO) {
            return val;
        }
        else {
            return swap(val);
        }
    }

    template <endian INTO, Unsigned UINT>
    constexpr inline auto PUREFN
    into_bytes(UINT value)
    {
        if constexpr (INTO != endian::native) {
            value = swap(value);
        }
        buffer::Array<u8, limits<UINT>::bytes> bytes { 0 };
        switch (limits<UINT>::bytes) {
            case 8:
                bytes[7] = u8((value >> 56) & 0xFF);
                bytes[6] = u8((value >> 48) & 0xFF);
                bytes[5] = u8((value >> 40) & 0xFF);
                bytes[4] = u8((value >> 32) & 0xFF);
            case 4:
                bytes[3] = u8((value >> 24) & 0xFF);
                bytes[2] = u8((value >> 16) & 0xFF);
            case 2:
                bytes[1] = u8((value >> 8) & 0xFF);
                bytes[0] = u8(value & 0xFF);
        }
        return bytes;
    }

    template <endian INTO>
    constexpr u16 PUREFN
    from_bytes(const buffer::Array<u8, 2> & bytes)
    {
        u16 value = bytes[0] | //
            u16(u16(bytes[1]) << 8);
        if constexpr (INTO != endian::native) {
            value = swap(value);
        }
        return value;
    }

    template <endian INTO>
    constexpr u32 PUREFN
    from_bytes(const buffer::Array<u8, 4> & bytes)
    {
        u32 value = bytes[0] |         //
            u32(u32(bytes[1]) << 8) |  //
            u32(u32(bytes[2]) << 16) | //
            u32(u32(bytes[3]) << 24);
        if constexpr (INTO != endian::native) {
            value = swap(value);
        }
        return value;
    }

    template <endian INTO>
    constexpr u64 PUREFN
    from_bytes(const buffer::Array<u8, 8> & bytes)
    {
        u64 value = bytes[0] |         //
            u64(u64(bytes[1]) << 8) |  //
            u64(u64(bytes[2]) << 16) | //
            u64(u64(bytes[3]) << 24) | //
            u64(u64(bytes[4]) << 32) | //
            u64(u64(bytes[5]) << 40) | //
            u64(u64(bytes[6]) << 48) | //
            u64(u64(bytes[7]) << 56);
        if constexpr (INTO != endian::native) {
            value = swap(value);
        }
        return value;
    }
}

#pragma once

#include "defs.hpp"
#include "types.hpp"

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

    template <endian INTO, typename SRC>
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

    template <endian INTO, typename SRC>
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
}

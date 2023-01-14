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
    swap(const u16 & val)
    {
        return                                    //
            static_cast<u16>((val & 0xff) << 8) | //
            static_cast<u16>((val & 0xff00) >> 8);
    }

    constexpr u32 PUREFN
    swap(const u32 & val)
    {
        return                                        //
            static_cast<u32>((val & 0xff) << 24) |    //
            static_cast<u32>((val & 0xff00) << 8) |   //
            static_cast<u32>((val & 0xff0000) >> 8) | //
            static_cast<u32>((val & 0xff000000) >> 24);
    }

    template <endian INTO, typename SRC>
    constexpr SRC PUREFN
    into(const SRC & val)
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
    from(const SRC & val)
    {
        if constexpr (endian::native == INTO) {
            return val;
        }
        else {
            return swap(val);
        }
    }
}

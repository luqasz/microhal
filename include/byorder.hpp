#pragma once

#include "types.hpp"

enum class endian : usize {
    little  = __ORDER_LITTLE_ENDIAN__,
    big     = __ORDER_BIG_ENDIAN__,
    native  = __BYTE_ORDER__,
    network = __ORDER_BIG_ENDIAN__,
};

namespace byorder {

    [[gnu::const]] constexpr u16
    swap(const u16 & val)
    {
        return                                    //
            static_cast<u16>((val & 0xff) << 8) | //
            static_cast<u16>((val & 0xff00) >> 8);
    }

    [[gnu::const]] constexpr u32
    swap(const u32 & val)
    {
        return                                        //
            static_cast<u32>((val & 0xff) << 24) |    //
            static_cast<u32>((val & 0xff00) << 8) |   //
            static_cast<u32>((val & 0xff0000) >> 8) | //
            static_cast<u32>((val & 0xff000000) >> 24);
    }

    template <endian INTO, typename SRC>
    [[gnu::const]] constexpr SRC
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
    [[gnu::const]] constexpr SRC
    from(const SRC & val)
    {
        if constexpr (endian::native == INTO) {
            return val;
        }
        else {
            return swap(val);
        }
    }

    template <typename T>
    class [[gnu::packed]] NetworkOrdered {
    public:
        NetworkOrdered() { }
        NetworkOrdered(const T & host_value) :
            network_value(into<endian::network>(host_value))
        {
        }

        operator T() const
        {
            return from<endian::network>(network_value);
        }

    private:
        T network_value { 0 };
    };
}

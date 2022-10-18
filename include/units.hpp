#pragma once

#include "types.hpp"

struct Frequency {
    const u32 value;

    constexpr Frequency(const u32 _value) :
        value(_value) { }

    constexpr Frequency
    operator/(const Frequency & other) const
    {
        return { value / other.value };
    }

    constexpr Frequency
    operator/(const u32 & other) const
    {
        return { value / other };
    }
};

constexpr Frequency operator"" _kHz(unsigned long long int freq)
{
    return Frequency { static_cast<u32>(freq * 1000) };
}

constexpr Frequency operator"" _Hz(unsigned long long int freq)
{
    return Frequency { static_cast<u32>(freq) };
}

constexpr Frequency operator"" _MHz(unsigned long long int freq)
{
    return Frequency { static_cast<u32>(freq * 1000000) };
}

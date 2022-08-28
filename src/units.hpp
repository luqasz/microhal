#pragma once
#include <stdint.h>

struct Frequency {
    const uint32_t value;

    constexpr Frequency(const uint32_t _value) :
        value(_value) {}

    constexpr Frequency
    operator/(const Frequency & other) const
    {
        return { value / other.value };
    }

    constexpr Frequency
    operator/(const uint32_t & other) const
    {
        return { value / other };
    }
};

constexpr Frequency operator"" _kHz(unsigned long long int freq)
{
    return Frequency { static_cast<uint32_t>(freq * 1000) };
}

constexpr Frequency operator"" _Hz(unsigned long long int freq)
{
    return Frequency { static_cast<uint32_t>(freq) };
}

constexpr Frequency operator"" _MHz(unsigned long long int freq)
{
    return Frequency { static_cast<uint32_t>(freq * 1000000) };
}

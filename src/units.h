#pragma once
#include <stdint.h>

struct Frequency {
    const uint32_t value;
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

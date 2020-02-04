#pragma once

struct Frequency {
    const unsigned long long int value;
};

constexpr Frequency operator"" _kHz (unsigned long long int freq)
{
    return Frequency{freq * 1000};
}

constexpr Frequency operator"" _Hz (unsigned long long int freq)
{
    return Frequency{freq};
}

#pragma once

#include "types.hpp"

namespace units {
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

        constexpr Frequency
        operator*(const u32 & other) const
        {
            return { value * other };
        }

        constexpr Frequency
        operator*(const Frequency & other) const
        {
            return { value * other.value };
        }

        constexpr Frequency
        operator-(const u32 & other) const
        {
            return { value - other };
        }

        constexpr Frequency
        operator+(const u32 & other) const
        {
            return Frequency { value + other };
        }

        constexpr bool
        operator>(const u32 & other) const
        {
            return value > other;
        }

        constexpr bool
        operator<(const u32 & other) const
        {
            return value < other;
        }
    };

    constexpr Frequency kHz = Frequency(400'000);
    constexpr Frequency Hz  = Frequency(1);
    constexpr Frequency MHz = Frequency(100'000'000);
}

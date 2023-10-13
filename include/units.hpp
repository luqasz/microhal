#pragma once

#include "types.hpp"
#include "defs.hpp"

namespace units {
    struct Frequency {
        const u32 value;

        explicit constexpr Frequency(const u32 _value) :
            value(_value) { }

        constexpr explicit
        operator u32()
        {
            return value;
        }

        constexpr u32
        operator/(const Frequency & other) const
        {
            return value / other.value;
        }

        constexpr Frequency
        operator/(const u32 & other) const
        {
            return Frequency(value / other);
        }

        constexpr Frequency
        operator*(const u32 & other) const
        {
            return Frequency(value * other);
        }

        constexpr Frequency
        operator-(const Frequency & other) const
        {
            return Frequency(value - other.value);
        }

        constexpr Frequency
        operator+(const Frequency & other) const
        {
            return Frequency(value + other.value);
        }

        constexpr bool
        operator>(const Frequency & other) const
        {
            return value > other.value;
        }

        constexpr bool
        operator<(const Frequency & other) const
        {
            return value < other.value;
        }

        constexpr bool
        operator==(const Frequency & other) const
        {
            return value == other.value;
        }
    };

    constexpr Frequency kHz = Frequency(100'000);
    constexpr Frequency Hz = Frequency(1);
    constexpr Frequency MHz = Frequency(100'000'000);
}

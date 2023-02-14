#pragma once

#include "types.hpp"
#include "defs.hpp"
#include "traits.hpp"

template <typename T>
    requires is_unsigned<T> bool
constexpr CONSTFN
is_power_of_two(T number)
{
    return (number != 0) and (number & (number - 1)) == 0;
}

// Return first bit position starting from LSB and counting from 0.
template <typename T>
    requires is_unsigned<T>
usize constexpr CONSTFN
first_lsbit(T n)
{
    usize i = 1, pos = 0;
    // Iterate through bits of n till we find a set bit
    // i&n will be non-zero only when 'i' and 'n' have a set bit
    // at same position
    while (!(i & n)) {
        // Unset current bit and set the next bit in 'i'
        i = static_cast<T>(i << 1);
        // increment position
        ++pos;
    }
    return pos;
}

template <typename T>
    requires is_unsigned<T>
constexpr T CONSTFN
countSetBits(T number)
{
    T count = 0;
    while (number) {
        count++;
        number &= (number - 1);
    }
    return count;
}

template <typename T>
    requires is_unsigned<T>
constexpr T CONSTFN
inverted(T value)
{
    return static_cast<T>(~value);
}

#pragma once

#include "types.hpp"

template <typename T>
bool constexpr isPowerOfTwo(T number)
{
    return (number != 0) && (number & (number - 1)) == 0;
}

// Return first bit position starting from LSB and counting from 0.
template <typename T>
usize constexpr first_lsbit(T n)
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
constexpr T
countSetBits(T number)
{
    T count = 0;
    while (number) {
        count++;
        number &= (number - 1);
    }
    return count;
}

template <typename T, typename U>
struct is_same {
    static const bool value = false;
};

template <typename T>
struct is_same<T, T> {
    static const bool value = true;
};

template <typename T, typename U>
constexpr bool
eqTypes()
{
    return is_same<T, U>::value;
}

template <typename T>
constexpr T
inverted(T value)
{
    return static_cast<T>(~value);
}

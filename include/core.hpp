#pragma once

#include "types.hpp"
#include "defs.hpp"

template <typename T>
constexpr inline T CONSTFN
max(const T & lhs, const T & rhs)
{
    return lhs > rhs ? lhs : rhs;
}

template <typename T, typename... Other>
constexpr inline T CONSTFN
max(const T & lhs, const T & rhs, const Other &... other)
{
    const T val = max(lhs, rhs);
    return max(val, other...);
}

template <typename T>
constexpr inline T CONSTFN
min(const T & lhs, const T & rhs)
{
    return lhs < rhs ? lhs : rhs;
}

template <typename T, typename... Other>
constexpr inline T CONSTFN
min(const T & lhs, const T & rhs, const Other &... other)
{
    const T val = min(lhs, rhs);
    return min(val, other...);
}

#pragma once

#include "types.hpp"

template <typename T, typename U>
constexpr bool is_same = false;

template <typename T>
constexpr bool is_same<T, T> = true;

template <typename T>
struct is_unsigned_struct {
    constexpr static bool value = false;
};

template <>
struct is_unsigned_struct<u8> {
    static constexpr bool value = true;
};

template <>
struct is_unsigned_struct<u16> {
    static constexpr bool value = true;
};

template <>
struct is_unsigned_struct<u32> {
    static constexpr bool value = true;
};

template <typename T>
constexpr bool is_unsigned = is_unsigned_struct<T>::value;

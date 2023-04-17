#pragma once

#include "traits.hpp"

template <typename Type>
concept Unsigned = is_unsigned<Type>;

template <class T, class U>
concept Same = is_same<T, U>;

// clang-format off
template <typename T, typename U>
concept Assignable = requires(T a, U b) {
    {b = a};
};

template<class W>
concept Writer = requires(W thing, typename W::ContainedType input) {
    { thing.write(input) };
    { thing.free() } -> Same<usize>;
};

template<class R>
concept Reader = requires(R thing, typename R::ContainedType input) {
    { thing.read() } -> Same<typename R::ContainedType>;
    { thing.len() } -> Same<usize>;
};
// clang-format on

#pragma once

#include <types.hpp>

template <usize LEN>
struct String {
    char str[LEN] = { 0 };

    constexpr String() { }

    explicit constexpr String(const char (&in)[LEN])
    {
        usize i = 0;
        while (i < LEN) {
            str[i] = in[i];
            i++;
        }
    }

    constexpr usize
    null_idx() const
    {
        usize idx = 0;
        while (idx < LEN) {
            if (!str[idx]) {
                return idx;
            }
            idx++;
        }
        return idx;
    }

    constexpr usize
    free() const
    {
        return LEN - null_idx();
    }

    constexpr usize
    len() const
    {
        return null_idx();
    }

    constexpr usize
    size() const
    {
        return LEN;
    }

    constexpr const char *
    begin() const
    {
        return str;
    }
    constexpr char *
    begin()
    {
        return str;
    }

    constexpr char *
    end()
    {
        return str + null_idx();
    }
    constexpr const char *
    end() const
    {
        return str + null_idx();
    }

    template <usize OLEN>
    constexpr String &
    operator+=(const String<OLEN> & other)
    {
        auto       start  = end();
        const auto finish = start + min(free(), other.len());
        auto       optr   = other.begin();
        while (start < finish) {
            *start++ = *optr++;
        }
        return *this;
    }
};

template <usize A, usize B>
constexpr auto
operator+(const String<A> & a, const String<B> & b)
{
    auto str = String<A + B>();
    str += a;
    str += b;
    return str;
}

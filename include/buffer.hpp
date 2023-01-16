#pragma once

#include "types.hpp"
#include "utils.hpp"

namespace buffer {

    template <typename T>
    struct Span {
    private:
        T *   ptr;
        usize len;

        constexpr Span(T * p, const usize N) noexcept :
            ptr(p),
            len(N)
        {
        }

    public:
        template <usize N>
        constexpr Span(T (&begin_)[N]) noexcept :
            ptr(begin_),
            len(N)
        {
        }

        constexpr const Span<const T>
        slice(const usize b, const usize e) const
        {
            return Span<const T>(ptr + b, e);
        }

        constexpr Span<T>
        slice(const usize b, const usize e)
        {
            return Span<T>(ptr + b, e);
        }

        constexpr T *
        begin()
        {
            return ptr;
        }

        constexpr T *
        end()
        {
            return ptr + len;
        }

        constexpr const T *
        begin() const
        {
            return ptr;
        }

        constexpr const T *
        end() const
        {
            return ptr + len;
        }

        constexpr usize
        size()
        {
            return len;
        }

        constexpr T &
        operator[](const usize idx)
        {
            return ptr[idx];
        }
    };

    template <typename Contained, usize Size>
    struct Array {
        Contained elems[Size];

        constexpr usize
        size() const
        {
            return size;
        }

        constexpr Contained &
        operator[](const usize idx)
        {
            return elems[idx];
        }

        constexpr const Contained &
        operator[](const usize idx) const
        {
            return elems[idx];
        }

        constexpr Contained *
        begin()
        {
            return elems;
        }

        constexpr const Contained *
        begin() const
        {
            return elems;
        }

        constexpr Contained *
        end()
        {
            return elems + Size;
        }

        constexpr const Contained *
        end() const
        {
            return elems + Size;
        }
    };

    template <typename DATA_TYPE, usize BUFFER_SIZE>
        requires(is_power_of_two(BUFFER_SIZE) and BUFFER_SIZE > 1)
    class Circular {

    private:
        usize                  head              = 0;
        usize                  tail              = 0;
        DATA_TYPE              data[BUFFER_SIZE] = { 0 };
        constexpr static usize mask              = BUFFER_SIZE - 1;

    public:
        constexpr usize
        size() const
        {
            return BUFFER_SIZE;
        }

        constexpr usize
        len() const
        {
            return static_cast<usize>(head - tail);
        }

        constexpr void
        write(const DATA_TYPE byte)
        {
            data[head++ & mask] = byte;
        }

        constexpr DATA_TYPE
        read()
        {
            return data[tail++ & mask];
        }
    };
}

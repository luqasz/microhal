#pragma once

#include "types.hpp"
#include "utils.hpp"

namespace buffer {

    template <typename T>
    struct Span {
    private:
        T *   ptr;
        usize length;

        constexpr Span(T * p, const usize N) noexcept :
            ptr(p),
            length(N)
        {
        }

    public:
        template <usize N>
        constexpr Span(T (&begin_)[N]) noexcept :
            ptr(begin_),
            length(N)
        {
        }

        constexpr const Span<T>
        slice(const usize b, const usize e) const
        {
            return Span<T>(ptr + b, e);
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

        constexpr const T *
        begin() const
        {
            return ptr;
        }

        constexpr T *
        end()
        {
            return ptr + length;
        }

        constexpr const T *
        end() const
        {
            return ptr + length;
        }

        constexpr usize
        size() const
        {
            return length;
        }

        constexpr usize
        len() const
        {
            return length;
        }

        constexpr usize
        free() const
        {
            return length;
        }

        constexpr T &
        operator[](const usize idx)
        {
            return ptr[idx];
        }

        constexpr const T &
        operator[](const usize idx) const
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
            return Size;
        }

        constexpr usize
        len() const
        {
            return Size;
        }

        constexpr usize
        free() const
        {
            return Size;
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

        constexpr
        operator Span<Contained>()
        {
            return Span(elems);
        }

        constexpr
        operator Span<Contained>() const
        {
            return Span(elems);
        }

        constexpr Span<Contained>
        span()
        {
            return Span(elems);
        }

        constexpr const Span<Contained>
        span() const
        {
            return Span(elems);
        }
    };

    template <class T, class... U>
    Array(T, U...) -> Array<T, 1 + sizeof...(U)>;

    template <typename DATA_TYPE, usize BUFFER_SIZE>
        requires(is_power_of_two(BUFFER_SIZE) and BUFFER_SIZE > 1 and BUFFER_SIZE >= ((limits<DATA_TYPE>::max + 1) / 2))
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

        constexpr usize
        free() const
        {
            return size() - len();
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

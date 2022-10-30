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

    template <typename DATA_TYPE, usize BUFFER_SIZE>
    class Circular {
        static_assert(isPowerOfTwo(BUFFER_SIZE), "Size must be power of 2.");
        static_assert(BUFFER_SIZE > 1, "Buffer must be at least 2 in size.");

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

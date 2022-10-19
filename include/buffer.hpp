#pragma once

#include "types.hpp"
#include "utils.hpp"

namespace buffer {

    template <typename T>
    class Slice {
        T * const begin_ptr;
        T * const end_ptr;

    public:
        constexpr Slice(T * const b, T * const e) :
            begin_ptr(b),
            end_ptr(e)
        {
        }

        constexpr T *
        begin() const
        {
            return begin_ptr;
        };

        constexpr T *
        end() const
        {
            return end_ptr;
        };

        constexpr T &
        operator[](const usize idx) const
        {
            return begin_ptr[idx];
        };

        constexpr usize
        size() const
        {
            return static_cast<usize>(end() - begin());
        };
    };

    template <typename T, usize SIZE>
    class Array {
        static_assert(SIZE > 0, "size must be > 0");
        T array[SIZE] = { 0 };

    public:
        constexpr Array() { }

        constexpr T &
        operator[](const usize idx)
        {
            return array[idx];
        };

        constexpr Slice<T>
        slice(const usize start, const usize num)
        {
            return Slice<T>(array + start, array + num);
        }

        constexpr Slice<T>
        whole()
        {
            return Slice<T>(array, array + SIZE);
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

#pragma once

#include "types.hpp"
#include "utils.hpp"

#include <stdint.h>

namespace Buffer {

    class Bytes {
    private:
        uint8_t * const begin_ptr;
        uint8_t * const end_ptr;

    protected:
        Bytes(uint8_t * const b, uint8_t * const e) :
            begin_ptr(b),
            end_ptr(e)
        {
        }

    public:
        constexpr uint8_t *
        begin() const
        {
            return begin_ptr;
        };

        constexpr uint8_t *
        end() const
        {
            return end_ptr;
        };

        /*
         * Return pointer to last element in array.
         */
        constexpr uint8_t *
        lastElemPtr() const
        {
            return end() - 1;
        }

        constexpr uint8_t &
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

    template <unsigned int SIZE>
    class SizedBytesArray : public Bytes {
        static_assert(SIZE > 0, "buffer size must be > 0");
        uint8_t array[SIZE] = { 0 };

    public:
        SizedBytesArray() :
            Bytes(array, array + SIZE) { }
    };

    template <typename DATA_TYPE, usize BUFFER_SIZE, typename HT_TYPE = usize>
    class Circular {
        static_assert(BUFFER_SIZE > 1, "Size bust be > 1.");

    private:
        HT_TYPE   head              = 0;
        HT_TYPE   tail              = 0;
        DATA_TYPE data[BUFFER_SIZE] = { 0 };

    public:
        constexpr HT_TYPE
        size() const
        {
            return BUFFER_SIZE;
        }

        constexpr HT_TYPE
        len() const
        {
            return static_cast<HT_TYPE>(head - tail);
        }

        HT_TYPE
        mask(const HT_TYPE val)
        {
            return val % size();
        }

        void
        write(DATA_TYPE value)
        {
            data[mask(head++)] = value;
        }

        DATA_TYPE
        read()
        {
            return data[mask(tail++)];
        }
    };

    template <typename DATA_TYPE, usize BUFFER_SIZE, typename HT_TYPE = usize>
    class CircularPowerOf2 {
        static_assert(isPowerOfTwo(BUFFER_SIZE), "Size must be power of 2.");
        static_assert(BUFFER_SIZE > 1, "Buffer must be at least 2 in size.");

    private:
        HT_TYPE                head              = 0;
        HT_TYPE                tail              = 0;
        DATA_TYPE              data[BUFFER_SIZE] = { 0 };
        constexpr static usize mask              = BUFFER_SIZE - 1;

    public:
        constexpr HT_TYPE
        size() const
        {
            return BUFFER_SIZE;
        }

        constexpr HT_TYPE
        len() const
        {
            return static_cast<HT_TYPE>(head - tail);
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

#ifndef buffer_h
#define buffer_h

#include "utils.h"

#include <stdint.h>

namespace Buffer {

    namespace Interface {
        class ArrayWrapper {
        public:
            virtual uint8_t *
            begin()
                = 0;

            virtual uint8_t *
            end()
                = 0;

            virtual uint8_t &
            operator[](uint8_t)
                = 0;
        };
    }

    template <unsigned int SIZE>
    class Array : public Buffer::Interface::ArrayWrapper {
        static_assert(SIZE > 0, "buffer size must be > 0");
        uint8_t array[SIZE] = { 0 };

    public:
        uint8_t *
        begin()
        {
            return &array[0];
        }

        uint8_t *
        end()
        {
            return &array[SIZE];
        }

        uint8_t &
        operator[](uint8_t idx)
        {
            return array[idx];
        }
    };

    template <uint8_t BUFFER_SIZE>
    class Circular {
        static_assert(BUFFER_SIZE < 256, "Size bust be < 256.");
        static_assert(BUFFER_SIZE > 0, "Size bust be > 0.");

    private:
        uint8_t head              = 0;
        uint8_t tail              = 0;
        uint8_t data[BUFFER_SIZE] = { 0 };
        uint8_t elements          = 0;

    public:
        uint8_t
        read()
        {
            uint8_t next_tail = static_cast<uint8_t>(tail + 1);
            if (next_tail >= BUFFER_SIZE)
                next_tail = 0;

            uint8_t value = data[tail];
            tail          = next_tail;
            elements--;
            return value;
        }

        void
        write(uint8_t byte)
        {
            uint8_t next_head = static_cast<uint8_t>(head + 1);
            if (next_head >= BUFFER_SIZE)
                next_head = 0;

            data[head] = byte;
            head       = next_head;
            elements++;
        }

        // Return how many elements are in the buffer.
        uint8_t
        size() const
        {
            return elements;
        }

        // Return free space.
        uint8_t
        free() const
        {
            return static_cast<uint8_t>(BUFFER_SIZE - elements);
        }
    };

    template <uint8_t BUFFER_SIZE>
    class CircularPowerOf2 {
        static_assert(isPowerOfTwo(BUFFER_SIZE), "Size must be power of 2.");

    private:
        uint8_t head              = 0;
        uint8_t tail              = 0;
        uint8_t data[BUFFER_SIZE] = { 0 };

    public:
        uint8_t
        size()
        {
            return static_cast<uint8_t>(head - tail);
        }

        uint8_t
        mask(uint8_t val)
        {
            return val % BUFFER_SIZE;
        }

        void
        write(uint8_t byte)
        {
            data[mask(head++)] = byte;
        }

        uint8_t
        read()
        {
            return data[mask(tail++)];
        }
    };

}

#endif

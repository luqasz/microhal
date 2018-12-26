#ifndef buffer_h
#define buffer_h

#include <stdint.h>

template <uint8_t BUFFER_SIZE>
class CircularBuffer {
private:
    uint8_t head              = 0;
    uint8_t tail              = 0;
    uint8_t data[BUFFER_SIZE] = { 0 };
    uint8_t elements          = 0;

public:
    uint8_t
    get() volatile
    {
        uint8_t next_tail = tail + 1;
        if (next_tail >= BUFFER_SIZE)
            next_tail = 0;

        uint8_t value = data[tail];
        tail          = next_tail;
        elements--;
        return value;
    }

    void
    put(uint8_t byte) volatile
    {
        uint8_t next_head = head + 1;
        if (next_head >= BUFFER_SIZE)
            next_head = 0;

        data[head] = byte;
        head       = next_head;
        elements++;
    }

    // Return how many elements are in the buffer.
    uint8_t
    size() volatile const
    {
        return elements;
    }

    // Return free space.
    uint8_t
    free() volatile const
    {
        return BUFFER_SIZE - elements;
    }
};

#endif

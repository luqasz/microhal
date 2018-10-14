#include <stdint.h>
#include "buffer.h"

// Return ammount of bytes stored in buffer
uint8_t
circ_buf_size (
    circ_buf * buffer
)
{
    return buffer->head - buffer->tail;
}

// Write a single byte into a buffer.
// Return number of bytes written.
uint8_t
circ_buf_push (
    circ_buf * c,
    uint8_t data
)
{
    uint8_t next_head;

    next_head = c->head + 1;
    if (next_head >= c->capacity)
        next_head = 0;

    // Check if buffer is full
    if (next_head == c->tail)
        return 0;

    c->data[c->head] = data;
    c->head = next_head;
    return 1;
}

// Read a single byte from a buffer.
// Return number of bytes read.
uint8_t
circ_buf_pop (
    circ_buf * c,
    uint8_t * data
)
{
    uint8_t next_tail;

    // Check if buffer is empty
    if (c->head == c->tail)
        return 0;

    next_tail = c->tail + 1;
    if (next_tail >= c->capacity)
        next_tail = 0;

    *data = c->data[c->tail];
    c->tail = next_tail;
    return 1;
}

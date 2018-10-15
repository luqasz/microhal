#include <stdint.h>

#ifndef buffer_H_
#define buffer_H_

#define CIRC_BUF_DEF(x,y)                \
    volatile uint8_t x##_data_space[y];  \
    volatile circ_buf x = {              \
        .data = x##_data_space,          \
        .head = 0,                       \
        .tail = 0,                       \
        .capacity = y                    \
    }

typedef struct
{
    uint8_t head;
    uint8_t tail;
    volatile uint8_t *const data;
    const uint8_t capacity;
} circ_buf;

uint8_t circ_buf_pop (
    volatile circ_buf * c,
    uint8_t * data
);
uint8_t circ_buf_push (
    volatile circ_buf * c,
    uint8_t data
);
uint8_t circ_buf_size (
    volatile circ_buf * buffer
);

#endif

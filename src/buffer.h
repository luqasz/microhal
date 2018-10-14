#include <stdint.h>

#ifndef buffer_H_
#define buffer_H_

#define CIRC_BUF_DEF(x,y)                \
    uint8_t x##_data_space[y];           \
    circ_buf x = {                       \
        .data = x##_data_space,          \
        .head = 0,                       \
        .tail = 0,                       \
        .capacity = y                    \
    }

typedef struct
{
    uint8_t head;
    uint8_t tail;
    uint8_t *const data;
    const uint8_t capacity;
} circ_buf;

uint8_t circ_buf_pop (
    circ_buf * c,
    uint8_t * data
);
uint8_t circ_buf_push (
    circ_buf * c,
    uint8_t data
);
uint8_t circ_buf_size (
    circ_buf * buffer
);

#endif

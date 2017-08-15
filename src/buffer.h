// Buffer implementation taken from:
// https://www.snellman.net/blog/archive/2016-12-13-ring-buffers/
#include <stdint.h>

#ifndef buffer_H_
#define buffer_H_

typedef struct {
    uint8_t head;
    uint8_t tail;
    unsigned char *data;
    uint8_t capacity;
} buffer;

uint8_t buffer_size(buffer *buf);
uint8_t buffer_mask(uint8_t val, buffer *buf);
uint8_t buffer_write(unsigned char byte, buffer *buf);
uint8_t buffer_read(unsigned char *bytes, uint8_t count, buffer *buf);

#endif

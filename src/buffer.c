// Buffer implementation taken from:
// https://www.snellman.net/blog/archive/2016-12-13-ring-buffers/
#include "buffer.h"


uint8_t buffer_size(buffer *buf) {
    return (uint8_t) (buf->head - buf->tail);
}


uint8_t buffer_mask(uint8_t val, buffer *buf) {
    return val % buf->capacity;
}


// Write given char to buffer and return number of written bytes.
uint8_t buffer_write(unsigned char byte, buffer *buf) {
    // check if buffer is full.
    if (buffer_size(buf) != buf->capacity) {
        buf->data[buffer_mask(buf->head++, buf)] = byte;
        return 1;
    }
    return 0;
}


// Read n number of bytes into buffer from ring buffer.
// Return umber of read bytes.
uint8_t buffer_read(unsigned char *bytes, uint8_t count, buffer *buf) {
    uint8_t ring_size = buffer_size(buf);
    uint8_t read = 0;
    count = count < ring_size ? count : ring_size;
    for (; count != 0; count--) {
        bytes[read++] = buf->data[buffer_mask(buf->tail++, buf)];
    }
    return read;
}

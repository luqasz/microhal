#ifndef UART_H_
#define UART_H_

void uart_start (
    void
);
void uart_write_byte (
    uint8_t byte
);
void uart_write_string (
    char *string
);

#define uart_write(value) _Generic((value),     \
    uint8_t: uart_write_byte,                   \
    char*: uart_write_string                    \
    )(value)

uint8_t uart_read_byte (
    void
);

#endif

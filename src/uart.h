#ifndef UART_H_
#define UART_H_

void uart_start (
    void
);
void uart_putchar (
    unsigned char byte
);
void uart_write (
    char *string
);

#endif

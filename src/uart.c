#include <avr/io.h>
#include <util/setbaud.h>
#include <avr/interrupt.h>
#include "registers.h"
#include "uart.h"
#include "buffer.h"

CIRC_BUF_DEF (tx_buf, 10);
CIRC_BUF_DEF (rx_buf, 10);

void
uart_start (
    void
)
{
    // Set baud rate
    UBRRH = (uint8_t) (UBRRH_VALUE >> 8);
    UBRRL = (uint8_t) UBRRL_VALUE;
    // Turn on RX and TX
    UCSRB = (1 << RXEN) | (1 << TXEN);
    // atmega328p is already configured to 8n1
}

void
uart_putchar (
    unsigned char byte
)
{
    register uint8_t num = 0;
    while (!num) {
        num = circ_buf_push (&tx_buf, byte);
    }
    // Enable data register empty interrupt.
    UCSRB |= (1 << UDRIE);
}

void
uart_write (
    char *string
)
{
    register char c;
    while ((c = *string++)) {
        uart_putchar (c);
    }
}

// Executed when data register is empty.
ISR (USART_UDRE_vect)
{
    unsigned char byte;
    if (circ_buf_pop (&tx_buf, &byte) == 1) {
        UDR = byte;
    }
    // Disable interrupt when no data in buffer.
    if (circ_buf_size (&tx_buf) == 0) {
        UCSRB &= (uint8_t) ~ (1 << UDRIE);
    }
}

// Executed when data is received.
/* ISR(USART_RX_vect) { */
/*     unsigned int data = UDR; */
/* } */

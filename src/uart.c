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

    UCSRB |= (1 << RXEN);       // Turn on RX.
    UCSRB |= (1 << TXEN);       // Turn on TX.
    UCSRB |= (1 << RXCIE);      // Turn on RX irq.
    // All atmega MCUs are already configured to 8n1
}

void
uart_write_string (
    char *string
)
{
    register char c;
    while ((c = *string++)) {
        uart_write_byte (c);
    }
}

void
uart_write_byte (
    uint8_t byte
)
{
    register uint8_t num = 0;
    while (!num) {
        num = circ_buf_push (&tx_buf, byte);
    }
    // Enable data register empty interrupt.
    UCSRB |= (1 << UDRIE);
}

uint8_t
uart_read_byte (
    void
)
{
    uint8_t byte;
    uint8_t num = 0;
    while (!num) {
        num = circ_buf_pop (&rx_buf, &byte);
    }
    return byte;
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
ISR (USART_RX_vect)
{
    circ_buf_push (&rx_buf, UDR);
}

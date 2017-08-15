#include <avr/io.h>
#include <util/setbaud.h>
#include <avr/interrupt.h>

#include "uart.h"
#include "buffer.h"


unsigned char rx_data[32];
buffer rx_buf = {
    .capacity = 32,
    .data = rx_data,
};

unsigned char tx_data[32];
buffer tx_buf = {
    .capacity = 32,
    .data = tx_data,
};


void uart_start(void) {
    // Set baud rate
    UBRR0H = (uint8_t)(UBRRH_VALUE>>8);
    UBRR0L = (uint8_t)UBRRL_VALUE;
    // Turn on RX and TX
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    // atmega328p is already configured to 8n1
}


void uart_putchar(unsigned char byte) {
    // Enable data register empty interrupt.
    UCSR0B |= (1<<UDRIE0);
    buffer_write(byte, &tx_buf);
}


// Executed when data register is empty.
ISR(USART_UDRE_vect) {
    unsigned char byte;
    if (buffer_read(&byte, 1, &tx_buf) == 1) {
        UDR0 = byte;
    }
    // Disable interrupt when no data in buffer.
    if ( buffer_size(&tx_buf) == 0 ) {
        UCSR0B &= ~(1<<UDRIE0);
    }
}


// Executed when data is received.
/* ISR(USART_RX_vect) { */
/*     unsigned int data = UDR0; */
/* } */

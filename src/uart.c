#include <avr/io.h>
#include <util/setbaud.h>
#include <avr/interrupt.h>

#include DEVICE_NAME
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
    UBRRH = (uint8_t)(UBRRH_VALUE>>8);
    UBRRL = (uint8_t)UBRRL_VALUE;
    // Turn on RX and TX
    UCSRB = (1<<RXEN)|(1<<TXEN);
    // atmega328p is already configured to 8n1
}


void uart_putchar(unsigned char byte) {
    register uint8_t num = 0;
    while (!num) {
        num = buffer_write(byte, &tx_buf);
    }
    // Enable data register empty interrupt.
    UCSRB |= (1<<UDRIE);
}

void uart_write(char *string) {
    register char c;
    while ((c = *string++)) {
        uart_putchar(c);
    }
}

// Executed when data register is empty.
ISR(USART_UDRE_vect) {
    unsigned char byte;
    if (buffer_read(&byte, 1, &tx_buf) == 1) {
        UDR = byte;
    }
    // Disable interrupt when no data in buffer.
    if ( buffer_size(&tx_buf) == 0 ) {
        UCSRB &= (uint8_t) ~(1<<UDRIE);
    }
}


// Executed when data is received.
/* ISR(USART_RX_vect) { */
/*     unsigned int data = UDR; */
/* } */

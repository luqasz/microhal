#include "uart.h"

#include "buffer.h"
#include "registers.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/atomic.h>

uint8_t const MODE_SELECT_MASK    = (uint8_t) ~(1 << UMSEL);
uint8_t const PARITY_MODE_MASK    = (uint8_t) ~((1 << UPM0) | (1 << UPM1));
uint8_t const STOP_BIT_MASK       = (uint8_t) ~(1 << USBS);
uint8_t const CHARACTER_SIZE_MASK = (uint8_t) ~((1 << UCSZ0) | (1 << UCSZ1) | (1 << UCSZ2));

volatile auto tx_buffer = CircularBuffer<5>();

static inline void
set_ubrr(uint16_t value)
{
    UBRRH = (uint8_t)(value >> 8);
    UBRRL = (uint8_t)value;
}

void
Uart::speed(enum BAUD_RATE_1X ubrr)
{
    set_ubrr((uint16_t)ubrr);
    UCSRA &= ~(1 << U2X);
}

void
Uart::speed(enum BAUD_RATE_2X ubrr)
{
    set_ubrr((uint16_t)ubrr);
    UCSRA |= (1 << U2X);
}

void
Uart::parity(enum PARITY_MODE parity)
{
    UCSRC &= PARITY_MODE_MASK;
    UCSRC |= parity;
}
void

Uart::stop_bits(enum STOP_BITS bits)
{
    UCSRC &= STOP_BIT_MASK;
    UCSRC |= bits;
}

void
Uart::character_size(enum CHARACTER_SIZE size)
{
    UCSRC &= CHARACTER_SIZE_MASK;
    UCSRC |= size;
}

void
Uart::start(void)
{
    UCSRB |= (1 << TXEN);  // Turn on TX.
    UCSRB |= (1 << RXEN);  // Turn on RX.
    UCSRB |= (1 << RXCIE); // Turn on RX irq.
}

void
Uart::write(const char * string)
{
    uint8_t c;
    while ((c = *string++)) {
        write(c);
    }
}

void
Uart::write(uint8_t byte)
{
    while (!tx_buffer.free()) {
    }
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        tx_buffer.put(byte);
    }
    UCSRB |= (1 << UDRIE); // Enable data register empty interrupt.
}

ISR(USART_UDRE_vect)
{
    /*
    No need to chech if we have anything in buffer.
    This irq will fire when at least one byte is present at the buffer.
    */
    UDR = tx_buffer.get();
    if (tx_buffer.size() == 0) {
        UCSRB &= (uint8_t) ~(1 << UDRIE); // Disable this interrupt.
    }
}

// // Executed when data is received.
// ISR(USART_RX_vect)
// {
//     rx_buffer.put(UDR);
// }

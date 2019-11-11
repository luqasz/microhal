#include "usart.h"

#include "buffer.h"
#include "irq.h"
#include "sfr.h"

#include <mcu_usart.h>
#include <stdint.h>

template <typename T>
static inline void
set_ubrr(T speed)
{
    uint16_t value = static_cast<uint16_t>(speed);
    /* This bit selects between accessing the UCSRC or the UBRRH Register.
    It is read as one when reading UCSRC.
    The URSEL must be zero when writing the UBRRH. */
    UCSR0C.clearBit(UCSR0C.URSEL);
    UBRR0H = static_cast<uint8_t>((value >> 8));
    UBRR0L = static_cast<uint8_t>(value);
}

void
USART::Async::set(USART::BaudRate_1x value) const
{
    set_ubrr(value);
    UCSR0A.clearBit(UCSR0A.U2X);
}

void
USART::Async::set(USART::BaudRate_2x value) const
{
    set_ubrr(value);
    UCSR0A.setBit(UCSR0A.U2X);
}

void
USART::Async::enable(USART::Channel channel) const
{
    switch (channel) {
        case USART::Channel::RX:
            UCSR0B.setBit(UCSR0B.RXEN); // Turn on RX.
            break;
        case USART::Channel::TX:
            UCSR0B.setBit(UCSR0B.TXEN); // Turn on TX.
            break;
    }
}

void
USART::Async::disable(USART::Channel channel) const
{
    switch (channel) {
        case USART::Channel::RX:
            UCSR0B.clearBit(UCSR0B.RXEN); // Turn off RX.
            break;
        case USART::Channel::TX:
            UCSR0B.clearBit(UCSR0B.TXEN); // Turn off TX.
            break;
    }
}

bool
USART::Async::is_tx_buffer_empty() const
{
    return static_cast<bool>(UCSR0A & UCSR0A.UDRE);
}

void
USART::Async::write(const uint8_t byte) const
{
    while (!is_tx_buffer_empty()) {
    }
    UDR0 = byte;
}
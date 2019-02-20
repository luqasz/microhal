#include "usart.h"

#include "buffer.h"
#include "irq.h"
#include "sfr.h"

#include <stdint.h>

volatile auto tx_buffer = Buffer::CircularPowerOf2<8>();

auto UCSR0A = Register<USART::UCSR0A_REG>();
auto UCSR0B = Register<USART::UCSR0B_REG>();
auto UCSR0C = Register<USART::UCSR0C_REG>();
auto UBRR0L = Register<USART::UBRR0L_REG>();
auto UBRR0H = Register<USART::UBRR0H_REG>();
auto UDR0   = Register<USART::UDR0_REG>();

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
USART::Master::set(USART::BaudRate_1x value) const
{
    set_ubrr(value);
    UCSR0A.clearBit(UCSR0A.U2X);
}

void
USART::Master::set(USART::BaudRate_2x value) const
{
    set_ubrr(value);
    UCSR0A.setBit(UCSR0A.U2X);
}

void
USART::Master::enable(USART::Channel channel) const
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
USART::Master::disable(USART::Channel channel) const
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

void
USART::Master::write(uint8_t byte) const
{
    while (tx_buffer.size() == 0) {
    }
    {
        Irq::atomicRestore();
        tx_buffer.write(byte);
    }
    UCSR0B.setBit(UCSR0B.UDRIE); // Enable data register empty interrupt.
}

void
Irq::UDRE(void)
{
    /*
    No need to check if we have anything in buffer.
    This irq will fire when at least one byte is present at the buffer.
    */
    UDR0 = tx_buffer.read();
    if (tx_buffer.size() == 0) {
        UCSR0B.clearBit(UCSR0B.UDRIE); // Disable this interrupt.
    }
}

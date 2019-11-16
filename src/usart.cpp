#include "usart.h"

#include "buffer.h"
#include "irq.h"
#include "sfr.h"

#include <stdint.h>


// UCSRA
constexpr uint8_t MPCM = 1;   // Multi-processor Communication Mode
constexpr uint8_t U2X  = 2;   // Double the USART transmission speed
constexpr uint8_t UPE  = 4;   // Parity Error
constexpr uint8_t DOR  = 8;   // Data overRun
constexpr uint8_t FE   = 16;  // Framing Error
constexpr uint8_t UDRE = 32;  // USART Data Register Empty
constexpr uint8_t TXC  = 64;  // USART Transmitt Complete
constexpr uint8_t RXC  = 128; // USART Receive Complete
// UCSRB
constexpr uint8_t TXB8  = 1;   // Transmit Data Bit 8
constexpr uint8_t RXB8  = 2;   // Receive Data Bit 8
constexpr uint8_t UCSZ2 = 4;   // Character Size
constexpr uint8_t TXEN  = 8;   // Transmitter Enable
constexpr uint8_t RXEN  = 16;  // Receiver Enable
constexpr uint8_t UDRIE = 32;  // USART Data register Empty Interrupt Enable
constexpr uint8_t TXCIE = 64;  // TX Complete Interrupt Enable
constexpr uint8_t RXCIE = 128; // RX Complete Interrupt Enable
// UCSRC
constexpr uint8_t UCPOL = 1;   // Clock Polarity
constexpr uint8_t UCSZ0 = 2;   // Character Size
constexpr uint8_t UCSZ1 = 4;   // Character Size
constexpr uint8_t USBS  = 8;   // Stop Bit Select
constexpr uint8_t UPM0  = 16;  // Parity Mode Bits
constexpr uint8_t UPM1  = 32;  // Parity Mode Bits
constexpr uint8_t UMSEL = 64;  // USART Mode Select
constexpr uint8_t URSEL = 128; // Register Select



template <typename T>
constexpr static inline void
set_ubrr(const T speed, const USART::Registers regs)
{
    uint16_t value = static_cast<uint16_t>(speed);
    /* This bit selects between accessing the UCSRC or the UBRRH Register.
    It is read as one when reading UCSRC.
    The URSEL must be zero when writing the UBRRH. */
    SFR::clearBit(regs.ucsrc, URSEL);
    UBRR0H = static_cast<uint8_t>((value >> 8));
    UBRR0L = static_cast<uint8_t>(value);
}

USART::Async::Async(const Registers r):
    regs(r){}

void
USART::Async::set(USART::BaudRate_1x value) const
{
    set_ubrr(value, regs);
    SFR::clearBit(regs.ucsra, U2X);
}

void
USART::Async::set(USART::BaudRate_2x value) const
{
    set_ubrr(value, regs);
    SFR::setBit(regs.ucsra, U2X);
}

void
USART::Async::enable(USART::Channel channel) const
{
    switch (channel) {
        case USART::Channel::RX:
            SFR::setBit(regs.ucsrb, RXEN);
            break;
        case USART::Channel::TX:
            SFR::setBit(regs.ucsrb, TXEN);
            break;
    }
}

void
USART::Async::disable(USART::Channel channel) const
{
    switch (channel) {
        case USART::Channel::RX:
            SFR::clearBit(regs.ucsrb, RXEN);
            break;
        case USART::Channel::TX:
            SFR::clearBit(regs.ucsrb, TXEN);
            break;
    }
}

bool
USART::Async::is_tx_buffer_empty() const
{
    return static_cast<bool>(SFR::iomem(regs.ucsra) & UDRE);
}

void
USART::Async::write(const uint8_t byte) const
{
    while (!is_tx_buffer_empty()) {
    }
    SFR::iomem(regs.udr) = byte;
}

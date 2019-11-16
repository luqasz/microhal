#pragma once

#include "sfr.h"

#include <stdint.h>

namespace USART {
auto constexpr UBRR0L = Register<SFR::UBRRL>();
auto constexpr UBRR0H = Register<SFR::UBRRH>();
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


    constexpr uint16_t
    calc_baud(const unsigned long int baud, const uint8_t divisor)
    {
        return static_cast<uint16_t>(
            ((F_CPU) + (8UL / divisor) * (baud)) / ((16UL / divisor) * (baud)) - 1UL);
    }

    enum class BaudRate_1x : uint16_t {
        x1_2400   = calc_baud(2400UL, 1),
        x1_4800   = calc_baud(4800UL, 1),
        x1_9600   = calc_baud(9600UL, 1),
        x1_14400  = calc_baud(14400UL, 1),
        x1_19200  = calc_baud(19200UL, 1),
        x1_28800  = calc_baud(28800UL, 1),
        x1_38400  = calc_baud(38400UL, 1),
        x1_57600  = calc_baud(57600UL, 1),
        x1_76800  = calc_baud(76800UL, 1),
        x1_115200 = calc_baud(115200UL, 1),
        x1_230400 = calc_baud(230400UL, 1),
        x1_250000 = calc_baud(250000UL, 1),
    };

    enum class BaudRate_2x : uint16_t {
        x2_2400   = calc_baud(2400UL, 2),
        x2_4800   = calc_baud(4800UL, 2),
        x2_9600   = calc_baud(9600UL, 2),
        x2_14400  = calc_baud(14400UL, 2),
        x2_19200  = calc_baud(19200UL, 2),
        x2_28800  = calc_baud(28800UL, 2),
        x2_38400  = calc_baud(38400UL, 2),
        x2_57600  = calc_baud(57600UL, 2),
        x2_76800  = calc_baud(76800UL, 2),
        x2_115200 = calc_baud(115200UL, 2),
        x2_230400 = calc_baud(230400UL, 2),
        x2_250000 = calc_baud(250000UL, 2),
    };

    enum class Parity : uint8_t {
        None,
        Even,
        Odd,
    };

    enum class StopBits : uint8_t {
        One,
        Two,
    };

    enum class CharacterSize : uint8_t {
        Bit5,
        Bit6,
        Bit7,
        Bit8,
    };

    enum class Channel : uint8_t {
        RX,
        TX,
    };

    struct Registers {
        const uint8_t udr;
        const uint8_t ucsra;
        const uint8_t ucsrb;
        const uint8_t ucsrc;
    };

    template <typename T>
    constexpr static inline void
    set_ubrr(const T speed, const uint8_t ucsrc)
    {
        uint16_t value = static_cast<uint16_t>(speed);
        /* This bit selects between accessing the UCSRC or the UBRRH Register.
        It is read as one when reading UCSRC.
        The URSEL must be zero when writing the UBRRH. */
        SFR::clearBit(ucsrc, URSEL);
        UBRR0H = static_cast<uint8_t>((value >> 8));
        UBRR0L = static_cast<uint8_t>(value);
    }


    template <typename REGS>
    class Async {

    public:
        void
        set(BaudRate_1x value) const
        {
            set_ubrr(value, REGS::ucsrc);
            SFR::clearBit(REGS::ucsra, U2X);
        }

        void
        set(BaudRate_2x value) const
        {
            set_ubrr(value, REGS::ucsrc);
            SFR::setBit(REGS::ucsra, U2X);
        }

        constexpr void
        enable(Channel channel) const
        {
            switch (channel) {
                case Channel::RX:
                    SFR::setBit(REGS::ucsrb, RXEN);
                    break;
                case Channel::TX:
                    SFR::setBit(REGS::ucsrb, TXEN);
                    break;
            }
        }

        constexpr void
        disable(Channel channel) const
        {
            switch (channel) {
                case Channel::RX:
                    SFR::clearBit(REGS::ucsrb, RXEN);
                    break;
                case Channel::TX:
                    SFR::clearBit(REGS::ucsrb, TXEN);
                    break;
            }
        }

        bool
        is_tx_buffer_empty() const
        {
            return static_cast<bool>(SFR::iomem(REGS::ucsra) & UDRE);
        }

        void
        write(const uint8_t byte) const
        {
            while (!is_tx_buffer_empty()) {
            }
            SFR::iomem(REGS::udr) = byte;
        }
    };

}

#include <mcu_usart.h>

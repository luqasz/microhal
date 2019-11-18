#ifndef USART_H
#define USART_H

#include "sfr.h"

#include <stdint.h>

namespace USART {

    template <typename REG>
    struct UCSRA {
        constexpr static uint8_t address = REG::address;
        enum bits {
            MPCM = 1,   // Multi-processor Communication Mode
            U2X  = 2,   // Double the USART transmission speed
            UPE  = 4,   // Parity Error
            DOR  = 8,   // Data overRun
            FE   = 16,  // Framing Error
            UDRE = 32,  // USART Data Register Empty
            TXC  = 64,  // USART Transmitt Complete
            RXC  = 128, // USART Receive Complete
        };
    };

    template <typename REG>
    struct UCSRB {
        constexpr static uint8_t address = REG::address;
        enum bits {
            TXB8  = 1,   // Transmit Data Bit 8
            RXB8  = 2,   // Receive Data Bit 8
            UCSZ2 = 4,   // Character Size
            TXEN  = 8,   // Transmitter Enable
            RXEN  = 16,  // Receiver Enable
            UDRIE = 32,  // USART Data register Empty Interrupt Enable
            TXCIE = 64,  // TX Complete Interrupt Enable
            RXCIE = 128, // RX Complete Interrupt Enable
        };
    };

    template <typename REG>
    struct UCSRC {
        constexpr static uint8_t address = REG::address;
        enum bits {
            UCPOL = 1,   // Clock Polarity
            UCSZ0 = 2,   // Character Size
            UCSZ1 = 4,   // Character Size
            USBS  = 8,   // Stop Bit Select
            UPM0  = 16,  // Parity Mode Bits
            UPM1  = 32,  // Parity Mode Bits
            UMSEL = 64,  // USART Mode Select
            URSEL = 128, // Register Select
        };
    };

    /*
     * Calculate UBRR value based on cpu frequency and desired baud rate.
     * Select valid divisor parameter for U2X.
     * 1 when U2X = 0
     * 2 when U2X = 1
     */
    constexpr uint16_t
    calc_baud(const unsigned long int freq, const unsigned long int baud, const uint8_t divisor)
    {
        uint16_t value = static_cast<uint16_t>(freq + (8UL / divisor) * baud);
        value /= static_cast<uint16_t>((16UL / divisor) * baud);
        return value - 1;
    }

    enum class BaudRate_1x : uint16_t {
        x1_2400   = calc_baud(F_CPU, 2400UL, 1),
        x1_4800   = calc_baud(F_CPU, 4800UL, 1),
        x1_9600   = calc_baud(F_CPU, 9600UL, 1),
        x1_14400  = calc_baud(F_CPU, 14400UL, 1),
        x1_19200  = calc_baud(F_CPU, 19200UL, 1),
        x1_28800  = calc_baud(F_CPU, 28800UL, 1),
        x1_38400  = calc_baud(F_CPU, 38400UL, 1),
        x1_57600  = calc_baud(F_CPU, 57600UL, 1),
        x1_76800  = calc_baud(F_CPU, 76800UL, 1),
        x1_115200 = calc_baud(F_CPU, 115200UL, 1),
        x1_230400 = calc_baud(F_CPU, 230400UL, 1),
        x1_250000 = calc_baud(F_CPU, 250000UL, 1),
    };

    enum class BaudRate_2x : uint16_t {
        x2_2400   = calc_baud(F_CPU, 2400UL, 2),
        x2_4800   = calc_baud(F_CPU, 4800UL, 2),
        x2_9600   = calc_baud(F_CPU, 9600UL, 2),
        x2_14400  = calc_baud(F_CPU, 14400UL, 2),
        x2_19200  = calc_baud(F_CPU, 19200UL, 2),
        x2_28800  = calc_baud(F_CPU, 28800UL, 2),
        x2_38400  = calc_baud(F_CPU, 38400UL, 2),
        x2_57600  = calc_baud(F_CPU, 57600UL, 2),
        x2_76800  = calc_baud(F_CPU, 76800UL, 2),
        x2_115200 = calc_baud(F_CPU, 115200UL, 2),
        x2_230400 = calc_baud(F_CPU, 230400UL, 2),
        x2_250000 = calc_baud(F_CPU, 250000UL, 2),
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

    template <typename HIGH, typename LOW, typename C_REG>
    constexpr static inline void
    set_ubrr_split(const uint16_t speed)
    {
        /* This bit selects between accessing the UCSRC or the UBRRH Register.
        It is read as one when reading UCSRC.
        The URSEL must be zero when writing the UBRRH. */
        Register<C_REG>().clearBit(C_REG::URSEL);
        Register<HIGH>() = static_cast<uint8_t>((speed >> 8));
        Register<LOW>()  = static_cast<uint8_t>(speed);
    }

    template <typename REG>
    constexpr static inline void
    set_ubrr_single(const uint16_t speed)
    {
        Register<REG>() = speed;
    }

    template <typename REGS>
    class Async {

    public:
        constexpr void
        set(BaudRate_1x value) const
        {
            uint16_t speed = static_cast<uint16_t>(value);
            REGS::ubrr(speed);
            REGS::ucsra.clearBit(REGS::ucsra.U2X);
        }

        constexpr void
        set(BaudRate_2x value) const
        {
            uint16_t speed = static_cast<uint16_t>(value);
            REGS::ubrr(speed);
            REGS::ucsra.setBit(REGS::ucsra.U2X);
        }

        constexpr void
        enable(Channel channel) const
        {
            switch (channel) {
                case Channel::RX:
                    REGS::ucsrb.setBit(REGS::ucsrb.RXEN);
                    break;
                case Channel::TX:
                    REGS::ucsrb.setBit(REGS::ucsrb.TXEN);
                    break;
            }
        }

        constexpr void
        disable(Channel channel) const
        {
            switch (channel) {
                case Channel::RX:
                    REGS::ucsrb.clearBit(REGS::ucsrb.RXEN);
                    break;
                case Channel::TX:
                    REGS::ucsrb.clearBit(REGS::ucsrb.TXEN);
                    break;
            }
        }

        bool
        is_tx_buffer_empty() const
        {
            return static_cast<bool>(REGS::ucsra.read() & REGS::ucsra.UDRE);
        }

        void
        write(const uint8_t byte) const
        {
            while (!is_tx_buffer_empty()) {
            }
            REGS::udr = byte;
        }
    };

}

#include <mcu_usart.h>
#endif

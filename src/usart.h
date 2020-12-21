#pragma once

#include "interface.h"
#include "sfr.h"
#include "ubrr.h"

#include <stdint.h>

namespace USART {

    template <typename REG>
    struct UCSRA {
        constexpr static uint16_t address = REG::address;
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
        constexpr static uint16_t address = REG::address;
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
        constexpr static uint16_t address = REG::address;
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
        SFR::RegisterRW<C_REG, uint8_t>().clearBit(C_REG::URSEL);
        SFR::RegisterRW<HIGH, uint8_t>() = static_cast<uint8_t>((speed >> 8));
        SFR::RegisterRW<LOW, uint8_t>()  = static_cast<uint8_t>(speed);
    }

    template <typename REG>
    constexpr static inline void
    set_ubrr_single(const uint16_t speed)
    {
        SFR::RegisterRW<REG, uint16_t>() = speed;
    }

    template <typename REGS>
    class Async : public Writer {

    public:
        constexpr void
        set(const BaudRate baud) const
        {
            REGS::ubrr(baud.ubrr);
            if (baud.u2x) {
                REGS::ucsra.setBit(REGS::ucsra.U2X);
            }
            REGS::ucsra.clearBit(REGS::ucsra.U2X);
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
            return REGS::ucsra.isSet(REGS::ucsra.UDRE);
        }

        virtual void
        write(const uint8_t byte)
        {
            while (!is_tx_buffer_empty()) {
            }
            REGS::udr = byte;
        }
    };

}

#include <mcu_usart.h>

#pragma once

#include "interface.hpp"
#include "sfr.hpp"
#include "ubrr.hpp"
#include "types.hpp"

namespace USART {

    template <typename REG>
    struct UCSRA {
        constexpr static u16 address = REG::address;
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
        constexpr static u16 address = REG::address;
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
        constexpr static u16 address = REG::address;
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

    enum class Parity : u8 {
        None,
        Even,
        Odd,
    };

    enum class StopBits : u8 {
        One,
        Two,
    };

    enum class CharacterSize : u8 {
        Bit5,
        Bit6,
        Bit7,
        Bit8,
    };

    enum class Channel : u8 {
        RX,
        TX,
    };

    template <typename HIGH, typename LOW, typename C_REG>
    constexpr static inline void
    set_ubrr_split(const u16 speed)
    {
        /* This bit selects between accessing the UCSRC or the UBRRH Register.
        It is read as one when reading UCSRC.
        The URSEL must be zero when writing the UBRRH. */
        SFR::RegisterRW<C_REG, u8>().clearBit(C_REG::URSEL);
        SFR::RegisterRW<HIGH, u8>() = static_cast<u8>((speed >> 8));
        SFR::RegisterRW<LOW, u8>()  = static_cast<u8>(speed);
    }

    template <typename REG>
    constexpr static inline void
    set_ubrr_single(const u16 speed)
    {
        SFR::RegisterRW<REG, u16>() = speed;
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
        write(const u8 byte)
        {
            while (!is_tx_buffer_empty()) {
            }
            REGS::udr = byte;
        }
    };

}
#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/usart.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/usart.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/usart.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif
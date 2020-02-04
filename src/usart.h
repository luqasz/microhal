#pragma once

#include "sfr.h"

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

    /*
     * Check if calculated UBRR is acceptable based on:
     *      cpu frequency
     *      UBRR
     *      baud
     *      acceptabe error rate
     *      divisor
     * Returns true if error rate is too high, false otherwise.
     * Select valid divisor parameter for U2X.
     * 1 when U2X = 0
     * 2 when U2X = 1
     */
    constexpr bool
    err_check(
        const unsigned long freq,
        const unsigned long ubrr,
        const unsigned long baud,
        const uint8_t       tol = 2,
        const uint8_t       div = 1)
    {
        unsigned long calc  = (16UL / div) * ((ubrr) + 1);
        unsigned long plus  = calc * (100UL * (baud) + (baud) * (tol));
        unsigned long minus = calc * (100UL * (baud) - (baud) * (tol));
        if ((100 * freq) > plus) {
            return true;
        }
        if ((100 * freq) < minus) {
            return true;
        }
        return false;
    }

    /*
     * Calculate UBRR value based on cpu frequency and desired baud rate.
     * Select valid divisor parameter for U2X.
     * 1 when U2X = 0
     * 2 when U2X = 1
     */
    constexpr unsigned long int
    calc_ubrr(const unsigned long freq, const unsigned long baud, const uint8_t divisor)
    {
        unsigned long value = static_cast<unsigned long>(freq + (8UL / divisor) * baud);
        value /= static_cast<unsigned long>((16UL / divisor) * baud);
        return value - 1;
    }

    struct BaudRate {
        const uint16_t ubrr;
        const bool     u2x;
        const bool     is_ok;
    };

    constexpr BaudRate
    calc_baud(const unsigned long int baud, const uint8_t tol = 2)
    {
        // Fisrt calculate with U2X = 0
        const unsigned long ubrr   = calc_ubrr(F_CPU, baud, 1);
        const bool          is_err = err_check(F_CPU, ubrr, baud, tol, 1);
        if (is_err == false) {
            return BaudRate { static_cast<uint16_t>(ubrr), false, true };
        }
        else {
            // Recalculate with U2X = 1
            const unsigned long ubrr   = calc_ubrr(F_CPU, baud, 2);
            const bool          is_err = err_check(F_CPU, ubrr, baud, tol, 2);
            if (is_err == false) {
                return BaudRate { static_cast<uint16_t>(ubrr), true, true };
            }
        }
        return BaudRate { 0, true, false };
    }

    template <unsigned long int baud, uint8_t tol = 2>
    constexpr BaudRate
    get_baud()
    {
        constexpr BaudRate rate = calc_baud(baud, tol);
        static_assert(rate.is_ok, "Calculated error rate too high");
        return rate;
    }

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
    class Async {

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

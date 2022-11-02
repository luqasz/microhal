#pragma once

#include "interface.hpp"
#include "sfr.hpp"
#include "ubrr.hpp"
#include "types.hpp"
#include "iomem.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/avr_usart_common.hpp"
#        include "mcu/atmega32/usart.hpp"
#    elif MCU == atmega328
#        include "mcu/avr_usart_common.hpp"
#        include "mcu/atmega328/usart.hpp"
#    elif MCU == atmega2560
#        include "mcu/avr_usart_common.hpp"
#        include "mcu/atmega2560/usart.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

namespace USART {

    template <typename REGS>
    class Async : public Writer {

        void
        ucsrc_set(const u8 bit, const u8 mask)
        {
            // Handle case when UCSRC and UBRRH addresses are same.
            if constexpr (REGS::ucsrc == REGS::ubrrh) {
                // First read returns UBRRH value, second UCSRC.
                iomem::read<u8>(USART::usart0::ucsrc);
                const u8 value = iomem::read<u8>(USART::usart0::ucsrc);
                // When writing, URSEL bit must be set.
                iomem::write<u8>(REGS::ucsrc, (value & inverted<u8>(mask)) | UCSRC::URSEL | bit);
            }
            else {
                iomem::set_bit<u8>(REGS::ucsrc, bit, mask);
            }
        }

        void
        ucsrc_clear(const u8 bit)
        {
            // Handle case when UCSRC and UBRRH addresses are same.
            if constexpr (REGS::ucsrc == REGS::ubrrh) {
                // First read returns UBRRH value, second UCSRC.
                iomem::read<u8>(USART::usart0::ucsrc);
                const u8 value = iomem::read<u8>(USART::usart0::ucsrc);
                // When writing, URSEL bit must be set.
                iomem::write<u8>(REGS::ucsrc, (value & inverted<u8>(bit)) | UCSRC::URSEL);
            }
            else {
                iomem::clear_bit<u8>(REGS::ucsrc, bit);
            }
        }

    public:
        Async()
        {
            ucsrc_clear(UCSRC::UMSEL0);
        }

        void
        set(const BaudRate baud) const
        {
            if constexpr (REGS::ucsrc == REGS::ubrrh) {
                // The URSEL must be zero when writing to UBRRH.
                // To be extra safe, bitwise & speed with register max allowed value.
                constexpr u16 reg_max = 4095;
                const u16     value   = static_cast<u16>(baud.ubrr & reg_max);
                iomem::write<u8>(REGS::ubrrh, static_cast<u8>(value >> 8));
                iomem::write<u8>(REGS::ubrrl, static_cast<u8>(value));
            }
            else {
                iomem::write<u16>(REGS::ubrrl, baud.ubrr);
            }
            if (baud.u2x) {
                iomem::set_bit<u8>(REGS::ucsra, UCSRA::U2X);
            }
            iomem::clear_bit<u8>(REGS::ucsra, UCSRA::U2X);
        }

        void
        set(const Parity parity)
        {
            constexpr static u8 PARITY_MASK = UCSRC::UPM1 | UCSRC::UPM0;
            ucsrc_set(static_cast<u8>(parity), PARITY_MASK);
        }

        void
        set(const StopBits stb)
        {
            switch (stb) {
                using enum StopBits;
                case One:
                    ucsrc_clear(UCSRC::USBS);
                    break;
                case Two:
                    ucsrc_set(UCSRC::USBS, 0);
                    break;
            }
        }

        void
        set(const CharacterSize chr_size)
        {
            constexpr static u8 CHAR_SIZE_MASK = UCSRC::UCSZ0 | UCSRC::UCSZ1;
            ucsrc_set(static_cast<u8>(chr_size), CHAR_SIZE_MASK);
        }

        void
        enable_rx() const
        {
            iomem::set_bit<u8>(REGS::ucsrb, UCSRB::RXEN);
        }

        void
        enable_tx() const
        {
            iomem::set_bit<u8>(REGS::ucsrb, UCSRB::TXEN);
        }

        void
        disable_rx() const
        {
            iomem::clear_bit<u8>(REGS::ucsrb, UCSRB::RXEN);
        }

        void
        disable_tx() const
        {
            iomem::clear_bit<u8>(REGS::ucsrb, UCSRB::TXEN);
        }

        bool
        rx_ready() const
        {
            return iomem::is_set_bit<u8>(REGS::ucsra, UCSRA::RXC);
        }

        u8
        read()
        {
            while (!rx_ready()) {
            }
            return iomem::read<u8>(REGS::udr);
        }

        bool
        tx_ready() const
        {
            return iomem::is_set_bit<u8>(REGS::ucsra, UCSRA::UDRE);
        }

        virtual void
        write(const u8 byte)
        {
            while (!tx_ready()) {
            }
            iomem::write<u8>(REGS::udr, byte);
        }
    };
}

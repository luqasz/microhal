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

    public:
        Async()
        {
            iomem::set_bit(REGS::ucsrc, UCSRC::UMSEL0);
        }

        void
        set(const BaudRate & baud) const
        {
            REGS::set_ubrr(baud.ubrr, REGS::ubrrh, REGS::ubrrl, REGS::ucsrc);
            if (baud.u2x) {
                iomem::set_bit(REGS::ucsra, UCSRA::U2X);
            }
            iomem::clear_bit(REGS::ucsra, UCSRA::U2X);
        }

        void
        set(const Parity parity)
        {
            constexpr static u8 PARITY_MASK = UCSRC::UPM1 | UCSRC::UPM0;
            iomem::set_bit(REGS::ucsrc, parity, PARITY_MASK);
        }

        void
        set(const StopBits stb)
        {
            switch (stb) {
                using enum StopBits;
                case One:
                    iomem::clear_bit(REGS::ucsrc, UCSRC::USBS);
                    break;
                case Two:
                    iomem::set_bit(REGS::ucsrc, UCSRC::USBS);
                    break;
            }
        }

        void
        set(const CharacterSize chr_size)
        {
            constexpr static u8 CHAR_SIZE_MASK = UCSRC::UCSZ0 | UCSRC::UCSZ1;
            iomem::set_bit(REGS::ucsrc, chr_size, CHAR_SIZE_MASK);
        }

        void
        enable_rx() const
        {
            iomem::set_bit(REGS::ucsrb, UCSRB::RXEN);
        }

        void
        enable_tx() const
        {
            iomem::set_bit(REGS::ucsrb, UCSRB::TXEN);
        }

        void
        disable_rx() const
        {
            iomem::clear_bit(REGS::ucsrb, UCSRB::RXEN);
        }

        void
        disable_tx() const
        {
            iomem::clear_bit(REGS::ucsrb, UCSRB::TXEN);
        }

        bool
        rx_ready() const
        {
            return iomem::is_set_bit(REGS::ucsra, UCSRA::RXC);
        }

        u8
        read()
        {
            while (!rx_ready()) {
            }
            return iomem::read(REGS::udr);
        }

        bool
        tx_ready() const
        {
            return iomem::is_set_bit(REGS::ucsra, UCSRA::UDRE);
        }

        virtual void
        write(const u8 byte)
        {
            while (!tx_ready()) {
            }
            iomem::write(REGS::udr, byte);
        }
    };
}

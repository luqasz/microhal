#pragma once

#include "sfr.hpp"
#include "ubrr.hpp"
#include "types.hpp"
#include "iomem.hpp"

#if MCU_ATMEGA32
#    include "mcu/atmega32/usart.hpp"
#elif MCU_ATMEGA328
#    include "mcu/atmega328/usart.hpp"
#elif MCU_ATMEGA2560
#    include "mcu/atmega2560/usart.hpp"
#else
#    error "Unknown MCU."
#endif

namespace USART {

    struct Config {
        const CharacterSize char_size;
        const Parity        parity;
        const StopBits      stop_bits;
        const UBRR          ubrr;
    };

    template <typename REGS>
    class Async {

        void
        ucsrc_set(const u8 bit, const u8 mask) const
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
        ucsrc_clear(const u8 bit) const
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

        const Async &
        set(const Config cfg) const
        {
            if constexpr (REGS::ucsrc == REGS::ubrrh) {
                // The URSEL must be zero when writing to UBRRH.
                // To be extra safe, bitwise & speed with register max allowed value.
                constexpr u16 reg_max = 4095;
                const u16     value   = static_cast<u16>(cfg.ubrr.value & reg_max);
                iomem::write<u8>(REGS::ubrrh, static_cast<u8>(value >> 8));
                iomem::write<u8>(REGS::ubrrl, static_cast<u8>(value));
            }
            else {
                iomem::write<u16>(REGS::ubrrl, cfg.ubrr.value);
            }
            if (cfg.ubrr.u2x == U2X::on) {
                iomem::set_bit<u8>(REGS::ucsra, UCSRA::U2X);
            }
            else {
                iomem::clear_bit<u8>(REGS::ucsra, UCSRA::U2X);
            }
            constexpr static u8 CHAR_SIZE_MASK = UCSRC::UCSZ0 | UCSRC::UCSZ1;
            constexpr static u8 PARITY_MASK    = UCSRC::UPM1 | UCSRC::UPM0;
            constexpr static u8 STOP_BIT_MASK  = UCSRC::USBS;
            constexpr static u8 MASK           = CHAR_SIZE_MASK | PARITY_MASK | STOP_BIT_MASK;
            const u8            bits           = u8(cfg.char_size) | u8(cfg.stop_bits) | u8(cfg.parity);
            ucsrc_set(bits, MASK);
            return *this;
        }

        const Async &
        enable(const Channel & ch) const
        {
            iomem::set_bit<u8>(REGS::ucsrb, static_cast<u8>(ch));
            return *this;
        }

        const Async &
        disable(const Channel & ch) const
        {
            iomem::clear_bit<u8>(REGS::ucsrb, static_cast<u8>(ch));
            return *this;
        }

        const Async &
        enable(const Irq irq) const
        {
            iomem::set_bit(REGS::ucsrb, static_cast<u8>(irq));
            return *this;
        }

        const Async &
        disable(const Irq irq) const
        {
            iomem::clear_bit(REGS::ucsrb, static_cast<u8>(irq));
            return *this;
        }

        bool
        rx_ready() const
        {
            return iomem::is_set_bit<u8>(REGS::ucsra, UCSRA::RXC);
        }

        u8
        read() const
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

        void
        write(const u8 byte) const
        {
            while (!tx_ready()) {
            }
            iomem::write<u8>(REGS::udr, byte);
        }

        void
        print(const char * string) const
        {
            u8 c;
            while ((c = static_cast<u8>(*string++))) {
                write(c);
            }
        }
    };
}

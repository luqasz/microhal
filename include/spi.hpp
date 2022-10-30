#pragma once

#include "buffer.hpp"
#include "iomem.hpp"
#include "sfr.hpp"
#include "types.hpp"
#include "gpio.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/spi.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/spi.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/spi.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

namespace spi {
    /*
    If SS is configured as an output, the pin is a general output pin which does not affect the SPI system.
    Typically, the pin will be driving the SS pin of the SPI Slave.
    If SS is configured as an input, it must be held high to ensure Master SPI operation.
    If the SS pin is driven low by peripheral circuitry when the SPI is configured as a Master with the SS pin defined as an input, the SPI system interprets this as another master selecting the SPI as a slave and starting to send data to it.
    */

    /*
    In which order bits will be shifted first.
    */
    enum class Order {
        LSB,
        MSB,
    };

    /*
    In which mode shoudl operate in.
    */
    enum class Mode : u8 {
        m0        = 0,                                 // clock polarity=0, clock phase=0
        m1        = SFR::SPCR::CPHA,                   // clock polarity=0, clock phase=1
        m2        = SFR::SPCR::CPOL,                   // clock polarity=1, clock phase=0
        m3        = SFR::SPCR::CPOL | SFR::SPCR::CPHA, // clock polarity=1, clock phase=1
        pol0_pha0 = m0,
        pol0_pha1 = m1,
        pol1_pha0 = m2,
        pol1_pha1 = m3,
    };

    constexpr u8 SPI2X = 0x04;

    enum class MasterClock : u8 {
        _2   = SPI2X,
        _4   = 0,
        _8   = SFR::SPCR::SPR0 | SPI2X,
        _16  = SFR::SPCR::SPR0,
        _32  = SFR::SPCR::SPR1 | SPI2X,
        _64  = SFR::SPCR::SPR1,
        _128 = SFR::SPCR::SPR0 | SFR::SPCR::SPR1,
    };

    struct Target {
        const Order       order;
        const Mode        mode;
        const MasterClock clock;
    };

    template <typename REGS>
    class Master {
    public:
        Master(const gpio::Pin & mosi, const gpio::Pin & miso, const gpio::Pin & sck)
        {
            (gpio::Output(sck));
            (gpio::Input(miso));
            (gpio::Output(mosi));
            iomem::set_bit<u8>(REGS::spcr::address, REGS::spcr::MSTR);
        }

        void
        enable() const
        {
            iomem::set_bit<u8>(REGS::spcr::address, REGS::spcr::SPE);
        }

        void
        disable() const
        {
            iomem::clear_bit<u8>(REGS::spcr::address, REGS::spcr::SPE);
        }

        void
        set(const MasterClock clock) const
        {
            constexpr u8 MASK = REGS::spcr::SPR0 | REGS::spcr::SPR1;
            iomem::set_bit(REGS::spcr::address, static_cast<u8>(clock), MASK);
            if (static_cast<u8>(clock) & SPI2X) {
                iomem::set_bit<u8>(REGS::spsr::address, REGS::spsr::SPI2X);
            }
            else {
                iomem::clear_bit<u8>(REGS::spsr::address, REGS::spsr::SPI2X);
            }
        }

        void
        set(const Order order) const
        {
            switch (order) {
                using enum Order;
                case LSB:
                    iomem::set_bit<u8>(REGS::spcr::address, REGS::spcr::DORD);
                    break;
                case MSB:
                    iomem::clear_bit<u8>(REGS::spcr::address, REGS::spcr::DORD);
                    break;
            }
        }

        void
        set(const Mode mode) const
        {
            constexpr u8 MASK = REGS::spcr::CPHA | REGS::spcr::CPOL;
            iomem::set_bit<u8>(REGS::spcr::address, static_cast<u8>(mode), MASK);
        }

        void
        communicate(u8 & byte, const Target & target) const
        {
            set(target.mode);
            set(target.clock);
            set(target.order);
            iomem::write<u8>(REGS::spdr::address, byte);
            iomem::set_bit_wait<u8>(REGS::spsr::address, REGS::spsr::SPIF); // Wait for transmission complete
            byte = iomem::read<u8>(REGS::spdr::address);
        }

        void
        communicate(buffer::Span<u8> buffer, const Target & target) const
        {
            for (u8 & byte : buffer) {
                communicate(byte, target);
            }
        }
    };
}

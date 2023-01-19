#pragma once

#include "buffer.hpp"
#include "iomem.hpp"
#include "sfr.hpp"
#include "types.hpp"
#include "gpio.hpp"

#if MCU_ATMEGA32
#    include "mcu/atmega32/spi.hpp"
#elif MCU_ATMEGA328
#    include "mcu/atmega328/spi.hpp"
#elif MCU_ATMEGA2560
#    include "mcu/atmega2560/spi.hpp"
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
    enum class Order : u8 {
        LSB = SFR::SPCR::DORD,
        MSB = 0,
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

    // Dummy SPI2X bit. Doesn't point to any bit in order, clock, mode bits.
    constexpr u8 SPI2X = SFR::SPCR::SPIE;

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
        set(const Target & target) const
        {
            constexpr u8 CLOCK_MASK      = REGS::spcr::SPR0 | REGS::spcr::SPR1;
            constexpr u8 MODE_MASK       = REGS::spcr::CPHA | REGS::spcr::CPOL;
            constexpr u8 DATA_ORDER_MASK = REGS::spcr::DORD;
            constexpr u8 MASK            = CLOCK_MASK | MODE_MASK | DATA_ORDER_MASK;
            static_assert(!(MASK & SPI2X), "SPI2X bit can't be inside MASK");
            const u8 reg_value = static_cast<u8>(target.clock) | static_cast<u8>(target.mode) | static_cast<u8>(target.order);
            iomem::set_bit<u8>(REGS::spcr::address, reg_value, MASK);

            if (static_cast<u8>(target.clock) & SPI2X) {
                iomem::set_bit<u8>(REGS::spsr::address, REGS::spsr::SPI2X);
            }
            else {
                iomem::clear_bit<u8>(REGS::spsr::address, REGS::spsr::SPI2X);
            }
        }

        void
        send(u8 & byte, const Target & target) const
        {
            set(target);
            rx_tx(byte);
        }

        void
        send(buffer::Span<u8> buffer, const Target & target) const
        {
            set(target);
            for (u8 & byte : buffer) {
                rx_tx(byte);
            }
        }

    private:
        void
        rx_tx(u8 & byte) const
        {
            iomem::write<u8>(REGS::spdr::address, byte);
            iomem::set_bit_wait<u8>(REGS::spsr::address, REGS::spsr::SPIF); // Wait for transmission complete.
            byte = iomem::read<u8>(REGS::spdr::address);                    // After reading SPDR, SPIF is cleared bu hardware.
        }
    };
}

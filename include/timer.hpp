#pragma once

#include "units.hpp"
#include "types.hpp"
#include "iomem.hpp"
#include "utils.hpp"
#include <timer_equations.hpp>

#if MCU_ATMEGA32
#    include "mcu/atmega32/timer.hpp"
#elif MCU_ATMEGA328
#    include "mcu/atmega328/timer.hpp"
#elif MCU_ATMEGA2560
#    include "mcu/atmega2560/timer.hpp"
#else
#    error "Unknown MCU."
#endif

namespace timer {

    // Capture/ICF irq fired when counter = TOP.
    // Overflow/TOIE irq  fired when counter = MAX.
    template <typename REGS>
    struct CompareMatch {

        using Irq = typename REGS::Irq;
        using Output = typename REGS::Output;
        const typename REGS::CMP compare {};
        const iomem::RegRW<u16> counter = iomem::RegRW<u16>(REGS::tcnt);
        // Not double buffered.
        const iomem::RegRW<u16> top = iomem::RegRW<u16>(REGS::icr);

        enum class Mode {
            Disconnect = 0,
            Toggle = 0b1,
            Low = 0b10,
            High = 0b11,
        };

        CompareMatch()
        {
            iomem::clear_bit<u8>(REGS::tccra, WGM01_MASK);
            iomem::set_bit<u8>(REGS::tccrb, TCCRB::WGM2 | TCCRB::WGM3, WGM23_MASK);
            top = 0;
        }

        ~CompareMatch()
        {
            set(Clock::Stopped);
        }

        const CompareMatch &
        enable(const Irq irq) const
        {
            iomem::set_bit(REGS::timsk, static_cast<u8>(irq));
            return *this;
        }

        const CompareMatch &
        disable(const Irq irq) const
        {
            iomem::clear_bit(REGS::timsk, static_cast<u8>(irq));
            return *this;
        }

        const CompareMatch &
        set(const Clock clk) const
        {
            iomem::set_bit(REGS::tccrb, u8(clk), CLOCK_MASK);
            return *this;
        }

        const CompareMatch &
        set(const TimerConfig & cfg)
        {
            set(cfg.clock);
            top = cfg.top;
            return *this;
        }

        const CompareMatch &
        set(const Output out, const Mode mode) const
        {
            // COM0,COM1 bits.
            constexpr static u8 COM_BITS = 0b11;
            const usize POS = first_lsbit(static_cast<u8>(out));
            const u8 MASK = static_cast<u8>(COM_BITS << POS);
            iomem::set_bit<u8>(REGS::tccra, static_cast<u8>(mode << POS), MASK);
            return *this;
        }
    };

    // Capture/ICF irq fired when counter = TOP.
    // Overflow/TOIE irq fired when counter = TOP.
    template <typename REGS>
    struct PWM {

        using Irq = typename REGS::Irq;
        using Output = typename REGS::Output;
        const typename REGS::CMP compare {};
        const iomem::RegRW<u16> counter = iomem::RegRW<u16>(REGS::tcnt);
        // Not double buffered.
        const iomem::RegRW<u16> top = iomem::RegRW<u16>(REGS::icr);

        enum class Mode {
            Disconnect = 0b00,
            Low = 0b10,
            High = 0b11,
        };

        PWM()
        {
            iomem::set_bit<u8>(REGS::tccra, TCCRA::WGM1, WGM01_MASK);
            iomem::set_bit<u8>(REGS::tccrb, TCCRB::WGM2 | TCCRB::WGM3, WGM23_MASK);
            top = 0;
        }

        ~PWM()
        {
            set(Clock::Stopped);
        }

        const PWM &
        enable(const Irq irq) const
        {
            iomem::set_bit(REGS::timsk, static_cast<u8>(irq));
            return *this;
        }

        const PWM &
        disable(const Irq irq) const
        {
            iomem::clear_bit(REGS::timsk, static_cast<u8>(irq));
            return *this;
        }

        const PWM &
        set(const Clock clk) const
        {
            iomem::set_bit(REGS::tccrb, u8 { clk }, CLOCK_MASK);
            return *this;
        }

        const PWM &
        set(const TimerConfig & cfg) const
        {
            set(cfg.clock);
            top = cfg.top;
            return *this;
        }

        const PWM &
        set(const Output out, const Mode mode) const
        {
            // COM0,COM1 bits.
            constexpr static u8 COM_BITS = 0b11;
            const usize POS = first_lsbit(static_cast<u8>(out));
            const u8 MASK = static_cast<u8>(COM_BITS << POS);
            iomem::set_bit<u8>(REGS::tccra, static_cast<u8>(static_cast<u8>(mode) << POS), MASK);
            return *this;
        }
    };

}

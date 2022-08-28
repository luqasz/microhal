#pragma once

#include "units.hpp"

#include <mcu_timer.hpp>

enum Clock {
    Stopped = 0,
    _1      = TCCRB::CS0,
    _8      = TCCRB::CS1,
    _64     = TCCRB::CS0 | TCCRB::CS1,
    _256    = TCCRB::CS2,
    _1024   = TCCRB::CS0 | TCCRB::CS1 | TCCRB::CS2,
};

constexpr uint8_t CLOCK_MASK = TCCRB::CS0 | TCCRB::CS1 | TCCRB::CS2;

struct Prescaler {
    const uint16_t value;
    const Clock    clock;
};

struct TimerConfig {
    const Clock    clock;
    const uint16_t top;
};

constexpr auto prescaler_1 = Prescaler {
    1,
    Clock::_1,
};
constexpr auto prescaler_8 = Prescaler {
    8,
    Clock::_8,
};
constexpr auto prescaler_64 = Prescaler {
    64,
    Clock::_64,
};
constexpr auto prescaler_256 = Prescaler {
    256,
    Clock::_256,
};
constexpr auto prescaler_1024 = Prescaler {
    1024,
    Clock::_1024,
};

constexpr Prescaler prescalers[] = {
    prescaler_1,
    prescaler_8,
    prescaler_64,
    prescaler_256,
    prescaler_1024,
};

constexpr TimerConfig
getConfig(const Frequency fcpu, const Frequency desired)
{
    for (Prescaler p : prescalers) {
        const Frequency ftimer = (fcpu / p.value);
        const uint32_t  top    = ((ftimer / desired).value - 1);
        if (top < 65536) {
            return TimerConfig {
                p.clock,
                static_cast<uint16_t>(top),
            };
        }
    }
    return TimerConfig {
        Clock::Stopped,
        0,
    };
}

/*
 * Each mode TOP = ICR register.
 */
enum TimerMode {
    CTC          = TCCRB::WGM2 | TCCRB::WGM3,
    PWM          = TCCRA::WGM1 | TCCRB::WGM2 | TCCRB::WGM3,
    CompareMatch = CTC,
};

template <typename REGS>
class Timer : public REGS {

    Clock clock = Stopped;
    using REGS::tccra;
    using REGS::tccrb;
    using REGS::timsk;

public:
    using REGS::compareMatch;
    using REGS::IRQ;
    using REGS::top;

    void
    set(const TimerMode mode) const
    {
        constexpr uint8_t TCCRA_MASK = (TCCRA::WGM0 | TCCRA::WGM1);
        constexpr uint8_t TCCRB_MASK = (TCCRB::WGM2 | TCCRB::WGM3);
        tccra.setBit(mode & TCCRA_MASK, TCCRA_MASK);
        tccrb.setBit(mode & TCCRB_MASK, TCCRB_MASK);
    }

    void
    set(const Frequency desired, const Frequency fcpu)
    {
        auto config = getConfig(fcpu, desired);
        clock       = config.clock;
        top         = config.top;
    }

    void
    set(const TimerConfig config)
    {
        clock = config.clock;
        top   = config.top;
    }

    void
    reset()
    {
        top = 0;
    }

    void
    start()
    {
        tccrb.setBit(clock, CLOCK_MASK);
    }

    void
    stop()
    {
        tccrb.setBit(Stopped, CLOCK_MASK);
    }

    void
    inverting(const typename REGS::Pin pin)
    {
        const uint8_t mode = static_cast<uint8_t>(pin | pin << 1);
        tccra.setBit(mode);
    }

    void
    nonInverting(const typename REGS::Pin pin)
    {
        const uint8_t mode = static_cast<uint8_t>(pin << 1);
        const uint8_t mask = static_cast<uint8_t>(pin | pin >> 1);
        tccra.setBit(mode, mask);
    }

    void
    enable(const typename REGS::IRQ irq) const
    {
        timsk.setBit(irq);
    }

    void
    disable(const typename REGS::IRQ irq) const
    {
        timsk.clearBit(irq);
    }
};

#pragma once

#include <mcu_timer.h>

enum Clock {
    _1    = TCCRB::CS0,
    _8    = TCCRB::CS1,
    _64   = TCCRB::CS0 | TCCRB::CS1,
    _256  = TCCRB::CS2,
    _1024 = TCCRB::CS0 | TCCRB::CS1 | TCCRB::CS2,
};

constexpr uint16_t
clockToPrescaler(const Clock clock)
{
    uint16_t prescaler = 0;
    switch (clock) {
        case Clock::_1:
            prescaler = 1;
            break;
        case Clock::_8:
            prescaler = 8;
            break;
        case Clock::_64:
            prescaler = 64;
            break;
        case Clock::_256:
            prescaler = 256;
            break;
        case Clock::_1024:
            prescaler = 1024;
            break;
    }
    return prescaler;
}

/*
 * Given desired frequency in Hz and clock, return TOP register value.
 */
constexpr uint16_t
frequencyToTop(const unsigned long desired, const Clock clock)
{
    return static_cast<uint16_t>((F_CPU / (desired * clockToPrescaler(clock))) - 1);
}

/*
 * Each mode TOP = ICR register.
 */
enum TimerMode {
    CTC                   = TCCRB::WGM2 | TCCRB::WGM3,
    PWM                   = TCCRA::WGM1 | TCCRB::WGM2 | TCCRB::WGM3,
    CompareMatch          = CTC,
};

template <typename REGS>
class Timer : public REGS {

public:
    using REGS::compareMatch;
    using REGS::IRQ;
    using REGS::tccra;
    using REGS::tccrb;
    using REGS::timsk;
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
    set(const Clock cl)
    {
        constexpr uint8_t CLOCK_MASK = TCCRB::CS0 | TCCRB::CS1 | TCCRB::CS2;
        tccrb.setBit(cl, CLOCK_MASK);
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


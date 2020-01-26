#pragma once

#include <mcu_timer.h>

enum TCCRA : uint8_t {
    WGM0  = 1,
    WGM1  = 2,
    COMB0 = 16,
    COMB1 = 32,
    COMA0 = 64,
    COMA1 = 128,
};

enum TCCRB : uint8_t {
    CS0  = 1,
    CS1  = 2,
    CS2  = 4,
    WGM2 = 8,
    WGM3 = 16,
    ICES = 64,
    ICNC = 128,
};

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
    PFC                   = TCCRB::WGM3,
    PC                    = TCCRA::WGM1 | TCCRB::WGM3,
    CompareMatch          = CTC,
    PhaseFrequencyCorrect = PFC,
    PhaseCorrect          = PC,
};

enum PinMode {
    InvertingA    = TCCRA::COMA1 | TCCRA::COMA0,
    InvertingB    = TCCRA::COMB1 | TCCRA::COMB0,
    NonInvertingA = TCCRA::COMA1,
    NonInvertingB = TCCRA::COMB1,
    ToggleA       = TCCRA::COMA0,
    ToggleB       = TCCRA::COMB0,
};

template <typename REGS>
class Timer {

public:
    void
    setCompareA(const uint16_t value) const
    {
        REGS::OCRA = value;
    }

    void
    setCompareB(const uint16_t value) const
    {
        REGS::OCRB = value;
    }

    void
    setTop(const uint16_t value) const
    {
        REGS::ICR = value;
    }

    uint16_t
    getTop() const
    {
        return REGS::ICR.read();
    }

    void
    set(const TimerMode mode) const
    {
        constexpr uint8_t TCCRA_MASK = (TCCRA::WGM0 | TCCRA::WGM1);
        constexpr uint8_t TCCRB_MASK = (TCCRB::WGM2 | TCCRB::WGM3);
        REGS::TCCRA.setBit(mode & TCCRA_MASK, TCCRA_MASK);
        REGS::TCCRB.setBit(mode & TCCRB_MASK, TCCRB_MASK);
    }

    void
    set(const Clock cl)
    {
        constexpr uint8_t CLOCK_MASK = TCCRB::CS0 | TCCRB::CS1 | TCCRB::CS2;
        REGS::TCCRB.setBit(cl, CLOCK_MASK);
    }

    void
    set(const PinMode mode) const
    {
        constexpr uint8_t PIN_MASK = TCCRA::COMA1 | TCCRA::COMA0 | TCCRA::COMB1 | TCCRA::COMB0;
        REGS::TCCRA.setBit(mode, PIN_MASK);
    }

    void
    enable(const TIRQ irq) const
    {
        REGS::TIMSK.setBit(irq);
    }

    void
    disable(const TIRQ irq) const
    {
        REGS::TIMSK.clearBit(irq);
    }
};


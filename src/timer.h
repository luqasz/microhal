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

enum Clock : uint8_t {
    None  = 0,
    _1    = TCCRB::CS0,
    _8    = TCCRB::CS1,
    _64   = TCCRB::CS0 | TCCRB::CS1,
    _256  = TCCRB::CS2,
    _1024 = TCCRB::CS0 | TCCRB::CS1 | TCCRB::CS2,
};

enum TimerMode {
    CTC = TCCRB::WGM2 | TCCRB::WGM3,               // Compare match. TOP = ICR
    PWM = TCCRA::WGM1 | TCCRB::WGM2 | TCCRB::WGM3, // TOP = ICR
    PFC = TCCRB::WGM3,                             // PWM Phase and Frequency Correct. TOP = ICR
    PC  = TCCRA::WGM1 | TCCRB::WGM3,               // Phase correct. TOP = ICR
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
    set(const Clock clock) const
    {
        REGS::TCCRB.setBit(clock);
    }

    void
    set(const PinMode mode) const
    {
        REGS::TCCRA.setBit(mode);
    }
};


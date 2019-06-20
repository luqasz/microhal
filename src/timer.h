#ifndef timer_h
#define timer_h

#include "sfr.h"
#include MCU_TIMER_HEADER
#include "utils.h"

#include <stdint.h>

namespace Timer0 {

    enum class Clock {
        _1    = CLOCK_REG::CS00,
        _8    = CLOCK_REG::CS01,
        _64   = CLOCK_REG::CS00 | CLOCK_REG::CS01,
        _256  = CLOCK_REG::CS02,
        _1024 = CLOCK_REG::CS00 | CLOCK_REG::CS02,
    };

    enum class Mode {
        Normal  = 0,
        PWM     = WGM_REG::WGM00,
        CTC     = WGM_REG::WGM01,
        FastPWM = WGM_REG::WGM00 | WGM_REG::WGM01,
    };

    enum class Irq {
        OnOverflow     = IRQ_REG::TOIE0,
        OnCompareMatch = IRQ_REG::OCIE0,
    };

    void
    set(Clock clock);

    void
    set(Mode mode);

    uint8_t
    getCounter();

    uint8_t
    getCompareReg();

    void
    enable(Irq irq);

}

#endif

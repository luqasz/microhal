#pragma once

#include "sfr.hpp"
#include "../common/atmega/timer.hpp"

namespace timer {

    struct Timer1 {
        constexpr static usize tccra = SFR::TCCR1A::address;
        constexpr static usize tccrb = SFR::TCCR1B::address;
        constexpr static usize ocra  = SFR::OCR1A::address;
        constexpr static usize ocrb  = SFR::OCR1B::address;
        constexpr static usize icr   = SFR::ICR1::address;
        constexpr static usize timsk = SFR::TIMSK::address;
        constexpr static usize tcnt  = SFR::TCNT1::address;
    };

    enum Output : u8 {
        A = TCCRA::COMA0,
        B = TCCRA::COMB0,
    };

}

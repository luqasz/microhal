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
        constexpr static usize timsk = SFR::TIMSK1::address;
        constexpr static usize tcnt  = SFR::TCNT1::address;
    };

    struct Timer3 {
        constexpr static usize tccra = SFR::TCCR3A::address;
        constexpr static usize tccrb = SFR::TCCR3B::address;
        constexpr static usize ocra  = SFR::OCR3A::address;
        constexpr static usize ocrb  = SFR::OCR3B::address;
        constexpr static usize icr   = SFR::ICR3::address;
        constexpr static usize timsk = SFR::TIMSK3::address;
        constexpr static usize tcnt  = SFR::TCNT3::address;
    };

    struct Timer4 {
        constexpr static usize tccra = SFR::TCCR4A::address;
        constexpr static usize tccrb = SFR::TCCR4B::address;
        constexpr static usize ocra  = SFR::OCR4A::address;
        constexpr static usize ocrb  = SFR::OCR4B::address;
        constexpr static usize icr   = SFR::ICR4::address;
        constexpr static usize timsk = SFR::TIMSK4::address;
        constexpr static usize tcnt  = SFR::TCNT4::address;
    };

    struct Timer5 {
        constexpr static usize tccra = SFR::TCCR5A::address;
        constexpr static usize tccrb = SFR::TCCR5B::address;
        constexpr static usize ocra  = SFR::OCR5A::address;
        constexpr static usize ocrb  = SFR::OCR5B::address;
        constexpr static usize icr   = SFR::ICR5::address;
        constexpr static usize timsk = SFR::TIMSK5::address;
        constexpr static usize tcnt  = SFR::TCNT5::address;
    };

    enum Output {
        A = TCCRA::COMA0,
        B = TCCRA::COMB0,
        C = TCCRA::COMC0,
    };
}

#pragma once

#include "sfr.hpp"
#include "../common/atmega/timer.hpp"

namespace timer {

    struct Timer1 {
        constexpr static u16  tccra = SFR::TCCR1A::address;
        constexpr static u16  tccrb = SFR::TCCR1B::address;
        constexpr static u16  ocra  = SFR::OCR1A::address;
        constexpr static u16  ocrb  = SFR::OCR1B::address;
        constexpr static u16  icr   = SFR::ICR1::address;
        constexpr static auto timsk = SFR::TIMSK1::address;
    };

    struct Timer3 {
        constexpr static u16  tccra = SFR::TCCR3A::address;
        constexpr static u16  tccrb = SFR::TCCR3B::address;
        constexpr static u16  ocra  = SFR::OCR3A::address;
        constexpr static u16  ocrb  = SFR::OCR3B::address;
        constexpr static u16  icr   = SFR::ICR3::address;
        constexpr static auto timsk = SFR::TIMSK3::address;
    };

    struct Timer4 {
        constexpr static u16  tccra = SFR::TCCR4A::address;
        constexpr static u16  tccrb = SFR::TCCR4B::address;
        constexpr static u16  ocra  = SFR::OCR4A::address;
        constexpr static u16  ocrb  = SFR::OCR4B::address;
        constexpr static u16  icr   = SFR::ICR4::address;
        constexpr static auto timsk = SFR::TIMSK4::address;
    };

    struct Timer5 {
        constexpr static u16  tccra = SFR::TCCR5A::address;
        constexpr static u16  tccrb = SFR::TCCR5B::address;
        constexpr static u16  ocra  = SFR::OCR5A::address;
        constexpr static u16  ocrb  = SFR::OCR5B::address;
        constexpr static u16  icr   = SFR::ICR5::address;
        constexpr static auto timsk = SFR::TIMSK5::address;
    };

    enum Output {
        A = TCCRA::COMA0,
        B = TCCRA::COMB0,
        C = TCCRA::COMC0,
    };
}

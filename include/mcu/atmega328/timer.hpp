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

    enum Output : u8 {
        A = TCCRA::COMA0,
        B = TCCRA::COMB0,
    };
}

#pragma once

#include "sfr.hpp"
#include "../common/atmega/timer.hpp"
#include <iomem.hpp>

namespace timer {

    struct Timer1 {
        constexpr static usize tccra = SFR::TCCR1A::address;
        constexpr static usize tccrb = SFR::TCCR1B::address;
        constexpr static usize icr = SFR::ICR1::address;
        constexpr static usize timsk = SFR::TIMSK::address;
        constexpr static usize tcnt = SFR::TCNT1::address;
        struct CMP {
            const iomem::RegRW<u16> a = iomem::RegRW<u16>(SFR::OCR1A::address);
            const iomem::RegRW<u16> b = iomem::RegRW<u16>(SFR::OCR1B::address);
        };
        enum class Irq {
            Overflow = TIMSK::TOIE,
            InputCapture = TIMSK::ICIE,
            CompareMatchA = TIMSK::OCIEA,
            CompareMatchB = TIMSK::OCIEB,
        };
        enum class Output {
            A = TCCRA::COMA0,
            B = TCCRA::COMB0,
        };
    };

}

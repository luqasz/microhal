#pragma once

#include <iomem.hpp>
#include "sfr.hpp"
#include "../common/atmega/timer.hpp"

namespace timer {

    struct Timer0 {
        constexpr static usize tccra = SFR::TCCR0A::address;
        constexpr static usize tccrb = SFR::TCCR0B::address;
        constexpr static usize timsk = SFR::TIMSK0::address;
        constexpr static usize tcnt  = SFR::TCNT0::address;
        struct CMP {
            const iomem::RegRW<u8> a = iomem::RegRW<u8>(SFR::OCR0A::address);
            const iomem::RegRW<u8> b = iomem::RegRW<u8>(SFR::OCR0B::address);
        };
        enum class Irq {
            Overflow      = TIMSK::TOIE,
            CompareMatchA = TIMSK::OCIEA,
            CompareMatchB = TIMSK::OCIEB,
        };
        enum class Output {
            A = TCCRA::COMA0,
            B = TCCRA::COMB0,
        };
    };

    struct Timer2 {
        constexpr static usize tccra = SFR::TCCR2A::address;
        constexpr static usize tccrb = SFR::TCCR2B::address;
        constexpr static usize timsk = SFR::TIMSK2::address;
        constexpr static usize tcnt  = SFR::TCNT2::address;
        struct CMP {
            const iomem::RegRW<u8> a = iomem::RegRW<u8>(SFR::OCR2A::address);
            const iomem::RegRW<u8> b = iomem::RegRW<u8>(SFR::OCR2B::address);
        };
        enum class Irq {
            Overflow      = TIMSK::TOIE,
            CompareMatchA = TIMSK::OCIEA,
            CompareMatchB = TIMSK::OCIEB,
        };
        enum class Output {
            A = TCCRA::COMA0,
            B = TCCRA::COMB0,
        };
    };

    struct Timer1 {
        constexpr static usize tccra = SFR::TCCR1A::address;
        constexpr static usize tccrb = SFR::TCCR1B::address;
        constexpr static usize icr   = SFR::ICR1::address;
        constexpr static usize timsk = SFR::TIMSK1::address;
        constexpr static usize tcnt  = SFR::TCNT1::address;
        struct CMP {
            const iomem::RegRW<u16> a = iomem::RegRW<u16>(SFR::OCR1A::address);
            const iomem::RegRW<u16> b = iomem::RegRW<u16>(SFR::OCR1B::address);
            const iomem::RegRW<u16> c = iomem::RegRW<u16>(SFR::OCR1C::address);
        };
        enum class Irq {
            Overflow      = TIMSK::TOIE,
            InputCapture  = TIMSK::ICIE,
            CompareMatchA = TIMSK::OCIEA,
            CompareMatchB = TIMSK::OCIEB,
            CompareMatchC = TIMSK::OCIEC,
        };
        enum class Output {
            A = TCCRA::COMA0,
            B = TCCRA::COMB0,
            C = TCCRA::COMC0,
        };
    };

    struct Timer3 {
        constexpr static usize tccra = SFR::TCCR3A::address;
        constexpr static usize tccrb = SFR::TCCR3B::address;
        constexpr static usize icr   = SFR::ICR3::address;
        constexpr static usize timsk = SFR::TIMSK3::address;
        constexpr static usize tcnt  = SFR::TCNT3::address;
        struct CMP {
            const iomem::RegRW<u16> a = iomem::RegRW<u16>(SFR::OCR3A::address);
            const iomem::RegRW<u16> b = iomem::RegRW<u16>(SFR::OCR3B::address);
            const iomem::RegRW<u16> c = iomem::RegRW<u16>(SFR::OCR3C::address);
        };
        enum class Irq {
            Overflow      = TIMSK::TOIE,
            InputCapture  = TIMSK::ICIE,
            CompareMatchA = TIMSK::OCIEA,
            CompareMatchB = TIMSK::OCIEB,
            CompareMatchC = TIMSK::OCIEC,
        };
        enum class Output {
            A = TCCRA::COMA0,
            B = TCCRA::COMB0,
            C = TCCRA::COMC0,
        };
    };

    struct Timer4 {
        constexpr static usize tccra = SFR::TCCR4A::address;
        constexpr static usize tccrb = SFR::TCCR4B::address;
        constexpr static usize icr   = SFR::ICR4::address;
        constexpr static usize timsk = SFR::TIMSK4::address;
        constexpr static usize tcnt  = SFR::TCNT4::address;
        struct CMP {
            const iomem::RegRW<u16> a = iomem::RegRW<u16>(SFR::OCR4A::address);
            const iomem::RegRW<u16> b = iomem::RegRW<u16>(SFR::OCR4B::address);
            const iomem::RegRW<u16> c = iomem::RegRW<u16>(SFR::OCR4C::address);
        };
        enum class Irq {
            Overflow      = TIMSK::TOIE,
            InputCapture  = TIMSK::ICIE,
            CompareMatchA = TIMSK::OCIEA,
            CompareMatchB = TIMSK::OCIEB,
            CompareMatchC = TIMSK::OCIEC,
        };
        enum class Output {
            A = TCCRA::COMA0,
            B = TCCRA::COMB0,
            C = TCCRA::COMC0,
        };
    };

    struct Timer5 {
        constexpr static usize tccra = SFR::TCCR5A::address;
        constexpr static usize tccrb = SFR::TCCR5B::address;
        constexpr static usize icr   = SFR::ICR5::address;
        constexpr static usize timsk = SFR::TIMSK5::address;
        constexpr static usize tcnt  = SFR::TCNT5::address;
        struct CMP {
            const iomem::RegRW<u16> a = iomem::RegRW<u16>(SFR::OCR5A::address);
            const iomem::RegRW<u16> b = iomem::RegRW<u16>(SFR::OCR5B::address);
            const iomem::RegRW<u16> c = iomem::RegRW<u16>(SFR::OCR5C::address);
        };
        enum class Irq {
            Overflow      = TIMSK::TOIE,
            InputCapture  = TIMSK::ICIE,
            CompareMatchA = TIMSK::OCIEA,
            CompareMatchB = TIMSK::OCIEB,
            CompareMatchC = TIMSK::OCIEC,
        };
        enum class Output {
            A = TCCRA::COMA0,
            B = TCCRA::COMB0,
            C = TCCRA::COMC0,
        };
    };
}

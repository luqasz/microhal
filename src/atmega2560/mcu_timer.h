#pragma once

#include "mcu_sfr.h"

struct Timer1 {
    constexpr static auto TCCRA = SFR::RegisterRW<SFR::TCCR1A, uint8_t>();
    constexpr static auto TCCRB = SFR::RegisterRW<SFR::TCCR1B, uint8_t>();
    constexpr static auto TIMSK = SFR::RegisterRW<SFR::TIMSK1, uint8_t>();
    constexpr static auto top   = SFR::RegisterRW<SFR::ICR1, uint16_t>();
    const static struct _ {
        constexpr static auto A = SFR::RegisterRW<SFR::OCR1A, uint16_t>();
        constexpr static auto B = SFR::RegisterRW<SFR::OCR1B, uint16_t>();
        constexpr static auto C = SFR::RegisterRW<SFR::OCR1C, uint16_t>();
    } compareMatch;
};

struct Timer3 {
    constexpr static auto TCCRA = SFR::RegisterRW<SFR::TCCR3A, uint8_t>();
    constexpr static auto TCCRB = SFR::RegisterRW<SFR::TCCR3B, uint8_t>();
    constexpr static auto TIMSK = SFR::RegisterRW<SFR::TIMSK3, uint8_t>();
    constexpr static auto top   = SFR::RegisterRW<SFR::ICR3, uint16_t>();
    const struct _ {
        constexpr static auto A = SFR::RegisterRW<SFR::OCR3A, uint16_t>();
        constexpr static auto B = SFR::RegisterRW<SFR::OCR3B, uint16_t>();
        constexpr static auto C = SFR::RegisterRW<SFR::OCR3C, uint16_t>();
    } compareMatch;
};

struct Timer4 {
    constexpr static auto TCCRA = SFR::RegisterRW<SFR::TCCR4A, uint8_t>();
    constexpr static auto TCCRB = SFR::RegisterRW<SFR::TCCR4B, uint8_t>();
    constexpr static auto TIMSK = SFR::RegisterRW<SFR::TIMSK4, uint8_t>();
    constexpr static auto top   = SFR::RegisterRW<SFR::ICR4, uint16_t>();
    const struct _ {
        constexpr static auto A = SFR::RegisterRW<SFR::OCR4A, uint16_t>();
        constexpr static auto B = SFR::RegisterRW<SFR::OCR4B, uint16_t>();
        constexpr static auto C = SFR::RegisterRW<SFR::OCR4C, uint16_t>();
    }compareMatch ;
};

struct Timer5 {
    constexpr static auto TCCRA = SFR::RegisterRW<SFR::TCCR5A, uint8_t>();
    constexpr static auto TCCRB = SFR::RegisterRW<SFR::TCCR5B, uint8_t>();
    constexpr static auto TIMSK = SFR::RegisterRW<SFR::TIMSK5, uint8_t>();
    constexpr static auto top   = SFR::RegisterRW<SFR::ICR5, uint16_t>();
    const struct _{
        constexpr static auto A = SFR::RegisterRW<SFR::OCR5A, uint16_t>();
        constexpr static auto B = SFR::RegisterRW<SFR::OCR5B, uint16_t>();
        constexpr static auto C = SFR::RegisterRW<SFR::OCR5C, uint16_t>();
    }compareMatch ;
};

enum TIRQ {
    Overflow = 0,
    CompareA = 2,
    CompareB = 4,
    CompareC = 8,
};


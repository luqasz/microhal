#pragma once

#include "mcu_sfr.h"

struct Timer1 {
    constexpr static auto TCCRA = SFR::RegisterRW<SFR::TCCR1A, uint8_t>();
    constexpr static auto TCCRB = SFR::RegisterRW<SFR::TCCR1B, uint8_t>();
    constexpr static auto TIMSK = SFR::RegisterRW<SFR::TIMSK, uint8_t>();
    constexpr static auto ICR   = SFR::RegisterRW<SFR::ICR1, uint16_t>();
    constexpr static auto OCRA  = SFR::RegisterRW<SFR::OCR1A, uint16_t>();
    constexpr static auto OCRB  = SFR::RegisterRW<SFR::OCR1B, uint16_t>();
};

enum TIRQ {
    Overflow = 4,
    CompareA = 16,
    CompareB = 8,
};


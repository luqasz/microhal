#pragma once

#include "mcu_sfr.h"

struct Timer1 {
    constexpr static auto TCCRA = SFR::BitRegisterRW<SFR::TCCR1A, uint8_t>();
    constexpr static auto TCCRB = SFR::BitRegisterRW<SFR::TCCR1B, uint8_t>();
    constexpr static auto TIMSK = SFR::BitRegisterRW<SFR::TIMSK, uint8_t>();
    constexpr static auto ICR   = SFR::DataRegisterRW<SFR::ICR1, uint16_t>();
    constexpr static auto OCRA  = SFR::DataRegisterRW<SFR::OCR1A, uint16_t>();
    constexpr static auto OCRB  = SFR::DataRegisterRW<SFR::OCR1B, uint16_t>();
};


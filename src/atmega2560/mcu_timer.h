#pragma once

#include "mcu_sfr.h"

struct Timer1 {
    constexpr static auto TCCRA = SFR::BitRegisterRW<SFR::TCCR1A, uint8_t>();
    constexpr static auto TCCRB = SFR::BitRegisterRW<SFR::TCCR1B, uint8_t>();
    constexpr static auto TIMSK = SFR::BitRegisterRW<SFR::TIMSK1, uint8_t>();
    constexpr static auto ICR   = SFR::DataRegisterRW<SFR::ICR1, uint16_t>();
    constexpr static auto OCRA  = SFR::DataRegisterRW<SFR::OCR1A, uint16_t>();
    constexpr static auto OCRB  = SFR::DataRegisterRW<SFR::OCR1B, uint16_t>();
};

struct Timer3 {
    constexpr static auto TCCRA = SFR::BitRegisterRW<SFR::TCCR3A, uint8_t>();
    constexpr static auto TCCRB = SFR::BitRegisterRW<SFR::TCCR3B, uint8_t>();
    constexpr static auto TIMSK = SFR::BitRegisterRW<SFR::TIMSK3, uint8_t>();
    constexpr static auto ICR   = SFR::DataRegisterRW<SFR::ICR3, uint16_t>();
    constexpr static auto OCRA  = SFR::DataRegisterRW<SFR::OCR3A, uint16_t>();
    constexpr static auto OCRB  = SFR::DataRegisterRW<SFR::OCR3B, uint16_t>();
};
struct Timer4 {
    constexpr static auto TCCRA = SFR::BitRegisterRW<SFR::TCCR4A, uint8_t>();
    constexpr static auto TCCRB = SFR::BitRegisterRW<SFR::TCCR4B, uint8_t>();
    constexpr static auto TIMSK = SFR::BitRegisterRW<SFR::TIMSK4, uint8_t>();
    constexpr static auto ICR   = SFR::DataRegisterRW<SFR::ICR4, uint16_t>();
    constexpr static auto OCRA  = SFR::DataRegisterRW<SFR::OCR4A, uint16_t>();
    constexpr static auto OCRB  = SFR::DataRegisterRW<SFR::OCR4B, uint16_t>();
};
struct Timer5 {
    constexpr static auto TCCRA = SFR::BitRegisterRW<SFR::TCCR5A, uint8_t>();
    constexpr static auto TCCRB = SFR::BitRegisterRW<SFR::TCCR5B, uint8_t>();
    constexpr static auto TIMSK = SFR::BitRegisterRW<SFR::TIMSK5, uint8_t>();
    constexpr static auto ICR   = SFR::DataRegisterRW<SFR::ICR5, uint16_t>();
    constexpr static auto OCRA  = SFR::DataRegisterRW<SFR::OCR5A, uint16_t>();
    constexpr static auto OCRB  = SFR::DataRegisterRW<SFR::OCR5B, uint16_t>();
};


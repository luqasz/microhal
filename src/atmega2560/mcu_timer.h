#pragma once

#include "mcu_sfr.h"

enum TCCRA : uint8_t {
    WGM0  = 1,
    WGM1  = 2,
    COMC0 = 4,
    COMC1 = 8,
    COMB0 = 16,
    COMB1 = 32,
    COMA0 = 64,
    COMA1 = 128,
};

enum TCCRB : uint8_t {
    CS0  = 1,
    CS1  = 2,
    CS2  = 4,
    WGM2 = 8,
    WGM3 = 16,
    ICES = 64,
    ICNC = 128,
};

enum TIMSK : uint8_t {
    TOIE  = 1,
    OCIEA = 2,
    OCIEB = 4,
    OCIEC = 8,
};

struct T16_IRQ {
    enum IRQ {
        Overflow = TIMSK::TOIE,
        CompareA = TIMSK::OCIEA,
        CompareB = TIMSK::OCIEB,
        CompareC = TIMSK::OCIEC,
    };
};

struct T16_PIN {
    enum Pin {
        PinA = TCCRA::COMA0,
        PinB = TCCRA::COMB0,
        PinC = TCCRA::COMC0,
    };
};

struct Timer1 : T16_IRQ, T16_PIN {
    constexpr static auto tccra = SFR::RegisterRW<SFR::TCCR1A, uint8_t>();
    constexpr static auto tccrb = SFR::RegisterRW<SFR::TCCR1B, uint8_t>();
    constexpr static auto timsk = SFR::RegisterRW<SFR::TIMSK1, uint8_t>();
    constexpr static auto top   = SFR::RegisterRW<SFR::ICR1, uint16_t>();
    const static struct _ {
        constexpr static auto A = SFR::RegisterRW<SFR::OCR1A, uint16_t>();
        constexpr static auto B = SFR::RegisterRW<SFR::OCR1B, uint16_t>();
        constexpr static auto C = SFR::RegisterRW<SFR::OCR1C, uint16_t>();
    } compareMatch;
};

struct Timer3 : T16_IRQ, T16_PIN {
    constexpr static auto tccra = SFR::RegisterRW<SFR::TCCR3A, uint8_t>();
    constexpr static auto tccrb = SFR::RegisterRW<SFR::TCCR3B, uint8_t>();
    constexpr static auto timsk = SFR::RegisterRW<SFR::TIMSK3, uint8_t>();
    constexpr static auto top   = SFR::RegisterRW<SFR::ICR3, uint16_t>();
    const struct _ {
        constexpr static auto A = SFR::RegisterRW<SFR::OCR3A, uint16_t>();
        constexpr static auto B = SFR::RegisterRW<SFR::OCR3B, uint16_t>();
        constexpr static auto C = SFR::RegisterRW<SFR::OCR3C, uint16_t>();
    } compareMatch;
};

struct Timer4 : T16_IRQ, T16_PIN {
    constexpr static auto tccra = SFR::RegisterRW<SFR::TCCR4A, uint8_t>();
    constexpr static auto tccrb = SFR::RegisterRW<SFR::TCCR4B, uint8_t>();
    constexpr static auto timsk = SFR::RegisterRW<SFR::TIMSK4, uint8_t>();
    constexpr static auto top   = SFR::RegisterRW<SFR::ICR4, uint16_t>();
    const struct _ {
        constexpr static auto A = SFR::RegisterRW<SFR::OCR4A, uint16_t>();
        constexpr static auto B = SFR::RegisterRW<SFR::OCR4B, uint16_t>();
        constexpr static auto C = SFR::RegisterRW<SFR::OCR4C, uint16_t>();
    } compareMatch;
};

struct Timer5 : T16_IRQ, T16_PIN {
    constexpr static auto tccra = SFR::RegisterRW<SFR::TCCR5A, uint8_t>();
    constexpr static auto tccrb = SFR::RegisterRW<SFR::TCCR5B, uint8_t>();
    constexpr static auto timsk = SFR::RegisterRW<SFR::TIMSK5, uint8_t>();
    constexpr static auto top   = SFR::RegisterRW<SFR::ICR5, uint16_t>();
    const struct _ {
        constexpr static auto A = SFR::RegisterRW<SFR::OCR5A, uint16_t>();
        constexpr static auto B = SFR::RegisterRW<SFR::OCR5B, uint16_t>();
        constexpr static auto C = SFR::RegisterRW<SFR::OCR5C, uint16_t>();
    } compareMatch;
};


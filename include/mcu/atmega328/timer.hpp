#pragma once

#include "sfr.hpp"

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
};

struct T16_IRQ {
    enum IRQ {
        Overflow = TIMSK::TOIE,
        CompareA = TIMSK::OCIEA,
        CompareB = TIMSK::OCIEB,
    };
};

struct T16_PIN {
    enum Pin {
        PinA = TCCRA::COMA0,
        PinB = TCCRA::COMB0,
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
    } compareMatch;
};

#pragma once
#include "../gpio.h"
#include "../sfr.h"

namespace SPI {

    struct SPI0 {
        constexpr static auto SPCR = SFR::RegisterRW<SFR::SPCR, uint8_t>();
        constexpr static auto SPSR = SFR::RegisterRW<SFR::SPSR, uint8_t>();
        constexpr static auto SPDR = SFR::RegisterRW<SFR::SPDR, uint8_t>();
    };

    const auto SS   = GPIO::PB4;
    const auto MOSI = GPIO::PB5;
    const auto MISO = GPIO::PB6;
    const auto SCK  = GPIO::PB7;
}

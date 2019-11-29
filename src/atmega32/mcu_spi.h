#pragma once
#include "../gpio.h"
#include "../sfr.h"

namespace SPI {

    struct SPI0 {
        constexpr static auto SPCR = Register<SFR::SPCR>();
        constexpr static auto SPSR = Register<SFR::SPSR>();
        constexpr static auto SPDR = SFR::DataRegisterRW<SFR::SPDR, uint8_t>();
    };

    const auto SS   = GPIO::PB4;
    const auto MOSI = GPIO::PB5;
    const auto MISO = GPIO::PB6;
    const auto SCK  = GPIO::PB7;
}

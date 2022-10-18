#pragma once
#include "../../gpio.hpp"
#include "../../sfr.hpp"

namespace SPI {

    enum class Instance {
        SPI0,
    };

    const auto SPI0_SS   = GPIO::PB4;
    const auto SPI0_MOSI = GPIO::PB5;
    const auto SPI0_MISO = GPIO::PB6;
    const auto SPI0_SCK  = GPIO::PB7;
}

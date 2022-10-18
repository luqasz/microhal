#pragma once
#include "../../gpio.hpp"
#include "../../sfr.hpp"

namespace spi {

    enum class Instance {
        SPI0,
    };

    const auto SPI0_SS   = gpio::PB4;
    const auto SPI0_MOSI = gpio::PB5;
    const auto SPI0_MISO = gpio::PB6;
    const auto SPI0_SCK  = gpio::PB7;
}

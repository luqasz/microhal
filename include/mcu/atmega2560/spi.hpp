#pragma once
#include "sfr.hpp"

namespace spi {
    struct spi0 {
        using spcr = SFR::SPCR;
        using spsr = SFR::SPSR;
        using spdr = SFR::SPDR;
    };

}

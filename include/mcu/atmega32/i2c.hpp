#pragma once

#include "sfr.hpp"
#include "../../types.hpp"

namespace i2c {
    struct i2c0 {
        using twcr = SFR::TWCR;
        using twbr = SFR::TWBR;
        using twdr = SFR::TWDR;

        constexpr static u8 ACK  = twcr::TWEA;
        constexpr static u8 NACK = 0;
    };
}
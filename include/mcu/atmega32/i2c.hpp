#pragma once

namespace I2C {
    auto TWCR = SFR::RegisterRW<SFR::TWCR, uint8_t>();
    auto TWBR = SFR::RegisterRW<SFR::TWBR, uint8_t>();
    auto TWDR = SFR::RegisterRW<SFR::TWDR, uint8_t>();
}
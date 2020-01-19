#pragma once

namespace PinIRQ {

    struct INT0 {
        static constexpr auto    EDGE_REG       = SFR::RegisterRW<SFR::MCUCR, uint8_t>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC00;
        static constexpr auto    ENABLE_REG     = SFR::RegisterRW<SFR::GICR, uint8_t>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT0;
    };

    struct INT1 {
        static constexpr auto    EDGE_REG       = SFR::RegisterRW<SFR::MCUCR, uint8_t>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC10;
        static constexpr auto    ENABLE_REG     = SFR::RegisterRW<SFR::GICR, uint8_t>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT1;
    };
}


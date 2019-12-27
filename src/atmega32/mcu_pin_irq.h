#pragma once

namespace PinIRQ {

    struct INT0 {
        static constexpr auto    EDGE_REG       = Register<SFR::MCUCR>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC00;
        static constexpr auto    ENABLE_REG     = Register<SFR::GICR>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT0;
        static constexpr uint8_t MASK           = inverted<uint8_t>(EDGE_REG.ISC01 | EDGE_REG.ISC00);
    };

    struct INT1 {
        static constexpr auto    EDGE_REG       = Register<SFR::MCUCR>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC10;
        static constexpr auto    ENABLE_REG     = Register<SFR::GICR>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT1;
        static constexpr uint8_t MASK           = inverted<uint8_t>(EDGE_REG.ISC11 | EDGE_REG.ISC10);
    };
}

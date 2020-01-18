#pragma once

namespace PinIRQ {

    struct INT0 {
        static constexpr auto    EDGE_REG       = Register<SFR::EICRA>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC00;
        static constexpr auto    ENABLE_REG     = Register<SFR::EIMSK>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT0;
        static constexpr uint8_t MASK           = EDGE_REG.ISC01 | EDGE_REG.ISC00;
    };

    struct INT1 {
        static constexpr auto    EDGE_REG       = Register<SFR::EICRA>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC10;
        static constexpr auto    ENABLE_REG     = Register<SFR::EIMSK>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT1;
        static constexpr uint8_t MASK           = EDGE_REG.ISC11 | EDGE_REG.ISC10;
    };

    struct INT2 {
        static constexpr auto    EDGE_REG       = Register<SFR::EICRA>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC20;
        static constexpr auto    ENABLE_REG     = Register<SFR::EIMSK>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT2;
        static constexpr uint8_t MASK           = EDGE_REG.ISC21 | EDGE_REG.ISC20;
    };

    struct INT3 {
        static constexpr auto    EDGE_REG       = Register<SFR::EICRA>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC30;
        static constexpr auto    ENABLE_REG     = Register<SFR::EIMSK>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT3;
        static constexpr uint8_t MASK           = EDGE_REG.ISC31 | EDGE_REG.ISC30;
    };

    struct INT4 {
        static constexpr auto    EDGE_REG       = Register<SFR::EICRB>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC40;
        static constexpr auto    ENABLE_REG     = Register<SFR::EIMSK>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT4;
        static constexpr uint8_t MASK           = EDGE_REG.ISC41 | EDGE_REG.ISC40;
    };

    struct INT5 {
        static constexpr auto    EDGE_REG       = Register<SFR::EICRB>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC50;
        static constexpr auto    ENABLE_REG     = Register<SFR::EIMSK>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT5;
        static constexpr uint8_t MASK           = EDGE_REG.ISC51 | EDGE_REG.ISC50;
    };

    struct INT6 {
        static constexpr auto    EDGE_REG       = Register<SFR::EICRB>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC60;
        static constexpr auto    ENABLE_REG     = Register<SFR::EIMSK>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT6;
        static constexpr uint8_t MASK           = EDGE_REG.ISC61 | EDGE_REG.ISC60;
    };

    struct INT7 {
        static constexpr auto    EDGE_REG       = Register<SFR::EICRB>();
        static constexpr uint8_t EDGE_REG_BIT   = EDGE_REG.ISC70;
        static constexpr auto    ENABLE_REG     = Register<SFR::EIMSK>();
        static constexpr uint8_t ENABLE_REG_BIT = ENABLE_REG.INT7;
        static constexpr uint8_t MASK           = EDGE_REG.ISC71 | EDGE_REG.ISC70;
    };
}

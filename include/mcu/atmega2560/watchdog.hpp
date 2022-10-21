#pragma once
#include "sfr.hpp"
#include "../../iomem.hpp"

namespace watchdog {

    using WDT            = SFR::WDTCSR;
    using MCUS           = SFR::MCUSR;
    constexpr u8 DISABLE = WDT::WDTCE | WDT::WDE;
    constexpr u8 ENABLE  = WDT::WDTCE | WDT::WDE;

    enum Clock : uint8_t {
        ms16  = 0,
        ms32  = WDT::WDP0,
        ms64  = WDT::WDP1,
        ms120 = WDT::WDP0 | WDT::WDP1,
        ms250 = WDT::WDP2,
        ms500 = WDT::WDP2 | WDT::WDP0,
        s1    = WDT::WDP2 | WDT::WDP1,
        s2    = WDT::WDP2 | WDT::WDP0 | WDT::WDP1,
        s4    = WDT::WDP3,
        s8    = WDT::WDP3 | WDT::WDP0,
    };

}

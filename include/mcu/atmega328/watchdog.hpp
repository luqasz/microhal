#pragma once
#include "sfr.hpp"

namespace watchdog {

    using WDT            = SFR::WDTCSR;
    using MCUS           = SFR::MCUSR;
    constexpr u8 DISABLE = WDT::WDCE | WDT::WDE;
    constexpr u8 ENABLE  = WDT::WDCE | WDT::WDE;

    enum Clock : uint8_t {
        ms15  = 0,
        ms30  = WDT::WDP0,
        ms60  = WDT::WDP1,
        ms120 = WDT::WDP0 | WDT::WDP1,
        ms250 = WDT::WDP2,
        ms500 = WDT::WDP2 | WDT::WDP0,
        s1    = WDT::WDP2 | WDT::WDP1,
        s2    = WDT::WDP2 | WDT::WDP0 | WDT::WDP1,
        s4    = WDT::WDP3,
        s8    = WDT::WDP3 | WDT::WDP0,
    };

}

#include "../common/atmega/watchdog.hpp"
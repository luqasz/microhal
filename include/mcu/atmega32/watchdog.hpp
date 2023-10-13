#pragma once

#include "sfr.hpp"
#include "../../iomem.hpp"

namespace watchdog {

    using WDT = SFR::WDTCR;
    using MCUS = SFR::MCUCSR;
    constexpr u8 DISABLE = WDT::WDTOE | WDT::WDE;
    constexpr u8 ENABLE = WDT::WDE;

    enum class Clock : u8 {
        ms15 = 0,
        ms30 = WDT::WDP0,
        ms60 = WDT::WDP1,
        ms120 = WDT::WDP0 | WDT::WDP1,
        ms250 = WDT::WDP2,
        ms500 = WDT::WDP2 | WDT::WDP0,
        s1 = WDT::WDP2 | WDT::WDP1,
        s2 = WDT::WDP2 | WDT::WDP0 | WDT::WDP1,
    };
}

#include "../common/atmega/watchdog.hpp"
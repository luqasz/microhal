#pragma once
#include "../sfr.hpp"

namespace Watchdog {

    constexpr auto    wdt     = SFR::RegisterRW<SFR::WDTCR, uint8_t>();
    constexpr auto    status  = SFR::RegisterRW<SFR::MCUCSR, uint8_t>();
    constexpr uint8_t DISABLE = wdt.WDTOE | wdt.WDE;
    constexpr uint8_t CHANGE  = wdt.WDTOE;

    enum Clock : uint8_t {
        ms16  = 0,
        ms32  = wdt.WDP0,
        ms64  = wdt.WDP1,
        ms120 = wdt.WDP0 | wdt.WDP1,
        ms250 = wdt.WDP2,
        ms500 = wdt.WDP2 | wdt.WDP0,
        s1    = wdt.WDP2 | wdt.WDP1,
        s2    = wdt.WDP2 | wdt.WDP0 | wdt.WDP1,
    };

    enum Mode : uint8_t {
        Reset = wdt.WDE,
    };

}

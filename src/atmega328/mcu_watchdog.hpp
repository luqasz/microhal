#pragma once
#include "../sfr.hpp"

namespace Watchdog {

    constexpr auto    wdt     = SFR::RegisterRW<SFR::WDTCSR, uint8_t>();
    constexpr auto    status  = SFR::RegisterRW<SFR::MCUSR, uint8_t>();
    constexpr uint8_t DISABLE = wdt.WDCE | wdt.WDE;
    constexpr uint8_t CHANGE  = wdt.WDCE;

    enum Clock : uint8_t {
        ms16  = 0,
        ms32  = wdt.WDP0,
        ms64  = wdt.WDP1,
        ms120 = wdt.WDP0 | wdt.WDP1,
        ms250 = wdt.WDP2,
        ms500 = wdt.WDP2 | wdt.WDP0,
        s1    = wdt.WDP2 | wdt.WDP1,
        s2    = wdt.WDP2 | wdt.WDP0 | wdt.WDP1,
        s4    = wdt.WDP3,
        s8    = wdt.WDP3 | wdt.WDP0,
    };

    enum Mode : uint8_t {
        Reset             = wdt.WDE,
        Interrupt         = wdt.WDIE,
        InterruptAndReset = wdt.WDIE | wdt.WDE,
    };

}

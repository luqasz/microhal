#pragma once

#include "sfr.hpp"

#include <mcu_watchdog.hpp>
#include <stdint.h>

namespace Watchdog {

    void inline reset()
    {
        asm("wdr");
    }

    void
    disable()
    {
        reset();
        status.clearBit(status.WDRF);
        wdt.setBit(DISABLE);
        wdt = 0x00;
    }

    void
    enable(const Clock clock, const Mode mode)
    {
        status.clearBit(status.WDRF);
        // Start proceduee.
        wdt.setBit(CHANGE | wdt.WDE);
        // Set prescaler and enable watchdog.
        // This operation must be a write operation,
        // since watchdog change bit can't be set.
        wdt.write(mode | clock | wdt.WDE);
    }

}

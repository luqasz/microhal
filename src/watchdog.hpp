#pragma once

#include "sfr.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "atmega32/mcu_watchdog.hpp"
#    elif MCU == atmega328
#        include "atmega328/mcu_watchdog.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif
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

#pragma once

#include "../types.hpp"
#include "../iomem.hpp"

namespace watchdog {

    [[gnu::always_inline]] static inline void
    reset()
    {
        asm("wdr");
    }

    [[gnu::always_inline]] static inline void
    disable()
    {
        reset();
        iomem::clear_bit<u8>(MCUS::address, MCUS::WDRF);
        iomem::set_bit<u8>(WDT::address, DISABLE);
        iomem::write<u8>(WDT::address, 0);
    }

    [[gnu::always_inline]] static inline void
    enable(const Clock clock)
    {
        reset();
        // clear reset flag
        iomem::clear_bit<u8>(MCUS::address, MCUS::WDRF);
        // Start proceduee.
        iomem::set_bit<u8>(WDT::address, ENABLE);
        // Set prescaler and enable watchdog.
        // This operation must be a write operation,
        // since watchdog change bit can't be set.
        iomem::write<u8>(WDT::address, static_cast<u8>(clock) | static_cast<u8>(WDT::WDE));
    }
}

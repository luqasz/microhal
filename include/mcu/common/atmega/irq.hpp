#pragma once

#include "../../../types.hpp"
#include "../../../iomem.hpp"
#include "../../../sfr.hpp"

#define VECTOR(vector) __asm__(vector) __attribute__((signal, used, externally_visible))

namespace irq {

    /* Vector executed when an IRQ fires with no accompanying handler. This
    may be used to create a catch-all for undefined but used IRQs for debugging purposes.
    */
    struct Default {
        static void
        handler() VECTOR("__vector_default");
    };

    static inline void
    global_enable()
    {
        asm volatile("sei" ::: "memory");
    }

    static inline void
    global_disable()
    {
        asm volatile("cli" ::: "memory");
    }

    class AtomicRestore {
        const u8 sreg_value;

    public:
        inline AtomicRestore() :
            sreg_value(iomem::read<u8>(SFR::SREG::address))
        {
            global_disable();
        }

        inline ~AtomicRestore()
        {
            iomem::write(SFR::SREG::address, sreg_value);
            asm volatile("" ::: "memory");
        }
    };
}

#ifndef irq_h
#define irq_h

#include "sfr.h"

#define VECTOR(vector) __asm__(vector) __attribute__((signal, used, externally_visible))

class RestoreIrq {
private:
    uint8_t               sreg_value;
    constexpr static auto reg = SFR::BitRegisterRW<SFR::SREG, uint8_t>();

public:
    RestoreIrq()
    {
        sreg_value = reg.read();
        // clang-format off
        __asm__ __volatile__ ("cli" ::: "memory");
        // clang-format on
    }
    ~RestoreIrq()
    {
        reg = sreg_value;
        // clang-format off
        __asm__ volatile ("" ::: "memory");
        // clang-format on
    }
};

class Irq_Base {
public:
    static void
    enable(void)
    {
        // clang-format off
        __asm__ __volatile__("sei" ::: "memory");
        // clang-format on
    }

    static void
    disable(void)
    {
        // clang-format off
        __asm__ __volatile__ ("cli" ::: "memory");
        // clang-format on
    }
    static void
    atomicRestore(void)
    {
        RestoreIrq();
    }

    /* Vector executed when an IRQ fires with no accompanying handler. This
    may be used to create a catch-all for undefined but used IRQs for debugging purposes.
    */
    static void
    CatchAll() VECTOR("__vector_default");
};

#include <mcu_irq.h>

#endif

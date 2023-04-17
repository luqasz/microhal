#pragma once

#include "../../../types.hpp"
#include "../../../sfr.hpp"

#define VECTOR(vector) __asm__(vector) __attribute__((signal, used, externally_visible))

class RestoreIrq {
private:
    u8                    sreg_value;
    constexpr static auto reg = SFR::RegisterRW<SFR::SREG, u8>();

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
        __asm__ __volatile__ ("" ::: "memory");
        // clang-format on
    }
};

struct IRQ_Base {

    static inline void
    enable(void)
    {
        // clang-format off
        __asm__ __volatile__("sei" ::: "memory");
        // clang-format on
    }

    static inline void
    disable(void)
    {
        // clang-format off
        __asm__ __volatile__ ("cli" ::: "memory");
        // clang-format on
    }

    /* Vector executed when an IRQ fires with no accompanying handler. This
    may be used to create a catch-all for undefined but used IRQs for debugging purposes.
    */
    static void
    CatchAll() VECTOR("__vector_default");
};

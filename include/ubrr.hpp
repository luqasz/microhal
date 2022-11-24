#pragma once

#include "units.hpp"
#include "types.hpp"

namespace USART {

    // Values represent divisor required for UBRR and error check functions.
    enum U2X {
        on  = 2, // U2X bit = 1
        off = 1, // U2X bit = 0
    };

    // TODO Embed U2X bit into 13th bit position.
    struct BaudRateAsync {
        const u16 ubrr;
        const U2X u2x;
    };

    /*
     * Check if calculated UBRR value produces tolerable error rate.
     */
    constexpr bool
    err_check(
        const units::Frequency freq,
        const BaudRateAsync    ubrr,
        const u32              baud,
        const u8               tol = 2)
    {
        const u32 calc  = (16u / ubrr.u2x) * (ubrr.ubrr + 1u);
        const u32 plus  = calc * (100u * baud + baud * tol);
        const u32 minus = calc * (100u * baud - baud * tol);
        if ((freq * 100) > plus) {
            return true;
        }
        if ((freq * 100) < minus) {
            return true;
        }
        return false;
    }

    /*
     * Calculate UBRR value based on cpu frequency and desired baud rate.
     */
    constexpr BaudRateAsync
    calc_ubrr(const units::Frequency freq, const u32 baud, const U2X u2x)
    {
        const u32 value = ((freq + (8u / u2x) * baud).value) / ((16u / u2x) * baud);
        return BaudRateAsync {
            .ubrr = static_cast<u16>(value - 1),
            .u2x  = u2x,
        };
    }

    template <const units::Frequency cpu_freq, const u32 baud, const u8 tol = 2, const U2X u2x = off>
    consteval BaudRateAsync
    baud_rate_async()
    {
        constexpr BaudRateAsync ubrr   = calc_ubrr(cpu_freq, baud, u2x);
        constexpr bool          is_err = err_check(cpu_freq, ubrr, baud, tol);
        static_assert(!is_err, "Calculated UBRR error rate too high");
        return ubrr;
    }

}

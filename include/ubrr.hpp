#pragma once

#include "units.hpp"
#include "types.hpp"

namespace USART {

    /*
     * Check if calculated UBRR is acceptable based on:
     *      cpu frequency
     *      UBRR
     *      baud
     *      acceptabe error rate
     *      divisor
     * Returns true if error rate is too high, false otherwise.
     * Select valid divisor parameter for U2X.
     * 1 when U2X = 0
     * 2 when U2X = 1
     */
    constexpr bool
    err_check(
        const Frequency freq,
        const u16       ubrr,
        const u32       baud,
        const u8        tol = 2,
        const u8        div = 1)
    {
        u32 calc  = (16u / div) * (ubrr + 1u);
        u32 plus  = calc * (100u * (baud) + (baud) * (tol));
        u32 minus = calc * (100u * (baud) - (baud) * (tol));
        if ((100 * freq.value) > plus) {
            return true;
        }
        if ((100 * freq.value) < minus) {
            return true;
        }
        return false;
    }

    /*
     * Calculate UBRR value based on cpu frequency and desired baud rate.
     * Select valid divisor parameter for U2X.
     * 1 when U2X = 0
     * 2 when U2X = 1
     */
    constexpr u16
    calc_ubrr(const Frequency freq, const u32 baud, const u8 divisor)
    {
        u32 value = (freq.value + (8u / divisor) * baud);
        value /= ((16u / divisor) * baud);
        return static_cast<u16>(value - 1);
    }

    struct BaudRate {
        const u16  ubrr;
        const bool u2x;
        const bool is_ok;
    };

    constexpr BaudRate
    get_baud(const Frequency freq, const u32 baud, const u8 tol = 2)
    {
        // Fisrt calculate with U2X = 0
        const u16  ubrr   = calc_ubrr(freq, baud, 1);
        const bool is_err = err_check(freq, ubrr, baud, tol, 1);
        if (is_err == false) {
            return BaudRate { ubrr, false, true };
        }
        else {
            // Recalculate with U2X = 1
            const u16  ubrr   = calc_ubrr(freq, baud, 2);
            const bool is_err = err_check(freq, ubrr, baud, tol, 2);
            if (is_err == false) {
                return BaudRate { ubrr, true, true };
            }
        }
        return BaudRate { 0, true, false };
    }

}

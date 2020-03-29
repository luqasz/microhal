#pragma once

#include "units.h"

#include <stdint.h>

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
        const uint16_t  ubrr,
        const uint32_t  baud,
        const uint8_t   tol = 2,
        const uint8_t   div = 1)
    {
        uint32_t calc  = (16UL / div) * ((ubrr) + 1);
        uint32_t plus  = calc * (100UL * (baud) + (baud) * (tol));
        uint32_t minus = calc * (100UL * (baud) - (baud) * (tol));
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
    constexpr uint16_t
    calc_ubrr(const Frequency freq, const uint32_t baud, const uint8_t divisor)
    {
        uint16_t value = static_cast<uint16_t>(freq.value + (8UL / divisor) * baud);
        value /= static_cast<uint16_t>((16UL / divisor) * baud);
        return value - 1;
    }

    struct BaudRate {
        const uint16_t ubrr;
        const bool     u2x;
        const bool     is_ok;
    };

    constexpr BaudRate
    get_baud(const Frequency freq, const uint32_t baud, const uint8_t tol = 2)
    {
        // Fisrt calculate with U2X = 0
        const uint16_t ubrr   = calc_ubrr(freq, baud, 1);
        const bool     is_err = err_check(freq, ubrr, baud, tol, 1);
        if (is_err == false) {
            return BaudRate { ubrr, false, true };
        }
        else {
            // Recalculate with U2X = 1
            const uint16_t ubrr   = calc_ubrr(freq, baud, 2);
            const bool     is_err = err_check(freq, ubrr, baud, tol, 2);
            if (is_err == false) {
                return BaudRate { ubrr, true, true };
            }
        }
        return BaudRate { 0, true, false };
    }

}

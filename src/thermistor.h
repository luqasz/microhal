#include <math.h>
#include <stdint.h>

#pragma once

constexpr float KELVIN_C = 273.15;

namespace SteinHart {
    // Steinhart Hart coefficients.
    struct COEF {
        const float a, b, c;
    };

    // Struct binding
    // R resistance at a given temperature in celsius.
    // T given temperature.
    struct ResistanceTemp {
        const uint32_t t;
        const uint32_t r;
    };

    /*
    * Return calculated coefficients based on three values.
    * Provide each value in steps of 25 degrees. See producers
    * datasheet for table with defined resistances.
    *
    * example:
    * 10k NTC
    * constexpr RT {
    *   .r = 10000,
    *   .t = 25,
    * };
    * constexpr RT {
    *   .r = 3605,
    *   .t = 50,
    * };
    * constexpr RT {
    *   .r = 1481,
    *   .t = 75,
    * };
    */
    constexpr COEF
    calc_coef(const ResistanceTemp rt1, const ResistanceTemp rt2, const ResistanceTemp rt3)
    {
        const float Y1 = 1 / (static_cast<float>(rt1.t) + KELVIN_C);
        const float Y2 = 1 / (static_cast<float>(rt2.t) + KELVIN_C);
        const float Y3 = 1 / (static_cast<float>(rt3.t) + KELVIN_C);

        const float L1 = log(static_cast<float>(rt1.r));
        const float L2 = log(static_cast<float>(rt2.r));
        const float L3 = log(static_cast<float>(rt3.r));

        const float G2 = (Y2 - Y1) / (L2 - L1);
        const float G3 = (Y3 - Y1) / (L3 - L1);

        const float c = ((G3 - G2) / (L3 - L2)) * pow(L1 + L2 + L3, -1);
        const float b = G2 - c * (pow(L1, 2) + (L1 * L2) + pow(L2, 2));
        const float a = Y1 - L1 * (b + c * pow(L1, 2));
        return COEF {
            .a = a,
            .b = b,
            .c = c,
        };
    }

    constexpr float
    steinhartHart(const float resistance, const COEF coef)
    {
        const float log_r  = log(resistance);
        const float log_r3 = log_r * log_r * log_r;
        return 1.0 / (coef.a + coef.b * log_r + coef.c * log_r3);
    }
}

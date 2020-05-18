#include <math.h>
#include <stdint.h>

#pragma once

constexpr float KELVIN_C = 273.15;

namespace SteinHart {
    // Steinhart Hart coefficients.
    struct COEF {
        const float A, B, C;
    };

    // Struct binding
    // R resistance at a given temperature in celsius.
    // T given temperature.
    struct RT {
        const uint32_t T;
        const uint32_t R;
    };

    /*
    * Return calculated coefficients based on three RT bindings.
    * Provide each binding in steps of 25 degrees. See producers
    * datasheet for table with defined resistances.
    *
    * example:
    * 10k NTC
    * constexpr RT {
    *   .R = 10000,
    *   .T = 25,
    * };
    * constexpr RT {
    *   .R = 3605,
    *   .T = 50,
    * };
    * constexpr RT {
    *   .R = 1481,
    *   .T = 75,
    * };
    */
    constexpr COEF
    calc_coef(const RT rt1, const RT rt2, const RT rt3)
    {
        const float Y1 = 1 / (T1 + KELVIN_C);
        const float Y2 = 1 / (T2 + KELVIN_C);
        const float Y3 = 1 / (T3 + KELVIN_C);

        const float L1 = log(R1);
        const float L2 = log(R2);
        const float L3 = log(R3);

        const float G2 = (Y2 - Y1) / (L2 - L1);
        const float G3 = (Y3 - Y1) / (L3 - L1);

        const float c = ((G3 - G2) / (L3 - L2)) * pow(L1 + L2 + L3, -1);
        const float b = G2 - c * (pow(L1, 2) + (L1 * L2) + pow(L2, 2));
        const float a = Y1 - L1 * (b + c * pow(L1, 2));
        return COEF {
            .A = a,
            .B = b,
            .C = c,
        };
    }

    constexpr double
    steinhartHart(const double r, const COEF coef)
    {
        double log_r  = log(r);
        double log_r3 = log_r * log_r * log_r;
        return 1.0 / (coef.A + coef.B * log_r + coef.C * log_r3);
    }
};

#include "types.hpp"
#include "defs.hpp"

#include <math.h>
#include <stdint.h>

#pragma once

/*
Substract from kelvin to get °C
*/
constexpr float KELVIN_C = 273.15f;
/*
External links:
    https://www.thinksrs.com/downloads/programs/therm%20calc/ntccalibrator/ntccalculator.html
    https://www.thinksrs.com/downloads/pdfs/applicationnotes/LDC%20Note%204%20NTC%20Calculator.pdf
*/
namespace thermistor {
    // Steinhart Hart coefficients.
    struct Coefficients {
        const float a, b, c;
    };

    struct CelsiusOhm {
        const float temp; // temperature in °C
        const float res;  // resistance in Ω
    };

    /*
    Return calculated coefficients based on 3 °C,Ω pairs.
    Provide each in steps of 25 °C.
    See producers data sheet for those values.
    */
    constexpr Coefficients CONSTFN
    calc_coef(const CelsiusOhm & rt1, const CelsiusOhm & rt2, const CelsiusOhm & rt3)
    {
        const float Y1 = 1 / (rt1.temp + KELVIN_C);
        const float Y2 = 1 / (rt2.temp + KELVIN_C);
        const float Y3 = 1 / (rt3.temp + KELVIN_C);

        const float L1 = log(rt1.res);
        const float L2 = log(rt2.res);
        const float L3 = log(rt3.res);

        const float G2 = (Y2 - Y1) / (L2 - L1);
        const float G3 = (Y3 - Y1) / (L3 - L1);

        const float c = ((G3 - G2) / (L3 - L2)) * static_cast<float>(pow(L1 + L2 + L3, -1));
        const float b = G2 - c * (static_cast<float>(pow(L1, 2)) + (L1 * L2) + static_cast<float>(pow(L2, 2)));
        const float a = Y1 - L1 * (b + c * static_cast<float>(pow(L1, 2)));
        return Coefficients {
            a,
            b,
            c,
        };
    }

    /*
    Given:
      Actual thermistor resistance in °C.
      Thermistor coefficients
    Return:
      Temperature in °C
    */
    constexpr float CONSTFN
    calc_temp(const float resistance, const Coefficients & coef)
    {
        const float log_r = log(resistance);
        const float log_r3 = log_r * log_r * log_r;
        const float in_kelvin = 1.0f / (coef.a + coef.b * log_r + coef.c * log_r3);
        return in_kelvin - KELVIN_C;
    }

    /*
    Given:
      Nominal resistance and temperature
      β value
      Actual resistance
    Return
      Temperature in °C.
    */
    constexpr float CONSTFN
    calc_temp(const float resistance, const CelsiusOhm & nominal, const float beta)
    {
        const float in_kelvin = 1.0f / (nominal.temp + KELVIN_C) + static_cast<float>(log(resistance / nominal.res)) / beta;
        return (1.0f / in_kelvin) - KELVIN_C;
    }
}

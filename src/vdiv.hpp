#pragma once

#include "types.h"

#include <math.h>
#include <stdint.h>

namespace vdiv {
    /*
     Vout = Vin * R2 / (R1 + R2)
     Vin = Vout * (R1 + R2) / R2
     R1 = R2 * (Vin - Vout) / Vout
     R2 = R1 * Vout / (Vin – Vout)

     Vin
      |
      |
     Source resistor R1
      |
      |-------Vout
      |
     Sink resistor R2
      |
      |
     GND
    */

    /*
    Return calculated sink resistor value based on:
      read ADC value
      ADV bits
      resistance in Ω
    */
    constexpr float
    calc_sink_r(const float adc_val, const float adc_bits, const float r1)
    {
        return r1 / ((static_cast<float>(pow(2, adc_bits)) / adc_val) - 1);
    }

    /*
    Return calculated source resistor value based on:
      read ADC value
      ADV bits
      resistance in Ω
    */
    constexpr float
    calc_source_r(const float adc_val, const float adc_bits, const float r2)
    {
        return r2 * ((static_cast<float>(pow(2, adc_bits)) / adc_val) - 1);
    }
}

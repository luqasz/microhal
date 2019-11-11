// vim: set ft=cpp:
#pragma once

#include <mcu_sfr.h>

namespace ADC {
    typedef SFR::ADCSRA ADCSRA_REG;
    typedef SFR::SFIOR  TRIGGER_REG;
    typedef SFR::ADMUX  ADMUX_REG;
    typedef SFR::ADMUX  VREF_REG;
    typedef SFR::ADCSRA CTL_REG;
    typedef SFR::ADCSRA PRESCALER_REG;
}

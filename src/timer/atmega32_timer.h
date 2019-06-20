#ifndef atmega32_timer_h
#define atmega32_timer_h

namespace Timer0 {

    typedef SFR::TCCR0 CLOCK_REG;
    typedef SFR::TCCR0 WGM_REG;
    typedef SFR::TCNT0 COUNTER_REG;
    typedef SFR::OCR0  COMPARE_REG;
    typedef SFR::TIMSK IRQ_REG;

}

#endif

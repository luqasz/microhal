#ifndef REGISTERS_h_
#define REGISTERS_h_

#if defined(__AVR_ATmega328P__)
#    include "mcu/atmega328p.h"
#elif defined(__AVR_ATmega32__)
#    include "mcu/atmega32.h"
#elif defined(__AVR_ATmega32A__)
#    include "mcu/atmega32.h"
#else
#    error "Unsupported MCU."
#endif

#endif

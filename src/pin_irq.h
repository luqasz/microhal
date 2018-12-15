#ifndef PIN_IRQ_H_
#define PIN_IRQ_H_

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>

typedef void (*irq_handler)(void);

enum TRIGGER_SOURCE {
    RISING  = 0x03,
    FALLING = 0x02,
    LOW     = 0x00,
    CHANGE  = 0x01,
};

enum INTERRUPT_PIN {
    INT_0,
    INT_1,
};

void attach_pin_interrupt(enum INTERRUPT_PIN, enum TRIGGER_SOURCE, irq_handler);

#endif
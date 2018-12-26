#include "pin_irq.h"

#include "registers.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>

void
nothing(void)
{
}

static volatile irq_handler handlers[IRQ_HANDLERS] = {
    nothing
};

void
attach_pin_interrupt(enum INTERRUPT_PIN pin, enum TRIGGER_SOURCE trigger, irq_handler function)
{
    uint8_t reg_value;
    uint8_t trigger_mask;
    uint8_t pin_bit;
    switch (pin) {
        case INT_0:
            trigger_mask = (uint8_t) ~((1 << ISC00) | (1 << ISC01));
            reg_value    = trigger << ISC00;
            pin_bit      = INT0;
            break;
        case INT_1:
            trigger_mask = (uint8_t) ~((1 << ISC10) | (1 << ISC11));
            reg_value    = trigger << ISC10;
            pin_bit      = INT1;
            break;
    }
    EXTERNAL_IRQ_REG &= trigger_mask;
    EXTERNAL_IRQ_REG |= reg_value;
    handlers[pin] = function;
    IRQ_ENABLE_REG |= 1 << pin_bit;
}

ISR(INT0_vect)
{
    handlers[INT_0]();
}

ISR(INT1_vect)
{
    handlers[INT_1]();
}
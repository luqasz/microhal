#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "registers.h"
#include "uart.h"
#include "spi.h"
#include "hwconfig.h"

#define ENC_A PD2
#define ENC_B PD4


int main(void) {
    // Enable INT0 interrupt
    MCUCR |= 1<<ISC00;
    // Rising and falling edge
    GICR |= 1<<INT0;
    // Pull up lines to 10k
    PORTD |= (1<<ENC_A) | (1<<ENC_B);
    uart_start();
    sei();
    char str[32];
    sprintf(str, "starting...\r\n");
    uart_write(str);
    while (1) {
    }
}

// Idea taken from
// https://www.circuitsathome.com/mcu/reading-rotary-encoder-on-arduino/
ISR(INT0_vect) {
    static uint8_t state;
    state <<= 2;
    state |= (PIND & 1<<ENC_A)?2:0;
    state |= (PIND & 1<<ENC_B)?1:0;
    switch (state & 0x0f) {
        // When rotated clockwise.
        case 6:
            break;
        // When rotated counter clockwise.
        case 3:
            break;
    }
}

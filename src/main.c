#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"

#define LED_ON PORTC &= ~(1<<PC0)
#define LED_OFF PORTC |= (1<<PC0)

int main(void) {
    DDRC |= (1<<PC0);
    uart_start();
    sei();
    while (1) {
        DDRC ^= (1<<PC0);
        uart_putchar('s');
    }
}

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "i2c.h"


int main(void) {
    uart_start();
    sei();
    uart_write("starting\r\n");
    while (1) {
    }
}

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "registers.h"
#include "uart.h"
#include "spi.h"
#include "hwconfig.h"

int main(void) {
    uart_start();
    sei();
    uint8_t value = 0;
    char str[32];
    while (1) {
        sprintf(str, "value=%d\r\n", value);
        uart_write(str);
        value ++;
    }
}

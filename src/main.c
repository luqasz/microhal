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
    char str[32];
    sprintf(str, "starting...\r\n");
    uart_write(str);
    uint16_t full_value = 0xAABB;
    unsigned char* a = (unsigned char*)&full_value;
    sprintf(str, "array[0] %d\r\n", a[0]);
    uart_write(str);
    sprintf(str, "array[1] %d\r\n", a[1]);
    uart_write(str);
    while (1) {
    }
}

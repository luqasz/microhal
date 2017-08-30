#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "i2c.h"

#define PCF8591_ADDR 0x48

void set_dac(uint8_t value) {
    uint8_t data[] = {64, value};
    i2c_write_buf(PCF8591_ADDR, sizeof(data), data);
}

int main(void) {
    uart_start();
    i2c_set_speed(100);
    sei();
    uart_write("starting\r\n");
    uint8_t i;
    while (1) {
        for (i=0; i != 255; i++) {
            _delay_ms(10);
            set_dac(i);
        }
        for (i=255; i != 0; i--) {
            _delay_ms(10);
            set_dac(i);
        }
    }
}

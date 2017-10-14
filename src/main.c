#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include DEVICE_NAME
#include "uart.h"
#include "spi.h"

#define CS PD4
#define CS_LOW PORTD &= (uint8_t) ~(1<<CS)
#define CS_HIGH PORTD |= (uint8_t) (1<<CS)

void set_dac(uint16_t val) {
    val = 4095 & val;
    CS_LOW;
    uint8_t right = (uint8_t) val;
    uint8_t left = (uint8_t) (val >> 8);
    left |= 0b00110000;
    spi_send(left);
    spi_send(right);
    CS_HIGH;
}

int main(void) {
    DDRD |= 1<<CS;
    CS_HIGH;
    DDRB |= 1<<SS;
    PORTB |= 1<<SS;
    spi_master();
    uart_start();
    sei();
    char string[30];
    uint16_t value = 0;
    while (1) {
        sprintf(string, "setting DAC to %d\r\n", value);
        uart_write(string);
        set_dac(value);
        value ++;
        _delay_ms(500);
    }
}

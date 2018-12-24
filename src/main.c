#include "registers.h"
#include "uart.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <stdio.h>

int
main(void)
{
    uart_start();
    sei();
    uart_write("1234567890");
    wdt_enable(WDTO_1S);
    while (1) {
        wdt_reset();
    }
}

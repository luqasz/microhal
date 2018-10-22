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
    char string[] = "some very long string to keep buffer full\r\n";
    uart_write(string);
    wdt_enable(WDTO_1S);
    while (1) {
        wdt_reset();
    }
}

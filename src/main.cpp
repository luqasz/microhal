#include "registers.h"
#include "uart.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

int
main(void)
{
    auto serial = Uart();
    serial.speed(x2_115200);
    serial.start();
    sei();
    serial.write("1234567890 abcdefghijklmnoprstuwxyz\r\n");
    while (1) {
    }
}

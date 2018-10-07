#include <avr/io.h>
#include "registers.h"
#include "uart.h"

int main(void) {
    uart_start();
    char string[] = "sine verry long string to make circular buffer full at all times";
    while (1) {
        uart_write(string);
    }
}

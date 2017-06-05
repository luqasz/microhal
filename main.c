#include <avr/io.h>
#include <util/delay.h>

#define LED_ON PORTC &= ~(1<<PC0)
#define LED_OFF PORTC |= (1<<PC0)

int main(void) {
    DDRC |= (1<<PC0);
    while (1) {
        DDRC ^= (1<<PC0);
        _delay_ms(1000);
    }
}

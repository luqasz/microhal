#include <avr/io.h>
#include <util/delay.h>

#define LED_ON PORTC &= ~(1<<PC6)
#define LED_OFF PORTC |= (1<<PC6)

void sleep(uint16_t millisec)
{
    while(millisec)
    {
        _delay_ms(1);
        millisec--;
    }
}

int main(void) {
    DDRC |= (1<<PC6);
    DDRA &= ~(1<<PA7);
    PORTA |= (1<<PA7);
    while (1) {
        if ( !(PINA & (1<<PA7)) ) {
            LED_ON;
        } else {
            LED_OFF;
        }
    }
}

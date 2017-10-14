#include <avr/io.h>
#include <util/delay.h>
#include "registers.h"

void spi_master(void) {
	// Set pins as output
	DDRB |= (1<<SCK)|(1<<MOSI);
	// Set SPI as master. Clock rate at fosc/16
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void spi_send(uint8_t byte) {
	SPDR = byte;
	// Wait for transmission complete
	while(!(SPSR & (1<<SPIF)));
}

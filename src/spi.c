#include <avr/io.h>
#include <util/delay.h>
#include "registers.h"
#include "spi.h"

// If SS is configured as an output, the pin is a general output pin which does not affect the SPI system. Typically, the pin will be driving the SS pin of the SPI Slave.
// If SS is configured as an input, it must be held high to ensure Master SPI operation. If the SS pin is driven low by peripheral circuitry when the SPI is configured as a Master with the SS pin defined as an input, the SPI system interprets this as another master selecting the SPI as a slave and starting to send data to it.
void
spi_master (
    void
)
{
    // Set pins as output
    DDR_SPI |= (1 << SCK);
    DDR_SPI |= (1 << MOSI);

    SPCR |= (1 << SPE);         // Enable SPI
    SPCR |= (1 << MSTR);        // Master mode
}

void
spi_send (
    uint8_t byte
)
{
    SPDR = byte;
    // Wait for transmission complete
    while (!(SPSR & (1 << SPIF)));
}

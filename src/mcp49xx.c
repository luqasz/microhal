#include <avr/io.h>
#include "spi.h"
#include "mcp49xx.h"

void
mcp4922_send (
    uint8_t control_bits,
    uint16_t value
)
{
    uint8_t right = (uint8_t) value;
    uint8_t left = (uint8_t) (value >> 8);
    left = (uint8_t) (left | control_bits);
    spi_send (left);
    spi_send (right);
}

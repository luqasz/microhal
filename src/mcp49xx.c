#include <avr/io.h>
#include "spi.h"

void mcp4922_send(uint8_t control_bits, uint16_t value) {
    // Mask out control bits
    value = 4095 & value;
    control_bits = (uint8_t) (control_bits << 4);
    uint8_t right = (uint8_t) value;
    uint8_t left = (uint8_t) (value >> 8);
    spi_send((left | control_bits));
    spi_send(right);
}

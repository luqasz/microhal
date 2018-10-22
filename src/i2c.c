#include "i2c.h"

#include <avr/io.h>

// Device address on I2C bus must be written without R/W bit.
// Functions take care of adding appropriate bit at the end.
// Example:
// Slave address is 0x48 which is 01001000 (8 bit in binary).
// For writing into device, address will be converted into 0x90 10010000 (last bit 0 means writing)
// For reading from device, address will be converted into 0x91 10010001 (last bit 1 means reading)

void
i2c_set_speed(
    uint16_t bitrateKHz)
{
    // Formula taken from atmel data sheet.
    uint8_t bitrate_div = (uint8_t)((F_CPU / 1000l) / bitrateKHz);
    if (bitrate_div >= 16)
        bitrate_div = (uint8_t)(bitrate_div - 16) / 2;

    TWBR = bitrate_div;
}

void
i2c_start(
    void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    while (!(TWCR & (1 << TWINT))) {
    };
}

void
i2c_stop(
    void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
    while ((TWCR & (1 << TWSTO))) {
    };
}

void
i2c_write_byte(
    uint8_t byte)
{
    TWDR = byte;
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Wait until byte is pushed out of register.
    while (!(TWCR & (1 << TWINT))) {
    };
}

uint8_t
i2c_read_byte(
    uint8_t ack)
{
    TWCR = (uint8_t)(1 << TWINT) | (uint8_t)(ack << TWEA) | (uint8_t)(1 << TWEN);
    // Wait until byte is present in register.
    while (!(TWCR & (1 << TWINT))) {
    };
    return TWDR;
}

void
i2c_write_buf(
    uint8_t slave_address,
    uint8_t address,
    uint8_t len,
    uint8_t * buf)
{
    i2c_start();
    i2c_write_byte((uint8_t)(slave_address << 1));
    i2c_write_byte(address);
    while (len--) {
        i2c_write_byte(*buf++);
    }
    i2c_stop();
}

void
i2c_read_buf(
    uint8_t slave_address,
    uint8_t address,
    uint8_t len,
    uint8_t * buf)
{
    i2c_start();
    i2c_write_byte((uint8_t)(slave_address << 1));
    i2c_write_byte(address);
    i2c_start();
    i2c_write_byte((uint8_t)((slave_address << 1) + 1));
    while (len--) {
        *buf++ = i2c_read_byte(len ? I2C_ACK : I2C_NACK);
    }
    i2c_stop();
}

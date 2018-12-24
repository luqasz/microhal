#include "i2c.h"

#include <avr/io.h>

// Device address on I2C bus must be written without R/W bit.
// Functions take care of adding appropriate bit at the end.
// Example:
// Slave address is 0x48 which is 01001000 (8 bit in binary).
// For writing into device, address will be converted into 0x90 10010000 (last bit 0 means writing)
// For reading from device, address will be converted into 0x91 10010001 (last bit 1 means reading)

void
I2C::speed(enum I2C_SPEED speed)
{
    // Formula taken from atmel data sheet.
    TWBR = (uint8_t)speed;
}

void
I2C::start(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    while (!(TWCR & (1 << TWINT))) {
    };
}

void
I2C::stop(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
    while ((TWCR & (1 << TWSTO))) {
    };
}

void
I2C::write(uint8_t byte)
{
    TWDR = byte;
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Wait until byte is pushed out of register.
    while (!(TWCR & (1 << TWINT))) {
    };
}

uint8_t
I2C::read(uint8_t ack)
{
    TWCR = (uint8_t)(1 << TWINT) | (uint8_t)(ack << TWEA) | (uint8_t)(1 << TWEN);
    // Wait until byte is present in register.
    while (!(TWCR & (1 << TWINT))) {
    };
    return TWDR;
}

void
I2C::write(
    uint8_t slave_address,
    uint8_t address,
    uint8_t len,
    uint8_t * buf)
{
    start();
    write((uint8_t)(slave_address << 1));
    write(address);
    while (len--) {
        write(*buf++);
    }
    stop();
}

void
I2C::read(
    uint8_t slave_address,
    uint8_t address,
    uint8_t len,
    uint8_t * buf)
{
    start();
    write((uint8_t)(slave_address << 1));
    write(address);
    start();
    write((uint8_t)((slave_address << 1) + 1));
    while (len--) {
        *buf++ = read(len ? I2C_ACK : I2C_NACK);
    }
    stop();
}

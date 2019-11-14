#include "i2c.h"

#include "sfr.h"

auto TWCR = Register<SFR::TWCR>();
auto TWBR = Register<SFR::TWBR>();
auto TWDR = Register<SFR::TWDR>();

const uint8_t ACK  = TWCR.TWEA;
const uint8_t NACK = 0;

void
twcr_wait(const uint8_t bit)
{
    while (!(TWCR & bit)) {
    };
}

void
start_signal(void)
{
    TWCR = (TWCR.TWINT | TWCR.TWEN | TWCR.TWSTA);
    twcr_wait(TWCR.TWINT);
}

void
stop_signal(void)
{
    TWCR = (TWCR.TWINT | TWCR.TWEN | TWCR.TWSTO);
    twcr_wait(TWCR.TWSTO);
}

void
write_blocking(uint8_t byte)
{
    TWDR = byte;
    TWCR = (TWCR.TWINT | TWCR.TWEN);
    // Wait until byte is pushed out of register.
    twcr_wait(TWCR.TWINT);
}

uint8_t
read_blocking(uint8_t ack)
{
    TWCR = (TWCR.TWINT | ack | TWCR.TWEN);
    // Wait until byte is present in register.
    twcr_wait(TWCR.TWINT);
    return TWDR;
}

void
set_speed(const I2C::Speed speed)
{
    TWBR = static_cast<uint8_t>(speed);
}

void
I2C::Master::write(const I2C::Target & target, Buffer::Bytes    set_speed(target.speed);
    start_signal();
    write_blocking(static_cast<uint8_t>(target.address << 1));
    write_blocking(target.start_address);
    for (uint8_t byte : buffer) {
    write_blocking(byte);
    }
    stop_signal();
}

void
I2C::Master::read(const I2C::Target & target, Buffer::Bytes & buffer)
{
    set_speed(target.speed);
    start_signal();
    write_blocking(static_cast<uint8_t>(target.address << 1));
    write_blocking(target.start_address);
    start_signal();
    write_blocking(static_cast<uint8_t>((target.address << 1) + 1));
    uint8_t counter = static_cast<uint8_t>(target.end_address - target.start_address);
    for (auto & value : buffer) {
        counter--;
        value = read_blocking(counter ? ACK : NACK);
    }
    stop_signal();
}

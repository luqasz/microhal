#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

#define I2C_ACK 1
#define I2C_NACK 0

void i2c_set_speed(
    uint16_t bitrateKHz);

void i2c_start(
    void);
void i2c_stop(
    void);
void i2c_write_byte(
    uint8_t byte);
uint8_t i2c_read_byte(
    uint8_t ack);

void i2c_write_buf(
    uint8_t slave_address,
    uint8_t address,
    uint8_t len,
    uint8_t * buf);
void i2c_read_buf(
    uint8_t slave_address,
    uint8_t address,
    uint8_t len,
    uint8_t * buf);

#endif

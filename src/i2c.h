#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

#define I2C_ACK 1
#define I2C_NACK 0

// Values represent direct value of TWBR.
enum I2C_SPEED : uint8_t {
    SPEED_100kHz = ((F_CPU / 100000) - 16) / 2,
    SPEED_400kHz = ((F_CPU / 400000) - 16) / 2,
};

class I2C {
public:
    void speed(enum I2C_SPEED);
    void start(void);
    void stop(void);
    void write(uint8_t);
    void write(
        uint8_t slave_address,
        uint8_t address,
        uint8_t len,
        uint8_t * buf);
    uint8_t read(uint8_t);
    void read(
        uint8_t slave_address,
        uint8_t address,
        uint8_t len,
        uint8_t * buf);
};

#endif

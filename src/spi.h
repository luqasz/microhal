#ifndef spi_h
#define spi_h

#include <stdint.h>

class SPI {
public:
    void master();
    uint8_t communicate(uint8_t);
};

#endif

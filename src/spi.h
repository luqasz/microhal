#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

void spi_master(
    void);
void spi_send(
    uint8_t byte);
#endif

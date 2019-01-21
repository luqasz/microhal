#ifndef atmega32_spi_h
#define atmega32_spi_h

#include "../gpio.h"

namespace SPI {

    const GPIO::Pin SCK  = GPIO::PB7;
    const GPIO::Pin SS   = GPIO::PB4;
    const GPIO::Pin MOSI = GPIO::PB5;
    const GPIO::Pin MISO = GPIO::PB6;

}

#endif
#ifndef spi_h
#define spi_h

#include "sfr.h"

#include <stdint.h>

namespace SPI {
    /*
    If SS is configured as an output, the pin is a general output pin which does not affect the SPI system.
    Typically, the pin will be driving the SS pin of the SPI Slave.
    If SS is configured as an input, it must be held high to ensure Master SPI operation.
    If the SS pin is driven low by peripheral circuitry when the SPI is configured as a Master with the SS pin defined as an input, the SPI system interprets this as another master selecting the SPI as a slave and starting to send data to it.
    */

    enum class DataOrder {
        LSB_First,
        MSB_First,
    };

    enum class Mode {
        m0,
        m1,
        m2,
        m3,
    };

    class Slave {
    public:
        /*
        Slave can work only with limited set of speed.
        Refer to datasheet for more information.
        */
        enum class Speed {
            d2,
            d4,
        };
    };

    class Master {
    public:
        enum class Speed {
            d2,
            d4,
            d8,
            d16,
            d32,
            d64,
            d128,
        };
        Master();
        void     set(const SPI::DataOrder);
        void     set(const SPI::Master::Speed);
        void     set(const SPI::Mode);
        void     enable();
        void     disable();
        uint8_t  communicate(const uint8_t);
        uint16_t communicate(const uint16_t);
    };
}

#if defined(__AVR_ATmega328P__)
#    include "spi/atmega328p_spi.h"
#elif defined(__AVR_ATmega32__)
#    include "spi/atmega32_spi.h"
#elif defined(__AVR_ATmega32A__)
#    include "spi/atmega32a_spi.h"
#else
#    error "Unsupported MCU."
#endif

#endif

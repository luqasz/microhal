#pragma once

#include "buffer.hpp"
#include "sfr.hpp"
#include "types.hpp"
#include "gpio.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/spi.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/spi.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/spi.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

namespace SPI {
    /*
    If SS is configured as an output, the pin is a general output pin which does not affect the SPI system.
    Typically, the pin will be driving the SS pin of the SPI Slave.
    If SS is configured as an input, it must be held high to ensure Master SPI operation.
    If the SS pin is driven low by peripheral circuitry when the SPI is configured as a Master with the SS pin defined as an input, the SPI system interprets this as another master selecting the SPI as a slave and starting to send data to it.
    */

    /*
    In which order bits will be shifted first.
    */
    enum class Order {
        LSB,
        MSB,
    };

    /*
    In which mode shoudl operate in.
    */
    enum class Mode {
        m0, // clock polarity=0, clock phase=0
        m1, // clock polarity=0, clock phase=1
        m2, // clock polarity=1, clock phase=0
        m3, // clock polarity=1, clock phase=1
        pol0_pha0 = m0,
        pol0_pha1 = m1,
        pol1_pha0 = m2,
        pol1_pha1 = m3,
    };

    enum class MasterClock {
        _2,
        _4,
        _8,
        _16,
        _32,
        _64,
        _128,
    };

    struct Target {
        const Order       order;
        const Mode        mode;
        const MasterClock clock;
    };

    class Master {
        const Instance inst;

    public:
        Master(const Instance _inst, const GPIO::Pin mosi, const GPIO::Pin miso, const GPIO::Pin sck);

        void
        enable();

        void
        disable();

        void
        communicate(u8, const Target &);

        void
        communicate(const buffer::Bytes &, const Target &);
    };
}

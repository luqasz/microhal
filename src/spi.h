#pragma once

#include "sfr.h"

#include <mcu_spi.h>
#include <stdint.h>

namespace SPI {
    /*
    If SS is configured as an output, the pin is a general output pin which does not affect the SPI system.
    Typically, the pin will be driving the SS pin of the SPI Slave.
    If SS is configured as an input, it must be held high to ensure Master SPI operation.
    If the SS pin is driven low by peripheral circuitry when the SPI is configured as a Master with the SS pin defined as an input, the SPI system interprets this as another master selecting the SPI as a slave and starting to send data to it.
    */

    enum DataOrder {
        LSB_First,
        MSB_First,
    };

    enum Mode {
        m0,
        m1,
        m2,
        m3,
    };

    template <typename NUM>
    class Master {
    public:
        enum Speed {
            d2,
            d4,
            d8,
            d16,
            d32,
            d64,
            d128,
        };

        /*
        Set MOSI SCK SS as outputs only.
        For more information why, see "SPI Pin Overrides" in datasheet.
        */
        Master()
        {
            SCK.output();
            MOSI.output();
            SS.output();
            NUM::SPCR.setBit(NUM::SPCR.MSTR);
        }

        void
        enable()
        {
            NUM::SPCR.setBit(NUM::SPCR.SPE);
        }

        void
        disable()
        {
            NUM::SPCR.clearBit(NUM::SPCR.SPE);
        }

        void
        set(const Speed speed)
        {
            switch (speed) {
                case Speed::d2:
                    NUM::SPSR.setBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR0);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR1);
                    break;
                case Speed::d4:
                    NUM::SPSR.clearBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR0);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR1);
                    break;
                case Speed::d8:
                    NUM::SPSR.setBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.setBit(NUM::SPCR.SPR0);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR1);
                    break;
                case Speed::d16:
                    NUM::SPSR.clearBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.setBit(NUM::SPCR.SPR0);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR1);
                    break;
                case Speed::d32:
                    NUM::SPSR.setBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR0);
                    NUM::SPCR.setBit(NUM::SPCR.SPR1);
                    break;
                case Speed::d64:
                    NUM::SPSR.setBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.setBit(NUM::SPCR.SPR0);
                    NUM::SPCR.setBit(NUM::SPCR.SPR1);
                    break;
                case Speed::d128:
                    NUM::SPSR.clearBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.setBit(NUM::SPCR.SPR0);
                    NUM::SPCR.setBit(NUM::SPCR.SPR1);
                    break;
            }
        }

        void
        set(const DataOrder order)
        {
            switch (order) {
                case DataOrder::LSB_First:
                    NUM::SPCR.setBit(NUM::SPCR.DORD);
                    break;
                case DataOrder::MSB_First:
                    NUM::SPCR.clearBit(NUM::SPCR.DORD);
                    break;
            }
        }

        void
        set(const Mode mode)
        {
            switch (mode) {
                case Mode::m0:
                    NUM::SPCR.clearBit(NUM::SPCR.CPHA);
                    NUM::SPCR.clearBit(NUM::SPCR.CPOL);
                    break;
                case Mode::m1:
                    NUM::SPCR.setBit(NUM::SPCR.CPHA);
                    NUM::SPCR.clearBit(NUM::SPCR.CPOL);
                    break;
                case Mode::m2:
                    NUM::SPCR.clearBit(NUM::SPCR.CPHA);
                    NUM::SPCR.setBit(NUM::SPCR.CPOL);
                    break;
                case Mode::m3:
                    NUM::SPCR.setBit(NUM::SPCR.CPHA);
                    NUM::SPCR.setBit(NUM::SPCR.CPOL);
                    break;
            }
        }

        uint8_t
        communicate(const uint8_t byte)
        {
            NUM::SPDR = byte;
            // Wait for transmission complete
            while (!(NUM::SPSR.isSet(NUM::SPSR.SPIF))) {
            }
            return NUM::SPDR.read();
        }

        uint16_t
        communicate(const uint16_t bytes)
        {

            uint8_t b1 = static_cast<uint8_t>(bytes >> 8);
            uint8_t b2 = static_cast<uint8_t>(bytes);
            b1         = communicate(b1);
            b2         = communicate(b2);
            return static_cast<uint16_t>(b1 << 8) | b2;
        }
    };
}

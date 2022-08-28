#pragma once

#include "buffer.hpp"
#include "sfr.hpp"

#include <gpio.hpp>
#include <mcu_spi.hpp>
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
        enum Clock {
            _2,
            _4,
            _8,
            _16,
            _32,
            _64,
            _128,
        };

        /*
        Set MOSI SCK SS as outputs only.
        For more information why, see "SPI Pin Overrides" in datasheet.
        */
        Master(const GPIO::Pin mosi, const GPIO::Pin miso, const GPIO::Pin sck)
        {
            GPIO::Output(sck, GPIO::High);
            GPIO::Input(miso, GPIO::High);
            GPIO::Output(mosi, GPIO::High);
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
        set(const Clock c)
        {
            switch (c) {
                case Clock::_2:
                    NUM::SPSR.setBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR0);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR1);
                    break;
                case Clock::_4:
                    NUM::SPSR.clearBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR0);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR1);
                    break;
                case Clock::_8:
                    NUM::SPSR.setBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.setBit(NUM::SPCR.SPR0);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR1);
                    break;
                case Clock::_16:
                    NUM::SPSR.clearBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.setBit(NUM::SPCR.SPR0);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR1);
                    break;
                case Clock::_32:
                    NUM::SPSR.setBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.clearBit(NUM::SPCR.SPR0);
                    NUM::SPCR.setBit(NUM::SPCR.SPR1);
                    break;
                case Clock::_64:
                    NUM::SPSR.setBit(NUM::SPSR.SPI2X);
                    NUM::SPCR.setBit(NUM::SPCR.SPR0);
                    NUM::SPCR.setBit(NUM::SPCR.SPR1);
                    break;
                case Clock::_128:
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
            NUM::SPSR.waitForSetBit(NUM::SPSR.SPIF); // Wait for transmission complete
            return NUM::SPDR.read();
        }

        void
        communicate(const Buffer::Bytes buffer)
        {
            for (uint8_t & byte : buffer) {
                byte = communicate(byte);
            }
        }
    };
}

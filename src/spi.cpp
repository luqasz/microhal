#include <spi.hpp>

namespace SPI {

    constexpr static auto SPCR = SFR::RegisterRW<SFR::SPCR, uint8_t>();
    constexpr static auto SPSR = SFR::RegisterRW<SFR::SPSR, uint8_t>();
    constexpr static auto SPDR = SFR::RegisterRW<SFR::SPDR, uint8_t>();

    Master::Master(const Instance _inst, const GPIO::Pin mosi, const GPIO::Pin miso, const GPIO::Pin sck) :
        inst(_inst)
    {
        GPIO::Output(sck, GPIO::High);
        GPIO::Input(miso, GPIO::High);
        GPIO::Output(mosi, GPIO::High);
        SPCR.setBit(SPCR.MSTR);
    }

    void
    Master::enable()
    {
        SPCR.setBit(SPCR.SPE);
    }

    void
    Master::disable()
    {
        SPCR.clearBit(SPCR.SPE);
    }

    void
    set(const MasterClock c)
    {
        switch (c) {
            case MasterClock::_2:
                SPSR.setBit(SPSR.SPI2X);
                SPCR.clearBit(SPCR.SPR0);
                SPCR.clearBit(SPCR.SPR1);
                break;
            case MasterClock::_4:
                SPSR.clearBit(SPSR.SPI2X);
                SPCR.clearBit(SPCR.SPR0);
                SPCR.clearBit(SPCR.SPR1);
                break;
            case MasterClock::_8:
                SPSR.setBit(SPSR.SPI2X);
                SPCR.setBit(SPCR.SPR0);
                SPCR.clearBit(SPCR.SPR1);
                break;
            case MasterClock::_16:
                SPSR.clearBit(SPSR.SPI2X);
                SPCR.setBit(SPCR.SPR0);
                SPCR.clearBit(SPCR.SPR1);
                break;
            case MasterClock::_32:
                SPSR.setBit(SPSR.SPI2X);
                SPCR.clearBit(SPCR.SPR0);
                SPCR.setBit(SPCR.SPR1);
                break;
            case MasterClock::_64:
                SPSR.setBit(SPSR.SPI2X);
                SPCR.setBit(SPCR.SPR0);
                SPCR.setBit(SPCR.SPR1);
                break;
            case MasterClock::_128:
                SPSR.clearBit(SPSR.SPI2X);
                SPCR.setBit(SPCR.SPR0);
                SPCR.setBit(SPCR.SPR1);
                break;
        }
    }

    void
    set(const Order order)
    {
        switch (order) {
            case Order::LSB:
                SPCR.setBit(SPCR.DORD);
                break;
            case Order::MSB:
                SPCR.clearBit(SPCR.DORD);
                break;
        }
    }

    void
    set(const Mode mode)
    {
        switch (mode) {
            case Mode::m0:
                SPCR.clearBit(SPCR.CPHA);
                SPCR.clearBit(SPCR.CPOL);
                break;
            case Mode::m1:
                SPCR.setBit(SPCR.CPHA);
                SPCR.clearBit(SPCR.CPOL);
                break;
            case Mode::m2:
                SPCR.clearBit(SPCR.CPHA);
                SPCR.setBit(SPCR.CPOL);
                break;
            case Mode::m3:
                SPCR.setBit(SPCR.CPHA);
                SPCR.setBit(SPCR.CPOL);
                break;
        }
    }

    void
    Master::communicate(u8 byte, const Target & target)
    {
        set(target.mode);
        set(target.clock);
        set(target.order);
        SPDR = byte;
        SPSR.waitForSetBit(SPSR.SPIF); // Wait for transmission complete
        byte = SPDR.read();
    }

    void
    Master::communicate(const buffer::Bytes & buffer, const Target & target)
    {
        for (u8 & byte : buffer) {
            communicate(byte, target);
        }
    }
};

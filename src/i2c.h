#pragma once

#include "buffer.h"
#include "sfr.h"
#include "units.h"

#include <stdint.h>

namespace I2C {
    auto TWCR = SFR::RegisterRW<SFR::TWCR, uint8_t>();
    auto TWBR = SFR::RegisterRW<SFR::TWBR, uint8_t>();
    auto TWDR = SFR::RegisterRW<SFR::TWDR, uint8_t>();

    const uint8_t ACK  = TWCR.TWEA;
    const uint8_t NACK = 0;

    /*
     * Calculate TWBR register value based on:
     * CPU frequency
     * desired frequency
     * */
    constexpr uint8_t
    calculate_twbr(const Frequency cpu_freq, const Frequency freq)
    {
        return static_cast<uint8_t>(((cpu_freq.value / freq.value) - 16) / 2);
    }

    struct Target {
        /*
        Device address on I2C bus must be written without R/W bit.
        Functions take care of adding appropriate bit at the end.
        Example:
        Slave address is 0x48 which is 01001000 (8 bit in binary).
        For writing into device, address will be converted into 0x90 10010000 (last bit 0 means writing)
        For reading from device, address will be converted into 0x91 10010001 (last bit 1 means reading)
        */
        const uint8_t   address;
        const uint8_t   start_address;
        const Frequency speed;
    };

    void
    start_signal(void)
    {
        TWCR = (TWCR.TWINT | TWCR.TWEN | TWCR.TWSTA);
        TWCR.waitForSetBit(TWCR.TWINT); // Wait for operation to complete.
    }

    void
    stop_signal(void)
    {
        TWCR = (TWCR.TWINT | TWCR.TWEN | TWCR.TWSTO);
        TWCR.waitForSetBit(TWCR.TWSTO); // Wait for operation to complete.
    }

    void
    write_blocking(const uint8_t byte)
    {
        TWDR = byte;
        TWCR = (TWCR.TWINT | TWCR.TWEN);
        TWCR.waitForSetBit(TWCR.TWINT); // Wait until byte is pushed out of register.
    }

    uint8_t
    read_blocking(const uint8_t ack)
    {
        TWCR = (TWCR.TWINT | ack | TWCR.TWEN);
        TWCR.waitForSetBit(TWCR.TWINT); // Wait until byte is present in register.
        return TWDR.read();
    }

    void
    set_speed(const Frequency cpu_freq, const Frequency freq)
    {
        TWBR = calculate_twbr(cpu_freq, freq);
    }

    class Master {
    public:
        const Frequency cpu_freq;

        Master(const Frequency fcpu) :
            cpu_freq(fcpu)
        {
        }

        void
        write(const I2C::Target target, const Buffer::Bytes buffer) const
        {
            set_speed(cpu_freq, target.speed);
            start_signal();
            write_blocking(static_cast<uint8_t>(target.address << 1));
            write_blocking(target.start_address);
            for (uint8_t byte : buffer) {
                write_blocking(byte);
            }
            stop_signal();
        }

        void
        read(const I2C::Target target, const Buffer::Bytes buffer) const
        {
            set_speed(cpu_freq, target.speed);
            start_signal();
            write_blocking(static_cast<uint8_t>(target.address << 1));
            write_blocking(target.start_address);
            start_signal();
            write_blocking(static_cast<uint8_t>((target.address << 1) + 1));
            for (uint8_t & byte : buffer) {
                const uint8_t signal = &byte == buffer.lastElemPtr() ? ACK : NACK;
                byte                 = read_blocking(signal);
            }
            stop_signal();
        }
    };
}

#include <i2c.hpp>

constexpr static auto TWCR = SFR::RegisterRW<SFR::TWCR, u8>();
constexpr static auto TWBR = SFR::RegisterRW<SFR::TWBR, u8>();
constexpr static auto TWDR = SFR::RegisterRW<SFR::TWDR, u8>();

constexpr static u8 ACK  = TWCR.TWEA;
constexpr static u8 NACK = 0;

namespace I2C {

    /*
     * Calculate TWBR register value based on:
     * CPU frequency
     * desired frequency
     * */
    constexpr u8
    calculate_twbr(const Frequency cpu_freq, const Frequency freq)
    {
        return static_cast<u8>(((cpu_freq.value / freq.value) - 16) / 2);
    }

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
    write_blocking(const u8 byte)
    {
        TWDR = byte;
        TWCR = (TWCR.TWINT | TWCR.TWEN);
        TWCR.waitForSetBit(TWCR.TWINT); // Wait until byte is pushed out of register.
    }

    u8
    read_blocking(const u8 ack)
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

    Master::Master(const Frequency fcpu) :
        cpu_freq(fcpu)
    {
    }

    void
    Master::write(const I2C::Target target, const buffer::Bytes buffer) const
    {
        set_speed(cpu_freq, target.speed);
        start_signal();
        write_blocking(static_cast<u8>(target.address << 1));
        write_blocking(target.start_address);
        for (u8 byte : buffer) {
            write_blocking(byte);
        }
        stop_signal();
    }

    void
    Master::read(const I2C::Target target, const buffer::Bytes buffer) const
    {
        set_speed(cpu_freq, target.speed);
        start_signal();
        write_blocking(static_cast<u8>(target.address << 1));
        write_blocking(target.start_address);
        start_signal();
        write_blocking(static_cast<u8>((target.address << 1) + 1));
        for (u8 & byte : buffer) {
            const u8 signal = &byte == buffer.lastElemPtr() ? ACK : NACK;
            byte            = read_blocking(signal);
        }
        stop_signal();
    }

}
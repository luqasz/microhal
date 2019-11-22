#ifndef i2c_h
#define i2c_h

#include "buffer.h"

#include <stdint.h>

namespace I2C {
    auto TWCR = Register<SFR::TWCR>();
    auto TWBR = Register<SFR::TWBR>();
    auto TWDR = Register<SFR::TWDR>();

    const uint8_t ACK  = TWCR.TWEA;
    const uint8_t NACK = 0;

    /* Calculate register value based on desired speed in Hz*/
    constexpr uint8_t
    calculate_twbr(const unsigned long int speed_Hz)
    {
        return static_cast<uint8_t>(((F_CPU / speed_Hz) - 16) / 2);
    }

    enum class Speed : uint8_t {
        kHz100 = calculate_twbr(100000UL),
        kHz400 = calculate_twbr(400000UL),
    };

    struct Target {
        /*
        Device address on I2C bus must be written without R/W bit.
        Functions take care of adding appropriate bit at the end.
        Example:
        Slave address is 0x48 which is 01001000 (8 bit in binary).
        For writing into device, address will be converted into 0x90 10010000 (last bit 0 means writing)
        For reading from device, address will be converted into 0x91 10010001 (last bit 1 means reading)
        */
        const uint8_t    address;
        const uint8_t    start_address;
        const uint8_t    end_address;
        const I2C::Speed speed;
    };

    void
    twcr_wait(const uint8_t bit)
    {
        while (!(TWCR & bit)) {
        };
    }

    void
    start_signal(void)
    {
        TWCR = (TWCR.TWINT | TWCR.TWEN | TWCR.TWSTA);
        twcr_wait(TWCR.TWINT);
    }

    void
    stop_signal(void)
    {
        TWCR = (TWCR.TWINT | TWCR.TWEN | TWCR.TWSTO);
        twcr_wait(TWCR.TWSTO);
    }

    void
    write_blocking(uint8_t byte)
    {
        TWDR = byte;
        TWCR = (TWCR.TWINT | TWCR.TWEN);
        // Wait until byte is pushed out of register.
        twcr_wait(TWCR.TWINT);
    }

    uint8_t
    read_blocking(uint8_t ack)
    {
        TWCR = (TWCR.TWINT | ack | TWCR.TWEN);
        // Wait until byte is present in register.
        twcr_wait(TWCR.TWINT);
        return TWDR;
    }

    void
    set_speed(const I2C::Speed speed)
    {
        TWBR = static_cast<uint8_t>(speed);
    }

    class Master {
    public:
        void
        write(const I2C::Target & target, Buffer::Bytes)
        {
            set_speed(target.speed);
            start_signal();
            write_blocking(static_cast<uint8_t>(target.address << 1));
            write_blocking(target.start_address);
            for (uint8_t byte : buffer) {
                write_blocking(byte);
            }
            stop_signal();
        }

        void
        read(const I2C::Target & target, Buffer::Bytes & buffer)
        {
            set_speed(target.speed);
            start_signal();
            write_blocking(static_cast<uint8_t>(target.address << 1));
            write_blocking(target.start_address);
            start_signal();
            write_blocking(static_cast<uint8_t>((target.address << 1) + 1));
            uint8_t counter = static_cast<uint8_t>(target.end_address - target.start_address);
            for (auto & value : buffer) {
                counter--;
                value = read_blocking(counter ? ACK : NACK);
            }
            stop_signal();
        }
    };
}

#endif

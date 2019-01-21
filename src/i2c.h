#ifndef i2c_h
#define i2c_h

#include "buffer.h"

#include <stdint.h>

namespace I2C {

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
        const uint8_t address;
        const uint8_t start_address;
        const uint8_t end_address;
        const I2C::Speed speed;
    };

    class Master {
    public:
        void read(const I2C::Target &, Buffer::Interface::ArrayWrapper &);
        void write(const I2C::Target &, Buffer::Interface::ArrayWrapper &);
    };

}

#endif

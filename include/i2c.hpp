#pragma once

#include "buffer.hpp"
#include "sfr.hpp"
#include "types.hpp"
#include "units.hpp"

namespace i2c {

    struct Target {
        /*
        Device address on I2C bus must be written without R/W bit.
        Functions take care of adding appropriate bit at the end.
        Example:
        Slave address is 0x48 which is 01001000 (8 bit in binary).
        For writing into device, address will be converted into 0x90 10010000 (last bit 0 means writing)
        For reading from device, address will be converted into 0x91 10010001 (last bit 1 means reading)
        */
        const u8        address;
        const u8        start_address;
        const Frequency speed;
    };

    class Master {
    public:
        const Frequency cpu_freq;
        Master(const Frequency fcpu);

        void
        write(const buffer::Slice<u8> & buffer, const Target & target) const;

        void
        read(const buffer::Slice<u8> & buffer, const Target & target) const;
    };
}

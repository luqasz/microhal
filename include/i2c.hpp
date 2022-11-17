#pragma once

#include "buffer.hpp"
#include "sfr.hpp"
#include "types.hpp"
#include "units.hpp"
#include "iomem.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/i2c.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/i2c.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/i2c.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

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
        const u8               address;
        const u8               start_address;
        const units::Frequency speed;
    };

    /*
     * Calculate TWBR register value based on:
     * CPU frequency
     * desired frequency
     * */
    constexpr u8
    calculate_twbr(const units::Frequency cpu_freq, const units::Frequency bus_freq)
    {
        return static_cast<u8>((((cpu_freq / bus_freq) - 16) / 2).value);
    }

    template <typename INSTANCE>
    class Master {
    public:
        const units::Frequency cpu_freq;

        Master(const units::Frequency fcpu) :
            cpu_freq(fcpu)
        {
        }

        void
        start_signal(void) const
        {
            constexpr u8 bits = (INSTANCE::twcr::TWINT | INSTANCE::twcr::TWEN | INSTANCE::twcr::TWSTA);
            iomem::write<u8>(INSTANCE::twcr::address, bits);
            // Wait for operation to complete.
            iomem::set_bit_wait(INSTANCE::twcr::address, INSTANCE::twcr::TWINT);
        }

        void
        stop_signal(void) const
        {
            constexpr u8 bits = (INSTANCE::twcr::TWINT | INSTANCE::twcr::TWEN | INSTANCE::twcr::TWSTO);
            iomem::write<u8>(INSTANCE::twcr::address, bits);
            // Wait until byte is pushed out of register.
            iomem::set_bit_wait(INSTANCE::twcr::address, INSTANCE::twcr::TWSTO);
        }

        void
        write_blocking(const u8 byte) const
        {
            iomem::write<u8>(INSTANCE::twdr::address, byte);
            constexpr u8 bits = (INSTANCE::twcr::TWINT | INSTANCE::twcr::TWEN);
            iomem::write<u8>(INSTANCE::twcr::address, bits);
            // Wait until byte is pushed out of register.
            iomem::set_bit_wait(INSTANCE::twcr::address, INSTANCE::twcr::TWINT);
        }

        u8
        read_blocking(const u8 ack) const
        {
            const u8 bits = (INSTANCE::twcr::TWINT | INSTANCE::twcr::TWEN | ack);
            iomem::write<u8>(INSTANCE::twcr::address, bits);
            // Wait until byte is present in register.
            iomem::set_bit_wait(INSTANCE::twcr::address, INSTANCE::twcr::TWINT);
            return iomem::read<u8>(INSTANCE::twdr::address);
        }

        void
        set_speed(const units::Frequency freq) const
        {
            iomem::write<u8>(INSTANCE::twbr::address, calculate_twbr(cpu_freq, freq));
        }

        void
        write(buffer::Span<const u8> buffer, const i2c::Target target) const
        {
            set_speed(target.speed);
            start_signal();
            write_blocking(static_cast<u8>(target.address << 1));
            write_blocking(target.start_address);
            for (u8 byte : buffer) {
                write_blocking(byte);
            }
            stop_signal();
        }

        void
        read(buffer::Span<u8> buffer, const i2c::Target target) const
        {
            usize elems = buffer.size();
            auto  elem  = buffer.begin();
            set_speed(target.speed);
            start_signal();
            write_blocking(static_cast<u8>(target.address << 1));
            write_blocking(target.start_address);
            start_signal();
            write_blocking(static_cast<u8>((target.address << 1) + 1));
            while (elems--) {
                *elem++ = read_blocking(elems ? INSTANCE::ACK : INSTANCE::NACK);
            }
            stop_signal();
        }
    };

}

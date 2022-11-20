#pragma once
#include "../../../types.hpp"
#include "../../../gpio.hpp"
#include "../../../iomem.hpp"

namespace gpio {

    enum PinNumber : u8 {
        Pin0 = 0x01,
        Pin1 = 0x02,
        Pin2 = 0x04,
        Pin3 = 0x08,
        Pin4 = 0x10,
        Pin5 = 0x20,
        Pin6 = 0x40,
        Pin7 = 0x80,
    };

    enum PullMode {
        HiZ    = 0,
        None   = HiZ,
        PullUp = 1,
    };

    struct Port {
        const usize port_address;
        const usize pin_address;
        const usize ddr_address;
    };

    struct Pin {
        const Port      port;
        const PinNumber number;
    };

    struct Bus8Bit {
        const Port port;

        constexpr Bus8Bit(const Port p) :
            port(p) { }

        void
        write(const u8 byte) const
        {
            iomem::write<u8>(port.ddr_address, 255);
            iomem::write<u8>(port.port_address, byte);
        }

        u8
        read() const
        {
            iomem::write<u8>(port.ddr_address, 0);
            return iomem::read<u8>(port.pin_address);
        }
    };

    struct Output {
        const Pin pin;

        Output(const Pin p) :
            pin(p)
        {
            iomem::set_bit<u8>(pin.port.ddr_address, pin.number);
        }

        void
        set(const State state) const
        {
            iomem::set_bit<u8>(pin.port.port_address, static_cast<u8>(state), pin.number);
        }

        void
        toggle() const
        {
            iomem::xor_bit<u8>(pin.port.port_address, pin.number);
        }

        void
        operator=(const State state) const
        {
            set(state);
        }
    };

    struct Input {
        const Pin pin;

        Input(const Pin p) :
            pin(p)
        {
            iomem::clear_bit<u8>(pin.port.ddr_address, pin.number);
        }

        void
        set(const PullMode mode) const
        {
            iomem::set_bit<u8>(pin.port.ddr_address, static_cast<u8>(mode), pin.number);
        }

        bool
        operator==(const State state) const
        {
            return (iomem::read<u8>(pin.port.pin_address) & pin.number) == state;
        }
    };
}

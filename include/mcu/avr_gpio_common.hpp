#pragma once
#include "../types.hpp"
#include "../gpio.hpp"

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
        HiZ,
        PullUp,
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
        void virtual write(const u8 byte) const = 0;
        u8 virtual read() const                 = 0;
    };

    struct PortBus : public Bus8Bit {
        const Port port;

        constexpr PortBus(const Port & p) :
            port(p) { }

        virtual void
        write(const u8 byte) const final
        {
            SFR::iomem<u8>(port.ddr_address)  = 255;
            SFR::iomem<u8>(port.port_address) = byte;
        }

        virtual u8
        read() const final
        {
            SFR::iomem<u8>(port.ddr_address) = 0;
            return SFR::iomem<u8>(port.pin_address);
        }
    };

    struct Output {
        const Pin pin;

        Output(const Pin & p);

        void
        operator=(const State state) const;

        const Output &
        set(const State state) const;

        void
        toggle() const;
    };

    struct Input {
        const Pin pin;

        Input(const Pin & p);

        const Input &
        set(const PullMode mode) const;

        bool
        operator==(const State state) const;
    };
}

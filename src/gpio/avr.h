#pragma once
#include <stdint.h>

namespace GPIO {

    enum PinNumber : uint8_t {
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
        const uint16_t port_address;
        const uint16_t pin_address;
        const uint16_t ddr_address;
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
        write(const uint8_t byte) const
        {
            SFR::iomem<uint8_t>(port.ddr_address)  = 255;
            SFR::iomem<uint8_t>(port.port_address) = byte;
        }

        uint8_t
        read() const
        {
            SFR::iomem<uint8_t>(port.ddr_address) = 0;
            return SFR::iomem<uint8_t>(port.pin_address);
        }
    };
}

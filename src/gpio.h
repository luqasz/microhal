#pragma once

#include "sfr.h"

#include <stdint.h>

namespace GPIO {

    enum PinNumber {
        Pin0 = 0x01,
        Pin1 = 0x02,
        Pin2 = 0x04,
        Pin3 = 0x08,
        Pin4 = 0x10,
        Pin5 = 0x20,
        Pin6 = 0x40,
        Pin7 = 0x80,
    };

    enum Mode {
        Output,
        Input,
    };

    enum PinState {
        Low,
        High,
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
    public:
        const GPIO::Port      port;
        const GPIO::PinNumber number;
    };

    void
    set(const Pin pin, const Mode mode)
    {
        switch (mode) {
            case Output:
                SFR::setBit(pin.port.ddr_address, pin.number);
                break;
            case Input:
                SFR::clearBit(pin.port.ddr_address, pin.number);
                break;
        }
    }

    void
    write(const Pin pin, const PinState state)
    {
        switch (state) {
            case PinState::High:
                SFR::setBit(pin.port.port_address, pin.number);
                break;
            case PinState::Low:
                SFR::clearBit(pin.port.port_address, pin.number);
                break;
        }
    }

    void
    toggle(const Pin pin)
    {
        SFR::iomem<uint8_t>(pin.port.port_address) ^= pin.number;
    }

    PinState
    read(const Pin pin)
    {
        if (SFR::iomem<uint8_t>(pin.port.pin_address) & pin.number) {
            return GPIO::PinState::High;
        }
        return GPIO::PinState::Low;
    }

    void
    set(const Port port, const Mode mode)
    {
        switch (mode) {
            case Output:
                SFR::iomem<uint8_t>(port.ddr_address) = 255;
                break;
            case Input:
                SFR::iomem<uint8_t>(port.ddr_address) = 0;
                break;
        }
    }

    void
    write(const Port port, const uint8_t value)
    {
        SFR::iomem<uint8_t>(port.port_address) = value;
    }

    uint8_t
    read(const Port port)
    {
        return SFR::iomem<uint8_t>(port.pin_address);
    }

    void
    set(const Port port, const PullMode mode)
    {
        switch (mode) {
            case PullMode::HiZ:
                SFR::iomem<uint8_t>(port.port_address) = 0;
                break;
            case PullMode::PullUp:
                SFR::iomem<uint8_t>(port.port_address) = 255;
                break;
        }
    }

}

#include <mcu_gpio.h>

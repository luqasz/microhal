#ifndef gpio_h
#define gpio_h

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

    enum class PinState {
        Low,
        High,
    };

    enum class PullMode {
        HiZ,
        PullUp,
    };

    class Output8Bit;
    class Input8Bit;

    struct Port {
        const uint16_t port_address;
        const uint16_t pin_address;
        const uint16_t ddr_address;

        Output8Bit output() const;
        Input8Bit  input() const;
    };

    class OutputPin;
    class InputPin;

    struct Pin {
    public:
        const GPIO::Port      port;
        const GPIO::PinNumber number;
        OutputPin             output() const;
        InputPin              input() const;
    };

    class OutputPin {
        const Pin pin;

    public:
        OutputPin(const Pin & pin) :
            pin(pin)
        {
            SFR::setBit<uint8_t>(pin.port.ddr_address, pin.number);
        }

        void
        operator=(const GPIO::PinState state) const
        {
            set(state);
        }

        void
        set(const GPIO::PinState state) const
        {
            switch (state) {
                case GPIO::PinState::High:
                    SFR::setBit<uint8_t>(pin.port.port_address, pin.number);
                    break;
                case GPIO::PinState::Low:
                    SFR::clearBit<uint8_t>(pin.port.port_address, pin.number);
                    break;
            }
        }
    };

    class InputPin {
        const GPIO::Pin pin;

    public:
        InputPin(const Pin & pin) :
            pin(pin)
        {
            SFR::clearBit<uint8_t>(pin.port.ddr_address, pin.number);
        }

        bool
        operator==(const GPIO::PinState state) const
        {
            return read() == state;
        }

        void
        set(const GPIO::PullMode mode) const
        {
            switch (mode) {
                case GPIO::PullMode::HiZ:
                    SFR::clearBit<uint8_t>(pin.port.port_address, pin.number);
                    break;
                case GPIO::PullMode::PullUp:
                    SFR::setBit<uint8_t>(pin.port.port_address, pin.number);
                    break;
            }
        }

        PinState
        read() const
        {
            if (SFR::iomem<uint8_t>(pin.port.pin_address) & pin.number) {
                return GPIO::PinState::High;
            }
            return GPIO::PinState::Low;
        }
    };

    class Output8Bit {
        const GPIO::Port port;

    public:
        Output8Bit(const GPIO::Port & port) :
            port(port)
        {
            SFR::iomem<uint8_t>(port.ddr_address) = 255;
        }

        void
        operator=(const uint8_t value) const
        {
            write(value);
        }

        void
        write(const uint8_t value) const
        {
            SFR::iomem<uint8_t>(port.port_address) = value;
        }
    };

    class Input8Bit {
        const GPIO::Port port;

    public:
        Input8Bit(const GPIO::Port & port) :
            port(port)
        {
            SFR::iomem<uint8_t>(port.ddr_address) = 0;
        }

        bool
        operator==(const uint8_t value) const
        {
            return read() == value;
        }

        uint8_t
        read() const
        {
            return SFR::iomem<uint8_t>(port.pin_address);
        }

        void
        set(const GPIO::PullMode mode) const
        {
            switch (mode) {
                case GPIO::PullMode::HiZ:
                    SFR::iomem<uint8_t>(port.port_address) = 0;
                    break;
                case GPIO::PullMode::PullUp:
                    SFR::iomem<uint8_t>(port.port_address) = 255;
                    break;
            }
        }
    };

    Output8Bit
    Port::output() const
    {
        return Output8Bit(*this);
    }

    Input8Bit
    Port::input() const
    {
        return Input8Bit(*this);
    }

    OutputPin
    Pin::output() const
    {
        return OutputPin(*this);
    }

    InputPin
    Pin::input() const
    {
        return InputPin(*this);
    }
}

#include <mcu_gpio.h>

#endif

#include "gpio.h"

#include "sfr.h"

GPIO::InputPin::InputPin(const GPIO::Pin pin) :
    pin(pin)
{
    SFR::clearBit(pin.port.ddr_address, pin.number);
}

void
GPIO::InputPin::set(const GPIO::PullMode mode) const
{
    switch (mode) {
        case GPIO::PullMode::HiZ:
            SFR::clearBit(pin.port.port_address, pin.number);
            break;
        case GPIO::PullMode::PullUp:
            SFR::setBit(pin.port.port_address, pin.number);
            break;
    }
}

bool
GPIO::InputPin::operator==(const GPIO::PinState state) const
{
    return read() == state;
}

GPIO::PinState
GPIO::InputPin::read() const
{
    if (SFR::iomem(pin.port.pin_address) & pin.number) {
        return GPIO::PinState::High;
    }
    return GPIO::PinState::Low;
}

GPIO::OutputPin::OutputPin(GPIO::Pin pin) :
    pin(pin)
{
    SFR::setBit(pin.port.ddr_address, pin.number);
}

void
GPIO::OutputPin::operator=(const GPIO::PinState state) const
{
    set(state);
}

void
GPIO::OutputPin::set(const GPIO::PinState state) const
{
    switch (state) {
        case GPIO::PinState::High:
            SFR::setBit(pin.port.port_address, pin.number);
            break;
        case GPIO::PinState::Low:
            SFR::clearBit(pin.port.port_address, pin.number);
            break;
    }
}

GPIO::Output8Bit::Output8Bit(GPIO::Port port) :
    port(port)
{
    SFR::iomem(port.ddr_address) = 255;
}

void
GPIO::Output8Bit::operator=(const uint8_t value) const
{
    set(value);
}

void
GPIO::Output8Bit::set(const uint8_t value) const
{
    SFR::iomem(port.port_address) = value;
}

GPIO::Input8Bit::Input8Bit(const GPIO::Port port) :
    port(port)
{
    SFR::iomem(port.ddr_address) = 0;
}

bool
GPIO::Input8Bit::operator==(const uint8_t value) const
{
    return read() == value;
}

uint8_t
GPIO::Input8Bit::read() const
{
    return SFR::iomem(port.pin_address);
}

void
GPIO::Input8Bit::set(const GPIO::PullMode mode) const
{
    switch (mode) {
        case GPIO::PullMode::HiZ:
            SFR::iomem(port.port_address) = 0;
            break;
        case GPIO::PullMode::PullUp:
            SFR::iomem(port.port_address) = 255;
            break;
    }
}

GPIO::OutputPin
GPIO::Pin::output() const
{
    return GPIO::OutputPin(*this);
}

GPIO::InputPin
GPIO::Pin::input() const
{
    return GPIO::InputPin(*this);
}

GPIO::Output8Bit
GPIO::Port::output() const
{
    return GPIO::Output8Bit(*this);
}

GPIO::Input8Bit
GPIO::Port::input() const
{
    return GPIO::Input8Bit(*this);
}
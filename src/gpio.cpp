#include "gpio.h"

#include "sfr.h"

GPIO::InputPin::InputPin(const GPIO::Pin pin) :
    pin(pin)
{
    SFR::clearBit(pin.port.ddr_address, pin.number);
}

void
GPIO::InputPin::set(GPIO::PullMode mode)
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
GPIO::InputPin::operator==(const GPIO::PinState state)
{
    return read() == state;
}

GPIO::PinState
GPIO::InputPin::read()
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
GPIO::OutputPin::operator=(const GPIO::PinState state)
{
    set(state);
}

bool
GPIO::OutputPin::operator==(const GPIO::PinState state)
{
    return read() == state;
}

void
GPIO::OutputPin::set(const GPIO::PinState state)
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

GPIO::PinState
GPIO::OutputPin::read()
{
    if (SFR::iomem(pin.port.port_address) & pin.number) {
        return GPIO::PinState::High;
    }
    return GPIO::PinState::Low;
}

GPIO::Output8Bit::Output8Bit(GPIO::Port port) :
    port(port)
{
    SFR::iomem(port.ddr_address) = 255;
}

void
GPIO::Output8Bit::operator=(const uint8_t value)
{
    set(value);
}

bool
GPIO::Output8Bit::operator==(const uint8_t value)
{
    return read() == value;
}

void
GPIO::Output8Bit::set(const uint8_t value)
{
    SFR::iomem(port.port_address) = value;
}

uint8_t
GPIO::Output8Bit::read(void)
{
    return SFR::iomem(port.port_address);
}

GPIO::Input8Bit::Input8Bit(const GPIO::Port port) :
    port(port)
{
    SFR::iomem(port.ddr_address) = 0;
}

bool
GPIO::Input8Bit::operator==(const uint8_t value)
{
    return read() == value;
}

uint8_t
GPIO::Input8Bit::read()
{
    return SFR::iomem(port.pin_address);
}

void
GPIO::Input8Bit::set(const GPIO::PullMode mode)
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
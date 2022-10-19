#include <gpio.hpp>

namespace gpio {

    Output::Output(const Pin & p) :
        pin(p)
    {
        SFR::setBit(pin.port.ddr_address, pin.number);
    }

    void
    Output::operator=(const State state) const
    {
        switch (state) {
            case State::High:
                SFR::setBit(pin.port.port_address, pin.number);
                break;
            case State::Low:
                SFR::clearBit(pin.port.port_address, pin.number);
                break;
        }
    }

    const Output &
    Output::set(const State state) const
    {
        *this = state;
        return *this;
    }

    void
    Output::toggle() const
    {
        SFR::iomem<u8>(pin.port.port_address) ^= pin.number;
    }

    Input::Input(const Pin & p) :
        pin(p)
    {
        SFR::clearBit(pin.port.ddr_address, pin.number);
    }

    const Input &
    Input::set(const PullMode mode) const
    {
        switch (mode) {
            case PullMode::PullUp:
                SFR::setBit(pin.port.ddr_address, pin.number);
                break;
            case PullMode::HiZ:
                SFR::clearBit(pin.port.ddr_address, pin.number);
                break;
        }
        return *this;
    }

    bool
    Input::operator==(const State state) const
    {
        return (SFR::iomem<u8>(pin.port.pin_address) & pin.number) == state;
    }

}
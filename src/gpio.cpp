#include <gpio.hpp>

namespace GPIO {

    Output::Output(const Pin & p, const State & s) :
        on_state(s),
        pin(p)
    {
        SFR::setBit(pin.port.ddr_address, pin.number);
    }

    void
    Output::operator=(const State state) const
    {
        set_state(state);
    }

    void
    Output::operator=(const Logic logic) const
    {
        switch (logic) {
            case Logic::On:
                set_state(on_state);
                break;
            case Logic::Off:
                set_state(static_cast<State>(!on_state));
                break;
        }
    }

    void
    Output::toggle() const
    {
        SFR::iomem<u8>(pin.port.port_address) ^= pin.number;
    }

    void
    Output::set_state(const State state) const
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

    Input::Input(const Pin p, const State s) :
        on_state(s),
        pin(p)
    {
        SFR::clearBit(pin.port.ddr_address, pin.number);
    }

    void
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
    }

    bool
    Input::operator==(const Logic logic) const
    {
        const auto state = read_state();
        switch (logic) {
            case Logic::On:
                return state == on_state;
                break;
            case Logic::Off:
                return state != on_state;
                break;
        }
        return false;
    }

    bool
    Input::operator==(const State state) const
    {
        return read_state() == state;
    }

    bool
    Input::read_state() const
    {
        return SFR::iomem<u8>(pin.port.pin_address) & pin.number;
    };

}
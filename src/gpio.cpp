#include <gpio.hpp>
#include <iomem.hpp>

namespace gpio {

    Output::Output(const Pin p) :
        pin(p)
    {
        iomem::set_bit<u8>(pin.port.ddr_address, pin.number);
    }

    void
    Output::operator=(const State state) const
    {
        switch (state) {
            case State::High:
                iomem::set_bit<u8>(pin.port.port_address, pin.number);
                break;
            case State::Low:
                iomem::clear_bit<u8>(pin.port.port_address, pin.number);
                break;
        }
    }

    void
    Output::set(const State state) const
    {
        *this = state;
    }

    void
    Output::toggle() const
    {
        iomem::xor_bit<u8>(pin.port.port_address, pin.number);
    }

    Input::Input(const Pin p) :
        pin(p)
    {
        iomem::clear_bit<u8>(pin.port.ddr_address, pin.number);
    }

    void
    Input::set(const PullMode mode) const
    {
        iomem::set_bit<u8>(pin.port.ddr_address, static_cast<u8>(mode), pin.number);
    }

    bool
    Input::operator==(const State state) const
    {
        return (iomem::read<u8>(pin.port.pin_address) & pin.number) == state;
    }

}
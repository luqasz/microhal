#include <drivers/mcp49xx.hpp>

namespace MCP49x2 {
    constexpr u16 SHUTDOWN_MASK = 0xEFFF;
    constexpr u16 ENABLE_BIT    = 0x1000;

    void
    DAC::set(Gain gain)
    {
        switch (gain) {
            case Gain::x1:
                bits |= 0x2000;
                break;
            case Gain::x2:
                bits &= 0xcfff;
                break;
        }
    }

    void
    DAC::set(BufferControl ctl)
    {
        switch (ctl) {
            case BufferControl::Unbuffered:
                bits &= 0xbfff;
                break;
            case BufferControl::Buffered:
                bits |= 0x4000;
                break;
        }
    }

    void
    DAC::enable()
    {
        bits |= ENABLE_BIT;
    }

    void
    DAC::disable()
    {
        bits &= SHUTDOWN_MASK;
    }

    MCP4922::MCP4922(Channel channel)
    {
        switch (channel) {
            case Channel::A:
                bits = 0;
                break;
            case Channel::B:
                bits = 0x8000;
                break;
        }
        enable();
    }

    void
    MCP4922::operator=(u16 value)
    {
        value &= 0x0FFF;
        bits |= value;
    }
}

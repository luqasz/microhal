#include "mcp49xx.h"

#include <stdint.h>

const uint16_t SHUTDOWN_MASK = 0xEFFF;
const uint16_t ENABLE_BIT    = 0x1000;

void
MCP49x2::DAC::set(MCP49x2::Gain gain)
{
    switch (gain) {
        case MCP49x2::Gain::x1:
            bits |= 0x2000;
            break;
        case MCP49x2::Gain::x2:
            bits &= 0xcfff;
            break;
    }
}

void
MCP49x2::DAC::set(MCP49x2::BufferControl ctl)
{
    switch (ctl) {
        case MCP49x2::BufferControl::Unbuffered:
            bits &= 0xbfff;
            break;
        case MCP49x2::BufferControl::Buffered:
            bits |= 0x4000;
            break;
    }
}

void
MCP49x2::DAC::enable()
{
    bits |= ENABLE_BIT;
}

void
MCP49x2::DAC::disable()
{
    bits &= SHUTDOWN_MASK;
}

MCP49x2::MCP4922::MCP4922(MCP49x2::Channel channel)
{
    switch (channel) {
        case MCP49x2::Channel::A:
            bits = 0;
            break;
        case MCP49x2::Channel::B:
            bits = 0x8000;
            break;
    }
    enable();
}

void
MCP49x2::MCP4922::operator=(uint16_t value)
{
    value &= 0x0FFF;
    bits |= value;
}

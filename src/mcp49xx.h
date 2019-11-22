#ifndef mcp49xx_h
#define mcp49xx_h

#include <stdint.h>

namespace MCP49x2 {
    constexpr uint16_t SHUTDOWN_MASK = 0xEFFF;
    constexpr uint16_t ENABLE_BIT    = 0x1000;

    enum class Channel {
        A,
        B,
    };

    enum class BufferControl {
        Buffered,
        Unbuffered,
    };

    enum class Gain {
        x1,
        x2,
    };

    class DAC {
        uint16_t bits = 0;

    public:
        void
        set(Gain gain)
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
        set(BufferControl ctl)
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
        enable()
        {
            bits |= ENABLE_BIT;
        }

        void
        disable()
        {
            bits &= SHUTDOWN_MASK;
        }
    };

    class MCP4922 : public DAC {
    public:
        MCP4922(Channel channel)
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
        operator=(uint16_t value)
        {
            value &= 0x0FFF;
            bits |= value;
        }
    };

}

#endif

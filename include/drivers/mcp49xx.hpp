#pragma once

#include "../types.hpp"

namespace MCP49x2 {

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
    public:
        u16 bits = 0;

        void
        set(Gain gain);

        void
        set(BufferControl ctl);

        void
        enable();

        void
        disable();
    };

    class MCP4922 : public DAC {
    public:
        MCP4922(Channel channel);

        void
        operator=(u16 value);
    };

}

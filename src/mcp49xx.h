#ifndef mcp49x2_h
#define mcp49x2_h

#include <stdint.h>

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
        uint16_t bits = 0;

    public:
        void set(const MCP49x2::Gain);
        void set(const MCP49x2::BufferControl);
        void disable(void);
        void enable(void);
    };

    class MCP4922 : public MCP49x2::DAC {
    public:
        MCP4922(MCP49x2::Channel);
        void operator=(const uint16_t);
    };

}

#endif

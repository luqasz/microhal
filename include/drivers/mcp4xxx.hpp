#pragma once

#include "../types.hpp"
#include "../defs.hpp"

namespace mcp4xxx {

    enum Channel : u16 {
        A = 0,
        B = 0x8080,
        Single = 0, // DACs with single output.
    };

    // VREF Input buffer control.
    enum BufferCtrl : u16 {
        Buffered = 0x4000,
        Unbuffered = 0,
        None = 0, // DACs without any buffer control.
    };

    enum Gain : u16 {
        x1 = 0x2000,
        x2 = 0,
    };

    enum State : u16 {
        Off = 0,
        On = 0x1000,
    };

    struct CtrllBits {
        Channel ch;
        BufferCtrl buf;
        Gain gain;
        State state;

        constexpr explicit
        operator u16() const
        {
            return u16(ch) | u16(buf) | u16(gain) | u16(state);
        }
    };

    // Return bits ready to be sent over SPI bus.
    template <const usize bits>
    requires(bits == 10 or bits == 12 or bits == 8)
    CONSTFN constexpr u16
    cmd(const CtrllBits & ctrl, u16 value)
    {
        if constexpr (bits == 10) {
            value <<= 2;
        }
        else if (bits == 8) {
            value <<= 4;
        }
        // Mask ignoring all control bits.
        constexpr u16 mask = 4095;
        return u16(ctrl) | (mask & value);
    }

}

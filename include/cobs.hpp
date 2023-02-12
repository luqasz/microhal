#pragma once

#include <types.hpp>
#include <buffer.hpp>

namespace cobs {

    constexpr usize
    encode(const buffer::Span<const u8> in, buffer::Span<u8> out)
    {
        usize zero = 0;
        usize dst  = 1;
        for (const u8 & src : in) {
            if (src == 0) {
                out[zero] = static_cast<u8>(dst - zero);
                zero      = dst;
                dst += 1;
            }
            else {
                out[dst] = src;
                dst += 1;
                if (dst - zero == 255) {
                    out[zero] = static_cast<u8>(dst - zero);
                    zero      = dst;
                    dst += 1;
                }
            }
        }
        out[zero] = static_cast<u8>(dst - zero);
        out[dst]  = 0;
        return dst + 1;
    }

    constexpr usize
    decode(const buffer::Span<const u8> in, buffer::Span<u8> out)
    {
        // Out span index.
        usize dst    = 0;
        usize in_pos = 0;
        while (in_pos < in.size()) {
            // Number of bytes to copy.
            const usize block_size = in[in_pos++] - 1;
            for (const u8 & src : in.slice(in_pos, block_size)) {
                if (src == 0) {
                    // Encoded block can't have 0 inside.
                    return 0;
                }
                out[dst++] = src;
            }
            in_pos += block_size;
            if (in[in_pos] == 0) {
                break;
            }
            if (block_size < 254) {
                out[dst++] = 0;
            }
        }
        return dst;
    }

}

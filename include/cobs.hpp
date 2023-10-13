#pragma once

#include <types.hpp>
#include <buffer.hpp>

/*
Search through the first 254 bytes of the packet looking for the first occurrence of a zero byte.
If no zero is found, then a code of 0xFF is output, followed by the 254 non-zero bytes.
If a zero is found, then the number of bytes examined, n, is output as the code byte,
followed by the non-zero bytes up to, but not including, the zero byte.
The zero is then skipped and this process is repeated until all the bytes of the packet
(including the final zero which is logically appended to every packet) have been encoded.
*/

namespace cobs {

    constexpr const u8 *
    cobs_end(const u8 * begin, const u8 * end)
    {
        const u8 * ptr = begin;
        while (ptr != end) {
            if (*ptr == 0 or (ptr - begin) == 254) {
                break;
            }
            ptr++;
        }
        return ptr;
    }

    template <Writer DST>
    requires Assignable<u8, typename DST::ContainedType>
    constexpr usize
    encode(const buffer::Span<const u8> in, DST & out)
    {
        const u8 * current = in.begin();
        const usize free_start = out.free();
        while (current < in.end()) {
            const u8 * end = cobs_end(current, in.end());
            const u8 len = u8(end - current);
            out.write(len + 1);
            while (current < end) {
                out.write(*current++);
            }
            if (len < 254) {
                current++;
            }
        }
        out.write(0);
        return free_start - out.free();
    }

    constexpr usize
    encode(const buffer::Span<const u8> in, buffer::Span<u8> out)
    {
        const u8 * current = in.begin();
        usize wrote = 0;
        while (current < in.end()) {
            const u8 * end = cobs_end(current, in.end());
            const u8 len = u8(end - current);
            out[wrote++] = len + 1;
            while (current < end) {
                out[wrote++] = *current++;
            }
            if (len < 254) {
                current++;
            }
        }
        out[wrote++] = 0;
        return wrote;
    }

    constexpr usize
    decode(const buffer::Span<const u8> in, buffer::Span<u8> out)
    {
        // Out span index.
        usize dst = 0;
        usize in_pos = 0;
        while (in_pos < in.size()) {
            // Number of bytes to copy.
            const usize block_size = in[in_pos++] - 1;
            for (const u8 & src : in.span(in_pos, block_size)) {
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

    // Return required packet size based on input size.
    constexpr usize
    required_encoded_size(usize source_len)
    {
        const usize end = source_len % 254 > 0 ? 1 : 0;
        return source_len + (source_len / 254) + end;
    }

}

#pragma once

#include "types.hpp"
#include "buffer.hpp"
#include <stdio.h>

namespace fmt {
    struct LineEnd {
        constexpr static char CRLF[] = "\r\n";
        constexpr static char LF[]   = "\n";
        constexpr static char CR[]   = "\r";
        constexpr static char None[] = "";
    };

    // Return given number str len in base 10.
    constexpr usize
    numlen10(auto num)
    {
        usize len = 0;
        while (num != 0) {
            len += 1;
            num /= 10;
        }
        return len;
    }

    // Convert number into string and write it to buffer.
    constexpr void
    str(buffer::Span<char> buf, u32 num)
    {
        constexpr char map[] = "0123456789";
        usize          idx   = numlen10(num);
        buf[idx--]           = '\0';
        while (num != 0) {
            buf[idx--] = map[num % 10];
            num /= 10;
        }
    }
}
#pragma once

#include "types.hpp"

#include <stdio.h>

namespace LineEnd {
    constexpr char CRLF[] = "\r\n";
    constexpr char LF[]   = "\n";
    constexpr char CR[]   = "\r";
    constexpr char None[] = "";
}

template <typename WriterType>
struct Printer {
    constexpr static usize BufferSize = 12;
    WriterType &           output;
    char                   buf[12] = { 0 };
    const char * const     line_end;

    constexpr Printer(WriterType & o, const char * le) :
        output(o),
        line_end(le)
    {
    }

    void
    print(const char * string) const
    {
        u8 c;
        while ((c = static_cast<u8>(*string++))) {
            output.write(c);
        }
    }

    void
    printLn(const char * string) const
    {
        print(string);
        print(line_end);
    }

    void
    print(const usize num)
    {
        snprintf(buf, BufferSize, "%zu", num);
        print(buf);
    }

    void
    printLn(const usize num)
    {
        snprintf(buf, BufferSize, "%zu", num);
        print(buf);
        print(line_end);
    }
};

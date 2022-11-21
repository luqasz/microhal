#pragma once

#include "types.hpp"
#include "fmt.hpp"
#include "buffer.hpp"

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
    char                   buf[BufferSize] = { 0 };
    const char * const     line_end;

    constexpr Printer(WriterType & o, const char * le) :
        output(o),
        line_end(le)
    {
    }

    void
    print(const char * string) const
    {
        output.print(string);
    }

    void
    printLn(const char * string) const
    {
        output.print(string);
        print(line_end);
    }

    void
    print(const usize num)
    {
        fmt::str(buf, num);
        print(buf);
    }

    void
    printLn(const usize num)
    {
        fmt::str(buf, num);
        printLn(buf);
    }
};

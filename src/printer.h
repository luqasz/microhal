#pragma once

#include "interface.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

namespace LineEnd {
    constexpr char CRLF[] = "\r\n";
    constexpr char LF[]   = "\n";
    constexpr char CR[]   = "\r";
    constexpr char None[] = "";
}

struct Printer {
    Writer &           output;
    char               buf[12] = { 0 };
    const char * const line_end;

    constexpr Printer(Writer & o, const char * const le) :
        output(o),
        line_end(le) { }

    void
    print(const char * string)
    {
        uint8_t c;
        while ((c = static_cast<uint8_t>(*string++))) {
            output.write(c);
        }
    }

    void
    printLn(const char * string)
    {
        print(string);
        print(line_end);
    }

    void
    print(const unsigned long int num)
    {
        ultoa(num, buf, 10);
        print(buf);
    }

    void
    printLn(const unsigned long int num)
    {
        ultoa(num, buf, 10);
        print(buf);
        print(line_end);
    }
};

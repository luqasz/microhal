#pragma once

#include "interface.hpp"
#include "types.hpp"

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
    print(const char * string) const;

    void
    printLn(const char * string) const;

    void
    print(const unsigned long int num);

    void
    printLn(const unsigned long int num);
};

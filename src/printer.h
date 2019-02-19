#ifndef printer_h
#define printer_h

#include <stdint.h>
#include <stdlib.h>

struct RN {
    constexpr static char lineEnd[] = "\r\n";
};

struct None {
    constexpr static char lineEnd[] = "";
};

template <typename Output, typename LE = None>
struct Printer : LE {
    Output output;
    char   buf[8];
    Printer(Output o) :
        output(o) {}

    constexpr void
    print(const char * string)
    {
        output.write(string);
    }

    constexpr void
    printLn(const char * string)
    {
        print(string);
        print(LE::lineEnd);
    }

    void
    print(const uint32_t num)
    {
        itoa(static_cast<int>(num), buf, 10);
        print(buf);
    }

    void
    printLn(const uint32_t num)
    {
        itoa(static_cast<int>(num), buf, 10);
        print(buf);
        print(LE::lineEnd);
    }
};

#endif
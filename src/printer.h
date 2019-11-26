#ifndef printer_h
#define printer_h

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct RN {
    constexpr static char lineEnd[] = "\r\n";
};

struct None {
    constexpr static char lineEnd[] = "";
};

template <typename Output, typename LE = None>
struct Printer {
    Output output;
    char   buf[12];
    constexpr Printer(Output o) :
        output(o) {}

    constexpr void
    print(const char * string)
    {
        uint8_t c;
        while ((c = *string++)) {
            output.write(c);
        }
    }

    constexpr void
    printLn(const char * string)
    {
        print(string);
        print(LE::lineEnd);
    }

    constexpr void
    print(const unsigned int num)
    {
        utoa(num, buf, 10);
        print(buf);
    }

    constexpr void
    printLn(const unsigned int num)
    {
        utoa(num, buf, 10);
        print(buf);
        print(LE::lineEnd);
    }

    constexpr void
    print(const unsigned long int num)
    {
        ultoa(num, buf, 10);
        print(buf);
    }

    constexpr void
    printLn(const unsigned long int num)
    {
        ultoa(num, buf, 10);
        print(buf);
        print(LE::lineEnd);
    }
};

#endif

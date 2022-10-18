#include <printer.hpp>
#include <stdio.h>

void
Printer::print(const char * string) const
{
    u8 c;
    while ((c = static_cast<u8>(*string++))) {
        output.write(c);
    }
}

void
Printer::printLn(const char * string) const
{
    print(string);
    print(line_end);
}

void
Printer::print(const unsigned long int num)
{
    snprintf(buf, 12, "%lu", num);
    print(buf);
}

void
Printer::printLn(const unsigned long int num)
{
    snprintf(buf, 12, "%lu", num);
    print(buf);
    print(line_end);
}
#pragma once

namespace Flash {

    uint8_t
    read(const uint8_t & p)
    {
        const uint16_t addr = reinterpret_cast<uint16_t>(&p);
        uint8_t        byte;
        asm(
            "lpm %0, Z \n"
            : "=r"(byte)
            : "z"(addr));
        return byte;
    }

    char
    read(const char * p)
    {
        const uint16_t addr = reinterpret_cast<uint16_t>(p);
        char           byte;
        asm(
            "lpm %0, Z \n"
            : "=r"(byte)
            : "z"(addr));
        return byte;
    }

    uint16_t
    read(const uint16_t & p)
    {

        uint16_t addr = reinterpret_cast<uint16_t>(&p);
        uint16_t result;
        asm(
            "lpm %A0, Z+ \n"
            "lpm %B0, Z  \n"
            : "=r"(result), "=z"(addr)
            : "1"(addr));
        return result;
    }

    uint32_t
    read(const uint32_t & p)
    {
        uint16_t addr = reinterpret_cast<uint16_t>(&p);
        uint32_t result;
        asm("lpm %A0, Z+ \n"
            "lpm %B0, Z+ \n"
            "lpm %C0, Z+ \n"
            "lpm %D0, Z  \n"
            : "=r"(result), "=z"(addr)
            : "1"(addr));
        return result;
    }

}

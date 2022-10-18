#pragma once
#include "types.hpp"
namespace Flash {

    inline u8
    read(const u8 & p)
    {
        const u16 addr = reinterpret_cast<u16>(&p);
        u8        byte;
        asm(
            "lpm %0, Z \n"
            : "=r"(byte)
            : "z"(addr));
        return byte;
    }

    inline char
    read(const char * p)
    {
        const u16 addr = reinterpret_cast<u16>(p);
        char      byte;
        asm(
            "lpm %0, Z \n"
            : "=r"(byte)
            : "z"(addr));
        return byte;
    }

    inline u16
    read(const u16 & p)
    {

        u16 addr = reinterpret_cast<u16>(&p);
        u16 result;
        asm(
            "lpm %A0, Z+ \n"
            "lpm %B0, Z  \n"
            : "=r"(result), "=z"(addr)
            : "1"(addr));
        return result;
    }

    inline u32
    read(const u32 & p)
    {
        u16 addr = reinterpret_cast<u16>(&p);
        u32 result;
        asm("lpm %A0, Z+ \n"
            "lpm %B0, Z+ \n"
            "lpm %C0, Z+ \n"
            "lpm %D0, Z  \n"
            : "=r"(result), "=z"(addr)
            : "1"(addr));
        return result;
    }

}

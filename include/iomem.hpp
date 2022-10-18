#pragma once
#include "types.hpp"

namespace iomem {

    template <typename WIDTH>
    inline WIDTH
    read(usize address)
    {
        /*
        GCC 12.x has a bug https://gcc.gnu.org/bugzilla/show_bug.cgi?id=106247
        It treats reinterpret_cast as a array and throws a warning "array out of bound"
        */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        return *reinterpret_cast<WIDTH volatile *>(address);
#pragma GCC diagnostic pop
    }

    template <typename WIDTH>
    inline void
    write(usize address, WIDTH value)
    {
        /*
        GCC 12.x has a bug https://gcc.gnu.org/bugzilla/show_bug.cgi?id=106247
        It treats reinterpret_cast as a array and throws a warning "array out of bound"
        */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        *reinterpret_cast<WIDTH volatile *>(address) = value;
#pragma GCC diagnostic pop
    }

    template <typename WIDTH>
    inline void
    modify(const usize address, auto fptr)
    {
        WIDTH reg_val = read<WIDTH>(address);
        write<WIDTH>(address, fptr(reg_val));
    }
}
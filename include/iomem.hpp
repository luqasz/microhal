#pragma once
#include "types.hpp"
#include "utils.hpp"

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

    template <typename BIT_SIZE>
    inline void
    set_bit(const usize address, const BIT_SIZE bit)
    {
        modify<BIT_SIZE>(address, [bit](BIT_SIZE val) {
            return static_cast<BIT_SIZE>(val | bit);
        });
    }

    template <typename BIT_SIZE>
    inline void
    set_bit(const usize address, const BIT_SIZE bit, const BIT_SIZE set_mask)
    {
        modify<BIT_SIZE>(address, [bit, set_mask](BIT_SIZE val) {
            return static_cast<BIT_SIZE>((val & inverted<BIT_SIZE>(set_mask)) | bit);
        });
    }

    template <typename BIT_SIZE>
    inline void
    clear_bit(const usize address, const BIT_SIZE bit)
    {
        modify<BIT_SIZE>(address, [bit](BIT_SIZE val) {
            return static_cast<BIT_SIZE>(val & inverted<BIT_SIZE>(bit));
        });
    }

    template <typename BIT_SIZE>
    inline void
    xor_bit(const usize address, const BIT_SIZE bit)
    {
        modify<BIT_SIZE>(address, [bit](BIT_SIZE val) {
            return static_cast<BIT_SIZE>(val ^ bit);
        });
    }

    template <typename BIT_SIZE>
    inline bool
    is_set_bit(const usize address, const BIT_SIZE bit)
    {
        return read<BIT_SIZE>(address) & bit;
    }

    // Wait for bit to be set.
    template <typename BIT_SIZE>
    inline void
    set_bit_wait(const usize address, const BIT_SIZE bit)
    {
        while (!(read<BIT_SIZE>(address) & bit)) { };
    }

    // Wait for bit to be cleared.
    template <typename BIT_SIZE>
    inline void
    clear_bit_wait(const usize address, const BIT_SIZE bit)
    {
        while ((read<BIT_SIZE>(address) & bit)) { };
    }

    template <typename WIDTH>
    struct RegRW {
        const usize address;
        const WIDTH mask;
        explicit RegRW(const usize address_, const WIDTH mask_ = limits<WIDTH>::max) :
            address(address_), mask(mask_) { }

        operator WIDTH() const
        {
            return read<WIDTH>(address);
        }

        void
        operator=(const WIDTH val) const
        {
            write(address, val);
        }
    };
}

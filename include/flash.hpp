#pragma once

#ifdef __AVR_HAVE_LPMX__
#    include "lpmx.hpp"
#else
#    error "No PGMSPACE support for this MCU."
#endif

#define PGMSPACE [[gnu::progmem]]

#include "types.hpp"

namespace Flash {

    template <typename T, usize SIZE>
    class Array {

        const T * const arr;

    public:
        constexpr Array(const T (&a)[SIZE]) :
            arr(a) { }

        constexpr T
        operator[](const usize p) const
        {
            return read(&arr[p]);
        }

        class Iterator {
            const T * const arr;
            usize           index;

        public:
            Iterator(const T * d, usize i) :
                arr { d }, index { i }
            {
            }

            T
            operator*() const
            {
                return read(&arr[index]);
            }

            auto
            operator++()
            {
                index++;
                return *this;
            }

            auto
            operator!=(Iterator other) const
            {
                return index != other.index;
            }
        };

        constexpr auto
        begin() const
        {
            return Iterator(arr, 0);
        }

        constexpr auto
        end() const
        {
            return Iterator(arr, SIZE);
        }
    };

}

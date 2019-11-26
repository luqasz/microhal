#pragma once

#ifdef __AVR_HAVE_LPMX__
#    include "lpmx.h"
#else
#    error "No PGMSPACE support for this MCU."
#endif

#define PGMSPACE [[gnu::progmem]]

#include <stdint.h>

namespace Flash {

    using SIZE_TYPE = uint16_t;

    template <typename T, SIZE_TYPE SIZE>
    class Array {

        const T * const arr;

    public:
        constexpr Array(const T (&a)[SIZE]) :
            arr(a) {}

        constexpr T operator[](const SIZE_TYPE p) const
        {
            return read(&arr[p]);
        }

        class Iterator {
            const T * const arr;
            SIZE_TYPE       index;

        public:
            Iterator(const T * d, SIZE_TYPE i) :
                arr { d }, index { i }
            {
            }

            T operator*() const
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

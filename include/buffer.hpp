#pragma once

#include "types.hpp"
#include "utils.hpp"
#include <concepts.hpp>
#include <core.hpp>

namespace buffer {

    template <typename T>
    struct Span {
        T *   ptr;
        usize length;
        using ContainedType = T;

        explicit constexpr Span(T * ptr_, const usize LEN) noexcept :
            ptr(ptr_),
            length(LEN)
        {
        }

        template <usize LEN>
        constexpr Span(T (&ptr_)[LEN]) noexcept :
            ptr(ptr_),
            length(LEN)
        {
        }

        constexpr bool
        contains(const ContainedType other) const
        {
            for (const ContainedType & each : *this) {
                if (each == other) {
                    return true;
                }
            }
            return false;
        }

        constexpr const Span<const T>
        span(const usize b, const usize e) const
        {
            return Span<const T>(ptr + b, e);
        }

        constexpr Span<T>
        span(const usize b, const usize e)
        {
            return Span<T>(ptr + b, e);
        }

        constexpr T *
        begin()
        {
            return ptr;
        }

        constexpr const T *
        begin() const
        {
            return ptr;
        }

        constexpr T *
        end()
        {
            return ptr + length;
        }

        constexpr const T *
        end() const
        {
            return ptr + length;
        }

        constexpr usize
        size() const
        {
            return length;
        }

        constexpr usize
        len() const
        {
            return length;
        }

        constexpr usize
        free() const
        {
            return length;
        }

        constexpr
        operator Span<const T>() const
        {
            return Span<const T>(ptr, length);
        }

        constexpr T &
        operator[](const usize idx)
        {
            return ptr[idx];
        }

        constexpr const T &
        operator[](const usize idx) const
        {
            return ptr[idx];
        }

        constexpr bool
        operator==(const Span<T> & other) const
        {
            if (size() != other.size()) {
                return false;
            }
            usize idx = 0;
            while (idx < size()) {
                if ((*this)[idx] != other[idx]) {
                    return false;
                }
                idx += 1;
            }
            return true;
        }
    };

    template <typename Contained, usize Size>
    struct Array {
        using ContainedType = Contained;
        Contained data[Size];

        constexpr bool
        contains(const ContainedType other) const
        {
            for (const ContainedType & each : *this) {
                if (each == other) {
                    return true;
                }
            }
            return false;
        }

        constexpr usize
        index(const ContainedType searched) const
        {
            usize cnt = 0;
            for (const ContainedType & each : *this) {
                if (each == searched) {
                    return cnt;
                }
                cnt++;
            }
            // TODO Add Option return type
            return 0;
        }

        constexpr usize
        size() const
        {
            return Size;
        }

        constexpr usize
        len() const
        {
            return Size;
        }

        constexpr usize
        free() const
        {
            return Size;
        }

        constexpr Contained &
        operator[](const usize idx)
        {
            return data[idx];
        }

        constexpr const Contained &
        operator[](const usize idx) const
        {
            return data[idx];
        }

        constexpr Contained *
        begin()
        {
            return data;
        }

        constexpr const Contained *
        begin() const
        {
            return data;
        }

        constexpr Contained *
        end()
        {
            return data + Size;
        }

        constexpr const Contained *
        end() const
        {
            return data + Size;
        }

        constexpr Span<Contained>
        span()
        {
            // TODO remove in favor of span() with defaults
            return Span(data);
        }

        constexpr const Span<const Contained>
        span() const
        {
            // TODO remove in favor of span() with defaults
            return Span(data);
        }

        constexpr Span<Contained>
        span(const usize sidx, const usize num)
        {
            return Span(data + sidx, num);
        }

        constexpr const Span<const Contained>
        span(const usize sidx, const usize num) const
        {
            return Span(data + sidx, num);
        }

        constexpr bool
        operator==(const Array<Contained, Size> & other) const
        {
            usize idx = 0;
            for (const Contained & elem : *this) {
                if (elem != other[idx]) {
                    return false;
                    idx += 1;
                }
            }
            return true;
        }
    };

    template <class T, class... U>
    Array(T, U...) -> Array<T, 1 + sizeof...(U)>;

    template <typename CT, usize BUFFER_SIZE>
        requires(BUFFER_SIZE > 1)
    struct Circular {
        using ContainedType = CT;
        using IndexType     = usize;
        // clangd doesn't like below assertions inside requires()
        static_assert(is_power_of_two(BUFFER_SIZE), "Buffer size must be power of 2.");
        static_assert(BUFFER_SIZE <= usize((limits<IndexType>::max / 2) + 1), "Buffer size must be at max half of given index type.");

        IndexType                  head = 0;
        IndexType                  tail = 0;
        constexpr static IndexType mask = BUFFER_SIZE - 1;
        ContainedType              data[BUFFER_SIZE];

        constexpr usize
        size() const
        {
            return BUFFER_SIZE;
        }

        constexpr usize
        len() const
        {
            return static_cast<usize>(head - tail);
        }

        constexpr usize
        free() const
        {
            return size() - len();
        }

        constexpr void
        write(const ContainedType value)
        {
            data[head++ & mask] = value;
        }

        constexpr ContainedType
        read()
        {
            return data[tail++ & mask];
        }
    };

    template <typename T, typename U>
        requires Assignable<T, U>
    constexpr usize
    copy(const Span<T> src, Span<U> dst)
    {
        usize       copied = 0;
        const usize limit  = min(src.len(), dst.len());
        while (copied < limit) {
            dst[copied] = src[copied];
            copied++;
        }
        return copied;
    }

    template <typename T, Writer W>
        requires Assignable<T, typename W::ContainedType>
    constexpr usize
    copy(const Span<T> src, W & dst)
    {
        usize       copied = 0;
        const usize limit  = min(dst.free(), src.len());
        while (copied < limit) {
            dst.write(src[copied]);
            copied++;
        }
        return copied;
    }

    template <Reader R, typename T>
        requires Assignable<typename R::ContainedType, T>
    constexpr usize
    copy(R & src, Span<T> dst)
    {
        usize       copied = 0;
        const usize limit  = min(src.len(), dst.len());
        while (copied < limit) {
            dst[copied] = src.read();
            copied++;
        }
        return copied;
    }

    template <Reader R, Writer W>
        requires Assignable<typename R::ContainedType, typename W::ContainedType>
    constexpr usize
    copy(R & src, W & dst)
    {
        usize       copied = 0;
        const usize limit  = min(src.len(), dst.free());
        while (copied < limit) {
            dst.write(src.read());
            copied++;
        }
        return copied;
    }

    template <typename T, usize N, usize U>
    constexpr Array<T, N + U>
    operator+(const Array<T, N> & lhs, const Array<T, U> & rhs)
    {
        Array<T, N + U> buf { 0 };
        copy(lhs.span(), buf.span(0, N));
        copy(rhs.span(), buf.span(N, U));
        return buf;
    }

}

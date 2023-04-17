#pragma once

#include <types.hpp>

template <class Tag, typename Contained>
class BitCombination {

private:
    Contained value;

public:
    constexpr BitCombination() noexcept :
        value()
    {
    }

    constexpr explicit BitCombination(const Contained & value) noexcept :
        value(value)
    {
    }

    constexpr explicit
    operator Contained &() noexcept
    {
        return value;
    }

    constexpr explicit
    operator const Contained &() const noexcept
    {
        return value;
    }

    constexpr Tag &
    operator|=(const Tag & other) noexcept
    {
        value |= other.value;
        return *this;
    }

    constexpr Tag
    operator|(const Tag & other) const noexcept
    {
        return Tag(value | other.value);
    }

    constexpr Tag &
    operator&=(const Tag & other) noexcept
    {
        value &= other.value;
        return *this;
    }

    constexpr Tag
    operator&(const Tag & other) const noexcept
    {
        return Tag(value & other.value);
    }

    constexpr bool
    operator==(const Tag & other) const noexcept
    {
        return value == other.value;
    }
};

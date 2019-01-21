#ifndef utils_h
#define utils_h

template <typename T>
bool constexpr isPowerOfTwo(T number)
{
    return (number != 0) && (number & (number - 1)) == 0;
}

template <typename T>
constexpr T
countSetBits(T number)
{
    T count = 0;
    while (number) {
        count++;
        number &= (number - 1);
    }
    return count;
}

template <typename T, typename U>
struct is_same {
    static const bool value = false;
};

template <typename T>
struct is_same<T, T> {
    static const bool value = true;
};

template <typename T, typename U>
constexpr bool
eqTypes()
{
    return is_same<T, U>::value;
}

template <typename UINT>
constexpr UINT
inverted(UINT value)
{
    return static_cast<UINT>(~value);
}

#endif
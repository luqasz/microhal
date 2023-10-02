#pragma once

// Function that:
// * can safely read any non-volatile objects, and modify the value of objects in a way that does not affect their return value or the observable state of the program
// * called with same arguments, return same result
#define PUREFN __attribute__((pure))

// Function that:
// * may access any global non volatile constants
// * called with same arguments, return same result
#define CONSTFN __attribute__((const))

#if !defined(_WIN32) || !defined(_WIN64) || !defined(__linux__) || !defined(__APPLE__)
#    define NO_OS
#endif

// clang-format off
#define ENUM_STR_CASE(ENUM_CODE) case ENUM_CODE: return #ENUM_CODE
// clang-format on

#define ENUM(name, atype, ...) \
    enum name { __VA_ARGS__ }; \
    static constexpr atype All_##name##_usize[] = { __VA_ARGS__ };

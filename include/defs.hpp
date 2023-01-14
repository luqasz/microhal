#pragma once

// Function that:
// * does not access any global data
// * called with same arguments, return same result
#define PUREFN __attribute__((pure))

// Function that:
// * may access any global const data
// * called with same arguments, return same result
#define CONSTFN __attribute__((const))

#if !defined(_WIN32) || !defined(_WIN64) || !defined(__linux__) || !defined(__APPLE__)
#    define NO_OS
#endif

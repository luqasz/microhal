#pragma once

// Function that:
// * does not access any global data
// * called with same arguments, return same result
#define PUREFN __attribute__((pure))

// Function that:
// * may access any global const data
// * called with same arguments, return same result
#define CONSTFN __attribute__((const))

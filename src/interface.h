#pragma once

#include <stdint.h>

struct Writer {
    void virtual write(const uint8_t byte) = 0;
};

#pragma once

#include "types.hpp"

struct Writer {
    void virtual write(const u8 byte) = 0;
};

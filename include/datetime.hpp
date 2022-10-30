#pragma once

#include "types.hpp"

struct DateTime {
    u8  second;
    u8  minute;
    u8  hour;
    u8  day;
    u8  month;
    u16 year;
};

constexpr static u16 YEAR_START = 2000;
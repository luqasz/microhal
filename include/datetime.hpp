#pragma once

#include "types.hpp"

struct DateTime {
    u16 year;
    u8 second;
    u8 minute;
    u8 hour;
    u8 day;
    u8 month;
};

constexpr static u16 YEAR_START = 2000;

#pragma once

#include "types.hpp"

typedef struct {
    u8  second;
    u8  minute;
    u8  hour;
    u8  month_day;
    u8  week_day;
    u8  month;
    u16 year;
} DateTime;

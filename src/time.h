#ifndef TIME_H_
#define TIME_H_

#include <stdint.h>

typedef struct {
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
    uint8_t month_day;
    uint8_t week_day;
    uint8_t month;
    uint16_t year;
} date_time;

#endif
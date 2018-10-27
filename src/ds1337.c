#include "ds1337.h"

#include "bcd.h"
#include "i2c.h"
#include "time.h"

#include <stdint.h>

// Registers in ascending order.
enum RTC_REGISTER {
    REG_SECONDS,   // 0 - 59
    REG_MINUTES,   // 0 - 59
    REG_HOURS,     // Time 24h 0 - 23 or 12h AM/PM 1 - 12 format. Bit 6 of the hours register is defined as the 12 or 24-hour mode-select bit.
    REG_WEEK_DAY,  // Day of week 1 - 7
    REG_MONTH_DAY, // Day of month 1 - 31
    REG_MONTH,     // Month 1 - 12 and century in 7th bit
    REG_YEAR,      // 0 - 99
    REG_A1_SECONDS,
    REG_A1_MINUTES,
    REG_A1_HOUR,
    REG_A1_DAY_DATE,
    REG_A2_MINUTES,
    REG_A2_HOUR,
    REG_A2_DAY_DATE,
    REG_CONTROL,
    REG_STATUS
};

const uint8_t DS1337_ADDR           = 0x68;
const uint8_t DATE_TIME_BUFFER_SIZE = REG_YEAR + 1;
const uint16_t YEAR_OFFSET          = 2000;

enum RTC_MASK {
    MONTH_MASK   = 0x1F,
    CENTURY_MASK = 0x80
};

void
ds1337_write_time(date_time * time)
{
    uint8_t buf[DATE_TIME_BUFFER_SIZE];
    buf[REG_SECONDS]   = dec_to_bcd(time->second);
    buf[REG_MINUTES]   = dec_to_bcd(time->minute);
    buf[REG_HOURS]     = dec_to_bcd(time->hour);
    buf[REG_MONTH_DAY] = dec_to_bcd(time->month_day);
    buf[REG_WEEK_DAY]  = dec_to_bcd(time->week_day);
    buf[REG_MONTH]     = dec_to_bcd(time->month);
    buf[REG_YEAR]      = dec_to_bcd((uint8_t)(time->year - YEAR_OFFSET));

    i2c_write_buf(
        DS1337_ADDR,
        REG_SECONDS,
        DATE_TIME_BUFFER_SIZE,
        buf);
}

void
ds1337_read_time(date_time * time)
{
    uint8_t buf[DATE_TIME_BUFFER_SIZE];
    i2c_read_buf(
        DS1337_ADDR,
        REG_SECONDS,
        DATE_TIME_BUFFER_SIZE,
        buf);

    time->second    = bcd_to_dec(buf[REG_SECONDS]);
    time->minute    = bcd_to_dec(buf[REG_MINUTES]);
    time->hour      = bcd_to_dec(buf[REG_HOURS]);
    time->month_day = bcd_to_dec(buf[REG_MONTH_DAY]);
    time->week_day  = bcd_to_dec(buf[REG_WEEK_DAY]);
    time->month     = bcd_to_dec((buf[REG_MONTH] & MONTH_MASK));
    time->year      = bcd_to_dec(buf[REG_YEAR]) + YEAR_OFFSET;
}

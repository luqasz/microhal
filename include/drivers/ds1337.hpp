#pragma once

#include "../buffer.hpp"
#include "../datetime.hpp"
#include "../encoders.hpp"
#include "../i2c.hpp"
#include "../types.hpp"
#include "../units.hpp"

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

constexpr u8  DS1337_ADDRESS        = 0x68;
constexpr u8  DATE_TIME_BUFFER_SIZE = REG_YEAR + 1;
constexpr u16 YEAR_OFFSET           = 2000;
constexpr u8  MONTH_MASK            = 0x1F;
constexpr u8  CENTURY_MASK          = 0x80;

constexpr auto clock_target = i2c::Target {
    DS1337_ADDRESS,
    REG_SECONDS,
    100_kHz,
};

class DS1337 {
    i2c::Master i2c_bus;

public:
    DS1337(i2c::Master & bus);

    void
    getDateTime(DateTime & dt) const;

    void
    setDateTime(DateTime & dt) const;
};

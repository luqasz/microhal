#pragma once

#include "buffer.hpp"
#include "datetime.hpp"
#include "encoders.hpp"
#include "i2c.hpp"
#include "units.hpp"

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

constexpr uint8_t  DS1337_ADDRESS        = 0x68;
constexpr uint8_t  DATE_TIME_BUFFER_SIZE = REG_YEAR + 1;
constexpr uint16_t YEAR_OFFSET           = 2000;
constexpr uint8_t  MONTH_MASK            = 0x1F;
constexpr uint8_t  CENTURY_MASK          = 0x80;

constexpr auto clock_target = I2C::Target {
    DS1337_ADDRESS,
    REG_SECONDS,
    100_kHz,
};

class DS1337 {
    I2C::Master i2c_bus;

public:
    DS1337(I2C::Master & bus) :
        i2c_bus(bus)
    {
    }

    void
    getDateTime(DateTime & dt) const
    {
        auto buffer = Buffer::SizedBytesArray<DATE_TIME_BUFFER_SIZE>();
        i2c_bus.read(clock_target, buffer);

        dt.second    = BCD::into_u8(BCD { buffer[REG_SECONDS] });
        dt.minute    = BCD::into_u8(BCD { buffer[REG_MINUTES] });
        dt.hour      = BCD::into_u8(BCD { buffer[REG_HOURS] });
        dt.month_day = BCD::into_u8(BCD { buffer[REG_MONTH_DAY] });
        dt.week_day  = BCD::into_u8(BCD { buffer[REG_WEEK_DAY] });
        dt.month     = BCD::into_u8(BCD { static_cast<u8>(buffer[REG_MONTH] & MONTH_MASK) });
        dt.year      = BCD::into_u8(BCD { buffer[REG_YEAR] }) + YEAR_OFFSET;
    }

    void
    setDateTime(DateTime & dt) const
    {
        auto buffer           = Buffer::SizedBytesArray<DATE_TIME_BUFFER_SIZE>();
        buffer[REG_SECONDS]   = BCD::from_u8(dt.second).value;
        buffer[REG_MINUTES]   = BCD::from_u8(dt.minute).value;
        buffer[REG_HOURS]     = BCD::from_u8(dt.hour).value;
        buffer[REG_MONTH_DAY] = BCD::from_u8(dt.month_day).value;
        buffer[REG_WEEK_DAY]  = BCD::from_u8(dt.week_day).value;
        buffer[REG_MONTH]     = BCD::from_u8(dt.month).value;
        buffer[REG_YEAR]      = BCD::from_u8(static_cast<uint8_t>(dt.year - YEAR_OFFSET)).value;

        i2c_bus.write(clock_target, buffer);
    }
};

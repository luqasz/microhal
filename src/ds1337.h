#ifndef ds1337_h
#define ds1337_h

#include "bcd.h"
#include "buffer.h"
#include "datetime.h"
#include "i2c.h"

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

const uint8_t  DS1337_ADDRESS        = 0x68;
const uint8_t  DATE_TIME_BUFFER_SIZE = REG_YEAR + 1;
const uint16_t YEAR_OFFSET           = 2000;
const uint8_t  MONTH_MASK            = 0x1F;
const uint8_t  CENTURY_MASK          = 0x80;

const auto clock_target = I2C::Target {
    DS1337_ADDRESS,
    REG_SECONDS,
    REG_YEAR,
    I2C::Speed::kHz100,
};

class DS1337 {
    I2C::Master i2c_bus;

public:
    DS1337(I2C::Master & bus) :
        i2c_bus(bus)
    {
    }

    void
    getDateTime(DateTime & dt)
    {
        auto buffer = Buffer::SizedBytesArray<DATE_TIME_BUFFER_SIZE>();
        i2c_bus.read(clock_target, buffer);

        dt.second    = bcd_to_dec(buffer[REG_SECONDS]);
        dt.minute    = bcd_to_dec(buffer[REG_MINUTES]);
        dt.hour      = bcd_to_dec(buffer[REG_HOURS]);
        dt.month_day = bcd_to_dec(buffer[REG_MONTH_DAY]);
        dt.week_day  = bcd_to_dec(buffer[REG_WEEK_DAY]);
        dt.month     = bcd_to_dec((buffer[REG_MONTH] & MONTH_MASK));
        dt.year      = bcd_to_dec(buffer[REG_YEAR]) + YEAR_OFFSET;
    }

    void
    setDateTime(DateTime & dt)
    {
        auto buffer           = Buffer::SizedBytesArray<DATE_TIME_BUFFER_SIZE>();
        buffer[REG_SECONDS]   = dec_to_bcd(dt.second);
        buffer[REG_MINUTES]   = dec_to_bcd(dt.minute);
        buffer[REG_HOURS]     = dec_to_bcd(dt.hour);
        buffer[REG_MONTH_DAY] = dec_to_bcd(dt.month_day);
        buffer[REG_WEEK_DAY]  = dec_to_bcd(dt.week_day);
        buffer[REG_MONTH]     = dec_to_bcd(dt.month);
        buffer[REG_YEAR]      = dec_to_bcd(static_cast<uint8_t>(dt.year - YEAR_OFFSET));

        i2c_bus.write(clock_target, buffer);
    }
};

#endif

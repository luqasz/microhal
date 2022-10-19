#include <drivers/ds1337.hpp>

DS1337::DS1337(i2c::Master & bus) :
    i2c_bus(bus)
{
}

void
DS1337::getDateTime(DateTime & dt)
{
    auto slice = buffer.slice(0, DATE_TIME_BUFFER_SIZE);
    i2c_bus.read(slice, clock_target);
    dt.second    = BCD::into_u8(BCD { slice[REG_SECONDS] });
    dt.minute    = BCD::into_u8(BCD { slice[REG_MINUTES] });
    dt.hour      = BCD::into_u8(BCD { slice[REG_HOURS] });
    dt.month_day = BCD::into_u8(BCD { slice[REG_MONTH_DAY] });
    dt.week_day  = BCD::into_u8(BCD { slice[REG_WEEK_DAY] });
    dt.month     = BCD::into_u8(BCD { static_cast<u8>(slice[REG_MONTH] & MONTH_MASK) });
    dt.year      = BCD::into_u8(BCD { slice[REG_YEAR] }) + YEAR_OFFSET;
}

void
DS1337::setDateTime(DateTime & dt)
{
    auto slice           = buffer.slice(0, DATE_TIME_BUFFER_SIZE);
    slice[REG_SECONDS]   = BCD::from_u8(dt.second).value;
    slice[REG_MINUTES]   = BCD::from_u8(dt.minute).value;
    slice[REG_HOURS]     = BCD::from_u8(dt.hour).value;
    slice[REG_MONTH_DAY] = BCD::from_u8(dt.month_day).value;
    slice[REG_WEEK_DAY]  = BCD::from_u8(dt.week_day).value;
    slice[REG_MONTH]     = BCD::from_u8(dt.month).value;
    slice[REG_YEAR]      = BCD::from_u8(static_cast<uint8_t>(dt.year - YEAR_OFFSET)).value;

    i2c_bus.write(slice, clock_target);
}

;
#include <drivers/ds1337.hpp>

DS1337::DS1337(I2C::Master & bus) :
    i2c_bus(bus)
{
}

void
DS1337::getDateTime(DateTime & dt) const
{
    auto buffer = buffer::SizedBytesArray<DATE_TIME_BUFFER_SIZE>();
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
DS1337::setDateTime(DateTime & dt) const
{
    auto buffer           = buffer::SizedBytesArray<DATE_TIME_BUFFER_SIZE>();
    buffer[REG_SECONDS]   = BCD::from_u8(dt.second).value;
    buffer[REG_MINUTES]   = BCD::from_u8(dt.minute).value;
    buffer[REG_HOURS]     = BCD::from_u8(dt.hour).value;
    buffer[REG_MONTH_DAY] = BCD::from_u8(dt.month_day).value;
    buffer[REG_WEEK_DAY]  = BCD::from_u8(dt.week_day).value;
    buffer[REG_MONTH]     = BCD::from_u8(dt.month).value;
    buffer[REG_YEAR]      = BCD::from_u8(static_cast<uint8_t>(dt.year - YEAR_OFFSET)).value;

    i2c_bus.write(clock_target, buffer);
}

;
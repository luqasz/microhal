#include <drivers/ds1337.hpp>
#include <encoders.hpp>

DS1337::DS1337(i2c::Master & bus) :
    i2c_bus(bus)
{
}

void
DS1337::getDateTime(DateTime & dt)
{
    auto slice = buffer.slice(0, DATE_TIME_BUFFER_SIZE);
    i2c_bus.read(slice, clock_target);
    dt.second    = encoder::bcd_to_dec(slice[REG_SECONDS]);
    dt.minute    = encoder::bcd_to_dec(slice[REG_MINUTES]);
    dt.hour      = encoder::bcd_to_dec(slice[REG_HOURS]);
    dt.month_day = encoder::bcd_to_dec(slice[REG_MONTH_DAY]);
    dt.week_day  = encoder::bcd_to_dec(slice[REG_WEEK_DAY]);
    dt.month     = encoder::bcd_to_dec(static_cast<u8>(slice[REG_MONTH] & MONTH_MASK));
    dt.year      = encoder::bcd_to_dec(static_cast<u8>(slice[REG_YEAR] + YEAR_OFFSET));
}

void
DS1337::setDateTime(DateTime & dt)
{
    auto slice           = buffer.slice(0, DATE_TIME_BUFFER_SIZE);
    slice[REG_SECONDS]   = encoder::dec_to_bcd(dt.second);
    slice[REG_MINUTES]   = encoder::dec_to_bcd(dt.minute);
    slice[REG_HOURS]     = encoder::dec_to_bcd(dt.hour);
    slice[REG_MONTH_DAY] = encoder::dec_to_bcd(dt.month_day);
    slice[REG_WEEK_DAY]  = encoder::dec_to_bcd(dt.week_day);
    slice[REG_MONTH]     = encoder::dec_to_bcd(dt.month);
    slice[REG_YEAR]      = encoder::dec_to_bcd(static_cast<uint8_t>(dt.year - YEAR_OFFSET));

    i2c_bus.write(slice, clock_target);
}

;
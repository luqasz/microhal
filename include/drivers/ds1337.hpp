#pragma once

#include "../buffer.hpp"
#include "../datetime.hpp"
#include "../types.hpp"
#include "../encoders.hpp"

namespace ds1337 {
    enum class Register : u8 {
        Seconds,    // 0 - 59
        Minutes,    // 0 - 59
        Hours,      // 0 - 23 or AM/PM 1 - 12 format.
        WeekDay,    // Day of week 1-7
        MonthDay,   // Day of month 1-31
        Month,      // Month 1-12.
        Year,       // 0-99.
        A1_Seconds, // 0-59 seconds. Bit 7 A1M1.
        A1_Minutes, // 0-59 minutes. Bit 7 A1M2.
        A1_Hour,    //
        A1_DayDate, //
        A2_Minutes, //
        A2_Hour,    //
        A2_DayDate, //
        Control,    //
        Status,     //
    };
    using DateTime_Array = buffer::Array<u8, usize(u8(Register::Year) + 1)>;
    using Registers_Array = buffer::Array<u8, usize(u8(Register::Status) + 1)>;
    constexpr inline static u8 I2C_ADDRESS = 0x68;
    constexpr inline static u8 MONTH_MASK = 0x1F; // Ignore century bit.
    constexpr inline static u8 HOUR_MASK = 0x1F;  // Ignore AM/PM bits.

    constexpr void
    get(DateTime & dt, const buffer::Span<u8> slice)
    {
        dt.second = encoder::bcd_to_dec(slice[u8(Register::Seconds)]);
        dt.minute = encoder::bcd_to_dec(slice[u8(Register::Minutes)]);
        dt.hour = encoder::bcd_to_dec(slice[u8(Register::Hours)] & HOUR_MASK);
        dt.day = encoder::bcd_to_dec(slice[u8(Register::MonthDay)]);
        dt.month = encoder::bcd_to_dec(slice[u8(Register::Month)] & MONTH_MASK);
        dt.year = encoder::bcd_to_dec(slice[u8(Register::Year)]) + YEAR_START;
    }

    constexpr void
    set(const DateTime & dt, buffer::Span<u8> slice)
    {
        slice[u8(Register::Seconds)] = encoder::dec_to_bcd(dt.second);
        slice[u8(Register::Minutes)] = encoder::dec_to_bcd(dt.minute);
        slice[u8(Register::Hours)] = encoder::dec_to_bcd(dt.hour) & HOUR_MASK;
        slice[u8(Register::MonthDay)] = encoder::dec_to_bcd(dt.day);
        slice[u8(Register::Month)] = encoder::dec_to_bcd(dt.month) & MONTH_MASK;
        slice[u8(Register::Year)] = encoder::dec_to_bcd(u8(dt.year - YEAR_START));
    }

}

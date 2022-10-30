#pragma once

#include "../buffer.hpp"
#include "../datetime.hpp"
#include "../types.hpp"
#include "../encoders.hpp"

namespace ds1337 {
    enum class REGISTER {
        SECONDS,     // 0 - 59
        MINUTES,     // 0 - 59
        HOURS,       // 0 - 23 or AM/PM 1 - 12 format.
        WEEK_DAY,    // Day of week 1-7
        MONTH_DAY,   // Day of month 1-31
        MONTH,       // Month 1-12.
        YEAR,        // 0-99.
        A1_SECONDS,  // 0-59 seconds. Bit 7 A1M1.
        A1_MINUTES,  // 0-59 minutes. Bit 7 A1M2.
        A1_HOUR,     //
        A1_DAY_DATE, //
        A2_MINUTES,  //
        A2_HOUR,     //
        A2_DAY_DATE, //
        CONTROL,     //
        STATUS,      //
    };
    constexpr static usize DATE_TIME_BUFFER_SIZE = u8(REGISTER::YEAR) + 1;
    constexpr static usize ALL_REGS_BUFFER_SIZE  = u8(REGISTER::STATUS) + 1;
    constexpr static u8    I2C_ADDRESS           = 0x68;
    constexpr static u8    MONTH_MASK            = 0x1F; // Ignore century bit.
    constexpr static u8    HOUR_MASK             = 0x1F; // Ignore AM/PM bits.

    constexpr void
    get(DateTime & dt, buffer::Span<u8> slice)
    {
        dt.second = encoder::bcd_to_dec(slice[u8(REGISTER::SECONDS)]);
        dt.minute = encoder::bcd_to_dec(slice[u8(REGISTER::MINUTES)]);
        dt.hour   = encoder::bcd_to_dec(slice[u8(REGISTER::HOURS)] & HOUR_MASK);
        dt.day    = encoder::bcd_to_dec(slice[u8(REGISTER::MONTH_DAY)]);
        dt.month  = encoder::bcd_to_dec(slice[u8(REGISTER::MONTH)] & MONTH_MASK);
        dt.year   = encoder::bcd_to_dec(slice[u8(REGISTER::YEAR)]) + YEAR_START;
    }

    constexpr void
    set(DateTime & dt, buffer::Span<u8> slice)
    {
        slice[u8(REGISTER::SECONDS)]   = encoder::dec_to_bcd(dt.second);
        slice[u8(REGISTER::MINUTES)]   = encoder::dec_to_bcd(dt.minute);
        slice[u8(REGISTER::HOURS)]     = encoder::dec_to_bcd(dt.hour) & HOUR_MASK;
        slice[u8(REGISTER::MONTH_DAY)] = encoder::dec_to_bcd(dt.day);
        slice[u8(REGISTER::MONTH)]     = encoder::dec_to_bcd(dt.month) & MONTH_MASK;
        slice[u8(REGISTER::YEAR)]      = encoder::dec_to_bcd(u8(dt.year - YEAR_START));
    }

}

#pragma once

#include <defs.hpp>
#include <types.hpp>
#include <units.hpp>

namespace timer {

    /*
     Given timer input frequency, desired frequency, timer counts
     return prescaler value.
     */
    PUREFN constexpr u32
    calc_prescaler(const units::Frequency & fin, const units::Frequency & fout, const u32 counts)
    {
        return fin / (fout * counts);
    }

    /*
     Given timer input frequency, desired frequency, timer prescaler,
     return number of timer counts required.
     */
    PUREFN constexpr u32
    calc_counts(const units::Frequency & fin, const units::Frequency & fout, const u32 presc)
    {
        return fin / (fout * presc);
    }

    /*
    Given timer frequency and desired frequency,
    return value of overflow register.
    Note -1 which account for overflow.
    */
    PUREFN constexpr u32
    calc_top(const units::Frequency & fin, const units::Frequency & fout)
    {
        return calc_counts(fin, fout, 1) - 1;
    }
}

#pragma once

#include "../../../types.hpp"
#include "../../../units.hpp"
#include "../../../defs.hpp"
#include <timer_equations.hpp>

namespace timer {

    enum TCCRA : u8 {
        WGM0  = 1,
        WGM1  = 2,
        COMC0 = 4,
        COMC1 = 8,
        COMB0 = 16,
        COMB1 = 32,
        COMA0 = 64,
        COMA1 = 128,
    };

    enum TCCRB : u8 {
        CS0  = 1,
        CS1  = 2,
        CS2  = 4,
        WGM2 = 8,
        WGM3 = 16,
        ICES = 64,
        ICNC = 128,
    };

    enum TIMSK : u8 {
        TOIE  = 0,
        OCIEA = 2,
        OCIEB = 4,
        OCIEC = 8,
        ICIE  = 32,
    };

    enum Clock : u8 {
        Stopped         = 0,
        ClockDiv_1      = TCCRB::CS0,
        ClockDiv_8      = TCCRB::CS1,
        ClockDiv_64     = TCCRB::CS0 | TCCRB::CS1,
        ClockDiv_256    = TCCRB::CS2,
        ClockDiv_1024   = TCCRB::CS0 | TCCRB::CS2,
        ExternalFalling = TCCRB::CS1 | TCCRB::CS2,
        ExternalRising  = TCCRB::CS0 | TCCRB::CS1 | TCCRB::CS2,
    };

    constexpr u8 CLOCK_MASK = TCCRB::CS0 | TCCRB::CS1 | TCCRB::CS2;
    constexpr u8 WGM01_MASK = TCCRA::WGM0 | TCCRA::WGM1;
    constexpr u8 WGM23_MASK = TCCRB::WGM2 | TCCRB::WGM3;

    struct Prescaler {
        const Clock clock;
        const u16   value;
    };

    struct TimerConfig {
        const Clock clock;
        const u16   top;
    };

    constexpr Prescaler prescalers[] = {
        {
            Clock::ClockDiv_1,
            1,
        },
        {
            Clock::ClockDiv_8,
            8,
        },
        {
            Clock::ClockDiv_64,
            64,
        },
        {
            Clock::ClockDiv_256,
            256,
        },
        {
            Clock::ClockDiv_1024,
            1024,
        },
    };

    template <typename TOP_REG>
    PUREFN constexpr TimerConfig
    calc_prescaled_top(const units::Frequency & fcpu, const units::Frequency & desired)
    {
        for (Prescaler p : prescalers) {
            const u32 top = calc_top((fcpu / p.value), desired);
            if (top < u32 { limits<TOP_REG>::max } + 1) {
                return TimerConfig {
                    .clock = p.clock,
                    .top   = static_cast<TOP_REG>(top),
                };
            }
        }
        return TimerConfig {
            .clock = Clock::Stopped,
            .top   = 0,
        };
    }
}

#pragma once

#include "../gpio.hpp"
#include "../types.hpp"

#include <stdint.h>
#include <util/delay.h>

namespace HD44780 {

    enum Cmd {
        ClearScreen = 0x01,
        CursorHome  = 0x02,
    };

    /*
    Line and row start from 0.
    */
    struct Position {
        const u8 line;
        const u8 row;
    };

    class LCD {
        const gpio::Bus8Bit & bus;
        const gpio::Output &  rs;
        const gpio::Output &  rw;
        const gpio::Output &  e;
        /*
        RS is a Register select pin.
        Low for command,
        High for data,
        */
        auto static constexpr COMMAND = gpio::Low;
        auto static constexpr DATA    = gpio::High;

        void
        waitUntillReady() const;

        void
        enable(const gpio::State state) const;

        u8
        read() const;

        void
        sendByte(const u8 byte, const gpio::State reg) const;

    public:
        LCD(const gpio::Bus8Bit & b, const gpio::Output & _rs, const gpio::Output & _rw, const gpio::Output & _e);

        void
        write(const u8 byte) const;

        void
        print(const char * string) const;

        void
        set(const HD44780::Cmd c) const;

        void
        set(const Position position) const;
    };
}

#pragma once

#include "../gpio.hpp"
#include "../interface.hpp"
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

    class LCD : public Writer {
        const GPIO::Bus8Bit & bus;
        const GPIO::Output &  rs;
        const GPIO::Output &  rw;
        const GPIO::Output &  e;
        /*
        RS is a Register select pin.
        Low for command,
        High for data,
        */
        auto static constexpr COMMAND = GPIO::Off;
        auto static constexpr DATA    = GPIO::On;

        void
        waitUntillReady() const;

        void
        enable(const GPIO::Logic logic) const;

        u8
        read() const;

        void
        sendByte(const u8 byte, const GPIO::Logic reg) const;

    public:
        LCD(const GPIO::Bus8Bit & b, const GPIO::Output & _rs, const GPIO::Output & _rw, const GPIO::Output & _e);

        void
        write(const u8 byte) final;

        void
        set(const HD44780::Cmd c) const;

        void
        set(const Position position) const;
    };
}
#pragma once

#include "../gpio.hpp"
#include "../types.hpp"

#include <stdint.h>
#include <util/delay.h>

namespace HD44780 {

    // DB7 high and DB0..DB6 low, represents busy flag.
    constexpr u8 BUSY_FLAG = 0x80;
    constexpr u8 LINE_1_ADDRESS = 0x00;
    constexpr u8 LINE_2_ADDRESS = 0x40;
    constexpr u8 LINE_3_ADDRESS = 0x14;
    constexpr u8 LINE_4_ADDRESS = 0x54;
    constexpr u8 SET_CGRAM_ADDRESS = 0x40;
    constexpr u8 SET_DDRAM_ADDRESS = 0x80;
    constexpr u8 ENTRY_MODE = 0x04;
    constexpr u8 DISPLAY_CONTROLL = 0x08;
    constexpr u8 FUNCTION_SET = 0x20;
    constexpr u8 ENTRY_CURSOR_RIGHT = ENTRY_MODE | 0x02;
    constexpr u8 ENTRY_CURSOR_LEFT = ENTRY_MODE | 0x00;
    constexpr u8 DisplayOn = DISPLAY_CONTROLL | 0x04;
    constexpr u8 DisplayOff = DISPLAY_CONTROLL | 0x00;
    constexpr u8 DisplayCursor = DISPLAY_CONTROLL | 0x02;
    constexpr u8 HideCursor = DISPLAY_CONTROLL;
    constexpr u8 CursorBlink = DISPLAY_CONTROLL | 0x01;
    constexpr u8 Mode_8Bit = FUNCTION_SET | 0x10;
    constexpr u8 Mode_4Bit = FUNCTION_SET | 0x00;
    constexpr u8 Lines_2 = FUNCTION_SET | 0x08;
    constexpr u8 Lines_1 = FUNCTION_SET | 0x00;
    constexpr u8 Dots_5x10 = FUNCTION_SET | 0x04;
    constexpr u8 Dots_5x8 = FUNCTION_SET | 0x00;

    enum Cmd {
        ClearScreen = 0x01,
        CursorHome = 0x02,
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
        const gpio::Output & rs;
        const gpio::Output & rw;
        const gpio::Output & e;
        /*
        RS is a Register select pin.
        Low for command,
        High for data,
        */
        auto static constexpr COMMAND = gpio::Low;
        auto static constexpr DATA = gpio::High;

        void
        busy_wait() const
        {
            rs = COMMAND;
            while ((read() & BUSY_FLAG)) {
            };
        }

        void
        enable(const gpio::State state) const
        {
            e = state;
            _delay_us(1);
        }

        u8
        read() const
        {
            rw = gpio::High;
            enable(gpio::High);
            const u8 result = bus.read();
            enable(gpio::Low);
            return result;
        }

        void
        write(const u8 byte, const gpio::State reg) const
        {
            rs = reg;
            rw = gpio::Low;
            enable(gpio::High);
            bus.write(byte);
            enable(gpio::Low);
            busy_wait();
        }

    public:
        /*
    Refer to page 45 for initializaton details in datasheet.

    For some unknown reason, all stages are not required.
    With winstar WEH oled displays, third stage caused weird characters
    to be displayed, when initialized more than once without power cycle.
    */
        LCD(const gpio::Bus8Bit & b, const gpio::Output & _rs, const gpio::Output & _rw, const gpio::Output & _e) :
            bus(b),
            rs(_rs),
            rw(_rw),
            e(_e)
        {
            _delay_ms(15);
            write(Mode_8Bit | Lines_2 | Dots_5x8, COMMAND);
            write(HideCursor, COMMAND);
            write(DisplayOn, COMMAND);
            write(ENTRY_CURSOR_RIGHT, COMMAND);
            write(ClearScreen, COMMAND);
        }

        void
        print(const char * string) const
        {
            u8 c;
            while ((c = static_cast<u8>(*string++))) {
                write(c, DATA);
            }
        }

        void
        set(const HD44780::Cmd cmd) const
        {
            write(cmd, COMMAND);
        }

        void
        set(const Position position) const
        {
            u8 address;
            switch (position.line) {
                case 0:
                    address = LINE_1_ADDRESS;
                    break;
                case 1:
                    address = LINE_2_ADDRESS;
                    break;
                case 2:
                    address = LINE_3_ADDRESS;
                    break;
                case 3:
                    address = LINE_4_ADDRESS;
                    break;
            }
            write(static_cast<u8>(SET_DDRAM_ADDRESS + address + position.row), COMMAND);
        }
    };
}

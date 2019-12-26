#ifndef hd44780_h
#define hd44780_h

#include "../gpio.h"

#include <stdint.h>
#include <util/delay.h>

namespace HD44780 {
    // DB7 high and DB0..DB6 low, represents busy flag.
    const uint8_t BUSY_FLAG = 0x80;

    // Tested with 2x16 and 4x20 displays.
    const uint8_t LINE_1_ADDRESS = 0x00;
    const uint8_t LINE_2_ADDRESS = 0x40;
    const uint8_t LINE_3_ADDRESS = 0x14;
    const uint8_t LINE_4_ADDRESS = 0x54;

    const uint8_t SET_CGRAM_ADDRESS  = 0x40;
    const uint8_t SET_DDRAM_ADDRESS  = 0x80;
    const uint8_t ENTRY_MODE         = 0x04;
    const uint8_t DISPLAY_CONTROLL   = 0x08;
    const uint8_t FUNCTION_SET       = 0x20;
    const uint8_t ENTRY_CURSOR_RIGHT = ENTRY_MODE | 0x02;
    const uint8_t ENTRY_CURSOR_LEFT  = ENTRY_MODE | 0x00;
    const uint8_t DisplayOn          = DISPLAY_CONTROLL | 0x04;
    const uint8_t DisplayOff         = DISPLAY_CONTROLL | 0x00;
    const uint8_t DisplayCursor      = DISPLAY_CONTROLL | 0x02;
    const uint8_t HideCursor         = DISPLAY_CONTROLL;
    const uint8_t CursorBlink        = DISPLAY_CONTROLL | 0x01;
    const uint8_t Mode_8Bit          = FUNCTION_SET | 0x10;
    const uint8_t Mode_4Bit          = FUNCTION_SET | 0x00;
    const uint8_t Lines_2            = FUNCTION_SET | 0x08;
    const uint8_t Lines_1            = FUNCTION_SET | 0x00;
    const uint8_t Dots_5x10          = FUNCTION_SET | 0x04;
    const uint8_t Dots_5x8           = FUNCTION_SET | 0x00;

    auto const High = GPIO::PinState::High;
    auto const Low  = GPIO::PinState::Low;
    /*
    RS is a Register select pin.
    Low for command,
    High for data,
    */
    auto const COMMAND = Low;
    auto const DATA    = High;

    enum Cmd {
        ClearScreen = 0x01,
        CursorHome  = 0x02,
    };

    /*
    Line and row start from 0.
    */
    struct Position {
        const uint8_t line;
        const uint8_t row;
    };

    template <typename DATA_LINE>
    class LCD {
        const DATA_LINE dataLine;
        const GPIO::Pin rs;
        const GPIO::Pin rw;
        const GPIO::Pin e;

        void
        waitUntillReady() const
        {
            GPIO::write(rs, COMMAND);
            while ((read() & BUSY_FLAG)) {
            };
        }

        void
        enable(const GPIO::PinState state) const
        {
            GPIO::write(e, state);
            _delay_us(1);
        }

        uint8_t
        read() const
        {
            GPIO::write(rw, High);
            enable(High);
            GPIO::set(dataLine, GPIO::Input);
            const uint8_t result = GPIO::read(dataLine);
            enable(Low);
            return result;
        }

        void
        sendByte(const uint8_t byte, const GPIO::PinState reg) const
        {
            GPIO::write(rs, reg);
            GPIO::write(rw, Low);
            enable(High);
            GPIO::set(dataLine, GPIO::Output);
            GPIO::write(dataLine, byte);
            enable(Low);
            waitUntillReady();
        }

    public:
        /*
        Refer to page 45 for initializaton details in datasheet.

        For some unknown reason, all stages are not required.
        With winstar WEH oled displays, third stage caused weird characters
        to be displayed, when initialized more than once without power cycle.
        */
        LCD(const DATA_LINE & dataLine, const GPIO::Pin & rs, const GPIO::Pin & rw, const GPIO::Pin & e) :
            dataLine(dataLine),
            rs(rs),
            rw(rw),
            e(e)
        {
            GPIO::set(rs, GPIO::Mode::Output);
            GPIO::set(rw, GPIO::Mode::Output);
            GPIO::set(e, GPIO::Mode::Output);
            _delay_ms(15);
            sendByte(Mode_8Bit | Lines_2 | Dots_5x8, COMMAND);
            sendByte(HideCursor, COMMAND);
            sendByte(DisplayOn, COMMAND);
            sendByte(ENTRY_CURSOR_RIGHT, COMMAND);
            sendByte(ClearScreen, COMMAND);
        }

        void
        write(const uint8_t byte) const
        {
            sendByte(byte, DATA);
        }

        void
        set(const HD44780::Cmd c) const
        {
            sendByte(c, COMMAND);
        }

        void
        set(const Position & position) const
        {
            uint8_t address;
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
            sendByte(static_cast<uint8_t>(SET_DDRAM_ADDRESS + address + position.row), COMMAND);
        }
    };
}

#endif

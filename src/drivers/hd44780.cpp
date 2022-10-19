#include "gpio.hpp"
#include <drivers/hd44780.hpp>

namespace HD44780 {

    // DB7 high and DB0..DB6 low, represents busy flag.
    constexpr static u8 BUSY_FLAG          = 0x80;
    constexpr static u8 LINE_1_ADDRESS     = 0x00;
    constexpr static u8 LINE_2_ADDRESS     = 0x40;
    constexpr static u8 LINE_3_ADDRESS     = 0x14;
    constexpr static u8 LINE_4_ADDRESS     = 0x54;
    constexpr static u8 SET_CGRAM_ADDRESS  = 0x40;
    constexpr static u8 SET_DDRAM_ADDRESS  = 0x80;
    constexpr static u8 ENTRY_MODE         = 0x04;
    constexpr static u8 DISPLAY_CONTROLL   = 0x08;
    constexpr static u8 FUNCTION_SET       = 0x20;
    constexpr static u8 ENTRY_CURSOR_RIGHT = ENTRY_MODE | 0x02;
    constexpr static u8 ENTRY_CURSOR_LEFT  = ENTRY_MODE | 0x00;
    constexpr static u8 DisplayOn          = DISPLAY_CONTROLL | 0x04;
    constexpr static u8 DisplayOff         = DISPLAY_CONTROLL | 0x00;
    constexpr static u8 DisplayCursor      = DISPLAY_CONTROLL | 0x02;
    constexpr static u8 HideCursor         = DISPLAY_CONTROLL;
    constexpr static u8 CursorBlink        = DISPLAY_CONTROLL | 0x01;
    constexpr static u8 Mode_8Bit          = FUNCTION_SET | 0x10;
    constexpr static u8 Mode_4Bit          = FUNCTION_SET | 0x00;
    constexpr static u8 Lines_2            = FUNCTION_SET | 0x08;
    constexpr static u8 Lines_1            = FUNCTION_SET | 0x00;
    constexpr static u8 Dots_5x10          = FUNCTION_SET | 0x04;
    constexpr static u8 Dots_5x8           = FUNCTION_SET | 0x00;

    void
    LCD::waitUntillReady() const
    {
        rs = COMMAND;
        while ((read() & BUSY_FLAG)) {
        };
    }

    void
    LCD::enable(const gpio::State state) const
    {
        e = state;
        _delay_us(1);
    }

    u8
    LCD::read() const
    {
        rw = gpio::High;
        enable(gpio::High);
        const u8 result = bus.read();
        enable(gpio::Low);
        return result;
    }

    void
    LCD::sendByte(const u8 byte, const gpio::State reg) const
    {
        rs = reg;
        rw = gpio::Low;
        enable(gpio::High);
        bus.write(byte);
        enable(gpio::Low);
        waitUntillReady();
    }

    /*
    Refer to page 45 for initializaton details in datasheet.

    For some unknown reason, all stages are not required.
    With winstar WEH oled displays, third stage caused weird characters
    to be displayed, when initialized more than once without power cycle.
    */
    LCD::LCD(const gpio::Bus8Bit & b, const gpio::Output & _rs, const gpio::Output & _rw, const gpio::Output & _e) :
        bus(b),
        rs(_rs),
        rw(_rw),
        e(_e)
    {
        _delay_ms(15);
        sendByte(Mode_8Bit | Lines_2 | Dots_5x8, COMMAND);
        sendByte(HideCursor, COMMAND);
        sendByte(DisplayOn, COMMAND);
        sendByte(ENTRY_CURSOR_RIGHT, COMMAND);
        sendByte(ClearScreen, COMMAND);
    }

    void
    LCD::write(const u8 byte)
    {
        sendByte(byte, DATA);
    }

    void
    LCD::set(const HD44780::Cmd c) const
    {
        sendByte(c, COMMAND);
    }

    void
    LCD::set(const Position position) const
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
        sendByte(static_cast<u8>(SET_DDRAM_ADDRESS + address + position.row), COMMAND);
    }
}

#ifndef hd44780_h
#define hd44780_h

#include "../gpio.h"

#include <stdint.h>

namespace HD44780 {

    enum Cmd {
        ClearScreen = 0x01,
        CursorHome  = 0x02,
    };

    /*
    Line and row start from 0.
    */
    struct Position {
        uint8_t line;
        uint8_t row;
    };

    class LCD {
        const GPIO::Port      dataLine;
        const GPIO::OutputPin rs;
        const GPIO::OutputPin rw;
        const GPIO::OutputPin e;

        void    waitUntillReady() const;
        void    enable(const GPIO::PinState) const;
        uint8_t read() const;
        void    sendByte(uint8_t, GPIO::PinState) const;

    public:
        LCD(const GPIO::Port, const GPIO::Pin, const GPIO::Pin, const GPIO::Pin);
        void write(const uint8_t) const;
        void set(const Cmd) const;
        void set(const Position &) const;
    };
}

#endif

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

    struct Bus8bit {
        const GPIO::Port      line;
        const GPIO::OutputPin rs;
        const GPIO::OutputPin rw;
        const GPIO::OutputPin e;
    };

    class LCD {
        const Bus8bit bus;

        void    waitUntillReady();
        void    enable_high();
        void    enable_low();
        uint8_t read();
        void    sendByte(uint8_t, GPIO::PinState);

    public:
        LCD(const Bus8bit);
        void write(const char * str);
        void set(Cmd);
        void set(const Position &);
    };
}

#endif

#ifndef uart_h
#define uart_h

#include "buffer.h"

#include <avr/io.h>
#include <stdint.h>

#define BAUD_1X(baud) (((F_CPU) + 8UL * (baud)) / (16UL * (baud)) - 1UL)
#define BAUD_2X(baud) (((F_CPU) + 4UL * (baud)) / (8UL * (baud)) - 1UL)

enum BAUD_RATE_1X : unsigned long {
    x1_2400   = BAUD_1X(2400),
    x1_4800   = BAUD_1X(4800),
    x1_9600   = BAUD_1X(9600),
    x1_14400  = BAUD_1X(14400),
    x1_19200  = BAUD_1X(19200),
    x1_28800  = BAUD_1X(28800),
    x1_38400  = BAUD_1X(38400),
    x1_57600  = BAUD_1X(57600),
    x1_76800  = BAUD_1X(76800),
    x1_115200 = BAUD_1X(115200),
    x1_230400 = BAUD_1X(230400),
    x1_250000 = BAUD_1X(250000),
};

enum BAUD_RATE_2X : unsigned long {
    x2_2400   = BAUD_2X(2400),
    x2_4800   = BAUD_2X(4800),
    x2_9600   = BAUD_2X(9600),
    x2_14400  = BAUD_2X(14400),
    x2_19200  = BAUD_2X(19200),
    x2_28800  = BAUD_2X(28800),
    x2_38400  = BAUD_2X(38400),
    x2_57600  = BAUD_2X(57600),
    x2_76800  = BAUD_2X(76800),
    x2_115200 = BAUD_2X(115200),
    x2_230400 = BAUD_2X(230400),
    x2_250000 = BAUD_2X(250000),
};

// Values represent bits to be written into UCSRC.
enum PARITY_MODE : uint8_t {
    DISABLED = 0,
    EVEN     = (1 << UPM1),
    ODD      = (1 << UPM1) | (1 << UPM0),
};

// Values represent bits to be written into UCSRC.
enum STOP_BITS : uint8_t {
    BIT_1 = 0,
    BIT_2 = (1 << USBS),
};

// Values represent bits to be written into UCSRC.
enum CHARACTER_SIZE : uint8_t {
    BIT_5 = 0,
    BIT_6 = (1 << UCSZ0),
    BIT_7 = (1 << UCSZ1),
    BIT_8 = (1 << UCSZ0) | (1 << UCSZ1),
};

class Uart {

public:
    void start(void);
    void parity(enum PARITY_MODE);
    void stop_bits(enum STOP_BITS);
    void character_size(enum CHARACTER_SIZE);
    void speed(enum BAUD_RATE_1X);
    void speed(enum BAUD_RATE_2X);
    void write(const char * string);
    void write(uint8_t byte);
};

#endif

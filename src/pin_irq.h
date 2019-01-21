#ifndef pin_irq_h
#define pin_irq_h

#include <stdint.h>

namespace PinInterrupts {

    enum Trigger {
        Low     = 0x00,
        Change  = 0x01,
        Falling = 0x02,
        Rising  = 0x03,
    };

    enum Pin {
        INT0 = 0,
        INT1,
    };

    void set(Pin, Trigger);
    void enable(Pin);
    void disable(Pin);
}

#endif
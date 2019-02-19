#ifndef gpio_h
#define gpio_h

#include "sfr.h"

#include <stdint.h>

namespace GPIO {

    enum PinNumber {
        Pin0 = 0x01,
        Pin1 = 0x02,
        Pin2 = 0x04,
        Pin3 = 0x08,
        Pin4 = 0x10,
        Pin5 = 0x20,
        Pin6 = 0x40,
        Pin7 = 0x80,
    };

    enum class PinState {
        Low,
        High,
    };

    enum class PullMode {
        HiZ,
        PullUp,
    };

    class Output8Bit;
    class Input8Bit;

    struct Port {
        const uint8_t port_address;
        const uint8_t pin_address;
        const uint8_t ddr_address;

        Output8Bit output() const;
        Input8Bit  input() const;
    };

    struct Pin {
        const GPIO::Port      port;
        const GPIO::PinNumber number;
    };

    class OutputPin {
        const GPIO::Pin pin;

    public:
        OutputPin(const GPIO::Pin);
        void operator=(const GPIO::PinState) const;
        void set(const GPIO::PinState) const;
    };

    class InputPin {
        const GPIO::Pin pin;

    public:
        InputPin(const GPIO::Pin);
        bool           operator==(const GPIO::PinState) const;
        void           set(const GPIO::PullMode) const;
        GPIO::PinState read() const;
    };

    class Output8Bit {
        const GPIO::Port port;

    public:
        Output8Bit(const GPIO::Port);
        void operator=(const uint8_t) const;
        void set(const uint8_t) const;
    };

    class Input8Bit {
        const GPIO::Port port;

    public:
        Input8Bit(const GPIO::Port);
        bool    operator==(const uint8_t) const;
        void    set(const GPIO::PullMode) const;
        uint8_t read() const;
    };
}

#if defined(__AVR_ATmega328P__)
#    include "gpio/atmega328p_gpio.h"
#elif defined(__AVR_ATmega32__)
#    include "gpio/atmega32_gpio.h"
#elif defined(__AVR_ATmega32A__)
#    include "gpio/atmega32a_gpio.h"
#else
#    error "Unsupported MCU."
#endif

#endif
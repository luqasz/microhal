#pragma once

#include "sfr.h"

#include <stdint.h>

namespace USART {

    constexpr uint16_t
    calc_baud(const unsigned long int baud, const uint8_t divisor)
    {
        return static_cast<uint16_t>(
            ((F_CPU) + (8UL / divisor) * (baud)) / ((16UL / divisor) * (baud)) - 1UL);
    }

    enum class BaudRate_1x : uint16_t {
        x1_2400   = calc_baud(2400UL, 1),
        x1_4800   = calc_baud(4800UL, 1),
        x1_9600   = calc_baud(9600UL, 1),
        x1_14400  = calc_baud(14400UL, 1),
        x1_19200  = calc_baud(19200UL, 1),
        x1_28800  = calc_baud(28800UL, 1),
        x1_38400  = calc_baud(38400UL, 1),
        x1_57600  = calc_baud(57600UL, 1),
        x1_76800  = calc_baud(76800UL, 1),
        x1_115200 = calc_baud(115200UL, 1),
        x1_230400 = calc_baud(230400UL, 1),
        x1_250000 = calc_baud(250000UL, 1),
    };

    enum class BaudRate_2x : uint16_t {
        x2_2400   = calc_baud(2400UL, 2),
        x2_4800   = calc_baud(4800UL, 2),
        x2_9600   = calc_baud(9600UL, 2),
        x2_14400  = calc_baud(14400UL, 2),
        x2_19200  = calc_baud(19200UL, 2),
        x2_28800  = calc_baud(28800UL, 2),
        x2_38400  = calc_baud(38400UL, 2),
        x2_57600  = calc_baud(57600UL, 2),
        x2_76800  = calc_baud(76800UL, 2),
        x2_115200 = calc_baud(115200UL, 2),
        x2_230400 = calc_baud(230400UL, 2),
        x2_250000 = calc_baud(250000UL, 2),
    };

    enum class Parity : uint8_t {
        None,
        Even,
        Odd,
    };

    enum class StopBits : uint8_t {
        Bit_1,
        Bit_2,
    };

    enum class CharacterSize : uint8_t {
        Bit_5,
        Bit_6,
        Bit_7,
        Bit_8,
    };

    enum class Channel : uint8_t {
        RX,
        TX,
    };

    class Async {

    public:
        void enable(USART::Channel) const;
        void disable(USART::Channel) const;
        void set(USART::BaudRate_1x) const;
        void set(USART::BaudRate_2x) const;
        void write(uint8_t byte) const;
        bool is_tx_buffer_empty() const;
    };

    class TX {
    };
}
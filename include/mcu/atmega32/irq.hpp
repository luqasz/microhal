#pragma once

#include "../common/atmega/irq.hpp"

namespace irq {

    struct INT0 {
        static void
        handler() VECTOR("__vector_1");
    };

    struct INT1 {
        static void
        handler() VECTOR("__vector_2");
    };

    struct INT2 {
        static void
        handler() VECTOR("__vector_3");
    };

    struct Timer2_CompareMatch {
        static void
        handler() VECTOR("__vector_4");
    };

    struct Timer2_Overflow {
        static void
        handler() VECTOR("__vector_5");
    };

    struct Timer1_Capture {
        static void
        handler() VECTOR("__vector_6");
    };

    struct Timer1_CompareMatch_A {
        static void
        handler() VECTOR("__vector_7");
    };

    struct Timer1_CompareMatch_B {
        static void
        handler() VECTOR("__vector_8");
    };

    struct Timer1_Overflow {
        static void
        handler() VECTOR("__vector_9");
    };

    struct Timer0_CompareMatch {
        static void
        handler() VECTOR("__vector_10");
    };

    struct Timer0_Overflow {
        static void
        handler() VECTOR("__vector_11");
    };

    struct SPI0 {
        static void
        handler() VECTOR("__vector_12");
    };

    struct USART0_RX {
        static void
        handler() VECTOR("__vector_13");
    };

    struct UDR0_Empty {
        static void
        handler() VECTOR("__vector_14");
    };

    struct USART0_TX {
        static void
        handler() VECTOR("__vector_15");
    };

    struct ADC {
        static void
        handler() VECTOR("__vector_16");
    };

    struct EEPROM {
        static void
        handler() VECTOR("__vector_17");
    };

    struct AnalogComparator {
        static void
        handler() VECTOR("__vector_18");
    };

    struct TWI0 {
        static void
        handler() VECTOR("__vector_19");
    };

    struct SPM {
        static void
        handler() VECTOR("__vector_20");
    };
}

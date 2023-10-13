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

    struct PCINT0 {
        static void
        handler() VECTOR("__vector_3");
    };

    struct PCINT1 {
        static void
        handler() VECTOR("__vector_4");
    };

    struct PCINT2 {
        static void
        handler() VECTOR("__vector_5");
    };

    struct WDT {
        static void
        handler() VECTOR("__vector_6");
    };

    struct Timer2_CompareMatch_A {
        static void
        handler() VECTOR("__vector_7");
    };

    struct Timer2_CompareMatch_B {
        static void
        handler() VECTOR("__vector_8");
    };

    struct Timer2_Overflow {
        static void
        handler() VECTOR("__vector_9");
    };

    struct Timer1_Capture {
        static void
        handler() VECTOR("__vector_10");
    };

    struct Timer1_CompareMatch_A {
        static void
        handler() VECTOR("__vector_11");
    };

    struct Timer1_CompareMatch_B {
        static void
        handler() VECTOR("__vector_12");
    };

    struct Timer1_Overflow {
        static void
        handler() VECTOR("__vector_13");
    };

    struct Timer0_CompareMatch_A {
        static void
        handler() VECTOR("__vector_14");
    };

    struct Timer0_CompareMatch_B {
        static void
        handler() VECTOR("__vector_15");
    };

    struct Timer0_Overflow {
        static void
        handler() VECTOR("__vector_16");
    };

    struct SPI {
        static void
        handler() VECTOR("__vector_17");
    };

    struct USART0_RX {
        static void
        handler() VECTOR("__vector_18");
    };

    struct USART0_UDRE {
        static void
        handler() VECTOR("__vector_19");
    };

    struct USART0_TX {
        static void
        handler() VECTOR("__vector_20");
    };

    struct ADC {
        static void
        handler() VECTOR("__vector_21");
    };

    struct EEPROM {
        static void
        handler() VECTOR("__vector_22");
    };

    struct AnalogComparator {
        static void
        handler() VECTOR("__vector_23");
    };

    struct TWI {
        static void
        handler() VECTOR("__vector_24");
    };

    struct SPM {
        static void
        handler() VECTOR("__vector_25");
    };
}

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

    struct INT3 {
        static void
        handler() VECTOR("__vector_4");
    };

    struct INT4 {
        static void
        handler() VECTOR("__vector_5");
    };

    struct INT5 {
        static void
        handler() VECTOR("__vector_6");
    };

    struct INT6 {
        static void
        handler() VECTOR("__vector_7");
    };

    struct INT7 {
        static void
        handler() VECTOR("__vector_8");
    };

    struct PCINT0 {
        static void
        handler() VECTOR("__vector_9");
    };

    struct PCINT1 {
        static void
        handler() VECTOR("__vector_10");
    };

    struct PCINT2 {
        static void
        handler() VECTOR("__vector_11");
    };

    struct WDT {
        static void
        handler() VECTOR("__vector_12");
    };

    struct Timer2_CompareMatch_A {
        static void
        handler() VECTOR("__vector_13");
    };

    struct Timer2_CompareMatch_B {
        static void
        handler() VECTOR("__vector_14");
    };

    struct Timer2_Overflow {
        static void
        handler() VECTOR("__vector_15");
    };

    struct Timer1_Capture {
        static void
        handler() VECTOR("__vector_16");
    };

    struct Timer1_CompareMatch_A {
        static void
        handler() VECTOR("__vector_17");
    };

    struct Timer1_CompareMatch_B {
        static void
        handler() VECTOR("__vector_18");
    };

    struct Timer1_CompareMatch_C {
        static void
        handler() VECTOR("__vector_19");
    };

    struct Timer1_Overflow {
        static void
        handler() VECTOR("__vector_20");
    };

    struct Timer0_CompareMatch_A {
        static void
        handler() VECTOR("__vector_21");
    };

    struct Timer0_CompareMatch_B {
        static void
        handler() VECTOR("__vector_22");
    };

    struct Timer0_Overflow {
        static void
        handler() VECTOR("__vector_23");
    };

    struct SPI {
        static void
        handler() VECTOR("__vector_24");
    };

    struct USART0_RX {
        static void
        handler() VECTOR("__vector_25");
    };

    struct USART0_UDRE {
        static void
        handler() VECTOR("__vector_26");
    };

    struct USART0_TX {
        static void
        handler() VECTOR("__vector_27");
    };

    struct AnalogComparator {
        static void
        handler() VECTOR("__vector_28");
    };

    struct ADC {
        static void
        handler() VECTOR("__vector_29");
    };

    struct EEPROM {
        static void
        handler() VECTOR("__vector_30");
    };

    struct Timer3_Capture {
        static void
        handler() VECTOR("__vector_31");
    };

    struct Timer3_CompareMatch_A {
        static void
        handler() VECTOR("__vector_32");
    };

    struct Timer3_CompareMatch_B {
        static void
        handler() VECTOR("__vector_33");
    };

    struct Timer3_CompareMatch_C {
        static void
        handler() VECTOR("__vector_34");
    };

    struct Timer3_Overflow {
        static void
        handler() VECTOR("__vector_35");
    };

    struct USART1_RX {
        static void
        handler() VECTOR("__vector_36");
    };

    struct USART1_UDRE {
        static void
        handler() VECTOR("__vector_37");
    };

    struct USART1_TX {
        static void
        handler() VECTOR("__vector_38");
    };

    struct TWI0 {
        static void
        handler() VECTOR("__vector_39");
    };

    struct SPM {
        static void
        handler() VECTOR("__vector_40");
    };

    struct Timer4_Capture {
        static void
        handler() VECTOR("__vector_41");
    };

    struct Timer4_CompareMatch_A {
        static void
        handler() VECTOR("__vector_42");
    };

    struct Timer4_CompareMatch_B {
        static void
        handler() VECTOR("__vector_43");
    };

    struct Timer4_CompareMatch_C {
        static void
        handler() VECTOR("__vector_44");
    };

    struct Timer4_Overflow {
        static void
        handler() VECTOR("__vector_45");
    };

    struct Timer5_Capture {
        static void
        handler() VECTOR("__vector_46");
    };

    struct Timer5_CompareMatch_A {
        static void
        handler() VECTOR("__vector_47");
    };

    struct Timer5_CompareMatch_B {
        static void
        handler() VECTOR("__vector_48");
    };

    struct Timer5_CompareMatch_C {
        static void
        handler() VECTOR("__vector_49");
    };

    struct Timer5_Overflow {
        static void
        handler() VECTOR("__vector_50");
    };

    struct USART2_RX {
        static void
        handler() VECTOR("__vector_51");
    };

    struct USART2_UDRE {
        static void
        handler() VECTOR("__vector_52");
    };

    struct USART2_TX {
        static void
        handler() VECTOR("__vector_53");
    };

    struct USART3_RX {
        static void
        handler() VECTOR("__vector_54");
    };

    struct USART3_UDRE {
        static void
        handler() VECTOR("__vector_55");
    };

    struct USART3_TX {
        static void
        handler() VECTOR("__vector_56");
    };

}

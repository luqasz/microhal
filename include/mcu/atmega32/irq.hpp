#pragma once

#include "../../irq.hpp"

struct IRQ : IRQ_Base {
    static void
    INT0() VECTOR("__vector_1");
    static void
    INT1() VECTOR("__vector_2");
    static void
    INT2() VECTOR("__vector_3");
    static void
    Timer2_CompareMatch() VECTOR("__vector_4");
    static void
    Timer2_Overflow() VECTOR("__vector_5");
    static void
    Timer1_Capture() VECTOR("__vector_6");
    static void
    Timer1_CompareMatch_A() VECTOR("__vector_7");
    static void
    Timer1_CompareMatch_B() VECTOR("__vector_8");
    static void
    Timer1_Overflow() VECTOR("__vector_9");
    static void
    Timer0_CompareMatch() VECTOR("__vector_10");
    static void
    Timer0_Overflow() VECTOR("__vector_11");
    static void
    SPI0() VECTOR("__vector_12");
    static void
    USART0_RX() VECTOR("__vector_13");
    static void
    UDR0_Empty() VECTOR("__vector_14");
    static void
    USART0_TX() VECTOR("__vector_15");
    static void
    ADC() VECTOR("__vector_16");
    static void
    EEPROM() VECTOR("__vector_17");
    static void
    AnalogComparator() VECTOR("__vector_18");
    static void
    TWI0() VECTOR("__vector_19");
    static void
    SPM() VECTOR("__vector_20");
};

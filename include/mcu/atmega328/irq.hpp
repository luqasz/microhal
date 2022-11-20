#pragma once

#include "../common/atmega/irq.hpp"
#include "../../irq.hpp"

class IRQ : public IRQ_Base {
public:
    static void
    INT0() VECTOR("__vector_1");
    static void
    INT1() VECTOR("__vector_2");
    static void
    PCINT0() VECTOR("__vector_3");
    static void
    PCINT1() VECTOR("__vector_4");
    static void
    PCINT2() VECTOR("__vector_5");
    static void
    WDT() VECTOR("__vector_6");
    static void
    Timer2_CompareMatch_A() VECTOR("__vector_7");
    static void
    Timer2_CompareMatch_B() VECTOR("__vector_8");
    static void
    Timer2_Overflow() VECTOR("__vector_9");
    static void
    Timer1_Capture() VECTOR("__vector_10");
    static void
    Timer1_CompareMatch_A() VECTOR("__vector_11");
    static void
    Timer1_CompareMatch_B() VECTOR("__vector_12");
    static void
    Timer1_Overflow() VECTOR("__vector_13");
    static void
    Timer0_CompareMatch_A() VECTOR("__vector_14");
    static void
    Timer0_CompareMatch_B() VECTOR("__vector_15");
    static void
    Timer0_Overflow() VECTOR("__vector_16");
    static void
    SPI() VECTOR("__vector_17");
    static void
    USART0_RX() VECTOR("__vector_18");
    static void
    USART0_UDRE() VECTOR("__vector_19");
    static void
    USART0_TX() VECTOR("__vector_20");
    static void
    ADC() VECTOR("__vector_21");
    static void
    EEPROM() VECTOR("__vector_22");
    static void
    Analog_Comparator() VECTOR("__vector_23");
    static void
    TWI() VECTOR("__vector_24");
    static void
    SPM() VECTOR("__vector_25");
};

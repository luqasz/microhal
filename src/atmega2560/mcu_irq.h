#pragma once

#include "../irq.h"

class Irq : public Irq_Base {
public:
    static void
    INT0() VECTOR("__vector_1");
    static void
    INT1() VECTOR("__vector_2");
    static void
    INT2() VECTOR("__vector_3");
    static void
    INT3() VECTOR("__vector_4");
    static void
    INT4() VECTOR("__vector_5");
    static void
    INT5() VECTOR("__vector_6");
    static void
    INT6() VECTOR("__vector_7");
    static void
    INT7() VECTOR("__vector_8");
    static void
    PCINT0() VECTOR("__vector_9");
    static void
    PCINT1() VECTOR("__vector_10");
    static void
    PCINT2() VECTOR("__vector_11");
    static void
    WDT() VECTOR("__vector_12");
    static void
    Timer2_CompareMatch_A() VECTOR("__vector_13");
    static void
    Timer2_CompareMatch_B() VECTOR("__vector_14");
    static void
    Timer2_Overflow() VECTOR("__vector_15");
    static void
    Timer1_Capture() VECTOR("__vector_16");
    static void
    Timer1_CompareMatch_A() VECTOR("__vector_17");
    static void
    Timer1_CompareMatch_B() VECTOR("__vector_18");
    static void
    Timer1_CompareMatch_C() VECTOR("__vector_19");
    static void
    Timer1_Overflow() VECTOR("__vector_20");
    static void
    Timer0_CompareMatch_A() VECTOR("__vector_21");
    static void
    Timer0_CompareMatch_B() VECTOR("__vector_22");
    static void
    Timer0_Overflow() VECTOR("__vector_23");
    static void
    SPI() VECTOR("__vector_24");
    static void
    USART0_RX() VECTOR("__vector_25");
    static void
    USART0_UDRE() VECTOR("__vector_26");
    static void
    USART0_TX() VECTOR("__vector_27");
    static void
    Analog_Comparator() VECTOR("__vector_28");
    static void
    ADC() VECTOR("__vector_29");
    static void
    EEPROM() VECTOR("__vector_30");
    static void
    Timer3_Capture() VECTOR("__vector_31");
    static void
    Timer3_CompareMatch_A() VECTOR("__vector_32");
    static void
    Timer3_CompareMatch_B() VECTOR("__vector_33");
    static void
    Timer3_CompareMatch_C() VECTOR("__vector_34");
    static void
    Timer3_Overflow() VECTOR("__vector_35");
    static void
    USART1_RX() VECTOR("__vector_36");
    static void
    USART1_UDRE() VECTOR("__vector_37");
    static void
    USART1_TX() VECTOR("__vector_38");
    static void
    TWI0() VECTOR("__vector_39");
    static void
    SPM() VECTOR("__vector_40");
    static void
    Timer4_Capture() VECTOR("__vector_41");
    static void
    Timer4_CompareMatch_A() VECTOR("__vector_42");
    static void
    Timer4_CompareMatch_B() VECTOR("__vector_43");
    static void
    Timer4_CompareMatch_C() VECTOR("__vector_44");
    static void
    Timer4_Overflow() VECTOR("__vector_45");
    static void
    Timer5_Capture() VECTOR("__vector_46");
    static void
    Timer5_CompareMatch_A() VECTOR("__vector_47");
    static void
    Timer5_CompareMatch_B() VECTOR("__vector_48");
    static void
    Timer5_CompareMatch_C() VECTOR("__vector_49");
    static void
    Timer5_Overflow() VECTOR("__vector_50");
    static void
    USART2_RX() VECTOR("__vector_51");
    static void
    USART2_UDRE() VECTOR("__vector_52");
    static void
    USART2_TX() VECTOR("__vector_53");
    static void
    USART3_RX() VECTOR("__vector_54");
    static void
    USART3_UDRE() VECTOR("__vector_55");
    static void
    USART3_TX() VECTOR("__vector_56");
};

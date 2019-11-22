#ifndef mcu_pin_irq_h
#define mcu_pin_irq_h

namespace PinIRQ {
    auto INT_EDGE_REG       = Register<SFR::MCUCR>();
    auto INT_IRQ_ENABLE_REG = Register<SFR::GICR>();

    constexpr uint8_t INT1_TRIGGER_MASK = inverted<uint8_t>(INT_EDGE_REG.ISC11 | INT_EDGE_REG.ISC10);
    constexpr uint8_t INT0_TRIGGER_MASK = inverted<uint8_t>(INT_EDGE_REG.ISC01 | INT_EDGE_REG.ISC00);
}

#endif

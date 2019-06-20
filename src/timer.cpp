#include "timer.h"

namespace Timer0 {

    constexpr uint8_t CLOCK_MASK = inverted<uint8_t>(CLOCK_REG::CS00 | CLOCK_REG::CS01 | CLOCK_REG::CS02);
    constexpr uint8_t MODE_MASK  = inverted<uint8_t>(WGM_REG::WGM00 | WGM_REG::WGM01);

    template <typename VALUE>
    constexpr void
    set_reg(VALUE value, uint8_t reg, uint8_t mask)
    {
        uint8_t reg_value = SFR::iomem(reg);
        reg_value &= mask;
        reg_value |= static_cast<uint8_t>(value);
        SFR::iomem(reg) = reg_value;
    }

    void
    set(Clock clock)
    {
        set_reg(clock, CLOCK_REG::address, CLOCK_MASK);
    }

    void
    set(Mode mode)
    {
        set_reg(mode, WGM_REG::address, MODE_MASK);
    }

    uint8_t
    getCounter()
    {
        return SFR::iomem(COUNTER_REG::address);
    }

    uint8_t
    getCompareReg()
    {
        return SFR::iomem(COMPARE_REG::address);
    }

    void
    enable(Irq irq)
    {
        SFR::iomem(IRQ_REG::address) |= static_cast<uint8_t>(irq);
    }

}
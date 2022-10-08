#pragma once

#include "utils.hpp"

#include <stdint.h>

namespace SFR {

    template <typename WIDTH>
    WIDTH volatile &
    iomem(uint16_t address)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        return *reinterpret_cast<WIDTH volatile *>(address);
#pragma GCC diagnostic pop
    }

    void
    setBit(const uint16_t address, const uint8_t bit)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        iomem<uint8_t>(address) |= bit;
#pragma GCC diagnostic pop
    }

    void
    setBit(const uint16_t address, const uint8_t bit, const uint8_t set_mask)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        uint8_t current = iomem<uint8_t>(address);
        current         = current | inverted<uint8_t>(set_mask);
        iomem<uint8_t>(address) |= bit;
#pragma GCC diagnostic pop
    }

    void
    clearBit(const uint16_t address, const uint8_t bit)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        iomem<uint8_t>(address) &= static_cast<uint8_t>(~bit);
#pragma GCC diagnostic pop
    }

    template <typename REG_TYPE, typename WIDTH>
    class RegisterRO : public REG_TYPE {
    public:
        WIDTH
        read() const
        {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
            return iomem<WIDTH>(REG_TYPE::address);
#pragma GCC diagnostic pop
        }

        bool
        isSet(const uint8_t bit) const
        {
            return read() & bit;
        }

        void
        waitForSetBit(const uint8_t bit) const
        {
            while (!isSet(bit)) {
            };
        }

        void
        waitForClearedBit(const uint8_t bit) const
        {
            while (isSet(bit)) {
            };
        }
    };

    template <typename REG_TYPE, typename WIDTH>
    class RegisterRW : public SFR::RegisterRO<REG_TYPE, WIDTH> {
    public:
        void
        write(const WIDTH value) const
        {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
            iomem<WIDTH>(REG_TYPE::address) = value;
#pragma GCC diagnostic pop
        }

        void
        operator=(const WIDTH value) const
        {
            write(value);
        }

        void
        setBit(const uint8_t bit) const
        {
            SFR::setBit(REG_TYPE::address, bit);
        }

        void
        setBit(const uint8_t bit, const uint8_t set_mask) const
        {
            SFR::setBit(REG_TYPE::address, bit, set_mask);
        }

        void
        clearBit(const WIDTH bit) const
        {
            SFR::clearBit(REG_TYPE::address, bit);
        }
    };
}

#ifdef MCU
#    if MCU == atmega32
#        include "atmega32/mcu_sfr.hpp"
#    elif MCU == atmega328
#        include "atmega328/mcu_sfr.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

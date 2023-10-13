#pragma once

#include "utils.hpp"
#include "types.hpp"

namespace SFR {

    template <typename WIDTH>
    WIDTH inline volatile &
    iomem(u16 address)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        return *reinterpret_cast<WIDTH volatile *>(address);
#pragma GCC diagnostic pop
    }

    inline void
    setBit(const u16 address, const u8 bit)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        iomem<u8>(address) |= bit;
#pragma GCC diagnostic pop
    }

    inline void
    setBit(const u16 address, const u8 bit, const u8 set_mask)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        u8 current = iomem<u8>(address);
        current = current | inverted<u8>(set_mask);
        iomem<u8>(address) |= bit;
#pragma GCC diagnostic pop
    }

    inline void
    clearBit(const u16 address, const u8 bit)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        iomem<u8>(address) &= static_cast<u8>(~bit);
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
        isSet(const u8 bit) const
        {
            return read() & bit;
        }

        void
        waitForSetBit(const u8 bit) const
        {
            while (!isSet(bit)) {
            };
        }

        void
        waitForClearedBit(const u8 bit) const
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
        setBit(const u8 bit) const
        {
            SFR::setBit(REG_TYPE::address, bit);
        }

        void
        setBit(const u8 bit, const u8 set_mask) const
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

#if MCU_ATMEGA32
#    include "mcu/atmega32/sfr.hpp"
#elif MCU_ATMEGA328
#    include "mcu/atmega328/sfr.hpp"
#elif MCU_ATMEGA2560
#    include "mcu/atmega2560/sfr.hpp"
#else
#    error "Unknown MCU."
#endif

#ifndef sfr_h
#define sfr_h

#include "utils.h"

#include <stdint.h>

namespace SFR {

    template <typename WIDTH>
    WIDTH volatile &
    iomem(uint16_t address)
    {
        return *reinterpret_cast<WIDTH volatile *>(address);
    }

    template <typename WIDTH>
    void
    setBit(uint16_t address, uint8_t bit)
    {
        iomem<WIDTH>(address) |= bit;
    }

    template <typename WIDTH>
    void
    clearBit(uint16_t address, uint8_t bit)
    {
        iomem<WIDTH>(address) &= static_cast<uint8_t>(~bit);
    }

    template <typename REG_TYPE, typename WIDTH>
    class BitRegisterRO : public REG_TYPE {
    public:
        WIDTH
        read() const
        {
            return iomem<WIDTH>(REG_TYPE::address);
        }

        bool
        isSet(const uint8_t bit) const
        {
            return read() & bit;
        }
    };

    template <typename REG_TYPE, typename WIDTH>
    class DataRegisterRO : public REG_TYPE {
    public:
        WIDTH
        read() const
        {
            return iomem<WIDTH>(REG_TYPE::address);
        }
    };

    template <typename REG_TYPE, typename WIDTH>
    class DataRegisterRW : public DataRegisterRO<REG_TYPE, WIDTH> {
    public:
        void
        write(const WIDTH value) const
        {
            SFR::iomem<WIDTH>(REG_TYPE::address) = value;
        }

        void
        operator=(const WIDTH value) const
        {
            write(value);
        }
    };

    template <typename REG_TYPE, typename WIDTH>
    class BitRegisterRW : public SFR::BitRegisterRO<REG_TYPE, WIDTH> {
    public:
        void
        write(const WIDTH value) const
        {
            SFR::iomem<WIDTH>(REG_TYPE::address) = value;
        }

        void
        operator=(const WIDTH value) const
        {
            write(value);
        }

        void
        setBit(const WIDTH bit) const
        {
            SFR::iomem<WIDTH>(REG_TYPE::address) |= bit;
        }

        void
        clearBit(const WIDTH bit) const
        {
            SFR::iomem<WIDTH>(REG_TYPE::address) &= static_cast<WIDTH>(~bit);
        }
    };
}

template <typename REG_TYPE, typename WIDTH = uint8_t>
class Register : public SFR::BitRegisterRO<REG_TYPE, WIDTH> {
public:
    void
    write(const WIDTH value) const
    {
        SFR::iomem<WIDTH>(REG_TYPE::address) = value;
    }

    void
    operator=(const WIDTH value) const
    {
        write(value);
    }

    void
    setBit(const WIDTH bit) const
    {
        SFR::iomem<WIDTH>(REG_TYPE::address) |= bit;
    }

    void
    clearBit(const WIDTH bit) const
    {
        SFR::iomem<WIDTH>(REG_TYPE::address) &= static_cast<WIDTH>(~bit);
    }
};

#include <mcu_sfr.h>

#endif

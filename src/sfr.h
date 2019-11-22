#ifndef sfr_h
#define sfr_h

#include "utils.h"

#include <stdint.h>

namespace SFR {

    template <typename UINT>
    UINT volatile &
    iomem(UINT address)
    {
        return *reinterpret_cast<UINT volatile *>(address);
    }

    template <typename UINT>
    void
    setBit(UINT address, uint8_t bit)
    {
        iomem(address) |= bit;
    }

    template <typename UINT>
    void
    clearBit(UINT address, uint8_t bit)
    {
        iomem(address) &= static_cast<uint8_t>(~bit);
    }

    template <typename REG_TYPE, typename uint_type>
    class RegisterRO : public REG_TYPE {
    public:
        uint_type
        read() const
        {
            return iomem(REG_TYPE::address);
        }

        bool
        isSet(const uint8_t bit) const
        {
            return read() & bit;
        }
    };

    template <typename REG_TYPE, typename uint_type>
    class DataRegisterRO : public REG_TYPE {
    public:
        uint_type
        read() const
        {
            return iomem(REG_TYPE::address);
        }
    };

    template <typename REG_TYPE, typename uint_type>
    class DataRegisterRW : public DataRegisterRO<REG_TYPE, uint_type> {
    public:
        void
        write(const uint_type value) const
        {
            SFR::iomem(REG_TYPE::address) = value;
        }

        void
        operator=(const uint_type value) const
        {
            write(value);
        }
    };

}

template <typename REG_TYPE, typename uint_type = uint8_t>
class Register : public SFR::RegisterRO<REG_TYPE, uint_type> {
public:
    void
    write(const uint_type value) const
    {
        SFR::iomem(REG_TYPE::address) = value;
    }

    void
    operator=(const uint_type value) const
    {
        write(value);
    }

    void
    setBit(const uint_type bit) const
    {
        SFR::iomem(REG_TYPE::address) |= bit;
    }

    void
    clearBit(const uint_type bit) const
    {
        SFR::iomem(REG_TYPE::address) &= static_cast<uint_type>(~bit);
    }
};

#include <mcu_sfr.h>

#endif

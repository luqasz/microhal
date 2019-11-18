#ifndef sfr_h
#define sfr_h

#include "utils.h"

#include <stdint.h>

template <typename REG_TYPE, typename uint_type = uint8_t>
class Register : public REG_TYPE {
private:
    uint_type volatile &
    sfr(void) const
    {
        return *reinterpret_cast<uint_type volatile *>(REG_TYPE::address);
    }

public:
    void
    write(const uint_type value) const
    {
        sfr() = value;
    }

    uint_type
    read() const
    {
        return sfr();
    }

    void
    operator=(const uint_type value) const
    {
        sfr() = value;
    }

    void
    setBit(const uint_type bit) const
    {
        sfr() |= bit;
    }

    void
    clearBit(const uint_type bit) const
    {
        sfr() &= static_cast<uint_type>(~bit);
    }

    bool
    isSet(const uint8_t bit) const
    {
        return sfr() & bit;
    }
};

namespace SFR {

    uint8_t volatile &  iomem(uint8_t address);
    uint16_t volatile & iomem(uint16_t address);

    void setBit(uint8_t address, uint8_t bit);
    void setBit(uint16_t address, uint8_t bit);

    void clearBit(uint8_t address, uint8_t bit);
    void clearBit(uint16_t address, uint8_t bit);

}

#include <mcu_sfr.h>

#endif

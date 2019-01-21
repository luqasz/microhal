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

    operator uint_type() const
    {
        return sfr();
    }

    void
    setBit(const uint_type bit) const
    {
        sfr() |= bit;
    }

    void
    clearBit(const uint_type bit) const
    {
        sfr() &= static_cast<uint8_t>(~bit);
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

#if defined(__AVR_ATmega328P__)
#    include "sfr/atmega328p_sfr.h"
#elif defined(__AVR_ATmega32__)
#    include "sfr/atmega32_sfr.h"
#elif defined(__AVR_ATmega32A__)
#    include "sfr/atmega32a_sfr.h"
#else
#    error "Unsupported MCU."
#endif

#endif

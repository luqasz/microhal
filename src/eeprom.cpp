#include <eeprom.hpp>

namespace EEPROM {

    constexpr static auto ctrl_reg = SFR::RegisterRW<SFR::EECR, u8>();
    constexpr static auto addr_reg = SFR::RegisterRW<SFR::EEAR, u16>();
    constexpr static auto data_reg = SFR::RegisterRW<SFR::EEDR, u8>();

    void
    write(const u8 byte, const u16 address)
    {
        ctrl_reg.waitForClearedBit(WE); // Wait untill ready.
        addr_reg = address;
        data_reg = byte;
        ctrl_reg.setBit(MWE);
        ctrl_reg.setBit(WE);
    }

    u8
    read(const u16 address)
    {
        ctrl_reg.waitForClearedBit(WE); // Wait untill ready.
        addr_reg = address;
        ctrl_reg.setBit(RE);
        return data_reg.read();
    }
}
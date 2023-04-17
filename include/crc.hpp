#include <types.hpp>

// CRC-16/XMODEM
// https://reveng.sourceforge.io/crc-catalogue/all.htm
constexpr u16
crc16_xmodem(u16 crc, u8 byte)
{
    usize i;
    crc = u16(crc ^ (u16(byte) << 8));
    for (i = 0; i < 8; i++) {
        if (crc & 0x8000)
            crc = u16((crc << 1) ^ 0x1021);
        else
            crc <<= 1;
    }
    return crc;
}

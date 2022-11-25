#pragma once

#include "../../../iomem.hpp"
#include "../../../sfr.hpp"

namespace USART {

    struct UCSRA {
        constexpr static u8 MPCM = 1;   // Multi-processor Communication Mode
        constexpr static u8 U2X  = 2;   // Double the USART transmission speed
        constexpr static u8 UPE  = 4;   // Parity Error
        constexpr static u8 DOR  = 8;   // Data overRun
        constexpr static u8 FE   = 16;  // Framing Error
        constexpr static u8 UDRE = 32;  // USART Data Register Empty
        constexpr static u8 TXC  = 64;  // USART Transmitt Complete
        constexpr static u8 RXC  = 128; // USART Receive Complete
    };

    struct UCSRB {
        constexpr static u8 TXB8  = 1;   // Transmit Data Bit 8
        constexpr static u8 RXB8  = 2;   // Receive Data Bit 8
        constexpr static u8 UCSZ2 = 4;   // Character Size
        constexpr static u8 TXEN  = 8;   // Transmitter Enable
        constexpr static u8 RXEN  = 16;  // Receiver Enable
        constexpr static u8 UDRIE = 32;  // USART Data register Empty Interrupt Enable
        constexpr static u8 TXCIE = 64;  // TX Complete Interrupt Enable
        constexpr static u8 RXCIE = 128; // RX Complete Interrupt Enable
    };

    struct UCSRC {
        constexpr static u8 UCPOL  = 1;   // Clock Polarity
        constexpr static u8 UCSZ0  = 2;   // Character Size
        constexpr static u8 UCSZ1  = 4;   // Character Size
        constexpr static u8 USBS   = 8;   // Stop Bit Select
        constexpr static u8 UPM0   = 16;  // Parity Mode Bits
        constexpr static u8 UPM1   = 32;  // Parity Mode Bits
        constexpr static u8 UMSEL0 = 64;  // USART Mode Select
        constexpr static u8 UMSEL1 = 128; // USART Mode Select
        constexpr static u8 URSEL  = 128; // Register access bit
    };

    enum class Parity {
        None = 0,
        Even = UCSRC::UPM1,
        Odd  = UCSRC::UPM1 | UCSRC::UPM0,
    };

    enum class StopBits {
        One = 0,
        Two = UCSRC::USBS,
    };

    enum class CharacterSize {
        Bit5 = 0,
        Bit6 = UCSRC::UCSZ0,
        Bit7 = UCSRC::UCSZ1,
        Bit8 = UCSRC::UCSZ0 | UCSRC::UCSZ1,
    };

    enum class Channel {
        RX    = UCSRB::RXEN,
        TX    = UCSRB::TXEN,
        RX_TX = RX | TX,
    };
}
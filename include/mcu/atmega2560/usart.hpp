#pragma once

#include "sfr.hpp"

namespace USART {

    struct usart0 {
        static constexpr auto udr   = SFR::UDR0::address;
        static constexpr auto ucsra = SFR::UCSR0A::address;
        static constexpr auto ucsrb = SFR::UCSR0B::address;
        static constexpr auto ucsrc = SFR::UCSR0C::address;
        static constexpr auto ubrrl = SFR::UBRR0::address;
    };

    struct usart1 {
        static constexpr auto udr   = SFR::UDR1::address;
        static constexpr auto ucsra = SFR::UCSR1A::address;
        static constexpr auto ucsrb = SFR::UCSR1B::address;
        static constexpr auto ucsrc = SFR::UCSR1C::address;
        static constexpr auto ubrrl = SFR::UBRR1::address;
    };

    struct usart2 {
        static constexpr auto udr   = SFR::UDR2::address;
        static constexpr auto ucsra = SFR::UCSR2A::address;
        static constexpr auto ucsrb = SFR::UCSR2B::address;
        static constexpr auto ucsrc = SFR::UCSR2C::address;
        static constexpr auto ubrrl = SFR::UBRR2::address;
    };

    struct usart3 {
        static constexpr auto udr   = SFR::UDR3::address;
        static constexpr auto ucsra = SFR::UCSR3A::address;
        static constexpr auto ucsrb = SFR::UCSR3B::address;
        static constexpr auto ucsrc = SFR::UCSR3C::address;
        static constexpr auto ubrrl = SFR::UBRR3::address;
    };
}

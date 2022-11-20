#pragma once

#include "sfr.hpp"

namespace USART {

    struct usart0 {
        static constexpr auto udr   = SFR::UDR0::address;
        static constexpr auto ucsra = SFR::UCSR0A::address;
        static constexpr auto ucsrb = SFR::UCSR0B::address;
        static constexpr auto ucsrc = SFR::UCSR0C::address;
        static constexpr auto ubrrl = SFR::UBRR0::address;
        static constexpr auto ubrrh = SFR::UBRR0::address + 1;
    };

}

#include "../common/atmega/usart.hpp"
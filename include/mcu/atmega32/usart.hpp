#pragma once

#include "sfr.hpp"
#include "../common/atmega/usart.hpp"

namespace USART {

    struct usart0 {
        static constexpr auto udr = SFR::UDR::address;
        static constexpr auto ucsra = SFR::UCSRA::address;
        static constexpr auto ucsrb = SFR::UCSRB::address;
        static constexpr auto ucsrc = SFR::UCSRC::address;
        static constexpr auto ubrrh = SFR::UBRRH::address;
        static constexpr auto ubrrl = SFR::UBRRL::address;
    };

}

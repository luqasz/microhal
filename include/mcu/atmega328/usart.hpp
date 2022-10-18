#pragma once

#include "../../sfr.hpp"

namespace USART {

    struct USART0 {
        static constexpr auto udr   = SFR::RegisterRW<SFR::UDR0, uint8_t>();
        static constexpr auto ucsra = SFR::RegisterRW<UCSRA<SFR::UCSR0A>, uint8_t>();
        static constexpr auto ucsrb = SFR::RegisterRW<UCSRB<SFR::UCSR0B>, uint8_t>();
        static constexpr auto ucsrc = SFR::RegisterRW<UCSRC<SFR::UCSR0C>, uint8_t>();
        static constexpr auto ubrr  = set_ubrr_single<SFR::UBRR0>;
    };

}

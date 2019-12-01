#pragma once

#include "../sfr.h"

namespace USART {

    struct USART0 {
        static constexpr auto udr   = SFR::DataRegisterRW<SFR::UDR0, uint8_t>();
        static constexpr auto ucsra = Register<UCSRA<SFR::UCSR0A>>();
        static constexpr auto ucsrb = Register<UCSRB<SFR::UCSR0B>>();
        static constexpr auto ucsrc = Register<UCSRC<SFR::UCSR0C>>();
        static constexpr auto ubrr  = set_ubrr_single<SFR::UBRR0>;
    };

}

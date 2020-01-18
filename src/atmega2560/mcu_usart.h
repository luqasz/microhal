#pragma once

#include "../sfr.h"

namespace USART {

    struct USART0 {
        static constexpr auto udr   = SFR::DataRegisterRW<SFR::UDR0, uint8_t>();
        static constexpr auto ucsra = SFR::BitRegisterRW<UCSRA<SFR::UCSR0A>, uint8_t>();
        static constexpr auto ucsrb = SFR::BitRegisterRW<UCSRB<SFR::UCSR0B>, uint8_t>();
        static constexpr auto ucsrc = SFR::BitRegisterRW<UCSRC<SFR::UCSR0C>, uint8_t>();
        static constexpr auto ubrr  = set_ubrr_single<SFR::UBRR0>;
    };

}

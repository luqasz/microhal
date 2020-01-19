#ifndef MCU_USART_H
#define MCU_USART_H

#include "../sfr.h"

namespace USART {

    struct USART0 {
        static constexpr auto udr   = SFR::RegisterRW<SFR::UDR, uint8_t>();
        static constexpr auto ucsra = SFR::RegisterRW<UCSRA<SFR::UCSRA>, uint8_t>();
        static constexpr auto ucsrb = SFR::RegisterRW<UCSRB<SFR::UCSRB>, uint8_t>();
        static constexpr auto ucsrc = SFR::RegisterRW<UCSRC<SFR::UCSRC>, uint8_t>();
        static constexpr auto ubrr  = set_ubrr_split<SFR::UBRRH, SFR::UBRRL, SFR::UCSRC>;
    };

}

#endif


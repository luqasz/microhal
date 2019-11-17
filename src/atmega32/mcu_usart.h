#ifndef MCU_USART_H
#define MCU_USART_H

#include "../sfr.h"

namespace USART {

    struct USART0 {
        static constexpr auto udr = Register<SFR::UDR>();
        static constexpr auto ucsra = Register<UCSRA<SFR::UCSRA>>();
        static constexpr auto ucsrb = Register<UCSRB<SFR::UCSRB>>();
        static constexpr auto ucsrc = Register<UCSRC<SFR::UCSRC>>();
        static constexpr auto ubrr = set_ubrr_split<SFR::UBRRH, SFR::UBRRL, SFR::UCSRC>;
    };

}

#endif

#ifndef MCU_USART_H
#define MCU_USART_H

#include "mcu_sfr.h"
#include "../usart.h"

namespace USART {

    constexpr Registers USART0 = {
        SFR::UDR::address,
        SFR::UCSRA::address,
        SFR::UCSRB::address,
        SFR::UCSRC::address,
    };

}

auto constexpr UBRR0L = Register<SFR::UBRRL>();
auto constexpr UBRR0H = Register<SFR::UBRRH>();

#endif

#ifndef MCU_USART_H
#define MCU_USART_H

#include "mcu_sfr.h"
#include "../usart.h"

namespace USART {

    struct USART0 {
        static const uint8_t udr = SFR::UDR::address;
        static const uint8_t ucsra = SFR::UCSRA::address;
        static const uint8_t ucsrb = SFR::UCSRB::address;
        static const uint8_t ucsrc = SFR::UCSRC::address;
    };

}


#endif

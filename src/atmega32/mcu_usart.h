// vim: set ft=cpp:
#pragma once

#include "../sfr.h"

// namespace USART {
//     struct USART0 {
//     };
//     REGISTERS USART0 = {
//         static constexpr auto UCSRA = Register<SFR::UCSRA>(),
//         static constexpr auto UCSRB = Register<SFR::UCSRB>(),
//         static constexpr auto UCSRC = Register<SFR::UCSRC>(),
//         static constexpr auto UBRRH = Register<SFR::UBRRH>(),
//         static constexpr auto UBRRL = Register<SFR::UBRRL>(),
//         static constexpr auto UUDR  = Register<SFR::UDR>(),
//     };
// }

auto constexpr UCSR0A = Register<SFR::UCSRA>();
auto constexpr UCSR0B = Register<SFR::UCSRB>();
auto constexpr UCSR0C = Register<SFR::UCSRC>();
auto constexpr UBRR0L = Register<SFR::UBRRL>();
auto constexpr UBRR0H = Register<SFR::UBRRH>();
auto constexpr UDR0   = Register<SFR::UDR>();

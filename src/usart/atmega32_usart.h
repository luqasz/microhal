#ifndef atmega32_usart_h
#define atmega32_usart_h

#include "../sfr.h"

typedef SFR::UCSRA UCSR0A_REG;
typedef SFR::UCSRB UCSR0B_REG;
typedef SFR::UCSRC UCSR0C_REG;
typedef SFR::UBRRL UBRR0L_REG;
typedef SFR::UBRRH UBRR0H_REG;
typedef SFR::UDR UDR0_REG;

#endif
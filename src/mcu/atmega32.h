#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#define DDR_SPI DDRB
#define MOSI PB5
#define MISO PB6
#define SCK PB7
#define SS PB4

#define ADC_TRIGGER_SOURCE_REGISTER SFIOR

#define EXTERNAL_IRQ_REG MCUCR
#define IRQ_ENABLE_REG GICR
#define IRQ_HANDLERS 2

#define USART_RX_vect USART_RXC_vect

#endif

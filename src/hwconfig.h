#define DAC_CS_PIN PD4
#define DAC_CS_PORT PORTD
#define DAC_CS_DDR DDRD
#define DAC_CS_LOW DAC_CS_PORT &= (uint8_t) ~(1<<DAC_CS_PIN)
#define DAC_CS_HIGH DAC_CS_PORT |= (uint8_t) (1<<DAC_CS_PIN)

#ifndef MCP4922_H_
#define MCP4922_H_

#define MCP49XX_DAC_B           0x80
#define MCP49XX_DAC_A           0x00
#define MCP49XX_BUFFERED        0x40
#define MCP49XX_UNBUFFERED      0x00
#define MCP49XX_GAIN_1          0x20
#define MCP49XX_GAIN_2          0x00
#define MCP49XX_ACTIVE          0x10
#define MCP49XX_SHUTDOWN        0x00

void mcp4922_send (
    uint8_t control_bits,
    uint16_t value
);

#endif

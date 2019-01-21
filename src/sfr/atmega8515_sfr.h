#ifndef atmega8515_sfr_h
#define atmega8515_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega8515
*/

namespace SFR {

    // Oscillator Calibration Value
    struct OSCCAL {
        static const uint8_t address = 0x24;
        enum bits : uint8_t {
            OSCCAL0 = 1,   // Oscillator Calibration
            OSCCAL1 = 2,   // Oscillator Calibration
            OSCCAL2 = 4,   // Oscillator Calibration
            OSCCAL3 = 8,   // Oscillator Calibration
            OSCCAL4 = 16,  // Oscillator Calibration
            OSCCAL5 = 32,  // Oscillator Calibration
            OSCCAL6 = 64,  // Oscillator Calibration
            OSCCAL7 = 128, // Oscillator Calibration
        };
    };

    // Port E Input Pins
    struct PINE {
        static const uint8_t address = 0x25;
    };

    // Port E Data Direction Register
    struct DDRE {
        static const uint8_t address = 0x26;
    };

    // Port E Data Register
    struct PORTE {
        static const uint8_t address = 0x27;
    };

    // Analog Comparator Control And Status Register
    struct ACSR {
        static const uint8_t address = 0x28;
        enum bits : uint8_t {
            ACIS0 = 1,   // Analog Comparator Interrupt Mode Select bits
            ACIS1 = 2,   // Analog Comparator Interrupt Mode Select bits
            ACIC  = 4,   // Analog Comparator Input Capture Enable
            ACIE  = 8,   // Analog Comparator Interrupt Enable
            ACI   = 16,  // Analog Comparator Interrupt Flag
            ACO   = 32,  // Analog Compare Output
            ACBG  = 64,  // Analog Comparator Bandgap Select
            ACD   = 128, // Analog Comparator Disable
        };
    };

    // USART Baud Rate Register Low Byte
    struct UBRRL {
        static const uint8_t address = 0x29;
    };

    // USART Control and Status Register B
    struct UCSRB {
        static const uint8_t address = 0x2a;
        enum bits : uint8_t {
            TXB8  = 1,   // Transmit Data Bit 8
            RXB8  = 2,   // Receive Data Bit 8
            UCSZ2 = 4,   // Character Size Bit 2
            TXEN  = 8,   // Transmitter Enable
            RXEN  = 16,  // Receiver Enable
            UDRIE = 32,  // USART Data register Empty Interrupt Enable
            TXCIE = 64,  // TX Complete Interrupt Enable
            RXCIE = 128, // RX Complete Interrupt Enable
        };
    };

    // USART Control and Status Register A
    struct UCSRA {
        static const uint8_t address = 0x2b;
        enum bits : uint8_t {
            MPCM = 1,   // Multi-processor Communication Mode
            U2X  = 2,   // Double the USART transmission speed
            UPE  = 4,   // Parity Error
            DOR  = 8,   // Data overRun
            FE   = 16,  // Framing Error
            UDRE = 32,  // USART Data Register Empty
            TXC  = 64,  // USART Transmitt Complete
            RXC  = 128, // USART Receive Complete
        };
    };

    // USART I/O Data Register
    struct UDR {
        static const uint8_t address = 0x2c;
    };

    // SPI Control Register
    struct SPCR {
        static const uint8_t address = 0x2d;
        enum bits : uint8_t {
            SPR0 = 1,   // SPI Clock Rate Selects
            SPR1 = 2,   // SPI Clock Rate Selects
            CPHA = 4,   // Clock Phase
            CPOL = 8,   // Clock polarity
            MSTR = 16,  // Master/Slave Select
            DORD = 32,  // Data Order
            SPE  = 64,  // SPI Enable
            SPIE = 128, // SPI Interrupt Enable
        };
    };

    // SPI Status Register
    struct SPSR {
        static const uint8_t address = 0x2e;
        enum bits : uint8_t {
            SPI2X = 1,   // Double SPI Speed Bit
            WCOL  = 64,  // Write Collision Flag
            SPIF  = 128, // SPI Interrupt Flag
        };
    };

    // SPI Data Register
    struct SPDR {
        static const uint8_t address = 0x2f;
    };

    // Port D Input Pins
    struct PIND {
        static const uint8_t address = 0x30;
    };

    // Port D Data Direction Register
    struct DDRD {
        static const uint8_t address = 0x31;
    };

    // Port D Data Register
    struct PORTD {
        static const uint8_t address = 0x32;
    };

    // Port C Input Pins
    struct PINC {
        static const uint8_t address = 0x33;
    };

    // Port C Data Direction Register
    struct DDRC {
        static const uint8_t address = 0x34;
    };

    // Port C Data Register
    struct PORTC {
        static const uint8_t address = 0x35;
    };

    // Port B Input Pins
    struct PINB {
        static const uint8_t address = 0x36;
    };

    // Port B Data Direction Register
    struct DDRB {
        static const uint8_t address = 0x37;
    };

    // Port B Data Register
    struct PORTB {
        static const uint8_t address = 0x38;
    };

    // Port A Input Pins
    struct PINA {
        static const uint8_t address = 0x39;
    };

    // Port A Data Direction Register
    struct DDRA {
        static const uint8_t address = 0x3a;
    };

    // Port A Data Register
    struct PORTA {
        static const uint8_t address = 0x3b;
    };

    // EEPROM Control Register
    struct EECR {
        static const uint8_t address = 0x3c;
        enum bits : uint8_t {
            EERE  = 1, // EEPROM Read Enable
            EEWE  = 2, // EEPROM Write Enable
            EEMWE = 4, // EEPROM Master Write Enable
            EERIE = 8, // EEPROM Ready Interrupt Enable
        };
    };

    // EEPROM Data Register
    struct EEDR {
        static const uint8_t address = 0x3d;
    };

    // EEPROM Address Register  Bytes
    struct EEAR {
        static const uint16_t address = 0x3e;
    };

    // USART Control and Status Register C
    struct UCSRC {
        static const uint8_t address = 0x40;
        enum bits : uint8_t {
            UCPOL = 1,   // Clock Polarity
            UCSZ0 = 2,   // Character Size Bits
            UCSZ1 = 4,   // Character Size Bits
            USBS  = 8,   // Stop Bit Select
            UPM0  = 16,  // Parity Mode Bits
            UPM1  = 32,  // Parity Mode Bits
            UMSEL = 64,  // USART Mode Select
            URSEL = 128, // Register Select
        };
    };

    // USART Baud Rate Register High Byte
    struct UBRRH {
        static const uint8_t address = 0x40;
        enum bits : uint8_t {
            UBRR0  = 1,   // USART Baud Rate Register bits
            UBRR1  = 2,   // USART Baud Rate Register bits
            UBRR10 = 4,   // USART Baud Rate Register bit 11
            UBRR11 = 8,   // USART Baud Rate Register bit 11
            URSEL  = 128, // Register Select
        };
    };

    // Watchdog Timer Control Register
    struct WDTCR {
        static const uint8_t address = 0x41;
        enum bits : uint8_t {
            WDP0 = 1,  // Watch Dog Timer Prescaler bits
            WDP1 = 2,  // Watch Dog Timer Prescaler bits
            WDP2 = 4,  // Watch Dog Timer Prescaler bits
            WDE  = 8,  // Watch Dog Enable
            WDCE = 16, // Watchdog Change Enable
        };
    };

    // Timer/Counter1 Input Capture Register  Bytes
    struct ICR1 {
        static const uint16_t address = 0x44;
    };

    // Timer/Counter1 Output Compare Register B  Bytes
    struct OCR1B {
        static const uint16_t address = 0x48;
    };

    // Timer/Counter1 Output Compare Register A  Bytes
    struct OCR1A {
        static const uint16_t address = 0x4a;
    };

    // Timer/Counter1  Bytes
    struct TCNT1 {
        static const uint16_t address = 0x4c;
    };

    // Timer/Counter1 Control Register B
    struct TCCR1B {
        static const uint8_t address = 0x4e;
        enum bits : uint8_t {
            CS10  = 1,   // Clock Select1 bits
            CS11  = 2,   // Clock Select1 bits
            CS12  = 4,   // Clock Select1 bits
            WGM10 = 8,   // Pulse Width Modulator Select Bits
            WGM11 = 16,  // Pulse Width Modulator Select Bits
            ICES1 = 64,  // Input Capture 1 Edge Select
            ICNC1 = 128, // Input Capture 1 Noise Canceler
        };
    };

    // Timer/Counter1 Control Register A
    struct TCCR1A {
        static const uint8_t address = 0x4f;
        enum bits : uint8_t {
            WGM10  = 1,   // Pulse Width Modulator Select Bits
            WGM11  = 2,   // Pulse Width Modulator Select Bits
            FOC1B  = 4,   // Force Output Compare for Channel B
            FOC1A  = 8,   // Force Output Compare for Channel A
            COM1B0 = 16,  // Compare Output Mode 1B, bits
            COM1B1 = 32,  // Compare Output Mode 1B, bits
            COM1A0 = 64,  // Compare Output Mode 1A, bits
            COM1A1 = 128, // Compare Output Mode 1A, bits
        };
    };

    // Special Function IO Register
    struct SFIOR {
        static const uint8_t address = 0x50;
        enum bits : uint8_t {
            PSR10 = 1,  // Prescaler Reset Timer / Counter 1 and Timer / Counter 0
            PUD   = 4,  // Pull-up Disable
            XMM0  = 8,  // External Memory High Mask Bits
            XMM1  = 16, // External Memory High Mask Bits
            XMM2  = 32, // External Memory High Mask Bits
            XMBK  = 64, // External Memory Bus Keeper Enable
        };
    };

    // Timer/Counter 0 Output Compare Register
    struct OCR0 {
        static const uint8_t address = 0x51;
    };

    // Timer/Counter 0 Register
    struct TCNT0 {
        static const uint8_t address = 0x52;
    };

    // Timer/Counter 0 Control Register
    struct TCCR0 {
        static const uint8_t address = 0x53;
        enum bits : uint8_t {
            CS00  = 1,   // Clock Selects
            CS01  = 2,   // Clock Selects
            CS02  = 4,   // Clock Selects
            WGM01 = 8,   // Waveform Generation Mode 1
            COM00 = 16,  // Compare Match Output Modes
            COM01 = 32,  // Compare Match Output Modes
            WGM00 = 64,  // Waveform Generation Mode 0
            FOC0  = 128, // Force Output Compare
        };
    };

    // MCU Control And Status Register
    struct MCUCSR {
        static const uint8_t address = 0x54;
        enum bits : uint8_t {
            PORF  = 1,  // Power-on reset flag
            EXTRF = 2,  // External Reset Flag
            BORF  = 4,  // Brown-out Reset Flag
            WDRF  = 8,  // Watchdog Reset Flag
            SM2   = 32, // Sleep Mode Select Bit 2
        };
    };

    // MCU Control Register
    struct MCUCR {
        static const uint8_t address = 0x55;
        enum bits : uint8_t {
            ISC00 = 1,   // Interrupt Sense Control 0 Bits
            ISC01 = 2,   // Interrupt Sense Control 0 Bits
            ISC10 = 4,   // Interrupt Sense Control 1 Bits
            ISC11 = 8,   // Interrupt Sense Control 1 Bits
            SM1   = 16,  // Sleep Mode Select Bit 1
            SE    = 32,  // Sleep Enable
            SRW10 = 64,  // Wait State Select Bits for Upper Sector, bit 0
            SRE   = 128, // External SRAM/XMEM Enable
        };
    };

    // Extended MCU Control Register
    struct EMCUCR {
        static const uint8_t address = 0x56;
        enum bits : uint8_t {
            ISC2  = 1,   // Interrupt Sense Control 2
            SRW11 = 2,   // Wait State Select Bits for Upper Sector, bit 1
            SRW00 = 4,   // Wait State Select Bits for Lower Sector, bits
            SRW01 = 8,   // Wait State Select Bits for Lower Sector, bits
            SRL0  = 16,  // Wait State Selector Limit bits
            SRL1  = 32,  // Wait State Selector Limit bits
            SRL2  = 64,  // Wait State Selector Limit bits
            SM0   = 128, // Sleep Mode Select Bit 0
        };
    };

    // Store Program Memory Control Register
    struct SPMCR {
        static const uint8_t address = 0x57;
        enum bits : uint8_t {
            SPMEN  = 1,   // Store Program Memory Enable
            PGERS  = 2,   // Page Erase
            PGWRT  = 4,   // Page Write
            BLBSET = 8,   // Boot Lock Bit Set
            RWWSRE = 16,  // Read-While-Write Section Read Enable
            RWWSB  = 64,  // Read-While-Write Section Busy
            SPMIE  = 128, // SPM Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR {
        static const uint8_t address = 0x58;
        enum bits : uint8_t {
            OCF0  = 1,   // Output Compare Flag 0
            TOV0  = 2,   // Timer/Counter0 Overflow Flag
            ICF1  = 8,   // Input Capture Flag 1
            OCF1B = 32,  // Output Compare Flag 1B
            OCF1A = 64,  // Output Compare Flag 1A
            TOV1  = 128, // Timer/Counter1 Overflow Flag
        };
    };

    // Timer/Counter Interrupt Mask Register
    struct TIMSK {
        static const uint8_t address = 0x59;
        enum bits : uint8_t {
            OCIE0  = 1,   // Timer/Counter0 Output Compare Match Interrupt register
            TOIE0  = 2,   // Timer/Counter0 Overflow Interrupt Enable
            TICIE1 = 8,   // Timer/Counter1 Input Capture Interrupt Enable
            OCIE1B = 32,  // Timer/Counter1 Output CompareB Match Interrupt Enable
            OCIE1A = 64,  // Timer/Counter1 Output CompareA Match Interrupt Enable
            TOIE1  = 128, // Timer/Counter1 Overflow Interrupt Enable
        };
    };

    // General Interrupt Flag Register
    struct GIFR {
        static const uint8_t address = 0x5a;
        enum bits : uint8_t {
            INTF2 = 32,  // External Interrupt Flag 2
            INTF0 = 64,  // External Interrupt Flags
            INTF1 = 128, // External Interrupt Flags
        };
    };

    // General Interrupt Control Register
    struct GICR {
        static const uint8_t address = 0x5b;
        enum bits : uint8_t {
            IVCE  = 1,   // Interrupt Vector Change Enable
            IVSEL = 2,   // Interrupt Vector Select
            INT2  = 32,  // External Interrupt Request 2 Enable
            INT0  = 64,  // External Interrupt Request 0 Enable
            INT1  = 128, // External Interrupt Request 1 Enable
        };
    };

    // Status Register
    struct SREG {
        static const uint8_t address = 0x5f;
        enum bits : uint8_t {
            C = 1,   // Carry Flag
            Z = 2,   // Zero Flag
            N = 4,   // Negative Flag
            V = 8,   // Two's Complement Overflow Flag
            S = 16,  // Sign Bit
            H = 32,  // Half Carry Flag
            T = 64,  // Bit Copy Storage
            I = 128, // Global Interrupt Enable
        };
    };

}

#endif
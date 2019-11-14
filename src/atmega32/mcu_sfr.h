#ifndef mcu_sfr_h
#define mcu_sfr_h

#include <stdint.h>

namespace SFR {

    // On-Chip Debug Related Register in I/O Memory
    struct OCDR {
        static const uint8_t address = 0x51;
    };

    // MCU Control And Status Register
    struct MCUCSR {
        static const uint8_t address = 0x54;
        enum bits : uint8_t {
            JTD   = 128, // JTAG Interface Disable
            ISC2  = 64,  // Interrupt Sense Control 2
            EXTRF = 2,   // External Reset Flag
            PORF  = 1,   // Power-on reset flag
            BORF  = 4,   // Brown-out Reset Flag
            WDRF  = 8,   // Watchdog Reset Flag
            JTRF  = 16,  // JTAG Reset Flag
        };
    };

    // EEPROM Read/Write Access  Bytes
    struct EEAR {
        static const uint16_t address = 0x3e;
    };

    // EEPROM Data Register
    struct EEDR {
        static const uint8_t address = 0x3d;
    };

    // EEPROM Control Register
    struct EECR {
        static const uint8_t address = 0x3c;
        enum bits : uint8_t {
            EERIE = 8, // EEPROM Ready Interrupt Enable
            EERE  = 1, // EEPROM Read Enable
            EEWE  = 2, // EEPROM Write Enable
            EEMWE = 4, // EEPROM Master Write Enable
        };
    };

    // Watchdog Timer Control Register
    struct WDTCR {
        static const uint8_t address = 0x41;
        enum bits : uint8_t {
            WDP0  = 1,  // Watch Dog Timer Prescaler bits
            WDP1  = 2,  // Watch Dog Timer Prescaler bits
            WDP2  = 4,  // Watch Dog Timer Prescaler bits
            WDE   = 8,  // Watch Dog Enable
            WDTOE = 16, // RW
        };
    };

    // General Interrupt Control Register
    struct GICR {
        static const uint8_t address = 0x5b;
        enum bits : uint8_t {
            INT2  = 32,  // External Interrupt Request 2 Enable
            IVCE  = 1,   // Interrupt Vector Change Enable
            IVSEL = 2,   // Interrupt Vector Select
            INT0  = 64,  // External Interrupt Request 0 Enable
            INT1  = 128, // External Interrupt Request 1 Enable
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
    struct MCUCR {
        static const uint8_t address = 0x55;
        enum bits : uint8_t {
            SE    = 128, // Sleep Enable
            ISC00 = 1,   // Interrupt Sense Control 0 Bits
            ISC01 = 2,   // Interrupt Sense Control 0 Bits
            SM1   = 32,  // Sleep Mode Select
            ISC10 = 4,   // Interrupt Sense Control 1 Bits
            SM2   = 64,  // Sleep Mode Select
            ISC11 = 8,   // Interrupt Sense Control 1 Bits
            SM0   = 16,  // Sleep Mode Select
        };
    };

    // Timer/Counter Control Register
    struct TCCR0 {
        static const uint8_t address = 0x53;
        enum bits : uint8_t {
            FOC0  = 128, // Force Output Compare
            COM01 = 32,  // Compare Match Output Modes
            WGM00 = 64,  // Waveform Generation Mode
            CS01  = 2,   // Clock Select
            CS02  = 4,   // Clock Select
            CS00  = 1,   // Clock Select
            WGM01 = 8,   // Waveform Generation Mode 1
            COM00 = 16,  // Compare Match Output Modes
        };
    };

    // Timer/Counter Register
    struct TCNT0 {
        static const uint8_t address = 0x52;
    };

    // Output Compare Register
    struct OCR0 {
        static const uint8_t address = 0x5c;
    };

    // Timer/Counter Interrupt Mask Register
    struct TIMSK {
        static const uint8_t address = 0x59;
        enum bits : uint8_t {
            TICIE1 = 32,  // Timer/Counter1 Input Capture Interrupt Enable
            TOIE0  = 1,   // Timer/Counter0 Overflow Interrupt Enable
            OCIE2  = 128, // Timer/Counter2 Output Compare Match Interrupt Enable
            OCIE0  = 2,   // Timer/Counter0 Output Compare Match Interrupt register
            TOIE1  = 4,   // Timer/Counter1 Overflow Interrupt Enable
            TOIE2  = 64,  // Timer/Counter2 Overflow Interrupt Enable
            OCIE1B = 8,   // Timer/Counter1 Output CompareB Match Interrupt Enable
            OCIE1A = 16,  // Timer/Counter1 Output CompareA Match Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR {
        static const uint8_t address = 0x58;
        enum bits : uint8_t {
            ICF1  = 32,  // Input Capture Flag 1
            TOV0  = 1,   // Timer/Counter0 Overflow Flag
            OCF0  = 2,   // Output Compare Flag 0
            TOV2  = 64,  // Timer/Counter2 Overflow Flag
            TOV1  = 4,   // Timer/Counter1 Overflow Flag
            OCF2  = 128, // Output Compare Flag 2
            OCF1B = 8,   // Output Compare Flag 1B
            OCF1A = 16,  // Output Compare Flag 1A
        };
    };

    // Timer/Counter2 Control Register
    struct TCCR2 {
        static const uint8_t address = 0x45;
        enum bits : uint8_t {
            COM21 = 32,  // Compare Output Mode bits
            CS20  = 1,   // Clock Select bits
            CS21  = 2,   // Clock Select bits
            WGM20 = 64,  // Pulse Width Modulator Enable
            CS22  = 4,   // Clock Select bits
            FOC2  = 128, // Force Output Compare
            WGM21 = 8,   // Clear Timer/Counter2 on Compare Match
            COM20 = 16,  // Compare Output Mode bits
        };
    };

    // Timer/Counter2
    struct TCNT2 {
        static const uint8_t address = 0x44;
    };

    // Timer/Counter2 Output Compare Register
    struct OCR2 {
        static const uint8_t address = 0x43;
    };

    // Asynchronous Status Register
    struct ASSR {
        static const uint8_t address = 0x42;
        enum bits : uint8_t {
            AS2    = 8, // Asynchronous Timer/counter2
            TCR2UB = 1, // Timer/counter Control Register2 Update Busy
            OCR2UB = 2, // Output Compare Register2 Update Busy
            TCN2UB = 4, // Timer/Counter2 Update Busy
        };
    };

    // Timer/Counter1 Control Register A
    struct TCCR1A {
        static const uint8_t address = 0x4f;
        enum bits : uint8_t {
            COM1A0 = 64,  // Compare Output Mode 1A, bits
            COM1A1 = 128, // Compare Output Mode 1A, bits
            WGM11  = 2,   // Waveform Generation Mode
            WGM10  = 1,   // Waveform Generation Mode
            FOC1B  = 4,   // Force Output Compare 1B
            COM1B1 = 32,  // Compare Output Mode 1B, bits
            FOC1A  = 8,   // Force Output Compare 1A
            COM1B0 = 16,  // Compare Output Mode 1B, bits
        };
    };

    // Timer/Counter1 Control Register B
    struct TCCR1B {
        static const uint8_t address = 0x4e;
        enum bits : uint8_t {
            ICNC1 = 128, // Input Capture 1 Noise Canceler
            ICES1 = 64,  // Input Capture 1 Edge Select
            CS10  = 1,   // Prescaler source of Timer/Counter 1
            CS11  = 2,   // Prescaler source of Timer/Counter 1
            CS12  = 4,   // Prescaler source of Timer/Counter 1
            WGM12 = 8,   // Waveform Generation Mode
            WGM13 = 16,  // Waveform Generation Mode
        };
    };

    // Timer/Counter1  Bytes
    struct TCNT1 {
        static const uint16_t address = 0x4c;
    };

    // Timer/Counter1 Output Compare Register  Bytes
    struct OCR1A {
        static const uint16_t address = 0x4a;
    };

    // Timer/Counter1 Output Compare Register  Bytes
    struct OCR1B {
        static const uint16_t address = 0x48;
    };

    // Timer/Counter1 Input Capture Register  Bytes
    struct ICR1 {
        static const uint16_t address = 0x46;
    };

    // SPI Data Register
    struct SPDR {
        static const uint8_t address = 0x2f;
    };

    // SPI Status Register
    struct SPSR {
        static const uint8_t address = 0x2e;
        enum bits : uint8_t {
            WCOL  = 64,  // Write Collision Flag
            SPI2X = 1,   // Double SPI Speed Bit
            SPIF  = 128, // SPI Interrupt Flag
        };
    };

    // SPI Control Register
    struct SPCR {
        static const uint8_t address = 0x2d;
        enum bits : uint8_t {
            DORD = 32,  // Data Order
            SPE  = 64,  // SPI Enable
            SPIE = 128, // SPI Interrupt Enable
            SPR0 = 1,   // SPI Clock Rate Selects
            CPHA = 4,   // Clock Phase
            SPR1 = 2,   // SPI Clock Rate Selects
            CPOL = 8,   // Clock polarity
            MSTR = 16,  // Master/Slave Select
        };
    };

    // USART I/O Data Register
    struct UDR {
        static const uint8_t address = 0x2c;
    };

    // USART Control and Status Register A
    struct UCSRA {
        static const uint8_t address = 0x2b;
        enum bits : uint8_t {
            UDRE = 32,  // USART Data Register Empty
            TXC  = 64,  // USART Transmitt Complete
            U2X  = 2,   // Double the USART transmission speed
            RXC  = 128, // USART Receive Complete
            MPCM = 1,   // Multi-processor Communication Mode
            UPE  = 4,   // Parity Error
            DOR  = 8,   // Data overRun
            FE   = 16,  // Framing Error
        };
    };

    // USART Control and Status Register B
    struct UCSRB {
        static const uint8_t address = 0x2a;
        enum bits : uint8_t {
            UDRIE = 32,  // USART Data register Empty Interrupt Enable
            TXB8  = 1,   // Transmit Data Bit 8
            RXB8  = 2,   // Receive Data Bit 8
            RXCIE = 128, // RX Complete Interrupt Enable
            UCSZ2 = 4,   // Character Size
            TXCIE = 64,  // TX Complete Interrupt Enable
            TXEN  = 8,   // Transmitter Enable
            RXEN  = 16,  // Receiver Enable
        };
    };

    // USART Control and Status Register C
    struct UCSRC {
        static const uint8_t address = 0x40;
        enum bits : uint8_t {
            UPM1  = 32,  // Parity Mode Bits
            UCPOL = 1,   // Clock Polarity
            UCSZ0 = 2,   // Character Size
            URSEL = 128, // Register Select
            UCSZ1 = 4,   // Character Size
            UMSEL = 64,  // USART Mode Select
            USBS  = 8,   // Stop Bit Select
            UPM0  = 16,  // Parity Mode Bits
        };
    };

    // USART Baud Rate Register Hight Byte
    struct UBRRH {
        static const uint8_t address = 0x40;
    };

    // USART Baud Rate Register Low Byte
    struct UBRRL {
        static const uint8_t address = 0x29;
    };

    // Special Function IO Register
    struct SFIOR {
        static const uint8_t address = 0x50;
        enum bits : uint8_t {
            ADTS0 = 32,  // ADC Auto Trigger Source
            PSR10 = 1,   // Prescaler Reset Timer/Counter1 and Timer/Counter0
            PSR2  = 2,   // Prescaler Reset Timer/Counter2
            ADTS1 = 64,  // ADC Auto Trigger Source
            PUD   = 4,   // Pull-up disable
            ADTS2 = 128, // ADC Auto Trigger Source
            ACME  = 8,   // Analog Comparator Multiplexer Enable
        };
    };

    // Analog Comparator Control And Status Register
    struct ACSR {
        static const uint8_t address = 0x28;
        enum bits : uint8_t {
            ACD   = 128, // Analog Comparator Disable
            ACIS0 = 1,   // Analog Comparator Interrupt Mode Select bits
            ACIS1 = 2,   // Analog Comparator Interrupt Mode Select bits
            ACBG  = 64,  // Analog Comparator Bandgap Select
            ACO   = 32,  // Analog Compare Output
            ACIC  = 4,   // Analog Comparator Input Capture Enable
            ACIE  = 8,   // Analog Comparator Interrupt Enable
            ACI   = 16,  // Analog Comparator Interrupt Flag
        };
    };

    // The ADC multiplexer Selection Register
    struct ADMUX {
        static const uint8_t address = 0x27;
        enum bits : uint8_t {
            ADLAR = 32,  // Left Adjust Result
            MUX0  = 1,   // Analog Channel and Gain Selection Bits
            MUX1  = 2,   // Analog Channel and Gain Selection Bits
            REFS0 = 64,  // Reference Selection Bits
            REFS1 = 128, // Reference Selection Bits
            MUX2  = 4,   // Analog Channel and Gain Selection Bits
            MUX3  = 8,   // Analog Channel and Gain Selection Bits
            MUX4  = 16,  // Analog Channel and Gain Selection Bits
        };
    };

    // The ADC Control and Status register
    struct ADCSRA {
        static const uint8_t address = 0x26;
        enum bits : uint8_t {
            ADEN  = 128, // ADC Enable
            ADPS0 = 1,   // ADC Prescaler Select Bits
            ADPS1 = 2,   // ADC Prescaler Select Bits
            ADSC  = 64,  // ADC Start Conversion
            ADPS2 = 4,   // ADC Prescaler Select Bits
            ADATE = 32,  // ADC Auto Trigger
            ADIE  = 8,   // ADC Interrupt Enable
            ADIF  = 16,  // ADC Interrupt Flag
        };
    };

    // ADC Data Register  Bytes
    struct ADC {
        static const uint16_t address = 0x24;
    };

    // Port A Data Register
    struct PORTA {
        static const uint8_t address = 0x3b;
    };

    // Port A Data Direction Register
    struct DDRA {
        static const uint8_t address = 0x3a;
    };

    // Port A Input Pins
    struct PINA {
        static const uint8_t address = 0x39;
    };

    // Port B Data Register
    struct PORTB {
        static const uint8_t address = 0x38;
    };

    // Port B Data Direction Register
    struct DDRB {
        static const uint8_t address = 0x37;
    };

    // Port B Input Pins
    struct PINB {
        static const uint8_t address = 0x36;
    };

    // Port C Data Register
    struct PORTC {
        static const uint8_t address = 0x35;
    };

    // Port C Data Direction Register
    struct DDRC {
        static const uint8_t address = 0x34;
    };

    // Port C Input Pins
    struct PINC {
        static const uint8_t address = 0x33;
    };

    // Port D Data Register
    struct PORTD {
        static const uint8_t address = 0x32;
    };

    // Port D Data Direction Register
    struct DDRD {
        static const uint8_t address = 0x31;
    };

    // Port D Input Pins
    struct PIND {
        static const uint8_t address = 0x30;
    };

    // Status Register
    struct SREG {
        static const uint8_t address = 0x5f;
        enum bits : uint8_t {
            H = 32,  // Half Carry Flag
            I = 128, // Global Interrupt Enable
            Z = 2,   // Zero Flag
            T = 64,  // Bit Copy Storage
            N = 4,   // Negative Flag
            C = 1,   // Carry Flag
            V = 8,   // Two's Complement Overflow Flag
            S = 16,  // Sign Bit
        };
    };

    // Stack Pointer
    struct SP {
        static const uint16_t address = 0x5d;
    };

    // Oscillator Calibration Value
    struct OSCCAL {
        static const uint8_t address = 0x51;
        enum bits : uint8_t {
            OSCCAL5 = 32,  // Oscillator Calibration
            OSCCAL0 = 1,   // Oscillator Calibration
            OSCCAL1 = 2,   // Oscillator Calibration
            OSCCAL6 = 64,  // Oscillator Calibration
            OSCCAL2 = 4,   // Oscillator Calibration
            OSCCAL7 = 128, // Oscillator Calibration
            OSCCAL3 = 8,   // Oscillator Calibration
            OSCCAL4 = 16,  // Oscillator Calibration
        };
    };

    // Store Program Memory Control Register
    struct SPMCR {
        static const uint8_t address = 0x57;
        enum bits : uint8_t {
            RWWSB  = 64,  // Read While Write Section Busy
            SPMIE  = 128, // SPM Interrupt Enable
            PGERS  = 2,   // Page Erase
            SPMEN  = 1,   // Store Program Memory Enable
            PGWRT  = 4,   // Page Write
            BLBSET = 8,   // Boot Lock Bit Set
            RWWSRE = 16,  // Read While Write secion read enable
        };
    };

    // TWI Bit Rate register
    struct TWBR {
        static const uint8_t address = 0x20;
    };

    // TWI Control Register
    struct TWCR {
        static const uint8_t address = 0x56;
        enum bits : uint8_t {
            TWINT = 128, // TWI Interrupt Flag
            TWIE  = 1,   // TWI Interrupt Enable
            TWEA  = 64,  // TWI Enable Acknowledge Bit
            TWSTA = 32,  // TWI Start Condition Bit
            TWEN  = 4,   // TWI Enable Bit
            TWWC  = 8,   // TWI Write Collition Flag
            TWSTO = 16,  // TWI Stop Condition Bit
        };
    };

    // TWI Status Register
    struct TWSR {
        static const uint8_t address = 0x21;
        enum bits : uint8_t {
            TWS2  = 32,  // TWI Status
            TWS3  = 64,  // TWI Status
            TWS4  = 128, // TWI Status
            TWPS0 = 1,   // TWI Prescaler bits
            TWPS1 = 2,   // TWI Prescaler bits
            TWS0  = 8,   // TWI Status
            TWS1  = 16,  // TWI Status
        };
    };

    // TWI Data register
    struct TWDR {
        static const uint8_t address = 0x23;
    };

    // TWI (Slave) Address register
    struct TWAR {
        static const uint8_t address = 0x22;
        enum bits : uint8_t {
            TWA4  = 32,  // TWI address bits
            TWA5  = 64,  // TWI address bits
            TWA0  = 2,   // TWI address bits
            TWA6  = 128, // TWI address bits
            TWA1  = 4,   // TWI address bits
            TWGCE = 1,   // TWI general call recognition enable bit
            TWA2  = 8,   // TWI address bits
            TWA3  = 16,  // TWI address bits
        };
    };

}

#endif

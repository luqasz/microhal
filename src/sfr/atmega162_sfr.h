#ifndef atmega162_sfr_h
#define atmega162_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega162
*/

namespace SFR {

    // USART Baud Rate Register Low Byte
    struct UBRR1L {
        static const uint8_t address = 0x20;
        enum bits : uint8_t {
            UBRR10 = 1,   // USART Baud Rate Register Low bits
            UBRR11 = 2,   // USART Baud Rate Register Low bits
            UBRR12 = 4,   // USART Baud Rate Register Low bits
            UBRR13 = 8,   // USART Baud Rate Register Low bits
            UBRR14 = 16,  // USART Baud Rate Register Low bits
            UBRR15 = 32,  // USART Baud Rate Register Low bits
            UBRR16 = 64,  // USART Baud Rate Register Low bits
            UBRR17 = 128, // USART Baud Rate Register Low bits
        };
    };

    // USART Control and Status Register B
    struct UCSR1B {
        static const uint8_t address = 0x21;
        enum bits : uint8_t {
            TXB81  = 1,   // Transmit Data Bit 8
            RXB81  = 2,   // Receive Data Bit 8
            UCSZ12 = 4,   // Character Size
            TXEN1  = 8,   // Transmitter Enable
            RXEN1  = 16,  // Receiver Enable
            UDRIE1 = 32,  // USART Data register Empty Interrupt Enable
            TXCIE1 = 64,  // TX Complete Interrupt Enable
            RXCIE1 = 128, // RX Complete Interrupt Enable
        };
    };

    // USART Control and Status Register A
    struct UCSR1A {
        static const uint8_t address = 0x22;
        enum bits : uint8_t {
            MPCM1 = 1,   // Multi-processor Communication Mode
            U2X1  = 2,   // Double the USART transmission speed
            UPE1  = 4,   // Parity Error
            DOR1  = 8,   // Data overRun
            FE1   = 16,  // Framing Error
            UDRE1 = 32,  // USART Data Register Empty
            TXC1  = 64,  // USART Transmitt Complete
            RXC1  = 128, // USART Receive Complete
        };
    };

    // USART I/O Data Register
    struct UDR1 {
        static const uint8_t address = 0x23;
    };

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

    // On-Chip Debug Related Register in I/O Memory
    struct OCDR {
        static const uint8_t address = 0x24;
        enum bits : uint8_t {
            OCDR0 = 1,   // On-Chip Debug Register Bits
            OCDR1 = 2,   // On-Chip Debug Register Bits
            OCDR2 = 4,   // On-Chip Debug Register Bits
            OCDR3 = 8,   // On-Chip Debug Register Bits
            OCDR4 = 16,  // On-Chip Debug Register Bits
            OCDR5 = 32,  // On-Chip Debug Register Bits
            OCDR6 = 64,  // On-Chip Debug Register Bits
            OCDR7 = 128, // On-Chip Debug Register Bits
        };
    };

    // Input Pins, Port E
    struct PINE {
        static const uint8_t address = 0x25;
    };

    // Data Direction Register, Port E
    struct DDRE {
        static const uint8_t address = 0x26;
    };

    // Data Register, Port E
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
    struct UBRR0L {
        static const uint8_t address = 0x29;
        enum bits : uint8_t {
            UBRR00 = 1,   // USART Baud Rate Register Low bits
            UBRR01 = 2,   // USART Baud Rate Register Low bits
            UBRR02 = 4,   // USART Baud Rate Register Low bits
            UBRR03 = 8,   // USART Baud Rate Register Low bits
            UBRR04 = 16,  // USART Baud Rate Register Low bits
            UBRR05 = 32,  // USART Baud Rate Register Low bits
            UBRR06 = 64,  // USART Baud Rate Register Low bits
            UBRR07 = 128, // USART Baud Rate Register Low bits
        };
    };

    // USART Control and Status Register B
    struct UCSR0B {
        static const uint8_t address = 0x2a;
        enum bits : uint8_t {
            TXB80  = 1,   // Transmit Data Bit 8
            RXB80  = 2,   // Receive Data Bit 8
            UCSZ02 = 4,   // Character Size
            TXEN0  = 8,   // Transmitter Enable
            RXEN0  = 16,  // Receiver Enable
            UDRIE0 = 32,  // USART Data register Empty Interrupt Enable
            TXCIE0 = 64,  // TX Complete Interrupt Enable
            RXCIE0 = 128, // RX Complete Interrupt Enable
        };
    };

    // USART Control and Status Register A
    struct UCSR0A {
        static const uint8_t address = 0x2b;
        enum bits : uint8_t {
            MPCM0 = 1,   // Multi-processor Communication Mode
            U2X0  = 2,   // Double the USART transmission speed
            UPE0  = 4,   // Parity Error
            DOR0  = 8,   // Data overRun
            FE0   = 16,  // Framing Error
            UDRE0 = 32,  // USART Data Register Empty
            TXC0  = 64,  // USART Transmitt Complete
            RXC0  = 128, // USART Receive Complete
        };
    };

    // USART I/O Data Register
    struct UDR0 {
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
        enum bits : uint8_t {
            EEDR0 = 1,   // EEPROM Data Register bits
            EEDR1 = 2,   // EEPROM Data Register bits
            EEDR2 = 4,   // EEPROM Data Register bits
            EEDR3 = 8,   // EEPROM Data Register bits
            EEDR4 = 16,  // EEPROM Data Register bits
            EEDR5 = 32,  // EEPROM Data Register bits
            EEDR6 = 64,  // EEPROM Data Register bits
            EEDR7 = 128, // EEPROM Data Register bits
        };
    };

    // EEPROM Address Register Bytes
    struct EEAR {
        static const uint16_t address = 0x3e;
        enum bits : uint8_t {
            EEAR0 = 1,   // EEPROM Address Register bits
            EEAR1 = 2,   // EEPROM Address Register bits
            EEAR2 = 4,   // EEPROM Address Register bits
            EEAR3 = 8,   // EEPROM Address Register bits
            EEAR4 = 16,  // EEPROM Address Register bits
            EEAR5 = 32,  // EEPROM Address Register bits
            EEAR6 = 64,  // EEPROM Address Register bits
            EEAR7 = 128, // EEPROM Address Register bits
        };
    };

    // USART Control and Status Register C
    struct UCSR0C {
        static const uint8_t address = 0x40;
        enum bits : uint8_t {
            UCPOL0 = 1,   // Clock Polarity
            UCSZ00 = 2,   // Character Size
            UCSZ01 = 4,   // Character Size
            USBS0  = 8,   // Stop Bit Select
            UPM00  = 16,  // Parity Mode Bits
            UPM01  = 32,  // Parity Mode Bits
            UMSEL0 = 64,  // USART Mode Select
            URSEL0 = 128, // Register Select
        };
    };

    // USART Baud Rate Register High Byte
    struct UBRR0H {
        static const uint8_t address = 0x40;
        enum bits : uint8_t {
            UBRR00 = 1,   // USART Baud Rate Register High bits
            UBRR01 = 2,   // USART Baud Rate Register High bits
            UBRR02 = 4,   // USART Baud Rate Register High bits
            UBRR03 = 8,   // USART Baud Rate Register High bits
            URSEL0 = 128, // Register Select
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

    // Output Compare Register
    struct OCR2 {
        static const uint8_t address = 0x42;
    };

    // Timer/Counter Register
    struct TCNT2 {
        static const uint8_t address = 0x43;
    };

    // Timer/Counter1 Input Capture Register  Bytes
    struct ICR1 {
        static const uint16_t address = 0x44;
    };

    // Asynchronous Status Register
    struct ASSR {
        static const uint8_t address = 0x46;
        enum bits : uint8_t {
            TCR2UB = 1, // Timer/Counter Control Register2 Update Busy
            OCR2UB = 2, // Output Compare Register2 Update Busy
            TCN2UB = 4, // Timer/Counter2 Update Busy
            AS2    = 8, // Asynchronous Timer 2
        };
    };

    // Timer/Counter Control Register
    struct TCCR2 {
        static const uint8_t address = 0x47;
        enum bits : uint8_t {
            CS20  = 1,   // Clock Select
            CS21  = 2,   // Clock Select
            CS22  = 4,   // Clock Select
            WGM21 = 8,   // Pulse Width Modulator Select Bit 1
            COM20 = 16,  // Compare Match Output Mode
            COM21 = 32,  // Compare Match Output Mode
            WGM20 = 64,  // Pulse Width Modulator Select Bit 0
            FOC2  = 128, // Forde Output Compare
        };
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
            PSR310 = 1,   // Prescaler Reset Timer/Counter3, Timer/Counter1 and Timer/Counter0
            PSR2   = 2,   // Prescaler Reset Timer/Counter2
            PUD    = 4,   // Pull-up Disable
            XMM0   = 8,   // External Memory High Mask Bits
            XMM1   = 16,  // External Memory High Mask Bits
            XMM2   = 32,  // External Memory High Mask Bits
            XMBK   = 64,  // External Memory Bus Keeper Enable
            TSM    = 128, // Timer/Counter Synchronization Mode
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
            PORF  = 1,   // Power-on reset flag
            EXTRF = 2,   // External Reset Flag
            BORF  = 4,   // Brown-out Reset Flag
            WDRF  = 8,   // Watchdog Reset Flag
            JTRF  = 16,  // JTAG Reset Flag
            SM2   = 32,  // Sleep Mode Select Bit 2
            JTD   = 128, // JTAG Interface Disable
        };
    };

    // MCU Control Register
    struct MCUCR {
        static const uint8_t address = 0x55;
        enum bits : uint8_t {
            ISC00 = 1,   // Interrupt Sense Control 0 bits
            ISC01 = 2,   // Interrupt Sense Control 0 bits
            ISC10 = 4,   // Interrupt Sense Control 1 bits
            ISC11 = 8,   // Interrupt Sense Control 1 bits
            SM1   = 16,  // Sleep Mode Select
            SE    = 32,  // Sleep Enable
            SRW10 = 64,  // External SRAM Wait State Select
            SRE   = 128, // External SRAM Enable
        };
    };

    // Extended MCU Control Register
    struct EMCUCR {
        static const uint8_t address = 0x56;
        enum bits : uint8_t {
            ISC2  = 1,   // Interrupt Sense Control 2
            SRW11 = 2,   // Wait State Select Bit 1 for Upper Sector
            SRW00 = 4,   // Wait State Select Bit 1 for Lower Sector
            SRW01 = 8,   // Wait State Select Bit 1 for Lower Sector
            SRL0  = 16,  // Wait State Sector Limit Bits
            SRL1  = 32,  // Wait State Sector Limit Bits
            SRL2  = 64,  // Wait State Sector Limit Bits
            SM0   = 128, // Sleep mode Select Bit 0
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
            RWWSRE = 16,  // Read While Write secion read enable
            RWWSB  = 64,  // Read While Write Section Busy
            SPMIE  = 128, // SPM Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR {
        static const uint8_t address = 0x58;
        enum bits : uint8_t {
            OCF0  = 1,   // Output Compare Flag 0
            TOV0  = 2,   // Timer/Counter0 Overflow Flag
            TOV2  = 4,   // Timer/Counter2 Overflow Flag
            ICF1  = 8,   // Input Capture Flag 1
            OCF2  = 16,  // Output Compare Flag 2
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
            TOIE2  = 4,   // Timer/Counter2 Overflow Interrupt Enable
            TICIE1 = 8,   // Timer/Counter1 Input Capture Interrupt Enable
            OCIE2  = 16,  // Timer/Counter2 Output Compare Match Interrupt Enable
            OCIE1B = 32,  // Timer/Counter1 Output CompareB Match Interrupt Enable
            OCIE1A = 64,  // Timer/Counter1 Output CompareA Match Interrupt Enable
            TOIE1  = 128, // Timer/Counter1 Overflow Interrupt Enable
        };
    };

    // General Interrupt Flag Register
    struct GIFR {
        static const uint8_t address = 0x5a;
        enum bits : uint8_t {
            PCIF0 = 8,   // Pin Change Interrupt Flags
            PCIF1 = 16,  // Pin Change Interrupt Flags
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
            PCIE0 = 8,   // Pin Change Interrupt Enables
            PCIE1 = 16,  // Pin Change Interrupt Enables
            INT2  = 32,  // External Interrupt Request 2 Enable
            INT0  = 64,  // External Interrupt Request 0 Enable
            INT1  = 128, // External Interrupt Request 1 Enable
        };
    };

    // USART Control and Status Register C
    struct UCSR1C {
        static const uint8_t address = 0x5c;
        enum bits : uint8_t {
            UCPOL1 = 1,   // Clock Polarity
            UCSZ10 = 2,   // Character Size
            UCSZ11 = 4,   // Character Size
            USBS1  = 8,   // Stop Bit Select
            UPM10  = 16,  // Parity Mode Bits
            UPM11  = 32,  // Parity Mode Bits
            UMSEL1 = 64,  // USART Mode Select
            URSEL1 = 128, // Register Select
        };
    };

    // USART Baud Rate Register Highg Byte
    struct UBRR1H {
        static const uint8_t address = 0x5c;
        enum bits : uint8_t {
            UBRR10 = 1,   // USART Baud Rate Register High bits
            UBRR11 = 2,   // USART Baud Rate Register High bits
            UBRR12 = 4,   // USART Baud Rate Register High bits
            UBRR13 = 8,   // USART Baud Rate Register High bits
            URSEL0 = 128, // Register Select
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

    // Clock prescale register
    struct CLKPR {
        static const uint8_t address = 0x61;
        enum bits : uint8_t {
            CLKPS0 = 1,   // Clock Prescaler Select Bits
            CLKPS1 = 2,   // Clock Prescaler Select Bits
            CLKPS2 = 4,   // Clock Prescaler Select Bits
            CLKPS3 = 8,   // Clock Prescaler Select Bits
            CLKPCE = 128, // Clock Prescaler Change Enable
        };
    };

    // Pin Change Enable Mask
    struct PCMSK0 {
        static const uint8_t address = 0x6b;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Interrupt mask bits
            PCINT1 = 2,   // Pin Change Interrupt mask bits
            PCINT2 = 4,   // Pin Change Interrupt mask bits
            PCINT3 = 8,   // Pin Change Interrupt mask bits
            PCINT4 = 16,  // Pin Change Interrupt mask bits
            PCINT5 = 32,  // Pin Change Interrupt mask bits
            PCINT6 = 64,  // Pin Change Interrupt mask bits
            PCINT7 = 128, // Pin Change Interrupt mask bits
        };
    };

    // Pin Change Mask Register 1
    struct PCMSK1 {
        static const uint8_t address = 0x6c;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Interrupt mask bits
            PCINT1 = 2,   // Pin Change Interrupt mask bits
            PCINT2 = 4,   // Pin Change Interrupt mask bits
            PCINT3 = 8,   // Pin Change Interrupt mask bits
            PCINT4 = 16,  // Pin Change Interrupt mask bits
            PCINT5 = 32,  // Pin Change Interrupt mask bits
            PCINT6 = 64,  // Pin Change Interrupt mask bits
            PCINT7 = 128, // Pin Change Interrupt mask bits
        };
    };

    // Extended Timer/Counter Interrupt Flag register
    struct ETIFR {
        static const uint8_t address = 0x7c;
        enum bits : uint8_t {
            TOV3  = 4,  // Timer/Counter3 Overflow Flag
            OCF3B = 8,  // Output Compare Flag 3B
            OCF3A = 16, // Output Compare Flag 3A
            ICF3  = 32, // Input Capture Flag 3
        };
    };

    // Extended Timer/Counter Interrupt Mask Register
    struct ETIMSK {
        static const uint8_t address = 0x7d;
        enum bits : uint8_t {
            TOIE3  = 4,  // Timer/Counter3 Overflow Interrupt Enable
            OCIE3B = 8,  // Timer/Counter3 Output CompareB Match Interrupt Enable
            OCIE3A = 16, // Timer/Counter3 Output CompareA Match Interrupt Enable
            TICIE3 = 32, // Timer/Counter3 Input Capture Interrupt Enable
        };
    };

    // Timer/Counter3 Input Capture Register  Bytes
    struct ICR3 {
        static const uint16_t address = 0x80;
    };

    // Timer/Counte3 Output Compare Register B  Bytes
    struct OCR3B {
        static const uint16_t address = 0x84;
    };

    // Timer/Counter3 Output Compare Register A  Bytes
    struct OCR3A {
        static const uint16_t address = 0x86;
    };

    // Timer/Counter3  Bytes
    struct TCNT3 {
        static const uint16_t address = 0x88;
    };

    // Timer/Counter3 Control Register B
    struct TCCR3B {
        static const uint8_t address = 0x8a;
        enum bits : uint8_t {
            CS30  = 1,   // Clock Select3 bits
            CS31  = 2,   // Clock Select3 bits
            CS32  = 4,   // Clock Select3 bits
            WGM30 = 8,   // Pulse Width Modulator Select Bits
            WGM31 = 16,  // Pulse Width Modulator Select Bits
            ICES3 = 64,  // Input Capture 3 Edge Select
            ICNC3 = 128, // Input Capture 3 Noise Canceler
        };
    };

    // Timer/Counter3 Control Register A
    struct TCCR3A {
        static const uint8_t address = 0x8b;
        enum bits : uint8_t {
            WGM30  = 1,   // Pulse Width Modulator Select Bits
            WGM31  = 2,   // Pulse Width Modulator Select Bits
            FOC3B  = 4,   // Force Output Compare for Channel B
            FOC3A  = 8,   // Force Output Compare for Channel A
            COM3B0 = 16,  // Compare Output Mode 3B, bits
            COM3B1 = 32,  // Compare Output Mode 3B, bits
            COM3A0 = 64,  // Compare Output Mode 3A, bits
            COM3A1 = 128, // Compare Output Mode 3A, bits
        };
    };

}

#endif
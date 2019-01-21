#ifndef atmega64a_sfr_h
#define atmega64a_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega64A
*/

namespace SFR {

    // Input Pins, Port F
    struct PINF {
        static const uint8_t address = 0x20;
    };

    // Input Pins, Port E
    struct PINE {
        static const uint8_t address = 0x21;
    };

    // Data Direction Register, Port E
    struct DDRE {
        static const uint8_t address = 0x22;
    };

    // Data Register, Port E
    struct PORTE {
        static const uint8_t address = 0x23;
    };

    // ADC Data Register  Bytes
    struct ADC {
        static const uint16_t address = 0x24;
    };

    // The ADC Control and Status register A
    struct ADCSRA {
        static const uint8_t address = 0x26;
        enum bits : uint8_t {
            ADPS0 = 1,   // ADC  Prescaler Select Bits
            ADPS1 = 2,   // ADC  Prescaler Select Bits
            ADPS2 = 4,   // ADC  Prescaler Select Bits
            ADIE  = 8,   // ADC Interrupt Enable
            ADIF  = 16,  // ADC Interrupt Flag
            ADATE = 32,  // ADC  Auto Trigger Enable
            ADSC  = 64,  // ADC Start Conversion
            ADEN  = 128, // ADC Enable
        };
    };

    // The ADC multiplexer Selection Register
    struct ADMUX {
        static const uint8_t address = 0x27;
        enum bits : uint8_t {
            MUX0  = 1,   // Analog Channel and Gain Selection Bits
            MUX1  = 2,   // Analog Channel and Gain Selection Bits
            MUX2  = 4,   // Analog Channel and Gain Selection Bits
            MUX3  = 8,   // Analog Channel and Gain Selection Bits
            MUX4  = 16,  // Analog Channel and Gain Selection Bits
            ADLAR = 32,  // Left Adjust Result
            REFS0 = 64,  // Reference Selection Bits
            REFS1 = 128, // Reference Selection Bits
        };
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
    };

    // EEPROM Read/Write Access  Bytes
    struct EEAR {
        static const uint16_t address = 0x3e;
    };

    // Special Function IO Register
    struct SFIOR {
        static const uint8_t address = 0x40;
        enum bits : uint8_t {
            PSR321 = 1,   // Prescaler Reset Timer/Counter3, Timer/Counter2, and Timer/Counter1
            PSR0   = 2,   // Prescaler Reset Timer/Counter0
            PUD    = 4,   // Pull Up Disable
            ACME   = 8,   // Analog Comparator Multiplexer Enable
            TSM    = 128, // Timer/Counter Synchronization Mode
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

    // On-Chip Debug Related Register in I/O Memory
    struct OCDR {
        static const uint8_t address = 0x42;
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

    // Output Compare Register
    struct OCR2 {
        static const uint8_t address = 0x43;
    };

    // Timer/Counter Register
    struct TCNT2 {
        static const uint8_t address = 0x44;
    };

    // Timer/Counter Control Register
    struct TCCR2 {
        static const uint8_t address = 0x45;
        enum bits : uint8_t {
            CS20  = 1,   // Clock Select
            CS21  = 2,   // Clock Select
            CS22  = 4,   // Clock Select
            WGM21 = 8,   // Waveform Generation Mode
            COM20 = 16,  // Compare Match Output Mode
            COM21 = 32,  // Compare Match Output Mode
            WGM20 = 64,  // Wafeform Generation Mode
            FOC2  = 128, // Force Output Compare
        };
    };

    // Timer/Counter1 Input Capture Register  Bytes
    struct ICR1 {
        static const uint16_t address = 0x46;
    };

    // Timer/Counter1 Output Compare Register  Bytes
    struct OCR1B {
        static const uint16_t address = 0x48;
    };

    // Timer/Counter1 Output Compare Register  Bytes
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
            WGM10 = 8,   // Waveform Generation Mode
            WGM11 = 16,  // Waveform Generation Mode
            ICES1 = 64,  // Input Capture 1 Edge Select
            ICNC1 = 128, // Input Capture 1 Noise Canceler
        };
    };

    // Timer/Counter1 Control Register A
    struct TCCR1A {
        static const uint8_t address = 0x4f;
        enum bits : uint8_t {
            WGM10  = 1,   // Waveform Generation Mode Bits
            WGM11  = 2,   // Waveform Generation Mode Bits
            COM1C0 = 4,   // Compare Output Mode 1C, bits
            COM1C1 = 8,   // Compare Output Mode 1C, bits
            COM1B0 = 16,  // Compare Output Mode 1B, bits
            COM1B1 = 32,  // Compare Output Mode 1B, bits
            COM1A0 = 64,  // Compare Output Mode 1A, bits
            COM1A1 = 128, // Compare Output Mode 1A, bits
        };
    };

    // Asynchronus Status Register
    struct ASSR {
        static const uint8_t address = 0x50;
        enum bits : uint8_t {
            TCR0UB = 1, // Timer/Counter Control Register 0 Update Busy
            OCR0UB = 2, // Output Compare register 0 Busy
            TCN0UB = 4, // Timer/Counter0 Update Busy
            AS0    = 8, // Asynchronus Timer/Counter 0
        };
    };

    // Output Compare Register
    struct OCR0 {
        static const uint8_t address = 0x51;
    };

    // Timer/Counter Register
    struct TCNT0 {
        static const uint8_t address = 0x52;
    };

    // Timer/Counter Control Register
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
            JTD   = 128, // JTAG Interface Disable
        };
    };

    // MCU Control Register
    struct MCUCR {
        static const uint8_t address = 0x55;
        enum bits : uint8_t {
            IVCE  = 1,   // Interrupt Vector Change Enable
            IVSEL = 2,   // Interrupt Vector Select
            SM2   = 4,   // Sleep Mode Select
            SM0   = 8,   // Sleep Mode Select
            SM1   = 16,  // Sleep Mode Select
            SE    = 32,  // Sleep Enable
            SRW10 = 64,  // External SRAM Wait State Select
            SRE   = 128, // External SRAM Enable
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR {
        static const uint8_t address = 0x56;
        enum bits : uint8_t {
            TOV0  = 1,   // Timer/Counter0 Overflow Flag
            OCF0  = 2,   // Output Compare Flag 0
            TOV1  = 4,   // Timer/Counter1 Overflow Flag
            OCF1B = 8,   // Output Compare Flag 1B
            OCF1A = 16,  // Output Compare Flag 1A
            ICF1  = 32,  // Input Capture Flag 1
            TOV2  = 64,  // Timer/Counter2 Overflow Flag
            OCF2  = 128, // Output Compare Flag 2
        };
    };

    // Timer/Counter Interrupt Mask Register
    struct TIMSK {
        static const uint8_t address = 0x57;
        enum bits : uint8_t {
            TOIE0  = 1,   // Timer/Counter0 Overflow Interrupt Enable
            OCIE0  = 2,   // Timer/Counter0 Output Compare Match Interrupt register
            TOIE1  = 4,   // Timer/Counter1 Overflow Interrupt Enable
            OCIE1B = 8,   // Timer/Counter1 Output CompareB Match Interrupt Enable
            OCIE1A = 16,  // Timer/Counter1 Output CompareA Match Interrupt Enable
            TICIE1 = 32,  // Timer/Counter1 Input Capture Interrupt Enable
            TOIE2  = 64,  //
            OCIE2  = 128, //
        };
    };

    // External Interrupt Flag Register
    struct EIFR {
        static const uint8_t address = 0x58;
        enum bits : uint8_t {
            INTF0 = 1,   // External Interrupt Flags
            INTF1 = 2,   // External Interrupt Flags
            INTF2 = 4,   // External Interrupt Flags
            INTF3 = 8,   // External Interrupt Flags
            INTF4 = 16,  // External Interrupt Flags
            INTF5 = 32,  // External Interrupt Flags
            INTF6 = 64,  // External Interrupt Flags
            INTF7 = 128, // External Interrupt Flags
        };
    };

    // External Interrupt Mask Register
    struct EIMSK {
        static const uint8_t address = 0x59;
        enum bits : uint8_t {
            INT0 = 1,   // External Interrupt Request 7 Enable
            INT1 = 2,   // External Interrupt Request 7 Enable
            INT2 = 4,   // External Interrupt Request 7 Enable
            INT3 = 8,   // External Interrupt Request 7 Enable
            INT4 = 16,  // External Interrupt Request 7 Enable
            INT5 = 32,  // External Interrupt Request 7 Enable
            INT6 = 64,  // External Interrupt Request 7 Enable
            INT7 = 128, // External Interrupt Request 7 Enable
        };
    };

    // External Interrupt Control Register B
    struct EICRB {
        static const uint8_t address = 0x5a;
        enum bits : uint8_t {
            ISC40 = 1,   // External Interrupt 7-4 Sense Control Bit
            ISC41 = 2,   // External Interrupt 7-4 Sense Control Bit
            ISC50 = 4,   // External Interrupt 7-4 Sense Control Bit
            ISC51 = 8,   // External Interrupt 7-4 Sense Control Bit
            ISC60 = 16,  // External Interrupt 7-4 Sense Control Bit
            ISC61 = 32,  // External Interrupt 7-4 Sense Control Bit
            ISC70 = 64,  // External Interrupt 7-4 Sense Control Bit
            ISC71 = 128, // External Interrupt 7-4 Sense Control Bit
        };
    };

    // XTAL Divide Control Register
    struct XDIV {
        static const uint8_t address = 0x5c;
        enum bits : uint8_t {
            XDIV0  = 1,   // XTAl Divide Select Bits
            XDIV1  = 2,   // XTAl Divide Select Bits
            XDIV2  = 4,   // XTAl Divide Select Bits
            XDIV3  = 8,   // XTAl Divide Select Bits
            XDIV4  = 16,  // XTAl Divide Select Bits
            XDIV5  = 32,  // XTAl Divide Select Bits
            XDIV6  = 64,  // XTAl Divide Select Bits
            XDIVEN = 128, // XTAL Divide Enable
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

    // Data Direction Register, Port F
    struct DDRF {
        static const uint8_t address = 0x61;
    };

    // Data Register, Port F
    struct PORTF {
        static const uint8_t address = 0x62;
    };

    // Input Pins, Port G
    struct PING {
        static const uint8_t address = 0x63;
    };

    // Data Direction Register, Port G
    struct DDRG {
        static const uint8_t address = 0x64;
    };

    // Data Register, Port G
    struct PORTG {
        static const uint8_t address = 0x65;
    };

    // Store Program Memory Control Register
    struct SPMCSR {
        static const uint8_t address = 0x68;
        enum bits : uint8_t {
            SPMEN  = 1,   // Store Program Memory Enable
            PGERS  = 2,   // Page Erase
            PGWRT  = 4,   // Page Write
            BLBSET = 8,   // Boot Lock Bit Set
            RWWSRE = 16,  // Read While Write section read enable
            RWWSB  = 64,  // Read While Write Section Busy
            SPMIE  = 128, // SPM Interrupt Enable
        };
    };

    // External Interrupt Control Register A
    struct EICRA {
        static const uint8_t address = 0x6a;
        enum bits : uint8_t {
            ISC00 = 1,   // External Interrupt Sense Control Bit
            ISC01 = 2,   // External Interrupt Sense Control Bit
            ISC10 = 4,   // External Interrupt Sense Control Bit
            ISC11 = 8,   // External Interrupt Sense Control Bit
            ISC20 = 16,  // External Interrupt Sense Control Bit
            ISC21 = 32,  // External Interrupt Sense Control Bit
            ISC30 = 64,  // External Interrupt Sense Control Bit
            ISC31 = 128, // External Interrupt Sense Control Bit
        };
    };

    // External Memory Control Register B
    struct XMCRB {
        static const uint8_t address = 0x6c;
        enum bits : uint8_t {
            XMM0 = 1,   // External Memory High Mask
            XMM1 = 2,   // External Memory High Mask
            XMM2 = 4,   // External Memory High Mask
            XMBK = 128, // External Memory Bus Keeper Enable
        };
    };

    // External Memory Control Register A
    struct XMCRA {
        static const uint8_t address = 0x6d;
        enum bits : uint8_t {
            SRW11 = 2,  // Wait state select bit upper page
            SRW00 = 4,  // Wait state select bit lower page
            SRW01 = 8,  // Wait state select bit lower page
            SRL0  = 16, // Wait state page limit
            SRL1  = 32, // Wait state page limit
            SRL2  = 64, // Wait state page limit
        };
    };

    // Oscillator Calibration Value
    struct OSCCAL {
        static const uint8_t address = 0x6f;
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

    // TWI Bit Rate register
    struct TWBR {
        static const uint8_t address = 0x70;
    };

    // TWI Status Register
    struct TWSR {
        static const uint8_t address = 0x71;
        enum bits : uint8_t {
            TWPS0 = 1,   // TWI Prescaler
            TWPS1 = 2,   // TWI Prescaler
            TWS0  = 8,   // TWI Status
            TWS1  = 16,  // TWI Status
            TWS2  = 32,  // TWI Status
            TWS3  = 64,  // TWI Status
            TWS4  = 128, // TWI Status
        };
    };

    // TWI (Slave) Address register
    struct TWAR {
        static const uint8_t address = 0x72;
        enum bits : uint8_t {
            TWGCE = 1,   // TWI General Call Recognition Enable Bit
            TWA0  = 2,   // TWI (Slave) Address register Bits
            TWA1  = 4,   // TWI (Slave) Address register Bits
            TWA2  = 8,   // TWI (Slave) Address register Bits
            TWA3  = 16,  // TWI (Slave) Address register Bits
            TWA4  = 32,  // TWI (Slave) Address register Bits
            TWA5  = 64,  // TWI (Slave) Address register Bits
            TWA6  = 128, // TWI (Slave) Address register Bits
        };
    };

    // TWI Data register
    struct TWDR {
        static const uint8_t address = 0x73;
    };

    // TWI Control Register
    struct TWCR {
        static const uint8_t address = 0x74;
        enum bits : uint8_t {
            TWIE  = 1,   // TWI Interrupt Enable
            TWEN  = 4,   // TWI Enable Bit
            TWWC  = 8,   // TWI Write Collition Flag
            TWSTO = 16,  // TWI Stop Condition Bit
            TWSTA = 32,  // TWI Start Condition Bit
            TWEA  = 64,  // TWI Enable Acknowledge Bit
            TWINT = 128, // TWI Interrupt Flag
        };
    };

    // Timer/Counter1 Output Compare Register  Bytes
    struct OCR1C {
        static const uint16_t address = 0x78;
    };

    // Timer/Counter1 Control Register C
    struct TCCR1C {
        static const uint8_t address = 0x7a;
        enum bits : uint8_t {
            FOC1C = 32,  // Force Output Compare for channel C
            FOC1B = 64,  // Force Output Compare for channel B
            FOC1A = 128, // Force Output Compare for channel A
        };
    };

    // Extended Timer/Counter Interrupt Flag register
    struct ETIFR {
        static const uint8_t address = 0x7c;
        enum bits : uint8_t {
            OCF1C = 1,  // Timer/Counter 1, Output Compare C Match Flag
            OCF3C = 2,  // Timer/Counter3 Output Compare C Match Flag
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
            OCIE1C = 1,  // Timer/Counter 1, Output Compare Match C Interrupt Enable
            OCIE3C = 2,  // Timer/Counter3, Output Compare Match Interrupt Enable
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

    // Timer/Counter3 Output compare Register C  Bytes
    struct OCR3C {
        static const uint16_t address = 0x82;
    };

    // Timer/Counter3 Output Compare Register B  Bytes
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
            WGM30 = 8,   // Waveform Generation Mode
            WGM31 = 16,  // Waveform Generation Mode
            ICES3 = 64,  // Input Capture 3 Edge Select
            ICNC3 = 128, // Input Capture 3  Noise Canceler
        };
    };

    // Timer/Counter3 Control Register A
    struct TCCR3A {
        static const uint8_t address = 0x8b;
        enum bits : uint8_t {
            WGM30  = 1,   // Waveform Generation Mode Bits
            WGM31  = 2,   // Waveform Generation Mode Bits
            COM3C0 = 4,   // Compare Output Mode 3C, bits
            COM3C1 = 8,   // Compare Output Mode 3C, bits
            COM3B0 = 16,  // Compare Output Mode 3B, bits
            COM3B1 = 32,  // Compare Output Mode 3B, bits
            COM3A0 = 64,  // Compare Output Mode 3A, bits
            COM3A1 = 128, // Compare Output Mode 3A, bits
        };
    };

    // Timer/Counter3 Control Register C
    struct TCCR3C {
        static const uint8_t address = 0x8c;
        enum bits : uint8_t {
            FOC3C = 32,  // Force Output Compare for channel C
            FOC3B = 64,  // Force Output Compare for channel B
            FOC3A = 128, // Force Output Compare for channel A
        };
    };

    // The ADC Control and Status register B
    struct ADCSRB {
        static const uint8_t address = 0x8e;
        enum bits : uint8_t {
            ADTS0 = 1, // ADC Auto Trigger Source bits
            ADTS1 = 2, // ADC Auto Trigger Source bits
            ADTS2 = 4, // ADC Auto Trigger Source bits
        };
    };

    // USART Baud Rate Register Hight Byte
    struct UBRR0H {
        static const uint8_t address = 0x90;
    };

    // USART Control and Status Register C
    struct UCSR0C {
        static const uint8_t address = 0x95;
        enum bits : uint8_t {
            UCPOL0 = 1,  // Clock Polarity
            UCSZ00 = 2,  // Character Size
            UCSZ01 = 4,  // Character Size
            USBS0  = 8,  // Stop Bit Select
            UPM00  = 16, // Parity Mode Bits
            UPM01  = 32, // Parity Mode Bits
            UMSEL0 = 64, // USART Mode Select
        };
    };

    // USART Baud Rate Register Hight Byte
    struct UBRR1H {
        static const uint8_t address = 0x98;
    };

    // USART Baud Rate Register Low Byte
    struct UBRR1L {
        static const uint8_t address = 0x99;
    };

    // USART Control and Status Register B
    struct UCSR1B {
        static const uint8_t address = 0x9a;
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
        static const uint8_t address = 0x9b;
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
        static const uint8_t address = 0x9c;
    };

    // USART Control and Status Register C
    struct UCSR1C {
        static const uint8_t address = 0x9d;
        enum bits : uint8_t {
            UCPOL1 = 1,  // Clock Polarity
            UCSZ10 = 2,  // Character Size
            UCSZ11 = 4,  // Character Size
            USBS1  = 8,  // Stop Bit Select
            UPM10  = 16, // Parity Mode Bits
            UPM11  = 32, // Parity Mode Bits
            UMSEL1 = 64, // USART Mode Select
        };
    };

}

#endif
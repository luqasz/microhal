#ifndef at90can32_sfr_h
#define at90can32_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       AT90CAN32
*/

namespace SFR {

    // Port A Input Pins
    struct PINA {
        static const uint8_t address = 0x20;
    };

    // Port A Data Direction Register
    struct DDRA {
        static const uint8_t address = 0x21;
    };

    // Port A Data Register
    struct PORTA {
        static const uint8_t address = 0x22;
    };

    // Port B Input Pins
    struct PINB {
        static const uint8_t address = 0x23;
    };

    // Port B Data Direction Register
    struct DDRB {
        static const uint8_t address = 0x24;
    };

    // Port B Data Register
    struct PORTB {
        static const uint8_t address = 0x25;
    };

    // Port C Input Pins
    struct PINC {
        static const uint8_t address = 0x26;
    };

    // Port C Data Direction Register
    struct DDRC {
        static const uint8_t address = 0x27;
    };

    // Port C Data Register
    struct PORTC {
        static const uint8_t address = 0x28;
    };

    // Port D Input Pins
    struct PIND {
        static const uint8_t address = 0x29;
    };

    // Port D Data Direction Register
    struct DDRD {
        static const uint8_t address = 0x2a;
    };

    // Port D Data Register
    struct PORTD {
        static const uint8_t address = 0x2b;
    };

    // Input Pins, Port E
    struct PINE {
        static const uint8_t address = 0x2c;
    };

    // Data Direction Register, Port E
    struct DDRE {
        static const uint8_t address = 0x2d;
    };

    // Data Register, Port E
    struct PORTE {
        static const uint8_t address = 0x2e;
    };

    // Input Pins, Port F
    struct PINF {
        static const uint8_t address = 0x2f;
    };

    // Data Direction Register, Port F
    struct DDRF {
        static const uint8_t address = 0x30;
    };

    // Data Register, Port F
    struct PORTF {
        static const uint8_t address = 0x31;
    };

    // Input Pins, Port G
    struct PING {
        static const uint8_t address = 0x32;
    };

    // Data Direction Register, Port G
    struct DDRG {
        static const uint8_t address = 0x33;
    };

    // Data Register, Port G
    struct PORTG {
        static const uint8_t address = 0x34;
    };

    // Timer/Counter0 Interrupt Flag register
    struct TIFR0 {
        static const uint8_t address = 0x35;
        enum bits : uint8_t {
            TOV0  = 1, // Timer/Counter0 Overflow Flag
            OCF0A = 2, // Timer/Counter0 Output Compare Flag 0
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR1 {
        static const uint8_t address = 0x36;
        enum bits : uint8_t {
            TOV1  = 1,  // Timer/Counter1 Overflow Flag
            OCF1A = 2,  // Output Compare Flag 1A
            OCF1B = 4,  // Output Compare Flag 1B
            OCF1C = 8,  // Output Compare Flag 1C
            ICF1  = 32, // Input Capture Flag 1
        };
    };

    // Timer/Counter Interrupt Flag Register
    struct TIFR2 {
        static const uint8_t address = 0x37;
        enum bits : uint8_t {
            TOV2  = 1, // Timer/Counter2 Overflow Flag
            OCF2A = 2, // Output Compare Flag 2
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR3 {
        static const uint8_t address = 0x38;
        enum bits : uint8_t {
            TOV3  = 1,  // Timer/Counter3 Overflow Flag
            OCF3A = 2,  // Output Compare Flag 3A
            OCF3B = 4,  // Output Compare Flag 3B
            OCF3C = 8,  // Output Compare Flag 3C
            ICF3  = 32, // Input Capture Flag 3
        };
    };

    // External Interrupt Flag Register
    struct EIFR {
        static const uint8_t address = 0x3c;
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
        static const uint8_t address = 0x3d;
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

    // General Purpose IO Register 0
    struct GPIOR0 {
        static const uint8_t address = 0x3e;
        enum bits : uint8_t {
            GPIOR00 = 1,   // General Purpose IO Register 0 bit 0
            GPIOR01 = 2,   // General Purpose IO Register 0 bit 1
            GPIOR02 = 4,   // General Purpose IO Register 0 bit 2
            GPIOR03 = 8,   // General Purpose IO Register 0 bit 3
            GPIOR04 = 16,  // General Purpose IO Register 0 bit 4
            GPIOR05 = 32,  // General Purpose IO Register 0 bit 5
            GPIOR06 = 64,  // General Purpose IO Register 0 bit 6
            GPIOR07 = 128, // General Purpose IO Register 0 bit 7
        };
    };

    // EEPROM Control Register
    struct EECR {
        static const uint8_t address = 0x3f;
        enum bits : uint8_t {
            EERE  = 1, // EEPROM Read Enable
            EEWE  = 2, // EEPROM Write Enable
            EEMWE = 4, // EEPROM Master Write Enable
            EERIE = 8, // EEPROM Ready Interrupt Enable
        };
    };

    // EEPROM Data Register
    struct EEDR {
        static const uint8_t address = 0x40;
        enum bits : uint8_t {
            EEDR0 = 1,   // EEPROM Data bits
            EEDR1 = 2,   // EEPROM Data bits
            EEDR2 = 4,   // EEPROM Data bits
            EEDR3 = 8,   // EEPROM Data bits
            EEDR4 = 16,  // EEPROM Data bits
            EEDR5 = 32,  // EEPROM Data bits
            EEDR6 = 64,  // EEPROM Data bits
            EEDR7 = 128, // EEPROM Data bits
        };
    };

    // EEPROM Read/Write Access Bytes
    struct EEAR {
        static const uint16_t address = 0x41;
        enum bits : uint8_t {
            EEAR0 = 1,   // EEPROM Address bits
            EEAR1 = 2,   // EEPROM Address bits
            EEAR2 = 4,   // EEPROM Address bits
            EEAR3 = 8,   // EEPROM Address bits
            EEAR4 = 16,  // EEPROM Address bits
            EEAR5 = 32,  // EEPROM Address bits
            EEAR6 = 64,  // EEPROM Address bits
            EEAR7 = 128, // EEPROM Address bits
        };
    };

    // General Timer/Control Register
    struct GTCCR {
        static const uint8_t address = 0x43;
        enum bits : uint8_t {
            PSR310 = 1,   // Prescaler Reset Timer/Counter1 and Timer/Counter0
            PSR2   = 2,   // Prescaler Reset Timer/Counter2
            TSM    = 128, // Timer/Counter Synchronization Mode
        };
    };

    // Timer/Counter0 Control Register
    struct TCCR0A {
        static const uint8_t address = 0x44;
        enum bits : uint8_t {
            CS00   = 1,   // Clock Selects
            CS01   = 2,   // Clock Selects
            CS02   = 4,   // Clock Selects
            WGM01  = 8,   // Waveform Generation Mode 1
            COM0A0 = 16,  // Compare Match Output Modes
            COM0A1 = 32,  // Compare Match Output Modes
            WGM00  = 64,  // Waveform Generation Mode 0
            FOC0A  = 128, // Force Output Compare
        };
    };

    // Timer/Counter0
    struct TCNT0 {
        static const uint8_t address = 0x46;
    };

    // Timer/Counter0 Output Compare Register
    struct OCR0A {
        static const uint8_t address = 0x47;
        enum bits : uint8_t {
            OCR0A0 = 1,   // Output Compare A bits
            OCR0A1 = 2,   // Output Compare A bits
            OCR0A2 = 4,   // Output Compare A bits
            OCR0A3 = 8,   // Output Compare A bits
            OCR0A4 = 16,  // Output Compare A bits
            OCR0A5 = 32,  // Output Compare A bits
            OCR0A6 = 64,  // Output Compare A bits
            OCR0A7 = 128, // Output Compare A bits
        };
    };

    // General Purpose IO Register 1
    struct GPIOR1 {
        static const uint8_t address = 0x4a;
        enum bits : uint8_t {
            GPIOR0 = 1,   // General Purpose IO Register 1 bis
            GPIOR1 = 2,   // General Purpose IO Register 1 bis
            GPIOR2 = 4,   // General Purpose IO Register 1 bis
            GPIOR3 = 8,   // General Purpose IO Register 1 bis
            GPIOR4 = 16,  // General Purpose IO Register 1 bis
            GPIOR5 = 32,  // General Purpose IO Register 1 bis
            GPIOR6 = 64,  // General Purpose IO Register 1 bis
            GPIOR7 = 128, // General Purpose IO Register 1 bis
        };
    };

    // General Purpose IO Register 2
    struct GPIOR2 {
        static const uint8_t address = 0x4b;
        enum bits : uint8_t {
            GPIOR0 = 1,   // General Purpose IO Register 2 bis
            GPIOR1 = 2,   // General Purpose IO Register 2 bis
            GPIOR2 = 4,   // General Purpose IO Register 2 bis
            GPIOR3 = 8,   // General Purpose IO Register 2 bis
            GPIOR4 = 16,  // General Purpose IO Register 2 bis
            GPIOR5 = 32,  // General Purpose IO Register 2 bis
            GPIOR6 = 64,  // General Purpose IO Register 2 bis
            GPIOR7 = 128, // General Purpose IO Register 2 bis
        };
    };

    // SPI Control Register
    struct SPCR {
        static const uint8_t address = 0x4c;
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
        static const uint8_t address = 0x4d;
        enum bits : uint8_t {
            SPI2X = 1,   // Double SPI Speed Bit
            WCOL  = 64,  // Write Collision Flag
            SPIF  = 128, // SPI Interrupt Flag
        };
    };

    // SPI Data Register
    struct SPDR {
        static const uint8_t address = 0x4e;
        enum bits : uint8_t {
            SPD0 = 1,   // SPI Data Register
            SPD1 = 2,   // SPI Data Register
            SPD2 = 4,   // SPI Data Register
            SPD3 = 8,   // SPI Data Register
            SPD4 = 16,  // SPI Data Register
            SPD5 = 32,  // SPI Data Register
            SPD6 = 64,  // SPI Data Register
            SPD7 = 128, // SPI Data Register
        };
    };

    // Analog Comparator Control And Status Register
    struct ACSR {
        static const uint8_t address = 0x50;
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

    // On-Chip Debug Related Register in I/O Memory
    struct OCDR {
        static const uint8_t address = 0x51;
    };

    // Sleep Mode Control Register
    struct SMCR {
        static const uint8_t address = 0x53;
        enum bits : uint8_t {
            SE  = 1, // Sleep Enable
            SM0 = 2, // Sleep Mode Select bits
            SM1 = 4, // Sleep Mode Select bits
            SM2 = 8, // Sleep Mode Select bits
        };
    };

    // MCU Status Register
    struct MCUSR {
        static const uint8_t address = 0x54;
        enum bits : uint8_t {
            PORF  = 1,  // Power-on reset flag
            EXTRF = 2,  // External Reset Flag
            BORF  = 4,  // Brown-out Reset Flag
            WDRF  = 8,  // Watchdog Reset Flag
            JTRF  = 16, // JTAG Reset Flag
        };
    };

    // MCU Control Register
    struct MCUCR {
        static const uint8_t address = 0x55;
        enum bits : uint8_t {
            IVCE  = 1,   // Interrupt Vector Change Enable
            IVSEL = 2,   // Interrupt Vector Select
            PUD   = 16,  // Pull-up disable
            JTD   = 128, // JTAG Interface Disable
        };
    };

    // Store Program Memory Control Register
    struct SPMCSR {
        static const uint8_t address = 0x57;
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

    // RAM Page Z Select Register - Not used.
    struct RAMPZ {
        static const uint8_t address = 0x5b;
        enum bits : uint8_t {
            RAMPZ0 = 1, // RAM Page Z Select Register Bit 0
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

    // Watchdog Timer Control Register
    struct WDTCR {
        static const uint8_t address = 0x60;
        enum bits : uint8_t {
            WDP0 = 1,  // Watch Dog Timer Prescaler bits
            WDP1 = 2,  // Watch Dog Timer Prescaler bits
            WDP2 = 4,  // Watch Dog Timer Prescaler bits
            WDE  = 8,  // Watch Dog Enable
            WDCE = 16, // Watchdog Change Enable
        };
    };

    // Clock Prescale Register
    struct CLKPR {
        static const uint8_t address = 0x61;
        enum bits : uint8_t {
            CLKPS0 = 1,   //
            CLKPS1 = 2,   //
            CLKPS2 = 4,   //
            CLKPS3 = 8,   //
            CLKPCE = 128, //
        };
    };

    // Oscillator Calibration Value
    struct OSCCAL {
        static const uint8_t address = 0x66;
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

    // External Interrupt Control Register A
    struct EICRA {
        static const uint8_t address = 0x69;
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

    // External Interrupt Control Register B
    struct EICRB {
        static const uint8_t address = 0x6a;
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

    // Timer/Counter0 Interrupt Mask Register
    struct TIMSK0 {
        static const uint8_t address = 0x6e;
        enum bits : uint8_t {
            TOIE0  = 1, // Timer/Counter0 Overflow Interrupt Enable
            OCIE0A = 2, // Timer/Counter0 Output Compare Match Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Mask Register
    struct TIMSK1 {
        static const uint8_t address = 0x6f;
        enum bits : uint8_t {
            TOIE1  = 1,  // Timer/Counter1 Overflow Interrupt Enable
            OCIE1A = 2,  // Timer/Counter1 Output CompareA Match Interrupt Enable
            OCIE1B = 4,  // Timer/Counter1 Output CompareB Match Interrupt Enable
            OCIE1C = 8,  // Timer/Counter1 Output CompareC Match Interrupt Enable
            ICIE1  = 32, // Timer/Counter1 Input Capture Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Mask register
    struct TIMSK2 {
        static const uint8_t address = 0x70;
        enum bits : uint8_t {
            TOIE2  = 1, // Timer/Counter2 Overflow Interrupt Enable
            OCIE2A = 2, // Timer/Counter2 Output Compare Match Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Mask Register
    struct TIMSK3 {
        static const uint8_t address = 0x71;
        enum bits : uint8_t {
            TOIE3  = 1,  // Timer/Counter3 Overflow Interrupt Enable
            OCIE3A = 2,  // Timer/Counter3 Output CompareA Match Interrupt Enable
            OCIE3B = 4,  // Timer/Counter3 Output CompareB Match Interrupt Enable
            OCIE3C = 8,  // Timer/Counter3 Output CompareC Match Interrupt Enable
            ICIE3  = 32, // Timer/Counter3 Input Capture Interrupt Enable
        };
    };

    // External Memory Control Register A
    struct XMCRA {
        static const uint8_t address = 0x74;
        enum bits : uint8_t {
            SRW00 = 1,   // Wait state select bit lower page
            SRW01 = 2,   // Wait state select bit lower page
            SRW10 = 4,   // Wait state select bit upper page
            SRW11 = 8,   // Wait state select bit upper page
            SRL0  = 16,  // Wait state page limit
            SRL1  = 32,  // Wait state page limit
            SRL2  = 64,  // Wait state page limit
            SRE   = 128, // External SRAM Enable
        };
    };

    // External Memory Control Register B
    struct XMCRB {
        static const uint8_t address = 0x75;
        enum bits : uint8_t {
            XMM0 = 1,   // External Memory High Mask
            XMM1 = 2,   // External Memory High Mask
            XMM2 = 4,   // External Memory High Mask
            XMBK = 128, // External Memory Bus Keeper Enable
        };
    };

    // ADC Data Register  Bytes
    struct ADC {
        static const uint16_t address = 0x78;
    };

    // The ADC Control and Status register
    struct ADCSRA {
        static const uint8_t address = 0x7a;
        enum bits : uint8_t {
            ADPS0 = 1,   // ADC  Prescaler Select Bits
            ADPS1 = 2,   // ADC  Prescaler Select Bits
            ADPS2 = 4,   // ADC  Prescaler Select Bits
            ADIE  = 8,   // ADC Interrupt Enable
            ADIF  = 16,  // ADC Interrupt Flag
            ADATE = 32,  // ADC Auto Trigger Enable
            ADSC  = 64,  // ADC Start Conversion
            ADEN  = 128, // ADC Enable
        };
    };

    // ADC Control and Status Register B
    struct ADCSRB {
        static const uint8_t address = 0x7b;
        enum bits : uint8_t {
            ADTS0 = 1,   // ADC Auto Trigger Sources
            ADTS1 = 2,   // ADC Auto Trigger Sources
            ADTS2 = 4,   // ADC Auto Trigger Sources
            ACME  = 64,  // Analog Comparator Multiplexer Enable
            ADHSM = 128, // ADC High Speed Mode
        };
    };

    // The ADC multiplexer Selection Register
    struct ADMUX {
        static const uint8_t address = 0x7c;
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

    // Digital Input Disable Register 1
    struct DIDR0 {
        static const uint8_t address = 0x7e;
        enum bits : uint8_t {
            ADC0D = 1,   // ADC0 Digital input Disable
            ADC1D = 2,   // ADC1 Digital input Disable
            ADC2D = 4,   // ADC2 Digital input Disable
            ADC3D = 8,   // ADC3 Digital input Disable
            ADC4D = 16,  // ADC4 Digital input Disable
            ADC5D = 32,  // ADC5 Digital input Disable
            ADC6D = 64,  // ADC6 Digital input Disable
            ADC7D = 128, // ADC7 Digital input Disable
        };
    };

    //
    struct DIDR1 {
        static const uint8_t address = 0x7f;
        enum bits : uint8_t {
            AIN0D = 1, // AIN0 Digital Input Disable
            AIN1D = 2, // AIN1 Digital Input Disable
        };
    };

    // Timer/Counter1 Control Register A
    struct TCCR1A {
        static const uint8_t address = 0x80;
        enum bits : uint8_t {
            WGM10  = 1,   // Waveform Generation Mode
            WGM11  = 2,   // Waveform Generation Mode
            COM1C0 = 4,   // Compare Output Mode 1C, bits
            COM1C1 = 8,   // Compare Output Mode 1C, bits
            COM1B0 = 16,  // Compare Output Mode 1B, bits
            COM1B1 = 32,  // Compare Output Mode 1B, bits
            COM1A0 = 64,  // Compare Output Mode 1A, bits
            COM1A1 = 128, // Compare Output Mode 1A, bits
        };
    };

    // Timer/Counter1 Control Register B
    struct TCCR1B {
        static const uint8_t address = 0x81;
        enum bits : uint8_t {
            CS10  = 1,   // Prescaler source of Timer/Counter 1
            CS11  = 2,   // Prescaler source of Timer/Counter 1
            CS12  = 4,   // Prescaler source of Timer/Counter 1
            WGM10 = 8,   // Waveform Generation Mode
            WGM11 = 16,  // Waveform Generation Mode
            ICES1 = 64,  // Input Capture 1 Edge Select
            ICNC1 = 128, // Input Capture 1 Noise Canceler
        };
    };

    // Timer/Counter 1 Control Register C
    struct TCCR1C {
        static const uint8_t address = 0x82;
        enum bits : uint8_t {
            FOC1C = 32,  // Force Output Compare 1C
            FOC1B = 64,  // Force Output Compare 1B
            FOC1A = 128, // Force Output Compare 1A
        };
    };

    // Timer/Counter1  Bytes
    struct TCNT1 {
        static const uint16_t address = 0x84;
    };

    // Timer/Counter1 Input Capture Register  Bytes
    struct ICR1 {
        static const uint16_t address = 0x86;
    };

    // Timer/Counter1 Output Compare Register  Bytes
    struct OCR1A {
        static const uint16_t address = 0x88;
    };

    // Timer/Counter1 Output Compare Register  Bytes
    struct OCR1B {
        static const uint16_t address = 0x8a;
    };

    // Timer/Counter1 Output Compare Register  Bytes
    struct OCR1C {
        static const uint16_t address = 0x8c;
    };

    // Timer/Counter3 Control Register A
    struct TCCR3A {
        static const uint8_t address = 0x90;
        enum bits : uint8_t {
            WGM30  = 1,   // Waveform Generation Mode
            WGM31  = 2,   // Waveform Generation Mode
            COM3C0 = 4,   // Compare Output Mode 3C, bits
            COM3C1 = 8,   // Compare Output Mode 3C, bits
            COM3B0 = 16,  // Compare Output Mode 3B, bits
            COM3B1 = 32,  // Compare Output Mode 3B, bits
            COM3A0 = 64,  // Compare Output Mode 3A, bits
            COM3A1 = 128, // Compare Output Mode 3A, bits
        };
    };

    // Timer/Counter3 Control Register B
    struct TCCR3B {
        static const uint8_t address = 0x91;
        enum bits : uint8_t {
            CS30  = 1,   // Prescaler source of Timer/Counter 3
            CS31  = 2,   // Prescaler source of Timer/Counter 3
            CS32  = 4,   // Prescaler source of Timer/Counter 3
            WGM30 = 8,   // Waveform Generation Mode
            WGM31 = 16,  // Waveform Generation Mode
            ICES3 = 64,  // Input Capture 3 Edge Select
            ICNC3 = 128, // Input Capture 3 Noise Canceler
        };
    };

    // Timer/Counter 3 Control Register C
    struct TCCR3C {
        static const uint8_t address = 0x92;
        enum bits : uint8_t {
            FOC3C = 32,  // Force Output Compare 3C
            FOC3B = 64,  // Force Output Compare 3B
            FOC3A = 128, // Force Output Compare 3A
        };
    };

    // Timer/Counter3  Bytes
    struct TCNT3 {
        static const uint16_t address = 0x94;
    };

    // Timer/Counter3 Input Capture Register  Bytes
    struct ICR3 {
        static const uint16_t address = 0x96;
    };

    // Timer/Counter3 Output Compare Register  Bytes
    struct OCR3A {
        static const uint16_t address = 0x98;
    };

    // Timer/Counter3 Output Compare Register  Bytes
    struct OCR3B {
        static const uint16_t address = 0x9a;
    };

    // Timer/Counter3 Output Compare Register  Bytes
    struct OCR3C {
        static const uint16_t address = 0x9c;
    };

    // Timer/Counter2 Control Register
    struct TCCR2A {
        static const uint8_t address = 0xb0;
        enum bits : uint8_t {
            CS20   = 1,   // Clock Select bits
            CS21   = 2,   // Clock Select bits
            CS22   = 4,   // Clock Select bits
            WGM21  = 8,   // Waveform Generation Mode
            COM2A0 = 16,  // Compare Output Mode bits
            COM2A1 = 32,  // Compare Output Mode bits
            WGM20  = 64,  // Waveform Genration Mode
            FOC2A  = 128, // Force Output Compare
        };
    };

    // Timer/Counter2
    struct TCNT2 {
        static const uint8_t address = 0xb2;
    };

    // Timer/Counter2 Output Compare Register
    struct OCR2A {
        static const uint8_t address = 0xb3;
    };

    // Asynchronous Status Register
    struct ASSR {
        static const uint8_t address = 0xb6;
        enum bits : uint8_t {
            TCR2UB = 1,  // TCR2UB: Timer/Counter Control Register2 Update Busy
            OCR2UB = 2,  // Output Compare Register2 Update Busy
            TCN2UB = 4,  // TCN2UB: Timer/Counter2 Update Busy
            AS2    = 8,  // AS2: Asynchronous Timer/Counter2
            EXCLK  = 16, // Enable External Clock Interrupt
        };
    };

    // TWI Bit Rate register
    struct TWBR {
        static const uint8_t address = 0xb8;
    };

    // TWI Status Register
    struct TWSR {
        static const uint8_t address = 0xb9;
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
        static const uint8_t address = 0xba;
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
        static const uint8_t address = 0xbb;
    };

    // TWI Control Register
    struct TWCR {
        static const uint8_t address = 0xbc;
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

    // USART Control and Status Register A
    struct UCSR0A {
        static const uint8_t address = 0xc0;
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

    // USART Control and Status Register B
    struct UCSR0B {
        static const uint8_t address = 0xc1;
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

    // USART Control and Status Register C
    struct UCSR0C {
        static const uint8_t address = 0xc2;
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

    // USART Baud Rate Register t Bytes
    struct UBRR0 {
        static const uint16_t address = 0xc4;
    };

    // USART I/O Data Register
    struct UDR0 {
        static const uint8_t address = 0xc6;
    };

    // USART Control and Status Register A
    struct UCSR1A {
        static const uint8_t address = 0xc8;
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

    // USART Control and Status Register B
    struct UCSR1B {
        static const uint8_t address = 0xc9;
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

    // USART Control and Status Register C
    struct UCSR1C {
        static const uint8_t address = 0xca;
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

    // USART Baud Rate Register t Bytes
    struct UBRR1 {
        static const uint16_t address = 0xcc;
    };

    // USART I/O Data Register
    struct UDR1 {
        static const uint8_t address = 0xce;
    };

    // CAN General Control Register
    struct CANGCON {
        static const uint8_t address = 0xd8;
        enum bits : uint8_t {
            SWRES  = 1,   // Software Reset Request
            ENASTB = 2,   // Enable / Standby
            TEST   = 4,   // Test Mode
            LISTEN = 8,   // Listening Mode
            SYNTTC = 16,  // Synchronization of TTC
            TTC    = 32,  // Time Trigger Communication
            OVRQ   = 64,  // Overload Frame Request
            ABRQ   = 128, // Abort Request
        };
    };

    // CAN General Status Register
    struct CANGSTA {
        static const uint8_t address = 0xd9;
        enum bits : uint8_t {
            ERRP  = 1,  // Error Passive Mode
            BOFF  = 2,  // Bus Off Mode
            ENFG  = 4,  // Enable Flag
            RXBSY = 8,  // Receiver Busy
            TXBSY = 16, // Transmitter Busy
            OVRG  = 64, // Overload Frame Flag
        };
    };

    // CAN General Interrupt Register
    struct CANGIT {
        static const uint8_t address = 0xda;
        enum bits : uint8_t {
            AERG   = 1,   // Ackknowledgement Error General
            FERG   = 2,   // Form Error General
            CERG   = 4,   // CRC Error General
            SERG   = 8,   // Stuff Error General
            BXOK   = 16,  // Burst Receive Interrupt
            OVRTIM = 32,  // Overrun CAN Timer
            BOFFIT = 64,  // Bus Off Interrupt Flag
            CANIT  = 128, // General Interrupt Flag
        };
    };

    // CAN General Interrupt Enable Register
    struct CANGIE {
        static const uint8_t address = 0xdb;
        enum bits : uint8_t {
            ENOVRT = 1,   // Enable CAN Timer Overrun Interrupt
            ENERG  = 2,   // Enable General Error Interrupt
            ENBX   = 4,   // Enable Burst Receive Interrupt
            ENERR  = 8,   // Enable MOb Error Interrupt
            ENTX   = 16,  // Enable Transmitt Interrupt
            ENRX   = 32,  // Enable Receive Interrupt
            ENBOFF = 64,  // Enable Bus Off INterrupt
            ENIT   = 128, // Enable all Interrupts
        };
    };

    // Enable MOb Register
    struct CANEN2 {
        static const uint8_t address = 0xdc;
        enum bits : uint8_t {
            ENMOB0 = 1,   // Enable MOb
            ENMOB1 = 2,   // Enable MOb
            ENMOB2 = 4,   // Enable MOb
            ENMOB3 = 8,   // Enable MOb
            ENMOB4 = 16,  // Enable MOb
            ENMOB5 = 32,  // Enable MOb
            ENMOB6 = 64,  // Enable MOb
            ENMOB7 = 128, // Enable MOb
        };
    };

    // Enable MOb Register
    struct CANEN1 {
        static const uint8_t address = 0xdd;
        enum bits : uint8_t {
            ENMOB0 = 1,  // Enable MOb
            ENMOB1 = 2,  // Enable MOb
            ENMOB2 = 4,  // Enable MOb
            ENMOB3 = 8,  // Enable MOb
            ENMOB4 = 16, // Enable MOb
            ENMOB5 = 32, // Enable MOb
            ENMOB6 = 64, // Enable MOb
        };
    };

    // Enable Interrupt MOb Register
    struct CANIE2 {
        static const uint8_t address = 0xde;
        enum bits : uint8_t {
            IEMOB0 = 1,   // Interrupt Enable by MOb
            IEMOB1 = 2,   // Interrupt Enable by MOb
            IEMOB2 = 4,   // Interrupt Enable by MOb
            IEMOB3 = 8,   // Interrupt Enable by MOb
            IEMOB4 = 16,  // Interrupt Enable by MOb
            IEMOB5 = 32,  // Interrupt Enable by MOb
            IEMOB6 = 64,  // Interrupt Enable by MOb
            IEMOB7 = 128, // Interrupt Enable by MOb
        };
    };

    // Enable Interrupt MOb Register
    struct CANIE1 {
        static const uint8_t address = 0xdf;
        enum bits : uint8_t {
            IEMOB0 = 1,  // Interrupt Enable by MOb
            IEMOB1 = 2,  // Interrupt Enable by MOb
            IEMOB2 = 4,  // Interrupt Enable by MOb
            IEMOB3 = 8,  // Interrupt Enable by MOb
            IEMOB4 = 16, // Interrupt Enable by MOb
            IEMOB5 = 32, // Interrupt Enable by MOb
            IEMOB6 = 64, // Interrupt Enable by MOb
        };
    };

    // CAN Status Interrupt MOb Register
    struct CANSIT2 {
        static const uint8_t address = 0xe0;
        enum bits : uint8_t {
            SIT0 = 1,   // Status of Interrupt by MOb
            SIT1 = 2,   // Status of Interrupt by MOb
            SIT2 = 4,   // Status of Interrupt by MOb
            SIT3 = 8,   // Status of Interrupt by MOb
            SIT4 = 16,  // Status of Interrupt by MOb
            SIT5 = 32,  // Status of Interrupt by MOb
            SIT6 = 64,  // Status of Interrupt by MOb
            SIT7 = 128, // Status of Interrupt by MOb
        };
    };

    // CAN Status Interrupt MOb Register
    struct CANSIT1 {
        static const uint8_t address = 0xe1;
        enum bits : uint8_t {
            SIT0 = 1,  // Status of Interrupt by MOb
            SIT1 = 2,  // Status of Interrupt by MOb
            SIT2 = 4,  // Status of Interrupt by MOb
            SIT3 = 8,  // Status of Interrupt by MOb
            SIT4 = 16, // Status of Interrupt by MOb
            SIT5 = 32, // Status of Interrupt by MOb
            SIT6 = 64, // Status of Interrupt by MOb
        };
    };

    // Bit Timing Register 1
    struct CANBT1 {
        static const uint8_t address = 0xe2;
        enum bits : uint8_t {
            BRP0 = 2,  // Baud Rate Prescaler bits
            BRP1 = 4,  // Baud Rate Prescaler bits
            BRP2 = 8,  // Baud Rate Prescaler bits
            BRP3 = 16, // Baud Rate Prescaler bits
            BRP4 = 32, // Baud Rate Prescaler bits
            BRP5 = 64, // Baud Rate Prescaler bits
        };
    };

    // Bit Timing Register 2
    struct CANBT2 {
        static const uint8_t address = 0xe3;
        enum bits : uint8_t {
            PRS0 = 2,  // Propagation Time Segment
            PRS1 = 4,  // Propagation Time Segment
            PRS2 = 8,  // Propagation Time Segment
            SJW0 = 32, // Re-Sync Jump Width
            SJW1 = 64, // Re-Sync Jump Width
        };
    };

    // Bit Timing Register 3
    struct CANBT3 {
        static const uint8_t address = 0xe4;
        enum bits : uint8_t {
            SMP   = 1,  // Sample Type
            PHS10 = 2,  // Phase Segment 1
            PHS11 = 4,  // Phase Segment 1
            PHS12 = 8,  // Phase Segment 1
            PHS20 = 16, // Phase Segments
            PHS21 = 32, // Phase Segments
            PHS22 = 64, // Phase Segments
        };
    };

    // Timer Control Register
    struct CANTCON {
        static const uint8_t address = 0xe5;
        enum bits : uint8_t {
            TPRSC0 = 1,   // CAN Timer Prescaler
            TPRSC1 = 2,   // CAN Timer Prescaler
            TPRSC2 = 4,   // CAN Timer Prescaler
            TPRSC3 = 8,   // CAN Timer Prescaler
            TPRSC4 = 16,  // CAN Timer Prescaler
            TPRSC5 = 32,  // CAN Timer Prescaler
            TPRSC6 = 64,  // CAN Timer Prescaler
            TPRSC7 = 128, // CAN Timer Prescaler
        };
    };

    // Timer Register
    struct CANTIM {
        static const uint8_t address = 0xe6;
        enum bits : uint8_t {
            CANTIM0 = 1,   // CAN Timer Count
            CANTIM1 = 2,   // CAN Timer Count
            CANTIM2 = 4,   // CAN Timer Count
            CANTIM3 = 8,   // CAN Timer Count
            CANTIM4 = 16,  // CAN Timer Count
            CANTIM5 = 32,  // CAN Timer Count
            CANTIM6 = 64,  // CAN Timer Count
            CANTIM7 = 128, // CAN Timer Count
        };
    };

    // TTC Timer Register
    struct CANTTC {
        static const uint8_t address = 0xe8;
        enum bits : uint8_t {
            TIMTTC0 = 1,   // TTC Timer Count
            TIMTTC1 = 2,   // TTC Timer Count
            TIMTTC2 = 4,   // TTC Timer Count
            TIMTTC3 = 8,   // TTC Timer Count
            TIMTTC4 = 16,  // TTC Timer Count
            TIMTTC5 = 32,  // TTC Timer Count
            TIMTTC6 = 64,  // TTC Timer Count
            TIMTTC7 = 128, // TTC Timer Count
        };
    };

    // Transmit Error Counter Register
    struct CANTEC {
        static const uint8_t address = 0xea;
        enum bits : uint8_t {
            TEC0 = 1,   // Trasnmit Error Count
            TEC1 = 2,   // Trasnmit Error Count
            TEC2 = 4,   // Trasnmit Error Count
            TEC3 = 8,   // Trasnmit Error Count
            TEC4 = 16,  // Trasnmit Error Count
            TEC5 = 32,  // Trasnmit Error Count
            TEC6 = 64,  // Trasnmit Error Count
            TEC7 = 128, // Trasnmit Error Count
        };
    };

    // Receive Error Counter Register
    struct CANREC {
        static const uint8_t address = 0xeb;
        enum bits : uint8_t {
            REC0 = 1,   // Receive Error Count
            REC1 = 2,   // Receive Error Count
            REC2 = 4,   // Receive Error Count
            REC3 = 8,   // Receive Error Count
            REC4 = 16,  // Receive Error Count
            REC5 = 32,  // Receive Error Count
            REC6 = 64,  // Receive Error Count
            REC7 = 128, // Receive Error Count
        };
    };

    // Highest Priority MOb Register
    struct CANHPMOB {
        static const uint8_t address = 0xec;
        enum bits : uint8_t {
            CGP0   = 1,   // CAN General purpose bits
            CGP1   = 2,   // CAN General purpose bits
            CGP2   = 4,   // CAN General purpose bits
            CGP3   = 8,   // CAN General purpose bits
            HPMOB0 = 16,  // Highest Priority MOb number
            HPMOB1 = 32,  // Highest Priority MOb number
            HPMOB2 = 64,  // Highest Priority MOb number
            HPMOB3 = 128, // Highest Priority MOb number
        };
    };

    // Page MOb Register
    struct CANPAGE {
        static const uint8_t address = 0xed;
        enum bits : uint8_t {
            INDX0  = 1,   // Data Buffer Index Bits
            INDX1  = 2,   // Data Buffer Index Bits
            INDX2  = 4,   // Data Buffer Index Bits
            AINC   = 8,   // MOb Data Buffer Auto Increment
            MOBNB0 = 16,  // MOb Number Bits
            MOBNB1 = 32,  // MOb Number Bits
            MOBNB2 = 64,  // MOb Number Bits
            MOBNB3 = 128, // MOb Number Bits
        };
    };

    // MOb Status Register
    struct CANSTMOB {
        static const uint8_t address = 0xee;
        enum bits : uint8_t {
            AERR = 1,   // Ackknowledgement Error
            FERR = 2,   // Form Error
            CERR = 4,   // CRC Error
            SERR = 8,   // Stuff Error
            BERR = 16,  // Bit Error
            RXOK = 32,  // Receive OK
            TXOK = 64,  // Transmit OK
            DLCW = 128, // Data Length Code Warning
        };
    };

    // MOb Control and DLC Register
    struct CANCDMOB {
        static const uint8_t address = 0xef;
        enum bits : uint8_t {
            DLC0    = 1,   // Data Length Code Bits
            DLC1    = 2,   // Data Length Code Bits
            DLC2    = 4,   // Data Length Code Bits
            DLC3    = 8,   // Data Length Code Bits
            IDE     = 16,  // Identifier Extension
            RPLV    = 32,  // Reply Valid
            CONMOB0 = 64,  // MOb Config Bits
            CONMOB1 = 128, // MOb Config Bits
        };
    };

    // Identifier Tag Register 4
    struct CANIDT4 {
        static const uint8_t address = 0xf0;
        enum bits : uint8_t {
            RB0TAG = 1,   // Reserved Bit 0 Tag
            RB1TAG = 2,   // Reserved Bit 1 Tag
            RTRTAG = 4,   // Remote Trasnmission Request Tag
            IDT0   = 8,   // Identifier Tag
            IDT1   = 16,  // Identifier Tag
            IDT2   = 32,  // Identifier Tag
            IDT3   = 64,  // Identifier Tag
            IDT4   = 128, // Identifier Tag
        };
    };

    // Identifier Tag Register 3
    struct CANIDT3 {
        static const uint8_t address = 0xf1;
        enum bits : uint8_t {
            IDT0 = 1,   // Identifier Tag
            IDT1 = 2,   // Identifier Tag
            IDT2 = 4,   // Identifier Tag
            IDT3 = 8,   // Identifier Tag
            IDT4 = 16,  // Identifier Tag
            IDT5 = 32,  // Identifier Tag
            IDT6 = 64,  // Identifier Tag
            IDT7 = 128, // Identifier Tag
        };
    };

    // Identifier Tag Register 2
    struct CANIDT2 {
        static const uint8_t address = 0xf2;
        enum bits : uint8_t {
            IDT0 = 1,   // Identifier Tag
            IDT1 = 2,   // Identifier Tag
            IDT2 = 4,   // Identifier Tag
            IDT3 = 8,   // Identifier Tag
            IDT4 = 16,  // Identifier Tag
            IDT5 = 32,  // Identifier Tag
            IDT6 = 64,  // Identifier Tag
            IDT7 = 128, // Identifier Tag
        };
    };

    // Identifier Tag Register 1
    struct CANIDT1 {
        static const uint8_t address = 0xf3;
        enum bits : uint8_t {
            IDT0 = 1,   // Identifier Tag
            IDT1 = 2,   // Identifier Tag
            IDT2 = 4,   // Identifier Tag
            IDT3 = 8,   // Identifier Tag
            IDT4 = 16,  // Identifier Tag
            IDT5 = 32,  // Identifier Tag
            IDT6 = 64,  // Identifier Tag
            IDT7 = 128, // Identifier Tag
        };
    };

    // Identifier Mask Register 4
    struct CANIDM4 {
        static const uint8_t address = 0xf4;
        enum bits : uint8_t {
            IDEMSK = 1,   // Identifier Extension Mask
            RTRMSK = 4,   // Remote Transmission Request Mask
            IDMSK0 = 8,   // Identifier Mask
            IDMSK1 = 16,  // Identifier Mask
            IDMSK2 = 32,  // Identifier Mask
            IDMSK3 = 64,  // Identifier Mask
            IDMSK4 = 128, // Identifier Mask
        };
    };

    // Identifier Mask Register 3
    struct CANIDM3 {
        static const uint8_t address = 0xf5;
        enum bits : uint8_t {
            IDMSK0 = 1,   // Identifier Mask
            IDMSK1 = 2,   // Identifier Mask
            IDMSK2 = 4,   // Identifier Mask
            IDMSK3 = 8,   // Identifier Mask
            IDMSK4 = 16,  // Identifier Mask
            IDMSK5 = 32,  // Identifier Mask
            IDMSK6 = 64,  // Identifier Mask
            IDMSK7 = 128, // Identifier Mask
        };
    };

    // Identifier Mask Register 2
    struct CANIDM2 {
        static const uint8_t address = 0xf6;
        enum bits : uint8_t {
            IDMSK0 = 1,   // Identifier Mask
            IDMSK1 = 2,   // Identifier Mask
            IDMSK2 = 4,   // Identifier Mask
            IDMSK3 = 8,   // Identifier Mask
            IDMSK4 = 16,  // Identifier Mask
            IDMSK5 = 32,  // Identifier Mask
            IDMSK6 = 64,  // Identifier Mask
            IDMSK7 = 128, // Identifier Mask
        };
    };

    // Identifier Mask Register 1
    struct CANIDM1 {
        static const uint8_t address = 0xf7;
        enum bits : uint8_t {
            IDMSK0 = 1,   // Identifier Mask
            IDMSK1 = 2,   // Identifier Mask
            IDMSK2 = 4,   // Identifier Mask
            IDMSK3 = 8,   // Identifier Mask
            IDMSK4 = 16,  // Identifier Mask
            IDMSK5 = 32,  // Identifier Mask
            IDMSK6 = 64,  // Identifier Mask
            IDMSK7 = 128, // Identifier Mask
        };
    };

    // Time Stamp Register
    struct CANSTM {
        static const uint16_t address = 0xf8;
        enum bits : uint8_t {
            TIMSTM0 = 1,   // Time Stamp Count
            TIMSTM1 = 2,   // Time Stamp Count
            TIMSTM2 = 4,   // Time Stamp Count
            TIMSTM3 = 8,   // Time Stamp Count
            TIMSTM4 = 16,  // Time Stamp Count
            TIMSTM5 = 32,  // Time Stamp Count
            TIMSTM6 = 64,  // Time Stamp Count
            TIMSTM7 = 128, // Time Stamp Count
        };
    };

    // Message Data Register
    struct CANMSG {
        static const uint8_t address = 0xfa;
        enum bits : uint8_t {
            MSG0 = 1,   // Message Data
            MSG1 = 2,   // Message Data
            MSG2 = 4,   // Message Data
            MSG3 = 8,   // Message Data
            MSG4 = 16,  // Message Data
            MSG5 = 32,  // Message Data
            MSG6 = 64,  // Message Data
            MSG7 = 128, // Message Data
        };
    };

}

#endif
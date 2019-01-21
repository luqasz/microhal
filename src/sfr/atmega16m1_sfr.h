#ifndef atmega16m1_sfr_h
#define atmega16m1_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega16M1
*/

namespace SFR {

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

    // Port E Input Pins
    struct PINE {
        static const uint8_t address = 0x2c;
    };

    // Port E Data Direction Register
    struct DDRE {
        static const uint8_t address = 0x2d;
    };

    // Port E Data Register
    struct PORTE {
        static const uint8_t address = 0x2e;
    };

    // Timer/Counter0 Interrupt Flag register
    struct TIFR0 {
        static const uint8_t address = 0x35;
        enum bits : uint8_t {
            TOV0  = 1, // Timer/Counter0 Overflow Flag
            OCF0A = 2, // Timer/Counter0 Output Compare Flag 0A
            OCF0B = 4, // Timer/Counter0 Output Compare Flag 0B
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR1 {
        static const uint8_t address = 0x36;
        enum bits : uint8_t {
            TOV1  = 1,  // Timer/Counter1 Overflow Flag
            OCF1A = 2,  // Output Compare Flag 1A
            OCF1B = 4,  // Output Compare Flag 1B
            ICF1  = 32, // Input Capture Flag 1
        };
    };

    // General Purpose IO Register 1
    struct GPIOR1 {
        static const uint8_t address = 0x39;
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
        static const uint8_t address = 0x3a;
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

    // Pin Change Interrupt Flag Register
    struct PCIFR {
        static const uint8_t address = 0x3b;
        enum bits : uint8_t {
            PCIF0 = 1, // Pin Change Interrupt Flags
            PCIF1 = 2, // Pin Change Interrupt Flags
            PCIF2 = 4, // Pin Change Interrupt Flags
            PCIF3 = 8, // Pin Change Interrupt Flags
        };
    };

    // External Interrupt Flag Register
    struct EIFR {
        static const uint8_t address = 0x3c;
        enum bits : uint8_t {
            INTF0 = 1, // External Interrupt Flags
            INTF1 = 2, // External Interrupt Flags
            INTF2 = 4, // External Interrupt Flags
            INTF3 = 8, // External Interrupt Flags
        };
    };

    // External Interrupt Mask Register
    struct EIMSK {
        static const uint8_t address = 0x3d;
        enum bits : uint8_t {
            INT0 = 1, // External Interrupt Request 3 Enable
            INT1 = 2, // External Interrupt Request 3 Enable
            INT2 = 4, // External Interrupt Request 3 Enable
            INT3 = 8, // External Interrupt Request 3 Enable
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
            EERE  = 1,  // EEPROM Read Enable
            EEWE  = 2,  // EEPROM Write Enable
            EEMWE = 4,  // EEPROM Master Write Enable
            EERIE = 8,  // EEPROM Ready Interrupt Enable
            EEPM0 = 16, // EEPROM Programming mode
            EEPM1 = 32, // EEPROM Programming mode
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

    // EEPROM Read/Write Access
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

    // General Timer/Counter Control Register
    struct GTCCR {
        static const uint8_t address = 0x43;
        enum bits : uint8_t {
            PSRSYNC = 1,   // Timer/Counter Prescaler Reset
            ICPSEL1 = 64,  // Timer/Counter1 Input Capture Selection
            TSM     = 128, // Timer/Counter Synchronization Mode
        };
    };

    // Timer/Counter  Control Register A
    struct TCCR0A {
        static const uint8_t address = 0x44;
        enum bits : uint8_t {
            WGM00  = 1,   // Waveform Generation Mode
            WGM01  = 2,   // Waveform Generation Mode
            COM0B0 = 16,  // Compare Output Mode for Channel B
            COM0B1 = 32,  // Compare Output Mode for Channel B
            COM0A0 = 64,  // Compare Output Mode for Channel A
            COM0A1 = 128, // Compare Output Mode for Channel A
        };
    };

    // Timer/Counter Control Register B
    struct TCCR0B {
        static const uint8_t address = 0x45;
        enum bits : uint8_t {
            CS00  = 1,   // Clock Select
            CS01  = 2,   // Clock Select
            CS02  = 4,   // Clock Select
            WGM02 = 8,   //
            FOC0B = 64,  // Force Output Compare B
            FOC0A = 128, // Force Output Compare A
        };
    };

    // Timer/Counter0
    struct TCNT0 {
        static const uint8_t address = 0x46;
        enum bits : uint8_t {
            TCNT00 = 1,   // Timer/Counter0 bits
            TCNT01 = 2,   // Timer/Counter0 bits
            TCNT02 = 4,   // Timer/Counter0 bits
            TCNT03 = 8,   // Timer/Counter0 bits
            TCNT04 = 16,  // Timer/Counter0 bits
            TCNT05 = 32,  // Timer/Counter0 bits
            TCNT06 = 64,  // Timer/Counter0 bits
            TCNT07 = 128, // Timer/Counter0 bits
        };
    };

    // Timer/Counter0 Output Compare Register A
    struct OCR0A {
        static const uint8_t address = 0x47;
        enum bits : uint8_t {
            OCR0A0 = 1,   // Timer/Counter0 Output Compare bits
            OCR0A1 = 2,   // Timer/Counter0 Output Compare bits
            OCR0A2 = 4,   // Timer/Counter0 Output Compare bits
            OCR0A3 = 8,   // Timer/Counter0 Output Compare bits
            OCR0A4 = 16,  // Timer/Counter0 Output Compare bits
            OCR0A5 = 32,  // Timer/Counter0 Output Compare bits
            OCR0A6 = 64,  // Timer/Counter0 Output Compare bits
            OCR0A7 = 128, // Timer/Counter0 Output Compare bits
        };
    };

    // Timer/Counter0 Output Compare Register B
    struct OCR0B {
        static const uint8_t address = 0x48;
        enum bits : uint8_t {
            OCR0B0 = 1,   // Timer/Counter0 Output Compare bits
            OCR0B1 = 2,   // Timer/Counter0 Output Compare bits
            OCR0B2 = 4,   // Timer/Counter0 Output Compare bits
            OCR0B3 = 8,   // Timer/Counter0 Output Compare bits
            OCR0B4 = 16,  // Timer/Counter0 Output Compare bits
            OCR0B5 = 32,  // Timer/Counter0 Output Compare bits
            OCR0B6 = 64,  // Timer/Counter0 Output Compare bits
            OCR0B7 = 128, // Timer/Counter0 Output Compare bits
        };
    };

    // PLL Control And Status Register
    struct PLLCSR {
        static const uint8_t address = 0x49;
        enum bits : uint8_t {
            PLOCK = 1, // PLL Lock Detector
            PLLE  = 2, // PLL Enable
            PLLF  = 4, // PLL Factor
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
    };

    // Analog Comparator Status Register
    struct ACSR {
        static const uint8_t address = 0x50;
        enum bits : uint8_t {
            AC0O  = 1,   // Analog Comparator 0 Output Bit
            AC1O  = 2,   // Analog Comparator 1 Output Bit
            AC2O  = 4,   // Analog Comparator 2 Output Bit
            AC3O  = 8,   // Analog Comparator 3 Output Bit
            AC0IF = 16,  // Analog Comparator 0 Interrupt Flag Bit
            AC1IF = 32,  // Analog Comparator 1  Interrupt Flag Bit
            AC2IF = 64,  // Analog Comparator 2 Interrupt Flag Bit
            AC3IF = 128, // Analog Comparator 3 Interrupt Flag Bit
        };
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
            PORF  = 1, // Power-on reset flag
            EXTRF = 2, // External Reset Flag
            BORF  = 4, // Brown-out Reset Flag
            WDRF  = 8, // Watchdog Reset Flag
        };
    };

    // MCU Control Register
    struct MCUCR {
        static const uint8_t address = 0x55;
        enum bits : uint8_t {
            IVCE  = 1,   // Interrupt Vector Change Enable
            IVSEL = 2,   // Interrupt Vector Select
            PUD   = 16,  // Pull-up disable
            SPIPS = 128, // SPI Pin Select
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
            SIGRD  = 32,  // Signature Row Read
            RWWSB  = 64,  // Read While Write Section Busy
            SPMIE  = 128, // SPM Interrupt Enable
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
    struct WDTCSR {
        static const uint8_t address = 0x60;
        enum bits : uint8_t {
            WDP0 = 1,   // Watchdog Timer Prescaler Bits
            WDP1 = 2,   // Watchdog Timer Prescaler Bits
            WDP2 = 4,   // Watchdog Timer Prescaler Bits
            WDE  = 8,   // Watch Dog Enable
            WDCE = 16,  // Watchdog Change Enable
            WDP3 = 32,  // Watchdog Timer Prescaler Bits
            WDIE = 64,  // Watchdog Timeout Interrupt Enable
            WDIF = 128, // Watchdog Timeout Interrupt Flag
        };
    };

    //
    struct CLKPR {
        static const uint8_t address = 0x61;
        enum bits : uint8_t {
            CLKPS0 = 1,   // Clock Prescaler Select
            CLKPS1 = 2,   // Clock Prescaler Select
            CLKPS2 = 4,   // Clock Prescaler Select
            CLKPS3 = 8,   // Clock Prescaler Select
            CLKPCE = 128, // Clock Prescaler Change Enable
        };
    };

    // Power Reduction Register
    struct PRR {
        static const uint8_t address = 0x64;
        enum bits : uint8_t {
            PRADC  = 1,  // Power Reduction ADC
            PRLIN  = 2,  // Power Reduction LIN UART
            PRSPI  = 4,  // Power Reduction Serial Peripheral Interface
            PRTIM0 = 8,  // Power Reduction Timer/Counter0
            PRTIM1 = 16, // Power Reduction Timer/Counter1
            PRPSC  = 32, // Power Reduction PSC
            PRCAN  = 64, // Power Reduction CAN
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

    // Pin Change Interrupt Control Register
    struct PCICR {
        static const uint8_t address = 0x68;
        enum bits : uint8_t {
            PCIE0 = 1, // Pin Change Interrupt Enables
            PCIE1 = 2, // Pin Change Interrupt Enables
            PCIE2 = 4, // Pin Change Interrupt Enables
            PCIE3 = 8, // Pin Change Interrupt Enables
        };
    };

    // External Interrupt Control Register
    struct EICRA {
        static const uint8_t address = 0x69;
        enum bits : uint8_t {
            ISC00 = 1,   // External Interrupt Sense Control 0 Bits
            ISC01 = 2,   // External Interrupt Sense Control 0 Bits
            ISC10 = 4,   // External Interrupt Sense Control 1 Bits
            ISC11 = 8,   // External Interrupt Sense Control 1 Bits
            ISC20 = 16,  // External Interrupt Sense Control Bit
            ISC21 = 32,  // External Interrupt Sense Control Bit
            ISC30 = 64,  // External Interrupt Sense Control Bit
            ISC31 = 128, // External Interrupt Sense Control Bit
        };
    };

    // Pin Change Mask Register 0
    struct PCMSK0 {
        static const uint8_t address = 0x6a;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Enable Masks
            PCINT1 = 2,   // Pin Change Enable Masks
            PCINT2 = 4,   // Pin Change Enable Masks
            PCINT3 = 8,   // Pin Change Enable Masks
            PCINT4 = 16,  // Pin Change Enable Masks
            PCINT5 = 32,  // Pin Change Enable Masks
            PCINT6 = 64,  // Pin Change Enable Masks
            PCINT7 = 128, // Pin Change Enable Masks
        };
    };

    // Pin Change Mask Register 1
    struct PCMSK1 {
        static const uint8_t address = 0x6b;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Enable Masks
            PCINT1 = 2,   // Pin Change Enable Masks
            PCINT2 = 4,   // Pin Change Enable Masks
            PCINT3 = 8,   // Pin Change Enable Masks
            PCINT4 = 16,  // Pin Change Enable Masks
            PCINT5 = 32,  // Pin Change Enable Masks
            PCINT6 = 64,  // Pin Change Enable Masks
            PCINT7 = 128, // Pin Change Enable Masks
        };
    };

    // Pin Change Mask Register 2
    struct PCMSK2 {
        static const uint8_t address = 0x6c;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Enable Masks
            PCINT1 = 2,   // Pin Change Enable Masks
            PCINT2 = 4,   // Pin Change Enable Masks
            PCINT3 = 8,   // Pin Change Enable Masks
            PCINT4 = 16,  // Pin Change Enable Masks
            PCINT5 = 32,  // Pin Change Enable Masks
            PCINT6 = 64,  // Pin Change Enable Masks
            PCINT7 = 128, // Pin Change Enable Masks
        };
    };

    // Pin Change Mask Register 3
    struct PCMSK3 {
        static const uint8_t address = 0x6d;
        enum bits : uint8_t {
            PCINT0 = 1, // Pin Change Enable Masks
            PCINT1 = 2, // Pin Change Enable Masks
            PCINT2 = 4, // Pin Change Enable Masks
        };
    };

    // Timer/Counter0 Interrupt Mask Register
    struct TIMSK0 {
        static const uint8_t address = 0x6e;
        enum bits : uint8_t {
            TOIE0  = 1, // Timer/Counter0 Overflow Interrupt Enable
            OCIE0A = 2, // Timer/Counter0 Output Compare Match A Interrupt Enable
            OCIE0B = 4, // Timer/Counter0 Output Compare Match B Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Mask Register
    struct TIMSK1 {
        static const uint8_t address = 0x6f;
        enum bits : uint8_t {
            TOIE1  = 1,  // Timer/Counter1 Overflow Interrupt Enable
            OCIE1A = 2,  // Timer/Counter1 Output CompareA Match Interrupt Enable
            OCIE1B = 4,  // Timer/Counter1 Output CompareB Match Interrupt Enable
            ICIE1  = 32, // Timer/Counter1 Input Capture Interrupt Enable
        };
    };

    // Amplifier 0 Control and Status Register
    struct AMP0CSR {
        static const uint8_t address = 0x75;
        enum bits : uint8_t {
            AMP0TS0 = 1,   // Amplifier 0 Clock Source Selection
            AMP0TS1 = 2,   // Amplifier 0 Clock Source Selection
            AMP0TS2 = 4,   // Amplifier 0 Clock Source Selection
            AMPCMP0 = 8,   // Amplifier 0 - Comparator 0 connection
            AMP0G0  = 16,  // Amplifier 0 Gain Selection
            AMP0G1  = 32,  // Amplifier 0 Gain Selection
            AMP0IS  = 64,  // Amplifier 0 Input Shunt
            AMP0EN  = 128, // Amplifier 0 Enable
        };
    };

    // Amplifier 1 Control and Status Register
    struct AMP1CSR {
        static const uint8_t address = 0x76;
        enum bits : uint8_t {
            AMP1TS0 = 1,   // Amplifier 1 Clock Source Selection
            AMP1TS1 = 2,   // Amplifier 1 Clock Source Selection
            AMP1TS2 = 4,   // Amplifier 1 Clock Source Selection
            AMPCMP1 = 8,   // Amplifier 1 - Comparator 1 Connection
            AMP1G0  = 16,  // Amplifier 1 Gain Selection
            AMP1G1  = 32,  // Amplifier 1 Gain Selection
            AMP1IS  = 64,  // Amplifier 1 Input Shunt
            AMP1EN  = 128, // Amplifier 1 Enable
        };
    };

    // Amplifier 2 Control and Status Register
    struct AMP2CSR {
        static const uint8_t address = 0x77;
        enum bits : uint8_t {
            AMP2TS0 = 1,   // Amplifier 2 Clock Source Selection
            AMP2TS1 = 2,   // Amplifier 2 Clock Source Selection
            AMP2TS2 = 4,   // Amplifier 2 Clock Source Selection
            AMPCMP2 = 8,   // Amplifier 2 - Comparator 2 Connection
            AMP2G0  = 16,  // Amplifier 2 Gain Selection
            AMP2G1  = 32,  // Amplifier 2 Gain Selection
            AMP2IS  = 64,  // Amplifier 2 Input Shunt
            AMP2EN  = 128, // Amplifier 2 Enable
        };
    };

    // ADC Data Register Bytes
    struct ADC {
        static const uint16_t address = 0x78;
        enum bits : uint8_t {
            ADC0 = 1,   // ADC Data bits
            ADC1 = 2,   // ADC Data bits
            ADC2 = 4,   // ADC Data bits
            ADC3 = 8,   // ADC Data bits
            ADC4 = 16,  // ADC Data bits
            ADC5 = 32,  // ADC Data bits
            ADC6 = 64,  // ADC Data bits
            ADC7 = 128, // ADC Data bits
        };
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
            ADTS0  = 1,   // ADC Auto Trigger Sources
            ADTS1  = 2,   // ADC Auto Trigger Sources
            ADTS2  = 4,   // ADC Auto Trigger Sources
            ADTS3  = 8,   // ADC Auto Trigger Sources
            AREFEN = 32,  // Analog Reference pin Enable
            ISRCEN = 64,  // Current Source Enable
            ADHSM  = 128, // ADC High Speed Mode
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

    // Digital Input Disable Register 0
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

    // Digital Input Disable Register 0
    struct DIDR1 {
        static const uint8_t address = 0x7f;
        enum bits : uint8_t {
            ADC8D  = 1,  // ADC8 Pin Digital input Disable
            ADC9D  = 2,  // ADC9 Pin Digital input Disable
            ADC10D = 4,  // ADC10 Pin Digital input Disable
            AMP0ND = 8,  // AMP0N Pin Digital input Disable
            AMP0PD = 16, // AMP0P Pin Digital input Disable
            ACMP0D = 32, // ACMP0 Pin Digital input Disable
            AMP2PD = 64, // AMP2P Pin Digital input Disable
        };
    };

    // Timer/Counter1 Control Register A
    struct TCCR1A {
        static const uint8_t address = 0x80;
        enum bits : uint8_t {
            WGM10  = 1,   // Waveform Generation Mode
            WGM11  = 2,   // Waveform Generation Mode
            COM1B0 = 16,  // Compare Output Mode for Channel B
            COM1B1 = 32,  // Compare Output Mode for Channel B
            COM1A0 = 64,  // Compare Output Mode for Channel A
            COM1A1 = 128, // Compare Output Mode for Channel A
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

    // Timer/Counter1 Control Register C
    struct TCCR1C {
        static const uint8_t address = 0x82;
        enum bits : uint8_t {
            FOC1B = 64,  // Force Output Compare for Channel B
            FOC1A = 128, // Force Output Compare for Channel A
        };
    };

    // Timer/Counter1 Bytes
    struct TCNT1 {
        static const uint16_t address = 0x84;
        enum bits : uint8_t {
            TCNT10 = 1,   // Timer/Counter1 bits
            TCNT11 = 2,   // Timer/Counter1 bits
            TCNT12 = 4,   // Timer/Counter1 bits
            TCNT13 = 8,   // Timer/Counter1 bits
            TCNT14 = 16,  // Timer/Counter1 bits
            TCNT15 = 32,  // Timer/Counter1 bits
            TCNT16 = 64,  // Timer/Counter1 bits
            TCNT17 = 128, // Timer/Counter1 bits
        };
    };

    // Timer/Counter1 Input Capture Register
    struct ICR1 {
        static const uint16_t address = 0x86;
        enum bits : uint8_t {
            ICR10 = 1,   // Timer/Counter1 Input Capture bits
            ICR11 = 2,   // Timer/Counter1 Input Capture bits
            ICR12 = 4,   // Timer/Counter1 Input Capture bits
            ICR13 = 8,   // Timer/Counter1 Input Capture bits
            ICR14 = 16,  // Timer/Counter1 Input Capture bits
            ICR15 = 32,  // Timer/Counter1 Input Capture bits
            ICR16 = 64,  // Timer/Counter1 Input Capture bits
            ICR17 = 128, // Timer/Counter1 Input Capture bits
        };
    };

    // Timer/Counter1 Output Compare Register A
    struct OCR1A {
        static const uint16_t address = 0x88;
        enum bits : uint8_t {
            OCR1A0 = 1,   // Timer/Counter1 Output Compare bits
            OCR1A1 = 2,   // Timer/Counter1 Output Compare bits
            OCR1A2 = 4,   // Timer/Counter1 Output Compare bits
            OCR1A3 = 8,   // Timer/Counter1 Output Compare bits
            OCR1A4 = 16,  // Timer/Counter1 Output Compare bits
            OCR1A5 = 32,  // Timer/Counter1 Output Compare bits
            OCR1A6 = 64,  // Timer/Counter1 Output Compare bits
            OCR1A7 = 128, // Timer/Counter1 Output Compare bits
        };
    };

    // Timer/Counter1 Output Compare Register B
    struct OCR1B {
        static const uint16_t address = 0x8a;
        enum bits : uint8_t {
            OCR1B0 = 1,   // Timer/Counter1 Output Compare bits
            OCR1B1 = 2,   // Timer/Counter1 Output Compare bits
            OCR1B2 = 4,   // Timer/Counter1 Output Compare bits
            OCR1B3 = 8,   // Timer/Counter1 Output Compare bits
            OCR1B4 = 16,  // Timer/Counter1 Output Compare bits
            OCR1B5 = 32,  // Timer/Counter1 Output Compare bits
            OCR1B6 = 64,  // Timer/Counter1 Output Compare bits
            OCR1B7 = 128, // Timer/Counter1 Output Compare bits
        };
    };

    // DAC Control Register
    struct DACON {
        static const uint8_t address = 0x90;
        enum bits : uint8_t {
            DAEN  = 1,   // DAC Enable Bit
            DAOE  = 2,   // DAC Output Enable
            DALA  = 4,   // DAC Left Adjust
            DATS0 = 16,  // DAC Trigger Selection Bits
            DATS1 = 32,  // DAC Trigger Selection Bits
            DATS2 = 64,  // DAC Trigger Selection Bits
            DAATE = 128, // DAC Auto Trigger Enable Bit
        };
    };

    // DAC Data Register
    struct DAC {
        static const uint8_t address = 0x91;
        enum bits : uint8_t {
            DAC0 = 1,   // DAC Data Register Bits
            DAC1 = 2,   // DAC Data Register Bits
            DAC2 = 4,   // DAC Data Register Bits
            DAC3 = 8,   // DAC Data Register Bits
            DAC4 = 16,  // DAC Data Register Bits
            DAC5 = 32,  // DAC Data Register Bits
            DAC6 = 64,  // DAC Data Register Bits
            DAC7 = 128, // DAC Data Register Bits
        };
    };

    // Analog Comparator 0 Control Register
    struct AC0CON {
        static const uint8_t address = 0x94;
        enum bits : uint8_t {
            AC0M0   = 1,   // Analog Comparator 0 Multiplexer Register
            AC0M1   = 2,   // Analog Comparator 0 Multiplexer Register
            AC0M2   = 4,   // Analog Comparator 0 Multiplexer Register
            ACCKSEL = 8,   // Analog Comparator Clock Select
            AC0IS0  = 16,  // Analog Comparator 0  Interrupt Select Bits
            AC0IS1  = 32,  // Analog Comparator 0  Interrupt Select Bits
            AC0IE   = 64,  // Analog Comparator 0 Interrupt Enable Bit
            AC0EN   = 128, // Analog Comparator 0 Enable Bit
        };
    };

    // Analog Comparator 1 Control Register
    struct AC1CON {
        static const uint8_t address = 0x95;
        enum bits : uint8_t {
            AC1M0  = 1,   // Analog Comparator 1 Multiplexer Register
            AC1M1  = 2,   // Analog Comparator 1 Multiplexer Register
            AC1M2  = 4,   // Analog Comparator 1 Multiplexer Register
            AC1ICE = 8,   // Analog Comparator 1 Interrupt Capture Enable Bit
            AC1IS0 = 16,  // Analog Comparator 1  Interrupt Select Bit
            AC1IS1 = 32,  // Analog Comparator 1  Interrupt Select Bit
            AC1IE  = 64,  // Analog Comparator 1 Interrupt Enable Bit
            AC1EN  = 128, // Analog Comparator 1 Enable Bit
        };
    };

    // Analog Comparator 2 Control Register
    struct AC2CON {
        static const uint8_t address = 0x96;
        enum bits : uint8_t {
            AC2M0  = 1,   // Analog Comparator 2 Multiplexer Register
            AC2M1  = 2,   // Analog Comparator 2 Multiplexer Register
            AC2M2  = 4,   // Analog Comparator 2 Multiplexer Register
            AC2IS0 = 16,  // Analog Comparator 2  Interrupt Select Bit
            AC2IS1 = 32,  // Analog Comparator 2  Interrupt Select Bit
            AC2IE  = 64,  // Analog Comparator 2 Interrupt Enable Bit
            AC2EN  = 128, // Analog Comparator 2 Enable Bit
        };
    };

    // Analog Comparator 3 Control Register
    struct AC3CON {
        static const uint8_t address = 0x97;
        enum bits : uint8_t {
            AC3M0  = 1,   // Analog Comparator 3 Multiplexer Register
            AC3M1  = 2,   // Analog Comparator 3 Multiplexer Register
            AC3M2  = 4,   // Analog Comparator 3 Multiplexer Register
            AC3IS0 = 16,  // Analog Comparator 3  Interrupt Select Bit
            AC3IS1 = 32,  // Analog Comparator 3  Interrupt Select Bit
            AC3IE  = 64,  // Analog Comparator 3 Interrupt Enable Bit
            AC3EN  = 128, // Analog Comparator 3 Enable Bit
        };
    };

    // PSC Module 0 Output Compare SA Register
    struct POCR0SA {
        static const uint16_t address = 0xa0;
        enum bits : uint8_t {
            POCR0SA0 = 1,   // PSC Output Compare SA bits
            POCR0SA1 = 2,   // PSC Output Compare SA bits
            POCR0SA2 = 4,   // PSC Output Compare SA bits
            POCR0SA3 = 8,   // PSC Output Compare SA bits
            POCR0SA4 = 16,  // PSC Output Compare SA bits
            POCR0SA5 = 32,  // PSC Output Compare SA bits
            POCR0SA6 = 64,  // PSC Output Compare SA bits
            POCR0SA7 = 128, // PSC Output Compare SA bits
        };
    };

    // PSC Module 0 Output Compare RA Register
    struct POCR0RA {
        static const uint16_t address = 0xa2;
        enum bits : uint8_t {
            POCR0RA0 = 1,   // PSC Output Compare RA bits
            POCR0RA1 = 2,   // PSC Output Compare RA bits
            POCR0RA2 = 4,   // PSC Output Compare RA bits
            POCR0RA3 = 8,   // PSC Output Compare RA bits
            POCR0RA4 = 16,  // PSC Output Compare RA bits
            POCR0RA5 = 32,  // PSC Output Compare RA bits
            POCR0RA6 = 64,  // PSC Output Compare RA bits
            POCR0RA7 = 128, // PSC Output Compare RA bits
        };
    };

    // PSC Module 0 Output Compare SB Register
    struct POCR0SB {
        static const uint16_t address = 0xa4;
        enum bits : uint8_t {
            POCR0SB0 = 1,   // PSC Output Compare SB bits
            POCR0SB1 = 2,   // PSC Output Compare SB bits
            POCR0SB2 = 4,   // PSC Output Compare SB bits
            POCR0SB3 = 8,   // PSC Output Compare SB bits
            POCR0SB4 = 16,  // PSC Output Compare SB bits
            POCR0SB5 = 32,  // PSC Output Compare SB bits
            POCR0SB6 = 64,  // PSC Output Compare SB bits
            POCR0SB7 = 128, // PSC Output Compare SB bits
        };
    };

    // PSC Module 1 Output Compare SA Register
    struct POCR1SA {
        static const uint16_t address = 0xa6;
        enum bits : uint8_t {
            POCR1SA0 = 1,   // PSC Output Compare SA bits
            POCR1SA1 = 2,   // PSC Output Compare SA bits
            POCR1SA2 = 4,   // PSC Output Compare SA bits
            POCR1SA3 = 8,   // PSC Output Compare SA bits
            POCR1SA4 = 16,  // PSC Output Compare SA bits
            POCR1SA5 = 32,  // PSC Output Compare SA bits
            POCR1SA6 = 64,  // PSC Output Compare SA bits
            POCR1SA7 = 128, // PSC Output Compare SA bits
        };
    };

    // PSC Module 1 Output Compare RA Register
    struct POCR1RA {
        static const uint16_t address = 0xa8;
        enum bits : uint8_t {
            POCR1RA0 = 1,   // PSC Output Compare RA bits
            POCR1RA1 = 2,   // PSC Output Compare RA bits
            POCR1RA2 = 4,   // PSC Output Compare RA bits
            POCR1RA3 = 8,   // PSC Output Compare RA bits
            POCR1RA4 = 16,  // PSC Output Compare RA bits
            POCR1RA5 = 32,  // PSC Output Compare RA bits
            POCR1RA6 = 64,  // PSC Output Compare RA bits
            POCR1RA7 = 128, // PSC Output Compare RA bits
        };
    };

    // PSC Module 1 Output Compare SB Register
    struct POCR1SB {
        static const uint16_t address = 0xaa;
        enum bits : uint8_t {
            POCR1SB0 = 1,   // PSC Output Compare SB bits
            POCR1SB1 = 2,   // PSC Output Compare SB bits
            POCR1SB2 = 4,   // PSC Output Compare SB bits
            POCR1SB3 = 8,   // PSC Output Compare SB bits
            POCR1SB4 = 16,  // PSC Output Compare SB bits
            POCR1SB5 = 32,  // PSC Output Compare SB bits
            POCR1SB6 = 64,  // PSC Output Compare SB bits
            POCR1SB7 = 128, // PSC Output Compare SB bits
        };
    };

    // PSC Module 2 Output Compare SA Register
    struct POCR2SA {
        static const uint16_t address = 0xac;
        enum bits : uint8_t {
            POCR2SA0 = 1,   // PSC Output Compare SA bits
            POCR2SA1 = 2,   // PSC Output Compare SA bits
            POCR2SA2 = 4,   // PSC Output Compare SA bits
            POCR2SA3 = 8,   // PSC Output Compare SA bits
            POCR2SA4 = 16,  // PSC Output Compare SA bits
            POCR2SA5 = 32,  // PSC Output Compare SA bits
            POCR2SA6 = 64,  // PSC Output Compare SA bits
            POCR2SA7 = 128, // PSC Output Compare SA bits
        };
    };

    // PSC Module 2 Output Compare RA Register
    struct POCR2RA {
        static const uint16_t address = 0xae;
        enum bits : uint8_t {
            POCR2RA0 = 1,   // PSC Output Compare RA bits
            POCR2RA1 = 2,   // PSC Output Compare RA bits
            POCR2RA2 = 4,   // PSC Output Compare RA bits
            POCR2RA3 = 8,   // PSC Output Compare RA bits
            POCR2RA4 = 16,  // PSC Output Compare RA bits
            POCR2RA5 = 32,  // PSC Output Compare RA bits
            POCR2RA6 = 64,  // PSC Output Compare RA bits
            POCR2RA7 = 128, // PSC Output Compare RA bits
        };
    };

    // PSC Module 2 Output Compare SB Register
    struct POCR2SB {
        static const uint16_t address = 0xb0;
        enum bits : uint8_t {
            POCR2SB0 = 1,   // PSC Output Compare SB bits
            POCR2SB1 = 2,   // PSC Output Compare SB bits
            POCR2SB2 = 4,   // PSC Output Compare SB bits
            POCR2SB3 = 8,   // PSC Output Compare SB bits
            POCR2SB4 = 16,  // PSC Output Compare SB bits
            POCR2SB5 = 32,  // PSC Output Compare SB bits
            POCR2SB6 = 64,  // PSC Output Compare SB bits
            POCR2SB7 = 128, // PSC Output Compare SB bits
        };
    };

    // PSC Output Compare RB Register
    struct POCR_RB {
        static const uint16_t address = 0xb2;
        enum bits : uint8_t {
            POCR_RB0 = 1,   // PSC Output Compare RB bits
            POCR_RB1 = 2,   // PSC Output Compare RB bits
            POCR_RB2 = 4,   // PSC Output Compare RB bits
            POCR_RB3 = 8,   // PSC Output Compare RB bits
            POCR_RB4 = 16,  // PSC Output Compare RB bits
            POCR_RB5 = 32,  // PSC Output Compare RB bits
            POCR_RB6 = 64,  // PSC Output Compare RB bits
            POCR_RB7 = 128, // PSC Output Compare RB bits
        };
    };

    // PSC Synchro Configuration
    struct PSYNC {
        static const uint8_t address = 0xb4;
        enum bits : uint8_t {
            PSYNC00 = 1,  // Selection of Synchronization Out for ADC
            PSYNC01 = 2,  // Selection of Synchronization Out for ADC
            PSYNC10 = 4,  // Selection of Synchronization Out for ADC
            PSYNC11 = 8,  // Selection of Synchronization Out for ADC
            PSYNC20 = 16, // Selection of Synchronization Out for ADC
            PSYNC21 = 32, // Selection of Synchronization Out for ADC
        };
    };

    // PSC Configuration Register
    struct PCNF {
        static const uint8_t address = 0xb5;
        enum bits : uint8_t {
            POPA   = 4,  // PSC Output A Polarity
            POPB   = 8,  // PSC Output B Polarity
            PMODE  = 16, // PSC Mode
            PULOCK = 32, // PSC Update Lock
        };
    };

    // PSC Output Configuration
    struct POC {
        static const uint8_t address = 0xb6;
        enum bits : uint8_t {
            POEN0A = 1,  // PSC Output 0A Enable
            POEN0B = 2,  // PSC Output 0B Enable
            POEN1A = 4,  // PSC Output 1A Enable
            POEN1B = 8,  // PSC Output 1B Enable
            POEN2A = 16, // PSC Output 2A Enable
            POEN2B = 32, // PSC Output 2B Enable
        };
    };

    // PSC Control Register
    struct PCTL {
        static const uint8_t address = 0xb7;
        enum bits : uint8_t {
            PRUN    = 1,   // PSC Run
            PCCYC   = 2,   // PSC Complete Cycle
            PCLKSEL = 32,  // PSC Input Clock Select
            PPRE0   = 64,  // PSC Prescaler Select bits
            PPRE1   = 128, // PSC Prescaler Select bits
        };
    };

    // PSC Module 0 Input Control Register
    struct PMIC0 {
        static const uint8_t address = 0xb8;
        enum bits : uint8_t {
            PRFM00 = 1,   // PSC Module 0 Input Mode bits
            PRFM01 = 2,   // PSC Module 0 Input Mode bits
            PRFM02 = 4,   // PSC Module 0 Input Mode bits
            PAOC0  = 8,   // PSC Module 0 Asynchronous Output Control
            PFLTE0 = 16,  // PSC Module 0 Input Filter Enable
            PELEV0 = 32,  // PSC Module 0 Input Level Selector
            PISEL0 = 64,  // PSC Module 0 Input Select
            POVEN0 = 128, // PSC Module 0 Overlap Enable
        };
    };

    // PSC Module 1 Input Control Register
    struct PMIC1 {
        static const uint8_t address = 0xb9;
        enum bits : uint8_t {
            PRFM10 = 1,   // PSC Module 1 Input Mode bits
            PRFM11 = 2,   // PSC Module 1 Input Mode bits
            PRFM12 = 4,   // PSC Module 1 Input Mode bits
            PAOC1  = 8,   // PSC Module 1 Asynchronous Output Control
            PFLTE1 = 16,  // PSC Module 1 Input Filter Enable
            PELEV1 = 32,  // PSC Module 1 Input Level Selector
            PISEL1 = 64,  // PSC Module 1 Input Select
            POVEN1 = 128, // PSC Module 1 Overlap Enable
        };
    };

    // PSC Module 2 Input Control Register
    struct PMIC2 {
        static const uint8_t address = 0xba;
        enum bits : uint8_t {
            PRFM20 = 1,   // PSC Module 2 Input Mode bits
            PRFM21 = 2,   // PSC Module 2 Input Mode bits
            PRFM22 = 4,   // PSC Module 2 Input Mode bits
            PAOC2  = 8,   // PSC Module 2 Asynchronous Output Control
            PFLTE2 = 16,  // PSC Module 2 Input Filter Enable
            PELEV2 = 32,  // PSC Module 2 Input Level Selector
            PISEL2 = 64,  // PSC Module 2 Input Select
            POVEN2 = 128, // PSC Module 2 Overlap Enable
        };
    };

    // PSC Interrupt Mask Register
    struct PIM {
        static const uint8_t address = 0xbb;
        enum bits : uint8_t {
            PEOPE = 1, // PSC End of Cycle Interrupt Enable
            PEVE0 = 2, // External Event 2 Interrupt Enable
            PEVE1 = 4, // External Event 2 Interrupt Enable
            PEVE2 = 8, // External Event 2 Interrupt Enable
        };
    };

    // PSC Interrupt Flag Register
    struct PIFR {
        static const uint8_t address = 0xbc;
        enum bits : uint8_t {
            PEOP = 1, // PSC End of Cycle Interrupt
            PEV0 = 2, // PSC External Event 2 Interrupt
            PEV1 = 4, // PSC External Event 2 Interrupt
            PEV2 = 8, // PSC External Event 2 Interrupt
        };
    };

    // LIN Control Register
    struct LINCR {
        static const uint8_t address = 0xc8;
        enum bits : uint8_t {
            LCMD0  = 1,   // LIN Command and Mode bits
            LCMD1  = 2,   // LIN Command and Mode bits
            LCMD2  = 4,   // LIN Command and Mode bits
            LENA   = 8,   // LIN or UART Enable
            LCONF0 = 16,  // LIN Configuration bits
            LCONF1 = 32,  // LIN Configuration bits
            LIN13  = 64,  // LIN Standard
            LSWRES = 128, // Software Reset
        };
    };

    // LIN Status and Interrupt Register
    struct LINSIR {
        static const uint8_t address = 0xc9;
        enum bits : uint8_t {
            LRXOK  = 1,   // Receive Performed Interrupt
            LTXOK  = 2,   // Transmit Performed Interrupt
            LIDOK  = 4,   // Identifier Interrupt
            LERR   = 8,   // Error Interrupt
            LBUSY  = 16,  // Busy Signal
            LIDST0 = 32,  // Identifier Status bits
            LIDST1 = 64,  // Identifier Status bits
            LIDST2 = 128, // Identifier Status bits
        };
    };

    // LIN Enable Interrupt Register
    struct LINENIR {
        static const uint8_t address = 0xca;
        enum bits : uint8_t {
            LENRXOK = 1, // Enable Receive Performed Interrupt
            LENTXOK = 2, // Enable Transmit Performed Interrupt
            LENIDOK = 4, // Enable Identifier Interrupt
            LENERR  = 8, // Enable Error Interrupt
        };
    };

    // LIN Error Register
    struct LINERR {
        static const uint8_t address = 0xcb;
        enum bits : uint8_t {
            LBERR  = 1,   // Bit Error Flag
            LCERR  = 2,   // Checksum Error Flag
            LPERR  = 4,   // Parity Error Flag
            LSERR  = 8,   // Synchronization Error Flag
            LFERR  = 16,  // Framing Error Flag
            LOVERR = 32,  // Overrun Error Flag
            LTOERR = 64,  // Frame Time Out Error Flag
            LABORT = 128, // Abort Flag
        };
    };

    // LIN Bit Timing Register
    struct LINBTR {
        static const uint8_t address = 0xcc;
        enum bits : uint8_t {
            LBT0  = 1,   // LIN Bit Timing bits
            LBT1  = 2,   // LIN Bit Timing bits
            LBT2  = 4,   // LIN Bit Timing bits
            LBT3  = 8,   // LIN Bit Timing bits
            LBT4  = 16,  // LIN Bit Timing bits
            LBT5  = 32,  // LIN Bit Timing bits
            LDISR = 128, // Disable Bit Timing Resynchronization
        };
    };

    // LIN Baud Rate Register
    struct LINBRR {
        static const uint8_t address = 0xcd;
        enum bits : uint8_t {
            LDIV0 = 1,   //
            LDIV1 = 2,   //
            LDIV2 = 4,   //
            LDIV3 = 8,   //
            LDIV4 = 16,  //
            LDIV5 = 32,  //
            LDIV6 = 64,  //
            LDIV7 = 128, //
        };
    };

    // LIN Data Length Register
    struct LINDLR {
        static const uint8_t address = 0xcf;
        enum bits : uint8_t {
            LRXDL0 = 1,   // LIN Receive Data Length bits
            LRXDL1 = 2,   // LIN Receive Data Length bits
            LRXDL2 = 4,   // LIN Receive Data Length bits
            LRXDL3 = 8,   // LIN Receive Data Length bits
            LTXDL0 = 16,  // LIN Transmit Data Length bits
            LTXDL1 = 32,  // LIN Transmit Data Length bits
            LTXDL2 = 64,  // LIN Transmit Data Length bits
            LTXDL3 = 128, // LIN Transmit Data Length bits
        };
    };

    // LIN Identifier Register
    struct LINIDR {
        static const uint8_t address = 0xd0;
        enum bits : uint8_t {
            LID0 = 1,   // Identifier bit 5 or Data Length bits
            LID1 = 2,   // Identifier bit 5 or Data Length bits
            LID2 = 4,   // Identifier bit 5 or Data Length bits
            LID3 = 8,   // Identifier bit 5 or Data Length bits
            LID4 = 16,  // Identifier bit 5 or Data Length bits
            LID5 = 32,  // Identifier bit 5 or Data Length bits
            LP0  = 64,  // Parity bits
            LP1  = 128, // Parity bits
        };
    };

    // LIN Data Buffer Selection Register
    struct LINSEL {
        static const uint8_t address = 0xd1;
        enum bits : uint8_t {
            LINDX0 = 1, // FIFO LIN Data Buffer Index bits
            LINDX1 = 2, // FIFO LIN Data Buffer Index bits
            LINDX2 = 4, // FIFO LIN Data Buffer Index bits
            LAINC  = 8, // Auto Increment of Data Buffer Index (Active Low)
        };
    };

    // LIN Data Register
    struct LINDAT {
        static const uint8_t address = 0xd2;
        enum bits : uint8_t {
            LDATA0 = 1,   // LIN Data In / Data out
            LDATA1 = 2,   // LIN Data In / Data out
            LDATA2 = 4,   // LIN Data In / Data out
            LDATA3 = 8,   // LIN Data In / Data out
            LDATA4 = 16,  // LIN Data In / Data out
            LDATA5 = 32,  // LIN Data In / Data out
            LDATA6 = 64,  // LIN Data In / Data out
            LDATA7 = 128, // LIN Data In / Data out
        };
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
            OVFG  = 64, // Overload Frame Flag
        };
    };

    // CAN General Interrupt Register Flags
    struct CANGIT {
        static const uint8_t address = 0xda;
        enum bits : uint8_t {
            AERG   = 1,   // Ackknowledgement Error General Flag
            FERG   = 2,   // Form Error General Flag
            CERG   = 4,   // CRC Error General Flag
            SERG   = 8,   // Stuff Error General Flag
            BXOK   = 16,  // Burst Receive Interrupt Flag
            OVRTIM = 32,  // Overrun CAN Timer Flag
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
            ENBOFF = 64,  // Enable Bus Off Interrupt
            ENIT   = 128, // Enable all Interrupts
        };
    };

    // Enable MOb Register 2
    struct CANEN2 {
        static const uint8_t address = 0xdc;
        enum bits : uint8_t {
            ENMOB0 = 1,  // Enable MObs
            ENMOB1 = 2,  // Enable MObs
            ENMOB2 = 4,  // Enable MObs
            ENMOB3 = 8,  // Enable MObs
            ENMOB4 = 16, // Enable MObs
            ENMOB5 = 32, // Enable MObs
        };
    };

    // Enable MOb Register 1(empty)
    struct CANEN1 {
        static const uint8_t address = 0xdd;
    };

    // Enable Interrupt MOb Register 2
    struct CANIE2 {
        static const uint8_t address = 0xde;
        enum bits : uint8_t {
            IEMOB0 = 1,  // Interrupt Enable  MObs
            IEMOB1 = 2,  // Interrupt Enable  MObs
            IEMOB2 = 4,  // Interrupt Enable  MObs
            IEMOB3 = 8,  // Interrupt Enable  MObs
            IEMOB4 = 16, // Interrupt Enable  MObs
            IEMOB5 = 32, // Interrupt Enable  MObs
        };
    };

    // Enable Interrupt MOb Register 1 (empty)
    struct CANIE1 {
        static const uint8_t address = 0xdf;
    };

    // CAN Status Interrupt MOb Register 2
    struct CANSIT2 {
        static const uint8_t address = 0xe0;
        enum bits : uint8_t {
            SIT0 = 1,  // Status of Interrupt MObs
            SIT1 = 2,  // Status of Interrupt MObs
            SIT2 = 4,  // Status of Interrupt MObs
            SIT3 = 8,  // Status of Interrupt MObs
            SIT4 = 16, // Status of Interrupt MObs
            SIT5 = 32, // Status of Interrupt MObs
        };
    };

    // CAN Status Interrupt MOb Register 1 (empty)
    struct CANSIT1 {
        static const uint8_t address = 0xe1;
    };

    // CAN Bit Timing Register 1
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

    // CAN Bit Timing Register 2
    struct CANBT2 {
        static const uint8_t address = 0xe3;
        enum bits : uint8_t {
            PRS0 = 2,  // Propagation Time Segment bits
            PRS1 = 4,  // Propagation Time Segment bits
            PRS2 = 8,  // Propagation Time Segment bits
            SJW0 = 32, // Re-Sync Jump Width bits
            SJW1 = 64, // Re-Sync Jump Width bits
        };
    };

    // CAN Bit Timing Register 3
    struct CANBT3 {
        static const uint8_t address = 0xe4;
        enum bits : uint8_t {
            SMP   = 1,  // Sample Type
            PHS10 = 2,  // Phase Segment 1 bits
            PHS11 = 4,  // Phase Segment 1 bits
            PHS12 = 8,  // Phase Segment 1 bits
            PHS20 = 16, // Phase Segment 2 bits
            PHS21 = 32, // Phase Segment 2 bits
            PHS22 = 64, // Phase Segment 2 bits
        };
    };

    // Timer Control Register
    struct CANTCON {
        static const uint8_t address = 0xe5;
        enum bits : uint8_t {
            TPRSC0 = 1,   // Timer Control bits
            TPRSC1 = 2,   // Timer Control bits
            TPRSC2 = 4,   // Timer Control bits
            TPRSC3 = 8,   // Timer Control bits
            TPRSC4 = 16,  // Timer Control bits
            TPRSC5 = 32,  // Timer Control bits
            TPRSC6 = 64,  // Timer Control bits
            TPRSC7 = 128, // Timer Control bits
        };
    };

    // Timer Register
    struct CANTIM {
        static const uint16_t address = 0xe6;
        enum bits : uint8_t {
            CANTIM0 = 1,   // Timer bits
            CANTIM1 = 2,   // Timer bits
            CANTIM2 = 4,   // Timer bits
            CANTIM3 = 8,   // Timer bits
            CANTIM4 = 16,  // Timer bits
            CANTIM5 = 32,  // Timer bits
            CANTIM6 = 64,  // Timer bits
            CANTIM7 = 128, // Timer bits
        };
    };

    // TTC Timer Register
    struct CANTTC {
        static const uint16_t address = 0xe8;
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
            TEC0 = 1,   // Transmit Error Counter bits
            TEC1 = 2,   // Transmit Error Counter bits
            TEC2 = 4,   // Transmit Error Counter bits
            TEC3 = 8,   // Transmit Error Counter bits
            TEC4 = 16,  // Transmit Error Counter bits
            TEC5 = 32,  // Transmit Error Counter bits
            TEC6 = 64,  // Transmit Error Counter bits
            TEC7 = 128, // Transmit Error Counter bits
        };
    };

    // Receive Error Counter Register
    struct CANREC {
        static const uint8_t address = 0xeb;
        enum bits : uint8_t {
            REC0 = 1,   // Receive Error Counter bits
            REC1 = 2,   // Receive Error Counter bits
            REC2 = 4,   // Receive Error Counter bits
            REC3 = 8,   // Receive Error Counter bits
            REC4 = 16,  // Receive Error Counter bits
            REC5 = 32,  // Receive Error Counter bits
            REC6 = 64,  // Receive Error Counter bits
            REC7 = 128, // Receive Error Counter bits
        };
    };

    // Highest Priority MOb Register
    struct CANHPMOB {
        static const uint8_t address = 0xec;
        enum bits : uint8_t {
            CGP0   = 1,   // CAN General Purpose bits
            CGP1   = 2,   // CAN General Purpose bits
            CGP2   = 4,   // CAN General Purpose bits
            CGP3   = 8,   // CAN General Purpose bits
            HPMOB0 = 16,  // Highest Priority MOb Number bits
            HPMOB1 = 32,  // Highest Priority MOb Number bits
            HPMOB2 = 64,  // Highest Priority MOb Number bits
            HPMOB3 = 128, // Highest Priority MOb Number bits
        };
    };

    // Page MOb Register
    struct CANPAGE {
        static const uint8_t address = 0xed;
        enum bits : uint8_t {
            INDX0  = 1,   // Data Buffer Index bits
            INDX1  = 2,   // Data Buffer Index bits
            INDX2  = 4,   // Data Buffer Index bits
            AINC   = 8,   // MOb Data Buffer Auto Increment (Active Low)
            MOBNB0 = 16,  // MOb Number bits
            MOBNB1 = 32,  // MOb Number bits
            MOBNB2 = 64,  // MOb Number bits
            MOBNB3 = 128, // MOb Number bits
        };
    };

    // MOb Status Register
    struct CANSTMOB {
        static const uint8_t address = 0xee;
        enum bits : uint8_t {
            AERR = 1,   // Ackknowledgement Error on MOb
            FERR = 2,   // Form Error on MOb
            CERR = 4,   // CRC Error on MOb
            SERR = 8,   // Stuff Error on MOb
            BERR = 16,  // Bit Error on MOb
            RXOK = 32,  // Receive OK on MOb
            TXOK = 64,  // Transmit OK on MOb
            DLCW = 128, // Data Length Code Warning on MOb
        };
    };

    // MOb Control and DLC Register
    struct CANCDMOB {
        static const uint8_t address = 0xef;
        enum bits : uint8_t {
            DLC0    = 1,   // Data Length Code bits
            DLC1    = 2,   // Data Length Code bits
            DLC2    = 4,   // Data Length Code bits
            DLC3    = 8,   // Data Length Code bits
            IDE     = 16,  // Identifier Extension
            RPLV    = 32,  // Reply Valid
            CONMOB0 = 64,  // MOb Config bits
            CONMOB1 = 128, // MOb Config bits
        };
    };

    // Identifier Tag Register 4
    struct CANIDT4 {
        static const uint8_t address = 0xf0;
        enum bits : uint8_t {
            RB0TAG = 1,   // Reserved Bit 0 Tag
            RB1TAG = 2,   // Reserved Bit 1 Tag
            RTRTAG = 4,   // Remote Transmission Request Tag
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
            TIMSTM0 = 1,   // TIMSTM
            TIMSTM1 = 2,   // TIMSTM
            TIMSTM2 = 4,   // TIMSTM
            TIMSTM3 = 8,   // TIMSTM
            TIMSTM4 = 16,  // TIMSTM
            TIMSTM5 = 32,  // TIMSTM
            TIMSTM6 = 64,  // TIMSTM
            TIMSTM7 = 128, // TIMSTM
        };
    };

    // Message Data Register
    struct CANMSG {
        static const uint8_t address = 0xfa;
        enum bits : uint8_t {
            MSG0 = 1,   // Message Data bits
            MSG1 = 2,   // Message Data bits
            MSG2 = 4,   // Message Data bits
            MSG3 = 8,   // Message Data bits
            MSG4 = 16,  // Message Data bits
            MSG5 = 32,  // Message Data bits
            MSG6 = 64,  // Message Data bits
            MSG7 = 128, // Message Data bits
        };
    };

}

#endif
#ifndef at90pwm81_sfr_h
#define at90pwm81_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       AT90PWM81
*/

namespace SFR {

    // Analog Comparator Status Register
    struct ACSR {
        static const uint8_t address = 0x20;
        enum bits : uint8_t {
            AC1O  = 2,   // Analog Comparator 1 Output Bit
            AC2O  = 4,   // Analog Comparator 2 Output Bit
            AC3O  = 8,   // Analog Comparator 3 Output Bit
            AC1IF = 32,  // Analog Comparator 1  Interrupt Flag Bit
            AC2IF = 64,  // Analog Comparator 2 Interrupt Flag Bit
            AC3IF = 128, // Analog Comparator 3 Interrupt Flag Bit
        };
    };

    // Timer/Counter Interrupt Mask Register
    struct TIMSK1 {
        static const uint8_t address = 0x21;
        enum bits : uint8_t {
            TOIE1 = 1,  // Timer/Counter1 Overflow Interrupt Enable
            ICIE1 = 32, // Timer/Counter1 Input Capture Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR1 {
        static const uint8_t address = 0x22;
        enum bits : uint8_t {
            TOV1 = 1,  // Timer/Counter1 Overflow Flag
            ICF1 = 32, // Input Capture Flag 1
        };
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

    // The ADC Control and Status register
    struct ADCSRA {
        static const uint8_t address = 0x26;
        enum bits : uint8_t {
            ADPS0 = 1,   // ADC Prescaler Select Bits
            ADPS1 = 2,   // ADC Prescaler Select Bits
            ADPS2 = 4,   // ADC Prescaler Select Bits
            ADIE  = 8,   // ADC Interrupt Enable
            ADIF  = 16,  // ADC Interrupt Flag
            ADATE = 32,  // ADC Auto Trigger Enable
            ADSC  = 64,  // ADC Start Conversion
            ADEN  = 128, // ADC Enable
        };
    };

    // ADC Control and Status Register B
    struct ADCSRB {
        static const uint8_t address = 0x27;
        enum bits : uint8_t {
            ADTS0   = 1,   // ADC Auto Trigger Sources
            ADTS1   = 2,   // ADC Auto Trigger Sources
            ADTS2   = 4,   // ADC Auto Trigger Sources
            ADTS3   = 8,   // ADC Auto Trigger Sources
            ADSSEN  = 16,  // ADC Single Shot Enable on PSC's Synchronisation Signals
            ADNCDIS = 64,  // ADC Noise Canceller Disable
            ADHSM   = 128, // ADC High Speed Mode
        };
    };

    // The ADC multiplexer Selection Register
    struct ADMUX {
        static const uint8_t address = 0x28;
        enum bits : uint8_t {
            MUX0  = 1,   // Analog Channel and Gain Selection Bits
            MUX1  = 2,   // Analog Channel and Gain Selection Bits
            MUX2  = 4,   // Analog Channel and Gain Selection Bits
            MUX3  = 8,   // Analog Channel and Gain Selection Bits
            ADLAR = 32,  // Left Adjust Result
            REFS0 = 64,  // Reference Selection Bits
            REFS1 = 128, // Reference Selection Bits
        };
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

    // PSC0 Interrupt Mask Register
    struct PIM0 {
        static const uint8_t address = 0x2f;
        enum bits : uint8_t {
            PEOPE0  = 1,  // End of Cycle Interrupt Enable
            PEOEPE0 = 2,  // End of Enhanced Cycle Enable
            PEVE0A  = 8,  // External Event A Interrupt Enable
            PEVE0B  = 16, // External Event B Interrupt Enable
        };
    };

    // PSC0 Interrupt Flag Register
    struct PIFR0 {
        static const uint8_t address = 0x30;
        enum bits : uint8_t {
            PEOP0  = 1,   // End of PSC0 Interrupt
            PRN00  = 2,   // Ramp Number
            PRN01  = 4,   // Ramp Number
            PEV0A  = 8,   // External Event A Interrupt
            PEV0B  = 16,  // External Event B Interrupt
            POAC0A = 64,  // PSC 0 Output A Activity
            POAC0B = 128, // PSC 0 Output A Activity
        };
    };

    // PSC 0 Configuration Register
    struct PCNF0 {
        static const uint8_t address = 0x31;
        enum bits : uint8_t {
            PCLKSEL0 = 2,   // PSC 0 Input Clock Select
            POP0     = 4,   // PSC 0 Output Polarity
            PMODE00  = 8,   // PSC 0 Mode
            PMODE01  = 16,  // PSC 0 Mode
            PLOCK0   = 32,  // PSC 0 Lock
            PALOCK0  = 64,  // PSC 0 Autolock
            PFIFTY0  = 128, // PSC 0 Fifty
        };
    };

    // PSC 0 Control Register
    struct PCTL0 {
        static const uint8_t address = 0x32;
        enum bits : uint8_t {
            PRUN0  = 1,   // PSC 0 Run
            PCCYC0 = 2,   // PSC0 Complete Cycle
            PBFM00 = 4,   // PSC 0 Balance Flank Width Modulation
            PAOC0A = 8,   // PSC 0 Asynchronous Output Control A
            PAOC0B = 16,  // PSC 0 Asynchronous Output Control B
            PBFM01 = 32,  // PSC 0 Balance Flank Width Modulation
            PPRE00 = 64,  // PSC 0 Prescaler Selects
            PPRE01 = 128, // PSC 0 Prescaler Selects
        };
    };

    // PSC2 Interrupt Mask Register
    struct PIM2 {
        static const uint8_t address = 0x33;
        enum bits : uint8_t {
            PEOPE2  = 1,  // End of Cycle Interrupt Enable
            PEOEPE2 = 2,  // End of Enhanced Cycle Interrupt Enable
            PEVE2A  = 8,  // External Event A Interrupt Enable
            PEVE2B  = 16, // External Event B Interrupt Enable
            PSEIE2  = 32, // PSC 2 Synchro Error Interrupt Enable
        };
    };

    // PSC2 Interrupt Flag Register
    struct PIFR2 {
        static const uint8_t address = 0x34;
        enum bits : uint8_t {
            PEOP2  = 1,   // End of PSC2 Interrupt
            PRN20  = 2,   // Ramp Number
            PRN21  = 4,   // Ramp Number
            PEV2A  = 8,   // External Event A Interrupt
            PEV2B  = 16,  // External Event B Interrupt
            PSEI2  = 32,  // PSC 2 Synchro Error Interrupt
            POAC2A = 64,  // PSC 2 Output A Activity
            POAC2B = 128, // PSC 2 Output A Activity
        };
    };

    // PSC 2 Configuration Register
    struct PCNF2 {
        static const uint8_t address = 0x35;
        enum bits : uint8_t {
            POME2    = 1,   // PSC 2 Output Matrix Enable
            PCLKSEL2 = 2,   // PSC 2 Input Clock Select
            POP2     = 4,   // PSC 2 Output Polarity
            PMODE20  = 8,   // PSC 2 Mode
            PMODE21  = 16,  // PSC 2 Mode
            PLOCK2   = 32,  // PSC 2 Lock
            PALOCK2  = 64,  // PSC 2 Autolock
            PFIFTY2  = 128, // PSC 2 Fifty
        };
    };

    // PSC 2 Control Register
    struct PCTL2 {
        static const uint8_t address = 0x36;
        enum bits : uint8_t {
            PRUN2  = 1,   // PSC 2 Run
            PCCYC2 = 2,   // PSC2 Complete Cycle
            PARUN2 = 4,   // PSC2 Auto Run
            PAOC2A = 8,   // PSC 2 Asynchronous Output Control A
            PAOC2B = 16,  // PSC 2 Asynchronous Output Control B
            PBFM2  = 32,  // Balance Flank Width Modulation
            PPRE20 = 64,  // PSC 2 Prescaler Selects
            PPRE21 = 128, // PSC 2 Prescaler Selects
        };
    };

    // SPI Control Register
    struct SPCR {
        static const uint8_t address = 0x37;
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
        static const uint8_t address = 0x38;
        enum bits : uint8_t {
            SPI2X = 1,   // Double SPI Speed Bit
            WCOL  = 64,  // Write Collision Flag
            SPIF  = 128, // SPI Interrupt Flag
        };
    };

    // General Purpose IO Register 0
    struct GPIOR0 {
        static const uint8_t address = 0x39;
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

    // General Purpose IO Register 1
    struct GPIOR1 {
        static const uint8_t address = 0x3a;
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
        static const uint8_t address = 0x3b;
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

    // EEPROM Control Register
    struct EECR {
        static const uint8_t address = 0x3c;
        enum bits : uint8_t {
            EERE   = 1,   // EEPROM Read Enable
            EEWE   = 2,   // EEPROM Write Enable
            EEMWE  = 4,   // EEPROM Master Write Enable
            EERIE  = 8,   // EEPROM Ready Interrupt Enable
            EEPM0  = 16,  // EEPROM Programming Mode
            EEPM1  = 32,  // EEPROM Programming Mode
            EEPAGE = 64,  // EEPROM Page Access
            NVMBSY = 128, // None Volatile Busy Memory Busy
        };
    };

    // EEPROM Data Register
    struct EEDR {
        static const uint8_t address = 0x3d;
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
        static const uint8_t address = 0x3e;
        enum bits : uint8_t {
            EEAR0 = 1,   // EEPROM Address bytes
            EEAR1 = 2,   // EEPROM Address bytes
            EEAR2 = 4,   // EEPROM Address bytes
            EEAR3 = 8,   // EEPROM Address bytes
            EEAR4 = 16,  // EEPROM Address bytes
            EEAR5 = 32,  // EEPROM Address bytes
            EEAR6 = 64,  // EEPROM Address bytes
            EEAR7 = 128, // EEPROM Address bytes
        };
    };

    // External Interrupt Flag Register
    struct EIFR {
        static const uint8_t address = 0x40;
        enum bits : uint8_t {
            INTF0 = 1, // External Interrupt Flags
            INTF1 = 2, // External Interrupt Flags
            INTF2 = 4, // External Interrupt Flags
        };
    };

    // External Interrupt Mask Register
    struct EIMSK {
        static const uint8_t address = 0x41;
        enum bits : uint8_t {
            INT0 = 1, // External Interrupt Request 2 Enable
            INT1 = 2, // External Interrupt Request 2 Enable
            INT2 = 4, // External Interrupt Request 2 Enable
        };
    };

    // Output Compare SB Register
    struct OCR0SB {
        static const uint8_t address = 0x42;
        enum bits : uint8_t {
            OCR0SB0 = 1,   // Output Compare 0 SB
            OCR0SB1 = 2,   // Output Compare 0 SB
            OCR0SB2 = 4,   // Output Compare 0 SB
            OCR0SB3 = 8,   // Output Compare 0 SB
            OCR0SB4 = 16,  // Output Compare 0 SB
            OCR0SB5 = 32,  // Output Compare 0 SB
            OCR0SB6 = 64,  // Output Compare 0 SB
            OCR0SB7 = 128, // Output Compare 0 SB
        };
    };

    // Output Compare RB Register
    struct OCR0RB {
        static const uint8_t address = 0x44;
        enum bits : uint8_t {
            OCR0RB0 = 1,   // Output Compare 0 RB
            OCR0RB1 = 2,   // Output Compare 0 RB
            OCR0RB2 = 4,   // Output Compare 0 RB
            OCR0RB3 = 8,   // Output Compare 0 RB
            OCR0RB4 = 16,  // Output Compare 0 RB
            OCR0RB5 = 32,  // Output Compare 0 RB
            OCR0RB6 = 64,  // Output Compare 0 RB
            OCR0RB7 = 128, // Output Compare 0 RB
        };
    };

    // Output Compare SB Register
    struct OCR2SB {
        static const uint8_t address = 0x46;
        enum bits : uint8_t {
            OCR2SB0 = 1,   // Output Compare 2 SB
            OCR2SB1 = 2,   // Output Compare 2 SB
            OCR2SB2 = 4,   // Output Compare 2 SB
            OCR2SB3 = 8,   // Output Compare 2 SB
            OCR2SB4 = 16,  // Output Compare 2 SB
            OCR2SB5 = 32,  // Output Compare 2 SB
            OCR2SB6 = 64,  // Output Compare 2 SB
            OCR2SB7 = 128, // Output Compare 2 SB
        };
    };

    // Output Compare RB Register
    struct OCR2RB {
        static const uint8_t address = 0x48;
        enum bits : uint8_t {
            OCR2RB0 = 1,   // Output Compare 2 RB
            OCR2RB1 = 2,   // Output Compare 2 RB
            OCR2RB2 = 4,   // Output Compare 2 RB
            OCR2RB3 = 8,   // Output Compare 2 RB
            OCR2RB4 = 16,  // Output Compare 2 RB
            OCR2RB5 = 32,  // Output Compare 2 RB
            OCR2RB6 = 64,  // Output Compare 2 RB
            OCR2RB7 = 128, // Output Compare 2 RB
        };
    };

    // Output Compare RA Register
    struct OCR0RA {
        static const uint8_t address = 0x4a;
        enum bits : uint8_t {
            OCR0RA0 = 1,   // Output Compare 0 RA
            OCR0RA1 = 2,   // Output Compare 0 RA
            OCR0RA2 = 4,   // Output Compare 0 RA
            OCR0RA3 = 8,   // Output Compare 0 RA
            OCR0RA4 = 16,  // Output Compare 0 RA
            OCR0RA5 = 32,  // Output Compare 0 RA
            OCR0RA6 = 64,  // Output Compare 0 RA
            OCR0RA7 = 128, // Output Compare 0 RA
        };
    };

    // ADC Data Register Bytes
    struct ADC {
        static const uint16_t address = 0x4c;
        enum bits : uint8_t {
            ADC0 = 1,   // ADC Data Register
            ADC1 = 2,   // ADC Data Register
            ADC2 = 4,   // ADC Data Register
            ADC3 = 8,   // ADC Data Register
            ADC4 = 16,  // ADC Data Register
            ADC5 = 32,  // ADC Data Register
            ADC6 = 64,  // ADC Data Register
            ADC7 = 128, // ADC Data Register
        };
    };

    // Output Compare RA Register
    struct OCR2RA {
        static const uint8_t address = 0x4e;
        enum bits : uint8_t {
            OCR2RA0 = 1,   // Output Compare 2 RA
            OCR2RA1 = 2,   // Output Compare 2 RA
            OCR2RA2 = 4,   // Output Compare 2 RA
            OCR2RA3 = 8,   // Output Compare 2 RA
            OCR2RA4 = 16,  // Output Compare 2 RA
            OCR2RA5 = 32,  // Output Compare 2 RA
            OCR2RA6 = 64,  // Output Compare 2 RA
            OCR2RA7 = 128, // Output Compare 2 RA
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
            IVCE   = 1,  // Interrupt Vector Change Enable
            IVSEL  = 2,  // Interrupt Vector Select
            CKRC81 = 4,  // Frequency Selection of the Calibrated RC Oscillator
            RSTDIS = 8,  // Reset Pin Disable
            PUD    = 16, // Pull-up disable
        };
    };

    // SPI Data Register
    struct SPDR {
        static const uint8_t address = 0x56;
        enum bits : uint8_t {
            SPD0 = 1,   // SPI Data bits
            SPD1 = 2,   // SPI Data bits
            SPD2 = 4,   // SPI Data bits
            SPD3 = 8,   // SPI Data bits
            SPD4 = 16,  // SPI Data bits
            SPD5 = 32,  // SPI Data bits
            SPD6 = 64,  // SPI Data bits
            SPD7 = 128, // SPI Data bits
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

    // DAC Data Register
    struct DAC {
        static const uint16_t address = 0x58;
        enum bits : uint8_t {
            DACH0 = 1,   // DAC Data Register Bits
            DACH1 = 2,   // DAC Data Register Bits
            DACH2 = 4,   // DAC Data Register Bits
            DACH3 = 8,   // DAC Data Register Bits
            DACH4 = 16,  // DAC Data Register Bits
            DACH5 = 32,  // DAC Data Register Bits
            DACH6 = 64,  // DAC Data Register Bits
            DACH7 = 128, // DAC Data Register Bits
        };
    };

    // Timer/Counter1 Bytes
    struct TCNT1 {
        static const uint8_t address = 0x5a;
        enum bits : uint8_t {
            TCNT10 = 1,   // Timer/Counter 1 bits
            TCNT11 = 2,   // Timer/Counter 1 bits
            TCNT12 = 4,   // Timer/Counter 1 bits
            TCNT13 = 8,   // Timer/Counter 1 bits
            TCNT14 = 16,  // Timer/Counter 1 bits
            TCNT15 = 32,  // Timer/Counter 1 bits
            TCNT16 = 64,  // Timer/Counter 1 bits
            TCNT17 = 128, // Timer/Counter 1 bits
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

    // Output Compare SA Register
    struct OCR0SA {
        static const uint8_t address = 0x60;
        enum bits : uint8_t {
            OCR0SA0 = 1,   // Output Compare 0 SA
            OCR0SA1 = 2,   // Output Compare 0 SA
            OCR0SA2 = 4,   // Output Compare 0 SA
            OCR0SA3 = 8,   // Output Compare 0 SA
            OCR0SA4 = 16,  // Output Compare 0 SA
            OCR0SA5 = 32,  // Output Compare 0 SA
            OCR0SA6 = 64,  // Output Compare 0 SA
            OCR0SA7 = 128, // Output Compare 0 SA
        };
    };

    // PSC 0 Input A Control
    struct PFRC0A {
        static const uint8_t address = 0x62;
        enum bits : uint8_t {
            PRFM0A0 = 1,   // PSC 0 Retrigger and Fault Mode for Part A
            PRFM0A1 = 2,   // PSC 0 Retrigger and Fault Mode for Part A
            PRFM0A2 = 4,   // PSC 0 Retrigger and Fault Mode for Part A
            PRFM0A3 = 8,   // PSC 0 Retrigger and Fault Mode for Part A
            PFLTE0A = 16,  // PSC 0 Filter Enable on Input Part A
            PELEV0A = 32,  // PSC 0 Edge Level Selector on Input Part A
            PISEL0A = 64,  // PSC 0 Input Select for Part A
            PCAE0A  = 128, // PSC 0 Capture Enable Input Part A
        };
    };

    // PSC 0 Input B Control
    struct PFRC0B {
        static const uint8_t address = 0x63;
        enum bits : uint8_t {
            PRFM0B0 = 1,   // PSC 0 Retrigger and Fault Mode for Part B
            PRFM0B1 = 2,   // PSC 0 Retrigger and Fault Mode for Part B
            PRFM0B2 = 4,   // PSC 0 Retrigger and Fault Mode for Part B
            PRFM0B3 = 8,   // PSC 0 Retrigger and Fault Mode for Part B
            PFLTE0B = 16,  // PSC 0 Filter Enable on Input Part B
            PELEV0B = 32,  // PSC 0 Edge Level Selector on Input Part B
            PISEL0B = 64,  // PSC 0 Input Select for Part B
            PCAE0B  = 128, // PSC 0 Capture Enable Input Part B
        };
    };

    // Output Compare SA Register
    struct OCR2SA {
        static const uint8_t address = 0x64;
        enum bits : uint8_t {
            OCR2SA0 = 1,   // Output Compare 2 SA
            OCR2SA1 = 2,   // Output Compare 2 SA
            OCR2SA2 = 4,   // Output Compare 2 SA
            OCR2SA3 = 8,   // Output Compare 2 SA
            OCR2SA4 = 16,  // Output Compare 2 SA
            OCR2SA5 = 32,  // Output Compare 2 SA
            OCR2SA6 = 64,  // Output Compare 2 SA
            OCR2SA7 = 128, // Output Compare 2 SA
        };
    };

    // PSC 2 Input B Control
    struct PFRC2A {
        static const uint8_t address = 0x66;
        enum bits : uint8_t {
            PRFM2A0 = 1,   // PSC 2 Retrigger and Fault Mode for Part A
            PRFM2A1 = 2,   // PSC 2 Retrigger and Fault Mode for Part A
            PRFM2A2 = 4,   // PSC 2 Retrigger and Fault Mode for Part A
            PRFM2A3 = 8,   // PSC 2 Retrigger and Fault Mode for Part A
            PFLTE2A = 16,  // PSC 2 Filter Enable on Input Part A
            PELEV2A = 32,  // PSC 2 Edge Level Selector on Input Part A
            PISEL2A = 64,  // PSC 2 Input Select for Part A
            PCAE2A  = 128, // PSC 2 Capture Enable Input Part A
        };
    };

    // PSC 2 Input B Control
    struct PFRC2B {
        static const uint8_t address = 0x67;
        enum bits : uint8_t {
            PRFM2B0 = 1,   // PSC 2 Retrigger and Fault Mode for Part B
            PRFM2B1 = 2,   // PSC 2 Retrigger and Fault Mode for Part B
            PRFM2B2 = 4,   // PSC 2 Retrigger and Fault Mode for Part B
            PRFM2B3 = 8,   // PSC 2 Retrigger and Fault Mode for Part B
            PFLTE2B = 16,  // PSC 2 Filter Enable on Input Part B
            PELEV2B = 32,  // PSC 2 Edge Level Selector on Input Part B
            PISEL2B = 64,  // PSC 2 Input Select for Part B
            PCAE2B  = 128, // PSC 2 Capture Enable Input Part B
        };
    };

    // PSC 0 Input Capture Register
    struct PICR0 {
        static const uint16_t address = 0x68;
        enum bits : uint8_t {
            PICR00 = 1,     // PSC 0 Input Capture Bytes
            PICR01 = 2,     // PSC 0 Input Capture Bytes
            PICR02 = 4,     // PSC 0 Input Capture Bytes
            PICR03 = 8,     // PSC 0 Input Capture Bytes
            PICR04 = 16,    // PSC 0 Input Capture Bytes
            PICR05 = 32,    // PSC 0 Input Capture Bytes
            PICR06 = 64,    // PSC 0 Input Capture Bytes
            PICR07 = 128,   // PSC 0 Input Capture Bytes
            PCST0  = 32768, // PSC 0 Capture Software Trigger Bit
        };
    };

    // PSC0 Synchro and Output Configuration
    struct PSOC0 {
        static const uint8_t address = 0x6a;
        enum bits : uint8_t {
            POEN0A   = 1,   // PSCOUT00 Output Enable
            POEN0B   = 4,   // PSCOUT01 Output Enable
            PSYNC00  = 16,  // Synchronisation out for ADC selection
            PSYNC01  = 32,  // Synchronisation out for ADC selection
            PISEL0B1 = 64,  // PSC Input Select
            PISEL0A1 = 128, // PSC Input Select
        };
    };

    // PSC 2 Input Capture Register
    struct PICR2 {
        static const uint16_t address = 0x6c;
        enum bits : uint8_t {
            PICR20 = 1,     // PSC 2 Input Capture Bytes
            PICR21 = 2,     // PSC 2 Input Capture Bytes
            PICR22 = 4,     // PSC 2 Input Capture Bytes
            PICR23 = 8,     // PSC 2 Input Capture Bytes
            PICR24 = 16,    // PSC 2 Input Capture Bytes
            PICR25 = 32,    // PSC 2 Input Capture Bytes
            PICR26 = 64,    // PSC 2 Input Capture Bytes
            PICR27 = 128,   // PSC 2 Input Capture Bytes
            PCST2  = 32768, // PSC 2 Capture Software Trigger Bit
        };
    };

    // PSC2 Synchro and Output Configuration
    struct PSOC2 {
        static const uint8_t address = 0x6e;
        enum bits : uint8_t {
            POEN2A  = 1,   // PSCOUT20 Output Enable
            POEN2C  = 2,   // PSCOUT22 Output Enable
            POEN2B  = 4,   // PSCOUT21 Output Enable
            POEN2D  = 8,   // PSCOUT23 Output Enable
            PSYNC20 = 16,  // Synchronization Out for ADC Selection
            PSYNC21 = 32,  // Synchronization Out for ADC Selection
            POS20   = 64,  // PSC 2 Output 23 Select
            POS21   = 128, // PSC 2 Output 23 Select
        };
    };

    // PSC 2 Output Matrix
    struct POM2 {
        static const uint8_t address = 0x6f;
        enum bits : uint8_t {
            POMV2A0 = 1,   // Output Matrix Output A Ramps
            POMV2A1 = 2,   // Output Matrix Output A Ramps
            POMV2A2 = 4,   // Output Matrix Output A Ramps
            POMV2A3 = 8,   // Output Matrix Output A Ramps
            POMV2B0 = 16,  // Output Matrix Output B Ramps
            POMV2B1 = 32,  // Output Matrix Output B Ramps
            POMV2B2 = 64,  // Output Matrix Output B Ramps
            POMV2B3 = 128, // Output Matrix Output B Ramps
        };
    };

    // PSC 2 Enhanced Configuration Register
    struct PCNFE2 {
        static const uint8_t address = 0x70;
        enum bits : uint8_t {
            PISEL2B1 = 1,   //
            PISEL2A1 = 2,   //
            PELEV2B1 = 4,   //
            PELEV2A1 = 8,   //
            PBFM21   = 16,  //
            PASDLK20 = 32,  //
            PASDLK21 = 64,  //
            PASDLK22 = 128, //
        };
    };

    // Analog Synchronization Delay Register
    struct PASDLY2 {
        static const uint8_t address = 0x71;
        enum bits : uint8_t {
            PASDLY20 = 1,   // Analog Synchronization Delay bits
            PASDLY21 = 2,   // Analog Synchronization Delay bits
            PASDLY22 = 4,   // Analog Synchronization Delay bits
            PASDLY23 = 8,   // Analog Synchronization Delay bits
            PASDLY24 = 16,  // Analog Synchronization Delay bits
            PASDLY25 = 32,  // Analog Synchronization Delay bits
            PASDLY26 = 64,  // Analog Synchronization Delay bits
            PASDLY27 = 128, // Analog Synchronization Delay bits
        };
    };

    // DAC Control Register
    struct DACON {
        static const uint8_t address = 0x76;
        enum bits : uint8_t {
            DAEN  = 1,   // DAC Enable Bit
            DALA  = 4,   // DAC Left Adjust
            DATS0 = 16,  // DAC Trigger Selection Bits
            DATS1 = 32,  // DAC Trigger Selection Bits
            DATS2 = 64,  // DAC Trigger Selection Bits
            DAATE = 128, // DAC Auto Trigger Enable Bit
        };
    };

    // Digital Input Disable Register 0
    struct DIDR0 {
        static const uint8_t address = 0x77;
        enum bits : uint8_t {
            ADC0D = 1,   // ADC0 Digital input Disable
            ADC1D = 2,   // ADC1 Digital input Disable
            ADC2D = 4,   // ADC2 Digital input Disable
            ADC3D = 8,   // ADC3 Digital input Disable
            ADC4D = 16,  // ADC4 Digital input Disable
            ADC5D = 32,  // ADC5 Digital input Disable
            ADC7D = 64,  // ADC7 Digital input Disable
            ADC8D = 128, // ADC8 Digital input Disable
        };
    };

    // Digital Input Disable Register 1
    struct DIDR1 {
        static const uint8_t address = 0x78;
        enum bits : uint8_t {
            ADC9D   = 1, // ADC9 Digital input Disable
            ADC10D  = 2, // ADC10 Digital input Disable
            AMP0PD  = 4, //
            ACMP1MD = 8, //
        };
    };

    //
    struct AMP0CSR {
        static const uint8_t address = 0x79;
        enum bits : uint8_t {
            AMP0TS0 = 1,   //
            AMP0TS1 = 2,   //
            AMP0GS  = 8,   //
            AMP0G0  = 16,  //
            AMP0G1  = 32,  //
            AMP0IS  = 64,  //
            AMP0EN  = 128, //
        };
    };

    //
    struct AC1ECON {
        static const uint8_t address = 0x7a;
        enum bits : uint8_t {
            AC1H0  = 1,  // Analog Comparator Hysteresis Select
            AC1H1  = 2,  // Analog Comparator Hysteresis Select
            AC1H2  = 4,  // Analog Comparator Hysteresis Select
            AC1ICE = 8,  // Analog Comparator Interrupt Capture Enable
            AC1OE  = 16, // Analog Comparator Ouput Enable
            AC1OI  = 32, // Analog Comparator Ouput Invert
        };
    };

    //
    struct AC2ECON {
        static const uint8_t address = 0x7b;
        enum bits : uint8_t {
            AC2H0 = 1,  // Analog Comparator Hysteresis Select
            AC2H1 = 2,  // Analog Comparator Hysteresis Select
            AC2H2 = 4,  // Analog Comparator Hysteresis Select
            AC2OE = 16, // Analog Comparator Ouput Enable
            AC2OI = 32, // Analog Comparator Ouput Invert
        };
    };

    //
    struct AC3ECON {
        static const uint8_t address = 0x7c;
        enum bits : uint8_t {
            AC3H0 = 1,  // Analog Comparator Hysteresis Select
            AC3H1 = 2,  // Analog Comparator Hysteresis Select
            AC3H2 = 4,  // Analog Comparator Hysteresis Select
            AC3OE = 16, // Analog Comparator Ouput Enable
            AC3OI = 32, // Analog Comparator Ouput Invert
        };
    };

    // Analog Comparator 1 Control Register
    struct AC1CON {
        static const uint8_t address = 0x7d;
        enum bits : uint8_t {
            AC1M0  = 1,   // Analog Comparator 1 Multiplexer Register
            AC1M1  = 2,   // Analog Comparator 1 Multiplexer Register
            AC1M2  = 4,   // Analog Comparator 1 Multiplexer Register
            AC1IS0 = 16,  // Analog Comparator 1  Interrupt Select Bit
            AC1IS1 = 32,  // Analog Comparator 1  Interrupt Select Bit
            AC1IE  = 64,  // Analog Comparator 1 Interrupt Enable Bit
            AC1EN  = 128, // Analog Comparator 1 Enable Bit
        };
    };

    // Analog Comparator 2 Control Register
    struct AC2CON {
        static const uint8_t address = 0x7e;
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

    // Analog Comparator3 Control Register
    struct AC3CON {
        static const uint8_t address = 0x7f;
        enum bits : uint8_t {
            AC3M0  = 1,   // Analog Comparator 3 Multiplexer Register
            AC3M1  = 2,   // Analog Comparator 3 Multiplexer Register
            AC3M2  = 4,   // Analog Comparator 3 Multiplexer Register
            AC3OEA = 8,   // Analog Comparator 3 Alternate Output Enable
            AC3IS0 = 16,  // Analog Comparator 3  Interrupt Select Bit
            AC3IS1 = 32,  // Analog Comparator 3  Interrupt Select Bit
            AC3IE  = 64,  // Analog Comparator 3 Interrupt Enable Bit
            AC3EN  = 128, // Analog Comparator3 Enable Bit
        };
    };

    // BandGap Resistor Calibration Register
    struct BGCRR {
        static const uint8_t address = 0x80;
        enum bits : uint8_t {
            BGCR0 = 1, //
            BGCR1 = 2, //
            BGCR2 = 4, //
            BGCR3 = 8, //
        };
    };

    // BandGap Current Calibration Register
    struct BGCCR {
        static const uint8_t address = 0x81;
        enum bits : uint8_t {
            BGCC0 = 1, //
            BGCC1 = 2, //
            BGCC2 = 4, //
            BGCC3 = 8, //
        };
    };

    // Watchdog Timer Control Register
    struct WDTCSR {
        static const uint8_t address = 0x82;
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
        static const uint8_t address = 0x83;
        enum bits : uint8_t {
            CLKPS0 = 1,   //
            CLKPS1 = 2,   //
            CLKPS2 = 4,   //
            CLKPS3 = 8,   //
            CLKPCE = 128, //
        };
    };

    //
    struct CLKCSR {
        static const uint8_t address = 0x84;
        enum bits : uint8_t {
            CLKC0  = 1,   // Clock Control
            CLKC1  = 2,   // Clock Control
            CLKC2  = 4,   // Clock Control
            CLKC3  = 8,   // Clock Control
            CLKRDY = 16,  // Clock Ready Flag
            CLKCCE = 128, // Clock Control Change Enable
        };
    };

    //
    struct CLKSELR {
        static const uint8_t address = 0x85;
        enum bits : uint8_t {
            CKSEL0 = 1,  // Clock Source Select
            CKSEL1 = 2,  // Clock Source Select
            CKSEL2 = 4,  // Clock Source Select
            CKSEL3 = 8,  // Clock Source Select
            CSUT0  = 16, // Clock Start up Time
            CSUT1  = 32, // Clock Start up Time
            COUT   = 64, // Clock OUT
        };
    };

    // Power Reduction Register
    struct PRR {
        static const uint8_t address = 0x86;
        enum bits : uint8_t {
            PRADC  = 1,   // Power Reduction ADC
            PRSPI  = 4,   // Power Reduction Serial Peripheral Interface
            PRTIM1 = 16,  // Power Reduction Timer/Counter1
            PRPSCR = 32,  // Power Reduction PSC0
            PRPSC2 = 128, // Power Reduction PSC2
        };
    };

    // PLL Control And Status Register
    struct PLLCSR {
        static const uint8_t address = 0x87;
        enum bits : uint8_t {
            PLOCK = 1,  // PLL Lock Detector
            PLLE  = 2,  // PLL Enable
            PLLF0 = 4,  //
            PLLF1 = 8,  //
            PLLF2 = 16, //
            PLLF3 = 32, //
        };
    };

    // Oscillator Calibration Value
    struct OSCCAL {
        static const uint8_t address = 0x88;
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
        static const uint8_t address = 0x89;
        enum bits : uint8_t {
            ISC00 = 1,  // External Interrupt Sense Control Bit
            ISC01 = 2,  // External Interrupt Sense Control Bit
            ISC10 = 4,  // External Interrupt Sense Control Bit
            ISC11 = 8,  // External Interrupt Sense Control Bit
            ISC20 = 16, // External Interrupt Sense Control Bit
            ISC21 = 32, // External Interrupt Sense Control Bit
        };
    };

    // Timer/Counter1 Control Register B
    struct TCCR1B {
        static const uint8_t address = 0x8a;
        enum bits : uint8_t {
            CS10  = 1,   // Prescaler source of Timer/Counter 1
            CS11  = 2,   // Prescaler source of Timer/Counter 1
            CS12  = 4,   // Prescaler source of Timer/Counter 1
            WGM13 = 16,  // Waveform Generation Mode
            ICES1 = 64,  // Input Capture 1 Edge Select
            ICNC1 = 128, // Input Capture 1 Noise Canceler
        };
    };

    // Timer/Counter1 Input Capture Register Bytes
    struct ICR1 {
        static const uint8_t address = 0x8c;
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

}

#endif
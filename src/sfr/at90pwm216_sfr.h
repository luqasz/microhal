#ifndef at90pwm216_sfr_h
#define at90pwm216_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       AT90PWM216
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

    // General Purpose IO Register 3
    struct GPIOR3 {
        static const uint8_t address = 0x3b;
        enum bits : uint8_t {
            GPIOR0 = 1,   // General Purpose IO Register 3 bis
            GPIOR1 = 2,   // General Purpose IO Register 3 bis
            GPIOR2 = 4,   // General Purpose IO Register 3 bis
            GPIOR3 = 8,   // General Purpose IO Register 3 bis
            GPIOR4 = 16,  // General Purpose IO Register 3 bis
            GPIOR5 = 32,  // General Purpose IO Register 3 bis
            GPIOR6 = 64,  // General Purpose IO Register 3 bis
            GPIOR7 = 128, // General Purpose IO Register 3 bis
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
            INT0 = 1, // External Interrupt Mask
            INT1 = 2, // External Interrupt Mask
            INT2 = 4, // External Interrupt Mask
            INT3 = 8, // External Interrupt Mask
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
            EEPM0 = 16, // EEPROM Programming Mode
            EEPM1 = 32, // EEPROM Programming Mode
        };
    };

    // EEPROM Data Register
    struct EEDR {
        static const uint8_t address = 0x40;
        enum bits : uint8_t {
            EEDR0 = 1,   // EEPROM Data Bits
            EEDR1 = 2,   // EEPROM Data Bits
            EEDR2 = 4,   // EEPROM Data Bits
            EEDR3 = 8,   // EEPROM Data Bits
            EEDR4 = 16,  // EEPROM Data Bits
            EEDR5 = 32,  // EEPROM Data Bits
            EEDR6 = 64,  // EEPROM Data Bits
            EEDR7 = 128, // EEPROM Data Bits
        };
    };

    // EEPROM Read/Write Access Bytes
    struct EEAR {
        static const uint16_t address = 0x41;
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

    // General Timer/Counter Control Register
    struct GTCCR {
        static const uint8_t address = 0x43;
        enum bits : uint8_t {
            PSRSYNC = 1,   // Prescaler Reset Timer/Counter1 and Timer/Counter0
            ICPSEL1 = 64,  // Timer1 Input Capture Selection Bit
            TSM     = 128, // Timer/Counter Synchronization Mode
        };
    };

    // Timer/Counter Control Register A
    struct TCCR0A {
        static const uint8_t address = 0x44;
        enum bits : uint8_t {
            WGM00  = 1,   // Waveform Generation Mode
            WGM01  = 2,   // Waveform Generation Mode
            COM0B0 = 16,  // Compare Output Mode, Fast PWm
            COM0B1 = 32,  // Compare Output Mode, Fast PWm
            COM0A0 = 64,  // Compare Output Mode, Phase Correct PWM Mode
            COM0A1 = 128, // Compare Output Mode, Phase Correct PWM Mode
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
            TCNT00 = 1,   // Timer Counter 0 value
            TCNT01 = 2,   // Timer Counter 0 value
            TCNT02 = 4,   // Timer Counter 0 value
            TCNT03 = 8,   // Timer Counter 0 value
            TCNT04 = 16,  // Timer Counter 0 value
            TCNT05 = 32,  // Timer Counter 0 value
            TCNT06 = 64,  // Timer Counter 0 value
            TCNT07 = 128, // Timer Counter 0 value
        };
    };

    // Timer/Counter0 Output Compare Register
    struct OCR0A {
        static const uint8_t address = 0x47;
        enum bits : uint8_t {
            OCR0A0 = 1,   // Output Compare A value
            OCR0A1 = 2,   // Output Compare A value
            OCR0A2 = 4,   // Output Compare A value
            OCR0A3 = 8,   // Output Compare A value
            OCR0A4 = 16,  // Output Compare A value
            OCR0A5 = 32,  // Output Compare A value
            OCR0A6 = 64,  // Output Compare A value
            OCR0A7 = 128, // Output Compare A value
        };
    };

    // Timer/Counter0 Output Compare Register
    struct OCR0B {
        static const uint8_t address = 0x48;
        enum bits : uint8_t {
            OCR0B0 = 1,   // Output Compare B value
            OCR0B1 = 2,   // Output Compare B value
            OCR0B2 = 4,   // Output Compare B value
            OCR0B3 = 8,   // Output Compare B value
            OCR0B4 = 16,  // Output Compare B value
            OCR0B5 = 32,  // Output Compare B value
            OCR0B6 = 64,  // Output Compare B value
            OCR0B7 = 128, // Output Compare B value
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
        enum bits : uint8_t {
            SPD0 = 1,   // SPI Data
            SPD1 = 2,   // SPI Data
            SPD2 = 4,   // SPI Data
            SPD3 = 8,   // SPI Data
            SPD4 = 16,  // SPI Data
            SPD5 = 32,  // SPI Data
            SPD6 = 64,  // SPI Data
            SPD7 = 128, // SPI Data
        };
    };

    // Analog Comparator Status Register
    struct ACSR {
        static const uint8_t address = 0x50;
        enum bits : uint8_t {
            AC0O    = 1,   // Analog Comparator 0 Output Bit
            AC1O    = 2,   // Analog Comparator 1 Output Bit
            AC2O    = 4,   // Analog Comparator 2 Output Bit
            AC0IF   = 16,  // Analog Comparator 0 Interrupt Flag Bit
            AC1IF   = 32,  // Analog Comparator 1  Interrupt Flag Bit
            AC2IF   = 64,  // Analog Comparator 2 Interrupt Flag Bit
            ACCKDIV = 128, // Analog Comparator Clock Divider
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
            CLKPS0 = 1,   //
            CLKPS1 = 2,   //
            CLKPS2 = 4,   //
            CLKPS3 = 8,   //
            CLKPCE = 128, //
        };
    };

    // Power Reduction Register
    struct PRR {
        static const uint8_t address = 0x64;
        enum bits : uint8_t {
            PRADC    = 1,   // Power Reduction ADC
            PRUSART0 = 2,   // Power Reduction USART
            PRSPI    = 4,   // Power Reduction Serial Peripheral Interface
            PRTIM0   = 8,   // Power Reduction Timer/Counter0
            PRTIM1   = 16,  // Power Reduction Timer/Counter1
            PRPSC0   = 32,  // Power Reduction PSC0
            PRPSC1   = 64,  // Power Reduction PSC1
            PRPSC2   = 128, // Power Reduction PSC2
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

    //
    struct AMP0CSR {
        static const uint8_t address = 0x76;
        enum bits : uint8_t {
            AMP0TS0 = 1,   //
            AMP0TS1 = 2,   //
            AMP0G0  = 16,  //
            AMP0G1  = 32,  //
            AMP0IS  = 64,  //
            AMP0EN  = 128, //
        };
    };

    //
    struct AMP1CSR {
        static const uint8_t address = 0x77;
        enum bits : uint8_t {
            AMP1TS0 = 1,   //
            AMP1TS1 = 2,   //
            AMP1G0  = 16,  //
            AMP1G1  = 32,  //
            AMP1IS  = 64,  //
            AMP1EN  = 128, //
        };
    };

    // ADC Data Register Bytes
    struct ADC {
        static const uint16_t address = 0x78;
    };

    // The ADC Control and Status register
    struct ADCSRA {
        static const uint8_t address = 0x7a;
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
        static const uint8_t address = 0x7b;
        enum bits : uint8_t {
            ADTS0 = 1,   // ADC Auto Trigger Source Selection 0
            ADTS1 = 2,   // ADC Auto Trigger Source Selection 1
            ADTS2 = 4,   // ADC Auto Trigger Source Selection 2
            ADTS3 = 8,   // ADC Auto Trigger Source Selection 3
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
            ADLAR = 32,  // Left Adjust Result
            REFS0 = 64,  // Reference Selection Bits
            REFS1 = 128, // Reference Selection Bits
        };
    };

    // Digital Input Disable Register 0
    struct DIDR0 {
        static const uint8_t address = 0x7e;
        enum bits : uint8_t {
            ADC0D = 1,   //
            ADC1D = 2,   //
            ADC2D = 4,   //
            ADC3D = 8,   //
            ADC4D = 16,  //
            ADC5D = 32,  //
            ADC6D = 64,  //
            ADC7D = 128, //
        };
    };

    // Digital Input Disable Register 1
    struct DIDR1 {
        static const uint8_t address = 0x7f;
        enum bits : uint8_t {
            ADC8D  = 1,  //
            ADC9D  = 2,  //
            ADC10D = 4,  //
            AMP0ND = 8,  //
            AMP0PD = 16, //
            ACMP0D = 32, //
        };
    };

    // Timer/Counter1 Control Register A
    struct TCCR1A {
        static const uint8_t address = 0x80;
        enum bits : uint8_t {
            WGM10  = 1,   // Waveform Generation Mode
            WGM11  = 2,   // Waveform Generation Mode
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

    // Timer/Counter1 Control Register C
    struct TCCR1C {
        static const uint8_t address = 0x82;
        enum bits : uint8_t {
            FOC1B = 64,  //
            FOC1A = 128, //
        };
    };

    // Timer/Counter1 Bytes
    struct TCNT1 {
        static const uint16_t address = 0x84;
        enum bits : uint8_t {
            TCNT10 = 1,   // Timer/Counter1
            TCNT11 = 2,   // Timer/Counter1
            TCNT12 = 4,   // Timer/Counter1
            TCNT13 = 8,   // Timer/Counter1
            TCNT14 = 16,  // Timer/Counter1
            TCNT15 = 32,  // Timer/Counter1
            TCNT16 = 64,  // Timer/Counter1
            TCNT17 = 128, // Timer/Counter1
        };
    };

    // Timer/Counter1 Input Capture Register Bytes
    struct ICR1 {
        static const uint16_t address = 0x86;
        enum bits : uint8_t {
            ICR10 = 1,   // Timer/Counter Input Capture
            ICR11 = 2,   // Timer/Counter Input Capture
            ICR12 = 4,   // Timer/Counter Input Capture
            ICR13 = 8,   // Timer/Counter Input Capture
            ICR14 = 16,  // Timer/Counter Input Capture
            ICR15 = 32,  // Timer/Counter Input Capture
            ICR16 = 64,  // Timer/Counter Input Capture
            ICR17 = 128, // Timer/Counter Input Capture
        };
    };

    // Timer/Counter1 Output Compare Register Bytes
    struct OCR1A {
        static const uint16_t address = 0x88;
        enum bits : uint8_t {
            OCR1A0 = 1,   // Timer/Counter1 Output Compare A Register
            OCR1A1 = 2,   // Timer/Counter1 Output Compare A Register
            OCR1A2 = 4,   // Timer/Counter1 Output Compare A Register
            OCR1A3 = 8,   // Timer/Counter1 Output Compare A Register
            OCR1A4 = 16,  // Timer/Counter1 Output Compare A Register
            OCR1A5 = 32,  // Timer/Counter1 Output Compare A Register
            OCR1A6 = 64,  // Timer/Counter1 Output Compare A Register
            OCR1A7 = 128, // Timer/Counter1 Output Compare A Register
        };
    };

    // Timer/Counter1 Output Compare Register Bytes
    struct OCR1B {
        static const uint16_t address = 0x8a;
        enum bits : uint8_t {
            OCR1B0 = 1,   // Timer/Counter1 Output Compare B Register
            OCR1B1 = 2,   // Timer/Counter1 Output Compare B Register
            OCR1B2 = 4,   // Timer/Counter1 Output Compare B Register
            OCR1B3 = 8,   // Timer/Counter1 Output Compare B Register
            OCR1B4 = 16,  // Timer/Counter1 Output Compare B Register
            OCR1B5 = 32,  // Timer/Counter1 Output Compare B Register
            OCR1B6 = 64,  // Timer/Counter1 Output Compare B Register
            OCR1B7 = 128, // Timer/Counter1 Output Compare B Register
        };
    };

    // PSC0 Interrupt Flag Register
    struct PIFR0 {
        static const uint8_t address = 0xa0;
        enum bits : uint8_t {
            PEOP0  = 1,   // End of PSC0 Interrupt
            PRN00  = 2,   // Ramp Number
            PRN01  = 4,   // Ramp Number
            PEV0A  = 8,   // External Event A Interrupt
            PEV0B  = 16,  // External Event B Interrupt
            PSEI0  = 32,  // PSC 0 Synchro Error Interrupt
            POAC0A = 64,  // PSC 0 Output A Activity
            POAC0B = 128, // PSC 0 Output A Activity
        };
    };

    // PSC0 Interrupt Mask Register
    struct PIM0 {
        static const uint8_t address = 0xa1;
        enum bits : uint8_t {
            PEOPE0 = 1,  // End of Cycle Interrupt Enable
            PEVE0A = 8,  // External Event A Interrupt Enable
            PEVE0B = 16, // External Event B Interrupt Enable
            PSEIE0 = 32, // PSC 0 Synchro Error Interrupt Enable
        };
    };

    // PSC2 Interrupt Flag Register
    struct PIFR2 {
        static const uint8_t address = 0xa4;
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

    // PSC2 Interrupt Mask Register
    struct PIM2 {
        static const uint8_t address = 0xa5;
        enum bits : uint8_t {
            PEOPE2 = 1,  // End of Cycle Interrupt Enable
            PEVE2A = 8,  // External Event A Interrupt Enable
            PEVE2B = 16, // External Event B Interrupt Enable
            PSEIE2 = 32, // PSC 2 Synchro Error Interrupt Enable
        };
    };

    // DAC Control Register
    struct DACON {
        static const uint8_t address = 0xaa;
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

    // DAC Data Register Bytes
    struct DAC {
        static const uint8_t address = 0xab;
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
        static const uint8_t address = 0xad;
        enum bits : uint8_t {
            AC0M0  = 1,   // Analog Comparator 0 Multiplexer Register
            AC0M1  = 2,   // Analog Comparator 0 Multiplexer Register
            AC0M2  = 4,   // Analog Comparator 0 Multiplexer Register
            AC0IS0 = 16,  // Analog Comparator 0  Interrupt Select Bit
            AC0IS1 = 32,  // Analog Comparator 0  Interrupt Select Bit
            AC0IE  = 64,  // Analog Comparator 0 Interrupt Enable Bit
            AC0EN  = 128, // Analog Comparator 0 Enable Bit
        };
    };

    // Analog Comparator 1 Control Register
    struct AC1CON {
        static const uint8_t address = 0xae;
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
        static const uint8_t address = 0xaf;
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

    // USART Control and Status register A
    struct UCSRA {
        static const uint8_t address = 0xc0;
        enum bits : uint8_t {
            MPCM = 1,   // Multi-processor Communication Mode
            U2X  = 2,   // Double USART Transmission Bit
            UPE  = 4,   // USART Parity Error
            DOR  = 8,   // Data Overrun
            FE   = 16,  // Framing Error
            UDRE = 32,  // USART Data Register Empty
            TXC  = 64,  // USART Transmitt Complete
            RXC  = 128, // USART Receive Complete
        };
    };

    // USART Control an Status register B
    struct UCSRB {
        static const uint8_t address = 0xc1;
        enum bits : uint8_t {
            TXB8  = 1,   // Transmit Data Bit 8
            RXB8  = 2,   // Receive Data Bit 8
            UCSZ2 = 4,   // Character Size
            TXEN  = 8,   // Transmitter Enable
            RXEN  = 16,  // Receiver Enable
            UDRIE = 32,  // USART Data Register Empty Interrupt Enable
            TXCIE = 64,  // TX Complete Interrupt Enable
            RXCIE = 128, // RX Complete Interrupt Enable
        };
    };

    // USART Control an Status register C
    struct UCSRC {
        static const uint8_t address = 0xc2;
        enum bits : uint8_t {
            UCPOL  = 1,  // Clock Polarity
            UCSZ0  = 2,  // Character Size Bits
            UCSZ1  = 4,  // Character Size Bits
            USBS   = 8,  // Stop Bit Select
            UPM0   = 16, // Parity Mode Bits
            UPM1   = 32, // Parity Mode Bits
            UMSEL0 = 64, // USART Mode Select
        };
    };

    // USART Baud Rate Register Low Byte
    struct UBRRL {
        static const uint8_t address = 0xc4;
        enum bits : uint8_t {
            UBRR0 = 1,   // USART Baud Rate Register bits
            UBRR1 = 2,   // USART Baud Rate Register bits
            UBRR2 = 4,   // USART Baud Rate Register bits
            UBRR3 = 8,   // USART Baud Rate Register bits
            UBRR4 = 16,  // USART Baud Rate Register bits
            UBRR5 = 32,  // USART Baud Rate Register bits
            UBRR6 = 64,  // USART Baud Rate Register bits
            UBRR7 = 128, // USART Baud Rate Register bits
        };
    };

    // USART Baud Rate Register High Byte
    struct UBRRH {
        static const uint8_t address = 0xc5;
        enum bits : uint8_t {
            UBRR0 = 1, // USART Baud Rate Register Bits
            UBRR1 = 2, // USART Baud Rate Register Bits
            UBRR2 = 4, // USART Baud Rate Register Bits
            UBRR3 = 8, // USART Baud Rate Register Bits
        };
    };

    // USART I/O Data Register
    struct UDR {
        static const uint8_t address = 0xc6;
    };

    // EUSART Control and Status Register A
    struct EUCSRA {
        static const uint8_t address = 0xc8;
        enum bits : uint8_t {
            URxS0 = 1,   // EUSART Control and Status Register A Bits
            URxS1 = 2,   // EUSART Control and Status Register A Bits
            URxS2 = 4,   // EUSART Control and Status Register A Bits
            URxS3 = 8,   // EUSART Control and Status Register A Bits
            UTxS0 = 16,  // EUSART Control and Status Register A Bits
            UTxS1 = 32,  // EUSART Control and Status Register A Bits
            UTxS2 = 64,  // EUSART Control and Status Register A Bits
            UTxS3 = 128, // EUSART Control and Status Register A Bits
        };
    };

    // EUSART Control Register B
    struct EUCSRB {
        static const uint8_t address = 0xc9;
        enum bits : uint8_t {
            BODR   = 1,  // Order Bit
            EMCH   = 2,  // Manchester Mode Bit
            EUSBS  = 8,  // EUSBS Enable Bit
            EUSART = 16, // EUSART Enable Bit
        };
    };

    // EUSART Status Register C
    struct EUCSRC {
        static const uint8_t address = 0xca;
        enum bits : uint8_t {
            STP0  = 1, // Stop Bits
            STP1  = 2, // Stop Bits
            F1617 = 4, // F1617 Bit
            FEM   = 8, // Frame Error Manchester Bit
        };
    };

    // Manchester Receiver Baud Rate Register Low Byte
    struct MUBRRL {
        static const uint8_t address = 0xcc;
        enum bits : uint8_t {
            MUBRR0 = 1,   // Manchester Receiver Baud Rate Register Bits
            MUBRR1 = 2,   // Manchester Receiver Baud Rate Register Bits
            MUBRR2 = 4,   // Manchester Receiver Baud Rate Register Bits
            MUBRR3 = 8,   // Manchester Receiver Baud Rate Register Bits
            MUBRR4 = 16,  // Manchester Receiver Baud Rate Register Bits
            MUBRR5 = 32,  // Manchester Receiver Baud Rate Register Bits
            MUBRR6 = 64,  // Manchester Receiver Baud Rate Register Bits
            MUBRR7 = 128, // Manchester Receiver Baud Rate Register Bits
        };
    };

    // Manchester Receiver Baud Rate Register High Byte
    struct MUBRRH {
        static const uint8_t address = 0xcd;
        enum bits : uint8_t {
            MUBRR0 = 1,   // Manchester Receiver Baud Rate Register Bits
            MUBRR1 = 2,   // Manchester Receiver Baud Rate Register Bits
            MUBRR2 = 4,   // Manchester Receiver Baud Rate Register Bits
            MUBRR3 = 8,   // Manchester Receiver Baud Rate Register Bits
            MUBRR4 = 16,  // Manchester Receiver Baud Rate Register Bits
            MUBRR5 = 32,  // Manchester Receiver Baud Rate Register Bits
            MUBRR6 = 64,  // Manchester Receiver Baud Rate Register Bits
            MUBRR7 = 128, // Manchester Receiver Baud Rate Register Bits
        };
    };

    // EUSART I/O Data Register
    struct EUDR {
        static const uint8_t address = 0xce;
    };

    // PSC0 Synchro and Output Configuration
    struct PSOC0 {
        static const uint8_t address = 0xd0;
        enum bits : uint8_t {
            POEN0A  = 1,  // PSCOUT00 Output Enable
            POEN0B  = 4,  // PSCOUT01 Output Enable
            PSYNC00 = 16, // Synchronization Out for ADC Selection
            PSYNC01 = 32, // Synchronization Out for ADC Selection
        };
    };

    // Output Compare SA Register
    struct OCR0SA {
        static const uint16_t address = 0xd2;
    };

    // Output Compare RA Register
    struct OCR0RA {
        static const uint16_t address = 0xd4;
    };

    // Output Compare SB Register
    struct OCR0SB {
        static const uint16_t address = 0xd6;
    };

    // Output Compare RB Register
    struct OCR0RB {
        static const uint16_t address = 0xd8;
    };

    // PSC 0 Configuration Register
    struct PCNF0 {
        static const uint8_t address = 0xda;
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
        static const uint8_t address = 0xdb;
        enum bits : uint8_t {
            PRUN0  = 1,   // PSC 0 Run
            PCCYC0 = 2,   // PSC0 Complete Cycle
            PARUN0 = 4,   // PSC0 Auto Run
            PAOC0A = 8,   // PSC 0 Asynchronous Output Control A
            PAOC0B = 16,  // PSC 0 Asynchronous Output Control B
            PBFM0  = 32,  // PSC 0 Balance Flank Width Modulation
            PPRE00 = 64,  // PSC 0 Prescaler Selects
            PPRE01 = 128, // PSC 0 Prescaler Selects
        };
    };

    // PSC 0 Input A Control
    struct PFRC0A {
        static const uint8_t address = 0xdc;
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
        static const uint8_t address = 0xdd;
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

    // PSC 0 Input Capture Register
    struct PICR0 {
        static const uint16_t address = 0xde;
        enum bits : uint8_t {
            PICR00 = 1,     // PSC 0 Input Capture Bytes
            PICR01 = 2,     // PSC 0 Input Capture Bytes
            PICR02 = 4,     // PSC 0 Input Capture Bytes
            PICR03 = 8,     // PSC 0 Input Capture Bytes
            PICR04 = 16,    // PSC 0 Input Capture Bytes
            PICR05 = 32,    // PSC 0 Input Capture Bytes
            PICR06 = 64,    // PSC 0 Input Capture Bytes
            PICR07 = 128,   // PSC 0 Input Capture Bytes
            PCST0  = 32768, // PSC 0 Input Capture Software Trig
        };
    };

    // PSC2 Synchro and Output Configuration
    struct PSOC2 {
        static const uint8_t address = 0xf0;
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
        static const uint8_t address = 0xf1;
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

    // Output Compare SA Register
    struct OCR2SA {
        static const uint16_t address = 0xf2;
    };

    // Output Compare RA Register
    struct OCR2RA {
        static const uint16_t address = 0xf4;
    };

    // Output Compare SB Register
    struct OCR2SB {
        static const uint16_t address = 0xf6;
    };

    // Output Compare RB Register
    struct OCR2RB {
        static const uint16_t address = 0xf8;
    };

    // PSC 2 Configuration Register
    struct PCNF2 {
        static const uint8_t address = 0xfa;
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
        static const uint8_t address = 0xfb;
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

    // PSC 2 Input B Control
    struct PFRC2A {
        static const uint8_t address = 0xfc;
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
        static const uint8_t address = 0xfd;
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

    // PSC 2 Input Capture Register
    struct PICR2 {
        static const uint16_t address = 0xfe;
        enum bits : uint8_t {
            PICR20 = 1,     // PSC 2 Input Capture Bytes
            PICR21 = 2,     // PSC 2 Input Capture Bytes
            PICR22 = 4,     // PSC 2 Input Capture Bytes
            PICR23 = 8,     // PSC 2 Input Capture Bytes
            PICR24 = 16,    // PSC 2 Input Capture Bytes
            PICR25 = 32,    // PSC 2 Input Capture Bytes
            PICR26 = 64,    // PSC 2 Input Capture Bytes
            PICR27 = 128,   // PSC 2 Input Capture Bytes
            PCST2  = 32768, // PSC 2 Input Capture Software Trig
        };
    };

}

#endif
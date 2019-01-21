#ifndef atmega1284p_sfr_h
#define atmega1284p_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega1284P
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
            OCF1A = 2,  // Timer/Counter1 Output Compare A Match Flag
            OCF1B = 4,  // Timer/Counter1 Output Compare B Match Flag
            ICF1  = 32, // Timer/Counter1 Input Capture Flag
        };
    };

    // Timer/Counter Interrupt Flag Register
    struct TIFR2 {
        static const uint8_t address = 0x37;
        enum bits : uint8_t {
            TOV2  = 1, // Timer/Counter2 Overflow Flag
            OCF2A = 2, // Output Compare Flag 2A
            OCF2B = 4, // Output Compare Flag 2B
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR3 {
        static const uint8_t address = 0x38;
        enum bits : uint8_t {
            TOV3  = 1,  // Timer/Counter3 Overflow Flag
            OCF3A = 2,  // Timer/Counter3 Output Compare A Match Flag
            OCF3B = 4,  // Timer/Counter3 Output Compare B Match Flag
            ICF3  = 32, // Timer/Counter3 Input Capture Flag
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
        };
    };

    // External Interrupt Mask Register
    struct EIMSK {
        static const uint8_t address = 0x3d;
        enum bits : uint8_t {
            INT0 = 1, // External Interrupt Request 2 Enable
            INT1 = 2, // External Interrupt Request 2 Enable
            INT2 = 4, // External Interrupt Request 2 Enable
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
            EEPE  = 2,  // EEPROM Write Enable
            EEMPE = 4,  // EEPROM Master Write Enable
            EERIE = 8,  // EEPROM Ready Interrupt Enable
            EEPM0 = 16, // EEPROM Programming Mode Bits
            EEPM1 = 32, // EEPROM Programming Mode Bits
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

    // EEPROM Address Register Low Bytes
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
            PSRSYNC = 1,   // Prescaler Reset Timer/Counter1 and Timer/Counter0
            PSRASY  = 2,   // Prescaler Reset Timer/Counter2
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
            OCR0A0 = 1,   // Timer/Counter0 Output Compare A bits
            OCR0A1 = 2,   // Timer/Counter0 Output Compare A bits
            OCR0A2 = 4,   // Timer/Counter0 Output Compare A bits
            OCR0A3 = 8,   // Timer/Counter0 Output Compare A bits
            OCR0A4 = 16,  // Timer/Counter0 Output Compare A bits
            OCR0A5 = 32,  // Timer/Counter0 Output Compare A bits
            OCR0A6 = 64,  // Timer/Counter0 Output Compare A bits
            OCR0A7 = 128, // Timer/Counter0 Output Compare A bits
        };
    };

    // Timer/Counter0 Output Compare Register B
    struct OCR0B {
        static const uint8_t address = 0x48;
        enum bits : uint8_t {
            OCR0B0 = 1,   // Timer/Counter0 Output Compare B bits
            OCR0B1 = 2,   // Timer/Counter0 Output Compare B bits
            OCR0B2 = 4,   // Timer/Counter0 Output Compare B bits
            OCR0B3 = 8,   // Timer/Counter0 Output Compare B bits
            OCR0B4 = 16,  // Timer/Counter0 Output Compare B bits
            OCR0B5 = 32,  // Timer/Counter0 Output Compare B bits
            OCR0B6 = 64,  // Timer/Counter0 Output Compare B bits
            OCR0B7 = 128, // Timer/Counter0 Output Compare B bits
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
            BODSE = 32,  // BOD Power Down in Sleep Enable
            BODS  = 64,  // BOD Power Down in Sleep
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
            SIGRD  = 32,  // Signature Row Read
            RWWSB  = 64,  // Read While Write Section Busy
            SPMIE  = 128, // SPM Interrupt Enable
        };
    };

    // RAM Page Z Select Register
    struct RAMPZ {
        static const uint8_t address = 0x5b;
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

    // Power Reduction Register0
    struct PRR0 {
        static const uint8_t address = 0x64;
        enum bits : uint8_t {
            PRADC    = 1,   // Power Reduction ADC
            PRUSART0 = 2,   // Power Reduction USART0
            PRSPI    = 4,   // Power Reduction Serial Peripheral Interface
            PRTIM1   = 8,   // Power Reduction Timer/Counter1
            PRUSART1 = 16,  // Power Reduction USART1
            PRTIM0   = 32,  // Power Reduction Timer/Counter0
            PRTIM2   = 64,  // Power Reduction Timer/Counter2
            PRTWI    = 128, // Power Reduction TWI
        };
    };

    // Power Reduction Register1
    struct PRR1 {
        static const uint8_t address = 0x65;
        enum bits : uint8_t {
            PRTIM3 = 1, // Power Reduction Timer/Counter3
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

    // External Interrupt Control Register A
    struct EICRA {
        static const uint8_t address = 0x69;
        enum bits : uint8_t {
            ISC00 = 1,  // External Interrupt Sense Control Bit
            ISC01 = 2,  // External Interrupt Sense Control Bit
            ISC10 = 4,  // External Interrupt Sense Control Bit
            ISC11 = 8,  // External Interrupt Sense Control Bit
            ISC20 = 16, // External Interrupt Sense Control Bit
            ISC21 = 32, // External Interrupt Sense Control Bit
        };
    };

    // Pin Change Mask Register 0
    struct PCMSK0 {
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

    // Pin Change Mask Register 1
    struct PCMSK1 {
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

    // Pin Change Mask Register 2
    struct PCMSK2 {
        static const uint8_t address = 0x6d;
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

    // Timer/Counter0 Interrupt Mask Register
    struct TIMSK0 {
        static const uint8_t address = 0x6e;
        enum bits : uint8_t {
            TOIE0  = 1, // Timer/Counter0 Overflow Interrupt Enable
            OCIE0A = 2, // Timer/Counter0 Output Compare Match A Interrupt Enable
            OCIE0B = 4, // Timer/Counter0 Output Compare Match B Interrupt Enable
        };
    };

    // Timer/Counter1 Interrupt Mask Register
    struct TIMSK1 {
        static const uint8_t address = 0x6f;
        enum bits : uint8_t {
            TOIE1  = 1,  // Timer/Counter1 Overflow Interrupt Enable
            OCIE1A = 2,  // Timer/Counter1 Output Compare A Match Interrupt Enable
            OCIE1B = 4,  // Timer/Counter1 Output Compare B Match Interrupt Enable
            ICIE1  = 32, // Timer/Counter1 Input Capture Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Mask register
    struct TIMSK2 {
        static const uint8_t address = 0x70;
        enum bits : uint8_t {
            TOIE2  = 1, // Timer/Counter2 Overflow Interrupt Enable
            OCIE2A = 2, // Timer/Counter2 Output Compare Match A Interrupt Enable
            OCIE2B = 4, // Timer/Counter2 Output Compare Match B Interrupt Enable
        };
    };

    // Timer/Counter3 Interrupt Mask Register
    struct TIMSK3 {
        static const uint8_t address = 0x71;
        enum bits : uint8_t {
            TOIE3  = 1,  // Timer/Counter3 Overflow Interrupt Enable
            OCIE3A = 2,  // Timer/Counter3 Output Compare A Match Interrupt Enable
            OCIE3B = 4,  // Timer/Counter3 Output Compare B Match Interrupt Enable
            ICIE3  = 32, // Timer/Counter3 Input Capture Interrupt Enable
        };
    };

    // Pin Change Mask Register 3
    struct PCMSK3 {
        static const uint8_t address = 0x73;
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

    // The ADC Control and Status register A
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
            ADTS0 = 1,  // ADC Auto Trigger Source bits
            ADTS1 = 2,  // ADC Auto Trigger Source bits
            ADTS2 = 4,  // ADC Auto Trigger Source bits
            ACME  = 64, // Analog Comparator Multiplexer Enable
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

    // Digital Input Disable Register
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
            AIN0D = 1, // AIN0 Digital Input Disable
            AIN1D = 2, // AIN1 Digital Input Disable
        };
    };

    // Timer/Counter1 Control Register A
    struct TCCR1A {
        static const uint8_t address = 0x80;
        enum bits : uint8_t {
            WGM10  = 1,   // Pulse Width Modulator Select Bits
            WGM11  = 2,   // Pulse Width Modulator Select Bits
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
            CS10  = 1,   // Clock Select1 bits
            CS11  = 2,   // Clock Select1 bits
            CS12  = 4,   // Clock Select1 bits
            WGM10 = 8,   // Waveform Generation Mode Bits
            WGM11 = 16,  // Waveform Generation Mode Bits
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

    // Timer/Counter1 Input Capture Register Bytes
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

    // Timer/Counter1 Output Compare Register A Bytes
    struct OCR1A {
        static const uint16_t address = 0x88;
        enum bits : uint8_t {
            OCR1A0 = 1,   // Timer/Counter1 Output Compare A bits
            OCR1A1 = 2,   // Timer/Counter1 Output Compare A bits
            OCR1A2 = 4,   // Timer/Counter1 Output Compare A bits
            OCR1A3 = 8,   // Timer/Counter1 Output Compare A bits
            OCR1A4 = 16,  // Timer/Counter1 Output Compare A bits
            OCR1A5 = 32,  // Timer/Counter1 Output Compare A bits
            OCR1A6 = 64,  // Timer/Counter1 Output Compare A bits
            OCR1A7 = 128, // Timer/Counter1 Output Compare A bits
        };
    };

    // Timer/Counter1 Output Compare Register B Bytes
    struct OCR1B {
        static const uint16_t address = 0x8a;
        enum bits : uint8_t {
            OCR1B0 = 1,   // Timer/Counter1 Output Compare B bits
            OCR1B1 = 2,   // Timer/Counter1 Output Compare B bits
            OCR1B2 = 4,   // Timer/Counter1 Output Compare B bits
            OCR1B3 = 8,   // Timer/Counter1 Output Compare B bits
            OCR1B4 = 16,  // Timer/Counter1 Output Compare B bits
            OCR1B5 = 32,  // Timer/Counter1 Output Compare B bits
            OCR1B6 = 64,  // Timer/Counter1 Output Compare B bits
            OCR1B7 = 128, // Timer/Counter1 Output Compare B bits
        };
    };

    // Timer/Counter3 Control Register A
    struct TCCR3A {
        static const uint8_t address = 0x90;
        enum bits : uint8_t {
            WGM30  = 1,   // Pulse Width Modulator Select Bits
            WGM31  = 2,   // Pulse Width Modulator Select Bits
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
            CS30  = 1,   // Clock Select3 bits
            CS31  = 2,   // Clock Select3 bits
            CS32  = 4,   // Clock Select3 bits
            WGM30 = 8,   // Waveform Generation Mode Bits
            WGM31 = 16,  // Waveform Generation Mode Bits
            ICES3 = 64,  // Input Capture 3 Edge Select
            ICNC3 = 128, // Input Capture 3 Noise Canceler
        };
    };

    // Timer/Counter3 Control Register C
    struct TCCR3C {
        static const uint8_t address = 0x92;
        enum bits : uint8_t {
            FOC3B = 64,  // Force Output Compare for Channel B
            FOC3A = 128, // Force Output Compare for Channel A
        };
    };

    // Timer/Counter3 Bytes
    struct TCNT3 {
        static const uint16_t address = 0x94;
        enum bits : uint8_t {
            TCNT30 = 1,   // Timer/Counter3 bits
            TCNT31 = 2,   // Timer/Counter3 bits
            TCNT32 = 4,   // Timer/Counter3 bits
            TCNT33 = 8,   // Timer/Counter3 bits
            TCNT34 = 16,  // Timer/Counter3 bits
            TCNT35 = 32,  // Timer/Counter3 bits
            TCNT36 = 64,  // Timer/Counter3 bits
            TCNT37 = 128, // Timer/Counter3 bits
        };
    };

    // Timer/Counter3 Input Capture Register Bytes
    struct ICR3 {
        static const uint16_t address = 0x96;
        enum bits : uint8_t {
            ICR30 = 1,   // Timer/Counter3 Input Capture bits
            ICR31 = 2,   // Timer/Counter3 Input Capture bits
            ICR32 = 4,   // Timer/Counter3 Input Capture bits
            ICR33 = 8,   // Timer/Counter3 Input Capture bits
            ICR34 = 16,  // Timer/Counter3 Input Capture bits
            ICR35 = 32,  // Timer/Counter3 Input Capture bits
            ICR36 = 64,  // Timer/Counter3 Input Capture bits
            ICR37 = 128, // Timer/Counter3 Input Capture bits
        };
    };

    // Timer/Counter3 Output Compare Register A Bytes
    struct OCR3A {
        static const uint16_t address = 0x98;
        enum bits : uint8_t {
            OCR3A0 = 1,   // Timer/Counter3 Output Compare A bits
            OCR3A1 = 2,   // Timer/Counter3 Output Compare A bits
            OCR3A2 = 4,   // Timer/Counter3 Output Compare A bits
            OCR3A3 = 8,   // Timer/Counter3 Output Compare A bits
            OCR3A4 = 16,  // Timer/Counter3 Output Compare A bits
            OCR3A5 = 32,  // Timer/Counter3 Output Compare A bits
            OCR3A6 = 64,  // Timer/Counter3 Output Compare A bits
            OCR3A7 = 128, // Timer/Counter3 Output Compare A bits
        };
    };

    // Timer/Counter3 Output Compare Register B Bytes
    struct OCR3B {
        static const uint16_t address = 0x9a;
        enum bits : uint8_t {
            OCR3B0 = 1,   // Timer/Counter3 Output Compare B bits
            OCR3B1 = 2,   // Timer/Counter3 Output Compare B bits
            OCR3B2 = 4,   // Timer/Counter3 Output Compare B bits
            OCR3B3 = 8,   // Timer/Counter3 Output Compare B bits
            OCR3B4 = 16,  // Timer/Counter3 Output Compare B bits
            OCR3B5 = 32,  // Timer/Counter3 Output Compare B bits
            OCR3B6 = 64,  // Timer/Counter3 Output Compare B bits
            OCR3B7 = 128, // Timer/Counter3 Output Compare B bits
        };
    };

    // Timer/Counter2 Control Register A
    struct TCCR2A {
        static const uint8_t address = 0xb0;
        enum bits : uint8_t {
            WGM20  = 1,   // Waveform Genration Mode
            WGM21  = 2,   // Waveform Genration Mode
            COM2B0 = 16,  // Compare Output Mode bits
            COM2B1 = 32,  // Compare Output Mode bits
            COM2A0 = 64,  // Compare Output Mode bits
            COM2A1 = 128, // Compare Output Mode bits
        };
    };

    // Timer/Counter2 Control Register B
    struct TCCR2B {
        static const uint8_t address = 0xb1;
        enum bits : uint8_t {
            CS20  = 1,   // Clock Select bits
            CS21  = 2,   // Clock Select bits
            CS22  = 4,   // Clock Select bits
            WGM22 = 8,   // Waveform Generation Mode
            FOC2B = 64,  // Force Output Compare B
            FOC2A = 128, // Force Output Compare A
        };
    };

    // Timer/Counter2
    struct TCNT2 {
        static const uint8_t address = 0xb2;
        enum bits : uint8_t {
            TCNT20 = 1,   // Timer/Counter2 bits
            TCNT21 = 2,   // Timer/Counter2 bits
            TCNT22 = 4,   // Timer/Counter2 bits
            TCNT23 = 8,   // Timer/Counter2 bits
            TCNT24 = 16,  // Timer/Counter2 bits
            TCNT25 = 32,  // Timer/Counter2 bits
            TCNT26 = 64,  // Timer/Counter2 bits
            TCNT27 = 128, // Timer/Counter2 bits
        };
    };

    // Timer/Counter2 Output Compare Register A
    struct OCR2A {
        static const uint8_t address = 0xb3;
        enum bits : uint8_t {
            OCR2A0 = 1,   // Timer/Counter2 Output Compare A bits
            OCR2A1 = 2,   // Timer/Counter2 Output Compare A bits
            OCR2A2 = 4,   // Timer/Counter2 Output Compare A bits
            OCR2A3 = 8,   // Timer/Counter2 Output Compare A bits
            OCR2A4 = 16,  // Timer/Counter2 Output Compare A bits
            OCR2A5 = 32,  // Timer/Counter2 Output Compare A bits
            OCR2A6 = 64,  // Timer/Counter2 Output Compare A bits
            OCR2A7 = 128, // Timer/Counter2 Output Compare A bits
        };
    };

    // Timer/Counter2 Output Compare Register B
    struct OCR2B {
        static const uint8_t address = 0xb4;
        enum bits : uint8_t {
            OCR2B0 = 1,   // Timer/Counter2 Output Compare B bits
            OCR2B1 = 2,   // Timer/Counter2 Output Compare B bits
            OCR2B2 = 4,   // Timer/Counter2 Output Compare B bits
            OCR2B3 = 8,   // Timer/Counter2 Output Compare B bits
            OCR2B4 = 16,  // Timer/Counter2 Output Compare B bits
            OCR2B5 = 32,  // Timer/Counter2 Output Compare B bits
            OCR2B6 = 64,  // Timer/Counter2 Output Compare B bits
            OCR2B7 = 128, // Timer/Counter2 Output Compare B bits
        };
    };

    // Asynchronous Status Register
    struct ASSR {
        static const uint8_t address = 0xb6;
        enum bits : uint8_t {
            TCR2BUB = 1,  // Timer/Counter Control Register2 Update Busy
            TCR2AUB = 2,  // Timer/Counter Control Register2 Update Busy
            OCR2BUB = 4,  // Output Compare Register 2 Update Busy
            OCR2AUB = 8,  // Output Compare Register2 Update Busy
            TCN2UB  = 16, // Timer/Counter2 Update Busy
            AS2     = 32, // Asynchronous Timer/Counter2
            EXCLK   = 64, // Enable External Clock Input
        };
    };

    // TWI Bit Rate register
    struct TWBR {
        static const uint8_t address = 0xb8;
        enum bits : uint8_t {
            TWBR0 = 1,   // TWI Bit Rate bits
            TWBR1 = 2,   // TWI Bit Rate bits
            TWBR2 = 4,   // TWI Bit Rate bits
            TWBR3 = 8,   // TWI Bit Rate bits
            TWBR4 = 16,  // TWI Bit Rate bits
            TWBR5 = 32,  // TWI Bit Rate bits
            TWBR6 = 64,  // TWI Bit Rate bits
            TWBR7 = 128, // TWI Bit Rate bits
        };
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
        enum bits : uint8_t {
            TWD0 = 1,   // TWI Data bits
            TWD1 = 2,   // TWI Data bits
            TWD2 = 4,   // TWI Data bits
            TWD3 = 8,   // TWI Data bits
            TWD4 = 16,  // TWI Data bits
            TWD5 = 32,  // TWI Data bits
            TWD6 = 64,  // TWI Data bits
            TWD7 = 128, // TWI Data bits
        };
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

    // TWI (Slave) Address Mask Register
    struct TWAMR {
        static const uint8_t address = 0xbd;
        enum bits : uint8_t {
            TWAM0 = 2,   //
            TWAM1 = 4,   //
            TWAM2 = 8,   //
            TWAM3 = 16,  //
            TWAM4 = 32,  //
            TWAM5 = 64,  //
            TWAM6 = 128, //
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
            UCPOL0  = 1,   // Clock Polarity
            UCSZ00  = 2,   // Character Size
            UCSZ01  = 4,   // Character Size
            USBS0   = 8,   // Stop Bit Select
            UPM00   = 16,  // Parity Mode Bits
            UPM01   = 32,  // Parity Mode Bits
            UMSEL00 = 64,  // USART Mode Select
            UMSEL01 = 128, // USART Mode Select
        };
    };

    // USART Baud Rate Register Bytes
    struct UBRR0 {
        static const uint16_t address = 0xc4;
        enum bits : uint8_t {
            UBRR00 = 1,   // USART Baud Rate Register
            UBRR01 = 2,   // USART Baud Rate Register
            UBRR02 = 4,   // USART Baud Rate Register
            UBRR03 = 8,   // USART Baud Rate Register
            UBRR04 = 16,  // USART Baud Rate Register
            UBRR05 = 32,  // USART Baud Rate Register
            UBRR06 = 64,  // USART Baud Rate Register
            UBRR07 = 128, // USART Baud Rate Register
        };
    };

    // USART I/O Data Register
    struct UDR0 {
        static const uint8_t address = 0xc6;
        enum bits : uint8_t {
            UDR00 = 1,   // USART I/O Data bits
            UDR01 = 2,   // USART I/O Data bits
            UDR02 = 4,   // USART I/O Data bits
            UDR03 = 8,   // USART I/O Data bits
            UDR04 = 16,  // USART I/O Data bits
            UDR05 = 32,  // USART I/O Data bits
            UDR06 = 64,  // USART I/O Data bits
            UDR07 = 128, // USART I/O Data bits
        };
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
            UCPOL1  = 1,   // Clock Polarity
            UCSZ10  = 2,   // Character Size
            UCSZ11  = 4,   // Character Size
            USBS1   = 8,   // Stop Bit Select
            UPM10   = 16,  // Parity Mode Bits
            UPM11   = 32,  // Parity Mode Bits
            UMSEL10 = 64,  // USART Mode Select
            UMSEL11 = 128, // USART Mode Select
        };
    };

    // USART Baud Rate Register Bytes
    struct UBRR1 {
        static const uint16_t address = 0xcc;
        enum bits : uint8_t {
            UBRR10 = 1,   // USART Baud Rate Register
            UBRR11 = 2,   // USART Baud Rate Register
            UBRR12 = 4,   // USART Baud Rate Register
            UBRR13 = 8,   // USART Baud Rate Register
            UBRR14 = 16,  // USART Baud Rate Register
            UBRR15 = 32,  // USART Baud Rate Register
            UBRR16 = 64,  // USART Baud Rate Register
            UBRR17 = 128, // USART Baud Rate Register
        };
    };

    // USART I/O Data Register
    struct UDR1 {
        static const uint8_t address = 0xce;
        enum bits : uint8_t {
            UDR10 = 1,   // USART I/O Data bits
            UDR11 = 2,   // USART I/O Data bits
            UDR12 = 4,   // USART I/O Data bits
            UDR13 = 8,   // USART I/O Data bits
            UDR14 = 16,  // USART I/O Data bits
            UDR15 = 32,  // USART I/O Data bits
            UDR16 = 64,  // USART I/O Data bits
            UDR17 = 128, // USART I/O Data bits
        };
    };

}

#endif
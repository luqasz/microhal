#ifndef atmega16u4_sfr_h
#define atmega16u4_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega16U4
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

    // Timer/Counter0 Interrupt Flag register
    struct TIFR0 {
        static const uint8_t address = 0x35;
        enum bits : uint8_t {
            TOV0  = 1, // Timer/Counter0 Overflow Flag
            OCF0A = 2, // Timer/Counter0 Output Compare Flag 0A
            OCF0B = 4, // Timer/Counter0 Output Compare Flag 0B
        };
    };

    // Timer/Counter1 Interrupt Flag register
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

    // Timer/Counter3 Interrupt Flag register
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

    // Timer/Counter4 Interrupt Flag register
    struct TIFR4 {
        static const uint8_t address = 0x39;
        enum bits : uint8_t {
            TOV4  = 4,   // Timer/Counter4 Overflow Flag
            OCF4B = 32,  // Output Compare Flag 4B
            OCF4A = 64,  // Output Compare Flag 4A
            OCF4D = 128, // Output Compare Flag 4D
        };
    };

    // Pin Change Interrupt Flag Register
    struct PCIFR {
        static const uint8_t address = 0x3b;
        enum bits : uint8_t {
            PCIF0 = 1, // Pin Change Interrupt Flag 0
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

    // EEPROM Address Register Low Bytes
    struct EEAR {
        static const uint16_t address = 0x41;
        enum bits : uint8_t {
            EEAR0 = 1,   // EEPROM Address Bits
            EEAR1 = 2,   // EEPROM Address Bits
            EEAR2 = 4,   // EEPROM Address Bits
            EEAR3 = 8,   // EEPROM Address Bits
            EEAR4 = 16,  // EEPROM Address Bits
            EEAR5 = 32,  // EEPROM Address Bits
            EEAR6 = 64,  // EEPROM Address Bits
            EEAR7 = 128, // EEPROM Address Bits
        };
    };

    // General Timer/Counter Control Register
    struct GTCCR {
        static const uint8_t address = 0x43;
        enum bits : uint8_t {
            PSRSYNC = 1,   // Prescaler Reset Timer/Counter1 and Timer/Counter0
            TSM     = 128, // Timer/Counter Synchronization Mode
        };
    };

    // Timer/Counter  Control Register A
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

    // Timer/Counter0 Output Compare Register
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

    // Timer/Counter0 Output Compare Register
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

    // PLL Status and Control register
    struct PLLCSR {
        static const uint8_t address = 0x49;
        enum bits : uint8_t {
            PLOCK  = 1,  // PLL Lock Status Bit
            PLLE   = 2,  // PLL Enable Bit
            PINDIV = 16, // PLL prescaler Bit 2
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
            SPDR0 = 1,   // SPI Data bits
            SPDR1 = 2,   // SPI Data bits
            SPDR2 = 4,   // SPI Data bits
            SPDR3 = 8,   // SPI Data bits
            SPDR4 = 16,  // SPI Data bits
            SPDR5 = 32,  // SPI Data bits
            SPDR6 = 64,  // SPI Data bits
            SPDR7 = 128, // SPI Data bits
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

    // PLL Frequency Control Register
    struct PLLFRQ {
        static const uint8_t address = 0x52;
        enum bits : uint8_t {
            PDIV0  = 1,   //
            PDIV1  = 2,   //
            PDIV2  = 4,   //
            PDIV3  = 8,   //
            PLLTM0 = 16,  //
            PLLTM1 = 32,  //
            PLLUSB = 64,  //
            PINMUX = 128, //
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
            SIGRD  = 32,  // Signature Row Read
            RWWSB  = 64,  // Read While Write Section Busy
            SPMIE  = 128, // SPM Interrupt Enable
        };
    };

    // Extended Z-pointer Register for ELPM/SPM
    struct RAMPZ {
        static const uint8_t address = 0x5b;
        enum bits : uint8_t {
            RAMPZ0 = 1, // Extended Z-Pointer Value
            RAMPZ1 = 2, // Extended Z-Pointer Value
        };
    };

    // Extended Indirect Register
    struct EIND {
        static const uint8_t address = 0x5c;
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
            PRUSART0 = 2,   // Power Reduction USART
            PRSPI    = 4,   // Power Reduction Serial Peripheral Interface
            PRTIM1   = 8,   // Power Reduction Timer/Counter1
            PRTIM0   = 32,  // Power Reduction Timer/Counter0
            PRTIM2   = 64,  // Power Reduction Timer/Counter2
            PRTWI    = 128, // Power Reduction TWI
        };
    };

    // Power Reduction Register1
    struct PRR1 {
        static const uint8_t address = 0x65;
        enum bits : uint8_t {
            PRUSART1 = 1,   // Power Reduction USART1
            PRTIM3   = 8,   // Power Reduction Timer/Counter3
            PRTIM4   = 16,  // Power Reduction Timer/Counter4
            PRUSB    = 128, // Power Reduction USB
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

    // Oscillator Control Register
    struct RCCTRL {
        static const uint8_t address = 0x67;
        enum bits : uint8_t {
            RCFREQ = 1, //
        };
    };

    // Pin Change Interrupt Control Register
    struct PCICR {
        static const uint8_t address = 0x68;
        enum bits : uint8_t {
            PCIE0 = 1, // Pin Change Interrupt Enable 0
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

    // Pin Change Mask Register 0
    struct PCMSK0 {
        static const uint8_t address = 0x6b;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Mask 0
            PCINT1 = 2,   // Pin Change Mask 0
            PCINT2 = 4,   // Pin Change Mask 0
            PCINT3 = 8,   // Pin Change Mask 0
            PCINT4 = 16,  // Pin Change Mask 0
            PCINT5 = 32,  // Pin Change Mask 0
            PCINT6 = 64,  // Pin Change Mask 0
            PCINT7 = 128, // Pin Change Mask 0
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
            OCIE1C = 8,  // Timer/Counter1 Output Compare C Match Interrupt Enable
            ICIE1  = 32, // Timer/Counter1 Input Capture Interrupt Enable
        };
    };

    // Timer/Counter3 Interrupt Mask Register
    struct TIMSK3 {
        static const uint8_t address = 0x71;
        enum bits : uint8_t {
            TOIE3  = 1,  // Timer/Counter3 Overflow Interrupt Enable
            OCIE3A = 2,  // Timer/Counter3 Output Compare A Match Interrupt Enable
            OCIE3B = 4,  // Timer/Counter3 Output Compare B Match Interrupt Enable
            OCIE3C = 8,  // Timer/Counter3 Output Compare C Match Interrupt Enable
            ICIE3  = 32, // Timer/Counter3 Input Capture Interrupt Enable
        };
    };

    // Timer/Counter4 Interrupt Mask Register
    struct TIMSK4 {
        static const uint8_t address = 0x72;
        enum bits : uint8_t {
            TOIE4  = 4,   // Timer/Counter4 Overflow Interrupt Enable
            OCIE4B = 32,  // Timer/Counter4 Output Compare B Match Interrupt Enable
            OCIE4A = 64,  // Timer/Counter4 Output Compare A Match Interrupt Enable
            OCIE4D = 128, // Timer/Counter4 Output Compare D Match Interrupt Enable
        };
    };

    // ADC Data Register  Bytes
    struct ADC {
        static const uint16_t address = 0x78;
        enum bits : uint8_t {
            ADC0 = 1,   // ADC Data Bits
            ADC1 = 2,   // ADC Data Bits
            ADC2 = 4,   // ADC Data Bits
            ADC3 = 8,   // ADC Data Bits
            ADC4 = 16,  // ADC Data Bits
            ADC5 = 32,  // ADC Data Bits
            ADC6 = 64,  // ADC Data Bits
            ADC7 = 128, // ADC Data Bits
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
            ADTS0 = 1,   // ADC Auto Trigger Sources
            ADTS1 = 2,   // ADC Auto Trigger Sources
            ADTS2 = 4,   // ADC Auto Trigger Sources
            ADTS3 = 8,   // ADC Auto Trigger Sources
            MUX5  = 32,  // Analog Channel and Gain Selection Bits
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
    struct DIDR2 {
        static const uint8_t address = 0x7d;
        enum bits : uint8_t {
            ADC8D  = 1,  // ADC8 Digital input Disable
            ADC9D  = 2,  // ADC9 Digital input Disable
            ADC10D = 4,  // ADC10 Digital input Disable
            ADC11D = 8,  // ADC11 Digital input Disable
            ADC12D = 16, // ADC12 Digital input Disable
            ADC13D = 32, // ADC13 Digital input Disable
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

    // Timer/Counter1 Output Compare Register C Bytes
    struct OCR1C {
        static const uint16_t address = 0x8c;
        enum bits : uint8_t {
            OCR1C0 = 1,   // Timer/Counter1 Output Compare C bits
            OCR1C1 = 2,   // Timer/Counter1 Output Compare C bits
            OCR1C2 = 4,   // Timer/Counter1 Output Compare C bits
            OCR1C3 = 8,   // Timer/Counter1 Output Compare C bits
            OCR1C4 = 16,  // Timer/Counter1 Output Compare C bits
            OCR1C5 = 32,  // Timer/Counter1 Output Compare C bits
            OCR1C6 = 64,  // Timer/Counter1 Output Compare C bits
            OCR1C7 = 128, // Timer/Counter1 Output Compare C bits
        };
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
            COM3A0 = 64,  // Compare Output Mode 1A, bits
            COM3A1 = 128, // Compare Output Mode 1A, bits
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

    // Timer/Counter3 Input Capture Register  Bytes
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

    // Timer/Counter3 Output Compare Register A  Bytes
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

    // Timer/Counter3 Output Compare Register C Bytes
    struct OCR3C {
        static const uint16_t address = 0x9c;
        enum bits : uint8_t {
            OCR3C0 = 1,   // Timer/Counter3 Output Compare C bits
            OCR3C1 = 2,   // Timer/Counter3 Output Compare C bits
            OCR3C2 = 4,   // Timer/Counter3 Output Compare C bits
            OCR3C3 = 8,   // Timer/Counter3 Output Compare C bits
            OCR3C4 = 16,  // Timer/Counter3 Output Compare C bits
            OCR3C5 = 32,  // Timer/Counter3 Output Compare C bits
            OCR3C6 = 64,  // Timer/Counter3 Output Compare C bits
            OCR3C7 = 128, // Timer/Counter3 Output Compare C bits
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

    // Timer/Counter4 Low Bytes
    struct TCNT4 {
        static const uint8_t address = 0xbe;
        enum bits : uint8_t {
            TC40 = 1,   // Timer/Counter4 bits
            TC41 = 2,   // Timer/Counter4 bits
            TC42 = 4,   // Timer/Counter4 bits
            TC43 = 8,   // Timer/Counter4 bits
            TC44 = 16,  // Timer/Counter4 bits
            TC45 = 32,  // Timer/Counter4 bits
            TC46 = 64,  // Timer/Counter4 bits
            TC47 = 128, // Timer/Counter4 bits
        };
    };

    // Timer/Counter4
    struct TC4H {
        static const uint8_t address = 0xbf;
        enum bits : uint8_t {
            TC40 = 1, // Timer/Counter4 bits
            TC41 = 2, // Timer/Counter4 bits
            TC42 = 4, // Timer/Counter4 bits
        };
    };

    // Timer/Counter4 Control Register A
    struct TCCR4A {
        static const uint8_t address = 0xc0;
        enum bits : uint8_t {
            PWM4B  = 1,   //
            PWM4A  = 2,   //
            FOC4B  = 4,   // Force Output Compare Match 4B
            FOC4A  = 8,   // Force Output Compare Match 4A
            COM4B0 = 16,  // Compare Output Mode 4B, bits
            COM4B1 = 32,  // Compare Output Mode 4B, bits
            COM4A0 = 64,  // Compare Output Mode 1A, bits
            COM4A1 = 128, // Compare Output Mode 1A, bits
        };
    };

    // Timer/Counter4 Control Register B
    struct TCCR4B {
        static const uint8_t address = 0xc1;
        enum bits : uint8_t {
            CS40   = 1,   // Clock Select Bits
            CS41   = 2,   // Clock Select Bits
            CS42   = 4,   // Clock Select Bits
            CS43   = 8,   // Clock Select Bits
            DTPS40 = 16,  // Dead Time Prescaler Bits
            DTPS41 = 32,  // Dead Time Prescaler Bits
            PSR4   = 64,  // Prescaler Reset Timer/Counter 4
            PWM4X  = 128, // PWM Inversion Mode
        };
    };

    // Timer/Counter 4 Control Register C
    struct TCCR4C {
        static const uint8_t address = 0xc2;
        enum bits : uint8_t {
            PWM4D   = 1,   // Pulse Width Modulator D Enable
            FOC4D   = 2,   // Force Output Compare Match 4D
            COM4D0  = 4,   // Comparator D Output Mode
            COM4D1  = 8,   // Comparator D Output Mode
            COM4B0S = 16,  // Comparator B Output Mode
            COM4B1S = 32,  // Comparator B Output Mode
            COM4A0S = 64,  // Comparator A Output Mode
            COM4A1S = 128, // Comparator A Output Mode
        };
    };

    // Timer/Counter 4 Control Register D
    struct TCCR4D {
        static const uint8_t address = 0xc3;
        enum bits : uint8_t {
            WGM40 = 1,   // Waveform Generation Mode bits
            WGM41 = 2,   // Waveform Generation Mode bits
            FPF4  = 4,   // Fault Protection Interrupt Flag
            FPAC4 = 8,   // Fault Protection Analog Comparator Enable
            FPES4 = 16,  // Fault Protection Edge Select
            FPNC4 = 32,  // Fault Protection Noise Canceler
            FPEN4 = 64,  // Fault Protection Mode Enable
            FPIE4 = 128, // Fault Protection Interrupt Enable
        };
    };

    // Timer/Counter 4 Control Register E
    struct TCCR4E {
        static const uint8_t address = 0xc4;
        enum bits : uint8_t {
            OC4OE0 = 1,   // Output Compare Override Enable bit
            OC4OE1 = 2,   // Output Compare Override Enable bit
            OC4OE2 = 4,   // Output Compare Override Enable bit
            OC4OE3 = 8,   // Output Compare Override Enable bit
            OC4OE4 = 16,  // Output Compare Override Enable bit
            OC4OE5 = 32,  // Output Compare Override Enable bit
            ENHC4  = 64,  // Enhanced Compare/PWM Mode
            TLOCK4 = 128, // Register Update Lock
        };
    };

    //
    struct CLKSEL0 {
        static const uint8_t address = 0xc5;
        enum bits : uint8_t {
            CLKS   = 1,   //
            EXTE   = 4,   //
            RCE    = 8,   //
            EXSUT0 = 16,  //
            EXSUT1 = 32,  //
            RCSUT0 = 64,  //
            RCSUT1 = 128, //
        };
    };

    //
    struct CLKSEL1 {
        static const uint8_t address = 0xc6;
        enum bits : uint8_t {
            EXCKSEL0 = 1,   //
            EXCKSEL1 = 2,   //
            EXCKSEL2 = 4,   //
            EXCKSEL3 = 8,   //
            RCCKSEL0 = 16,  //
            RCCKSEL1 = 32,  //
            RCCKSEL2 = 64,  //
            RCCKSEL3 = 128, //
        };
    };

    //
    struct CLKSTA {
        static const uint8_t address = 0xc7;
        enum bits : uint8_t {
            EXTON = 1, //
            RCON  = 2, //
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

    // USART Control and Status Register D
    struct UCSR1D {
        static const uint8_t address = 0xcb;
        enum bits : uint8_t {
            RTSEN = 1, // RTS Enable
            CTSEN = 2, // CTS Enable
        };
    };

    // USART Baud Rate Register  Bytes
    struct UBRR1 {
        static const uint16_t address = 0xcc;
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

    // Timer/Counter4 Output Compare Register A
    struct OCR4A {
        static const uint8_t address = 0xcf;
        enum bits : uint8_t {
            OCR4A0 = 1,   // Timer/Counter4 Output Compare A bits
            OCR4A1 = 2,   // Timer/Counter4 Output Compare A bits
            OCR4A2 = 4,   // Timer/Counter4 Output Compare A bits
            OCR4A3 = 8,   // Timer/Counter4 Output Compare A bits
            OCR4A4 = 16,  // Timer/Counter4 Output Compare A bits
            OCR4A5 = 32,  // Timer/Counter4 Output Compare A bits
            OCR4A6 = 64,  // Timer/Counter4 Output Compare A bits
            OCR4A7 = 128, // Timer/Counter4 Output Compare A bits
        };
    };

    // Timer/Counter4 Output Compare Register B
    struct OCR4B {
        static const uint8_t address = 0xd0;
        enum bits : uint8_t {
            OCR4B0 = 1,   // Timer/Counter4 Output Compare B bits
            OCR4B1 = 2,   // Timer/Counter4 Output Compare B bits
            OCR4B2 = 4,   // Timer/Counter4 Output Compare B bits
            OCR4B3 = 8,   // Timer/Counter4 Output Compare B bits
            OCR4B4 = 16,  // Timer/Counter4 Output Compare B bits
            OCR4B5 = 32,  // Timer/Counter4 Output Compare B bits
            OCR4B6 = 64,  // Timer/Counter4 Output Compare B bits
            OCR4B7 = 128, // Timer/Counter4 Output Compare B bits
        };
    };

    // Timer/Counter4 Output Compare Register C
    struct OCR4C {
        static const uint8_t address = 0xd1;
        enum bits : uint8_t {
            OCR4C0 = 1,   // Timer/Counter4 Output Compare C bits
            OCR4C1 = 2,   // Timer/Counter4 Output Compare C bits
            OCR4C2 = 4,   // Timer/Counter4 Output Compare C bits
            OCR4C3 = 8,   // Timer/Counter4 Output Compare C bits
            OCR4C4 = 16,  // Timer/Counter4 Output Compare C bits
            OCR4C5 = 32,  // Timer/Counter4 Output Compare C bits
            OCR4C6 = 64,  // Timer/Counter4 Output Compare C bits
            OCR4C7 = 128, // Timer/Counter4 Output Compare C bits
        };
    };

    // Timer/Counter4 Output Compare Register D
    struct OCR4D {
        static const uint8_t address = 0xd2;
        enum bits : uint8_t {
            OCR4D0 = 1,   // Timer/Counter4 Output Compare D bits
            OCR4D1 = 2,   // Timer/Counter4 Output Compare D bits
            OCR4D2 = 4,   // Timer/Counter4 Output Compare D bits
            OCR4D3 = 8,   // Timer/Counter4 Output Compare D bits
            OCR4D4 = 16,  // Timer/Counter4 Output Compare D bits
            OCR4D5 = 32,  // Timer/Counter4 Output Compare D bits
            OCR4D6 = 64,  // Timer/Counter4 Output Compare D bits
            OCR4D7 = 128, // Timer/Counter4 Output Compare D bits
        };
    };

    // Timer/Counter 4 Dead Time Value
    struct DT4 {
        static const uint8_t address = 0xd4;
        enum bits : uint8_t {
            DT4L0 = 1,   // Timer/Counter 4 Dead Time Value Bits
            DT4L1 = 2,   // Timer/Counter 4 Dead Time Value Bits
            DT4L2 = 4,   // Timer/Counter 4 Dead Time Value Bits
            DT4L3 = 8,   // Timer/Counter 4 Dead Time Value Bits
            DT4L4 = 16,  // Timer/Counter 4 Dead Time Value Bits
            DT4L5 = 32,  // Timer/Counter 4 Dead Time Value Bits
            DT4L6 = 64,  // Timer/Counter 4 Dead Time Value Bits
            DT4L7 = 128, // Timer/Counter 4 Dead Time Value Bits
        };
    };

    //
    struct UHWCON {
        static const uint8_t address = 0xd7;
        enum bits : uint8_t {
            UVREGE = 1, //
        };
    };

    // USB General Control Register
    struct USBCON {
        static const uint8_t address = 0xd8;
        enum bits : uint8_t {
            VBUSTE  = 1,   //
            OTGPADE = 16,  //
            FRZCLK  = 32,  //
            USBE    = 128, //
        };
    };

    //
    struct USBSTA {
        static const uint8_t address = 0xd9;
        enum bits : uint8_t {
            VBUS  = 1, //
            SPEED = 8, //
        };
    };

    //
    struct USBINT {
        static const uint8_t address = 0xda;
        enum bits : uint8_t {
            VBUSTI = 1, //
        };
    };

    //
    struct UDCON {
        static const uint8_t address = 0xe0;
        enum bits : uint8_t {
            DETACH = 1, //
            RMWKUP = 2, //
            LSM    = 4, // USB low speed mode
            RSTCPU = 8, //
        };
    };

    //
    struct UDINT {
        static const uint8_t address = 0xe1;
        enum bits : uint8_t {
            SUSPI   = 1,  //
            SOFI    = 4,  //
            EORSTI  = 8,  //
            WAKEUPI = 16, //
            EORSMI  = 32, //
            UPRSMI  = 64, //
        };
    };

    //
    struct UDIEN {
        static const uint8_t address = 0xe2;
        enum bits : uint8_t {
            SUSPE   = 1,  //
            SOFE    = 4,  //
            EORSTE  = 8,  //
            WAKEUPE = 16, //
            EORSME  = 32, //
            UPRSME  = 64, //
        };
    };

    //
    struct UDADDR {
        static const uint8_t address = 0xe3;
        enum bits : uint8_t {
            UADD0 = 1,   //
            UADD1 = 2,   //
            UADD2 = 4,   //
            UADD3 = 8,   //
            UADD4 = 16,  //
            UADD5 = 32,  //
            UADD6 = 64,  //
            ADDEN = 128, //
        };
    };

    //
    struct UDFNUM {
        static const uint16_t address = 0xe4;
        enum bits : uint8_t {
            FNUM0 = 1,   // Frame number value
            FNUM1 = 2,   // Frame number value
            FNUM2 = 4,   // Frame number value
            FNUM3 = 8,   // Frame number value
            FNUM4 = 16,  // Frame number value
            FNUM5 = 32,  // Frame number value
            FNUM6 = 64,  // Frame number value
            FNUM7 = 128, // Frame number value
        };
    };

    //
    struct UDMFN {
        static const uint8_t address = 0xe6;
        enum bits : uint8_t {
            FNCERR = 16, //
        };
    };

    //
    struct UEINTX {
        static const uint8_t address = 0xe8;
        enum bits : uint8_t {
            TXINI    = 1,   //
            STALLEDI = 2,   //
            RXOUTI   = 4,   //
            RXSTPI   = 8,   //
            NAKOUTI  = 16,  //
            RWAL     = 32,  //
            NAKINI   = 64,  //
            FIFOCON  = 128, //
        };
    };

    //
    struct UENUM {
        static const uint8_t address = 0xe9;
        enum bits : uint8_t {
            UENUM0 = 1, //
            UENUM1 = 2, //
            UENUM2 = 4, //
        };
    };

    //
    struct UERST {
        static const uint8_t address = 0xea;
        enum bits : uint8_t {
            EPRST0 = 1,  //
            EPRST1 = 2,  //
            EPRST2 = 4,  //
            EPRST3 = 8,  //
            EPRST4 = 16, //
            EPRST5 = 32, //
            EPRST6 = 64, //
        };
    };

    //
    struct UECONX {
        static const uint8_t address = 0xeb;
        enum bits : uint8_t {
            EPEN     = 1,  //
            RSTDT    = 8,  //
            STALLRQC = 16, //
            STALLRQ  = 32, //
        };
    };

    //
    struct UECFG0X {
        static const uint8_t address = 0xec;
        enum bits : uint8_t {
            EPDIR   = 1,   //
            EPTYPE0 = 64,  //
            EPTYPE1 = 128, //
        };
    };

    //
    struct UECFG1X {
        static const uint8_t address = 0xed;
        enum bits : uint8_t {
            ALLOC   = 2,  //
            EPBK0   = 4,  //
            EPBK1   = 8,  //
            EPSIZE0 = 16, //
            EPSIZE1 = 32, //
            EPSIZE2 = 64, //
        };
    };

    //
    struct UESTA0X {
        static const uint8_t address = 0xee;
        enum bits : uint8_t {
            NBUSYBK0 = 1,   //
            NBUSYBK1 = 2,   //
            DTSEQ0   = 4,   //
            DTSEQ1   = 8,   //
            UNDERFI  = 32,  //
            OVERFI   = 64,  //
            CFGOK    = 128, //
        };
    };

    //
    struct UESTA1X {
        static const uint8_t address = 0xef;
        enum bits : uint8_t {
            CURRBK0 = 1, //
            CURRBK1 = 2, //
            CTRLDIR = 4, //
        };
    };

    //
    struct UEIENX {
        static const uint8_t address = 0xf0;
        enum bits : uint8_t {
            TXINE    = 1,   //
            STALLEDE = 2,   //
            RXOUTE   = 4,   //
            RXSTPE   = 8,   //
            NAKOUTE  = 16,  //
            NAKINE   = 64,  //
            FLERRE   = 128, //
        };
    };

    //
    struct UEDATX {
        static const uint8_t address = 0xf1;
        enum bits : uint8_t {
            DAT0 = 1,   //
            DAT1 = 2,   //
            DAT2 = 4,   //
            DAT3 = 8,   //
            DAT4 = 16,  //
            DAT5 = 32,  //
            DAT6 = 64,  //
            DAT7 = 128, //
        };
    };

    //
    struct UEBCLX {
        static const uint8_t address = 0xf2;
        enum bits : uint8_t {
            BYCT0 = 1,   // Byte count bits
            BYCT1 = 2,   // Byte count bits
            BYCT2 = 4,   // Byte count bits
            BYCT3 = 8,   // Byte count bits
            BYCT4 = 16,  // Byte count bits
            BYCT5 = 32,  // Byte count bits
            BYCT6 = 64,  // Byte count bits
            BYCT7 = 128, // Byte count bits
        };
    };

    //
    struct UEBCHX {
        static const uint8_t address = 0xf3;
        enum bits : uint8_t {
            BYCT0 = 1, // Byte count bits
            BYCT1 = 2, // Byte count bits
            BYCT2 = 4, // Byte count bits
        };
    };

    //
    struct UEINT {
        static const uint8_t address = 0xf4;
        enum bits : uint8_t {
            EPINT0 = 1,  // Endpoint interrupt bits
            EPINT1 = 2,  // Endpoint interrupt bits
            EPINT2 = 4,  // Endpoint interrupt bits
            EPINT3 = 8,  // Endpoint interrupt bits
            EPINT4 = 16, // Endpoint interrupt bits
            EPINT5 = 32, // Endpoint interrupt bits
            EPINT6 = 64, // Endpoint interrupt bits
        };
    };

}

#endif
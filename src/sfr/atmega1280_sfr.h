#ifndef atmega1280_sfr_h
#define atmega1280_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega1280
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

    // Timer/Counter Interrupt Flag Register
    struct TIFR2 {
        static const uint8_t address = 0x37;
        enum bits : uint8_t {
            TOV2  = 1, // Timer/Counter2 Overflow Flag
            OCF2A = 2, // Output Compare Flag 2A
            OCF2B = 4, // Output Compare Flag 2B
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
            TOV4  = 1,  // Timer/Counter4 Overflow Flag
            OCF4A = 2,  // Output Compare Flag 4A
            OCF4B = 4,  // Output Compare Flag 4B
            OCF4C = 8,  // Output Compare Flag 4C
            ICF4  = 32, // Input Capture Flag 4
        };
    };

    // Timer/Counter5 Interrupt Flag register
    struct TIFR5 {
        static const uint8_t address = 0x3a;
        enum bits : uint8_t {
            TOV5  = 1,  // Timer/Counter5 Overflow Flag
            OCF5A = 2,  // Output Compare Flag 5A
            OCF5B = 4,  // Output Compare Flag 5B
            OCF5C = 8,  // Output Compare Flag 5C
            ICF5  = 32, // Input Capture Flag 5
        };
    };

    // Pin Change Interrupt Flag Register
    struct PCIFR {
        static const uint8_t address = 0x3b;
        enum bits : uint8_t {
            PCIF0 = 1, // Pin Change Interrupt Flags
            PCIF1 = 2, // Pin Change Interrupt Flags
            PCIF2 = 4, // Pin Change Interrupt Flags
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
    };

    // EEPROM Address Register Low Bytes
    struct EEAR {
        static const uint16_t address = 0x41;
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
    };

    // Timer/Counter0 Output Compare Register
    struct OCR0A {
        static const uint8_t address = 0x47;
    };

    // Timer/Counter0 Output Compare Register
    struct OCR0B {
        static const uint8_t address = 0x48;
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
            SIGRD  = 32,  // Signature Row Read
            RWWSB  = 64,  // Read While Write Section Busy
            SPMIE  = 128, // SPM Interrupt Enable
        };
    };

    // RAM Page Z Select Register
    struct RAMPZ {
        static const uint8_t address = 0x5b;
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
            PRUSART0 = 2,   // Power Reduction USART0
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
            PRUSART1 = 1,  // Power Reduction USART1
            PRUSART2 = 2,  // Power Reduction USART2
            PRUSART3 = 4,  // Power Reduction USART3
            PRTIM3   = 8,  // Power Reduction Timer/Counter3
            PRTIM4   = 16, // Power Reduction Timer/Counter4
            PRTIM5   = 32, // Power Reduction Timer/Counter5
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
            PCINT0 = 1,   // Pin Change Enable bits
            PCINT1 = 2,   // Pin Change Enable bits
            PCINT2 = 4,   // Pin Change Enable bits
            PCINT3 = 8,   // Pin Change Enable bits
            PCINT4 = 16,  // Pin Change Enable bits
            PCINT5 = 32,  // Pin Change Enable bits
            PCINT6 = 64,  // Pin Change Enable bits
            PCINT7 = 128, // Pin Change Enable bits
        };
    };

    // Pin Change Mask Register 1
    struct PCMSK1 {
        static const uint8_t address = 0x6c;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Enable bits
            PCINT1 = 2,   // Pin Change Enable bits
            PCINT2 = 4,   // Pin Change Enable bits
            PCINT3 = 8,   // Pin Change Enable bits
            PCINT4 = 16,  // Pin Change Enable bits
            PCINT5 = 32,  // Pin Change Enable bits
            PCINT6 = 64,  // Pin Change Enable bits
            PCINT7 = 128, // Pin Change Enable bits
        };
    };

    // Pin Change Mask Register 2
    struct PCMSK2 {
        static const uint8_t address = 0x6d;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Enable bits
            PCINT1 = 2,   // Pin Change Enable bits
            PCINT2 = 4,   // Pin Change Enable bits
            PCINT3 = 8,   // Pin Change Enable bits
            PCINT4 = 16,  // Pin Change Enable bits
            PCINT5 = 32,  // Pin Change Enable bits
            PCINT6 = 64,  // Pin Change Enable bits
            PCINT7 = 128, // Pin Change Enable bits
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
            OCIE3C = 8,  // Timer/Counter3 Output Compare C Match Interrupt Enable
            ICIE3  = 32, // Timer/Counter3 Input Capture Interrupt Enable
        };
    };

    // Timer/Counter4 Interrupt Mask Register
    struct TIMSK4 {
        static const uint8_t address = 0x72;
        enum bits : uint8_t {
            TOIE4  = 1,  // Timer/Counter4 Overflow Interrupt Enable
            OCIE4A = 2,  // Timer/Counter4 Output Compare A Match Interrupt Enable
            OCIE4B = 4,  // Timer/Counter4 Output Compare B Match Interrupt Enable
            OCIE4C = 8,  // Timer/Counter4 Output Compare C Match Interrupt Enable
            ICIE4  = 32, // Timer/Counter4 Input Capture Interrupt Enable
        };
    };

    // Timer/Counter5 Interrupt Mask Register
    struct TIMSK5 {
        static const uint8_t address = 0x73;
        enum bits : uint8_t {
            TOIE5  = 1,  // Timer/Counter5 Overflow Interrupt Enable
            OCIE5A = 2,  // Timer/Counter5 Output Compare A Match Interrupt Enable
            OCIE5B = 4,  // Timer/Counter5 Output Compare B Match Interrupt Enable
            OCIE5C = 8,  // Timer/Counter5 Output Compare C Match Interrupt Enable
            ICIE5  = 32, // Timer/Counter5 Input Capture Interrupt Enable
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

    // The ADC Control and Status register A
    struct ADCSRA {
        static const uint8_t address = 0x7a;
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

    // ADC Control and Status Register B
    struct ADCSRB {
        static const uint8_t address = 0x7b;
        enum bits : uint8_t {
            ADTS0 = 1,  // ADC Auto Trigger Source bits
            ADTS1 = 2,  // ADC Auto Trigger Source bits
            ADTS2 = 4,  // ADC Auto Trigger Source bits
            MUX5  = 8,  // Analog Channel and Gain Selection Bits
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
    struct DIDR2 {
        static const uint8_t address = 0x7d;
        enum bits : uint8_t {
            ADC8D  = 1,   //
            ADC9D  = 2,   //
            ADC10D = 4,   //
            ADC11D = 8,   //
            ADC12D = 16,  //
            ADC13D = 32,  //
            ADC14D = 64,  //
            ADC15D = 128, //
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

    // Timer/Counter1 Output Compare Register A  Bytes
    struct OCR1A {
        static const uint16_t address = 0x88;
    };

    // Timer/Counter1 Output Compare Register B  Bytes
    struct OCR1B {
        static const uint16_t address = 0x8a;
    };

    // Timer/Counter1 Output Compare Register C  Bytes
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

    // Timer/Counter3  Bytes
    struct TCNT3 {
        static const uint16_t address = 0x94;
    };

    // Timer/Counter3 Input Capture Register  Bytes
    struct ICR3 {
        static const uint16_t address = 0x96;
    };

    // Timer/Counter3 Output Compare Register A  Bytes
    struct OCR3A {
        static const uint16_t address = 0x98;
    };

    // Timer/Counter3 Output Compare Register B  Bytes
    struct OCR3B {
        static const uint16_t address = 0x9a;
    };

    // Timer/Counter3 Output Compare Register B  Bytes
    struct OCR3C {
        static const uint16_t address = 0x9c;
    };

    // Timer/Counter4 Control Register A
    struct TCCR4A {
        static const uint8_t address = 0xa0;
        enum bits : uint8_t {
            WGM40  = 1,   // Waveform Generation Mode
            WGM41  = 2,   // Waveform Generation Mode
            COM4C0 = 4,   // Compare Output Mode 4C, bits
            COM4C1 = 8,   // Compare Output Mode 4C, bits
            COM4B0 = 16,  // Compare Output Mode 4B, bits
            COM4B1 = 32,  // Compare Output Mode 4B, bits
            COM4A0 = 64,  // Compare Output Mode 1A, bits
            COM4A1 = 128, // Compare Output Mode 1A, bits
        };
    };

    // Timer/Counter4 Control Register B
    struct TCCR4B {
        static const uint8_t address = 0xa1;
        enum bits : uint8_t {
            CS40  = 1,   // Prescaler source of Timer/Counter 4
            CS41  = 2,   // Prescaler source of Timer/Counter 4
            CS42  = 4,   // Prescaler source of Timer/Counter 4
            WGM40 = 8,   // Waveform Generation Mode
            WGM41 = 16,  // Waveform Generation Mode
            ICES4 = 64,  // Input Capture 4 Edge Select
            ICNC4 = 128, // Input Capture 4 Noise Canceler
        };
    };

    // Timer/Counter 4 Control Register C
    struct TCCR4C {
        static const uint8_t address = 0xa2;
        enum bits : uint8_t {
            FOC4C = 32,  // Force Output Compare 4C
            FOC4B = 64,  // Force Output Compare 4B
            FOC4A = 128, // Force Output Compare 4A
        };
    };

    // Timer/Counter4  Bytes
    struct TCNT4 {
        static const uint16_t address = 0xa4;
    };

    // Timer/Counter4 Input Capture Register  Bytes
    struct ICR4 {
        static const uint16_t address = 0xa6;
    };

    // Timer/Counter4 Output Compare Register A  Bytes
    struct OCR4A {
        static const uint16_t address = 0xa8;
    };

    // Timer/Counter4 Output Compare Register B  Bytes
    struct OCR4B {
        static const uint16_t address = 0xaa;
    };

    // Timer/Counter4 Output Compare Register B  Bytes
    struct OCR4C {
        static const uint16_t address = 0xac;
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
    };

    // Timer/Counter2 Output Compare Register A
    struct OCR2A {
        static const uint8_t address = 0xb3;
    };

    // Timer/Counter2 Output Compare Register B
    struct OCR2B {
        static const uint8_t address = 0xb4;
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

    // USART Baud Rate Register  Bytes
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

    // USART Baud Rate Register  Bytes
    struct UBRR1 {
        static const uint16_t address = 0xcc;
    };

    // USART I/O Data Register
    struct UDR1 {
        static const uint8_t address = 0xce;
    };

    // USART Control and Status Register A
    struct UCSR2A {
        static const uint8_t address = 0xd0;
        enum bits : uint8_t {
            MPCM2 = 1,   // Multi-processor Communication Mode
            U2X2  = 2,   // Double the USART transmission speed
            UPE2  = 4,   // Parity Error
            DOR2  = 8,   // Data overRun
            FE2   = 16,  // Framing Error
            UDRE2 = 32,  // USART Data Register Empty
            TXC2  = 64,  // USART Transmitt Complete
            RXC2  = 128, // USART Receive Complete
        };
    };

    // USART Control and Status Register B
    struct UCSR2B {
        static const uint8_t address = 0xd1;
        enum bits : uint8_t {
            TXB82  = 1,   // Transmit Data Bit 8
            RXB82  = 2,   // Receive Data Bit 8
            UCSZ22 = 4,   // Character Size
            TXEN2  = 8,   // Transmitter Enable
            RXEN2  = 16,  // Receiver Enable
            UDRIE2 = 32,  // USART Data register Empty Interrupt Enable
            TXCIE2 = 64,  // TX Complete Interrupt Enable
            RXCIE2 = 128, // RX Complete Interrupt Enable
        };
    };

    // USART Control and Status Register C
    struct UCSR2C {
        static const uint8_t address = 0xd2;
        enum bits : uint8_t {
            UCPOL2  = 1,   // Clock Polarity
            UCSZ20  = 2,   // Character Size
            UCSZ21  = 4,   // Character Size
            USBS2   = 8,   // Stop Bit Select
            UPM20   = 16,  // Parity Mode Bits
            UPM21   = 32,  // Parity Mode Bits
            UMSEL20 = 64,  // USART Mode Select
            UMSEL21 = 128, // USART Mode Select
        };
    };

    // USART Baud Rate Register  Bytes
    struct UBRR2 {
        static const uint16_t address = 0xd4;
    };

    // USART I/O Data Register
    struct UDR2 {
        static const uint8_t address = 0xd6;
    };

    // PORT H Input Pins
    struct PINH {
        static const uint8_t address = 0x100;
    };

    // PORT H Data Direction Register
    struct DDRH {
        static const uint8_t address = 0x101;
    };

    // PORT H Data Register
    struct PORTH {
        static const uint8_t address = 0x102;
    };

    // PORT J Input Pins
    struct PINJ {
        static const uint8_t address = 0x103;
    };

    // PORT J Data Direction Register
    struct DDRJ {
        static const uint8_t address = 0x104;
    };

    // PORT J Data Register
    struct PORTJ {
        static const uint8_t address = 0x105;
    };

    // PORT K Input Pins
    struct PINK {
        static const uint8_t address = 0x106;
    };

    // PORT K Data Direction Register
    struct DDRK {
        static const uint8_t address = 0x107;
    };

    // PORT K Data Register
    struct PORTK {
        static const uint8_t address = 0x108;
    };

    // PORT L Input Pins
    struct PINL {
        static const uint8_t address = 0x109;
    };

    // PORT L Data Direction Register
    struct DDRL {
        static const uint8_t address = 0x10a;
    };

    // PORT L Data Register
    struct PORTL {
        static const uint8_t address = 0x10b;
    };

    // Timer/Counter5 Control Register A
    struct TCCR5A {
        static const uint8_t address = 0x120;
        enum bits : uint8_t {
            WGM50  = 1,   // Waveform Generation Mode
            WGM51  = 2,   // Waveform Generation Mode
            COM5C0 = 4,   // Compare Output Mode 5C, bits
            COM5C1 = 8,   // Compare Output Mode 5C, bits
            COM5B0 = 16,  // Compare Output Mode 5B, bits
            COM5B1 = 32,  // Compare Output Mode 5B, bits
            COM5A0 = 64,  // Compare Output Mode 1A, bits
            COM5A1 = 128, // Compare Output Mode 1A, bits
        };
    };

    // Timer/Counter5 Control Register B
    struct TCCR5B {
        static const uint8_t address = 0x121;
        enum bits : uint8_t {
            CS50  = 1,   // Prescaler source of Timer/Counter 5
            CS51  = 2,   // Prescaler source of Timer/Counter 5
            CS52  = 4,   // Prescaler source of Timer/Counter 5
            WGM50 = 8,   // Waveform Generation Mode
            WGM51 = 16,  // Waveform Generation Mode
            ICES5 = 64,  // Input Capture 5 Edge Select
            ICNC5 = 128, // Input Capture 5 Noise Canceler
        };
    };

    // Timer/Counter 5 Control Register C
    struct TCCR5C {
        static const uint8_t address = 0x122;
        enum bits : uint8_t {
            FOC5C = 32,  // Force Output Compare 5C
            FOC5B = 64,  // Force Output Compare 5B
            FOC5A = 128, // Force Output Compare 5A
        };
    };

    // Timer/Counter5  Bytes
    struct TCNT5 {
        static const uint16_t address = 0x124;
    };

    // Timer/Counter5 Input Capture Register  Bytes
    struct ICR5 {
        static const uint16_t address = 0x126;
    };

    // Timer/Counter5 Output Compare Register A  Bytes
    struct OCR5A {
        static const uint16_t address = 0x128;
    };

    // Timer/Counter5 Output Compare Register B  Bytes
    struct OCR5B {
        static const uint16_t address = 0x12a;
    };

    // Timer/Counter5 Output Compare Register B  Bytes
    struct OCR5C {
        static const uint16_t address = 0x12c;
    };

    // USART Control and Status Register A
    struct UCSR3A {
        static const uint8_t address = 0x130;
        enum bits : uint8_t {
            MPCM3 = 1,   // Multi-processor Communication Mode
            U2X3  = 2,   // Double the USART transmission speed
            UPE3  = 4,   // Parity Error
            DOR3  = 8,   // Data overRun
            FE3   = 16,  // Framing Error
            UDRE3 = 32,  // USART Data Register Empty
            TXC3  = 64,  // USART Transmitt Complete
            RXC3  = 128, // USART Receive Complete
        };
    };

    // USART Control and Status Register B
    struct UCSR3B {
        static const uint8_t address = 0x131;
        enum bits : uint8_t {
            TXB83  = 1,   // Transmit Data Bit 8
            RXB83  = 2,   // Receive Data Bit 8
            UCSZ32 = 4,   // Character Size
            TXEN3  = 8,   // Transmitter Enable
            RXEN3  = 16,  // Receiver Enable
            UDRIE3 = 32,  // USART Data register Empty Interrupt Enable
            TXCIE3 = 64,  // TX Complete Interrupt Enable
            RXCIE3 = 128, // RX Complete Interrupt Enable
        };
    };

    // USART Control and Status Register C
    struct UCSR3C {
        static const uint8_t address = 0x132;
        enum bits : uint8_t {
            UCPOL3  = 1,   // Clock Polarity
            UCSZ30  = 2,   // Character Size
            UCSZ31  = 4,   // Character Size
            USBS3   = 8,   // Stop Bit Select
            UPM30   = 16,  // Parity Mode Bits
            UPM31   = 32,  // Parity Mode Bits
            UMSEL30 = 64,  // USART Mode Select
            UMSEL31 = 128, // USART Mode Select
        };
    };

    // USART Baud Rate Register  Bytes
    struct UBRR3 {
        static const uint16_t address = 0x134;
    };

    // USART I/O Data Register
    struct UDR3 {
        static const uint8_t address = 0x136;
    };

}

#endif
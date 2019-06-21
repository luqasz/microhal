#ifndef atmega2564rfr2_sfr_h
#define atmega2564rfr2_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega2564RFR2
*/

namespace SFR {

    // Port A Input Pins Address
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

    // Port B Input Pins Address
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

    // Port C Input Pins Address
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

    // Port D Input Pins Address
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

    // Port E Input Pins Address
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

    // Port F Input Pins Address
    struct PINF {
        static const uint8_t address = 0x2f;
    };

    // Port F Data Direction Register
    struct DDRF {
        static const uint8_t address = 0x30;
    };

    // Port F Data Register
    struct PORTF {
        static const uint8_t address = 0x31;
    };

    // Port G Input Pins Address
    struct PING {
        static const uint8_t address = 0x32;
    };

    // Port G Data Direction Register
    struct DDRG {
        static const uint8_t address = 0x33;
    };

    // Port G Data Register
    struct PORTG {
        static const uint8_t address = 0x34;
    };

    // Timer/Counter0 Interrupt Flag Register
    struct TIFR0 {
        static const uint8_t address = 0x35;
        enum bits : uint8_t {
            TOV0  = 1, // Timer/Counter0 Overflow Flag
            OCF0A = 2, // Timer/Counter0 Output Compare A Match Flag
            OCF0B = 4, // Timer/Counter0 Output Compare B Match Flag
        };
    };

    // Timer/Counter1 Interrupt Flag Register
    struct TIFR1 {
        static const uint8_t address = 0x36;
        enum bits : uint8_t {
            TOV1  = 1,  // Timer/Counter1 Overflow Flag
            OCF1A = 2,  // Timer/Counter1 Output Compare A Match Flag
            OCF1B = 4,  // Timer/Counter1 Output Compare B Match Flag
            OCF1C = 8,  // Timer/Counter1 Output Compare C Match Flag
            ICF1  = 32, // Timer/Counter1 Input Capture Flag
        };
    };

    // Timer/Counter Interrupt Flag Register
    struct TIFR2 {
        static const uint8_t address = 0x37;
        enum bits : uint8_t {
            TOV2  = 1,   // Timer/Counter2 Overflow Flag
            OCF2A = 2,   // Output Compare Flag 2 A
            OCF2B = 4,   // Output Compare Flag 2 B
            Res0  = 8,   // Reserved Bit
            Res1  = 16,  // Reserved Bit
            Res2  = 32,  // Reserved Bit
            Res3  = 64,  // Reserved Bit
            Res4  = 128, // Reserved Bit
        };
    };

    // Timer/Counter3 Interrupt Flag Register
    struct TIFR3 {
        static const uint8_t address = 0x38;
        enum bits : uint8_t {
            TOV3  = 1,  // Timer/Counter3 Overflow Flag
            OCF3A = 2,  // Timer/Counter3 Output Compare A Match Flag
            OCF3B = 4,  // Timer/Counter3 Output Compare B Match Flag
            OCF3C = 8,  // Timer/Counter3 Output Compare C Match Flag
            ICF3  = 32, // Timer/Counter3 Input Capture Flag
        };
    };

    // Timer/Counter4 Interrupt Flag Register
    struct TIFR4 {
        static const uint8_t address = 0x39;
        enum bits : uint8_t {
            TOV4  = 1,  // Timer/Counter4 Overflow Flag
            OCF4A = 2,  // Timer/Counter4 Output Compare A Match Flag
            OCF4B = 4,  // Timer/Counter4 Output Compare B Match Flag
            OCF4C = 8,  // Timer/Counter4 Output Compare C Match Flag
            ICF4  = 32, // Timer/Counter4 Input Capture Flag
        };
    };

    // Timer/Counter5 Interrupt Flag Register
    struct TIFR5 {
        static const uint8_t address = 0x3a;
        enum bits : uint8_t {
            TOV5  = 1,  // Timer/Counter5 Overflow Flag
            OCF5A = 2,  // Timer/Counter5 Output Compare A Match Flag
            OCF5B = 4,  // Timer/Counter5 Output Compare B Match Flag
            OCF5C = 8,  // Timer/Counter5 Output Compare C Match Flag
            ICF5  = 32, // Timer/Counter5 Input Capture Flag
        };
    };

    // Pin Change Interrupt Flag Register
    struct PCIFR {
        static const uint8_t address = 0x3b;
        enum bits : uint8_t {
            PCIF0 = 1,   // Pin Change Interrupt Flags
            PCIF1 = 2,   // Pin Change Interrupt Flags
            PCIF2 = 4,   // Pin Change Interrupt Flags
            Res0  = 8,   // Reserved Bit
            Res1  = 16,  // Reserved Bit
            Res2  = 32,  // Reserved Bit
            Res3  = 64,  // Reserved Bit
            Res4  = 128, // Reserved Bit
        };
    };

    // External Interrupt Flag Register
    struct EIFR {
        static const uint8_t address = 0x3c;
        enum bits : uint8_t {
            INTF0 = 1,   // External Interrupt Flag
            INTF1 = 2,   // External Interrupt Flag
            INTF2 = 4,   // External Interrupt Flag
            INTF3 = 8,   // External Interrupt Flag
            INTF4 = 16,  // External Interrupt Flag
            INTF5 = 32,  // External Interrupt Flag
            INTF6 = 64,  // External Interrupt Flag
            INTF7 = 128, // External Interrupt Flag
        };
    };

    // External Interrupt Mask Register
    struct EIMSK {
        static const uint8_t address = 0x3d;
        enum bits : uint8_t {
            INT0 = 1,   // External Interrupt Request Enable
            INT1 = 2,   // External Interrupt Request Enable
            INT2 = 4,   // External Interrupt Request Enable
            INT3 = 8,   // External Interrupt Request Enable
            INT4 = 16,  // External Interrupt Request Enable
            INT5 = 32,  // External Interrupt Request Enable
            INT6 = 64,  // External Interrupt Request Enable
            INT7 = 128, // External Interrupt Request Enable
        };
    };

    // General Purpose IO Register 0
    struct GPIOR0 {
        static const uint8_t address = 0x3e;
        enum bits : uint8_t {
            GPIOR00 = 1,   // General Purpose I/O Register 0 Value
            GPIOR01 = 2,   // General Purpose I/O Register 0 Value
            GPIOR02 = 4,   // General Purpose I/O Register 0 Value
            GPIOR03 = 8,   // General Purpose I/O Register 0 Value
            GPIOR04 = 16,  // General Purpose I/O Register 0 Value
            GPIOR05 = 32,  // General Purpose I/O Register 0 Value
            GPIOR06 = 64,  // General Purpose I/O Register 0 Value
            GPIOR07 = 128, // General Purpose I/O Register 0 Value
        };
    };

    // EEPROM Control Register
    struct EECR {
        static const uint8_t address = 0x3f;
        enum bits : uint8_t {
            EERE  = 1,  // EEPROM Read Enable
            EEPE  = 2,  // EEPROM Programming Enable
            EEMPE = 4,  // EEPROM Master Write Enable
            EERIE = 8,  // EEPROM Ready Interrupt Enable
            EEPM0 = 16, // EEPROM Programming Mode
            EEPM1 = 32, // EEPROM Programming Mode
        };
    };

    // EEPROM Data Register
    struct EEDR {
        static const uint8_t address = 0x40;
    };

    // EEPROM Address Register  Bytes
    struct EEAR {
        static const uint16_t address = 0x41;
    };

    // General Timer/Counter Control Register
    struct GTCCR {
        static const uint8_t address = 0x43;
        enum bits : uint8_t {
            PSRSYNC = 1,   // Prescaler Reset for Synchronous Timer/Counters
            PSRASY  = 2,   // Prescaler Reset Timer/Counter2
            TSM     = 128, // Timer/Counter Synchronization Mode
        };
    };

    // Timer/Counter0 Control Register A
    struct TCCR0A {
        static const uint8_t address = 0x44;
        enum bits : uint8_t {
            WGM00  = 1,   // Waveform Generation Mode
            WGM01  = 2,   // Waveform Generation Mode
            Res0   = 4,   // Reserved Bit
            Res1   = 8,   // Reserved Bit
            COM0B0 = 16,  // Compare Match Output B Mode
            COM0B1 = 32,  // Compare Match Output B Mode
            COM0A0 = 64,  // Compare Match Output A Mode
            COM0A1 = 128, // Compare Match Output A Mode
        };
    };

    // Timer/Counter0 Control Register B
    struct TCCR0B {
        static const uint8_t address = 0x45;
        enum bits : uint8_t {
            CS00  = 1,   // Clock Select
            CS01  = 2,   // Clock Select
            CS02  = 4,   // Clock Select
            WGM02 = 8,   //
            Res0  = 16,  // Reserved Bit
            Res1  = 32,  // Reserved Bit
            FOC0B = 64,  // Force Output Compare B
            FOC0A = 128, // Force Output Compare A
        };
    };

    // Timer/Counter0 Register
    struct TCNT0 {
        static const uint8_t address = 0x46;
    };

    // Timer/Counter0 Output Compare Register
    struct OCR0A {
        static const uint8_t address = 0x47;
    };

    // Timer/Counter0 Output Compare Register B
    struct OCR0B {
        static const uint8_t address = 0x48;
    };

    // General Purpose IO Register 1
    struct GPIOR1 {
        static const uint8_t address = 0x4a;
        enum bits : uint8_t {
            GPIOR0 = 1,   // General Purpose I/O Register 1 Value
            GPIOR1 = 2,   // General Purpose I/O Register 1 Value
            GPIOR2 = 4,   // General Purpose I/O Register 1 Value
            GPIOR3 = 8,   // General Purpose I/O Register 1 Value
            GPIOR4 = 16,  // General Purpose I/O Register 1 Value
            GPIOR5 = 32,  // General Purpose I/O Register 1 Value
            GPIOR6 = 64,  // General Purpose I/O Register 1 Value
            GPIOR7 = 128, // General Purpose I/O Register 1 Value
        };
    };

    // General Purpose I/O Register 2
    struct GPIOR2 {
        static const uint8_t address = 0x4b;
        enum bits : uint8_t {
            GPIOR0 = 1,   // General Purpose I/O Register 2 Value
            GPIOR1 = 2,   // General Purpose I/O Register 2 Value
            GPIOR2 = 4,   // General Purpose I/O Register 2 Value
            GPIOR3 = 8,   // General Purpose I/O Register 2 Value
            GPIOR4 = 16,  // General Purpose I/O Register 2 Value
            GPIOR5 = 32,  // General Purpose I/O Register 2 Value
            GPIOR6 = 64,  // General Purpose I/O Register 2 Value
            GPIOR7 = 128, // General Purpose I/O Register 2 Value
        };
    };

    // SPI Control Register
    struct SPCR {
        static const uint8_t address = 0x4c;
        enum bits : uint8_t {
            SPR0 = 1,   // SPI Clock Rate Select 1 and 0
            SPR1 = 2,   // SPI Clock Rate Select 1 and 0
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
            ACIS0 = 1,   // Analog Comparator Interrupt Mode Select
            ACIS1 = 2,   // Analog Comparator Interrupt Mode Select
            ACIC  = 4,   // Analog Comparator Input Capture Enable
            ACIE  = 8,   // Analog Comparator Interrupt Enable
            ACI   = 16,  // Analog Comparator Interrupt Flag
            ACO   = 32,  // Analog Compare Output
            ACBG  = 64,  // Analog Comparator Bandgap Select
            ACD   = 128, // Analog Comparator Disable
        };
    };

    // On-Chip Debug Register
    struct OCDR {
        static const uint8_t address = 0x51;
        enum bits : uint8_t {
            OCDR0 = 1,   // On-Chip Debug Register Data
            OCDR1 = 2,   // On-Chip Debug Register Data
            OCDR2 = 4,   // On-Chip Debug Register Data
            OCDR3 = 8,   // On-Chip Debug Register Data
            OCDR4 = 16,  // On-Chip Debug Register Data
            OCDR5 = 32,  // On-Chip Debug Register Data
            OCDR6 = 64,  // On-Chip Debug Register Data
            OCDR7 = 128, // On-Chip Debug Register Data
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
            PORF  = 1,  // Power-on Reset Flag
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
            PUD   = 16,  // Pull-up Disable
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
            RWWSRE = 16,  // Read While Write Section Read Enable
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

    // Clock Prescale Register
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

    // Power Reduction Register 2
    struct PRR2 {
        static const uint8_t address = 0x63;
        enum bits : uint8_t {
            PRRAM0 = 1, // Power Reduction SRAM0
            PRRAM1 = 2, // Power Reduction SRAM1
            PRRAM2 = 4, // Power Reduction SRAM2
            PRRAM3 = 8, // Power Reduction SRAM3
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
            PRPGA    = 16,  // Power Reduction PGA
            PRTIM0   = 32,  // Power Reduction Timer/Counter0
            PRTIM2   = 64,  // Power Reduction Timer/Counter2
            PRTWI    = 128, // Power Reduction TWI
        };
    };

    // Power Reduction Register 1
    struct PRR1 {
        static const uint8_t address = 0x65;
        enum bits : uint8_t {
            PRUSART1 = 1,   // Power Reduction USART1
            PRTIM3   = 8,   // Power Reduction Timer/Counter3
            PRTIM4   = 16,  // Power Reduction Timer/Counter4
            PRTIM5   = 32,  // Power Reduction Timer/Counter5
            PRTRX24  = 64,  // Power Reduction Transceiver
            Res      = 128, // Reserved Bit
        };
    };

    // Oscillator Calibration Value
    struct OSCCAL {
        static const uint8_t address = 0x66;
        enum bits : uint8_t {
            CAL0 = 1,   // Oscillator Calibration Tuning Value
            CAL1 = 2,   // Oscillator Calibration Tuning Value
            CAL2 = 4,   // Oscillator Calibration Tuning Value
            CAL3 = 8,   // Oscillator Calibration Tuning Value
            CAL4 = 16,  // Oscillator Calibration Tuning Value
            CAL5 = 32,  // Oscillator Calibration Tuning Value
            CAL6 = 64,  // Oscillator Calibration Tuning Value
            CAL7 = 128, // Oscillator Calibration Tuning Value
        };
    };

    // Reference Voltage Calibration Register
    struct BGCR {
        static const uint8_t address = 0x67;
        enum bits : uint8_t {
            BGCAL0      = 1,   // Coarse Calibration Bits
            BGCAL1      = 2,   // Coarse Calibration Bits
            BGCAL2      = 4,   // Coarse Calibration Bits
            BGCAL_FINE0 = 8,   // Fine Calibration Bits
            BGCAL_FINE1 = 16,  // Fine Calibration Bits
            BGCAL_FINE2 = 32,  // Fine Calibration Bits
            BGCAL_FINE3 = 64,  // Fine Calibration Bits
            Res         = 128, // Reserved Bit
        };
    };

    // Pin Change Interrupt Control Register
    struct PCICR {
        static const uint8_t address = 0x68;
        enum bits : uint8_t {
            PCIE0 = 1,   // Pin Change Interrupt Enables
            PCIE1 = 2,   // Pin Change Interrupt Enables
            PCIE2 = 4,   // Pin Change Interrupt Enables
            Res0  = 8,   // Reserved Bit
            Res1  = 16,  // Reserved Bit
            Res2  = 32,  // Reserved Bit
            Res3  = 64,  // Reserved Bit
            Res4  = 128, // Reserved Bit
        };
    };

    // External Interrupt Control Register A
    struct EICRA {
        static const uint8_t address = 0x69;
        enum bits : uint8_t {
            ISC00 = 1,   // External Interrupt 0 Sense Control Bit
            ISC01 = 2,   // External Interrupt 0 Sense Control Bit
            ISC10 = 4,   // External Interrupt 1 Sense Control Bit
            ISC11 = 8,   // External Interrupt 1 Sense Control Bit
            ISC20 = 16,  // External Interrupt 2 Sense Control Bit
            ISC21 = 32,  // External Interrupt 2 Sense Control Bit
            ISC30 = 64,  // External Interrupt 3 Sense Control Bit
            ISC31 = 128, // External Interrupt 3 Sense Control Bit
        };
    };

    // External Interrupt Control Register B
    struct EICRB {
        static const uint8_t address = 0x6a;
        enum bits : uint8_t {
            ISC40 = 1,   // External Interrupt 4 Sense Control Bit
            ISC41 = 2,   // External Interrupt 4 Sense Control Bit
            ISC50 = 4,   // External Interrupt 5 Sense Control Bit
            ISC51 = 8,   // External Interrupt 5 Sense Control Bit
            ISC60 = 16,  // External Interrupt 6 Sense Control Bit
            ISC61 = 32,  // External Interrupt 6 Sense Control Bit
            ISC70 = 64,  // External Interrupt 7 Sense Control Bit
            ISC71 = 128, // External Interrupt 7 Sense Control Bit
        };
    };

    // Pin Change Mask Register 0
    struct PCMSK0 {
        static const uint8_t address = 0x6b;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Enable Mask
            PCINT1 = 2,   // Pin Change Enable Mask
            PCINT2 = 4,   // Pin Change Enable Mask
            PCINT3 = 8,   // Pin Change Enable Mask
            PCINT4 = 16,  // Pin Change Enable Mask
            PCINT5 = 32,  // Pin Change Enable Mask
            PCINT6 = 64,  // Pin Change Enable Mask
            PCINT7 = 128, // Pin Change Enable Mask
        };
    };

    // Pin Change Mask Register 1
    struct PCMSK1 {
        static const uint8_t address = 0x6c;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Enable Mask
            PCINT1 = 2,   // Pin Change Enable Mask
            PCINT2 = 4,   // Pin Change Enable Mask
            PCINT3 = 8,   // Pin Change Enable Mask
            PCINT4 = 16,  // Pin Change Enable Mask
            PCINT5 = 32,  // Pin Change Enable Mask
            PCINT6 = 64,  // Pin Change Enable Mask
            PCINT7 = 128, // Pin Change Enable Mask
        };
    };

    // Pin Change Mask Register 2
    struct PCMSK2 {
        static const uint8_t address = 0x6d;
        enum bits : uint8_t {
            PCINT0 = 1,   // Pin Change Enable Mask
            PCINT1 = 2,   // Pin Change Enable Mask
            PCINT2 = 4,   // Pin Change Enable Mask
            PCINT3 = 8,   // Pin Change Enable Mask
            PCINT4 = 16,  // Pin Change Enable Mask
            PCINT5 = 32,  // Pin Change Enable Mask
            PCINT6 = 64,  // Pin Change Enable Mask
            PCINT7 = 128, // Pin Change Enable Mask
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
            TOIE2  = 1,   // Timer/Counter2 Overflow Interrupt Enable
            OCIE2A = 2,   // Timer/Counter2 Output Compare Match A Interrupt Enable
            OCIE2B = 4,   // Timer/Counter2 Output Compare Match B Interrupt Enable
            Res0   = 8,   // Reserved Bit
            Res1   = 16,  // Reserved Bit
            Res2   = 32,  // Reserved Bit
            Res3   = 64,  // Reserved Bit
            Res4   = 128, // Reserved Bit
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

    // Flash Extended-Mode Control-Register
    struct NEMCR {
        static const uint8_t address = 0x75;
        enum bits : uint8_t {
            AEAM0 = 16, // Address for Extended Address Mode of Extra Rows
            AEAM1 = 32, // Address for Extended Address Mode of Extra Rows
            ENEAM = 64, // Enable Extended Address Mode for Extra Rows
        };
    };

    // The ADC Control and Status Register C
    struct ADCSRC {
        static const uint8_t address = 0x77;
        enum bits : uint8_t {
            ADSUT0 = 1,   // ADC Start-up Time
            ADSUT1 = 2,   // ADC Start-up Time
            ADSUT2 = 4,   // ADC Start-up Time
            ADSUT3 = 8,   // ADC Start-up Time
            ADSUT4 = 16,  // ADC Start-up Time
            Res0   = 32,  // Reserved
            ADTHT0 = 64,  // ADC Track-and-Hold Time
            ADTHT1 = 128, // ADC Track-and-Hold Time
        };
    };

    // ADC Data Register  Bytes
    struct ADC {
        static const uint16_t address = 0x78;
    };

    // The ADC Control and Status Register A
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
            ADTS0  = 1,   // ADC Auto Trigger Source
            ADTS1  = 2,   // ADC Auto Trigger Source
            ADTS2  = 4,   // ADC Auto Trigger Source
            MUX5   = 8,   // Analog Channel and Gain Selection Bits
            ACCH   = 16,  // Analog Channel Change
            REFOK  = 32,  // Reference Voltage OK
            ACME   = 64,  // Analog Comparator Multiplexer Enable
            AVDDOK = 128, // AVDD Supply Voltage OK
        };
    };

    // The ADC Multiplexer Selection Register
    struct ADMUX {
        static const uint8_t address = 0x7c;
        enum bits : uint8_t {
            MUX0  = 1,   // Analog Channel and Gain Selection Bits
            MUX1  = 2,   // Analog Channel and Gain Selection Bits
            MUX2  = 4,   // Analog Channel and Gain Selection Bits
            MUX3  = 8,   // Analog Channel and Gain Selection Bits
            MUX4  = 16,  // Analog Channel and Gain Selection Bits
            ADLAR = 32,  // ADC Left Adjust Result
            REFS0 = 64,  // Reference Selection Bits
            REFS1 = 128, // Reference Selection Bits
        };
    };

    // Digital Input Disable Register 2
    struct DIDR2 {
        static const uint8_t address = 0x7d;
        enum bits : uint8_t {
            ADC8D  = 1,   // Reserved Bits
            ADC9D  = 2,   // Reserved Bits
            ADC10D = 4,   // Reserved Bits
            ADC11D = 8,   // Reserved Bits
            ADC12D = 16,  // Reserved Bits
            ADC13D = 32,  // Reserved Bits
            ADC14D = 64,  // Reserved Bits
            ADC15D = 128, // Reserved Bits
        };
    };

    // Digital Input Disable Register 0
    struct DIDR0 {
        static const uint8_t address = 0x7e;
        enum bits : uint8_t {
            ADC0D = 1,   // Disable ADC7:0 Digital Input
            ADC1D = 2,   // Disable ADC7:0 Digital Input
            ADC2D = 4,   // Disable ADC7:0 Digital Input
            ADC3D = 8,   // Disable ADC7:0 Digital Input
            ADC4D = 16,  // Disable ADC7:0 Digital Input
            ADC5D = 32,  // Disable ADC7:0 Digital Input
            ADC6D = 64,  // Disable ADC7:0 Digital Input
            ADC7D = 128, // Disable ADC7:0 Digital Input
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
            COM1C0 = 4,   // Compare Output Mode for Channel C
            COM1C1 = 8,   // Compare Output Mode for Channel C
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
            CS10  = 1,   // Clock Select
            CS11  = 2,   // Clock Select
            CS12  = 4,   // Clock Select
            WGM10 = 8,   // Waveform Generation Mode
            WGM11 = 16,  // Waveform Generation Mode
            Res   = 32,  // Reserved Bit
            ICES1 = 64,  // Input Capture 1 Edge Select
            ICNC1 = 128, // Input Capture 1 Noise Canceller
        };
    };

    // Timer/Counter1 Control Register C
    struct TCCR1C {
        static const uint8_t address = 0x82;
        enum bits : uint8_t {
            FOC1C = 32,  // Force Output Compare for Channel C
            FOC1B = 64,  // Force Output Compare for Channel B
            FOC1A = 128, // Force Output Compare for Channel A
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
            COM3C0 = 4,   // Compare Output Mode for Channel C
            COM3C1 = 8,   // Compare Output Mode for Channel C
            COM3B0 = 16,  // Compare Output Mode for Channel B
            COM3B1 = 32,  // Compare Output Mode for Channel B
            COM3A0 = 64,  // Compare Output Mode for Channel A
            COM3A1 = 128, // Compare Output Mode for Channel A
        };
    };

    // Timer/Counter3 Control Register B
    struct TCCR3B {
        static const uint8_t address = 0x91;
        enum bits : uint8_t {
            CS30  = 1,   // Clock Select
            CS31  = 2,   // Clock Select
            CS32  = 4,   // Clock Select
            WGM30 = 8,   // Waveform Generation Mode
            WGM31 = 16,  // Waveform Generation Mode
            Res   = 32,  // Reserved Bit
            ICES3 = 64,  // Input Capture 3 Edge Select
            ICNC3 = 128, // Input Capture 3 Noise Canceller
        };
    };

    // Timer/Counter3 Control Register C
    struct TCCR3C {
        static const uint8_t address = 0x92;
        enum bits : uint8_t {
            FOC3C = 32,  // Force Output Compare for Channel C
            FOC3B = 64,  // Force Output Compare for Channel B
            FOC3A = 128, // Force Output Compare for Channel A
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

    // Timer/Counter3 Output Compare Register C  Bytes
    struct OCR3C {
        static const uint16_t address = 0x9c;
    };

    // Timer/Counter4 Control Register A
    struct TCCR4A {
        static const uint8_t address = 0xa0;
        enum bits : uint8_t {
            WGM40  = 1,   // Waveform Generation Mode
            WGM41  = 2,   // Waveform Generation Mode
            COM4C0 = 4,   // Compare Output Mode for Channel C
            COM4C1 = 8,   // Compare Output Mode for Channel C
            COM4B0 = 16,  // Compare Output Mode for Channel B
            COM4B1 = 32,  // Compare Output Mode for Channel B
            COM4A0 = 64,  // Compare Output Mode for Channel A
            COM4A1 = 128, // Compare Output Mode for Channel A
        };
    };

    // Timer/Counter4 Control Register B
    struct TCCR4B {
        static const uint8_t address = 0xa1;
        enum bits : uint8_t {
            CS40  = 1,   // Clock Select
            CS41  = 2,   // Clock Select
            CS42  = 4,   // Clock Select
            WGM40 = 8,   // Waveform Generation Mode
            WGM41 = 16,  // Waveform Generation Mode
            Res   = 32,  // Reserved Bit
            ICES4 = 64,  // Input Capture 4 Edge Select
            ICNC4 = 128, // Input Capture 4 Noise Canceller
        };
    };

    // Timer/Counter4 Control Register C
    struct TCCR4C {
        static const uint8_t address = 0xa2;
        enum bits : uint8_t {
            FOC4C = 32,  // Force Output Compare for Channel C
            FOC4B = 64,  // Force Output Compare for Channel B
            FOC4A = 128, // Force Output Compare for Channel A
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

    // Timer/Counter4 Output Compare Register C  Bytes
    struct OCR4C {
        static const uint16_t address = 0xac;
    };

    // Timer/Counter2 Control Register A
    struct TCCR2A {
        static const uint8_t address = 0xb0;
        enum bits : uint8_t {
            WGM20  = 1,   // Waveform Generation Mode
            WGM21  = 2,   // Waveform Generation Mode
            COM2B0 = 16,  // Compare Match Output B Mode
            COM2B1 = 32,  // Compare Match Output B Mode
            COM2A0 = 64,  // Compare Match Output A Mode
            COM2A1 = 128, // Compare Match Output A Mode
        };
    };

    // Timer/Counter2 Control Register B
    struct TCCR2B {
        static const uint8_t address = 0xb1;
        enum bits : uint8_t {
            CS20  = 1,   // Clock Select
            CS21  = 2,   // Clock Select
            CS22  = 4,   // Clock Select
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
            TCR2BUB  = 1,   // Timer/Counter2 Control Register B Update Busy
            TCR2AUB  = 2,   // Timer/Counter2 Control Register A Update Busy
            OCR2BUB  = 4,   // Timer/Counter2 Output Compare Register B Update Busy
            OCR2AUB  = 8,   // Timer/Counter2 Output Compare Register A Update Busy
            TCN2UB   = 16,  // Timer/Counter2 Update Busy
            AS2      = 32,  // Timer/Counter2 Asynchronous Mode
            EXCLK    = 64,  // Enable External Clock Input
            EXCLKAMR = 128, // Enable External Clock Input for AMR
        };
    };

    // TWI Bit Rate Register
    struct TWBR {
        static const uint8_t address = 0xb8;
    };

    // TWI Status Register
    struct TWSR {
        static const uint8_t address = 0xb9;
        enum bits : uint8_t {
            TWPS0 = 1,   // TWI Prescaler Bits
            TWPS1 = 2,   // TWI Prescaler Bits
            Res   = 4,   // Reserved Bit
            TWS0  = 8,   // TWI Status
            TWS1  = 16,  // TWI Status
            TWS2  = 32,  // TWI Status
            TWS3  = 64,  // TWI Status
            TWS4  = 128, // TWI Status
        };
    };

    // TWI (Slave) Address Register
    struct TWAR {
        static const uint8_t address = 0xba;
        enum bits : uint8_t {
            TWGCE = 1,   // TWI General Call Recognition Enable Bit
            TWA0  = 2,   // TWI (Slave) Address
            TWA1  = 4,   // TWI (Slave) Address
            TWA2  = 8,   // TWI (Slave) Address
            TWA3  = 16,  // TWI (Slave) Address
            TWA4  = 32,  // TWI (Slave) Address
            TWA5  = 64,  // TWI (Slave) Address
            TWA6  = 128, // TWI (Slave) Address
        };
    };

    // TWI Data Register
    struct TWDR {
        static const uint8_t address = 0xbb;
    };

    // TWI Control Register
    struct TWCR {
        static const uint8_t address = 0xbc;
        enum bits : uint8_t {
            TWIE  = 1,   // TWI Interrupt Enable
            Res   = 2,   // Reserved Bit
            TWEN  = 4,   // TWI Enable Bit
            TWWC  = 8,   // TWI Write Collision Flag
            TWSTO = 16,  // TWI STOP Condition Bit
            TWSTA = 32,  // TWI START Condition Bit
            TWEA  = 64,  // TWI Enable Acknowledge Bit
            TWINT = 128, // TWI Interrupt Flag
        };
    };

    // TWI (Slave) Address Mask Register
    struct TWAMR {
        static const uint8_t address = 0xbd;
        enum bits : uint8_t {
            Res   = 1,   // Reserved Bit
            TWAM0 = 2,   // TWI Address Mask
            TWAM1 = 4,   // TWI Address Mask
            TWAM2 = 8,   // TWI Address Mask
            TWAM3 = 16,  // TWI Address Mask
            TWAM4 = 32,  // TWI Address Mask
            TWAM5 = 64,  // TWI Address Mask
            TWAM6 = 128, // TWI Address Mask
        };
    };

    // Transceiver Interrupt Enable Register 1
    struct IRQ_MASK1 {
        static const uint8_t address = 0xbe;
        enum bits : uint8_t {
            TX_START_EN  = 1,   // Transmit Start Interrupt enable
            MAF_0_AMI_EN = 2,   // Address Match Interrupt enable Address filter 0
            MAF_1_AMI_EN = 4,   // Address Match Interrupt enable Address filter 1
            MAF_2_AMI_EN = 8,   // Address Match Interrupt enable Address filter 2
            MAF_3_AMI_EN = 16,  // Address Match Interrupt enable Address filter 3
            Res0         = 32,  // Reserved Bit
            Res1         = 64,  // Reserved Bit
            Res2         = 128, // Reserved Bit
        };
    };

    // Transceiver Interrupt Status Register 1
    struct IRQ_STATUS1 {
        static const uint8_t address = 0xbf;
        enum bits : uint8_t {
            TX_START  = 1,   // Transmit Start Interrupt Status
            MAF_0_AMI = 2,   // Address Match Interrupt Status Address filter 0
            MAF_1_AMI = 4,   // Address Match Interrupt Status Address filter 1
            MAF_2_AMI = 8,   // Address Match Interrupt Status Address filter 2
            MAF_3_AMI = 16,  // Address Match Interrupt Status Address filter 3
            Res0      = 32,  // Reserved Bit
            Res1      = 64,  // Reserved Bit
            Res2      = 128, // Reserved Bit
        };
    };

    // USART0 Control and Status Register A
    struct UCSR0A {
        static const uint8_t address = 0xc0;
        enum bits : uint8_t {
            MPCM0 = 1,   // Multi-processor Communication Mode
            U2X0  = 2,   // Double the USART Transmission Speed
            UPE0  = 4,   // USART Parity Error
            DOR0  = 8,   // Data OverRun
            FE0   = 16,  // Frame Error
            UDRE0 = 32,  // USART Data Register Empty
            TXC0  = 64,  // USART Transmit Complete
            RXC0  = 128, // USART Receive Complete
        };
    };

    // USART0 Control and Status Register B
    struct UCSR0B {
        static const uint8_t address = 0xc1;
        enum bits : uint8_t {
            TXB80  = 1,   // Transmit Data Bit 8
            RXB80  = 2,   // Receive Data Bit 8
            UCSZ02 = 4,   // Character Size
            TXEN0  = 8,   // Transmitter Enable
            RXEN0  = 16,  // Receiver Enable
            UDRIE0 = 32,  // USART Data Register Empty Interrupt Enable
            TXCIE0 = 64,  // TX Complete Interrupt Enable
            RXCIE0 = 128, // RX Complete Interrupt Enable
        };
    };

    // USART0 Control and Status Register C
    struct UCSR0C {
        static const uint8_t address = 0xc2;
        enum bits : uint8_t {
            UCPOL0  = 1,   // Clock Polarity
            UCPHA0  = 2,   // Clock Phase
            UCSZ00  = 2,   // Character Size
            UDORD0  = 4,   // Data Order
            UCSZ01  = 4,   // Character Size
            USBS0   = 8,   // Stop Bit Select
            UPM00   = 16,  // Parity Mode
            UPM01   = 32,  // Parity Mode
            UMSEL00 = 64,  // USART Mode Select
            UMSEL01 = 128, // USART Mode Select
        };
    };

    // USART0 Baud Rate Register  Bytes
    struct UBRR0 {
        static const uint16_t address = 0xc4;
    };

    // USART0 I/O Data Register
    struct UDR0 {
        static const uint8_t address = 0xc6;
    };

    // USART1 Control and Status Register A
    struct UCSR1A {
        static const uint8_t address = 0xc8;
        enum bits : uint8_t {
            MPCM1 = 1,   // Multi-processor Communication Mode
            U2X1  = 2,   // Double the USART Transmission Speed
            UPE1  = 4,   // USART Parity Error
            DOR1  = 8,   // Data OverRun
            FE1   = 16,  // Frame Error
            UDRE1 = 32,  // USART Data Register Empty
            TXC1  = 64,  // USART Transmit Complete
            RXC1  = 128, // USART Receive Complete
        };
    };

    // USART1 Control and Status Register B
    struct UCSR1B {
        static const uint8_t address = 0xc9;
        enum bits : uint8_t {
            TXB81  = 1,   // Transmit Data Bit 8
            RXB81  = 2,   // Receive Data Bit 8
            UCSZ12 = 4,   // Character Size
            TXEN1  = 8,   // Transmitter Enable
            RXEN1  = 16,  // Receiver Enable
            UDRIE1 = 32,  // USART Data Register Empty Interrupt Enable
            TXCIE1 = 64,  // TX Complete Interrupt Enable
            RXCIE1 = 128, // RX Complete Interrupt Enable
        };
    };

    // USART1 Control and Status Register C
    struct UCSR1C {
        static const uint8_t address = 0xca;
        enum bits : uint8_t {
            UCPOL1  = 1,   // Clock Polarity
            UCPHA1  = 2,   // Clock Phase
            UCSZ10  = 2,   // Character Size
            UDORD1  = 4,   // Data Order
            UCSZ11  = 4,   // Character Size
            USBS1   = 8,   // Stop Bit Select
            UPM10   = 16,  // Parity Mode
            UPM11   = 32,  // Parity Mode
            UMSEL10 = 64,  // USART Mode Select
            UMSEL11 = 128, // USART Mode Select
        };
    };

    // USART1 Baud Rate Register  Bytes
    struct UBRR1 {
        static const uint16_t address = 0xcc;
    };

    // USART1 I/O Data Register
    struct UDR1 {
        static const uint8_t address = 0xce;
    };

    // Symbol Counter Received Frame Timestamp Register LL-Byte
    struct SCRSTRLL {
        static const uint8_t address = 0xd7;
        enum bits : uint8_t {
            SCRSTRLL0 = 1,   // Symbol Counter Received Frame Timestamp Register LL-Byte
            SCRSTRLL1 = 2,   // Symbol Counter Received Frame Timestamp Register LL-Byte
            SCRSTRLL2 = 4,   // Symbol Counter Received Frame Timestamp Register LL-Byte
            SCRSTRLL3 = 8,   // Symbol Counter Received Frame Timestamp Register LL-Byte
            SCRSTRLL4 = 16,  // Symbol Counter Received Frame Timestamp Register LL-Byte
            SCRSTRLL5 = 32,  // Symbol Counter Received Frame Timestamp Register LL-Byte
            SCRSTRLL6 = 64,  // Symbol Counter Received Frame Timestamp Register LL-Byte
            SCRSTRLL7 = 128, // Symbol Counter Received Frame Timestamp Register LL-Byte
        };
    };

    // Symbol Counter Received Frame Timestamp Register LH-Byte
    struct SCRSTRLH {
        static const uint8_t address = 0xd8;
        enum bits : uint8_t {
            SCRSTRLH0 = 1,   // Symbol Counter Received Frame Timestamp Register LH-Byte
            SCRSTRLH1 = 2,   // Symbol Counter Received Frame Timestamp Register LH-Byte
            SCRSTRLH2 = 4,   // Symbol Counter Received Frame Timestamp Register LH-Byte
            SCRSTRLH3 = 8,   // Symbol Counter Received Frame Timestamp Register LH-Byte
            SCRSTRLH4 = 16,  // Symbol Counter Received Frame Timestamp Register LH-Byte
            SCRSTRLH5 = 32,  // Symbol Counter Received Frame Timestamp Register LH-Byte
            SCRSTRLH6 = 64,  // Symbol Counter Received Frame Timestamp Register LH-Byte
            SCRSTRLH7 = 128, // Symbol Counter Received Frame Timestamp Register LH-Byte
        };
    };

    // Symbol Counter Received Frame Timestamp Register HL-Byte
    struct SCRSTRHL {
        static const uint8_t address = 0xd9;
        enum bits : uint8_t {
            SCRSTRHL0 = 1,   // Symbol Counter Received Frame Timestamp Register HL-Byte
            SCRSTRHL1 = 2,   // Symbol Counter Received Frame Timestamp Register HL-Byte
            SCRSTRHL2 = 4,   // Symbol Counter Received Frame Timestamp Register HL-Byte
            SCRSTRHL3 = 8,   // Symbol Counter Received Frame Timestamp Register HL-Byte
            SCRSTRHL4 = 16,  // Symbol Counter Received Frame Timestamp Register HL-Byte
            SCRSTRHL5 = 32,  // Symbol Counter Received Frame Timestamp Register HL-Byte
            SCRSTRHL6 = 64,  // Symbol Counter Received Frame Timestamp Register HL-Byte
            SCRSTRHL7 = 128, // Symbol Counter Received Frame Timestamp Register HL-Byte
        };
    };

    // Symbol Counter Received Frame Timestamp Register HH-Byte
    struct SCRSTRHH {
        static const uint8_t address = 0xda;
        enum bits : uint8_t {
            SCRSTRHH0 = 1,   // Symbol Counter Received Frame Timestamp Register HH-Byte
            SCRSTRHH1 = 2,   // Symbol Counter Received Frame Timestamp Register HH-Byte
            SCRSTRHH2 = 4,   // Symbol Counter Received Frame Timestamp Register HH-Byte
            SCRSTRHH3 = 8,   // Symbol Counter Received Frame Timestamp Register HH-Byte
            SCRSTRHH4 = 16,  // Symbol Counter Received Frame Timestamp Register HH-Byte
            SCRSTRHH5 = 32,  // Symbol Counter Received Frame Timestamp Register HH-Byte
            SCRSTRHH6 = 64,  // Symbol Counter Received Frame Timestamp Register HH-Byte
            SCRSTRHH7 = 128, // Symbol Counter Received Frame Timestamp Register HH-Byte
        };
    };

    // Symbol Counter Compare Source Register
    struct SCCSR {
        static const uint8_t address = 0xdb;
        enum bits : uint8_t {
            SCCS10 = 1,   // Symbol Counter Compare Source select register for Compare Units
            SCCS11 = 2,   // Symbol Counter Compare Source select register for Compare Units
            SCCS20 = 4,   // Symbol Counter Compare Source select register for Compare Unit 2
            SCCS21 = 8,   // Symbol Counter Compare Source select register for Compare Unit 2
            SCCS30 = 16,  // Symbol Counter Compare Source select register for Compare Unit 3
            SCCS31 = 32,  // Symbol Counter Compare Source select register for Compare Unit 3
            Res0   = 64,  // Reserved Bit
            Res1   = 128, // Reserved Bit
        };
    };

    // Symbol Counter Control Register 0
    struct SCCR0 {
        static const uint8_t address = 0xdc;
        enum bits : uint8_t {
            SCCMP0  = 1,   // Symbol Counter Compare Unit 3 Mode select
            SCCMP1  = 2,   // Symbol Counter Compare Unit 3 Mode select
            SCCMP2  = 4,   // Symbol Counter Compare Unit 3 Mode select
            SCTSE   = 8,   // Symbol Counter Automatic Timestamping enable
            SCCKSEL = 16,  // Symbol Counter Clock Source select
            SCEN    = 32,  // Symbol Counter enable
            SCMBTS  = 64,  // Manual Beacon Timestamp
            SCRES   = 128, // Symbol Counter Synchronization
        };
    };

    // Symbol Counter Control Register 1
    struct SCCR1 {
        static const uint8_t address = 0xdd;
        enum bits : uint8_t {
            SCENBO   = 1,   // Backoff Slot Counter enable
            SCEECLK  = 2,   // Enable External Clock Source on PG2
            SCCKDIV0 = 4,   // Clock divider for synchronous clock source (16MHz Transceiver Clock)
            SCCKDIV1 = 8,   // Clock divider for synchronous clock source (16MHz Transceiver Clock)
            SCCKDIV2 = 16,  // Clock divider for synchronous clock source (16MHz Transceiver Clock)
            SCBTSM   = 32,  // Symbol Counter Beacon Timestamp Mask Register
            Res0     = 64,  // Reserved Bit
            Res1     = 128, // Reserved Bit
        };
    };

    // Symbol Counter Status Register
    struct SCSR {
        static const uint8_t address = 0xde;
        enum bits : uint8_t {
            SCBSY = 1,   // Symbol Counter busy
            Res0  = 2,   // Reserved Bit
            Res1  = 4,   // Reserved Bit
            Res2  = 8,   // Reserved Bit
            Res3  = 16,  // Reserved Bit
            Res4  = 32,  // Reserved Bit
            Res5  = 64,  // Reserved Bit
            Res6  = 128, // Reserved Bit
        };
    };

    // Symbol Counter Interrupt Mask Register
    struct SCIRQM {
        static const uint8_t address = 0xdf;
        enum bits : uint8_t {
            IRQMCP0 = 1,   // Symbol Counter Compare Match 3 IRQ enable
            IRQMCP1 = 2,   // Symbol Counter Compare Match 3 IRQ enable
            IRQMCP2 = 4,   // Symbol Counter Compare Match 3 IRQ enable
            IRQMOF  = 8,   // Symbol Counter Overflow IRQ enable
            IRQMBO  = 16,  // Backoff Slot Counter IRQ enable
            Res0    = 32,  // Reserved Bit
            Res1    = 64,  // Reserved Bit
            Res2    = 128, // Reserved Bit
        };
    };

    // Symbol Counter Interrupt Status Register
    struct SCIRQS {
        static const uint8_t address = 0xe0;
        enum bits : uint8_t {
            IRQSCP0 = 1,   // Compare Unit 3 Compare Match IRQ
            IRQSCP1 = 2,   // Compare Unit 3 Compare Match IRQ
            IRQSCP2 = 4,   // Compare Unit 3 Compare Match IRQ
            IRQSOF  = 8,   // Symbol Counter Overflow IRQ
            IRQSBO  = 16,  // Backoff Slot Counter IRQ
            Res0    = 32,  // Reserved Bit
            Res1    = 64,  // Reserved Bit
            Res2    = 128, // Reserved Bit
        };
    };

    // Symbol Counter Register LL-Byte
    struct SCCNTLL {
        static const uint8_t address = 0xe1;
        enum bits : uint8_t {
            SCCNTLL0 = 1,   // Symbol Counter Register LL-Byte
            SCCNTLL1 = 2,   // Symbol Counter Register LL-Byte
            SCCNTLL2 = 4,   // Symbol Counter Register LL-Byte
            SCCNTLL3 = 8,   // Symbol Counter Register LL-Byte
            SCCNTLL4 = 16,  // Symbol Counter Register LL-Byte
            SCCNTLL5 = 32,  // Symbol Counter Register LL-Byte
            SCCNTLL6 = 64,  // Symbol Counter Register LL-Byte
            SCCNTLL7 = 128, // Symbol Counter Register LL-Byte
        };
    };

    // Symbol Counter Register LH-Byte
    struct SCCNTLH {
        static const uint8_t address = 0xe2;
        enum bits : uint8_t {
            SCCNTLH0 = 1,   // Symbol Counter Register LH-Byte
            SCCNTLH1 = 2,   // Symbol Counter Register LH-Byte
            SCCNTLH2 = 4,   // Symbol Counter Register LH-Byte
            SCCNTLH3 = 8,   // Symbol Counter Register LH-Byte
            SCCNTLH4 = 16,  // Symbol Counter Register LH-Byte
            SCCNTLH5 = 32,  // Symbol Counter Register LH-Byte
            SCCNTLH6 = 64,  // Symbol Counter Register LH-Byte
            SCCNTLH7 = 128, // Symbol Counter Register LH-Byte
        };
    };

    // Symbol Counter Register HL-Byte
    struct SCCNTHL {
        static const uint8_t address = 0xe3;
        enum bits : uint8_t {
            SCCNTHL0 = 1,   // Symbol Counter Register HL-Byte
            SCCNTHL1 = 2,   // Symbol Counter Register HL-Byte
            SCCNTHL2 = 4,   // Symbol Counter Register HL-Byte
            SCCNTHL3 = 8,   // Symbol Counter Register HL-Byte
            SCCNTHL4 = 16,  // Symbol Counter Register HL-Byte
            SCCNTHL5 = 32,  // Symbol Counter Register HL-Byte
            SCCNTHL6 = 64,  // Symbol Counter Register HL-Byte
            SCCNTHL7 = 128, // Symbol Counter Register HL-Byte
        };
    };

    // Symbol Counter Register HH-Byte
    struct SCCNTHH {
        static const uint8_t address = 0xe4;
        enum bits : uint8_t {
            SCCNTHH0 = 1,   // Symbol Counter Register HH-Byte
            SCCNTHH1 = 2,   // Symbol Counter Register HH-Byte
            SCCNTHH2 = 4,   // Symbol Counter Register HH-Byte
            SCCNTHH3 = 8,   // Symbol Counter Register HH-Byte
            SCCNTHH4 = 16,  // Symbol Counter Register HH-Byte
            SCCNTHH5 = 32,  // Symbol Counter Register HH-Byte
            SCCNTHH6 = 64,  // Symbol Counter Register HH-Byte
            SCCNTHH7 = 128, // Symbol Counter Register HH-Byte
        };
    };

    // Symbol Counter Beacon Timestamp Register LL-Byte
    struct SCBTSRLL {
        static const uint8_t address = 0xe5;
        enum bits : uint8_t {
            SCBTSRLL0 = 1,   // Symbol Counter Beacon Timestamp Register LL-Byte
            SCBTSRLL1 = 2,   // Symbol Counter Beacon Timestamp Register LL-Byte
            SCBTSRLL2 = 4,   // Symbol Counter Beacon Timestamp Register LL-Byte
            SCBTSRLL3 = 8,   // Symbol Counter Beacon Timestamp Register LL-Byte
            SCBTSRLL4 = 16,  // Symbol Counter Beacon Timestamp Register LL-Byte
            SCBTSRLL5 = 32,  // Symbol Counter Beacon Timestamp Register LL-Byte
            SCBTSRLL6 = 64,  // Symbol Counter Beacon Timestamp Register LL-Byte
            SCBTSRLL7 = 128, // Symbol Counter Beacon Timestamp Register LL-Byte
        };
    };

    // Symbol Counter Beacon Timestamp Register LH-Byte
    struct SCBTSRLH {
        static const uint8_t address = 0xe6;
        enum bits : uint8_t {
            SCBTSRLH0 = 1,   // Symbol Counter Beacon Timestamp Register LH-Byte
            SCBTSRLH1 = 2,   // Symbol Counter Beacon Timestamp Register LH-Byte
            SCBTSRLH2 = 4,   // Symbol Counter Beacon Timestamp Register LH-Byte
            SCBTSRLH3 = 8,   // Symbol Counter Beacon Timestamp Register LH-Byte
            SCBTSRLH4 = 16,  // Symbol Counter Beacon Timestamp Register LH-Byte
            SCBTSRLH5 = 32,  // Symbol Counter Beacon Timestamp Register LH-Byte
            SCBTSRLH6 = 64,  // Symbol Counter Beacon Timestamp Register LH-Byte
            SCBTSRLH7 = 128, // Symbol Counter Beacon Timestamp Register LH-Byte
        };
    };

    // Symbol Counter Beacon Timestamp Register HL-Byte
    struct SCBTSRHL {
        static const uint8_t address = 0xe7;
        enum bits : uint8_t {
            SCBTSRHL0 = 1,   // Symbol Counter Beacon Timestamp Register HL-Byte
            SCBTSRHL1 = 2,   // Symbol Counter Beacon Timestamp Register HL-Byte
            SCBTSRHL2 = 4,   // Symbol Counter Beacon Timestamp Register HL-Byte
            SCBTSRHL3 = 8,   // Symbol Counter Beacon Timestamp Register HL-Byte
            SCBTSRHL4 = 16,  // Symbol Counter Beacon Timestamp Register HL-Byte
            SCBTSRHL5 = 32,  // Symbol Counter Beacon Timestamp Register HL-Byte
            SCBTSRHL6 = 64,  // Symbol Counter Beacon Timestamp Register HL-Byte
            SCBTSRHL7 = 128, // Symbol Counter Beacon Timestamp Register HL-Byte
        };
    };

    // Symbol Counter Beacon Timestamp Register HH-Byte
    struct SCBTSRHH {
        static const uint8_t address = 0xe8;
        enum bits : uint8_t {
            SCBTSRHH0 = 1,   // Symbol Counter Beacon Timestamp Register HH-Byte
            SCBTSRHH1 = 2,   // Symbol Counter Beacon Timestamp Register HH-Byte
            SCBTSRHH2 = 4,   // Symbol Counter Beacon Timestamp Register HH-Byte
            SCBTSRHH3 = 8,   // Symbol Counter Beacon Timestamp Register HH-Byte
            SCBTSRHH4 = 16,  // Symbol Counter Beacon Timestamp Register HH-Byte
            SCBTSRHH5 = 32,  // Symbol Counter Beacon Timestamp Register HH-Byte
            SCBTSRHH6 = 64,  // Symbol Counter Beacon Timestamp Register HH-Byte
            SCBTSRHH7 = 128, // Symbol Counter Beacon Timestamp Register HH-Byte
        };
    };

    // Symbol Counter Frame Timestamp Register LL-Byte
    struct SCTSRLL {
        static const uint8_t address = 0xe9;
        enum bits : uint8_t {
            SCTSRLL0 = 1,   // Symbol Counter Frame Timestamp Register LL-Byte
            SCTSRLL1 = 2,   // Symbol Counter Frame Timestamp Register LL-Byte
            SCTSRLL2 = 4,   // Symbol Counter Frame Timestamp Register LL-Byte
            SCTSRLL3 = 8,   // Symbol Counter Frame Timestamp Register LL-Byte
            SCTSRLL4 = 16,  // Symbol Counter Frame Timestamp Register LL-Byte
            SCTSRLL5 = 32,  // Symbol Counter Frame Timestamp Register LL-Byte
            SCTSRLL6 = 64,  // Symbol Counter Frame Timestamp Register LL-Byte
            SCTSRLL7 = 128, // Symbol Counter Frame Timestamp Register LL-Byte
        };
    };

    // Symbol Counter Frame Timestamp Register LH-Byte
    struct SCTSRLH {
        static const uint8_t address = 0xea;
        enum bits : uint8_t {
            SCTSRLH0 = 1,   // Symbol Counter Frame Timestamp Register LH-Byte
            SCTSRLH1 = 2,   // Symbol Counter Frame Timestamp Register LH-Byte
            SCTSRLH2 = 4,   // Symbol Counter Frame Timestamp Register LH-Byte
            SCTSRLH3 = 8,   // Symbol Counter Frame Timestamp Register LH-Byte
            SCTSRLH4 = 16,  // Symbol Counter Frame Timestamp Register LH-Byte
            SCTSRLH5 = 32,  // Symbol Counter Frame Timestamp Register LH-Byte
            SCTSRLH6 = 64,  // Symbol Counter Frame Timestamp Register LH-Byte
            SCTSRLH7 = 128, // Symbol Counter Frame Timestamp Register LH-Byte
        };
    };

    // Symbol Counter Frame Timestamp Register HL-Byte
    struct SCTSRHL {
        static const uint8_t address = 0xeb;
        enum bits : uint8_t {
            SCTSRHL0 = 1,   // Symbol Counter Frame Timestamp Register HL-Byte
            SCTSRHL1 = 2,   // Symbol Counter Frame Timestamp Register HL-Byte
            SCTSRHL2 = 4,   // Symbol Counter Frame Timestamp Register HL-Byte
            SCTSRHL3 = 8,   // Symbol Counter Frame Timestamp Register HL-Byte
            SCTSRHL4 = 16,  // Symbol Counter Frame Timestamp Register HL-Byte
            SCTSRHL5 = 32,  // Symbol Counter Frame Timestamp Register HL-Byte
            SCTSRHL6 = 64,  // Symbol Counter Frame Timestamp Register HL-Byte
            SCTSRHL7 = 128, // Symbol Counter Frame Timestamp Register HL-Byte
        };
    };

    // Symbol Counter Frame Timestamp Register HH-Byte
    struct SCTSRHH {
        static const uint8_t address = 0xec;
        enum bits : uint8_t {
            SCTSRHH0 = 1,   // Symbol Counter Frame Timestamp Register HH-Byte
            SCTSRHH1 = 2,   // Symbol Counter Frame Timestamp Register HH-Byte
            SCTSRHH2 = 4,   // Symbol Counter Frame Timestamp Register HH-Byte
            SCTSRHH3 = 8,   // Symbol Counter Frame Timestamp Register HH-Byte
            SCTSRHH4 = 16,  // Symbol Counter Frame Timestamp Register HH-Byte
            SCTSRHH5 = 32,  // Symbol Counter Frame Timestamp Register HH-Byte
            SCTSRHH6 = 64,  // Symbol Counter Frame Timestamp Register HH-Byte
            SCTSRHH7 = 128, // Symbol Counter Frame Timestamp Register HH-Byte
        };
    };

    // Symbol Counter Output Compare Register 3 LL-Byte
    struct SCOCR3LL {
        static const uint8_t address = 0xed;
        enum bits : uint8_t {
            SCOCR3LL0 = 1,   // Symbol Counter Output Compare Register 3 LL-Byte
            SCOCR3LL1 = 2,   // Symbol Counter Output Compare Register 3 LL-Byte
            SCOCR3LL2 = 4,   // Symbol Counter Output Compare Register 3 LL-Byte
            SCOCR3LL3 = 8,   // Symbol Counter Output Compare Register 3 LL-Byte
            SCOCR3LL4 = 16,  // Symbol Counter Output Compare Register 3 LL-Byte
            SCOCR3LL5 = 32,  // Symbol Counter Output Compare Register 3 LL-Byte
            SCOCR3LL6 = 64,  // Symbol Counter Output Compare Register 3 LL-Byte
            SCOCR3LL7 = 128, // Symbol Counter Output Compare Register 3 LL-Byte
        };
    };

    // Symbol Counter Output Compare Register 3 LH-Byte
    struct SCOCR3LH {
        static const uint8_t address = 0xee;
        enum bits : uint8_t {
            SCOCR3LH0 = 1,   // Symbol Counter Output Compare Register 3 LH-Byte
            SCOCR3LH1 = 2,   // Symbol Counter Output Compare Register 3 LH-Byte
            SCOCR3LH2 = 4,   // Symbol Counter Output Compare Register 3 LH-Byte
            SCOCR3LH3 = 8,   // Symbol Counter Output Compare Register 3 LH-Byte
            SCOCR3LH4 = 16,  // Symbol Counter Output Compare Register 3 LH-Byte
            SCOCR3LH5 = 32,  // Symbol Counter Output Compare Register 3 LH-Byte
            SCOCR3LH6 = 64,  // Symbol Counter Output Compare Register 3 LH-Byte
            SCOCR3LH7 = 128, // Symbol Counter Output Compare Register 3 LH-Byte
        };
    };

    // Symbol Counter Output Compare Register 3 HL-Byte
    struct SCOCR3HL {
        static const uint8_t address = 0xef;
        enum bits : uint8_t {
            SCOCR3HL0 = 1,   // Symbol Counter Output Compare Register 3 HL-Byte
            SCOCR3HL1 = 2,   // Symbol Counter Output Compare Register 3 HL-Byte
            SCOCR3HL2 = 4,   // Symbol Counter Output Compare Register 3 HL-Byte
            SCOCR3HL3 = 8,   // Symbol Counter Output Compare Register 3 HL-Byte
            SCOCR3HL4 = 16,  // Symbol Counter Output Compare Register 3 HL-Byte
            SCOCR3HL5 = 32,  // Symbol Counter Output Compare Register 3 HL-Byte
            SCOCR3HL6 = 64,  // Symbol Counter Output Compare Register 3 HL-Byte
            SCOCR3HL7 = 128, // Symbol Counter Output Compare Register 3 HL-Byte
        };
    };

    // Symbol Counter Output Compare Register 3 HH-Byte
    struct SCOCR3HH {
        static const uint8_t address = 0xf0;
        enum bits : uint8_t {
            SCOCR3HH0 = 1,   // Symbol Counter Output Compare Register 3 HH-Byte
            SCOCR3HH1 = 2,   // Symbol Counter Output Compare Register 3 HH-Byte
            SCOCR3HH2 = 4,   // Symbol Counter Output Compare Register 3 HH-Byte
            SCOCR3HH3 = 8,   // Symbol Counter Output Compare Register 3 HH-Byte
            SCOCR3HH4 = 16,  // Symbol Counter Output Compare Register 3 HH-Byte
            SCOCR3HH5 = 32,  // Symbol Counter Output Compare Register 3 HH-Byte
            SCOCR3HH6 = 64,  // Symbol Counter Output Compare Register 3 HH-Byte
            SCOCR3HH7 = 128, // Symbol Counter Output Compare Register 3 HH-Byte
        };
    };

    // Symbol Counter Output Compare Register 2 LL-Byte
    struct SCOCR2LL {
        static const uint8_t address = 0xf1;
        enum bits : uint8_t {
            SCOCR2LL0 = 1,   // Symbol Counter Output Compare Register 2 LL-Byte
            SCOCR2LL1 = 2,   // Symbol Counter Output Compare Register 2 LL-Byte
            SCOCR2LL2 = 4,   // Symbol Counter Output Compare Register 2 LL-Byte
            SCOCR2LL3 = 8,   // Symbol Counter Output Compare Register 2 LL-Byte
            SCOCR2LL4 = 16,  // Symbol Counter Output Compare Register 2 LL-Byte
            SCOCR2LL5 = 32,  // Symbol Counter Output Compare Register 2 LL-Byte
            SCOCR2LL6 = 64,  // Symbol Counter Output Compare Register 2 LL-Byte
            SCOCR2LL7 = 128, // Symbol Counter Output Compare Register 2 LL-Byte
        };
    };

    // Symbol Counter Output Compare Register 2 LH-Byte
    struct SCOCR2LH {
        static const uint8_t address = 0xf2;
        enum bits : uint8_t {
            SCOCR2LH0 = 1,   // Symbol Counter Output Compare Register 2 LH-Byte
            SCOCR2LH1 = 2,   // Symbol Counter Output Compare Register 2 LH-Byte
            SCOCR2LH2 = 4,   // Symbol Counter Output Compare Register 2 LH-Byte
            SCOCR2LH3 = 8,   // Symbol Counter Output Compare Register 2 LH-Byte
            SCOCR2LH4 = 16,  // Symbol Counter Output Compare Register 2 LH-Byte
            SCOCR2LH5 = 32,  // Symbol Counter Output Compare Register 2 LH-Byte
            SCOCR2LH6 = 64,  // Symbol Counter Output Compare Register 2 LH-Byte
            SCOCR2LH7 = 128, // Symbol Counter Output Compare Register 2 LH-Byte
        };
    };

    // Symbol Counter Output Compare Register 2 HL-Byte
    struct SCOCR2HL {
        static const uint8_t address = 0xf3;
        enum bits : uint8_t {
            SCOCR2HL0 = 1,   // Symbol Counter Output Compare Register 2 HL-Byte
            SCOCR2HL1 = 2,   // Symbol Counter Output Compare Register 2 HL-Byte
            SCOCR2HL2 = 4,   // Symbol Counter Output Compare Register 2 HL-Byte
            SCOCR2HL3 = 8,   // Symbol Counter Output Compare Register 2 HL-Byte
            SCOCR2HL4 = 16,  // Symbol Counter Output Compare Register 2 HL-Byte
            SCOCR2HL5 = 32,  // Symbol Counter Output Compare Register 2 HL-Byte
            SCOCR2HL6 = 64,  // Symbol Counter Output Compare Register 2 HL-Byte
            SCOCR2HL7 = 128, // Symbol Counter Output Compare Register 2 HL-Byte
        };
    };

    // Symbol Counter Output Compare Register 2 HH-Byte
    struct SCOCR2HH {
        static const uint8_t address = 0xf4;
        enum bits : uint8_t {
            SCOCR2HH0 = 1,   // Symbol Counter Output Compare Register 2 HH-Byte
            SCOCR2HH1 = 2,   // Symbol Counter Output Compare Register 2 HH-Byte
            SCOCR2HH2 = 4,   // Symbol Counter Output Compare Register 2 HH-Byte
            SCOCR2HH3 = 8,   // Symbol Counter Output Compare Register 2 HH-Byte
            SCOCR2HH4 = 16,  // Symbol Counter Output Compare Register 2 HH-Byte
            SCOCR2HH5 = 32,  // Symbol Counter Output Compare Register 2 HH-Byte
            SCOCR2HH6 = 64,  // Symbol Counter Output Compare Register 2 HH-Byte
            SCOCR2HH7 = 128, // Symbol Counter Output Compare Register 2 HH-Byte
        };
    };

    // Symbol Counter Output Compare Register 1 LL-Byte
    struct SCOCR1LL {
        static const uint8_t address = 0xf5;
        enum bits : uint8_t {
            SCOCR1LL0 = 1,   // Symbol Counter Output Compare Register 1 LL-Byte
            SCOCR1LL1 = 2,   // Symbol Counter Output Compare Register 1 LL-Byte
            SCOCR1LL2 = 4,   // Symbol Counter Output Compare Register 1 LL-Byte
            SCOCR1LL3 = 8,   // Symbol Counter Output Compare Register 1 LL-Byte
            SCOCR1LL4 = 16,  // Symbol Counter Output Compare Register 1 LL-Byte
            SCOCR1LL5 = 32,  // Symbol Counter Output Compare Register 1 LL-Byte
            SCOCR1LL6 = 64,  // Symbol Counter Output Compare Register 1 LL-Byte
            SCOCR1LL7 = 128, // Symbol Counter Output Compare Register 1 LL-Byte
        };
    };

    // Symbol Counter Output Compare Register 1 LH-Byte
    struct SCOCR1LH {
        static const uint8_t address = 0xf6;
        enum bits : uint8_t {
            SCOCR1LH0 = 1,   // Symbol Counter Output Compare Register 1 LH-Byte
            SCOCR1LH1 = 2,   // Symbol Counter Output Compare Register 1 LH-Byte
            SCOCR1LH2 = 4,   // Symbol Counter Output Compare Register 1 LH-Byte
            SCOCR1LH3 = 8,   // Symbol Counter Output Compare Register 1 LH-Byte
            SCOCR1LH4 = 16,  // Symbol Counter Output Compare Register 1 LH-Byte
            SCOCR1LH5 = 32,  // Symbol Counter Output Compare Register 1 LH-Byte
            SCOCR1LH6 = 64,  // Symbol Counter Output Compare Register 1 LH-Byte
            SCOCR1LH7 = 128, // Symbol Counter Output Compare Register 1 LH-Byte
        };
    };

    // Symbol Counter Output Compare Register 1 HL-Byte
    struct SCOCR1HL {
        static const uint8_t address = 0xf7;
        enum bits : uint8_t {
            SCOCR1HL0 = 1,   // Symbol Counter Output Compare Register 1 HL-Byte
            SCOCR1HL1 = 2,   // Symbol Counter Output Compare Register 1 HL-Byte
            SCOCR1HL2 = 4,   // Symbol Counter Output Compare Register 1 HL-Byte
            SCOCR1HL3 = 8,   // Symbol Counter Output Compare Register 1 HL-Byte
            SCOCR1HL4 = 16,  // Symbol Counter Output Compare Register 1 HL-Byte
            SCOCR1HL5 = 32,  // Symbol Counter Output Compare Register 1 HL-Byte
            SCOCR1HL6 = 64,  // Symbol Counter Output Compare Register 1 HL-Byte
            SCOCR1HL7 = 128, // Symbol Counter Output Compare Register 1 HL-Byte
        };
    };

    // Symbol Counter Output Compare Register 1 HH-Byte
    struct SCOCR1HH {
        static const uint8_t address = 0xf8;
        enum bits : uint8_t {
            SCOCR1HH0 = 1,   // Symbol Counter Output Compare Register 1 HH-Byte
            SCOCR1HH1 = 2,   // Symbol Counter Output Compare Register 1 HH-Byte
            SCOCR1HH2 = 4,   // Symbol Counter Output Compare Register 1 HH-Byte
            SCOCR1HH3 = 8,   // Symbol Counter Output Compare Register 1 HH-Byte
            SCOCR1HH4 = 16,  // Symbol Counter Output Compare Register 1 HH-Byte
            SCOCR1HH5 = 32,  // Symbol Counter Output Compare Register 1 HH-Byte
            SCOCR1HH6 = 64,  // Symbol Counter Output Compare Register 1 HH-Byte
            SCOCR1HH7 = 128, // Symbol Counter Output Compare Register 1 HH-Byte
        };
    };

    // Symbol Counter Transmit Frame Timestamp Register LL-Byte
    struct SCTSTRLL {
        static const uint8_t address = 0xf9;
        enum bits : uint8_t {
            SCTSTRLL0 = 1,   // Symbol Counter Transmit Frame Timestamp Register LL-Byte
            SCTSTRLL1 = 2,   // Symbol Counter Transmit Frame Timestamp Register LL-Byte
            SCTSTRLL2 = 4,   // Symbol Counter Transmit Frame Timestamp Register LL-Byte
            SCTSTRLL3 = 8,   // Symbol Counter Transmit Frame Timestamp Register LL-Byte
            SCTSTRLL4 = 16,  // Symbol Counter Transmit Frame Timestamp Register LL-Byte
            SCTSTRLL5 = 32,  // Symbol Counter Transmit Frame Timestamp Register LL-Byte
            SCTSTRLL6 = 64,  // Symbol Counter Transmit Frame Timestamp Register LL-Byte
            SCTSTRLL7 = 128, // Symbol Counter Transmit Frame Timestamp Register LL-Byte
        };
    };

    // Symbol Counter Transmit Frame Timestamp Register LH-Byte
    struct SCTSTRLH {
        static const uint8_t address = 0xfa;
        enum bits : uint8_t {
            SCTSTRLH0 = 1,   // Symbol Counter Transmit Frame Timestamp Register LH-Byte
            SCTSTRLH1 = 2,   // Symbol Counter Transmit Frame Timestamp Register LH-Byte
            SCTSTRLH2 = 4,   // Symbol Counter Transmit Frame Timestamp Register LH-Byte
            SCTSTRLH3 = 8,   // Symbol Counter Transmit Frame Timestamp Register LH-Byte
            SCTSTRLH4 = 16,  // Symbol Counter Transmit Frame Timestamp Register LH-Byte
            SCTSTRLH5 = 32,  // Symbol Counter Transmit Frame Timestamp Register LH-Byte
            SCTSTRLH6 = 64,  // Symbol Counter Transmit Frame Timestamp Register LH-Byte
            SCTSTRLH7 = 128, // Symbol Counter Transmit Frame Timestamp Register LH-Byte
        };
    };

    // Symbol Counter Transmit Frame Timestamp Register HL-Byte
    struct SCTSTRHL {
        static const uint8_t address = 0xfb;
        enum bits : uint8_t {
            SCTSTRHL0 = 1,   // Symbol Counter Transmit Frame Timestamp Register HL-Byte
            SCTSTRHL1 = 2,   // Symbol Counter Transmit Frame Timestamp Register HL-Byte
            SCTSTRHL2 = 4,   // Symbol Counter Transmit Frame Timestamp Register HL-Byte
            SCTSTRHL3 = 8,   // Symbol Counter Transmit Frame Timestamp Register HL-Byte
            SCTSTRHL4 = 16,  // Symbol Counter Transmit Frame Timestamp Register HL-Byte
            SCTSTRHL5 = 32,  // Symbol Counter Transmit Frame Timestamp Register HL-Byte
            SCTSTRHL6 = 64,  // Symbol Counter Transmit Frame Timestamp Register HL-Byte
            SCTSTRHL7 = 128, // Symbol Counter Transmit Frame Timestamp Register HL-Byte
        };
    };

    // Symbol Counter Transmit Frame Timestamp Register HH-Byte
    struct SCTSTRHH {
        static const uint8_t address = 0xfc;
        enum bits : uint8_t {
            SCTSTRHH0 = 1,   // Symbol Counter Transmit Frame Timestamp Register HH-Byte
            SCTSTRHH1 = 2,   // Symbol Counter Transmit Frame Timestamp Register HH-Byte
            SCTSTRHH2 = 4,   // Symbol Counter Transmit Frame Timestamp Register HH-Byte
            SCTSTRHH3 = 8,   // Symbol Counter Transmit Frame Timestamp Register HH-Byte
            SCTSTRHH4 = 16,  // Symbol Counter Transmit Frame Timestamp Register HH-Byte
            SCTSTRHH5 = 32,  // Symbol Counter Transmit Frame Timestamp Register HH-Byte
            SCTSTRHH6 = 64,  // Symbol Counter Transmit Frame Timestamp Register HH-Byte
            SCTSTRHH7 = 128, // Symbol Counter Transmit Frame Timestamp Register HH-Byte
        };
    };

    // Multiple Address Filter Configuration Register 0
    struct MAFCR0 {
        static const uint8_t address = 0x10c;
        enum bits : uint8_t {
            MAF0EN = 1,   // Multiple Address Filter 0 Enable
            MAF1EN = 2,   // Multiple Address Filter 1 Enable
            MAF2EN = 4,   // Multiple Address Filter 2 Enable
            MAF3EN = 8,   // Multiple Address Filter 3 Enable
            Res0   = 16,  // Reserved Bit
            Res1   = 32,  // Reserved Bit
            Res2   = 64,  // Reserved Bit
            Res3   = 128, // Reserved Bit
        };
    };

    // Multiple Address Filter Configuration Register 1
    struct MAFCR1 {
        static const uint8_t address = 0x10d;
        enum bits : uint8_t {
            AACK_0_I_AM_COORD = 1,   // Enable PAN Coordinator mode for address filter 0.
            AACK_0_SET_PD     = 2,   // Set Data Pending bit for address filter 0.
            AACK_1_I_AM_COORD = 4,   // Enable PAN Coordinator mode for address filter 1.
            AACK_1_SET_PD     = 8,   // Set Data Pending bit for address filter 1.
            AACK_2_I_AM_COORD = 16,  // Enable PAN Coordinator mode for address filter 2.
            AACK_2_SET_PD     = 32,  // Set Data Pending bit for address filter 2.
            AACK_3_I_AM_COORD = 64,  // Enable PAN Coordinator mode for address filter 3.
            AACK_3_SET_PD     = 128, // Set Data Pending bit for address filter 3.
        };
    };

    // Transceiver MAC Short Address Register for Frame Filter 0 (Low Byte)
    struct MAFSA0L {
        static const uint8_t address = 0x10e;
        enum bits : uint8_t {
            MAFSA0L0 = 1,   // MAC Short Address low Byte for Frame Filter 0
            MAFSA0L1 = 2,   // MAC Short Address low Byte for Frame Filter 0
            MAFSA0L2 = 4,   // MAC Short Address low Byte for Frame Filter 0
            MAFSA0L3 = 8,   // MAC Short Address low Byte for Frame Filter 0
            MAFSA0L4 = 16,  // MAC Short Address low Byte for Frame Filter 0
            MAFSA0L5 = 32,  // MAC Short Address low Byte for Frame Filter 0
            MAFSA0L6 = 64,  // MAC Short Address low Byte for Frame Filter 0
            MAFSA0L7 = 128, // MAC Short Address low Byte for Frame Filter 0
        };
    };

    // Transceiver MAC Short Address Register for Frame Filter 0 (High Byte)
    struct MAFSA0H {
        static const uint8_t address = 0x10f;
        enum bits : uint8_t {
            MAFSA0H0 = 1,   // MAC Short Address high Byte for Frame Filter 0
            MAFSA0H1 = 2,   // MAC Short Address high Byte for Frame Filter 0
            MAFSA0H2 = 4,   // MAC Short Address high Byte for Frame Filter 0
            MAFSA0H3 = 8,   // MAC Short Address high Byte for Frame Filter 0
            MAFSA0H4 = 16,  // MAC Short Address high Byte for Frame Filter 0
            MAFSA0H5 = 32,  // MAC Short Address high Byte for Frame Filter 0
            MAFSA0H6 = 64,  // MAC Short Address high Byte for Frame Filter 0
            MAFSA0H7 = 128, // MAC Short Address high Byte for Frame Filter 0
        };
    };

    // Transceiver Personal Area Network ID Register for Frame Filter 0 (Low Byte)
    struct MAFPA0L {
        static const uint8_t address = 0x110;
        enum bits : uint8_t {
            MAFPA0L0 = 1,   // MAC Personal Area Network ID low Byte for Frame Filter 0
            MAFPA0L1 = 2,   // MAC Personal Area Network ID low Byte for Frame Filter 0
            MAFPA0L2 = 4,   // MAC Personal Area Network ID low Byte for Frame Filter 0
            MAFPA0L3 = 8,   // MAC Personal Area Network ID low Byte for Frame Filter 0
            MAFPA0L4 = 16,  // MAC Personal Area Network ID low Byte for Frame Filter 0
            MAFPA0L5 = 32,  // MAC Personal Area Network ID low Byte for Frame Filter 0
            MAFPA0L6 = 64,  // MAC Personal Area Network ID low Byte for Frame Filter 0
            MAFPA0L7 = 128, // MAC Personal Area Network ID low Byte for Frame Filter 0
        };
    };

    // Transceiver Personal Area Network ID Register for Frame Filter 0 (High Byte)
    struct MAFPA0H {
        static const uint8_t address = 0x111;
        enum bits : uint8_t {
            MAFPA0H0 = 1,   // MAC Personal Area Network ID high Byte for Frame Filter 0
            MAFPA0H1 = 2,   // MAC Personal Area Network ID high Byte for Frame Filter 0
            MAFPA0H2 = 4,   // MAC Personal Area Network ID high Byte for Frame Filter 0
            MAFPA0H3 = 8,   // MAC Personal Area Network ID high Byte for Frame Filter 0
            MAFPA0H4 = 16,  // MAC Personal Area Network ID high Byte for Frame Filter 0
            MAFPA0H5 = 32,  // MAC Personal Area Network ID high Byte for Frame Filter 0
            MAFPA0H6 = 64,  // MAC Personal Area Network ID high Byte for Frame Filter 0
            MAFPA0H7 = 128, // MAC Personal Area Network ID high Byte for Frame Filter 0
        };
    };

    // Transceiver MAC Short Address Register for Frame Filter 1 (Low Byte)
    struct MAFSA1L {
        static const uint8_t address = 0x112;
        enum bits : uint8_t {
            MAFSA1L0 = 1,   // MAC Short Address low Byte for Frame Filter 1
            MAFSA1L1 = 2,   // MAC Short Address low Byte for Frame Filter 1
            MAFSA1L2 = 4,   // MAC Short Address low Byte for Frame Filter 1
            MAFSA1L3 = 8,   // MAC Short Address low Byte for Frame Filter 1
            MAFSA1L4 = 16,  // MAC Short Address low Byte for Frame Filter 1
            MAFSA1L5 = 32,  // MAC Short Address low Byte for Frame Filter 1
            MAFSA1L6 = 64,  // MAC Short Address low Byte for Frame Filter 1
            MAFSA1L7 = 128, // MAC Short Address low Byte for Frame Filter 1
        };
    };

    // Transceiver MAC Short Address Register for Frame Filter 1 (High Byte)
    struct MAFSA1H {
        static const uint8_t address = 0x113;
        enum bits : uint8_t {
            MAFSA1H0 = 1,   // MAC Short Address high Byte for Frame Filter 1
            MAFSA1H1 = 2,   // MAC Short Address high Byte for Frame Filter 1
            MAFSA1H2 = 4,   // MAC Short Address high Byte for Frame Filter 1
            MAFSA1H3 = 8,   // MAC Short Address high Byte for Frame Filter 1
            MAFSA1H4 = 16,  // MAC Short Address high Byte for Frame Filter 1
            MAFSA1H5 = 32,  // MAC Short Address high Byte for Frame Filter 1
            MAFSA1H6 = 64,  // MAC Short Address high Byte for Frame Filter 1
            MAFSA1H7 = 128, // MAC Short Address high Byte for Frame Filter 1
        };
    };

    // Transceiver Personal Area Network ID Register for Frame Filter 1 (Low Byte)
    struct MAFPA1L {
        static const uint8_t address = 0x114;
        enum bits : uint8_t {
            MAFPA1L0 = 1,   // MAC Personal Area Network ID low Byte for Frame Filter 1
            MAFPA1L1 = 2,   // MAC Personal Area Network ID low Byte for Frame Filter 1
            MAFPA1L2 = 4,   // MAC Personal Area Network ID low Byte for Frame Filter 1
            MAFPA1L3 = 8,   // MAC Personal Area Network ID low Byte for Frame Filter 1
            MAFPA1L4 = 16,  // MAC Personal Area Network ID low Byte for Frame Filter 1
            MAFPA1L5 = 32,  // MAC Personal Area Network ID low Byte for Frame Filter 1
            MAFPA1L6 = 64,  // MAC Personal Area Network ID low Byte for Frame Filter 1
            MAFPA1L7 = 128, // MAC Personal Area Network ID low Byte for Frame Filter 1
        };
    };

    // Transceiver Personal Area Network ID Register for Frame Filter 1 (High Byte)
    struct MAFPA1H {
        static const uint8_t address = 0x115;
        enum bits : uint8_t {
            MAFPA1H0 = 1,   // MAC Personal Area Network ID high Byte for Frame Filter 1
            MAFPA1H1 = 2,   // MAC Personal Area Network ID high Byte for Frame Filter 1
            MAFPA1H2 = 4,   // MAC Personal Area Network ID high Byte for Frame Filter 1
            MAFPA1H3 = 8,   // MAC Personal Area Network ID high Byte for Frame Filter 1
            MAFPA1H4 = 16,  // MAC Personal Area Network ID high Byte for Frame Filter 1
            MAFPA1H5 = 32,  // MAC Personal Area Network ID high Byte for Frame Filter 1
            MAFPA1H6 = 64,  // MAC Personal Area Network ID high Byte for Frame Filter 1
            MAFPA1H7 = 128, // MAC Personal Area Network ID high Byte for Frame Filter 1
        };
    };

    // Transceiver MAC Short Address Register for Frame Filter 2 (Low Byte)
    struct MAFSA2L {
        static const uint8_t address = 0x116;
        enum bits : uint8_t {
            MAFSA2L0 = 1,   // MAC Short Address low Byte for Frame Filter 2
            MAFSA2L1 = 2,   // MAC Short Address low Byte for Frame Filter 2
            MAFSA2L2 = 4,   // MAC Short Address low Byte for Frame Filter 2
            MAFSA2L3 = 8,   // MAC Short Address low Byte for Frame Filter 2
            MAFSA2L4 = 16,  // MAC Short Address low Byte for Frame Filter 2
            MAFSA2L5 = 32,  // MAC Short Address low Byte for Frame Filter 2
            MAFSA2L6 = 64,  // MAC Short Address low Byte for Frame Filter 2
            MAFSA2L7 = 128, // MAC Short Address low Byte for Frame Filter 2
        };
    };

    // Transceiver MAC Short Address Register for Frame Filter 2 (High Byte)
    struct MAFSA2H {
        static const uint8_t address = 0x117;
        enum bits : uint8_t {
            MAFSA2H0 = 1,   // MAC Short Address high Byte for Frame Filter 2
            MAFSA2H1 = 2,   // MAC Short Address high Byte for Frame Filter 2
            MAFSA2H2 = 4,   // MAC Short Address high Byte for Frame Filter 2
            MAFSA2H3 = 8,   // MAC Short Address high Byte for Frame Filter 2
            MAFSA2H4 = 16,  // MAC Short Address high Byte for Frame Filter 2
            MAFSA2H5 = 32,  // MAC Short Address high Byte for Frame Filter 2
            MAFSA2H6 = 64,  // MAC Short Address high Byte for Frame Filter 2
            MAFSA2H7 = 128, // MAC Short Address high Byte for Frame Filter 2
        };
    };

    // Transceiver Personal Area Network ID Register for Frame Filter 2 (Low Byte)
    struct MAFPA2L {
        static const uint8_t address = 0x118;
        enum bits : uint8_t {
            MAFPA2L0 = 1,   // MAC Personal Area Network ID low Byte for Frame Filter 2
            MAFPA2L1 = 2,   // MAC Personal Area Network ID low Byte for Frame Filter 2
            MAFPA2L2 = 4,   // MAC Personal Area Network ID low Byte for Frame Filter 2
            MAFPA2L3 = 8,   // MAC Personal Area Network ID low Byte for Frame Filter 2
            MAFPA2L4 = 16,  // MAC Personal Area Network ID low Byte for Frame Filter 2
            MAFPA2L5 = 32,  // MAC Personal Area Network ID low Byte for Frame Filter 2
            MAFPA2L6 = 64,  // MAC Personal Area Network ID low Byte for Frame Filter 2
            MAFPA2L7 = 128, // MAC Personal Area Network ID low Byte for Frame Filter 2
        };
    };

    // Transceiver Personal Area Network ID Register for Frame Filter 2 (High Byte)
    struct MAFPA2H {
        static const uint8_t address = 0x119;
        enum bits : uint8_t {
            MAFPA2H0 = 1,   // MAC Personal Area Network ID high Byte for Frame Filter 2
            MAFPA2H1 = 2,   // MAC Personal Area Network ID high Byte for Frame Filter 2
            MAFPA2H2 = 4,   // MAC Personal Area Network ID high Byte for Frame Filter 2
            MAFPA2H3 = 8,   // MAC Personal Area Network ID high Byte for Frame Filter 2
            MAFPA2H4 = 16,  // MAC Personal Area Network ID high Byte for Frame Filter 2
            MAFPA2H5 = 32,  // MAC Personal Area Network ID high Byte for Frame Filter 2
            MAFPA2H6 = 64,  // MAC Personal Area Network ID high Byte for Frame Filter 2
            MAFPA2H7 = 128, // MAC Personal Area Network ID high Byte for Frame Filter 2
        };
    };

    // Transceiver MAC Short Address Register for Frame Filter 3 (Low Byte)
    struct MAFSA3L {
        static const uint8_t address = 0x11a;
        enum bits : uint8_t {
            MAFSA3L0 = 1,   // MAC Short Address low Byte for Frame Filter 3
            MAFSA3L1 = 2,   // MAC Short Address low Byte for Frame Filter 3
            MAFSA3L2 = 4,   // MAC Short Address low Byte for Frame Filter 3
            MAFSA3L3 = 8,   // MAC Short Address low Byte for Frame Filter 3
            MAFSA3L4 = 16,  // MAC Short Address low Byte for Frame Filter 3
            MAFSA3L5 = 32,  // MAC Short Address low Byte for Frame Filter 3
            MAFSA3L6 = 64,  // MAC Short Address low Byte for Frame Filter 3
            MAFSA3L7 = 128, // MAC Short Address low Byte for Frame Filter 3
        };
    };

    // Transceiver MAC Short Address Register for Frame Filter 3 (High Byte)
    struct MAFSA3H {
        static const uint8_t address = 0x11b;
        enum bits : uint8_t {
            MAFSA3H0 = 1,   // MAC Short Address high Byte for Frame Filter 3
            MAFSA3H1 = 2,   // MAC Short Address high Byte for Frame Filter 3
            MAFSA3H2 = 4,   // MAC Short Address high Byte for Frame Filter 3
            MAFSA3H3 = 8,   // MAC Short Address high Byte for Frame Filter 3
            MAFSA3H4 = 16,  // MAC Short Address high Byte for Frame Filter 3
            MAFSA3H5 = 32,  // MAC Short Address high Byte for Frame Filter 3
            MAFSA3H6 = 64,  // MAC Short Address high Byte for Frame Filter 3
            MAFSA3H7 = 128, // MAC Short Address high Byte for Frame Filter 3
        };
    };

    // Transceiver Personal Area Network ID Register for Frame Filter 3 (Low Byte)
    struct MAFPA3L {
        static const uint8_t address = 0x11c;
        enum bits : uint8_t {
            MAFPA3L0 = 1,   // MAC Personal Area Network ID low Byte for Frame Filter 3
            MAFPA3L1 = 2,   // MAC Personal Area Network ID low Byte for Frame Filter 3
            MAFPA3L2 = 4,   // MAC Personal Area Network ID low Byte for Frame Filter 3
            MAFPA3L3 = 8,   // MAC Personal Area Network ID low Byte for Frame Filter 3
            MAFPA3L4 = 16,  // MAC Personal Area Network ID low Byte for Frame Filter 3
            MAFPA3L5 = 32,  // MAC Personal Area Network ID low Byte for Frame Filter 3
            MAFPA3L6 = 64,  // MAC Personal Area Network ID low Byte for Frame Filter 3
            MAFPA3L7 = 128, // MAC Personal Area Network ID low Byte for Frame Filter 3
        };
    };

    // Transceiver Personal Area Network ID Register for Frame Filter 3 (High Byte)
    struct MAFPA3H {
        static const uint8_t address = 0x11d;
        enum bits : uint8_t {
            MAFPA3H0 = 1,   // MAC Personal Area Network ID high Byte for Frame Filter 3
            MAFPA3H1 = 2,   // MAC Personal Area Network ID high Byte for Frame Filter 3
            MAFPA3H2 = 4,   // MAC Personal Area Network ID high Byte for Frame Filter 3
            MAFPA3H3 = 8,   // MAC Personal Area Network ID high Byte for Frame Filter 3
            MAFPA3H4 = 16,  // MAC Personal Area Network ID high Byte for Frame Filter 3
            MAFPA3H5 = 32,  // MAC Personal Area Network ID high Byte for Frame Filter 3
            MAFPA3H6 = 64,  // MAC Personal Area Network ID high Byte for Frame Filter 3
            MAFPA3H7 = 128, // MAC Personal Area Network ID high Byte for Frame Filter 3
        };
    };

    // Timer/Counter5 Control Register A
    struct TCCR5A {
        static const uint8_t address = 0x120;
        enum bits : uint8_t {
            WGM50  = 1,   // Waveform Generation Mode
            WGM51  = 2,   // Waveform Generation Mode
            COM5C0 = 4,   // Compare Output Mode for Channel C
            COM5C1 = 8,   // Compare Output Mode for Channel C
            COM5B0 = 16,  // Compare Output Mode for Channel B
            COM5B1 = 32,  // Compare Output Mode for Channel B
            COM5A0 = 64,  // Compare Output Mode for Channel A
            COM5A1 = 128, // Compare Output Mode for Channel A
        };
    };

    // Timer/Counter5 Control Register B
    struct TCCR5B {
        static const uint8_t address = 0x121;
        enum bits : uint8_t {
            CS50  = 1,   // Clock Select
            CS51  = 2,   // Clock Select
            CS52  = 4,   // Clock Select
            WGM50 = 8,   // Waveform Generation Mode
            WGM51 = 16,  // Waveform Generation Mode
            Res   = 32,  // Reserved Bit
            ICES5 = 64,  // Input Capture 5 Edge Select
            ICNC5 = 128, // Input Capture 5 Noise Canceller
        };
    };

    // Timer/Counter5 Control Register C
    struct TCCR5C {
        static const uint8_t address = 0x122;
        enum bits : uint8_t {
            FOC5C = 32,  // Force Output Compare for Channel C
            FOC5B = 64,  // Force Output Compare for Channel B
            FOC5A = 128, // Force Output Compare for Channel A
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

    // Timer/Counter5 Output Compare Register C  Bytes
    struct OCR5C {
        static const uint16_t address = 0x12c;
    };

    // Low Leakage Voltage Regulator Control Register
    struct LLCR {
        static const uint8_t address = 0x12f;
        enum bits : uint8_t {
            LLENCAL = 1,   // Enable Automatic Calibration
            LLSHORT = 2,   // Short Lower Calibration Circuit
            LLTCO   = 4,   // Temperature Coefficient of Current Source
            LLCAL   = 8,   // Calibration Active
            LLCOMP  = 16,  // Comparator Output
            LLDONE  = 32,  // Calibration Done
            Res0    = 64,  // Reserved Bit
            Res1    = 128, // Reserved Bit
        };
    };

    // Low Leakage Voltage Regulator Data Register (Low-Byte)
    struct LLDRL {
        static const uint8_t address = 0x130;
        enum bits : uint8_t {
            LLDRL0 = 1, // Low-Byte Data Register Bits
            LLDRL1 = 2, // Low-Byte Data Register Bits
            LLDRL2 = 4, // Low-Byte Data Register Bits
            LLDRL3 = 8, // Low-Byte Data Register Bits
        };
    };

    // Low Leakage Voltage Regulator Data Register (High-Byte)
    struct LLDRH {
        static const uint8_t address = 0x131;
        enum bits : uint8_t {
            LLDRH0 = 1,  // High-Byte Data Register Bits
            LLDRH1 = 2,  // High-Byte Data Register Bits
            LLDRH2 = 4,  // High-Byte Data Register Bits
            LLDRH3 = 8,  // High-Byte Data Register Bits
            LLDRH4 = 16, // High-Byte Data Register Bits
        };
    };

    // Data Retention Configuration Register #3
    struct DRTRAM3 {
        static const uint8_t address = 0x132;
        enum bits : uint8_t {
            ENDRT   = 16, // Enable SRAM Data Retention
            DRTSWOK = 32, // DRT Switch OK
        };
    };

    // Data Retention Configuration Register #2
    struct DRTRAM2 {
        static const uint8_t address = 0x133;
        enum bits : uint8_t {
            ENDRT   = 16, // Enable SRAM Data Retention
            DRTSWOK = 32, // DRT Switch OK
            Res     = 64, // Reserved Bit
        };
    };

    // Data Retention Configuration Register #1
    struct DRTRAM1 {
        static const uint8_t address = 0x134;
        enum bits : uint8_t {
            ENDRT   = 16, // Enable SRAM Data Retention
            DRTSWOK = 32, // DRT Switch OK
        };
    };

    // Data Retention Configuration Register #0
    struct DRTRAM0 {
        static const uint8_t address = 0x135;
        enum bits : uint8_t {
            ENDRT   = 16, // Enable SRAM Data Retention
            DRTSWOK = 32, // DRT Switch OK
        };
    };

    // Port Driver Strength Register 0
    struct DPDS0 {
        static const uint8_t address = 0x136;
        enum bits : uint8_t {
            PBDRV0 = 1,   // Driver Strength Port B
            PBDRV1 = 2,   // Driver Strength Port B
            PDDRV0 = 4,   // Driver Strength Port D
            PDDRV1 = 8,   // Driver Strength Port D
            PEDRV0 = 16,  // Driver Strength Port E
            PEDRV1 = 32,  // Driver Strength Port E
            PFDRV0 = 64,  // Driver Strength Port F
            PFDRV1 = 128, // Driver Strength Port F
        };
    };

    // Port Driver Strength Register 1
    struct DPDS1 {
        static const uint8_t address = 0x137;
        enum bits : uint8_t {
            PGDRV0 = 1, // Driver Strength Port G
            PGDRV1 = 2, // Driver Strength Port G
        };
    };

    // Power Amplifier Ramp up/down Control Register
    struct PARCR {
        static const uint8_t address = 0x138;
        enum bits : uint8_t {
            PARUFI = 1,   // Power Amplifier Ramp Up Frequency Inversion
            PARDFI = 2,   // Power Amplifier Ramp Down Frequency Inversion
            PALTU0 = 4,   // ext. PA Ramp Up Lead Time
            PALTU1 = 8,   // ext. PA Ramp Up Lead Time
            PALTU2 = 16,  // ext. PA Ramp Up Lead Time
            PALTD0 = 32,  // ext. PA Ramp Down Lead Time
            PALTD1 = 64,  // ext. PA Ramp Down Lead Time
            PALTD2 = 128, // ext. PA Ramp Down Lead Time
        };
    };

    // Transceiver Pin Register
    struct TRXPR {
        static const uint8_t address = 0x139;
        enum bits : uint8_t {
            TRXRST = 1, // Force Transceiver Reset
            SLPTR  = 2, // Multi-purpose Transceiver Control Bit
        };
    };

    // AES Control Register
    struct AES_CTRL {
        static const uint8_t address = 0x13c;
        enum bits : uint8_t {
            AES_IM      = 4,   // AES Interrupt Enable
            AES_DIR     = 8,   // Set AES Operation Direction
            AES_MODE    = 32,  // Set AES Operation Mode
            AES_REQUEST = 128, // Request AES Operation.
        };
    };

    // AES Status Register
    struct AES_STATUS {
        static const uint8_t address = 0x13d;
        enum bits : uint8_t {
            AES_DONE = 1,   // AES Operation Finished with Success
            AES_ER   = 128, // AES Operation Finished with Error
        };
    };

    // AES Plain and Cipher Text Buffer Register
    struct AES_STATE {
        static const uint8_t address = 0x13e;
        enum bits : uint8_t {
            AES_STATE0 = 1,   // AES Plain and Cipher Text Buffer
            AES_STATE1 = 2,   // AES Plain and Cipher Text Buffer
            AES_STATE2 = 4,   // AES Plain and Cipher Text Buffer
            AES_STATE3 = 8,   // AES Plain and Cipher Text Buffer
            AES_STATE4 = 16,  // AES Plain and Cipher Text Buffer
            AES_STATE5 = 32,  // AES Plain and Cipher Text Buffer
            AES_STATE6 = 64,  // AES Plain and Cipher Text Buffer
            AES_STATE7 = 128, // AES Plain and Cipher Text Buffer
        };
    };

    // AES Encryption and Decryption Key Buffer Register
    struct AES_KEY {
        static const uint8_t address = 0x13f;
        enum bits : uint8_t {
            AES_KEY0 = 1,   // AES Encryption/Decryption Key Buffer
            AES_KEY1 = 2,   // AES Encryption/Decryption Key Buffer
            AES_KEY2 = 4,   // AES Encryption/Decryption Key Buffer
            AES_KEY3 = 8,   // AES Encryption/Decryption Key Buffer
            AES_KEY4 = 16,  // AES Encryption/Decryption Key Buffer
            AES_KEY5 = 32,  // AES Encryption/Decryption Key Buffer
            AES_KEY6 = 64,  // AES Encryption/Decryption Key Buffer
            AES_KEY7 = 128, // AES Encryption/Decryption Key Buffer
        };
    };

    // Transceiver Status Register
    struct TRX_STATUS {
        static const uint8_t address = 0x141;
        enum bits : uint8_t {
            TRX_STATUS0 = 1,   // Transceiver Main Status
            TRX_STATUS1 = 2,   // Transceiver Main Status
            TRX_STATUS2 = 4,   // Transceiver Main Status
            TRX_STATUS3 = 8,   // Transceiver Main Status
            TRX_STATUS4 = 16,  // Transceiver Main Status
            TST_STATUS  = 32,  // Test mode status
            CCA_STATUS  = 64,  // CCA Status Result
            CCA_DONE    = 128, // CCA Algorithm Status
        };
    };

    // Transceiver State Control Register
    struct TRX_STATE {
        static const uint8_t address = 0x142;
        enum bits : uint8_t {
            TRX_CMD0     = 1,   // State Control Command
            TRX_CMD1     = 2,   // State Control Command
            TRX_CMD2     = 4,   // State Control Command
            TRX_CMD3     = 8,   // State Control Command
            TRX_CMD4     = 16,  // State Control Command
            TRAC_STATUS0 = 32,  // Transaction Status
            TRAC_STATUS1 = 64,  // Transaction Status
            TRAC_STATUS2 = 128, // Transaction Status
        };
    };

    // Reserved
    struct TRX_CTRL_0 {
        static const uint8_t address = 0x143;
        enum bits : uint8_t {
            PMU_IF_INV = 16,  // PMU IF Inverse
            PMU_START  = 32,  // Start of Phase Measurement Unit
            PMU_EN     = 64,  // Enable Phase Measurement Unit
            Res7       = 128, // Reserved
        };
    };

    // Transceiver Control Register 1
    struct TRX_CTRL_1 {
        static const uint8_t address = 0x144;
        enum bits : uint8_t {
            PLL_TX_FLT     = 16,  // Enable PLL TX filter
            TX_AUTO_CRC_ON = 32,  // Enable Automatic CRC Calculation
            IRQ_2_EXT_EN   = 64,  // Connect Frame Start IRQ to TC1
            PA_EXT_EN      = 128, // External PA support enable
        };
    };

    // Transceiver Transmit Power Control Register
    struct PHY_TX_PWR {
        static const uint8_t address = 0x145;
        enum bits : uint8_t {
            TX_PWR0 = 1, // Transmit Power Setting
            TX_PWR1 = 2, // Transmit Power Setting
            TX_PWR2 = 4, // Transmit Power Setting
            TX_PWR3 = 8, // Transmit Power Setting
        };
    };

    // Receiver Signal Strength Indicator Register
    struct PHY_RSSI {
        static const uint8_t address = 0x146;
        enum bits : uint8_t {
            RSSI0        = 1,   // Receiver Signal Strength Indicator
            RSSI1        = 2,   // Receiver Signal Strength Indicator
            RSSI2        = 4,   // Receiver Signal Strength Indicator
            RSSI3        = 8,   // Receiver Signal Strength Indicator
            RSSI4        = 16,  // Receiver Signal Strength Indicator
            RND_VALUE0   = 32,  // Random Value
            RND_VALUE1   = 64,  // Random Value
            RX_CRC_VALID = 128, // Received Frame CRC Status
        };
    };

    // Transceiver Energy Detection Level Register
    struct PHY_ED_LEVEL {
        static const uint8_t address = 0x147;
        enum bits : uint8_t {
            ED_LEVEL0 = 1,   // Energy Detection Level
            ED_LEVEL1 = 2,   // Energy Detection Level
            ED_LEVEL2 = 4,   // Energy Detection Level
            ED_LEVEL3 = 8,   // Energy Detection Level
            ED_LEVEL4 = 16,  // Energy Detection Level
            ED_LEVEL5 = 32,  // Energy Detection Level
            ED_LEVEL6 = 64,  // Energy Detection Level
            ED_LEVEL7 = 128, // Energy Detection Level
        };
    };

    // Transceiver Clear Channel Assessment (CCA) Control Register
    struct PHY_CC_CCA {
        static const uint8_t address = 0x148;
        enum bits : uint8_t {
            CHANNEL0    = 1,   // RX/TX Channel Selection
            CHANNEL1    = 2,   // RX/TX Channel Selection
            CHANNEL2    = 4,   // RX/TX Channel Selection
            CHANNEL3    = 8,   // RX/TX Channel Selection
            CHANNEL4    = 16,  // RX/TX Channel Selection
            CCA_MODE0   = 32,  // Select CCA Measurement Mode
            CCA_MODE1   = 64,  // Select CCA Measurement Mode
            CCA_REQUEST = 128, // Manual CCA Measurement Request
        };
    };

    // Transceiver CCA Threshold Setting Register
    struct CCA_THRES {
        static const uint8_t address = 0x149;
        enum bits : uint8_t {
            CCA_ED_THRES0 = 1,   // ED Threshold Level for CCA Measurement
            CCA_ED_THRES1 = 2,   // ED Threshold Level for CCA Measurement
            CCA_ED_THRES2 = 4,   // ED Threshold Level for CCA Measurement
            CCA_ED_THRES3 = 8,   // ED Threshold Level for CCA Measurement
            CCA_CS_THRES0 = 16,  // CS Threshold Level for CCA Measurement
            CCA_CS_THRES1 = 32,  // CS Threshold Level for CCA Measurement
            CCA_CS_THRES2 = 64,  // CS Threshold Level for CCA Measurement
            CCA_CS_THRES3 = 128, // CS Threshold Level for CCA Measurement
        };
    };

    // Transceiver Receive Control Register
    struct RX_CTRL {
        static const uint8_t address = 0x14a;
        enum bits : uint8_t {
            PDT_THRES0 = 1, // Receiver Sensitivity Control
            PDT_THRES1 = 2, // Receiver Sensitivity Control
            PDT_THRES2 = 4, // Receiver Sensitivity Control
            PDT_THRES3 = 8, // Receiver Sensitivity Control
        };
    };

    // Start of Frame Delimiter Value Register
    struct SFD_VALUE {
        static const uint8_t address = 0x14b;
        enum bits : uint8_t {
            SFD_VALUE0 = 1,   // Start of Frame Delimiter Value
            SFD_VALUE1 = 2,   // Start of Frame Delimiter Value
            SFD_VALUE2 = 4,   // Start of Frame Delimiter Value
            SFD_VALUE3 = 8,   // Start of Frame Delimiter Value
            SFD_VALUE4 = 16,  // Start of Frame Delimiter Value
            SFD_VALUE5 = 32,  // Start of Frame Delimiter Value
            SFD_VALUE6 = 64,  // Start of Frame Delimiter Value
            SFD_VALUE7 = 128, // Start of Frame Delimiter Value
        };
    };

    // Transceiver Control Register 2
    struct TRX_CTRL_2 {
        static const uint8_t address = 0x14c;
        enum bits : uint8_t {
            OQPSK_DATA_RATE0 = 1,   // Data Rate Selection
            OQPSK_DATA_RATE1 = 2,   // Data Rate Selection
            RX_SAFE_MODE     = 128, // RX Safe Mode
        };
    };

    // Antenna Diversity Control Register
    struct ANT_DIV {
        static const uint8_t address = 0x14d;
        enum bits : uint8_t {
            ANT_CTRL0     = 1,   // Static Antenna Diversity Switch Control
            ANT_CTRL1     = 2,   // Static Antenna Diversity Switch Control
            ANT_EXT_SW_EN = 4,   // Enable External Antenna Switch Control
            ANT_DIV_EN    = 8,   // Enable Antenna Diversity
            ANT_SEL       = 128, // Antenna Diversity Antenna Status
        };
    };

    // Transceiver Interrupt Enable Register
    struct IRQ_MASK {
        static const uint8_t address = 0x14e;
        enum bits : uint8_t {
            PLL_LOCK_EN    = 1,   // PLL Lock Interrupt Enable
            PLL_UNLOCK_EN  = 2,   // PLL Unlock Interrupt Enable
            RX_START_EN    = 4,   // RX_START Interrupt Enable
            RX_END_EN      = 8,   // RX_END Interrupt Enable
            CCA_ED_DONE_EN = 16,  // End of ED Measurement Interrupt Enable
            AMI_EN         = 32,  // Address Match Interrupt Enable
            TX_END_EN      = 64,  // TX_END Interrupt Enable
            AWAKE_EN       = 128, // Awake Interrupt Enable
        };
    };

    // Transceiver Interrupt Status Register
    struct IRQ_STATUS {
        static const uint8_t address = 0x14f;
        enum bits : uint8_t {
            PLL_LOCK    = 1,   // PLL Lock Interrupt Status
            PLL_UNLOCK  = 2,   // PLL Unlock Interrupt Status
            RX_START    = 4,   // RX_START Interrupt Status
            RX_END      = 8,   // RX_END Interrupt Status
            CCA_ED_DONE = 16,  // End of ED Measurement Interrupt Status
            AMI         = 32,  // Address Match Interrupt Status
            TX_END      = 64,  // TX_END Interrupt Status
            AWAKE       = 128, // Awake Interrupt Status
        };
    };

    // Voltage Regulator Control and Status Register
    struct VREG_CTRL {
        static const uint8_t address = 0x150;
        enum bits : uint8_t {
            DVDD_OK   = 4,   // DVDD Supply Voltage Valid
            DVREG_EXT = 8,   // Use External DVDD Regulator
            AVDD_OK   = 64,  // AVDD Supply Voltage Valid
            AVREG_EXT = 128, // Use External AVDD Regulator
        };
    };

    // Battery Monitor Control and Status Register
    struct BATMON {
        static const uint8_t address = 0x151;
        enum bits : uint8_t {
            BATMON_VTH0 = 1,   // Battery Monitor Threshold Voltage
            BATMON_VTH1 = 2,   // Battery Monitor Threshold Voltage
            BATMON_VTH2 = 4,   // Battery Monitor Threshold Voltage
            BATMON_VTH3 = 8,   // Battery Monitor Threshold Voltage
            BATMON_HR   = 16,  // Battery Monitor Voltage Range
            BATMON_OK   = 32,  // Battery Monitor Status
            BAT_LOW_EN  = 64,  // Battery Monitor Interrupt Enable
            BAT_LOW     = 128, // Battery Monitor Interrupt Status
        };
    };

    // Crystal Oscillator Control Register
    struct XOSC_CTRL {
        static const uint8_t address = 0x152;
        enum bits : uint8_t {
            XTAL_TRIM0 = 1,   // Crystal Oscillator Load Capacitance Trimming
            XTAL_TRIM1 = 2,   // Crystal Oscillator Load Capacitance Trimming
            XTAL_TRIM2 = 4,   // Crystal Oscillator Load Capacitance Trimming
            XTAL_TRIM3 = 8,   // Crystal Oscillator Load Capacitance Trimming
            XTAL_MODE0 = 16,  // Crystal Oscillator Operating Mode
            XTAL_MODE1 = 32,  // Crystal Oscillator Operating Mode
            XTAL_MODE2 = 64,  // Crystal Oscillator Operating Mode
            XTAL_MODE3 = 128, // Crystal Oscillator Operating Mode
        };
    };

    // Channel Control Register 0
    struct CC_CTRL_0 {
        static const uint8_t address = 0x153;
        enum bits : uint8_t {
            CC_NUMBER0 = 1,   // Channel Number
            CC_NUMBER1 = 2,   // Channel Number
            CC_NUMBER2 = 4,   // Channel Number
            CC_NUMBER3 = 8,   // Channel Number
            CC_NUMBER4 = 16,  // Channel Number
            CC_NUMBER5 = 32,  // Channel Number
            CC_NUMBER6 = 64,  // Channel Number
            CC_NUMBER7 = 128, // Channel Number
        };
    };

    // Channel Control Register 1
    struct CC_CTRL_1 {
        static const uint8_t address = 0x154;
        enum bits : uint8_t {
            CC_BAND0 = 1, // Channel Band
            CC_BAND1 = 2, // Channel Band
            CC_BAND2 = 4, // Channel Band
            CC_BAND3 = 8, // Channel Band
        };
    };

    // Transceiver Receiver Sensitivity Control Register
    struct RX_SYN {
        static const uint8_t address = 0x155;
        enum bits : uint8_t {
            RX_PDT_LEVEL0 = 1,   // Reduce Receiver Sensitivity
            RX_PDT_LEVEL1 = 2,   // Reduce Receiver Sensitivity
            RX_PDT_LEVEL2 = 4,   // Reduce Receiver Sensitivity
            RX_PDT_LEVEL3 = 8,   // Reduce Receiver Sensitivity
            RX_OVERRIDE   = 64,  // Receiver Override Function
            RX_PDT_DIS    = 128, // Prevent Frame Reception
        };
    };

    // Transceiver Reduced Power Consumption Control
    struct TRX_RPC {
        static const uint8_t address = 0x156;
        enum bits : uint8_t {
            XAH_RPC_EN   = 1,   // Smart Receiving in Extended Operating Modes Enable
            IPAN_RPC_EN  = 2,   // Smart Receiving Mode IPAN Handling Enable
            Res0         = 4,   // Reserved
            PLL_RPC_EN   = 8,   // PLL Smart Receiving Mode Enable
            PDT_RPC_EN   = 16,  // Smart Receiving Mode Reduced Sensitivity Enable
            RX_RPC_EN    = 32,  // Reciver Smart Receiving Mode Enable
            RX_RPC_CTRL0 = 64,  // Smart Receiving Mode Timing
            RX_RPC_CTRL1 = 128, // Smart Receiving Mode Timing
        };
    };

    // Transceiver Acknowledgment Frame Control Register 1
    struct XAH_CTRL_1 {
        static const uint8_t address = 0x157;
        enum bits : uint8_t {
            AACK_PROM_MODE   = 2,  // Enable Promiscuous Mode
            AACK_ACK_TIME    = 4,  // Reduce Acknowledgment Time
            AACK_UPLD_RES_FT = 16, // Process Reserved Frames
            AACK_FLTR_RES_FT = 32, // Filter Reserved Frames
        };
    };

    // Transceiver Filter Tuning Control Register
    struct FTN_CTRL {
        static const uint8_t address = 0x158;
        enum bits : uint8_t {
            FTN_START = 128, // Start Calibration Loop of Filter Tuning Network
        };
    };

    // Transceiver Center Frequency Calibration Control Register
    struct PLL_CF {
        static const uint8_t address = 0x15a;
        enum bits : uint8_t {
            PLL_CF_START = 128, // Start Center Frequency Calibration
        };
    };

    // Transceiver Delay Cell Calibration Control Register
    struct PLL_DCU {
        static const uint8_t address = 0x15b;
        enum bits : uint8_t {
            PLL_DCU_START = 128, // Start Delay Cell Calibration
        };
    };

    // Device Identification Register (Part Number)
    struct PART_NUM {
        static const uint8_t address = 0x15c;
        enum bits : uint8_t {
            PART_NUM0 = 1,   // Part Number
            PART_NUM1 = 2,   // Part Number
            PART_NUM2 = 4,   // Part Number
            PART_NUM3 = 8,   // Part Number
            PART_NUM4 = 16,  // Part Number
            PART_NUM5 = 32,  // Part Number
            PART_NUM6 = 64,  // Part Number
            PART_NUM7 = 128, // Part Number
        };
    };

    // Device Identification Register (Version Number)
    struct VERSION_NUM {
        static const uint8_t address = 0x15d;
        enum bits : uint8_t {
            VERSION_NUM0 = 1,   // Version Number
            VERSION_NUM1 = 2,   // Version Number
            VERSION_NUM2 = 4,   // Version Number
            VERSION_NUM3 = 8,   // Version Number
            VERSION_NUM4 = 16,  // Version Number
            VERSION_NUM5 = 32,  // Version Number
            VERSION_NUM6 = 64,  // Version Number
            VERSION_NUM7 = 128, // Version Number
        };
    };

    // Device Identification Register (Manufacture ID Low Byte)
    struct MAN_ID_0 {
        static const uint8_t address = 0x15e;
        enum bits : uint8_t {
            MAN_ID_00 = 1,   // Manufacturer ID (Low Byte)
            MAN_ID_01 = 2,   // Manufacturer ID (Low Byte)
            MAN_ID_02 = 4,   // Manufacturer ID (Low Byte)
            MAN_ID_03 = 8,   // Manufacturer ID (Low Byte)
            MAN_ID_04 = 16,  // Manufacturer ID (Low Byte)
            MAN_ID_05 = 32,  // Manufacturer ID (Low Byte)
            MAN_ID_06 = 64,  // Manufacturer ID (Low Byte)
            MAN_ID_07 = 128, // Manufacturer ID (Low Byte)
        };
    };

    // Device Identification Register (Manufacture ID High Byte)
    struct MAN_ID_1 {
        static const uint8_t address = 0x15f;
        enum bits : uint8_t {
            MAN_ID_0 = 1,   // Manufacturer ID (High Byte)
            MAN_ID_1 = 2,   // Manufacturer ID (High Byte)
            MAN_ID_2 = 4,   // Manufacturer ID (High Byte)
            MAN_ID_3 = 8,   // Manufacturer ID (High Byte)
            MAN_ID_4 = 16,  // Manufacturer ID (High Byte)
            MAN_ID_5 = 32,  // Manufacturer ID (High Byte)
            MAN_ID_6 = 64,  // Manufacturer ID (High Byte)
            MAN_ID_7 = 128, // Manufacturer ID (High Byte)
        };
    };

    // Transceiver MAC Short Address Register (Low Byte)
    struct SHORT_ADDR_0 {
        static const uint8_t address = 0x160;
        enum bits : uint8_t {
            SHORT_ADDR_00 = 1,   // MAC Short Address
            SHORT_ADDR_01 = 2,   // MAC Short Address
            SHORT_ADDR_02 = 4,   // MAC Short Address
            SHORT_ADDR_03 = 8,   // MAC Short Address
            SHORT_ADDR_04 = 16,  // MAC Short Address
            SHORT_ADDR_05 = 32,  // MAC Short Address
            SHORT_ADDR_06 = 64,  // MAC Short Address
            SHORT_ADDR_07 = 128, // MAC Short Address
        };
    };

    // Transceiver MAC Short Address Register (High Byte)
    struct SHORT_ADDR_1 {
        static const uint8_t address = 0x161;
        enum bits : uint8_t {
            SHORT_ADDR_0 = 1,   // MAC Short Address
            SHORT_ADDR_1 = 2,   // MAC Short Address
            SHORT_ADDR_2 = 4,   // MAC Short Address
            SHORT_ADDR_3 = 8,   // MAC Short Address
            SHORT_ADDR_4 = 16,  // MAC Short Address
            SHORT_ADDR_5 = 32,  // MAC Short Address
            SHORT_ADDR_6 = 64,  // MAC Short Address
            SHORT_ADDR_7 = 128, // MAC Short Address
        };
    };

    // Transceiver Personal Area Network ID Register (Low Byte)
    struct PAN_ID_0 {
        static const uint8_t address = 0x162;
        enum bits : uint8_t {
            PAN_ID_00 = 1,   // MAC Personal Area Network ID
            PAN_ID_01 = 2,   // MAC Personal Area Network ID
            PAN_ID_02 = 4,   // MAC Personal Area Network ID
            PAN_ID_03 = 8,   // MAC Personal Area Network ID
            PAN_ID_04 = 16,  // MAC Personal Area Network ID
            PAN_ID_05 = 32,  // MAC Personal Area Network ID
            PAN_ID_06 = 64,  // MAC Personal Area Network ID
            PAN_ID_07 = 128, // MAC Personal Area Network ID
        };
    };

    // Transceiver Personal Area Network ID Register (High Byte)
    struct PAN_ID_1 {
        static const uint8_t address = 0x163;
        enum bits : uint8_t {
            PAN_ID_0 = 1,   // MAC Personal Area Network ID
            PAN_ID_1 = 2,   // MAC Personal Area Network ID
            PAN_ID_2 = 4,   // MAC Personal Area Network ID
            PAN_ID_3 = 8,   // MAC Personal Area Network ID
            PAN_ID_4 = 16,  // MAC Personal Area Network ID
            PAN_ID_5 = 32,  // MAC Personal Area Network ID
            PAN_ID_6 = 64,  // MAC Personal Area Network ID
            PAN_ID_7 = 128, // MAC Personal Area Network ID
        };
    };

    // Transceiver MAC IEEE Address Register 0
    struct IEEE_ADDR_0 {
        static const uint8_t address = 0x164;
        enum bits : uint8_t {
            IEEE_ADDR_00 = 1,   // MAC IEEE Address
            IEEE_ADDR_01 = 2,   // MAC IEEE Address
            IEEE_ADDR_02 = 4,   // MAC IEEE Address
            IEEE_ADDR_03 = 8,   // MAC IEEE Address
            IEEE_ADDR_04 = 16,  // MAC IEEE Address
            IEEE_ADDR_05 = 32,  // MAC IEEE Address
            IEEE_ADDR_06 = 64,  // MAC IEEE Address
            IEEE_ADDR_07 = 128, // MAC IEEE Address
        };
    };

    // Transceiver MAC IEEE Address Register 1
    struct IEEE_ADDR_1 {
        static const uint8_t address = 0x165;
        enum bits : uint8_t {
            IEEE_ADDR_0 = 1,   // MAC IEEE Address
            IEEE_ADDR_1 = 2,   // MAC IEEE Address
            IEEE_ADDR_2 = 4,   // MAC IEEE Address
            IEEE_ADDR_3 = 8,   // MAC IEEE Address
            IEEE_ADDR_4 = 16,  // MAC IEEE Address
            IEEE_ADDR_5 = 32,  // MAC IEEE Address
            IEEE_ADDR_6 = 64,  // MAC IEEE Address
            IEEE_ADDR_7 = 128, // MAC IEEE Address
        };
    };

    // Transceiver MAC IEEE Address Register 2
    struct IEEE_ADDR_2 {
        static const uint8_t address = 0x166;
        enum bits : uint8_t {
            IEEE_ADDR_0 = 1,   // MAC IEEE Address
            IEEE_ADDR_1 = 2,   // MAC IEEE Address
            IEEE_ADDR_2 = 4,   // MAC IEEE Address
            IEEE_ADDR_3 = 8,   // MAC IEEE Address
            IEEE_ADDR_4 = 16,  // MAC IEEE Address
            IEEE_ADDR_5 = 32,  // MAC IEEE Address
            IEEE_ADDR_6 = 64,  // MAC IEEE Address
            IEEE_ADDR_7 = 128, // MAC IEEE Address
        };
    };

    // Transceiver MAC IEEE Address Register 3
    struct IEEE_ADDR_3 {
        static const uint8_t address = 0x167;
        enum bits : uint8_t {
            IEEE_ADDR_0 = 1,   // MAC IEEE Address
            IEEE_ADDR_1 = 2,   // MAC IEEE Address
            IEEE_ADDR_2 = 4,   // MAC IEEE Address
            IEEE_ADDR_3 = 8,   // MAC IEEE Address
            IEEE_ADDR_4 = 16,  // MAC IEEE Address
            IEEE_ADDR_5 = 32,  // MAC IEEE Address
            IEEE_ADDR_6 = 64,  // MAC IEEE Address
            IEEE_ADDR_7 = 128, // MAC IEEE Address
        };
    };

    // Transceiver MAC IEEE Address Register 4
    struct IEEE_ADDR_4 {
        static const uint8_t address = 0x168;
        enum bits : uint8_t {
            IEEE_ADDR_0 = 1,   // MAC IEEE Address
            IEEE_ADDR_1 = 2,   // MAC IEEE Address
            IEEE_ADDR_2 = 4,   // MAC IEEE Address
            IEEE_ADDR_3 = 8,   // MAC IEEE Address
            IEEE_ADDR_4 = 16,  // MAC IEEE Address
            IEEE_ADDR_5 = 32,  // MAC IEEE Address
            IEEE_ADDR_6 = 64,  // MAC IEEE Address
            IEEE_ADDR_7 = 128, // MAC IEEE Address
        };
    };

    // Transceiver MAC IEEE Address Register 5
    struct IEEE_ADDR_5 {
        static const uint8_t address = 0x169;
        enum bits : uint8_t {
            IEEE_ADDR_0 = 1,   // MAC IEEE Address
            IEEE_ADDR_1 = 2,   // MAC IEEE Address
            IEEE_ADDR_2 = 4,   // MAC IEEE Address
            IEEE_ADDR_3 = 8,   // MAC IEEE Address
            IEEE_ADDR_4 = 16,  // MAC IEEE Address
            IEEE_ADDR_5 = 32,  // MAC IEEE Address
            IEEE_ADDR_6 = 64,  // MAC IEEE Address
            IEEE_ADDR_7 = 128, // MAC IEEE Address
        };
    };

    // Transceiver MAC IEEE Address Register 6
    struct IEEE_ADDR_6 {
        static const uint8_t address = 0x16a;
        enum bits : uint8_t {
            IEEE_ADDR_0 = 1,   // MAC IEEE Address
            IEEE_ADDR_1 = 2,   // MAC IEEE Address
            IEEE_ADDR_2 = 4,   // MAC IEEE Address
            IEEE_ADDR_3 = 8,   // MAC IEEE Address
            IEEE_ADDR_4 = 16,  // MAC IEEE Address
            IEEE_ADDR_5 = 32,  // MAC IEEE Address
            IEEE_ADDR_6 = 64,  // MAC IEEE Address
            IEEE_ADDR_7 = 128, // MAC IEEE Address
        };
    };

    // Transceiver MAC IEEE Address Register 7
    struct IEEE_ADDR_7 {
        static const uint8_t address = 0x16b;
        enum bits : uint8_t {
            IEEE_ADDR_0 = 1,   // MAC IEEE Address
            IEEE_ADDR_1 = 2,   // MAC IEEE Address
            IEEE_ADDR_2 = 4,   // MAC IEEE Address
            IEEE_ADDR_3 = 8,   // MAC IEEE Address
            IEEE_ADDR_4 = 16,  // MAC IEEE Address
            IEEE_ADDR_5 = 32,  // MAC IEEE Address
            IEEE_ADDR_6 = 64,  // MAC IEEE Address
            IEEE_ADDR_7 = 128, // MAC IEEE Address
        };
    };

    // Transceiver Extended Operating Mode Control Register
    struct XAH_CTRL_0 {
        static const uint8_t address = 0x16c;
        enum bits : uint8_t {
            SLOTTED_OPERATION  = 1,   // Set Slotted Acknowledgment
            MAX_CSMA_RETRIES0  = 2,   // Maximum Number of CSMA-CA Procedure Repetition Attempts
            MAX_CSMA_RETRIES1  = 4,   // Maximum Number of CSMA-CA Procedure Repetition Attempts
            MAX_CSMA_RETRIES2  = 8,   // Maximum Number of CSMA-CA Procedure Repetition Attempts
            MAX_FRAME_RETRIES0 = 16,  // Maximum Number of Frame Re-transmission Attempts
            MAX_FRAME_RETRIES1 = 32,  // Maximum Number of Frame Re-transmission Attempts
            MAX_FRAME_RETRIES2 = 64,  // Maximum Number of Frame Re-transmission Attempts
            MAX_FRAME_RETRIES3 = 128, // Maximum Number of Frame Re-transmission Attempts
        };
    };

    // Transceiver CSMA-CA Random Number Generator Seed Register
    struct CSMA_SEED_0 {
        static const uint8_t address = 0x16d;
        enum bits : uint8_t {
            CSMA_SEED_00 = 1,   // Seed Value for CSMA Random Number Generator
            CSMA_SEED_01 = 2,   // Seed Value for CSMA Random Number Generator
            CSMA_SEED_02 = 4,   // Seed Value for CSMA Random Number Generator
            CSMA_SEED_03 = 8,   // Seed Value for CSMA Random Number Generator
            CSMA_SEED_04 = 16,  // Seed Value for CSMA Random Number Generator
            CSMA_SEED_05 = 32,  // Seed Value for CSMA Random Number Generator
            CSMA_SEED_06 = 64,  // Seed Value for CSMA Random Number Generator
            CSMA_SEED_07 = 128, // Seed Value for CSMA Random Number Generator
        };
    };

    // Transceiver Acknowledgment Frame Control Register 2
    struct CSMA_SEED_1 {
        static const uint8_t address = 0x16e;
        enum bits : uint8_t {
            CSMA_SEED_10    = 1,   // Seed Value for CSMA Random Number Generator
            CSMA_SEED_11    = 2,   // Seed Value for CSMA Random Number Generator
            CSMA_SEED_12    = 4,   // Seed Value for CSMA Random Number Generator
            AACK_I_AM_COORD = 8,   // Set Personal Area Network Coordinator
            AACK_DIS_ACK    = 16,  // Disable Acknowledgment Frame Transmission
            AACK_SET_PD     = 32,  // Set Frame Pending Sub-field
            AACK_FVN_MODE0  = 64,  // Acknowledgment Frame Filter Mode
            AACK_FVN_MODE1  = 128, // Acknowledgment Frame Filter Mode
        };
    };

    // Transceiver CSMA-CA Back-off Exponent Control Register
    struct CSMA_BE {
        static const uint8_t address = 0x16f;
        enum bits : uint8_t {
            MIN_BE0 = 1,   // Minimum Back-off Exponent
            MIN_BE1 = 2,   // Minimum Back-off Exponent
            MIN_BE2 = 4,   // Minimum Back-off Exponent
            MIN_BE3 = 8,   // Minimum Back-off Exponent
            MAX_BE0 = 16,  // Maximum Back-off Exponent
            MAX_BE1 = 32,  // Maximum Back-off Exponent
            MAX_BE2 = 64,  // Maximum Back-off Exponent
            MAX_BE3 = 128, // Maximum Back-off Exponent
        };
    };

    // Transceiver Digital Test Control Register
    struct TST_CTRL_DIGI {
        static const uint8_t address = 0x176;
        enum bits : uint8_t {
            TST_CTRL_DIG0 = 1, // Digital Test Controller Register
            TST_CTRL_DIG1 = 2, // Digital Test Controller Register
            TST_CTRL_DIG2 = 4, // Digital Test Controller Register
            TST_CTRL_DIG3 = 8, // Digital Test Controller Register
        };
    };

    // Transceiver Received Frame Length Register
    struct TST_RX_LENGTH {
        static const uint8_t address = 0x17b;
        enum bits : uint8_t {
            RX_LENGTH0 = 1,   // Received Frame Length
            RX_LENGTH1 = 2,   // Received Frame Length
            RX_LENGTH2 = 4,   // Received Frame Length
            RX_LENGTH3 = 8,   // Received Frame Length
            RX_LENGTH4 = 16,  // Received Frame Length
            RX_LENGTH5 = 32,  // Received Frame Length
            RX_LENGTH6 = 64,  // Received Frame Length
            RX_LENGTH7 = 128, // Received Frame Length
        };
    };

    // Start of frame buffer
    struct TRXFBST {
        static const uint8_t address = 0x180;
    };

    // End of frame buffer
    struct TRXFBEND {
        static const uint8_t address = 0x1ff;
    };

}

#endif
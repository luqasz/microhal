#ifndef at90usb162_sfr_h
#define at90usb162_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       AT90USB162
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
        enum bits : uint8_t {
            PINC0 = 1,   // Port C Input Pins bits
            PINC1 = 2,   // Port C Input Pins bits
            PINC2 = 4,   // Port C Input Pins bits
            PINC0 = 16,  // Port C Input Pins bits
            PINC1 = 32,  // Port C Input Pins bits
            PINC2 = 64,  // Port C Input Pins bits
            PINC3 = 128, // Port C Input Pins bits
        };
    };

    // Port C Data Direction Register
    struct DDRC {
        static const uint8_t address = 0x27;
        enum bits : uint8_t {
            DDC0 = 1,   // Port C Data Direction Register bits
            DDC1 = 2,   // Port C Data Direction Register bits
            DDC2 = 4,   // Port C Data Direction Register bits
            DDC0 = 16,  // Port C Data Direction Register bits
            DDC1 = 32,  // Port C Data Direction Register bits
            DDC2 = 64,  // Port C Data Direction Register bits
            DDC3 = 128, // Port C Data Direction Register bits
        };
    };

    // Port C Data Register
    struct PORTC {
        static const uint8_t address = 0x28;
        enum bits : uint8_t {
            PORTC0 = 1,   // Port C Data Register bits
            PORTC1 = 2,   // Port C Data Register bits
            PORTC2 = 4,   // Port C Data Register bits
            PORTC0 = 16,  // Port C Data Register bits
            PORTC1 = 32,  // Port C Data Register bits
            PORTC2 = 64,  // Port C Data Register bits
            PORTC3 = 128, // Port C Data Register bits
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

    // Pin Change Interrupt Flag Register
    struct PCIFR {
        static const uint8_t address = 0x3b;
        enum bits : uint8_t {
            PCIF0 = 1, // Pin Change Interrupt Flags
            PCIF1 = 2, // Pin Change Interrupt Flags
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

    // PLL Status and Control register
    struct PLLCSR {
        static const uint8_t address = 0x49;
        enum bits : uint8_t {
            PLOCK = 1,  // PLL Lock Status Bit
            PLLE  = 2,  // PLL Enable Bit
            PLLP0 = 4,  // PLL prescaler Bits
            PLLP1 = 8,  // PLL prescaler Bits
            PLLP2 = 16, // PLL prescaler Bits
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

    // debugWire communication register
    struct DWDR {
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
            USBRF = 32, // USB reset flag
        };
    };

    // MCU Control Register
    struct MCUCR {
        static const uint8_t address = 0x55;
        enum bits : uint8_t {
            IVCE  = 1,  // Interrupt Vector Change Enable
            IVSEL = 2,  // Interrupt Vector Select
            PUD   = 16, // Pull-up disable
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

    // Watchdog Timer Clock Divider
    struct WDTCKD {
        static const uint8_t address = 0x62;
        enum bits : uint8_t {
            WCLKD0 = 1, // Watchdog Timer Clock Dividers
            WCLKD1 = 2, // Watchdog Timer Clock Dividers
            WDEWIE = 4, // Watchdog Early Warning Interrupt Enable
            WDEWIF = 8, // Watchdog Early Warning Interrupt Flag
        };
    };

    // Regulator Control Register
    struct REGCR {
        static const uint8_t address = 0x63;
        enum bits : uint8_t {
            REGDIS = 1, //
        };
    };

    // Power Reduction Register0
    struct PRR0 {
        static const uint8_t address = 0x64;
        enum bits : uint8_t {
            PRSPI  = 4,  // Power Reduction Serial Peripheral Interface
            PRTIM1 = 8,  // Power Reduction Timer/Counter1
            PRTIM0 = 32, // Power Reduction Timer/Counter0
        };
    };

    // Power Reduction Register1
    struct PRR1 {
        static const uint8_t address = 0x65;
        enum bits : uint8_t {
            PRUSART1 = 1,   // Power Reduction USART1
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

    // Pin Change Interrupt Control Register
    struct PCICR {
        static const uint8_t address = 0x68;
        enum bits : uint8_t {
            PCIE0 = 1, // Pin Change Interrupt Enables
            PCIE1 = 2, // Pin Change Interrupt Enables
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
            PCINT0 = 1,  //
            PCINT1 = 2,  //
            PCINT2 = 4,  //
            PCINT3 = 8,  //
            PCINT4 = 16, //
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
    };

    //
    struct CLKSEL0 {
        static const uint8_t address = 0xd0;
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
        static const uint8_t address = 0xd1;
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
        static const uint8_t address = 0xd2;
        enum bits : uint8_t {
            EXTON = 1, //
            RCON  = 2, //
        };
    };

    // USB General Control Register
    struct USBCON {
        static const uint8_t address = 0xd8;
        enum bits : uint8_t {
            FRZCLK = 32,  //
            USBE   = 128, //
        };
    };

    //
    struct UDCON {
        static const uint8_t address = 0xe0;
        enum bits : uint8_t {
            DETACH = 1, //
            RMWKUP = 2, //
            RSTCPU = 4, //
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
    };

    //
    struct UEBCLX {
        static const uint8_t address = 0xf2;
    };

    //
    struct UEINT {
        static const uint8_t address = 0xf4;
    };

    // PS2 Pad Enable register
    struct PS2CON {
        static const uint8_t address = 0xfa;
        enum bits : uint8_t {
            PS2EN = 1, // Enable
        };
    };

    //
    struct UPOE {
        static const uint8_t address = 0xfb;
        enum bits : uint8_t {
            DMI    = 1,   //
            DPI    = 2,   //
            DATAI  = 4,   //
            SCKI   = 8,   //
            UPDRV0 = 16,  //
            UPDRV1 = 32,  //
            UPWE0  = 64,  //
            UPWE1  = 128, //
        };
    };

}

#endif
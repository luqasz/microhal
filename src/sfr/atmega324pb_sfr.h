#ifndef atmega324pb_sfr_h
#define atmega324pb_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega324PB
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

    // Timer/Counter Interrupt Flag register
    struct TIFR4 {
        static const uint8_t address = 0x39;
        enum bits : uint8_t {
            TOV4  = 1,  // Timer/Counter4 Overflow Flag
            OCF4A = 2,  // Timer/Counter4 Output Compare A Match Flag
            OCF4B = 4,  // Timer/Counter4 Output Compare B Match Flag
            ICF4  = 32, // Timer/Counter4 Input Capture Flag
        };
    };

    // Pin Change Interrupt Flag Register
    struct PCIFR {
        static const uint8_t address = 0x3b;
        enum bits : uint8_t {
            PCIF0 = 1,  // Pin Change Interrupt Flags
            PCIF1 = 2,  // Pin Change Interrupt Flags
            PCIF2 = 4,  // Pin Change Interrupt Flags
            PCIF3 = 8,  // Pin Change Interrupt Flags
            PCIF4 = 16, // Pin Change Interrupt Flags
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
            INT0 = 1, // External Interrupt Request Enable
            INT1 = 2, // External Interrupt Request Enable
            INT2 = 4, // External Interrupt Request Enable
        };
    };

    // General Purpose IO Register 0
    struct GPIOR0 {
        static const uint8_t address = 0x3e;
    };

    // EEPROM Control Register
    struct EECR {
        static const uint8_t address = 0x3f;
        enum bits : uint8_t {
            EERE  = 1,  // EEPROM Read Enable
            EEPE  = 2,  // EEPROM Programming Enable
            EEMPE = 4,  // EEPROM Master Programming Enable
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

    // Timer/Counter0 Control Register A
    struct TCCR0A {
        static const uint8_t address = 0x44;
        enum bits : uint8_t {
            WGM00  = 1,   // Waveform Generation Mode
            WGM01  = 2,   // Waveform Generation Mode
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
            WGM02 = 8,   // Waveform Generation Mode
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
    };

    // General Purpose IO Register 2
    struct GPIOR2 {
        static const uint8_t address = 0x4b;
    };

    // SPI Control Register
    struct SPCR0 {
        static const uint8_t address = 0x4c;
        enum bits : uint8_t {
            SPR0 = 1,   // SPI Clock Rate Select
            SPR1 = 2,   // SPI Clock Rate Select
            CPHA = 4,   // Clock Phase
            CPOL = 8,   // Clock polarity
            MSTR = 16,  // Master/Slave Select
            DORD = 32,  // Data Order
            SPE  = 64,  // SPI Enable
            SPIE = 128, // SPI Interrupt Enable
        };
    };

    // SPI Status Register
    struct SPSR0 {
        static const uint8_t address = 0x4d;
        enum bits : uint8_t {
            SPI2X = 1,   // Double SPI Speed Bit
            WCOL  = 64,  // Write Collision Flag
            SPIF  = 128, // SPI Interrupt Flag
        };
    };

    // SPI Data Register
    struct SPDR0 {
        static const uint8_t address = 0x4e;
    };

    // Analog Comparator Control And Status Register B
    struct ACSRB {
        static const uint8_t address = 0x4f;
        enum bits : uint8_t {
            ACOE = 1, // Analog Comparator Output enable
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

    // XOSC Failure Detection Control and Status Register
    struct XFDCSR {
        static const uint8_t address = 0x62;
        enum bits : uint8_t {
            XFDIE = 1, // Failure Detection Interrupt Enable
            XFDIF = 2, // Failure Detection Interrupt Flag
        };
    };

    // Power Reduction Register2
    struct PRR2 {
        static const uint8_t address = 0x63;
        enum bits : uint8_t {
            PRTWI1   = 1, // Power Reduction TWI1
            PRSPI1   = 2, // Power Reduction Serial Peripheral Interface 1
            PRUSART2 = 4, // Power Reduction USART2
            PRPTC    = 8, // Power Reduction Peripheral Touch Controller
        };
    };

    // Power Reduction Register0
    struct PRR0 {
        static const uint8_t address = 0x64;
        enum bits : uint8_t {
            PRADC    = 1,   // Power Reduction ADC
            PRUSART0 = 2,   // Power Reduction USART0
            PRSPI0   = 4,   // Power Reduction Serial Peripheral Interface 0
            PRTIM1   = 8,   // Power Reduction Timer/Counter1
            PRUSART1 = 16,  // Power Reduction USART1
            PRTIM0   = 32,  // Power Reduction Timer/Counter0
            PRTIM2   = 64,  // Power Reduction Timer/Counter2
            PRTWI0   = 128, // Power Reduction TWI0
        };
    };

    // Power Reduction Register1
    struct PRR1 {
        static const uint8_t address = 0x65;
        enum bits : uint8_t {
            PRTIM3 = 1, // Power Reduction Timer/Counter3
            PRTIM4 = 2, // Power Reduction Timer/Counter4
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
            PCIE0 = 1,  // Pin Change Interrupt Enables
            PCIE1 = 2,  // Pin Change Interrupt Enables
            PCIE2 = 4,  // Pin Change Interrupt Enables
            PCIE3 = 8,  // Pin Change Interrupt Enables
            PCIE4 = 16, // Pin Change Interrupt Enables
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

    // Timer/Counter4 Interrupt Mask Register
    struct TIMSK4 {
        static const uint8_t address = 0x72;
        enum bits : uint8_t {
            TOIE4  = 1,  // Timer/Counter4 Overflow Interrupt Enable
            OCIE4A = 2,  // Timer/Counter4 Output Compare A Match Interrupt Enable
            OCIE4B = 4,  // Timer/Counter4 Output Compare B Match Interrupt Enable
            ICIE4  = 32, // Timer/Counter4 Input Capture Interrupt Enable
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

    // Pin Change Mask Register 4
    struct PCMSK4 {
        static const uint8_t address = 0x75;
        enum bits : uint8_t {
            PCINT0 = 1,  // Pin Change Enable Masks
            PCINT1 = 2,  // Pin Change Enable Masks
            PCINT2 = 4,  // Pin Change Enable Masks
            PCINT3 = 8,  // Pin Change Enable Masks
            PCINT4 = 16, // Pin Change Enable Masks
            PCINT5 = 32, // Pin Change Enable Masks
            PCINT6 = 64, // Pin Change Enable Masks
        };
    };

    // ADC Data Register  Bytes
    struct ADC {
        static const uint16_t address = 0x78;
    };

    // ADC Control and Status register A
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

    // ADC Control and Status register B
    struct ADCSRB {
        static const uint8_t address = 0x7b;
        enum bits : uint8_t {
            ADTS0  = 1,   // ADC Auto Trigger Source bits
            ADTS1  = 2,   // ADC Auto Trigger Source bits
            ADTS2  = 4,   // ADC Auto Trigger Source bits
            ACME   = 64,  // Analog Comparator Multiplexer Enable
            GPIOEN = 128, // Enable GPIO function of PE4
        };
    };

    // ADC multiplexer Selection Register
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
    };

    // Timer/Counter3 Input Capture Register Bytes
    struct ICR3 {
        static const uint16_t address = 0x96;
    };

    // Timer/Counter3 Output Compare Register A Bytes
    struct OCR3A {
        static const uint16_t address = 0x98;
    };

    // Timer/Counter3 Output Compare Register B Bytes
    struct OCR3B {
        static const uint16_t address = 0x9a;
    };

    // Timer/Counter4 Control Register A
    struct TCCR4A {
        static const uint8_t address = 0xa0;
        enum bits : uint8_t {
            WGM40  = 1,   // Pulse Width Modulator Select Bits
            WGM41  = 2,   // Pulse Width Modulator Select Bits
            COM4B0 = 16,  // Compare Output Mode 4B, bits
            COM4B1 = 32,  // Compare Output Mode 4B, bits
            COM4A0 = 64,  // Compare Output Mode 4A, bits
            COM4A1 = 128, // Compare Output Mode 4A, bits
        };
    };

    // Timer/Counter4 Control Register B
    struct TCCR4B {
        static const uint8_t address = 0xa1;
        enum bits : uint8_t {
            CS40  = 1,   // Clock Select4 bits
            CS41  = 2,   // Clock Select4 bits
            CS42  = 4,   // Clock Select4 bits
            WGM40 = 8,   // Waveform Generation Mode Bits
            WGM41 = 16,  // Waveform Generation Mode Bits
            ICES4 = 64,  // Input Capture 4 Edge Select
            ICNC4 = 128, // Input Capture 4 Noise Canceler
        };
    };

    // Timer/Counter4 Control Register C
    struct TCCR4C {
        static const uint8_t address = 0xa2;
        enum bits : uint8_t {
            FOC4B = 64,  // Force Output Compare for Channel B
            FOC4A = 128, // Force Output Compare for Channel A
        };
    };

    // Timer/Counter4 Bytes
    struct TCNT4 {
        static const uint16_t address = 0xa4;
    };

    // Timer/Counter4 Input Capture Register Bytes
    struct ICR4 {
        static const uint16_t address = 0xa6;
    };

    // Timer/Counter4 Output Compare Register A Bytes
    struct OCR4A {
        static const uint16_t address = 0xa8;
    };

    // Timer/Counter4 Output Compare Register B Bytes
    struct OCR4B {
        static const uint16_t address = 0xaa;
    };

    // SPI Control Register
    struct SPCR1 {
        static const uint8_t address = 0xac;
        enum bits : uint8_t {
            SPR0 = 1,   // SPI Clock Rate Select
            SPR1 = 2,   // SPI Clock Rate Select
            CPHA = 4,   // Clock Phase
            CPOL = 8,   // Clock polarity
            MSTR = 16,  // Master/Slave Select
            DORD = 32,  // Data Order
            SPE  = 64,  // SPI Enable
            SPIE = 128, // SPI Interrupt Enable
        };
    };

    // SPI Status Register
    struct SPSR1 {
        static const uint8_t address = 0xad;
        enum bits : uint8_t {
            SPI2X = 1,   // Double SPI Speed Bit
            WCOL  = 64,  // Write Collision Flag
            SPIF  = 128, // SPI Interrupt Flag
        };
    };

    // SPI Data Register
    struct SPDR1 {
        static const uint8_t address = 0xae;
    };

    // Timer/Counter2 Control Register A
    struct TCCR2A {
        static const uint8_t address = 0xb0;
        enum bits : uint8_t {
            WGM20  = 1,   // Waveform Genration Mode
            WGM21  = 2,   // Waveform Genration Mode
            COM2B0 = 16,  // Compare Output Mode 2B bits
            COM2B1 = 32,  // Compare Output Mode 2B bits
            COM2A0 = 64,  // Compare Output Mode 2A bits
            COM2A1 = 128, // Compare Output Mode 2A bits
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
    struct TWBR0 {
        static const uint8_t address = 0xb8;
    };

    // TWI Status Register
    struct TWSR0 {
        static const uint8_t address = 0xb9;
        enum bits : uint8_t {
            TWPS0 = 1,   // TWI Prescaler
            TWPS1 = 2,   // TWI Prescaler
            TWS00 = 8,   // TWI Status
            TWS01 = 16,  // TWI Status
            TWS02 = 32,  // TWI Status
            TWS03 = 64,  // TWI Status
            TWS04 = 128, // TWI Status
        };
    };

    // TWI (Slave) Address register
    struct TWAR0 {
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
    struct TWDR0 {
        static const uint8_t address = 0xbb;
    };

    // TWI Control Register
    struct TWCR0 {
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
    struct TWAMR0 {
        static const uint8_t address = 0xbd;
        enum bits : uint8_t {
            TWAM00 = 2,   //
            TWAM01 = 4,   //
            TWAM02 = 8,   //
            TWAM03 = 16,  //
            TWAM04 = 32,  //
            TWAM05 = 64,  //
            TWAM06 = 128, //
        };
    };

    // USART Control and Status Register A
    struct UCSR0A {
        static const uint8_t address = 0xc0;
        enum bits : uint8_t {
            MPCM = 1,   // Multi-processor Communication Mode
            U2X  = 2,   // Double the USART transmission speed
            UPE  = 4,   // Parity Error
            DOR  = 8,   // Data overRun
            FE   = 16,  // Framing Error
            UDRE = 32,  // USART Data Register Empty
            TXC  = 64,  // USART Transmitt Complete
            RXC  = 128, // USART Receive Complete
        };
    };

    // USART Control and Status Register B
    struct UCSR0B {
        static const uint8_t address = 0xc1;
        enum bits : uint8_t {
            TXB8  = 1,   // Transmit Data Bit 8
            RXB8  = 2,   // Receive Data Bit 8
            UCSZ2 = 4,   // Character Size
            TXEN  = 8,   // Transmitter Enable
            RXEN  = 16,  // Receiver Enable
            UDRIE = 32,  // USART Data register Empty Interrupt Enable
            TXCIE = 64,  // TX Complete Interrupt Enable
            RXCIE = 128, // RX Complete Interrupt Enable
        };
    };

    // USART Control and Status Register C
    struct UCSR0C {
        static const uint8_t address = 0xc2;
        enum bits : uint8_t {
            UCPOL  = 1,   // Clock Polarity
            UCSZ0  = 2,   // Character Size
            UCSZ1  = 4,   // Character Size
            USBS   = 8,   // Stop Bit Select
            UPM0   = 16,  // Parity Mode Bits
            UPM1   = 32,  // Parity Mode Bits
            UMSEL0 = 64,  // USART Mode Select
            UMSEL1 = 128, // USART Mode Select
        };
    };

    // USART Control and Status Register D
    struct UCSR0D {
        static const uint8_t address = 0xc3;
        enum bits : uint8_t {
            SFDE  = 32,  // Start Frame Detection Enable
            RXS   = 64,  // Start Frame Detect Flag
            RXSIE = 128, // RX Start Frame Interrupt Enable
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
            MPCM = 1,   // Multi-processor Communication Mode
            U2X  = 2,   // Double the USART transmission speed
            UPE  = 4,   // Parity Error
            DOR  = 8,   // Data overRun
            FE   = 16,  // Framing Error
            UDRE = 32,  // USART Data Register Empty
            TXC  = 64,  // USART Transmitt Complete
            RXC  = 128, // USART Receive Complete
        };
    };

    // USART Control and Status Register B
    struct UCSR1B {
        static const uint8_t address = 0xc9;
        enum bits : uint8_t {
            TXB8  = 1,   // Transmit Data Bit 8
            RXB8  = 2,   // Receive Data Bit 8
            UCSZ2 = 4,   // Character Size
            TXEN  = 8,   // Transmitter Enable
            RXEN  = 16,  // Receiver Enable
            UDRIE = 32,  // USART Data register Empty Interrupt Enable
            TXCIE = 64,  // TX Complete Interrupt Enable
            RXCIE = 128, // RX Complete Interrupt Enable
        };
    };

    // USART Control and Status Register C
    struct UCSR1C {
        static const uint8_t address = 0xca;
        enum bits : uint8_t {
            UCPOL  = 1,   // Clock Polarity
            UCSZ0  = 2,   // Character Size
            UCSZ1  = 4,   // Character Size
            USBS   = 8,   // Stop Bit Select
            UPM0   = 16,  // Parity Mode Bits
            UPM1   = 32,  // Parity Mode Bits
            UMSEL0 = 64,  // USART Mode Select
            UMSEL1 = 128, // USART Mode Select
        };
    };

    // USART Control and Status Register D
    struct UCSR1D {
        static const uint8_t address = 0xcb;
        enum bits : uint8_t {
            SFDE  = 32,  // Start Frame Detection Enable
            RXS   = 64,  // Start Frame Detect Flag
            RXSIE = 128, // RX Start Frame Interrupt Enable
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
            MPCM = 1,   // Multi-processor Communication Mode
            U2X  = 2,   // Double the USART transmission speed
            UPE  = 4,   // Parity Error
            DOR  = 8,   // Data overRun
            FE   = 16,  // Framing Error
            UDRE = 32,  // USART Data Register Empty
            TXC  = 64,  // USART Transmitt Complete
            RXC  = 128, // USART Receive Complete
        };
    };

    // USART Control and Status Register B
    struct UCSR2B {
        static const uint8_t address = 0xd1;
        enum bits : uint8_t {
            TXB8  = 1,   // Transmit Data Bit 8
            RXB8  = 2,   // Receive Data Bit 8
            UCSZ2 = 4,   // Character Size
            TXEN  = 8,   // Transmitter Enable
            RXEN  = 16,  // Receiver Enable
            UDRIE = 32,  // USART Data register Empty Interrupt Enable
            TXCIE = 64,  // TX Complete Interrupt Enable
            RXCIE = 128, // RX Complete Interrupt Enable
        };
    };

    // USART Control and Status Register C
    struct UCSR2C {
        static const uint8_t address = 0xd2;
        enum bits : uint8_t {
            UCPOL  = 1,   // Clock Polarity
            UCSZ0  = 2,   // Character Size
            UCSZ1  = 4,   // Character Size
            USBS   = 8,   // Stop Bit Select
            UPM0   = 16,  // Parity Mode Bits
            UPM1   = 32,  // Parity Mode Bits
            UMSEL0 = 64,  // USART Mode Select
            UMSEL1 = 128, // USART Mode Select
        };
    };

    // USART Control and Status Register D
    struct UCSR2D {
        static const uint8_t address = 0xd3;
        enum bits : uint8_t {
            SFDE  = 32,  // Start Frame Detection Enable
            RXS   = 64,  // Start Frame Detect Flag
            RXSIE = 128, // RX Start Frame Interrupt Enable
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

    // TWI Bit Rate register
    struct TWBR1 {
        static const uint8_t address = 0xd8;
    };

    // TWI Status Register
    struct TWSR1 {
        static const uint8_t address = 0xd9;
        enum bits : uint8_t {
            TWPS0 = 1,   // TWI Prescaler
            TWPS1 = 2,   // TWI Prescaler
            TWS00 = 8,   // TWI Status
            TWS01 = 16,  // TWI Status
            TWS02 = 32,  // TWI Status
            TWS03 = 64,  // TWI Status
            TWS04 = 128, // TWI Status
        };
    };

    // TWI (Slave) Address register
    struct TWAR1 {
        static const uint8_t address = 0xda;
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
    struct TWDR1 {
        static const uint8_t address = 0xdb;
    };

    // TWI Control Register
    struct TWCR1 {
        static const uint8_t address = 0xdc;
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
    struct TWAMR1 {
        static const uint8_t address = 0xdd;
        enum bits : uint8_t {
            TWAM10 = 2,   //
            TWAM11 = 4,   //
            TWAM12 = 8,   //
            TWAM13 = 16,  //
            TWAM14 = 32,  //
            TWAM15 = 64,  //
            TWAM16 = 128, //
        };
    };

}

#endif
#ifndef atmega165p_sfr_h
#define atmega165p_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega165P
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

    // Port G Input Pins
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

    // Timer/Counter0 Interrupt Flag register
    struct TIFR0 {
        static const uint8_t address = 0x35;
        enum bits : uint8_t {
            TOV0  = 1, // Timer/Counter0 Overflow Flag
            OCF0A = 2, // Timer/Counter0 Output Compare Flag 0
        };
    };

    // Timer/Counter1 Interrupt Flag register
    struct TIFR1 {
        static const uint8_t address = 0x36;
        enum bits : uint8_t {
            TOV1  = 1,  // Timer/Counter1 Overflow Flag
            OCF1A = 2,  // Output Compare Flag 1A
            OCF1B = 4,  // Output Compare Flag 1B
            ICF1  = 32, // Input Capture Flag 1
        };
    };

    // Timer/Counter2 Interrupt Flag Register
    struct TIFR2 {
        static const uint8_t address = 0x37;
        enum bits : uint8_t {
            TOV2  = 1, // Timer/Counter2 Overflow Flag
            OCF2A = 2, // Timer/Counter2 Output Compare Flag 2
        };
    };

    // External Interrupt Flag Register
    struct EIFR {
        static const uint8_t address = 0x3c;
        enum bits : uint8_t {
            INTF0 = 1,   // External Interrupt Flag 0
            PCIF0 = 64,  // Pin Change Interrupt Flags
            PCIF1 = 128, // Pin Change Interrupt Flags
        };
    };

    // External Interrupt Mask Register
    struct EIMSK {
        static const uint8_t address = 0x3d;
        enum bits : uint8_t {
            INT0  = 1,   // External Interrupt Request 0 Enable
            PCIE0 = 64,  // Pin Change Interrupt Enables
            PCIE1 = 128, // Pin Change Interrupt Enables
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
            EERE  = 1, // EEPROM Read Enable
            EEWE  = 2, // EEPROM Write Enable
            EEMWE = 4, // EEPROM Master Write Enable
            EERIE = 8, // EEPROM Ready Interrupt Enable
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

    // General Timer/Control Register
    struct GTCCR {
        static const uint8_t address = 0x43;
        enum bits : uint8_t {
            PSR10 = 1,   // Prescaler Reset Timer/Counter1 and Timer/Counter0
            PSR2  = 2,   // Prescaler Reset Timer/Counter2
            TSM   = 128, // Timer/Counter Synchronization Mode
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
            CLKPS0 = 1,   // Clock Prescaler Select Bits
            CLKPS1 = 2,   // Clock Prescaler Select Bits
            CLKPS2 = 4,   // Clock Prescaler Select Bits
            CLKPS3 = 8,   // Clock Prescaler Select Bits
            CLKPCE = 128, // Clock Prescaler Change Enable
        };
    };

    // Power Reduction Register
    struct PRR {
        static const uint8_t address = 0x64;
        enum bits : uint8_t {
            PRADC    = 1, // Power Reduction ADC
            PRUSART0 = 2, // Power Reduction USART
            PRSPI    = 4, // Power Reduction Serial Peripheral Interface
            PRTIM1   = 8, // Power Reduction Timer/Counter1
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

    // External Interrupt Control Register
    struct EICRA {
        static const uint8_t address = 0x69;
        enum bits : uint8_t {
            ISC00 = 1, // External Interrupt Sense Control 0 Bit 0
            ISC01 = 2, // External Interrupt Sense Control 0 Bit 1
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

    // Timer/Counter0 Interrupt Mask Register
    struct TIMSK0 {
        static const uint8_t address = 0x6e;
        enum bits : uint8_t {
            TOIE0  = 1, // Timer/Counter0 Overflow Interrupt Enable
            OCIE0A = 2, // Timer/Counter0 Output Compare Match Interrupt Enable
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

    // Timer/Counter2 Interrupt Mask register
    struct TIMSK2 {
        static const uint8_t address = 0x70;
        enum bits : uint8_t {
            TOIE2  = 1, // Timer/Counter2 Overflow Interrupt Enable
            OCIE2A = 2, // Timer/Counter2 Output Compare Match Interrupt Enable
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
            ADTS0 = 1,  // ADC Auto Trigger Sources
            ADTS1 = 2,  // ADC Auto Trigger Sources
            ADTS2 = 4,  // ADC Auto Trigger Sources
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
            WGM20  = 64,  // Waveform Generation Mode
            FOC2A  = 128, // Force Output Compare A
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

    // USI Control Register
    struct USICR {
        static const uint8_t address = 0xb8;
        enum bits : uint8_t {
            USITC  = 1,   // Toggle Clock Port Pin
            USICLK = 2,   // Clock Strobe
            USICS0 = 4,   // USI Clock Source Select Bits
            USICS1 = 8,   // USI Clock Source Select Bits
            USIWM0 = 16,  // USI Wire Mode Bits
            USIWM1 = 32,  // USI Wire Mode Bits
            USIOIE = 64,  // Counter Overflow Interrupt Enable
            USISIE = 128, // Start Condition Interrupt Enable
        };
    };

    // USI Status Register
    struct USISR {
        static const uint8_t address = 0xb9;
        enum bits : uint8_t {
            USICNT0 = 1,   // USI Counter Value Bits
            USICNT1 = 2,   // USI Counter Value Bits
            USICNT2 = 4,   // USI Counter Value Bits
            USICNT3 = 8,   // USI Counter Value Bits
            USIDC   = 16,  // Data Output Collision
            USIPF   = 32,  // Stop Condition Flag
            USIOIF  = 64,  // Counter Overflow Interrupt Flag
            USISIF  = 128, // Start Condition Interrupt Flag
        };
    };

    // USI Data Register
    struct USIDR {
        static const uint8_t address = 0xba;
    };

    // USART Control and Status Register A
    struct UCSR0A {
        static const uint8_t address = 0xc0;
        enum bits : uint8_t {
            MPCM0 = 1,   // Multi-processor Communication Mode
            U2X0  = 2,   // Double the USART Transmission Speed
            UPE0  = 4,   // USART Parity Error
            DOR0  = 8,   // Data OverRun
            FE0   = 16,  // Framing Error
            UDRE0 = 32,  // USART Data Register Empty
            TXC0  = 64,  // USART Transmit Complete
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
            UDRIE0 = 32,  // USART Data Register Empty Interrupt Enable
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

    // USART Baud Rate Register  Bytes
    struct UBRR0 {
        static const uint16_t address = 0xc4;
    };

    // USART I/O Data Register
    struct UDR0 {
        static const uint8_t address = 0xc6;
    };

}

#endif
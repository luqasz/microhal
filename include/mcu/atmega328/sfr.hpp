#pragma once

#include "../../types.hpp"

#include <stdint.h>

namespace SFR {

    // USART I/O Data Register
    struct UDR0 {
        static const uint16_t address = 0xc6;
        enum bits : uint8_t {
            UDR05 = 32,  // USART I/O Data bits
            UDR00 = 1,   // USART I/O Data bits
            UDR01 = 2,   // USART I/O Data bits
            UDR06 = 64,  // USART I/O Data bits
            UDR02 = 4,   // USART I/O Data bits
            UDR07 = 128, // USART I/O Data bits
            UDR03 = 8,   // USART I/O Data bits
            UDR04 = 16,  // USART I/O Data bits
        };
    };

    // USART Control and Status Register A
    struct UCSR0A {
        static const uint16_t address = 0xc0;
        enum bits : uint8_t {
            RXC0  = 128, // USART Receive Complete
            UDRE0 = 32,  // USART Data Register Empty
            U2X0  = 2,   // Double the USART transmission speed
            MPCM0 = 1,   // Multi-processor Communication Mode
            TXC0  = 64,  // USART Transmitt Complete
            UPE0  = 4,   // Parity Error
            DOR0  = 8,   // Data overRun
            FE0   = 16,  // Framing Error
        };
    };

    // USART Control and Status Register B
    struct UCSR0B {
        static const uint16_t address = 0xc1;
        enum bits : uint8_t {
            UDRIE0 = 32,  // USART Data register Empty Interrupt Enable
            RXCIE0 = 128, // RX Complete Interrupt Enable
            RXB80  = 2,   // Receive Data Bit 8
            TXCIE0 = 64,  // TX Complete Interrupt Enable
            UCSZ02 = 4,   // Character Size
            TXB80  = 1,   // Transmit Data Bit 8
            TXEN0  = 8,   // Transmitter Enable
            RXEN0  = 16,  // Receiver Enable
        };
    };

    // USART Control and Status Register C
    struct UCSR0C {
        static const uint16_t address = 0xc2;
        enum bits : uint8_t {
            UMSEL00 = 64,  // USART Mode Select
            UCPOL0  = 1,   // Clock Polarity
            UCSZ00  = 2,   // Character Size
            UMSEL01 = 128, // USART Mode Select
            UCSZ01  = 4,   // Character Size
            UPM01   = 32,  // Parity Mode Bits
            USBS0   = 8,   // Stop Bit Select
            UPM00   = 16,  // Parity Mode Bits
        };
    };

    // USART Baud Rate Register Bytes
    struct UBRR0 {
        static const uint16_t address = 0xc4;
        enum bits : uint8_t {
            UBRR05 = 32,  // USART Baud rate bits
            UBRR00 = 1,   // USART Baud rate bits
            UBRR01 = 2,   // USART Baud rate bits
            UBRR06 = 64,  // USART Baud rate bits
            UBRR02 = 4,   // USART Baud rate bits
            UBRR07 = 128, // USART Baud rate bits
            UBRR03 = 8,   // USART Baud rate bits
            UBRR04 = 16,  // USART Baud rate bits
        };
    };

    // TWI (Slave) Address Mask Register
    struct TWAMR {
        static const uint16_t address = 0xbd;
        enum bits : uint8_t {
            TWAM4 = 32,  //
            TWAM5 = 64,  //
            TWAM0 = 2,   //
            TWAM6 = 128, //
            TWAM1 = 4,   //
            TWAM2 = 8,   //
            TWAM3 = 16,  //
        };
    };

    // TWI Bit Rate register
    struct TWBR {
        static const uint16_t address = 0xb8;
        enum bits : uint8_t {
            TWBR5 = 32,  // TWI Bit rate bits
            TWBR0 = 1,   // TWI Bit rate bits
            TWBR1 = 2,   // TWI Bit rate bits
            TWBR6 = 64,  // TWI Bit rate bits
            TWBR2 = 4,   // TWI Bit rate bits
            TWBR7 = 128, // TWI Bit rate bits
            TWBR3 = 8,   // TWI Bit rate bits
            TWBR4 = 16,  // TWI Bit rate bits
        };
    };

    // TWI Control Register
    struct TWCR {
        static const uint16_t address = 0xbc;
        enum bits : uint8_t {
            TWINT = 128, // TWI Interrupt Flag
            TWSTA = 32,  // TWI Start Condition Bit
            TWEA  = 64,  // TWI Enable Acknowledge Bit
            TWIE  = 1,   // TWI Interrupt Enable
            TWEN  = 4,   // TWI Enable Bit
            TWWC  = 8,   // TWI Write Collition Flag
            TWSTO = 16,  // TWI Stop Condition Bit
        };
    };

    // TWI Status Register
    struct TWSR {
        static const uint16_t address = 0xb9;
        enum bits : uint8_t {
            TWS2  = 32,  // TWI Status
            TWPS0 = 1,   // TWI Prescaler
            TWPS1 = 2,   // TWI Prescaler
            TWS3  = 64,  // TWI Status
            TWS4  = 128, // TWI Status
            TWS0  = 8,   // TWI Status
            TWS1  = 16,  // TWI Status
        };
    };

    // TWI Data register
    struct TWDR {
        static const uint16_t address = 0xbb;
        enum bits : uint8_t {
            TWDR5 = 32,  // TWI Data bits
            TWDR0 = 1,   // TWI Data bits
            TWDR1 = 2,   // TWI Data bits
            TWDR6 = 64,  // TWI Data bits
            TWDR2 = 4,   // TWI Data bits
            TWDR7 = 128, // TWI Data bits
            TWDR3 = 8,   // TWI Data bits
            TWDR4 = 16,  // TWI Data bits
        };
    };

    // TWI (Slave) Address register
    struct TWAR {
        static const uint16_t address = 0xba;
        enum bits : uint8_t {
            TWA4  = 32,  // TWI (Slave) Address register Bits
            TWGCE = 1,   // TWI General Call Recognition Enable Bit
            TWA0  = 2,   // TWI (Slave) Address register Bits
            TWA5  = 64,  // TWI (Slave) Address register Bits
            TWA1  = 4,   // TWI (Slave) Address register Bits
            TWA6  = 128, // TWI (Slave) Address register Bits
            TWA2  = 8,   // TWI (Slave) Address register Bits
            TWA3  = 16,  // TWI (Slave) Address register Bits
        };
    };

    // Timer/Counter Interrupt Mask Register
    struct TIMSK1 {
        static const uint16_t address = 0x6f;
        enum bits : uint8_t {
            ICIE1  = 32, // Timer/Counter1 Input Capture Interrupt Enable
            TOIE1  = 1,  // Timer/Counter1 Overflow Interrupt Enable
            OCIE1A = 2,  // Timer/Counter1 Output CompareA Match Interrupt Enable
            OCIE1B = 4,  // Timer/Counter1 Output CompareB Match Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR1 {
        static const uint16_t address = 0x36;
        enum bits : uint8_t {
            ICF1  = 32, // Input Capture Flag 1
            TOV1  = 1,  // Timer/Counter1 Overflow Flag
            OCF1A = 2,  // Output Compare Flag 1A
            OCF1B = 4,  // Output Compare Flag 1B
        };
    };

    // Timer/Counter1 Control Register A
    struct TCCR1A {
        static const uint16_t address = 0x80;
        enum bits : uint8_t {
            COM1A0 = 64,  // Compare Output Mode 1A, bits
            WGM10  = 1,   // Waveform Generation Mode
            WGM11  = 2,   // Waveform Generation Mode
            COM1A1 = 128, // Compare Output Mode 1A, bits
            COM1B1 = 32,  // Compare Output Mode 1B, bits
            COM1B0 = 16,  // Compare Output Mode 1B, bits
        };
    };

    // Timer/Counter1 Control Register B
    struct TCCR1B {
        static const uint16_t address = 0x81;
        enum bits : uint8_t {
            ICNC1 = 128, // Input Capture 1 Noise Canceler
            CS10  = 1,   // Prescaler source of Timer/Counter 1
            CS11  = 2,   // Prescaler source of Timer/Counter 1
            ICES1 = 64,  // Input Capture 1 Edge Select
            CS12  = 4,   // Prescaler source of Timer/Counter 1
            WGM12 = 8,   // Waveform Generation Mode
            WGM13 = 16,  // Waveform Generation Mode
        };
    };

    // Timer/Counter1 Control Register C
    struct TCCR1C {
        static const uint16_t address = 0x82;
        enum bits : uint8_t {
            FOC1B = 64,  //
            FOC1A = 128, //
        };
    };

    // Timer/Counter1 Bytes
    struct TCNT1 {
        static const uint16_t address = 0x84;
        enum bits : uint8_t {
            TCNT15 = 32,  // Timer/Counter1 bits
            TCNT10 = 1,   // Timer/Counter1 bits
            TCNT11 = 2,   // Timer/Counter1 bits
            TCNT16 = 64,  // Timer/Counter1 bits
            TCNT12 = 4,   // Timer/Counter1 bits
            TCNT17 = 128, // Timer/Counter1 bits
            TCNT13 = 8,   // Timer/Counter1 bits
            TCNT14 = 16,  // Timer/Counter1 bits
        };
    };

    // Timer/Counter1 Output Compare Register Bytes
    struct OCR1A {
        static const uint16_t address = 0x88;
        enum bits : uint8_t {
            OCR1A5 = 32,  // Timer/Counter1 Output Compare A bits
            OCR1A0 = 1,   // Timer/Counter1 Output Compare A bits
            OCR1A1 = 2,   // Timer/Counter1 Output Compare A bits
            OCR1A6 = 64,  // Timer/Counter1 Output Compare A bits
            OCR1A2 = 4,   // Timer/Counter1 Output Compare A bits
            OCR1A7 = 128, // Timer/Counter1 Output Compare A bits
            OCR1A3 = 8,   // Timer/Counter1 Output Compare A bits
            OCR1A4 = 16,  // Timer/Counter1 Output Compare A bits
        };
    };

    // Timer/Counter1 Output Compare Register Bytes
    struct OCR1B {
        static const uint16_t address = 0x8a;
        enum bits : uint8_t {
            OCR1B5 = 32,  // Timer/Counter1 Output Compare B bits
            OCR1B0 = 1,   // Timer/Counter1 Output Compare B bits
            OCR1B1 = 2,   // Timer/Counter1 Output Compare B bits
            OCR1B6 = 64,  // Timer/Counter1 Output Compare B bits
            OCR1B2 = 4,   // Timer/Counter1 Output Compare B bits
            OCR1B7 = 128, // Timer/Counter1 Output Compare B bits
            OCR1B3 = 8,   // Timer/Counter1 Output Compare B bits
            OCR1B4 = 16,  // Timer/Counter1 Output Compare B bits
        };
    };

    // Timer/Counter1 Input Capture Register Bytes
    struct ICR1 {
        static const uint16_t address = 0x86;
        enum bits : uint8_t {
            ICR15 = 32,  // Timer/Counter1 Input Capture bits
            ICR10 = 1,   // Timer/Counter1 Input Capture bits
            ICR11 = 2,   // Timer/Counter1 Input Capture bits
            ICR16 = 64,  // Timer/Counter1 Input Capture bits
            ICR12 = 4,   // Timer/Counter1 Input Capture bits
            ICR17 = 128, // Timer/Counter1 Input Capture bits
            ICR13 = 8,   // Timer/Counter1 Input Capture bits
            ICR14 = 16,  // Timer/Counter1 Input Capture bits
        };
    };

    // General Timer/Counter Control Register
    struct GTCCR {
        static const uint16_t address = 0x43;
        enum bits : uint8_t {
            TSM     = 128, // Timer/Counter Synchronization Mode
            PSRSYNC = 1,   // Prescaler Reset Timer/Counter1 and Timer/Counter0
            PSRASY  = 2,   // Prescaler Reset Timer/Counter2
        };
    };

    // Timer/Counter Interrupt Mask register
    struct TIMSK2 {
        static const uint16_t address = 0x70;
        enum bits : uint8_t {
            TOIE2  = 1, // Timer/Counter2 Overflow Interrupt Enable
            OCIE2A = 2, // Timer/Counter2 Output Compare Match A Interrupt Enable
            OCIE2B = 4, // Timer/Counter2 Output Compare Match B Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Flag Register
    struct TIFR2 {
        static const uint16_t address = 0x37;
        enum bits : uint8_t {
            TOV2  = 1, // Timer/Counter2 Overflow Flag
            OCF2A = 2, // Output Compare Flag 2A
            OCF2B = 4, // Output Compare Flag 2B
        };
    };

    // Timer/Counter2 Control Register A
    struct TCCR2A {
        static const uint16_t address = 0xb0;
        enum bits : uint8_t {
            COM2B1 = 32,  // Compare Output Mode bits
            WGM20  = 1,   // Waveform Genration Mode
            WGM21  = 2,   // Waveform Genration Mode
            COM2A0 = 64,  // Compare Output Mode bits
            COM2A1 = 128, // Compare Output Mode bits
            COM2B0 = 16,  // Compare Output Mode bits
        };
    };

    // Timer/Counter2 Control Register B
    struct TCCR2B {
        static const uint16_t address = 0xb1;
        enum bits : uint8_t {
            FOC2A = 128, // Force Output Compare A
            CS20  = 1,   // Clock Select bits
            CS21  = 2,   // Clock Select bits
            FOC2B = 64,  // Force Output Compare B
            CS22  = 4,   // Clock Select bits
            WGM22 = 8,   // Waveform Generation Mode
        };
    };

    // Timer/Counter2
    struct TCNT2 {
        static const uint16_t address = 0xb2;
        enum bits : uint8_t {
            TCNT25 = 32,  // Timer/Counter2 bits
            TCNT20 = 1,   // Timer/Counter2 bits
            TCNT21 = 2,   // Timer/Counter2 bits
            TCNT26 = 64,  // Timer/Counter2 bits
            TCNT22 = 4,   // Timer/Counter2 bits
            TCNT27 = 128, // Timer/Counter2 bits
            TCNT23 = 8,   // Timer/Counter2 bits
            TCNT24 = 16,  // Timer/Counter2 bits
        };
    };

    // Timer/Counter2 Output Compare Register B
    struct OCR2B {
        static const uint16_t address = 0xb4;
        enum bits : uint8_t {
            OCR2B5 = 32,  // Timer/Counter2 Output Compare B bits
            OCR2B0 = 1,   // Timer/Counter2 Output Compare B bits
            OCR2B1 = 2,   // Timer/Counter2 Output Compare B bits
            OCR2B6 = 64,  // Timer/Counter2 Output Compare B bits
            OCR2B2 = 4,   // Timer/Counter2 Output Compare B bits
            OCR2B7 = 128, // Timer/Counter2 Output Compare B bits
            OCR2B3 = 8,   // Timer/Counter2 Output Compare B bits
            OCR2B4 = 16,  // Timer/Counter2 Output Compare B bits
        };
    };

    // Timer/Counter2 Output Compare Register A
    struct OCR2A {
        static const uint16_t address = 0xb3;
        enum bits : uint8_t {
            OCR2A5 = 32,  // Timer/Counter2 Output Compare A bits
            OCR2A0 = 1,   // Timer/Counter2 Output Compare A bits
            OCR2A1 = 2,   // Timer/Counter2 Output Compare A bits
            OCR2A6 = 64,  // Timer/Counter2 Output Compare A bits
            OCR2A2 = 4,   // Timer/Counter2 Output Compare A bits
            OCR2A7 = 128, // Timer/Counter2 Output Compare A bits
            OCR2A3 = 8,   // Timer/Counter2 Output Compare A bits
            OCR2A4 = 16,  // Timer/Counter2 Output Compare A bits
        };
    };

    // Asynchronous Status Register
    struct ASSR {
        static const uint16_t address = 0xb6;
        enum bits : uint8_t {
            EXCLK   = 64, // Enable External Clock Input
            AS2     = 32, // Asynchronous Timer/Counter2
            TCR2BUB = 1,  // Timer/Counter Control Register2 Update Busy
            TCR2AUB = 2,  // Timer/Counter Control Register2 Update Busy
            OCR2BUB = 4,  // Output Compare Register 2 Update Busy
            OCR2AUB = 8,  // Output Compare Register2 Update Busy
            TCN2UB  = 16, // Timer/Counter2 Update Busy
        };
    };

    // The ADC multiplexer Selection Register
    struct ADMUX {
        static const uint16_t address = 0x7c;
        enum bits : uint8_t {
            REFS0 = 64,  // Reference Selection Bits
            MUX0  = 1,   // Analog Channel Selection Bits
            MUX1  = 2,   // Analog Channel Selection Bits
            REFS1 = 128, // Reference Selection Bits
            MUX2  = 4,   // Analog Channel Selection Bits
            ADLAR = 32,  // Left Adjust Result
            MUX3  = 8,   // Analog Channel Selection Bits
        };
    };

    // ADC Data Register Bytes
    struct ADC {
        static const uint16_t address = 0x78;
        enum bits : uint8_t {
            ADC5 = 32,  // ADC Data bits
            ADC0 = 1,   // ADC Data bits
            ADC1 = 2,   // ADC Data bits
            ADC6 = 64,  // ADC Data bits
            ADC2 = 4,   // ADC Data bits
            ADC7 = 128, // ADC Data bits
            ADC3 = 8,   // ADC Data bits
            ADC4 = 16,  // ADC Data bits
        };
    };

    // The ADC Control and Status register A
    struct ADCSRA {
        static const uint16_t address = 0x7a;
        enum bits : uint8_t {
            ADEN  = 128, // ADC Enable
            ADPS0 = 1,   // ADC  Prescaler Select Bits
            ADPS1 = 2,   // ADC  Prescaler Select Bits
            ADSC  = 64,  // ADC Start Conversion
            ADPS2 = 4,   // ADC  Prescaler Select Bits
            ADATE = 32,  // ADC  Auto Trigger Enable
            ADIE  = 8,   // ADC Interrupt Enable
            ADIF  = 16,  // ADC Interrupt Flag
        };
    };

    // The ADC Control and Status register B
    struct ADCSRB {
        static const uint16_t address = 0x7b;
        enum bits : uint8_t {
            ACME  = 64, //
            ADTS0 = 1,  // ADC Auto Trigger Source bits
            ADTS1 = 2,  // ADC Auto Trigger Source bits
            ADTS2 = 4,  // ADC Auto Trigger Source bits
        };
    };

    // Digital Input Disable Register
    struct DIDR0 {
        static const uint16_t address = 0x7e;
        enum bits : uint8_t {
            ADC5D = 32, //
            ADC0D = 1,  //
            ADC1D = 2,  //
            ADC2D = 4,  //
            ADC3D = 8,  //
            ADC4D = 16, //
        };
    };

    // Analog Comparator Control And Status Register
    struct ACSR {
        static const uint16_t address = 0x50;
        enum bits : uint8_t {
            ACD   = 128, // Analog Comparator Disable
            ACO   = 32,  // Analog Compare Output
            ACBG  = 64,  // Analog Comparator Bandgap Select
            ACIS0 = 1,   // Analog Comparator Interrupt Mode Select bits
            ACIC  = 4,   // Analog Comparator Input Capture Enable
            ACIS1 = 2,   // Analog Comparator Interrupt Mode Select bits
            ACIE  = 8,   // Analog Comparator Interrupt Enable
            ACI   = 16,  // Analog Comparator Interrupt Flag
        };
    };

    // Digital Input Disable Register 1
    struct DIDR1 {
        static const uint16_t address = 0x7f;
        enum bits : uint8_t {
            AIN0D = 1, // AIN0 Digital Input Disable
            AIN1D = 2, // AIN1 Digital Input Disable
        };
    };

    // Port B Data Register
    struct PORTB {
        static const uint16_t address = 0x25;
    };

    // Port B Data Direction Register
    struct DDRB {
        static const uint16_t address = 0x24;
    };

    // Port B Input Pins
    struct PINB {
        static const uint16_t address = 0x23;
    };

    // Port C Data Register
    struct PORTC {
        static const uint16_t address = 0x28;
    };

    // Port C Data Direction Register
    struct DDRC {
        static const uint16_t address = 0x27;
    };

    // Port C Input Pins
    struct PINC {
        static const uint16_t address = 0x26;
    };

    // Port D Data Register
    struct PORTD {
        static const uint16_t address = 0x2b;
    };

    // Port D Data Direction Register
    struct DDRD {
        static const uint16_t address = 0x2a;
    };

    // Port D Input Pins
    struct PIND {
        static const uint16_t address = 0x29;
    };

    // Timer/Counter0 Output Compare Register
    struct OCR0B {
        static const uint16_t address = 0x48;
        enum bits : uint8_t {
            OCR0B5 = 32,  // Timer/Counter0 Output Compare B bits
            OCR0B0 = 1,   // Timer/Counter0 Output Compare B bits
            OCR0B1 = 2,   // Timer/Counter0 Output Compare B bits
            OCR0B6 = 64,  // Timer/Counter0 Output Compare B bits
            OCR0B2 = 4,   // Timer/Counter0 Output Compare B bits
            OCR0B7 = 128, // Timer/Counter0 Output Compare B bits
            OCR0B3 = 8,   // Timer/Counter0 Output Compare B bits
            OCR0B4 = 16,  // Timer/Counter0 Output Compare B bits
        };
    };

    // Timer/Counter0 Output Compare Register
    struct OCR0A {
        static const uint16_t address = 0x47;
        enum bits : uint8_t {
            OCR0A5 = 32,  // Timer/Counter0 Output Compare A bits
            OCR0A0 = 1,   // Timer/Counter0 Output Compare A bits
            OCR0A1 = 2,   // Timer/Counter0 Output Compare A bits
            OCR0A6 = 64,  // Timer/Counter0 Output Compare A bits
            OCR0A2 = 4,   // Timer/Counter0 Output Compare A bits
            OCR0A7 = 128, // Timer/Counter0 Output Compare A bits
            OCR0A3 = 8,   // Timer/Counter0 Output Compare A bits
            OCR0A4 = 16,  // Timer/Counter0 Output Compare A bits
        };
    };

    // Timer/Counter0
    struct TCNT0 {
        static const uint16_t address = 0x46;
        enum bits : uint8_t {
            TCNT05 = 32,  // Timer/Counter0 bits
            TCNT00 = 1,   // Timer/Counter0 bits
            TCNT01 = 2,   // Timer/Counter0 bits
            TCNT06 = 64,  // Timer/Counter0 bits
            TCNT02 = 4,   // Timer/Counter0 bits
            TCNT07 = 128, // Timer/Counter0 bits
            TCNT03 = 8,   // Timer/Counter0 bits
            TCNT04 = 16,  // Timer/Counter0 bits
        };
    };

    // Timer/Counter Control Register B
    struct TCCR0B {
        static const uint16_t address = 0x45;
        enum bits : uint8_t {
            FOC0B = 64,  // Force Output Compare B
            CS00  = 1,   // Clock Select
            CS01  = 2,   // Clock Select
            FOC0A = 128, // Force Output Compare A
            CS02  = 4,   // Clock Select
            WGM02 = 8,   //
        };
    };

    // Timer/Counter  Control Register A
    struct TCCR0A {
        static const uint16_t address = 0x44;
        enum bits : uint8_t {
            COM0B1 = 32,  // Compare Output Mode, Fast PWm
            WGM00  = 1,   // Waveform Generation Mode
            WGM01  = 2,   // Waveform Generation Mode
            COM0A0 = 64,  // Compare Output Mode, Phase Correct PWM Mode
            COM0A1 = 128, // Compare Output Mode, Phase Correct PWM Mode
            COM0B0 = 16,  // Compare Output Mode, Fast PWm
        };
    };

    // Timer/Counter0 Interrupt Mask Register
    struct TIMSK0 {
        static const uint16_t address = 0x6e;
        enum bits : uint8_t {
            TOIE0  = 1, // Timer/Counter0 Overflow Interrupt Enable
            OCIE0A = 2, // Timer/Counter0 Output Compare Match A Interrupt Enable
            OCIE0B = 4, // Timer/Counter0 Output Compare Match B Interrupt Enable
        };
    };

    // Timer/Counter0 Interrupt Flag register
    struct TIFR0 {
        static const uint16_t address = 0x35;
        enum bits : uint8_t {
            TOV0  = 1, // Timer/Counter0 Overflow Flag
            OCF0A = 2, // Timer/Counter0 Output Compare Flag 0A
            OCF0B = 4, // Timer/Counter0 Output Compare Flag 0B
        };
    };

    // External Interrupt Control Register
    struct EICRA {
        static const uint16_t address = 0x69;
        enum bits : uint8_t {
            ISC11 = 8, // External Interrupt Sense Control 1 Bits
            ISC00 = 1, // External Interrupt Sense Control 0 Bits
            ISC01 = 2, // External Interrupt Sense Control 0 Bits
            ISC10 = 4, // External Interrupt Sense Control 1 Bits
        };
    };

    // External Interrupt Mask Register
    struct EIMSK {
        static const uint16_t address = 0x3d;
        enum bits : uint8_t {
            INT0 = 1, // External Interrupt Request 1 Enable
            INT1 = 2, // External Interrupt Request 1 Enable
        };
    };

    // External Interrupt Flag Register
    struct EIFR {
        static const uint16_t address = 0x3c;
        enum bits : uint8_t {
            INTF0 = 1, // External Interrupt Flags
            INTF1 = 2, // External Interrupt Flags
        };
    };

    // Pin Change Interrupt Control Register
    struct PCICR {
        static const uint16_t address = 0x68;
        enum bits : uint8_t {
            PCIE0 = 1, // Pin Change Interrupt Enables
            PCIE1 = 2, // Pin Change Interrupt Enables
            PCIE2 = 4, // Pin Change Interrupt Enables
        };
    };

    // Pin Change Mask Register 2
    struct PCMSK2 {
        static const uint16_t address = 0x6d;
        enum bits : uint8_t {
            PCINT5 = 32,  // Pin Change Enable Masks
            PCINT0 = 1,   // Pin Change Enable Masks
            PCINT1 = 2,   // Pin Change Enable Masks
            PCINT6 = 64,  // Pin Change Enable Masks
            PCINT2 = 4,   // Pin Change Enable Masks
            PCINT7 = 128, // Pin Change Enable Masks
            PCINT3 = 8,   // Pin Change Enable Masks
            PCINT4 = 16,  // Pin Change Enable Masks
        };
    };

    // Pin Change Mask Register 1
    struct PCMSK1 {
        static const uint16_t address = 0x6c;
        enum bits : uint8_t {
            PCINT5 = 32, // Pin Change Enable Masks
            PCINT0 = 1,  // Pin Change Enable Masks
            PCINT1 = 2,  // Pin Change Enable Masks
            PCINT6 = 64, // Pin Change Enable Masks
            PCINT2 = 4,  // Pin Change Enable Masks
            PCINT3 = 8,  // Pin Change Enable Masks
            PCINT4 = 16, // Pin Change Enable Masks
        };
    };

    // Pin Change Mask Register 0
    struct PCMSK0 {
        static const uint16_t address = 0x6b;
        enum bits : uint8_t {
            PCINT5 = 32,  // Pin Change Enable Masks
            PCINT0 = 1,   // Pin Change Enable Masks
            PCINT1 = 2,   // Pin Change Enable Masks
            PCINT6 = 64,  // Pin Change Enable Masks
            PCINT2 = 4,   // Pin Change Enable Masks
            PCINT7 = 128, // Pin Change Enable Masks
            PCINT3 = 8,   // Pin Change Enable Masks
            PCINT4 = 16,  // Pin Change Enable Masks
        };
    };

    // Pin Change Interrupt Flag Register
    struct PCIFR {
        static const uint16_t address = 0x3b;
        enum bits : uint8_t {
            PCIF0 = 1, // Pin Change Interrupt Flags
            PCIF1 = 2, // Pin Change Interrupt Flags
            PCIF2 = 4, // Pin Change Interrupt Flags
        };
    };

    // SPI Data Register
    struct SPDR {
        static const uint16_t address = 0x4e;
        enum bits : uint8_t {
            SPDR5 = 32,  // SPI Data bits
            SPDR0 = 1,   // SPI Data bits
            SPDR1 = 2,   // SPI Data bits
            SPDR6 = 64,  // SPI Data bits
            SPDR2 = 4,   // SPI Data bits
            SPDR7 = 128, // SPI Data bits
            SPDR3 = 8,   // SPI Data bits
            SPDR4 = 16,  // SPI Data bits
        };
    };

    // SPI Status Register
    struct SPSR {
        static const uint16_t address = 0x4d;
        enum bits : uint8_t {
            WCOL  = 64,  // Write Collision Flag
            SPI2X = 1,   // Double SPI Speed Bit
            SPIF  = 128, // SPI Interrupt Flag
        };
    };

    // SPI Control Register
    struct SPCR {
        static const uint16_t address = 0x4c;
        enum bits : uint8_t {
            DORD = 32,  // Data Order
            SPE  = 64,  // SPI Enable
            SPIE = 128, // SPI Interrupt Enable
            SPR0 = 1,   // SPI Clock Rate Selects
            CPHA = 4,   // Clock Phase
            SPR1 = 2,   // SPI Clock Rate Selects
            CPOL = 8,   // Clock polarity
            MSTR = 16,  // Master/Slave Select
        };
    };

    // Watchdog Timer Control Register
    struct WDTCSR {
        static const uint16_t address = 0x60;
        enum bits : uint8_t {
            WDP3 = 32,  // Watchdog Timer Prescaler Bits
            WDP0 = 1,   // Watchdog Timer Prescaler Bits
            WDP1 = 2,   // Watchdog Timer Prescaler Bits
            WDIF = 128, // Watchdog Timeout Interrupt Flag
            WDP2 = 4,   // Watchdog Timer Prescaler Bits
            WDIE = 64,  // Watchdog Timeout Interrupt Enable
            WDE  = 8,   // Watch Dog Enable
            WDCE = 16,  // Watchdog Change Enable
        };
    };

    // EEPROM Address Register Bytes
    struct EEAR {
        static const uint16_t address = 0x41;
        enum bits : uint8_t {
            EEAR5 = 32,  // EEPROM Address Bits
            EEAR0 = 1,   // EEPROM Address Bits
            EEAR1 = 2,   // EEPROM Address Bits
            EEAR6 = 64,  // EEPROM Address Bits
            EEAR2 = 4,   // EEPROM Address Bits
            EEAR7 = 128, // EEPROM Address Bits
            EEAR3 = 8,   // EEPROM Address Bits
            EEAR4 = 16,  // EEPROM Address Bits
        };
    };

    // EEPROM Data Register
    struct EEDR {
        static const uint16_t address = 0x40;
        enum bits : uint8_t {
            EEDR5 = 32,  // EEPROM Data Bits
            EEDR0 = 1,   // EEPROM Data Bits
            EEDR1 = 2,   // EEPROM Data Bits
            EEDR6 = 64,  // EEPROM Data Bits
            EEDR2 = 4,   // EEPROM Data Bits
            EEDR7 = 128, // EEPROM Data Bits
            EEDR3 = 8,   // EEPROM Data Bits
            EEDR4 = 16,  // EEPROM Data Bits
        };
    };

    // EEPROM Control Register
    struct EECR {
        static const uint16_t address = 0x3f;
        enum bits : uint8_t {
            EEPM1 = 32, // EEPROM Programming Mode Bits
            EERE  = 1,  // EEPROM Read Enable
            EEPE  = 2,  // EEPROM Write Enable
            EEMPE = 4,  // EEPROM Master Write Enable
            EERIE = 8,  // EEPROM Ready Interrupt Enable
            EEPM0 = 16, // EEPROM Programming Mode Bits
        };
    };

    // Power Reduction Register
    struct PRR {
        static const uint16_t address = 0x64;
        enum bits : uint8_t {
            PRTIM2   = 64,  // Power Reduction Timer/Counter2
            PRADC    = 1,   // Power Reduction ADC
            PRTIM0   = 32,  // Power Reduction Timer/Counter0
            PRTWI    = 128, // Power Reduction TWI
            PRUSART0 = 2,   // Power Reduction USART
            PRSPI    = 4,   // Power Reduction Serial Peripheral Interface
            PRTIM1   = 8,   // Power Reduction Timer/Counter1
        };
    };

    // Oscillator Calibration Value
    struct OSCCAL {
        static const uint16_t address = 0x66;
        enum bits : uint8_t {
            OSCCAL5 = 32,  // Oscillator Calibration
            OSCCAL0 = 1,   // Oscillator Calibration
            OSCCAL1 = 2,   // Oscillator Calibration
            OSCCAL6 = 64,  // Oscillator Calibration
            OSCCAL2 = 4,   // Oscillator Calibration
            OSCCAL7 = 128, // Oscillator Calibration
            OSCCAL3 = 8,   // Oscillator Calibration
            OSCCAL4 = 16,  // Oscillator Calibration
        };
    };

    // Clock Prescale Register
    struct CLKPR {
        static const uint16_t address = 0x61;
        enum bits : uint8_t {
            CLKPCE = 128, // Clock Prescaler Change Enable
            CLKPS0 = 1,   // Clock Prescaler Select Bits
            CLKPS1 = 2,   // Clock Prescaler Select Bits
            CLKPS2 = 4,   // Clock Prescaler Select Bits
            CLKPS3 = 8,   // Clock Prescaler Select Bits
        };
    };

    // Status Register
    struct SREG {
        static const uint16_t address = 0x5f;
        enum bits : uint8_t {
            T = 64,  // Bit Copy Storage
            I = 128, // Global Interrupt Enable
            C = 1,   // Carry Flag
            H = 32,  // Half Carry Flag
            Z = 2,   // Zero Flag
            N = 4,   // Negative Flag
            V = 8,   // Two's Complement Overflow Flag
            S = 16,  // Sign Bit
        };
    };

    // Stack Pointer
    struct SP {
        static const uint16_t address = 0x5d;
    };

    // Store Program Memory Control and Status Register
    struct SPMCSR {
        static const uint16_t address = 0x57;
        enum bits : uint8_t {
            SPMIE  = 128, // SPM Interrupt Enable
            SPMEN  = 1,   // Store Program Memory
            PGERS  = 2,   // Page Erase
            RWWSB  = 64,  // Read-While-Write Section Busy
            PGWRT  = 4,   // Page Write
            SIGRD  = 32,  // Signature Row Read
            BLBSET = 8,   // Boot Lock Bit Set
            RWWSRE = 16,  // Read-While-Write section read enable
        };
    };

    // MCU Control Register
    struct MCUCR {
        static const uint16_t address = 0x55;
        enum bits : uint8_t {
            PUD   = 16, //
            IVCE  = 1,  //
            IVSEL = 2,  //
        };
    };

    // MCU Status Register
    struct MCUSR {
        static const uint16_t address = 0x54;
        enum bits : uint8_t {
            WDRF  = 8, // Watchdog Reset Flag
            PORF  = 1, // Power-on reset flag
            EXTRF = 2, // External Reset Flag
            BORF  = 4, // Brown-out Reset Flag
        };
    };

    // Sleep Mode Control Register
    struct SMCR {
        static const uint16_t address = 0x53;
        enum bits : uint8_t {
            SM2 = 8, // Sleep Mode Select Bits
            SE  = 1, // Sleep Enable
            SM0 = 2, // Sleep Mode Select Bits
            SM1 = 4, // Sleep Mode Select Bits
        };
    };

    // General Purpose I/O Register 2
    struct GPIOR2 {
        static const uint16_t address = 0x4b;
    };

    // General Purpose I/O Register 1
    struct GPIOR1 {
        static const uint16_t address = 0x4a;
    };

    // General Purpose I/O Register 0
    struct GPIOR0 {
        static const uint16_t address = 0x3e;
    };

}

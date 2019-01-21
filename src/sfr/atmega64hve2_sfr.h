#ifndef atmega64hve2_sfr_h
#define atmega64hve2_sfr_h

#include <stdint.h>

/*
Source            Atmel.ATmega_DFP.1.3.300.atpack
Family            megaAVR
Architecture      AVR8
Device name       ATmega64HVE2
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

    // Timer/Counter Interrupt Flag register
    struct TIFR0 {
        static const uint8_t address = 0x35;
        enum bits : uint8_t {
            TOV0  = 1, // Timer/Counter0 Overflow Flag
            OCF0A = 2, // Timer/Counter0 Output Compare Flag A
            OCF0B = 4, // Timer/Counter0 Output Compare Flag B
            ICF0  = 8, // Timer/Counter 0 Input Capture Flag
        };
    };

    // Timer/Counter Interrupt Flag register
    struct TIFR1 {
        static const uint8_t address = 0x36;
        enum bits : uint8_t {
            TOV1  = 1, // Timer/Counter1 Overflow Flag
            OCF1A = 2, // Timer/Counter1 Output Compare Flag A
            OCF1B = 4, // Timer/Counter1 Output Compare Flag B
            ICF1  = 8, // Timer/Counter 1 Input Capture Flag
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
            INTF0 = 1, // External Interrupt Flag 0
        };
    };

    // External Interrupt Mask Register
    struct EIMSK {
        static const uint8_t address = 0x3d;
        enum bits : uint8_t {
            INT0 = 1, // External Interrupt Request 0 Enable
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
            EEPE  = 2,  // EEPROM Write Enable
            EEMPE = 4,  // EEPROM Master Write Enable
            EERIE = 8,  // EEProm Ready Interrupt Enable
            EEPM0 = 16, //
            EEPM1 = 32, //
        };
    };

    // EEPROM Data Register
    struct EEDR {
        static const uint8_t address = 0x40;
    };

    // EEPROM Read/Write Access
    struct EEAR {
        static const uint16_t address = 0x41;
    };

    // General Timer/Counter Control Register
    struct GTCCR {
        static const uint8_t address = 0x43;
        enum bits : uint8_t {
            PSRSYNC = 1,   // Prescaler Reset
            TSM     = 128, // Timer/Counter Synchronization Mode
        };
    };

    // Timer/Counter 0 Control Register A
    struct TCCR0A {
        static const uint8_t address = 0x44;
        enum bits : uint8_t {
            WGM00 = 1,   // Waveform Generation Mode
            ICS0  = 8,   // Input Capture Select
            ICES0 = 16,  // Input Capture Edge Select
            ICNC0 = 32,  // Input Capture Noise Canceler
            ICEN0 = 64,  // Input Capture Mode Enable
            TCW0  = 128, // Timer/Counter Width
        };
    };

    // Timer/Counter0 Control Register B
    struct TCCR0B {
        static const uint8_t address = 0x45;
        enum bits : uint8_t {
            CS00 = 1, // Clock Select0 bit 0
            CS01 = 2, // Clock Select0 bit 1
            CS02 = 4, // Clock Select0 bit 2
        };
    };

    // Timer Counter 0  Bytes
    struct TCNT0 {
        static const uint16_t address = 0x46;
    };

    // Output Compare Register 0A
    struct OCR0A {
        static const uint8_t address = 0x48;
    };

    // Output Compare Register B
    struct OCR0B {
        static const uint8_t address = 0x49;
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
            BODRF = 4,  // Brown-out Reset Flag
            WDRF  = 8,  // Watchdog Reset Flag
            OCDRF = 16, // OCD Reset Flag
        };
    };

    // MCU Control Register
    struct MCUCR {
        static const uint8_t address = 0x55;
        enum bits : uint8_t {
            IVCE  = 1,  // Interrupt Vector Change Enable
            IVSEL = 2,  // Interrupt Vector Select
            PUD   = 16, // Pull-up disable
            CKOE  = 32, // Clock Output Enable
        };
    };

    // Store Program Memory Control and Status Register
    struct SPMCSR {
        static const uint8_t address = 0x57;
        enum bits : uint8_t {
            SPMEN  = 1,   // Store Program Memory Enable
            PGERS  = 2,   // Page Erase
            PGWRT  = 4,   // Page Write
            LBSET  = 8,   // Lock Bit Set
            RWWSRE = 16,  // Read-While-Write Section Read Enable
            SIGRD  = 32,  // Signature Row Read
            RWWSB  = 64,  // Read-While-Write Section Busy
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

    // Clock Prescale Register
    struct CLKPR {
        static const uint8_t address = 0x61;
        enum bits : uint8_t {
            CLKPS0 = 1,   // Clock Prescaler Select Bits
            CLKPS1 = 2,   // Clock Prescaler Select Bits
            CLKPCE = 128, // Clock Prescaler Change Enable
        };
    };

    // Wake-up Timer Control and Status Register
    struct WUTCSR {
        static const uint8_t address = 0x62;
        enum bits : uint8_t {
            WUTP0 = 1,   // Wake-up Timer Prescaler Bits
            WUTP1 = 2,   // Wake-up Timer Prescaler Bits
            WUTP2 = 4,   // Wake-up Timer Prescaler Bits
            WUTE  = 8,   // Wake-up Timer Enable
            WUTR  = 16,  // Wake-up Timer Reset
            WUTIE = 64,  // Wake-up Timer Interrupt Enable
            WUTIF = 128, // Wake-up Timer Interrupt Flag
        };
    };

    // Watchdog Timer Configuration Lock Register
    struct WDTCLR {
        static const uint8_t address = 0x63;
        enum bits : uint8_t {
            WDCLE = 1, // Watchdog Timer Comfiguration Lock Enable
            WDCL0 = 2, // Watchdog Timer Comfiguration Lock bits
            WDCL1 = 4, // Watchdog Timer Comfiguration Lock bits
        };
    };

    // Power Reduction Register 0
    struct PRR0 {
        static const uint8_t address = 0x64;
        enum bits : uint8_t {
            PRTIM0 = 1, // Power Reduction Timer/Counter0
            PRTIM1 = 2, // Power Reduction Timer/Counter1
            PRSPI  = 4, // Power reduction SPI
            PRLIN  = 8, // Power Reduction LIN UART Interface
        };
    };

    // Slow Oscillator Calibration Register A
    struct SOSCCALA {
        static const uint8_t address = 0x66;
    };

    // Oscillator Calibration Register B
    struct SOSCCALB {
        static const uint8_t address = 0x67;
    };

    // Pin Change Interrupt Control Register
    struct PCICR {
        static const uint8_t address = 0x68;
        enum bits : uint8_t {
            PCIE0 = 1, // Pin Change Interrupt Enables
            PCIE1 = 2, // Pin Change Interrupt Enables
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

    // Pin Change Enable Mask Register 0
    struct PCMSK0 {
        static const uint8_t address = 0x6b;
    };

    // Pin Change Enable Mask Register 1
    struct PCMSK1 {
        static const uint8_t address = 0x6c;
    };

    // Timer/Counter Interrupt Mask Register
    struct TIMSK0 {
        static const uint8_t address = 0x6e;
        enum bits : uint8_t {
            TOIE0  = 1, // Timer/Counter0 Overflow Interrupt Enable
            OCIE0A = 2, // Timer/Counter0 Output Compare A Interrupt Enable
            OCIE0B = 4, // Timer/Counter0 Output Compare B Interrupt Enable
            ICIE0  = 8, // Timer/Counter n Input Capture Interrupt Enable
        };
    };

    // Timer/Counter Interrupt Mask Register
    struct TIMSK1 {
        static const uint8_t address = 0x6f;
        enum bits : uint8_t {
            TOIE1  = 1, // Timer/Counter1 Overflow Interrupt Enable
            OCIE1A = 2, // Timer/Counter1 Output Compare A Interrupt Enable
            OCIE1B = 4, // Timer/Counter1 Output Compare B Interrupt Enable
            ICIE1  = 8, // Timer/Counter n Input Capture Interrupt Enable
        };
    };

    // Digital Input Disable Register
    struct DIDR0 {
        static const uint8_t address = 0x7e;
        enum bits : uint8_t {
            PA0DID = 1, // When this bit is written logic one, the digital input buffer of the corresponding V_ADC pin is disabled.
            PA1DID = 2, // When this bit is written logic one, the digital input buffer of the corresponding V_ADC pin is disabled.
        };
    };

    // Timer/Counter 1 Control Register A
    struct TCCR1A {
        static const uint8_t address = 0x80;
        enum bits : uint8_t {
            WGM10 = 1,   // Waveform Generation Mode
            ICS1  = 8,   // Input Capture Select
            ICES1 = 16,  // Input Capture Edge Select
            ICNC1 = 32,  // Input Capture Noise Canceler
            ICEN1 = 64,  // Input Capture Mode Enable
            TCW1  = 128, // Timer/Counter Width
        };
    };

    // Timer/Counter1 Control Register B
    struct TCCR1B {
        static const uint8_t address = 0x81;
        enum bits : uint8_t {
            CS0 = 1, // Clock Select1 bis
            CS1 = 2, // Clock Select1 bis
            CS2 = 4, // Clock Select1 bis
        };
    };

    // Timer Counter 1  Bytes
    struct TCNT1 {
        static const uint16_t address = 0x84;
    };

    // Output Compare Register 1A
    struct OCR1A {
        static const uint8_t address = 0x88;
    };

    // Output Compare Register B
    struct OCR1B {
        static const uint8_t address = 0x89;
    };

    // LIN Control Register
    struct LINCR {
        static const uint8_t address = 0xc0;
        enum bits : uint8_t {
            LCMD0  = 1,   // LIN Command and Mode bits
            LCMD1  = 2,   // LIN Command and Mode bits
            LCMD2  = 4,   // LIN Command and Mode bits
            LENA   = 8,   // LIN or UART Enable
            LCONF0 = 16,  // LIN Configuration bits
            LCONF1 = 32,  // LIN Configuration bits
            LIN13  = 64,  // LIN Standard
            LSWRES = 128, // Software Reset
        };
    };

    // LIN Status and Interrupt Register
    struct LINSIR {
        static const uint8_t address = 0xc1;
        enum bits : uint8_t {
            LRXOK  = 1,   // Receive Performed Interrupt
            LTXOK  = 2,   // Transmit Performed Interrupt
            LIDOK  = 4,   // Identifier Interrupt
            LERR   = 8,   // Error Interrupt
            LBUSY  = 16,  // Busy Signal
            LIDST0 = 32,  // Identifier Status bits
            LIDST1 = 64,  // Identifier Status bits
            LIDST2 = 128, // Identifier Status bits
        };
    };

    // LIN Enable Interrupt Register
    struct LINENIR {
        static const uint8_t address = 0xc2;
        enum bits : uint8_t {
            LENRXOK = 1, // Enable Receive Performed Interrupt
            LENTXOK = 2, // Enable Transmit Performed Interrupt
            LENIDOK = 4, // Enable Identifier Interrupt
            LENERR  = 8, // Enable Error Interrupt
        };
    };

    // LIN Error Register
    struct LINERR {
        static const uint8_t address = 0xc3;
        enum bits : uint8_t {
            LBERR  = 1,   // Bit Error Flag
            LCERR  = 2,   // Checksum Error Flag
            LPERR  = 4,   // Parity Error Flag
            LSERR  = 8,   // Synchronization Error Flag
            LFERR  = 16,  // Framing Error Flag
            LOVERR = 32,  // Overrun Error Flag
            LTOERR = 64,  // Frame Time Out Error Flag
            LABORT = 128, // Abort Flag
        };
    };

    // LIN Bit Timing Register
    struct LINBTR {
        static const uint8_t address = 0xc4;
        enum bits : uint8_t {
            LBT0  = 1,   // LIN Bit Timing bits
            LBT1  = 2,   // LIN Bit Timing bits
            LBT2  = 4,   // LIN Bit Timing bits
            LBT3  = 8,   // LIN Bit Timing bits
            LBT4  = 16,  // LIN Bit Timing bits
            LBT5  = 32,  // LIN Bit Timing bits
            LDISR = 128, // Disable Bit Timing Resynchronization
        };
    };

    // LIN Baud Rate Low Register
    struct LINBRRL {
        static const uint8_t address = 0xc5;
        enum bits : uint8_t {
            LDIV0 = 1,   //
            LDIV1 = 2,   //
            LDIV2 = 4,   //
            LDIV3 = 8,   //
            LDIV4 = 16,  //
            LDIV5 = 32,  //
            LDIV6 = 64,  //
            LDIV7 = 128, //
        };
    };

    // LIN Baud Rate High Register
    struct LINBRRH {
        static const uint8_t address = 0xc6;
        enum bits : uint8_t {
            LDIV0 = 1, //
            LDIV1 = 2, //
            LDIV2 = 4, //
            LDIV3 = 8, //
        };
    };

    // LIN Data Length Register
    struct LINDLR {
        static const uint8_t address = 0xc7;
        enum bits : uint8_t {
            LRXDL0 = 1,   // LIN Receive Data Length bits
            LRXDL1 = 2,   // LIN Receive Data Length bits
            LRXDL2 = 4,   // LIN Receive Data Length bits
            LRXDL3 = 8,   // LIN Receive Data Length bits
            LTXDL0 = 16,  // LIN Transmit Data Length bits
            LTXDL1 = 32,  // LIN Transmit Data Length bits
            LTXDL2 = 64,  // LIN Transmit Data Length bits
            LTXDL3 = 128, // LIN Transmit Data Length bits
        };
    };

    // LIN Identifier Register
    struct LINIDR {
        static const uint8_t address = 0xc8;
        enum bits : uint8_t {
            LID0 = 1,   // Identifier bit 5 or Data Length bits
            LID1 = 2,   // Identifier bit 5 or Data Length bits
            LID2 = 4,   // Identifier bit 5 or Data Length bits
            LID3 = 8,   // Identifier bit 5 or Data Length bits
            LID4 = 16,  // Identifier bit 5 or Data Length bits
            LID5 = 32,  // Identifier bit 5 or Data Length bits
            LP0  = 64,  // Parity bits
            LP1  = 128, // Parity bits
        };
    };

    // LIN Data Buffer Selection Register
    struct LINSEL {
        static const uint8_t address = 0xc9;
        enum bits : uint8_t {
            LINDX0 = 1, // FIFO LIN Data Buffer Index bits
            LINDX1 = 2, // FIFO LIN Data Buffer Index bits
            LINDX2 = 4, // FIFO LIN Data Buffer Index bits
            LAINC  = 8, // Auto Increment of Data Buffer Index (Active Low)
        };
    };

    // LIN Data Register
    struct LINDAT {
        static const uint8_t address = 0xca;
        enum bits : uint8_t {
            LDATA0 = 1,   //
            LDATA1 = 2,   //
            LDATA2 = 4,   //
            LDATA3 = 8,   //
            LDATA4 = 16,  //
            LDATA5 = 32,  //
            LDATA6 = 64,  //
            LDATA7 = 128, //
        };
    };

    // Bandgap Control and Status Register A
    struct BGCSRA {
        static const uint8_t address = 0xd1;
        enum bits : uint8_t {
            BGSC0 = 1, // Band Gap Sample Configuration
            BGSC1 = 2, // Band Gap Sample Configuration
            BGSC2 = 4, // Band Gap Sample Configuration
        };
    };

    // Band Gap Calibration Register B
    struct BGCRB {
        static const uint8_t address = 0xd2;
        enum bits : uint8_t {
            BGCL0 = 1,   // Band Gap Calibration Linear
            BGCL1 = 2,   // Band Gap Calibration Linear
            BGCL2 = 4,   // Band Gap Calibration Linear
            BGCL3 = 8,   // Band Gap Calibration Linear
            BGCL4 = 16,  // Band Gap Calibration Linear
            BGCL5 = 32,  // Band Gap Calibration Linear
            BGCL6 = 64,  // Band Gap Calibration Linear
            BGCL7 = 128, // Band Gap Calibration Linear
        };
    };

    // Band Gap Calibration Register A
    struct BGCRA {
        static const uint8_t address = 0xd3;
        enum bits : uint8_t {
            BGCN0 = 1,   // Band Gap Calibration Nominal
            BGCN1 = 2,   // Band Gap Calibration Nominal
            BGCN2 = 4,   // Band Gap Calibration Nominal
            BGCN3 = 8,   // Band Gap Calibration Nominal
            BGCN4 = 16,  // Band Gap Calibration Nominal
            BGCN5 = 32,  // Band Gap Calibration Nominal
            BGCN6 = 64,  // Band Gap Calibration Nominal
            BGCN7 = 128, // Band Gap Calibration Nominal
        };
    };

    // Band Gap Lock Register
    struct BGLR {
        static const uint8_t address = 0xd4;
        enum bits : uint8_t {
            BGPL  = 1, // Band Gap Lock
            BGPLE = 2, // Band Gap Lock Enable
        };
    };

    // PLL Control and Status Register
    struct PLLCSR {
        static const uint8_t address = 0xd8;
        enum bits : uint8_t {
            PLLCIE = 1,  // PLL Lock Change Interrupt Enable
            PLLCIF = 2,  // PLL Lock Change Interrupt Flag
            LOCK   = 16, // PLL Lock
            SWEN   = 32, // PLL Software Enable
        };
    };

    // Port B Override
    struct PBOV {
        static const uint8_t address = 0xdc;
        enum bits : uint8_t {
            PBOE0  = 1,   // Port B Override Enable 0
            PBOE3  = 8,   // Port B Override Enable 3
            PBOVCE = 128, // Port B Override Change Enable
        };
    };

    // ADC Synchronization Control and Status Register
    struct ADSCSRA {
        static const uint8_t address = 0xe0;
        enum bits : uint8_t {
            SCMD0 = 1, // Synchronization Command
            SCMD1 = 2, // Synchronization Command
            SBSY  = 4, // Synchronization Busy
        };
    };

    // ADC Synchronization Control and Status Register
    struct ADSCSRB {
        static const uint8_t address = 0xe1;
        enum bits : uint8_t {
            CADICRB = 1,  // CADIC Data Read Out Busy
            CADACRB = 2,  // CADAC Data Read Out Busy
            CADICPS = 4,  // C-ADC Instantaneous Conversion Polarity Status
            VADICRB = 16, // VADIC Data Read Out Busy
            VADACRB = 32, // VADAC Data Read Out Busy
            VADICPS = 64, // V-ADC Instantaneous Conversion Polarity Status
        };
    };

    // ADC Control Register A
    struct ADCRA {
        static const uint8_t address = 0xe2;
        enum bits : uint8_t {
            CKSEL  = 1, // Sampling Clock Select
            ADCMS0 = 2, // C-ADC Chopper Mode Select
            ADCMS1 = 4, // C-ADC Chopper Mode Select
            ADPSEL = 8, // ADC Polarity Select
        };
    };

    // ADC Control Register B
    struct ADCRB {
        static const uint8_t address = 0xe3;
        enum bits : uint8_t {
            ADADES0 = 1,  // Accumulated Decimation Ratio Select
            ADADES1 = 2,  // Accumulated Decimation Ratio Select
            ADADES2 = 4,  // Accumulated Decimation Ratio Select
            ADIDES0 = 8,  // Instantaneous Decimation Ratio Select
            ADIDES1 = 16, // Instantaneous Decimation Ratio Select
        };
    };

    // ADC Control Register B
    struct ADCRC {
        static const uint8_t address = 0xe4;
        enum bits : uint8_t {
            CADRCT0 = 1,   // C-ADC Regular Current Count Threshold
            CADRCT1 = 2,   // C-ADC Regular Current Count Threshold
            CADRCT2 = 4,   // C-ADC Regular Current Count Threshold
            CADRCT3 = 8,   // C-ADC Regular Current Count Threshold
            CADRCM0 = 16,  // C-ADC Regular Current Comparator Mode
            CADRCM1 = 32,  // C-ADC Regular Current Comparator Mode
            CADEN   = 128, // C-ADC Enable
        };
    };

    // ADC Control Register D
    struct ADCRD {
        static const uint8_t address = 0xe5;
        enum bits : uint8_t {
            CADDSEL = 1,  // C-ADC Diagnostics Channel Select
            CADPDM0 = 2,  // C-ADC Pin Diagnostics Mode
            CADPDM1 = 4,  // C-ADC Pin Diagnostics Mode
            CADG0   = 8,  // C-ADC Gain
            CADG1   = 16, // C-ADC Gain
            CADG2   = 32, // C-ADC Gain
        };
    };

    // ADC Control Register E
    struct ADCRE {
        static const uint8_t address = 0xe6;
        enum bits : uint8_t {
            VADMUX0 = 1,   // V-ADC Channel Select
            VADMUX1 = 2,   // V-ADC Channel Select
            VADMUX2 = 4,   // V-ADC Channel Select
            VADPDM0 = 8,   // V-ADC Pin Diagnostics Mode
            VADPDM1 = 16,  // V-ADC Pin Diagnostics Mode
            VADREFS = 32,  // V-ADC Reference Select
            VADEN   = 128, // V-ADC Enable
        };
    };

    // ADC Interrupt Flag Register
    struct ADIFR {
        static const uint8_t address = 0xe7;
        enum bits : uint8_t {
            CADICIF = 1,  // C-ADC Instantaneous Current Interrupt Flag
            CADACIF = 2,  // C-ADC Accumulated Current Interrupt Flag
            CADRCIF = 4,  // C-ADC Regulator Current Interrupt Flag
            VADICIF = 16, // V-DAC Instantaneous Voltage Interrupt Flag
            VADACIF = 32, // V-ADC Accumulated Voltage Interrupt Flag
        };
    };

    // ADC Interrupt Mask Register
    struct ADIMR {
        static const uint8_t address = 0xe8;
        enum bits : uint8_t {
            CADICIE = 1,  // C-ADC Instantaneous Current Interrupt Enable
            CADACIE = 2,  // C-ADC Accumulated Current Interrupt Enable
            CADRCIE = 4,  // C-ADC Regulator Current Interrupt Enable
            VADICIE = 16, // V-DAC Instantaneous Voltage Interrupt Enable
            VADACIE = 32, // V-ADC Accumulated Voltage Interrupt Enable
        };
    };

    // CC-ADC Regulator Current Comparator Threshold Level
    struct CADRCL {
        static const uint16_t address = 0xe9;
    };

    // C-ADC Instantaneous Conversion Result
    struct CADIC {
        static const uint16_t address = 0xeb;
    };

    // C-ADC Accumulated Conversion Result
    struct CADAC0 {
        static const uint8_t address = 0xed;
    };

    // C-ADC Accumulated Conversion Result
    struct CADAC1 {
        static const uint8_t address = 0xee;
    };

    // C-ADC Accumulated Conversion Result
    struct CADAC2 {
        static const uint8_t address = 0xef;
    };

    // C-ADC Accumulated Conversion Result
    struct CADAC3 {
        static const uint8_t address = 0xf0;
    };

    // V-ADC Instantaneous Conversion Result
    struct VADIC {
        static const uint16_t address = 0xf1;
    };

    // V-ADC Accumulated Conversion Result
    struct VADAC0 {
        static const uint8_t address = 0xf3;
    };

    // V-ADC Accumulated Conversion Result
    struct VADAC1 {
        static const uint8_t address = 0xf4;
    };

    // V-ADC Accumulated Conversion Result
    struct VADAC2 {
        static const uint8_t address = 0xf5;
    };

    // V-ADC Accumulated Conversion Result
    struct VADAC3 {
        static const uint8_t address = 0xf6;
    };

}

#endif
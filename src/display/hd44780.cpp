#include "hd44780.h"

#include <avr/io.h>
#include <util/delay.h>

#define RS_PIN PA0
#define RS_PORT PORTA
#define RS_DDR DDRA
#define RW_PIN PA1
#define RW_PORT PORTA
#define RW_DDR DDRA
#define ENABLE_PIN PA2
#define ENABLE_PORT PORTA
#define ENABLE_DDR DDRA
#define DATA_DDR DDRC

#define RS_HIGH RS_PORT |= (1 << RS_PIN)
#define RS_LOW RS_PORT &= ~(1 << RS_PIN)

#define RW_HIGH RW_PORT |= (1 << RW_PIN)
#define RW_LOW RW_PORT &= ~(1 << RW_PIN)

#define ENABLE_HIGH ENABLE_PORT |= (1 << ENABLE_PIN)
#define ENABLE_LOW ENABLE_PORT &= ~(1 << ENABLE_PIN)

// DB7 high and DB0..DB6 low, represents busy flag.
static const uint8_t IS_BUSY = 0x80;

// Tested with 2x16 and 4x20 displays.
static const uint8_t LINE_1_ADDRESS = 0x00;
static const uint8_t LINE_2_ADDRESS = 0x40;
static const uint8_t LINE_3_ADDRESS = 0x14;
static const uint8_t LINE_4_ADDRESS = 0x54;

static inline void
data_dir_out(void)
{
    DATA_DDR = 255;
}

static inline void
data_dir_in(void)
{
    DATA_DDR = 0;
}

static inline void
enable_high(void)
{
    ENABLE_HIGH;
    _delay_us(100);
}

static inline void
enable_low(void)
{
    ENABLE_LOW;
    _delay_us(200);
}

// Refer to page 45 for initializaton details in datasheet.
void
LCD_HD44780::init(void)
{
    data_dir_out();
    ENABLE_DDR |= 1 << ENABLE_PIN;
    RW_DDR |= 1 << RW_PIN;
    RS_DDR |= 1 << RS_PIN;

    _delay_ms(15);
    // For some unknown reason, all stages are not required.
    // With winstar WEH oled displays, third stage caused weird characters
    // to be displayed, when initialized more than once without power cycle.

    // Regular stages found in others code.
    // const uint8_t INIT_8_BIT = 0x30;
    // enable_high();
    // PORTC = INIT_8_BIT;
    // enable_low();
    // _delay_ms(5);

    // enable_high();
    // PORTC = INIT_8_BIT;
    // enable_low();
    // _delay_us(100);

    command(FUNCTION_SET | FUNCTION_8_BIT | FUNCTION_2_LINES | FUNCTION_5x8);
    command(DISPLAY_CONTROLL | DISPLAY_ON);
    command(CLEAR_SCREEN);
    command(ENTRY_MODE | ENTRY_CURSOR_RIGHT);
}

void
LCD_HD44780::command(enum COMMAND cmd)
{
    RS_LOW;
    LCD_HD44780::write(cmd);
}

void
LCD_HD44780::command(uint8_t cmd)
{
    RS_LOW;
    LCD_HD44780::write(cmd);
}

void
LCD_HD44780::write(uint8_t data)
{
    RS_HIGH;
    data_dir_out();
    RW_LOW;
    enable_high();
    PORTC = data;
    enable_low();
    wait_untill_ready();
}

void
LCD_HD44780::write(const char * str)
{
    char character;
    while ((character = *(str++))) {
        write(character);
    };
}

void
LCD_HD44780::move_cursor(uint8_t line, uint8_t collumn)
{
    switch (line) {
        case 0:
            line = LINE_1_ADDRESS;
            break;
        case 1:
            line = LINE_2_ADDRESS;
            break;
        case 2:
            line = LINE_3_ADDRESS;
            break;
        case 3:
            line = LINE_4_ADDRESS;
            break;
    }
    command((SET_DDRAM_ADDRESS + line + collumn));
}

uint8_t
LCD_HD44780::read(void)
{
    data_dir_in();
    RW_HIGH;
    enable_high();
    uint8_t result = PINC;
    enable_low();
    return result;
}

inline void
LCD_HD44780::wait_untill_ready(void)
{
    RS_LOW;
    while ((read() & IS_BUSY)) {
    };
}
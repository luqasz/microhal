#include <gpio.h>
#include <printer.h>
#include <spi.h>
#include <stdio.h>
#include <usart.h>
#include <util/delay.h>

void
send_bit(const GPIO::Pin pin, const uint8_t bit)
{
    // bit 0 400ns H, 800ns L
    // bit 1 850ns H, 450ns L
    GPIO::write(pin, GPIO::High);
    asm("nop");
    asm("nop");
    asm("nop");
    if (bit == 0)
        GPIO::write(pin, GPIO::Low);
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    GPIO::write(pin, GPIO::Low);
    asm("nop");
    asm("nop");
}

void
send(const GPIO::Pin pin, const uint8_t r, const uint8_t g, const uint8_t b)
{
    // G
    uint8_t i = 128;
    while (i > 0) {
        if ((g & i) == 0)
            send_bit(pin, 0);
        else
            send_bit(pin, 1);
        i = static_cast<uint8_t>(i >> 1);
    }
    // R
    i = 128;
    while (i > 0) {
        if ((r & i) == 0)
            send_bit(pin, 0);
        else
            send_bit(pin, 1);
        i = static_cast<uint8_t>(i >> 1);
    }
    // B
    i = 128;
    while (i > 0) {
        if ((b & i) == 0)
            send_bit(pin, 0);
        else
            send_bit(pin, 1);
        i = static_cast<uint8_t>(i >> 1);
    }
}

int
main(void)
{
    auto    pin  = GPIO::PC0;
    uint8_t leds = 8 * 8;
    while (leds) {
        send(pin, 0, 0, 32);
        leds--;
        _delay_us(50);
    }
}

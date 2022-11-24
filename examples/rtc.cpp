#include <datetime.hpp>
#include <drivers/ds1337.hpp>
#include <i2c.hpp>
#include <irq.hpp>
#include <printer.hpp>
#include <sfr.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>
#include <units.hpp>

constexpr units::Frequency fcpu = units::Hz * 11059200;
constexpr auto             baud = USART::baud_rate_async<fcpu, 115200, 2>();

constexpr auto config = USART::Config {
    .char_size = USART::CharacterSize::Bit8,
    .parity    = USART::Parity::None,
    .stop_bits = USART::StopBits::One,
};

constexpr auto rtc_target = i2c::Target {
    .address       = ds1337::I2C_ADDRESS,
    .start_address = u8(ds1337::REGISTER::SECONDS),
    .speed         = units::kHz * 400,
};

using USART_0 = USART::Async<USART::usart0>;

int
main()
{
    u8   rtc_buffer[ds1337::DATE_TIME_BUFFER_SIZE] = { 0 };
    auto usart                                     = USART_0().set(config);
    usart.set(baud);
    usart.enable_tx();
    auto serial = Printer(usart, LineEnd::CRLF);
    auto bus    = i2c::Master<i2c::i2c0>(fcpu);
    auto dt     = DateTime {
            .second = 50,
            .minute = 59,
            .hour   = 23,
            .day    = 30,
            .month  = 11,
            .year   = 2019,
    };

    serial.printLn("Setting date and time.");
    ds1337::set(dt, rtc_buffer);
    bus.write(rtc_buffer, rtc_target);
    char strbuf[30];
    while (true) {
        bus.read(rtc_buffer, rtc_target);
        ds1337::get(dt, rtc_buffer);
        snprintf(strbuf, 30, "%d.%d.%d %d:%d", dt.year, dt.month, dt.hour, dt.minute, dt.second);
        serial.printLn(strbuf);
        _delay_ms(1000);
    }
}

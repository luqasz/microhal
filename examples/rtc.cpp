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

auto constexpr fcpu = 11059200_Hz;
auto constexpr baud = USART::get_baud(fcpu, 115200, 2);
static_assert(baud.is_ok, "Calculated error rate too high");
auto usart  = USART::Async<USART::USART0>();
auto serial = Printer(usart, LineEnd::CRLF);

int
main(void)
{
    IRQ::enable();
    usart.set(baud);
    usart.enable(USART::Channel::TX);
    auto bus     = i2c::Master(fcpu);
    auto rtc     = DS1337(bus);
    auto dt      = DateTime {};
    dt.year      = 2019;
    dt.month     = 11;
    dt.month_day = 30;
    dt.hour      = 23;
    dt.minute    = 59;
    dt.second    = 50;
    serial.printLn("Setting date and time.");
    rtc.setDateTime(dt);
    char buf[30];
    while (true) {
        rtc.getDateTime(dt);
        sprintf(buf, "%d.%d.%d %d:%d:%d", dt.year, dt.month, dt.month_day, dt.hour, dt.minute, dt.second);
        serial.printLn(buf);
        _delay_ms(1000);
    }
}

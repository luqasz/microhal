#include <buffer.hpp>
#include <gpio.hpp>
#include <irq.hpp>
#include <drivers/mcp4xxx.hpp>
#include <printer.hpp>
#include <sfr.hpp>
#include <spi.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>

constexpr units::Frequency fcpu = units::Hz * 11059200;
constexpr auto             baud = USART::baud_rate_async<fcpu, 115200, 2>();

using USART_0 = USART::Async<USART::usart0>;

auto constexpr target = spi::Target {
    spi::Order::MSB,
    spi::Mode::m0,
    spi::MasterClock::_2,
};

constexpr auto ctrl_bits = mcp4xxx::CtrllBits {
    .ch    = mcp4xxx::A,
    .buf   = mcp4xxx::Buffered,
    .gain  = mcp4xxx::x1,
    .state = mcp4xxx::On,
};

template <typename SENDER>
void
send(SENDER spi, u16 value, const gpio::Output cs)
{

    const u16 data      = mcp4xxx::cmd<12>(ctrl_bits, value);
    u8        buffer[2] = {
        static_cast<u8>(data >> 8),
        static_cast<u8>(data),
    };
    cs = gpio::Low;
    spi.communicate(buffer, target);
    cs = gpio::High;
}

int
main(void)
{
    auto usart = USART_0();
    usart.set(baud);
    usart.enable_tx();
    auto serial = Printer(usart, LineEnd::CRLF);
    auto spi    = spi::Master<spi::spi0>(gpio::PB5, gpio::PB6, gpio::PB7);
    spi.enable();
    auto DAC_CS = gpio::Output(gpio::PB4).set(gpio::High);
    IRQ::enable();
    serial.printLn("Sending bytes over SPI");
    while (true) {
        send(spi, 4095, DAC_CS);
        send(spi, 1, DAC_CS);
    }
}

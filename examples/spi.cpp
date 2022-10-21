#include <buffer.hpp>
#include <gpio.hpp>
#include <irq.hpp>
#include <drivers/mcp49xx.hpp>
#include <printer.hpp>
#include <sfr.hpp>
#include <spi.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>

auto constexpr baud = USART::get_baud(11059200_Hz, 115200, 2);
static_assert(baud.is_ok, "Calculated error rate too high");

using USART_0 = USART::Async<USART::usart0>;

auto constexpr target = spi::Target {
    spi::Order::MSB,
    spi::Mode::m0,
    spi::MasterClock::_2,
};

template <typename SENDER, typename DAC>
void
send(SENDER spi, DAC dac, uint16_t value, const gpio::Output cs)
{
    auto buffer = buffer::Array<u8, 2>();
    dac         = value;
    buffer[0]   = static_cast<uint8_t>(dac.bits >> 8);
    buffer[1]   = static_cast<uint8_t>(dac.bits);
    cs          = gpio::Low;
    spi.communicate(buffer.whole(), target);
    cs = gpio::High;
}

int
main(void)
{
    auto usart = USART_0();
    usart.set(baud);
    usart.enable_tx();
    auto serial = Printer(usart, LineEnd::CRLF);
    auto spi    = spi::Master(spi::Instance::SPI0, spi::SPI0_MOSI, spi::SPI0_MISO, spi::SPI0_SCK);
    spi.enable();
    auto DAC_CS = gpio::Output(spi::SPI0_SS).set(gpio::High);
    auto dac    = MCP49x2::MCP4922(MCP49x2::Channel::A);
    dac.set(MCP49x2::Gain::x1);
    dac.set(MCP49x2::BufferControl::Unbuffered);
    IRQ::enable();
    serial.printLn("Sending bytes over SPI");
    while (true) {
        send(spi, dac, 4095, DAC_CS);
        send(spi, dac, 1, DAC_CS);
    }
}

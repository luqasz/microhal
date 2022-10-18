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
auto usart  = USART::Async<USART::USART0>();
auto serial = Printer(usart, LineEnd::CRLF);

auto constexpr target = SPI::Target {
    SPI::Order::MSB,
    SPI::Mode::m0,
    SPI::MasterClock::_2,
};

template <typename SENDER, typename DAC>
void
send(SENDER spi, DAC dac, uint16_t value, const gpio::Output cs)
{
    auto buffer = buffer::SizedBytesArray<2>();
    dac         = value;
    buffer[0]   = static_cast<uint8_t>(dac.bits >> 8);
    buffer[1]   = static_cast<uint8_t>(dac.bits);
    cs          = gpio::Off;
    spi.communicate(buffer, target);
    cs = gpio::On;
}

int
main(void)
{
    auto spi = SPI::Master(SPI::Instance::SPI0, SPI::SPI0_MOSI, SPI::SPI0_MISO, SPI::SPI0_SCK);
    spi.enable();
    auto DAC_CS = gpio::Output(SPI::SPI0_SS, gpio::Low);
    DAC_CS      = gpio::High;
    auto dac    = MCP49x2::MCP4922(MCP49x2::Channel::A);
    dac.set(MCP49x2::Gain::x1);
    dac.set(MCP49x2::BufferControl::Unbuffered);
    IRQ::enable();
    usart.set(baud);
    usart.enable(USART::Channel::TX);
    serial.printLn("Sending bytes over SPI");
    while (true) {
        send(spi, dac, 4095, DAC_CS);
        send(spi, dac, 1, DAC_CS);
    }
}

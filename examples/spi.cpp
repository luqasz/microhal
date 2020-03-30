#include <buffer.h>
#include <gpio.h>
#include <irq.h>
#include <mcp49xx.h>
#include <printer.h>
#include <sfr.h>
#include <spi.h>
#include <stdio.h>
#include <units.h>
#include <usart.h>
#include <util/delay.h>

auto constexpr baud = USART::get_baud(11059200_Hz, 115200, 2);
static_assert(baud.is_ok, "Calculated error rate too high");
auto usart  = USART::Async<USART::USART0>();
auto serial = Printer<USART::Async<USART::USART0>, RN>(usart);

template <typename SENDER, typename DAC>
void
send(SENDER spi, DAC dac, uint16_t value)
{
    auto buffer = Buffer::SizedBytesArray<2>();
    dac         = value;
    buffer[0]   = static_cast<uint8_t>(dac.bits >> 8);
    buffer[1]   = static_cast<uint8_t>(dac.bits);
    GPIO::write(SPI::SS, GPIO::Low);
    spi.communicate(buffer);
    GPIO::write(SPI::SS, GPIO::High);
}

int
main(void)
{
    auto spi = SPI::Master<SPI::SPI0>();
    spi.set(SPI::Mode::m0);
    spi.set(spi.Clock::_2);
    spi.enable();
    GPIO::set(SPI::SS, GPIO::Output);
    GPIO::write(SPI::SS, GPIO::High);
    auto dac = MCP49x2::MCP4922(MCP49x2::Channel::A);
    dac.set(MCP49x2::Gain::x1);
    dac.set(MCP49x2::BufferControl::Unbuffered);
    Irq::enable();
    usart.set(baud);
    usart.enable(USART::Channel::TX);
    serial.printLn("Sending bytes over SPI");
    while (true) {
        send(spi, dac, 4095);
        send(spi, dac, 1);
    }
}

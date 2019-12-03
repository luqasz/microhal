#include <gpio.h>
#include <irq.h>
#include <mcp49xx.h>
#include <printer.h>
#include <sfr.h>
#include <spi.h>
#include <stdio.h>
#include <usart.h>
#include <util/delay.h>

auto constexpr baud = USART::get_baud<BAUD, 2>();
auto usart          = USART::Async<USART::USART0>();
auto serial         = Printer<USART::Async<USART::USART0>, RN>(usart);

template <typename SENDER, typename DAC>
void
send(SENDER spi, DAC dac, uint16_t value)
{
    dac     = value;
    auto cs = SPI::SS.output();
    cs.set(GPIO::PinState::Low);
    spi.communicate(dac.bits);
    cs.set(GPIO::PinState::High);
}

int
main(void)
{
    auto spi = SPI::Master<SPI::SPI0>();
    spi.set(SPI::Mode::m0);
    spi.set(spi.Speed::d2);
    spi.enable();
    // spi.set(SPI::DataOrder::LSB_First);
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

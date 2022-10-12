#include <datetime.hpp>
#include <flash.hpp>
#include <irq.hpp>
#include <printer.hpp>
#include <sfr.hpp>
#include <stdio.h>
#include <units.hpp>
#include <usart.hpp>
#include <util/delay.h>

auto constexpr baud = USART::get_baud(11059200_Hz, 115200u, 2);
static_assert(baud.is_ok, "Calculated error rate too high");
auto usart  = USART::Async<USART::USART0>();
auto serial = Printer(usart, LineEnd::CRLF);

PGMSPACE const char     arr[] = "text from flash";
PGMSPACE const uint16_t word  = 65534;
PGMSPACE const uint32_t dword = 4294967295;

int
main(void)
{
    Irq::enable();
    usart.set(baud);
    usart.enable(USART::Channel::TX);
    auto string = Flash::Array(arr);
    for (char c : string) {
        usart.write(static_cast<uint8_t>(c));
    }
    serial.printLn("");
    serial.printLn(Flash::read(word));
    serial.printLn(Flash::read(dword));
    while (true) {
    }
}

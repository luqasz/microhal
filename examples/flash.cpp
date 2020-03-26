#include <datetime.h>
#include <ds1337.h>
#include <flash.h>
#include <i2c.h>
#include <irq.h>
#include <printer.h>
#include <sfr.h>
#include <stdio.h>
#include <usart.h>
#include <util/delay.h>

auto constexpr baud = USART::get_baud<115200, 2>();
auto usart          = USART::Async<USART::USART0>();
auto serial         = Printer<USART::Async<USART::USART0>, RN>(usart);

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

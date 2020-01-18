#include <gpio.h>
#include <irq.h>
#include <stdio.h>
#include <timer.h>

int
main(void)
{
    GPIO::set(GPIO::PD5, GPIO::Output);
    GPIO::set(GPIO::PD4, GPIO::Output);

    auto timer = Timer<Timer1>();
    timer.set(CTC);
    timer.set(ToggleA);
    timer.set(ToggleB);
    timer.setTop(200);
    timer.set(Clock::_1);
    constexpr uint16_t counter = 2;
    timer.setCompareA(counter);
    timer.setCompareB(counter);
    Irq::enable();
    while (true) {
    }
}


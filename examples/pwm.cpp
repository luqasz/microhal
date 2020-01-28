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
    timer.top = 200;
    timer.set(Clock::_1);
    timer.compareMatch.A = 4;
    timer.compareMatch.B = 8;
    Irq::enable();
    while (true) {
    }
}


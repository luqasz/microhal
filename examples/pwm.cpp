#include <gpio.h>
#include <irq.h>
#include <stdio.h>
#include <timer.h>
#include <units.h>

constexpr auto FCPU   = 11059200_Hz;
constexpr auto config = getConfig(25_Hz, FCPU);

int
main(void)
{
    GPIO::Output(GPIO::PB1);
    GPIO::Output(GPIO::PB2);

    auto timer = Timer<Timer1>();
    timer.set(PWM);
    timer.inverting(timer.PinA);
    timer.inverting(timer.PinB);
    timer.set(25_Hz, FCPU);
    timer.compareMatch.A = timer.top.read() / 2;
    timer.compareMatch.B = timer.top.read() / 4;
    timer.start();
    while (true) {
    }
}

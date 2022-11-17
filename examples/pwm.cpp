#include <gpio.hpp>
#include <irq.hpp>
#include <stdio.h>
#include <timer.hpp>
#include <units.hpp>

constexpr auto FCPU   = units::Hz * 11059200;
constexpr auto config = getConfig(units::Hz * 25, FCPU);

int
main(void)
{
    gpio::Output(gpio::PB1);
    gpio::Output(gpio::PB2);

    auto timer = Timer<Timer1>();
    timer.set(PWM);
    timer.inverting(timer.PinA);
    timer.inverting(timer.PinB);
    timer.set(units::Hz * 25, FCPU);
    timer.compareMatch.A = timer.top.read() / 2;
    timer.compareMatch.B = timer.top.read() / 4;
    timer.start();
    while (true) {
    }
}

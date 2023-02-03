#include <timer.hpp>
#include <gpio.hpp>
#include <irq.hpp>
#include <stdio.h>
#include <timer.hpp>
#include <units.hpp>

using TIMER1 = timer::PWM<timer::Timer1>;

int
main(void)
{
    constexpr auto FCPU      = units::Hz * 11059200;
    constexpr auto timer_cfg = timer::calc_prescaled_top<u16>(units::Hz * 25, FCPU);

    (gpio::Output(gpio::PB1));
    (gpio::Output(gpio::PB2));

    const auto timer = TIMER1();
    timer.set(TIMER1::Output::A, TIMER1::Mode::High).set(timer_cfg);
    while (true) {
    }
}

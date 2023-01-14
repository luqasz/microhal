#include "mcu/atmega32/timer.hpp"
#include <gpio.hpp>
#include <irq.hpp>
#include <stdio.h>
#include <timer.hpp>
#include <units.hpp>

int
main(void)
{
    constexpr auto FCPU      = units::Hz * 11059200;
    constexpr auto timer_cfg = timer::calc_prescaled_top<u16>(units::Hz * 25, FCPU);

    (gpio::Output(gpio::PB1));
    (gpio::Output(gpio::PB2));

    const auto timer = timer::PWM<timer::Timer1>();
    timer.set(timer::Output::A, timer.High).set(timer_cfg);
    while (true) {
    }
}

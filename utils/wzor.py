# coding: utf-8

import math
from matplotlib import pyplot as plt

MOTOR_ROUND_STEPS = 200
INTERPOLATION = 1
ROUND_STEPS = MOTOR_ROUND_STEPS * INTERPOLATION # steps per full rotation including interpolation
ALPHA = math.radians(360 / ROUND_STEPS)


class FloatMethod:

    def speed(self, alpha, freq):
        return alpha / freq

    def init_delay(self, delay, alpha, accel):
        return (1 / delay) * math.sqrt((2 * alpha) / accel)

    def delay_at(self, initial, n):
        return initial * (math.sqrt(n + 1) - math.sqrt(n))

    def steps_to_limit(self, speed, accel):
        # Find out after how many steps does the speed hit the max speed limit.
        return pow(speed, 2) / (2 * ALPHA * accel)

    def delays(self, steps, accel, speed, delay):
        end_accel_step = self.steps_to_limit(speed, accel)
        idelay = self.init_delay(delay, ALPHA, accel)
        yield idelay
        step = 1
        for s in range(step, int(end_accel_step) + 1):
            yield self.delay_at(idelay, s)
            step = s
        max_speed = (ALPHA / delay) / speed
        for _ in range(step, steps + 1):
            yield max_speed


class Approx(FloatMethod):

    def delay_at(self, previous, n):
        result = previous - ((2 * previous) / (4 * n + 1))
        return result

    def delays(self, steps, accel, speed, delay, alpha):
        d0 = int(delay * math.sqrt((2 * alpha) / accel))
        yield d0
        step = 1
        previous = d0
        for s in range(step, steps + 1):
            dx = int(self.delay_at(previous, s))
            yield dx
            previous = dx
            step = s
        # for s in range(step, steps + 1):
        #     yield (ALPHA / delay) / speed


if __name__ == '__main__':
    fmethod = FloatMethod()
    approx_method = Approx()
    float_delays = tuple(fmethod.delays(steps=1000, accel=1000, speed=200, delay=10))
    approx_delays = tuple(approx_method.delays(steps=1000, accel=1, speed=200, delay=2000, alpha=1))
    fpoints = tuple(ALPHA / d for d in float_delays)
    # apoints = tuple(1 / d for d in approx_delays)
    # plt.plot(delays, label='delay')
    plt.plot(fpoints)
    plt.grid(True)
    plt.ylabel('speed')
    plt.xlabel('step')
    plt.show()


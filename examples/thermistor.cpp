#include <thermistor.h>

constexpr auto rt1 = SteinHart::ResistanceTemp {
    .t = 25,
    .r = 100000,
};

constexpr auto rt2 = SteinHart::ResistanceTemp {
    .t = 50,
    .r = 3605,
};

constexpr auto rt3 = SteinHart::ResistanceTemp {
    .t = 0,
    .r = 32554,
};

constexpr auto coef = SteinHart::calc_coef(rt1, rt2, rt3);

constexpr float lookup[] = {
    SteinHart::steinhartHart(10000, coef),
    SteinHart::steinhartHart(20000, coef),
    SteinHart::steinhartHart(5000, coef),
};

int
main(void)
{
    while (true) {
    }
}

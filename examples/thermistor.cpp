#include <thermistor.hpp>

constexpr auto rt1 = thermistor::CelsiusOhm {
    0,
    32'554,
};

constexpr auto rt2 = thermistor::CelsiusOhm {
    25,
    10'000,
};

constexpr auto rt3 = thermistor::CelsiusOhm {
    50,
    3'605,
};

constexpr auto coef         = thermistor::calc_coef(rt1, rt2, rt3);
constexpr auto steinhart_25 = thermistor::calc_temp(rt2.res, coef);
constexpr auto beta_25      = thermistor::calc_temp(rt2.res, rt2, 3844.95f);

static_assert(steinhart_25 > 24.9f && steinhart_25 < 25.1f, "nominal temperature != 25C");
static_assert(beta_25 > 24.9f && beta_25 < 25.1f, "nominal temperature != 25C");

int
main(void)
{
    while (true) {
    }
}

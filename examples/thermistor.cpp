#include <thermistor.hpp>

constexpr auto rt1 = Thermistor::CelsiusOhm {
    0,
    32'554,
};

constexpr auto rt2 = Thermistor::CelsiusOhm {
    25,
    10'000,
};

constexpr auto rt3 = Thermistor::CelsiusOhm {
    50,
    3'605,
};

constexpr auto coef         = Thermistor::calc_coef(rt1, rt2, rt3);
constexpr auto steinhart_25 = Thermistor::calc_temp(rt2.res, coef);
constexpr auto beta_25      = Thermistor::calc_temp(rt2.res, rt2, 3844.95f);

static_assert(steinhart_25 > 24.9 && steinhart_25 < 25.1, "nominal temperature != 25C");
static_assert(beta_25 > 24.9 && beta_25 < 25.1, "nominal temperature != 25C");

int
main(void)
{
    while (true) {
    }
}

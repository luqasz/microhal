#include "catch.hpp"

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

const auto coef = Thermistor::calc_coef(rt1, rt2, rt3);

TEST_CASE("SteinhartHart temperature calculation")
{
    const auto degree_25 = Thermistor::calc_temp(rt2.res, coef);
    REQUIRE(degree_25 > 24.9f);
    REQUIRE(degree_25 < 25.1f);
}

TEST_CASE("Temperature calculation using beta value")
{
    const auto degree_25 = Thermistor::calc_temp(rt2.res, rt2, 3844.95f);
    REQUIRE(degree_25 > 24.9f);
    REQUIRE(degree_25 < 25.1f);
}

#include "catch.hpp"

#include <vdiv.hpp>

TEST_CASE("Calculate sink resistor value")
{
    const auto r = vdiv::calc_sink_r(2048, 12, 10000);
    REQUIRE(r == 10000);
}

TEST_CASE("Calculate source resistor")
{
    const auto r = vdiv::calc_source_r(2048, 12, 10000);
    REQUIRE(r == 10000);
}

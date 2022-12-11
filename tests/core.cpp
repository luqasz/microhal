#include "catch.hpp"

#include <core.hpp>

TEST_CASE("max")
{
    const auto result = max(1, 2, 3, 8, 22, 32);
    REQUIRE(result == 32);
}

TEST_CASE("min")
{
    const auto result = min(34, 2, 8, 4);
    REQUIRE(result == 2);
}

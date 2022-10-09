#include "catch.hpp"

#include <_types/_uint8_t.h>
#include <bcd.hpp>

TEST_CASE("BCD to DEC")
{
    const auto bcd = BCD::from_u8(22);
    REQUIRE(bcd.value == 34);
}

TEST_CASE("DEC to BCD")
{
    const auto dec = BCD::into_u8(BCD { 34 });
    REQUIRE(dec == 22);
}

TEST_CASE("DEC BCD reversable")
{
    const auto input_bcd = BCD { 34 };
    const auto dec       = BCD::into_u8(input_bcd);
    const auto bcd       = BCD::from_u8(dec);
    REQUIRE(input_bcd == bcd);
}
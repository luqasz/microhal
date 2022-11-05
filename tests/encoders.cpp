#include "catch.hpp"

#include <encoders.hpp>

TEST_CASE("DEC to BCD")
{
    const auto bcd = encoder::dec_to_bcd(22);
    REQUIRE(bcd == 34);
}

TEST_CASE("BCD to DEC")
{
    const auto dec = encoder::bcd_to_dec(34);
    REQUIRE(dec == 22);
}

TEST_CASE("DEC BCD reversable")
{
    const u8   input_bcd = 34;
    const auto dec       = encoder::bcd_to_dec(input_bcd);
    const auto bcd       = encoder::dec_to_bcd(dec);
    REQUIRE(input_bcd == bcd);
}
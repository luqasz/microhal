#include "catch.hpp"

#include <buffer.hpp>

TEST_CASE("Span has valid size")
{
    const u8 tbl[] = { 1, 2, 3 };
    REQUIRE(buffer::Span(tbl).size() == 3);
}

TEST_CASE("Span slice has valid size")
{
    const u8   tbl[] = { 1, 2, 3, 4 };
    const auto slice = buffer::Span(tbl).slice(1, 3);
    REQUIRE(slice.size() == 3);
}

TEST_CASE("Circular buffer has valid len")
{
    auto buf = buffer::Circular<u8, 8, u16>();
    buf.write(1);
    buf.write(2);
    REQUIRE(buf.len() == 2);
}

TEST_CASE("Copy span to circular")
{
    auto     buf   = buffer::Circular<u8, 4, u16>();
    const u8 tbl[] = { 1, 2, 3, 4 };
    buf.write(1);
    buf.write(2);
    const usize copied = copy(tbl, buf);
    REQUIRE(copied == 2);
}

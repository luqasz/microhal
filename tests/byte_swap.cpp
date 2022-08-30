#include "catch.hpp"

#include <byorder.hpp>

TEST_CASE("Swap u16")
{
    const u16 bytes   = 0xCAFE;
    const u16 swapped = byorder::into<endian::network>(bytes);
    REQUIRE(swapped == 0xFECA);
    REQUIRE(byorder::from<endian::network>(swapped) == bytes);
}

TEST_CASE("Swap u32")
{
    const u32 bytes   = 0xDEADBEEF;
    const u32 swapped = byorder::into<endian::network>(bytes);
    REQUIRE(swapped == 0xEFBEADDE);
    REQUIRE(byorder::from<endian::network>(swapped) == bytes);
}

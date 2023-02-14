#include "catch.hpp"

#include <byte_order.hpp>

TEST_CASE("Into big endian u16")
{
    const u16 bytes   = 0xCAFE;
    const u16 swapped = byorder::into<endian::big>(bytes);
    REQUIRE(swapped == 0xFECA);
    REQUIRE(byorder::from<endian::big>(swapped) == bytes);
}

TEST_CASE("Into big endian u32")
{
    const u32 bytes   = 0xDEADBEEF;
    const u32 swapped = byorder::into<endian::big>(bytes);
    REQUIRE(swapped == 0xEFBEADDE);
    REQUIRE(byorder::from<endian::big>(swapped) == bytes);
}

TEST_CASE("Into big endian u64")
{
    const u64 bytes   = 0xCAFEDEADBEEFCAFE;
    const u64 swapped = byorder::into<endian::big>(bytes);
    REQUIRE(swapped == 0xFECAEFBEADDEFECA);
    REQUIRE(byorder::from<endian::big>(swapped) == bytes);
}

TEST_CASE("Into u16 big endian bytes")
{
    const u16 value = 0x6566;
    auto      bytes = byorder::into_bytes<endian::big>(value);
    REQUIRE(bytes[0] == u8(0x65));
    REQUIRE(bytes[1] == u8(0x66));
}

TEST_CASE("Into u16 little endian bytes")
{
    const u16 value = 0x6566;
    auto      bytes = byorder::into_bytes<endian::little>(value);
    REQUIRE(bytes[0] == u8(0x66));
    REQUIRE(bytes[1] == u8(0x65));
}

TEST_CASE("Into u32 big endian bytes")
{
    const u32 value = 0x65666768;
    auto      bytes = byorder::into_bytes<endian::big>(value);
    REQUIRE(bytes[0] == u8(0x65));
    REQUIRE(bytes[1] == u8(0x66));
    REQUIRE(bytes[2] == u8(0x67));
    REQUIRE(bytes[3] == u8(0x68));
}

TEST_CASE("Into u32 little endian bytes")
{
    const u32 value = 0x65666768;
    auto      bytes = byorder::into_bytes<endian::little>(value);
    REQUIRE(bytes[0] == u8(0x68));
    REQUIRE(bytes[1] == u8(0x67));
    REQUIRE(bytes[2] == u8(0x66));
    REQUIRE(bytes[3] == u8(0x65));
}

TEST_CASE("Into u64 big endian bytes")
{
    const u64 value = 0x6566676869707172;
    auto      bytes = byorder::into_bytes<endian::big>(value);
    REQUIRE(bytes[0] == u8(0x65));
    REQUIRE(bytes[1] == u8(0x66));
    REQUIRE(bytes[2] == u8(0x67));
    REQUIRE(bytes[3] == u8(0x68));
    REQUIRE(bytes[4] == u8(0x69));
    REQUIRE(bytes[5] == u8(0x70));
    REQUIRE(bytes[6] == u8(0x71));
    REQUIRE(bytes[7] == u8(0x72));
}

TEST_CASE("Into u64 little endian bytes")
{
    const u64 value = 0x6566676869707172;
    auto      bytes = byorder::into_bytes<endian::little>(value);
    REQUIRE(bytes[0] == u8(0x72));
    REQUIRE(bytes[1] == u8(0x71));
    REQUIRE(bytes[2] == u8(0x70));
    REQUIRE(bytes[3] == u8(0x69));
    REQUIRE(bytes[4] == u8(0x68));
    REQUIRE(bytes[5] == u8(0x67));
    REQUIRE(bytes[6] == u8(0x66));
    REQUIRE(bytes[7] == u8(0x65));
}

TEST_CASE("From big endian bytes u16")
{
    const buffer::Array<u8, 2> bytes { 0x65, 0x66 };
    const u16                  value = byorder::from_bytes<endian::big>(bytes);
    REQUIRE(value == 0x6566);
}

TEST_CASE("From little endian bytes u16")
{
    const buffer::Array<u8, 2> bytes { 0x65, 0x66 };
    const u16                  value = byorder::from_bytes<endian::little>(bytes);
    REQUIRE(value == 0x6665);
}

TEST_CASE("From big endian bytes u32")
{
    const buffer::Array<u8, 4> bytes { 0x65, 0x66, 0x67, 0x68 };
    const u32                  value = byorder::from_bytes<endian::big>(bytes);
    REQUIRE(value == 0x65666768);
}

TEST_CASE("From little endian bytes u32")
{
    const buffer::Array<u8, 4> bytes { 0x65, 0x66, 0x67, 0x68 };
    const u32                  value = byorder::from_bytes<endian::little>(bytes);
    REQUIRE(value == 0x68676665);
}

TEST_CASE("From big endian bytes u64")
{
    const buffer::Array<u8, 8> bytes { 0x65, 0x66, 0x67, 0x68, 0x69, 0x70, 0x71, 0x72 };
    const u64                  value = byorder::from_bytes<endian::big>(bytes);
    REQUIRE(value == 0x6566676869707172);
}

TEST_CASE("From little endian bytes u64")
{
    const buffer::Array<u8, 8> bytes { 0x65, 0x66, 0x67, 0x68, 0x69, 0x70, 0x71, 0x72 };
    const u64                  value = byorder::from_bytes<endian::little>(bytes);
    REQUIRE(value == 0x7271706968676665);
}

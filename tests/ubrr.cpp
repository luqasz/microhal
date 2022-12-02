#include "catch.hpp"

#include <ubrr.hpp>
#include <units.hpp>
/*
 * Below tests only check baud rates that are
 * possible to configure for a given frequency
 * regardless of error rate.
 * Table with possible baud rates can be found in datasheet.
 */

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=2400]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 2400, USART::U2X::off).value == 25);
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 2400, USART::U2X::on).value == 51);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=4800]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 4800, USART::U2X::off).value == 12);
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 4800, USART::U2X::on).value == 25);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=9600]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 9600, USART::U2X::off).value == 6);
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 9600, USART::U2X::on).value == 12);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=14400]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 14400, USART::U2X::off).value == 3);
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 14400, USART::U2X::on).value == 8);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=19200]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 19200, USART::U2X::off).value == 2);
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 19200, USART::U2X::on).value == 6);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=28800]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 28800, USART::U2X::off).value == 1);
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 28800, USART::U2X::on).value == 3);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=38400]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 38400, USART::U2X::off).value == 1);
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 38400, USART::U2X::on).value == 2);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=57600]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 57600, USART::U2X::off).value == 0);
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 57600, USART::U2X::on).value == 1);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=76800]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 76800, USART::U2X::on).value == 1);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=115200]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 1000000, 115200, USART::U2X::on).value == 0);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=2400]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 2400, USART::U2X::off).value == 287);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 2400, USART::U2X::on).value == 575);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=4800]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 4800, USART::U2X::off).value == 143);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 4800, USART::U2X::on).value == 287);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=9600]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 9600, USART::U2X::off).value == 71);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 9600, USART::U2X::on).value == 143);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=14400]")
{

    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 14400, USART::U2X::off).value == 47);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 14400, USART::U2X::on).value == 95);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=19200]")
{

    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 19200, USART::U2X::off).value == 35);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 19200, USART::U2X::on).value == 71);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=28800]")
{

    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 28800, USART::U2X::off).value == 23);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 28800, USART::U2X::on).value == 47);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=38400]")
{

    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 38400, USART::U2X::off).value == 17);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 38400, USART::U2X::on).value == 35);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=57600]")
{

    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 57600, USART::U2X::off).value == 11);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 57600, USART::U2X::on).value == 23);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=76800]")
{

    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 76800, USART::U2X::off).value == 8);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 76800, USART::U2X::on).value == 17);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=115200]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 115200, USART::U2X::off).value == 5);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 115200, USART::U2X::on).value == 11);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=230400]")
{
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 230400, USART::U2X::off).value == 2);
    REQUIRE(USART::calc_ubrr(units::Hz * 11059200, 230400, USART::U2X::on).value == 5);
}

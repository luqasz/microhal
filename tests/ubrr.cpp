#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <ubrr.h>
#include <units.h>
/*
 * Below tests only check baud rates that are
 * possible to configure for a given frequency
 * regardless of error rate.
 * Table with possible baud rates can be found in datasheet.
 */

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=2400]")
{
    REQUIRE(USART::calc_ubrr(1000000_Hz, 2400, 1) == 25);
    REQUIRE(USART::calc_ubrr(1000000_Hz, 2400, 2) == 51);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=4800]")
{
    REQUIRE(USART::calc_ubrr(1000000_Hz, 4800, 1) == 12);
    REQUIRE(USART::calc_ubrr(1000000_Hz, 4800, 2) == 25);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=9600]")
{
    REQUIRE(USART::calc_ubrr(1000000_Hz, 9600, 1) == 6);
    REQUIRE(USART::calc_ubrr(1000000_Hz, 9600, 2) == 12);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=14400]")
{
    REQUIRE(USART::calc_ubrr(1000000_Hz, 14400, 1) == 3);
    REQUIRE(USART::calc_ubrr(1000000_Hz, 14400, 2) == 8);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=19200]")
{
    REQUIRE(USART::calc_ubrr(1000000_Hz, 19200, 1) == 2);
    REQUIRE(USART::calc_ubrr(1000000_Hz, 19200, 2) == 6);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=28800]")
{
    REQUIRE(USART::calc_ubrr(1000000_Hz, 28800, 1) == 1);
    REQUIRE(USART::calc_ubrr(1000000_Hz, 28800, 2) == 3);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=38400]")
{
    REQUIRE(USART::calc_ubrr(1000000_Hz, 38400, 1) == 1);
    REQUIRE(USART::calc_ubrr(1000000_Hz, 38400, 2) == 2);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=57600]")
{
    REQUIRE(USART::calc_ubrr(1000000_Hz, 57600, 1) == 0);
    REQUIRE(USART::calc_ubrr(1000000_Hz, 57600, 2) == 1);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=76800]")
{
    REQUIRE(USART::calc_ubrr(1000000_Hz, 76800, 2) == 1);
}

TEST_CASE("UBRR calculation [F_CPU=1000000 BAUD=115200]")
{
    REQUIRE(USART::calc_ubrr(1000000_Hz, 115200, 2) == 0);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=2400]")
{
    REQUIRE(USART::calc_ubrr(11059200_Hz, 2400, 1) == 287);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 2400, 2) == 575);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=4800]")
{
    REQUIRE(USART::calc_ubrr(11059200_Hz, 4800, 1) == 143);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 4800, 2) == 287);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=9600]")
{
    REQUIRE(USART::calc_ubrr(11059200_Hz, 9600, 1) == 71);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 9600, 2) == 143);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=14400]")
{

    REQUIRE(USART::calc_ubrr(11059200_Hz, 14400, 1) == 47);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 14400, 2) == 95);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=19200]")
{

    REQUIRE(USART::calc_ubrr(11059200_Hz, 19200, 1) == 35);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 19200, 2) == 71);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=28800]")
{

    REQUIRE(USART::calc_ubrr(11059200_Hz, 28800, 1) == 23);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 28800, 2) == 47);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=38400]")
{

    REQUIRE(USART::calc_ubrr(11059200_Hz, 38400, 1) == 17);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 38400, 2) == 35);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=57600]")
{

    REQUIRE(USART::calc_ubrr(11059200_Hz, 57600, 1) == 11);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 57600, 2) == 23);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=76800]")
{

    REQUIRE(USART::calc_ubrr(11059200_Hz, 76800, 1) == 8);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 76800, 2) == 17);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=115200]")
{
    REQUIRE(USART::calc_ubrr(11059200_Hz, 115200, 1) == 5);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 115200, 2) == 11);
}

TEST_CASE("UBRR calculation [F_CPU=11059200 BAUD=230400]")
{
    REQUIRE(USART::calc_ubrr(11059200_Hz, 230400, 1) == 2);
    REQUIRE(USART::calc_ubrr(11059200_Hz, 230400, 2) == 5);
}

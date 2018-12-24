cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(avr_libs)

set(AVR_PROGRAMMER usbasp)
set(AVR_PROGRAMMER_PORT usb)
set(AVR_MCU atmega32)
set(F_CPU 11059200)
set(EXECUTABLE_NAME ${PROJECT_NAME}_${AVR_MCU})
set(CMAKE_BUILD_TYPE MinSizeRel)
set(CMAKE_CXX_STANDARD 17)

string(
    TIMESTAMP
    UTC_DATETIME
    "%Y.%m.%d %H:%M"
    UTC
    )

add_executable(
    ${EXECUTABLE_NAME}
    src/main.cpp
    src/uart.cpp
    )

target_compile_definitions(
    ${EXECUTABLE_NAME}
    PUBLIC
    )

set_property(
    SOURCE
    src/main.cpp
    PROPERTY
    COMPILE_DEFINITIONS
    UTC_DATETIME="${UTC_DATETIME}"
)

target_compile_options(
    ${EXECUTABLE_NAME}
    PUBLIC
    -Os
    -fpack-struct
    -fshort-enums
    -Wall
    -Werror
    -Wextra
    -Wsign-conversion
    -Wfloat-conversion
    -pedantic-errors
    -funsigned-bitfields
    -funsigned-char
    -ffunction-sections
    -flto
    -fwhole-program
    )


set_property(
    TARGET ${EXECUTABLE_NAME}
    APPEND_STRING PROPERTY
    LINK_FLAGS " -Wl,--gc-sections -mrelax -flto -fwhole-program")

include(avr-gcc.cmake)

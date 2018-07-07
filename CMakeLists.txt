cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(avr_libs)
set(C_STANDARD 11)
set(C_STANDARD_REQUIRED 11)

set(AVR_PROGRAMMER usbasp)
set(AVR_PROGRAMMER_PORT usb)
set(AVR_MCU atmega328p)
set(EXECUTABLE_NAME ${PROJECT_NAME}_${AVR_MCU})

add_executable(
    ${EXECUTABLE_NAME}
    src/main.c
    )

target_compile_definitions(
    ${EXECUTABLE_NAME}
    PUBLIC
    BAUD=${BAUD}
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
    )

set_target_properties(
    ${EXECUTABLE_NAME}
    PROPERTIES
    LINK_FLAGS "
    -Wl,--gc-sections
    -mrelax
    ")

include(avr-gcc.cmake)

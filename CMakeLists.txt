cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(avr_libs)

set(AVR_PROGRAMMER usbasp)
set(AVR_PROGRAMMER_PORT usb)
set(AVR_MCU atmega328p)
set(EXECUTABLE_NAME ${PROJECT_NAME}_${AVR_MCU})

add_executable(
    ${EXECUTABLE_NAME}
    src/main.c
    src/uart.c
    src/buffer.c
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
    -std=c11
    )

set_target_properties(
    ${EXECUTABLE_NAME}
    PROPERTIES
    LINK_FLAGS "
    -Wl,--gc-sections
    -mrelax
    ")

include(avr-gcc.cmake)

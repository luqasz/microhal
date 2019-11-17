cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(avr_libs)

set(AVR_PROGRAMMER usbasp)
set(AVR_PROGRAMMER_PORT usb)
set(AVR_MCU atmega32)
set(F_CPU 11059200)
set(EXECUTABLE_NAME ${PROJECT_NAME}_${AVR_MCU})
set(CMAKE_BUILD_TYPE MinSizeRel)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

string(
    TIMESTAMP
    UTC_DATETIME
    "%Y.%m.%d %H:%M"
    UTC
    )

add_executable(
    ${EXECUTABLE_NAME}
    src/main.cpp
    src/sfr.cpp
    src/eeprom.cpp
    )

target_compile_definitions(
    ${EXECUTABLE_NAME}
    PUBLIC
    F_CPU=${F_CPU}UL
    )


target_compile_options(
    ${EXECUTABLE_NAME}
    PUBLIC
    -fpack-struct
    -fshort-enums
    -Wall
    -Werror
    -Wextra
    -Wconversion
    -Wsign-conversion
    -Wfloat-conversion
    -Woverloaded-virtual
    -pedantic-errors
    -funsigned-bitfields
    -funsigned-char
    -ffunction-sections
    -flto
    -fwhole-program
    -fno-exceptions
    -fno-asynchronous-unwind-tables
    -fno-rtti
    )


set_property(
    TARGET ${EXECUTABLE_NAME}
    APPEND_STRING PROPERTY
    LINK_FLAGS " -Wl,--gc-sections -mrelax -flto -fwhole-program")

include(avr-gcc.cmake)

include_directories(
    AFTER
    src/${AVR_MCU}
    )

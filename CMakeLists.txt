cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(
    avr_libs
    LANGUAGES CXX
    )

set(CMAKE_CROSSCOMPILING 1)
set(AVR_PROGRAMMER usbasp)
set(AVR_PROGRAMMER_PORT usb)
set(F_CPU 11059200)
set(EXECUTABLE_NAME ${PROJECT_NAME}_$ENV{MCU})
set(CMAKE_BUILD_TYPE MinSizeRel)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

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
    -mmcu=$ENV{MCU}
    )

target_link_options(
    ${EXECUTABLE_NAME}
    PUBLIC
    -Wl,--gc-sections
    -mrelax
    -flto
    -fwhole-program
    -mmcu=$ENV{MCU}
    )

# Without this, avr-gcc throws:
# avr-ld: warning: cannot find entry symbol arch_paths_first; defaulting to 0000000000000000
string(REPLACE "-Wl,-search_paths_first" "" CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS}")
string(REPLACE "-Wl,-search_paths_first" "" CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS}")

target_include_directories(
    ${EXECUTABLE_NAME}
    PUBLIC
    src/$ENV{MCU}
    )

include(avr-gcc.cmake)

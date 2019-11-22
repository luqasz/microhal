cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(
    avr_libs
    LANGUAGES CXX
    )

set(AVR_PROGRAMMER usbasp)
set(AVR_PROGRAMMER_PORT usb)
set(CMAKE_BUILD_TYPE MinSizeRel)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/sfr.cpp
    src/eeprom.cpp
    )

target_compile_definitions(
    ${PROJECT_NAME}
    PUBLIC
    F_CPU=${F_CPU}UL
    )

target_compile_options(
    ${PROJECT_NAME}
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
    -mmcu=${MCU}
    )

target_link_options(
    ${PROJECT_NAME}
    PUBLIC
    -Wl,--gc-sections
    -mrelax
    -flto
    -fwhole-program
    -mmcu=${MCU}
    )

# Without this, avr-gcc throws:
# avr-ld: warning: cannot find entry symbol arch_paths_first; defaulting to 0000000000000000
string(REPLACE "-Wl,-search_paths_first" "" CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS}")
string(REPLACE "-Wl,-search_paths_first" "" CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS}")
include(src/mcu.cmake)
include(avr-gcc.cmake)

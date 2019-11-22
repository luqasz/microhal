cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
# Without this, avr-gcc throws:
# avr-ld: warning: cannot find entry symbol arch_paths_first; defaulting to 0000000000000000
set(HAVE_FLAG_SEARCH_PATHS_FIRST 0)
project(
    avr_libs
    LANGUAGES CXX
    )

set(AVR_PROGRAMMER usbasp)
set(AVR_PROGRAMMER_PORT usb)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    )

set_property(
    TARGET
    ${PROJECT_NAME}
    PROPERTY
    CXX_STANDARD
    17
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

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    src/${MCU}
    )

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    src/
    )

include(avr-gcc.cmake)

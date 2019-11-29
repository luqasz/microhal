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

include(avr-gcc.cmake)

function(target_options target_name)
    set_target_properties(
        ${target_name}
        PROPERTIES
        CXX_STANDARD 17
        )

    target_compile_definitions(
        ${target_name}
        PUBLIC
        F_CPU=${F_CPU}UL
        )

    target_compile_options(
        ${target_name}
        PUBLIC
        -fshort-enums
        -Wall
        -Werror
        -Wextra
        -Wconversion
        -Wsign-conversion
        -Wfloat-conversion
        -Woverloaded-virtual
        -pedantic-errors
        -funsigned-char
        -ffunction-sections
        -flto
        -fno-exceptions
        -fno-asynchronous-unwind-tables
        -fno-rtti
        $<$<CXX_COMPILER_ID:GNU>:-fwhole-program>
        $<$<CXX_COMPILER_ID:GNU>:-fpack-struct>
        $<$<CXX_COMPILER_ID:GNU>:-funsigned-bitfields>
        $<$<AND:$<NOT:$<BOOL:${BUILD_TESTS}>>,$<CXX_COMPILER_ID:GNU>>:-mmcu=${MCU}>
        )

    target_link_options(
        ${target_name}
        PUBLIC
        -mrelax
        -flto
        $<$<CXX_COMPILER_ID:GNU>:-Wl,--gc-sections>
        $<$<CXX_COMPILER_ID:GNU>:-fwhole-program>
        $<$<AND:$<NOT:$<BOOL:${BUILD_TESTS}>>,$<CXX_COMPILER_ID:GNU>>:-mmcu=${MCU}>
        )

    target_include_directories(
        ${target_name}
        PUBLIC
        src/${MCU}
        )

    target_include_directories(
        ${target_name}
        PUBLIC
        src/
        )
endfunction()

function(example target_name)
    add_executable(
        ${target_name}
        examples/${target_name}.cpp
        )
    target_options(${target_name})
    binutils(${target_name})
    avrdude(${target_name})
endfunction()


example(rtc)
example(usart)
example(flash)
example(adc)
example(spi)


if(${BUILD_TESTS})
    add_executable(
        tests
        tests/ubrr.cpp
        )
    target_options(tests)
endif()

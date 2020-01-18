cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
# Without this, avr-gcc throws:
# avr-ld: warning: cannot find entry symbol arch_paths_first; defaulting to 0000000000000000
set(HAVE_FLAG_SEARCH_PATHS_FIRST 0)
project(
    avr_libs
    LANGUAGES CXX
    )

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
        BAUD=${BAUD}
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
        -fno-exceptions
        -fno-asynchronous-unwind-tables
        -fno-rtti
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-flto>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-ffunction-sections>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-fdata-sections>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-Wl,--gc-sections>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-fwhole-program>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-mmcu=${MCU}>
        )

    target_link_options(
        ${target_name}
        PUBLIC
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-flto>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-ffunction-sections>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-fdata-sections>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-Wl,--gc-sections>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-fwhole-program>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-mmcu=${MCU}>
        $<$<NOT:$<BOOL:${BUILD_TESTS}>>:-mrelax>
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
example(watchdog)
example(ws2812)
example(lcd)
example(pin_irq)
example(pwm)


if(${BUILD_TESTS})
    add_executable(
        tests
        tests/ubrr.cpp
        )
    target_options(tests)
endif()

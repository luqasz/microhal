set(LIBTESTS_TARGET unit_tests)

add_executable(
    ${LIBTESTS_TARGET}
    ubrr.cpp
    tests_main.cpp
    thermistor.cpp
    vdiv.cpp
    byte_swap.cpp
    encoders.cpp
)

target_link_libraries(${LIBTESTS_TARGET} PUBLIC ${lib_name})

set_target_properties(
    ${LIBTESTS_TARGET}
    PROPERTIES
    CXX_STANDARD 17
)

target_compile_definitions(
    ${LIBTESTS_TARGET}
    PUBLIC
    F_CPU=16000000UL
)

target_compile_options(
    ${LIBTESTS_TARGET}
    PUBLIC
    -Wall
    -Werror
    -Wextra
    -Wconversion
    -Wsign-conversion
    -Wfloat-conversion
    -Woverloaded-virtual
    -Wdouble-promotion
    -pedantic-errors
    -funsigned-char
    -fno-exceptions
    -fno-asynchronous-unwind-tables
    -fno-rtti
    -fshort-enums
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(${LIBTESTS_TARGET} PUBLIC -fsingle-precision-constant)
endif()

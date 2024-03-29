set(LIBTESTS_TARGET unit_tests)

add_executable(
    ${LIBTESTS_TARGET}
    ubrr.cpp
    tests_main.cpp
    thermistor.cpp
    vdiv.cpp
    byte_order.cpp
    encoders.cpp
    core.cpp
    cobs.cpp
    buffer.cpp
)

target_link_libraries(${LIBTESTS_TARGET} PUBLIC ${PROJECT_NAME})

set_target_properties(
    ${LIBTESTS_TARGET}
    PROPERTIES
    CXX_STANDARD 20
)

target_compile_definitions(
    ${LIBTESTS_TARGET}
    PUBLIC
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
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(${LIBTESTS_TARGET} PUBLIC -fsingle-precision-constant)
endif()

cmake_minimum_required(VERSION 3.21)

project(
    microhal
    LANGUAGES CXX
)

add_library(
    ${PROJECT_NAME}
    INTERFACE
)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

if(PROJECT_IS_TOP_LEVEL)
    if(PRESET_NAME STREQUAL "unit-tests")
        add_subdirectory(tests)
    else()
        target_sources(
            ${PROJECT_NAME}
            INTERFACE
        )
        add_subdirectory(examples)
    endif()
endif()

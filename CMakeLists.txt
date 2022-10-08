cmake_minimum_required(VERSION 3.21)
set(lib_name microhal)

project(
    ${lib_name}
    LANGUAGES CXX
)

add_library(${lib_name} INTERFACE)

target_include_directories(
    ${lib_name}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>"
)

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory(tests)
endif()
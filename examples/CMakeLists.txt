cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_PROCESSOR $ENV{MCU})
SET(CMAKE_CROSSCOMPILING 1)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(
    examples
    LANGUAGES CXX
)
add_subdirectory(../ build)
file(GLOB cpp_files CONFIGURE_DEPENDS "*.cpp")
add_compile_options(
    -Werror 
    -Wall 
    -Wextra 
    -Wconversion 
    -Wpedantic 
    -Woverloaded-virtual 
    -Wdouble-promotion
)
foreach(file ${cpp_files})
    cmake_path(GET file STEM LAST_ONLY basename)
    add_executable(${basename} ${file})
    set_target_properties(${basename} PROPERTIES CXX_STANDARD 17)
    target_compile_definitions(${basename} PUBLIC F_CPU=16000000UL MCU=${CMAKE_SYSTEM_PROCESSOR})
    target_compile_options(
        ${basename}
        PUBLIC
        -flto
        -Wpadded
        -fno-exceptions
        -fno-asynchronous-unwind-tables
        -fno-rtti
        -fno-short-enums
        -fsingle-precision-constant
        -mmcu=${CMAKE_SYSTEM_PROCESSOR}
    )
    target_link_options(
        ${basename}
        PUBLIC
        -flto
        -mmcu=${CMAKE_SYSTEM_PROCESSOR}
    )
    target_link_libraries(${basename} PUBLIC microhal)
endforeach()


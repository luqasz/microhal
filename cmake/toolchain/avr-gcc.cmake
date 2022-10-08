set(CMAKE_SYSTEM_NAME               Generic)

# Without that flag CMake is not able to pass test compilation check
set(CMAKE_TRY_COMPILE_TARGET_TYPE   STATIC_LIBRARY)

set(CMAKE_AR                        avr-ar${CMAKE_EXECUTABLE_SUFFIX})
set(CMAKE_ASM_COMPILER              avr-gcc${CMAKE_EXECUTABLE_SUFFIX})
set(CMAKE_C_COMPILER                avr-gcc${CMAKE_EXECUTABLE_SUFFIX})
set(CMAKE_CXX_COMPILER              avr-g++${CMAKE_EXECUTABLE_SUFFIX})
set(CMAKE_LINKER                    avr-ld${CMAKE_EXECUTABLE_SUFFIX})
set(CMAKE_OBJCOPY                   avr-objcopy${CMAKE_EXECUTABLE_SUFFIX} CACHE INTERNAL "")
set(CMAKE_RANLIB                    avr-ranlib${CMAKE_EXECUTABLE_SUFFIX} CACHE INTERNAL "")
set(CMAKE_SIZE                      avr-size${CMAKE_EXECUTABLE_SUFFIX} CACHE INTERNAL "")
set(CMAKE_STRIP                     avr-strip${CMAKE_EXECUTABLE_SUFFIX} CACHE INTERNAL "")

set(CMAKE_C_FLAGS_DEBUG_INIT                    "-Og -g")
set(CMAKE_CXX_FLAGS_DEBUG_INIT                  "${CMAKE_C_FLAGS_DEBUG_INIT}")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT           "")

set(CMAKE_C_FLAGS_RElWITHDEBINFO_INIT           "")
set(CMAKE_CXX_FLAGS_RElWITHDEBINFO_INIT         "${CMAKE_C_FLAGS_RElWITHDEBINFO_INIT}")
set(CMAKE_EXE_LINKER_FLAGS_RElWITHDEBINFO_INIT  "")

set(CMAKE_C_FLAGS_RELEASE_INIT                  "-ffunction-sections -fdata-sections")
set(CMAKE_CXX_FLAGS_RELEASE_INIT                "${CMAKE_C_FLAGS_RELEASE_INIT}")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE_INIT         "-Wl,--gc-sections")

set(CMAKE_C_FLAGS_MINSIZEREL_INIT               "-ffunction-sections -fdata-sections")
set(CMAKE_CXX_FLAGS_MISIZEREL_INIT              "${CMAKE_C_FLAGS_MISIZEREL_INIT}")
set(CMAKE_EXE_LINKER_FLAGS_MISIZEREL_INIT       "-Wl,--gc-sections")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


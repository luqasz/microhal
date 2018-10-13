cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
set(CMAKE_CROSSCOMPILING 1)

find_program(AVR_OBJCOPY avr-objcopy)
find_program(AVR_SIZE_TOOL avr-size)
find_program(AVR_OBJDUMP avr-objdump)
find_program(AVR_UPLOADTOOL avrdude)

set(hex_file ${EXECUTABLE_NAME}.hex)
set(eeprom_file ${EXECUTABLE_NAME}.eeprom)
set(dis_file ${EXECUTABLE_NAME}.dis)

target_compile_options(
    ${EXECUTABLE_NAME}
    PUBLIC
    -mmcu=${AVR_MCU} 
)

# Without this, avr-gcc throws:
# avr-ld: warning: cannot find entry symbol arch_paths_first; defaulting to 0000000000000000
string(REPLACE "-Wl,-search_paths_first" "" CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS}")
string(REPLACE "-Wl,-search_paths_first" "" CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS}")

target_compile_definitions(
    ${EXECUTABLE_NAME}
    PUBLIC
    F_CPU=${F_CPU}UL
    )

set_property(
    TARGET ${EXECUTABLE_NAME} 
    APPEND_STRING PROPERTY 
    LINK_FLAGS " -mmcu=${AVR_MCU}")

add_custom_command(
   OUTPUT ${dis_file}
   COMMAND
       ${AVR_OBJDUMP}
       -h
       -S ${EXECUTABLE_NAME} > ${dis_file}
   DEPENDS ${EXECUTABLE_NAME}
)

add_custom_command(
    OUTPUT ${hex_file}
    COMMAND
        ${AVR_OBJCOPY}
        -j .text
        -j .data
        -O ihex ${EXECUTABLE_NAME} ${hex_file}
    DEPENDS ${EXECUTABLE_NAME}
)

add_custom_command(
   OUTPUT ${eeprom_file}
   COMMAND
       ${AVR_OBJCOPY}
       -j .eeprom
       --set-section-flags=.eeprom=alloc,load
       --change-section-lma .eeprom=0
       --no-change-warnings
       -O ihex ${EXECUTABLE_NAME} ${eeprom_file}
   DEPENDS ${EXECUTABLE_NAME}
)

add_custom_target(
   size
       ${AVR_SIZE_TOOL}
       --format=avr
       --mcu=${AVR_MCU}
       ${EXECUTABLE_NAME}
   DEPENDS ${EXECUTABLE_NAME}
)

add_custom_target(
   upload_hex
       ${AVR_UPLOADTOOL}
       -p ${AVR_MCU}
       -c ${AVR_PROGRAMMER}
       -U flash:w:${hex_file}
       -P ${AVR_PROGRAMMER_PORT}
   DEPENDS ${hex_file}
)

# see also bug http://savannah.nongnu.org/bugs/?40142
add_custom_target(
   upload_eeprom
       ${AVR_UPLOADTOOL}
       -p ${AVR_MCU}
       -c ${AVR_PROGRAMMER}
       -U eeprom:w:${eeprom_file}
       -P ${AVR_PROGRAMMER_PORT}
   DEPENDS ${eeprom_file}
)

add_custom_target(
   status
       ${AVR_UPLOADTOOL}
       -p ${AVR_MCU}
       -c ${AVR_PROGRAMMER}
       -P ${AVR_PROGRAMMER_PORT}
       -n
       -v
)

add_custom_target(
   get_fuses
       ${AVR_UPLOADTOOL}
       -p ${AVR_MCU}
       -c ${AVR_PROGRAMMER}
       -P ${AVR_PROGRAMMER_PORT}
       -n
       -U lfuse:r:-:b
       -U hfuse:r:-:b
)

add_custom_target(
   set_fuses
       ${AVR_UPLOADTOOL}
       -p ${AVR_MCU}
       -c ${AVR_PROGRAMMER}
       -P ${AVR_PROGRAMMER_PORT}
       -U lfuse:w:${AVR_L_FUSE}:m
       -U hfuse:w:${AVR_H_FUSE}:m
)

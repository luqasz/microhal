find_program(avr_objcopy avr-objcopy)
find_program(avr_size_tool avr-objdump)
find_program(avr_objdump avr-objdump)
find_program(avr_uploadtool avrdude)

set(bin_file ${PROJECT_NAME}.bin)
set(eeprom_file ${PROJECT_NAME}.eeprom)
# Below values must match. e.g.
# ihex for objdump i for avrdude
# binary for objdump r for avrdude
set(objdump_format binary)
set(avrdude_format r)

add_custom_command(
    OUTPUT ${bin_file}
    COMMAND
        ${avr_objcopy}
        -j .text
        -j .data
        -O ${objdump_format} ${PROJECT_NAME} ${bin_file}
        DEPENDS ${PROJECT_NAME}
)

add_custom_command(
   OUTPUT ${eeprom_file}
   COMMAND
       ${avr_objcopy}
       -j .eeprom
       --set-section-flags=.eeprom=alloc,load
       --change-section-lma .eeprom=0
       --no-change-warnings
       -O ${objdump_format} ${PROJECT_NAME} ${eeprom_file}
       DEPENDS ${PROJECT_NAME}
)

add_custom_target(
   dis
       ${avr_objdump}
       -w
       -j .text
       -j .data
       -C
       -S
       ${PROJECT_NAME}
       DEPENDS ${PROJECT_NAME}
)


add_custom_target(
   size
       ${avr_size_tool}
       -w
       -P mem-usage
       ${PROJECT_NAME}
       DEPENDS ${PROJECT_NAME}
)

add_custom_target(
   flash
       ${avr_uploadtool}
       -p ${AVR_MCU}
       -c ${AVR_PROGRAMMER}
       -U flash:w:${bin_file}:${avrdude_format}
       -P ${AVR_PROGRAMMER_PORT}
       DEPENDS ${bin_file}
)

# see also bug http://savannah.nongnu.org/bugs/?40142
add_custom_target(
   eeprom
       ${avr_uploadtool}
       -p ${AVR_MCU}
       -c ${AVR_PROGRAMMER}
       -U eeprom:w:${eeprom_file}:${avrdude_format}
       -P ${AVR_PROGRAMMER_PORT}
       DEPENDS ${eeprom_file}
)

add_custom_target(
   status
       ${avr_uploadtool}
       -p ${AVR_MCU}
       -c ${AVR_PROGRAMMER}
       -P ${AVR_PROGRAMMER_PORT}
       -n
       -v
)

add_custom_target(
   get_fuses
       ${avr_uploadtool}
       -p ${AVR_MCU}
       -c ${AVR_PROGRAMMER}
       -P ${AVR_PROGRAMMER_PORT}
       -n
       -U lfuse:r:-:b
       -U hfuse:r:-:b
)

add_custom_target(
   set_fuses
       ${avr_uploadtool}
       -p ${AVR_MCU}
       -c ${AVR_PROGRAMMER}
       -P ${AVR_PROGRAMMER_PORT}
       -U lfuse:w:${AVR_L_FUSE}:m
       -U hfuse:w:${AVR_H_FUSE}:m
)

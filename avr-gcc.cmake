find_program(avr_uploadtool avrdude)

# Below values must match. e.g.
# ihex for objdump i for avrdude
# binary for objdump r for avrdude
set(objdump_format binary)
set(avrdude_format r)

function(binutils target_name)

    set(eeprom_file ${target_name}.eeprom)
    set(bin_file ${target_name}.bin)

    add_custom_command(
        OUTPUT ${bin_file}
        COMMAND
            ${CMAKE_OBJCOPY}
            -j .text
            -j .data
            -O ${objdump_format} ${target_name} ${bin_file}
            DEPENDS ${target_name}
    )

    add_custom_command(
       OUTPUT ${eeprom_file}
       COMMAND
           ${CMAKE_OBJCOPY}
           -j .eeprom
           --set-section-flags=.eeprom=alloc,load
           --change-section-lma .eeprom=0
           --no-change-warnings
           -O ${objdump_format} ${target_name} ${eeprom_file}
           DEPENDS ${target_name}
    )

    add_custom_target(
       dis_${target_name}
           ${CMAKE_OBJDUMP}
           -w
           -j .text
           -j .data
           -C
           -S
           ${target_name}
           DEPENDS ${target_name}
    )

    add_custom_target(
       size_${target_name}
           ${CMAKE_OBJDUMP}
           -w
           -P mem-usage
           ${target_name}
           DEPENDS ${target_name}
    )
endfunction()

function(avrdude target_name)
    set(bin_file ${target_name}.bin)

    add_custom_target(
       flash_${target_name}
           ${avr_uploadtool}
           -p ${CMAKE_SYSTEM_PROCESSOR}
           -c ${AVR_PROGRAMMER}
           -b ${AVR_PROGRAMMER_BAUD}
           -P ${AVR_PROGRAMMER_PORT}
           -U flash:w:${bin_file}:${avrdude_format}
           DEPENDS ${bin_file}
    )
endfunction()

add_custom_target(
   status
       ${avr_uploadtool}
       -p ${CMAKE_SYSTEM_PROCESSOR}
       -c ${AVR_PROGRAMMER}
       -P ${AVR_PROGRAMMER_PORT}
       -b ${AVR_PROGRAMMER_BAUD}
       -n
       -v
)

add_custom_target(
   get_fuses
       ${avr_uploadtool}
       -p ${CMAKE_SYSTEM_PROCESSOR}
       -c ${AVR_PROGRAMMER}
       -P ${AVR_PROGRAMMER_PORT}
       -b ${AVR_PROGRAMMER_BAUD}
       -n
       -U lfuse:r:-:b
       -U hfuse:r:-:b
)

add_custom_target(
   set_fuses
       ${avr_uploadtool}
       -b ${AVR_PROGRAMMER_BAUD}
       -p ${CMAKE_SYSTEM_PROCESSOR}
       -c ${AVR_PROGRAMMER}
       -P ${AVR_PROGRAMMER_PORT}
       -b ${AVR_PROGRAMMER_BAUD}
       -U lfuse:w:${AVR_L_FUSE}:m
       -U hfuse:w:${AVR_H_FUSE}:m
)

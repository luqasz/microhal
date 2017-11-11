# Create variables from command line arguments.
vars = Variables(None, ARGUMENTS)
vars.Add('MCU', 'Microcontroller', 'atmega32')
vars.Add('F_CPU', 'CPU frequency in Hz', 11059200)
vars.Add('BAUD', 'UART baud rate', 115200)
vars.Add('PROGRAMMER', 'avrdude programmer typr', 'usbasp')
vars.Add('PROGRAMMER_PORT', 'avrdude programmer port', 'usb')

defines = {
  'F_CPU': '${F_CPU}UL',
  'BAUD': '${BAUD}',
}

compiler_flags = (
    '-mmcu=${MCU}',
    '-Os',                              # Optimize for size
    '-Wall',                            # Turn on warnings
    '-Wextra',                          # Turn on more warnings
    '-Wsign-conversion',                # Warn for implicit sign conversion
    '-Wfloat-conversion',               # Warn for implicit float conversion
    '-Werror',                          # Treat all warnings as errors
    '-funsigned-char',                  # char type is promoted to unsigned char
    '-ffunction-sections',              # Do not compile unused functions
    '-std=gnu11',
)

linker_flags = (
    '-Wl,--gc-sections',                # Do not link unused functions
)

env = Environment(
    CC='avr-gcc',
    variables=vars,
    LINKFLAGS=linker_flags + compiler_flags,
    CFLAGS=compiler_flags,
    CPPDEFINES=defines,
)

main = env.Program("main.elf", Glob('src/*.c'))

SIZE = env.Command(
        target='${SOURCE}.size.dummy',
        source=main,
        action='avr-size --mcu=${MCU} --format=avr ${SOURCE}'
        )
HEX = env.Command(
        target='${SOURCE.base}.hex',
        source=main,
        action='avr-objcopy -O ihex ${SOURCE} ${TARGET}'
        )
FLASH = env.Command(
        target='${SOURCE}.flash.dummy',
        source=HEX,
        action='avrdude -p ${MCU} -P ${PROGRAMMER_PORT} -c ${PROGRAMMER} -U flash:w:${SOURCE}'
        )

env.AlwaysBuild(SIZE)
env.AlwaysBuild(FLASH)
env.Alias('flash', FLASH)
env.Alias('size', SIZE)

Default(SIZE, FLASH)
Help(vars.GenerateHelpText(env))

include hardware.mk

# Target file name (without extension).
TARGET = main

#---------------- Compiler Options ----------------
CFLAGS = -mmcu=$(MCU)
CFLAGS += -DF_CPU=$(F_CPU)UL
CFLAGS += -DBAUD=$(BAUD)UL
# Optimize for size
CFLAGS += -Os
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -Wsign-conversion
CFLAGS += -Wfloat-conversion
# Do not compile unused functions
CFLAGS += -ffunction-sections
# Assume char to be unsigned
CFLAGS += -funsigned-char
CFLAGS += -std=gnu11
#---------------- Linker Options ----------------
# Do not link unused functions
LDFLAGS += -Wl,--gc-sections
#---------------- Programming Options (avrdude) ----------------
AVRDUDE_FLAGS = -p $(MCU)
AVRDUDE_FLAGS += -P $(PROGRAMMER_PORT)
AVRDUDE_FLAGS += -c $(PROGRAMMER)


# Default target.
all: program size


ci: clean size


size: $(TARGET).elf
	@echo
	avr-size --mcu=$(MCU) --format=avr $(TARGET).elf


# Program the device.
program: $(TARGET).hex
	avrdude $(AVRDUDE_FLAGS) -U flash:w:$(TARGET).hex


%.hex: %.elf
	@echo Creating: $@
	avr-objcopy -O ihex $< $@


# Link: create ELF output file from object files.
%.elf: $(patsubst %.c,%.o,$(wildcard src/*.c))
	@echo Linking: $@
	avr-gcc $(CFLAGS) $^ --output $@ $(LDFLAGS)


# Compile: create object files from C source files.
%.o: %.c
	@echo Compiling: $<
	avr-gcc -c $(CFLAGS) $< -o $@


clean:
	find . -name "*.elf" -delete
	find . -name "*.hex" -delete
	find . -name "*.o" -delete


.PHONY : clean all ci size

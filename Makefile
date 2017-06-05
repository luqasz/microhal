# MCU name for avrdude and avr-gcc
MCU = atmega328p

# Processor frequency.
#     This will define a symbol, F_CPU, in all source code files equal to the
#     processor frequency. You can then use this symbol in your source code to
#     calculate timings. Do NOT tack on a 'UL' at the end, this will be done
#     automatically to create a 32-bit value in your source code.
F_CPU = 8000000

AVRDUDE_PROGRAMMER = stk500v2

AVRDUDE_PORT = /dev/tty.usbserial-FTWAKGHJ

# Output format. (can be srec, ihex, binary)
FORMAT = ihex

# Target file name (without extension).
TARGET = main

# List C source files here.
SRC = $(wildcard *.c)

# Relative path in which directory builds will be done.
BUILDDIR = .builds

#---------------- Compiler Options ----------------
CFLAGS = -mmcu=$(MCU) -I.
CFLAGS += -DF_CPU=$(F_CPU)UL
# Optimize for size
CFLAGS += -Os
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -std=gnu11
# Do not compile unused functions
CFLAGS += -ffunction-sections
#---------------- Linker Options ----------------
# Create map file
LDFLAGS = -Wl,-Map=$(BUILDDIR)/$(TARGET).map
# Add cross reference to  map file
LDFLAGS += -Wl,--cref
# Do not compile unused functions
LDFLAGS += -Wl,--gc-sections
#---------------- Programming Options (avrdude) ----------------
AVRDUDE_FLAGS = -p $(MCU)
AVRDUDE_FLAGS += -P $(AVRDUDE_PORT)
AVRDUDE_FLAGS += -c $(AVRDUDE_PROGRAMMER)


# Define all object files.
OBJ = $(addprefix $(BUILDDIR)/,$(SRC:.c=.o))

# Default target.
all: clean build program size

ci: clean build size

build: elf hex

elf: $(BUILDDIR) $(BUILDDIR)/$(TARGET).elf
hex: $(BUILDDIR) $(BUILDDIR)/$(TARGET).hex

$(BUILDDIR):
	mkdir -p $@


size: elf
	@echo
	avr-size --mcu=$(MCU) --format=avr $(BUILDDIR)/$(TARGET).elf


# Program the device.
program: $(BUILDDIR)/$(TARGET).hex
	avrdude $(AVRDUDE_FLAGS) -U flash:w:$(BUILDDIR)/$(TARGET).hex


# Create final .hex from ELF output file.
$(BUILDDIR)/%.hex: $(BUILDDIR)/%.elf
	@echo Creating load file for Flash: $@
	avr-objcopy -O $(FORMAT) $< $@


# Link: create ELF output file from object files.
.SECONDARY : $(BUILDDIR)/$(TARGET).elf
.PRECIOUS : $(OBJ)
$(BUILDDIR)/%.elf: $(OBJ)
	@echo Linking: $@
	avr-gcc $(CFLAGS) $^ --output $@ $(LDFLAGS)


# Compile: create object files from C source files.
$(BUILDDIR)/%.o: %.c $(BUILDDIR)
	@echo Compiling: $<
	avr-gcc -c $(CFLAGS) $(abspath $<) -o $@


clean:
	@rm -fr $(BUILDDIR)/*


.PHONY : all \
	size \
	build \
	elf \
	hex \
	clean \
	program

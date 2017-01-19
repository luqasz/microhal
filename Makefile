# Hey Emacs, this is a -*- makefile -*-
#----------------------------------------------------------------------------
# WinAVR Makefile Template written by Eric B. Weddington, Jörg Wunsch, et al.
#
# Released to the Public Domain
#
# Additional material for this makefile was written by:
# Peter Fleury
# Tim Henigan
# Colin O'Flynn
# Reiner Patommel
# Markus Pfaff
# Sander Pool
# Frederik Rouleau
#
#----------------------------------------------------------------------------
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make program = Download the hex file to the device, using avrdude.
#                Please customize the avrdude settings below first!
#----------------------------------------------------------------------------

# MCU name
MCU = atmega32

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


# Place -D or -U options here
CDEFS = -DF_CPU=$(F_CPU)UL


#---------------- Compiler Options ----------------
CFLAGS = -mmcu=$(MCU) -I.
CFLAGS += $(CDEFS)
CFLAGS += -Os
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -Wall -Wstrict-prototypes
CFLAGS += -Wa,-adhlns=$(addprefix $(BUILDDIR)/,$(<:.c=.lst))
CFLAGS += -std=gnu99
CFLAGS += -gstabs
CFLAGS += -gstrict-dwarf


#---------------- Library Options ----------------
# Minimalistic printf version
PRINTF_LIB_MIN = -Wl,-u,vfprintf -lprintf_min

# Floating point printf version (requires MATH_LIB = -lm below)
PRINTF_LIB_FLOAT = -Wl,-u,vfprintf -lprintf_flt

# If this is left blank, then it will use the Standard printf version.
PRINTF_LIB =


# Minimalistic scanf version
SCANF_LIB_MIN = -Wl,-u,vfscanf -lscanf_min

# Floating point + %[ scanf version (requires MATH_LIB = -lm below)
SCANF_LIB_FLOAT = -Wl,-u,vfscanf -lscanf_flt

# If this is left blank, then it will use the Standard scanf version.
SCANF_LIB =


MATH_LIB = -lm


#---------------- Linker Options ----------------
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
LDFLAGS = -Wl,-Map=$(BUILDDIR)/$(TARGET).map,--cref
LDFLAGS += $(PRINTF_LIB) $(SCANF_LIB) $(MATH_LIB)


#---------------- Programming Options (avrdude) ----------------

AVRDUDE_FLAGS = -p $(MCU)
AVRDUDE_FLAGS += -P $(AVRDUDE_PORT)
AVRDUDE_FLAGS += -c $(AVRDUDE_PROGRAMMER)

#============================================================================


# Define all object files.
OBJ = $(addprefix $(BUILDDIR)/,$(SRC:.c=.o))

# Default target.
all: clean build program size

ci: clean build size

build: elf hex

elf: $(BUILDDIR) $(BUILDDIR)/$(TARGET).elf
hex: $(BUILDDIR) $(BUILDDIR)/$(TARGET).hex

$(BUILDDIR):
	@echo
	mkdir -p $@


size: elf
	@echo
	avr-size --mcu=$(MCU) --format=avr $(BUILDDIR)/$(TARGET).elf


# Program the device.
program: $(BUILDDIR)/$(TARGET).hex
	avrdude $(AVRDUDE_FLAGS) -U flash:w:$(BUILDDIR)/$(TARGET).hex


# Create final .hex from ELF output file.
$(BUILDDIR)/%.hex: $(BUILDDIR)/%.elf
	@echo
	@echo Creating load file for Flash: $@
	avr-objcopy -O $(FORMAT) $< $@


# Link: create ELF output file from object files.
.SECONDARY : $(BUILDDIR)/$(TARGET).elf
.PRECIOUS : $(OBJ)
$(BUILDDIR)/%.elf: $(OBJ)
	@echo
	@echo Linking: $@
	avr-gcc $(CFLAGS) $^ --output $@ $(LDFLAGS)


# Compile: create object files from C source files.
$(BUILDDIR)/%.o: %.c $(BUILDDIR)
	@echo
	@echo Compiling: $<
	avr-gcc -c $(CFLAGS) $(abspath $<) -o $@


clean:
	rm -fr $(BUILDDIR)/*


.PHONY : all \
	size \
	build \
	elf \
	hex \
	clean \
	program

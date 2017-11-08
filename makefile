include hardware.mk

# Target file name (without extension).
TARGET = main
# List C source files here.
SRC = $(wildcard src/*.c)
# Relative path in which directory builds will be done.
BUILDDIR = .builds

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
# Create map file
LDFLAGS = -Wl,-Map=$(BUILDDIR)/$(TARGET).map
# Add cross reference to map file
LDFLAGS += -Wl,--cref
# Do not link unused functions
LDFLAGS += -Wl,--gc-sections
#---------------- Programming Options (avrdude) ----------------
AVRDUDE_FLAGS = -p $(MCU)
AVRDUDE_FLAGS += -P $(PROGRAMMER_PORT)
AVRDUDE_FLAGS += -c $(PROGRAMMER)


# Define all object files.
OBJ = $(addprefix $(BUILDDIR)/,$(SRC:.c=.o))

# Default target.
all: clean build program size

ci: clean build size

build: elf hex

elf: $(BUILDDIR) $(BUILDDIR)/$(TARGET).elf
hex: $(BUILDDIR) $(BUILDDIR)/$(TARGET).hex

$(BUILDDIR):
	mkdir -p $@/src


size: elf
	@echo
	avr-size --mcu=$(MCU) --format=avr $(BUILDDIR)/$(TARGET).elf


# Program the device.
program: $(BUILDDIR)/$(TARGET).hex
	avrdude $(AVRDUDE_FLAGS) -U flash:w:$(BUILDDIR)/$(TARGET).hex


# Create final .hex from ELF output file.
$(BUILDDIR)/%.hex: $(BUILDDIR)/%.elf
	@echo Creating load file for Flash: $@
	avr-objcopy -O ihex $< $@


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
	@rm -fr $(BUILDDIR)
	@find . -name "*.o" -delete


.PHONY : all \
	size \
	build \
	elf \
	hex \
	clean \
	program

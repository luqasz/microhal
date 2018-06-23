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


all: install size


ci: clean size


size: $(TARGET)_$(MCU).elf
	@echo
	avr-size --mcu=$(MCU) --format=avr $(TARGET)_$(MCU).elf


install: $(TARGET)_$(MCU).hex
	avrdude $(AVRDUDE_FLAGS) -U flash:w:$(TARGET)_$(MCU).hex


%.hex: %.elf
	@echo Creating: $@
	avr-objcopy -O ihex $< $@


%.elf: $(patsubst %.c,%.o,$(wildcard src/*.c))
	@echo Linking: $@
	avr-gcc $(CFLAGS) $^ --output $@ $(LDFLAGS)


%.o: %.c
	@echo Compiling: $<
	avr-gcc -c $(CFLAGS) $< -o $@


clean:
	find . -name "*.elf" -delete
	find . -name "*.hex" -delete
	find . -name "*.o" -delete


.PHONY : clean all ci size install

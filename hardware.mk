########################################################################
# This file contains various hardware related options. Do not append   #
# any UL or such. They will be done in makefile.                       #
########################################################################

# MCU name for avrdude and avr-gcc
MCU = atmega32
# Processor frequency in Hz
F_CPU = 11059200
# Avrdude programmer. Passed to -c option. See avrdude -c? for valid programmers.
PROGRAMMER = usbasp
# Absolute path to programmer port.
PROGRAMMER_PORT = usb
# UART baud rate.
BAUD = 115200

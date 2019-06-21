#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import jinja2
import argparse
from pathlib import Path
from atdf_parser import parseZip
from collections import namedtuple
from filters import (
    onlyGpio,
    notGpio,
    filterDevices,
)

"""
list of avr arch and __ gcc defines for devices
https://www.nongnu.org/avr-libc/user-manual/using_tools.html
"""

here = str(Path(__file__).resolve().parent)


PathTemplate = namedtuple('PathTemplate', ('path', 'template', 'type'))


class Renderer:

    jenv = jinja2.Environment(
        loader=jinja2.FileSystemLoader(searchpath=here),
        undefined=jinja2.StrictUndefined,
        keep_trailing_newline=True,
        trim_blocks=True,
        lstrip_blocks=True,
    )

    def render(self, template):
        jtemplate = self.jenv.get_template(template)
        return jtemplate.render(
            device=self.device,
            atpack_file=self.atpack_file.name,
        )


class GPIO:

    def __init__(self, registers, letter):
        self.letter = letter
        self.registers = registers

    def __str__(self):
        return str(self.letter)

    def extract(self, name):
        for reg in self.registers:
            if reg.name.startswith(name):
                return reg

    @property
    def pin(self):
        return self.extract('PIN')

    @property
    def port(self):
        return self.extract('PORT')

    @property
    def ddr(self):
        return self.extract('DDR')


def groupGPIO(sequence):
    found = filter(onlyGpio, sequence)
    found = tuple(found)
    letters = set(reg.name[-1:] for reg in found)
    for letter in letters:
        regs = tuple(reg for reg in found if reg.name.endswith(letter))
        assert len(regs) == 3, "Number of registers != 3 {}".format(regs)
        yield GPIO(registers=regs, letter=letter)


Renderer.jenv.filters['notGPIO'] = lambda x: filter(notGpio, x)
Renderer.jenv.globals['groupGPIO'] = groupGPIO


def render(device, atpack, template):
    return Renderer.jenv.get_template(template).render(
        device=device,
        atpack_file=atpack,
    ).lstrip()


def write(dest_dir, content, file_name):
    dest_dir.mkdir(parents=True, exist_ok=True)
    dest_file = dest_dir / file_name
    dest_file.write_text(content)


def run(atpack, destinations):
    devices = parseZip(atpack)
    for device in filter(filterDevices, devices):
        device.registers = tuple(device.registers)
        for dest in destinations:
            file_name = "{}_{}.h".format(device.name.lower(), dest.type)
            content = render(device, atpack, dest.template)
            write(dest.path, content, file_name)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '-a',
        dest='atpack_file',
        required=True,
        help='*.atpack file.',
    )
    parser.add_argument(
        '--sfr-dir',
        required=True,
        help='Destination directory for SFR definitions.',
    )
    parser.add_argument(
        '--gpio-dir',
        required=True,
        help='Destination directory for GPIO definitions.',
    )
    parser.add_argument(
        '--eeprom-dir',
        required=True,
        help='Destination directory for EEPROM definitions.',
    )
    args = parser.parse_args()
    dest = (
        PathTemplate(path=Path(args.gpio_dir), type='gpio', template='gpio.j2'),
        PathTemplate(path=Path(args.sfr_dir), type='sfr', template='sfr.j2'),
        PathTemplate(path=Path(args.eeprom_dir), type='eeprom', template='eeprom.j2'),
    )
    run(
        atpack=Path(args.atpack_file),
        destinations=dest,
    )


if __name__ == '__main__':
    main()

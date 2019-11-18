#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import jinja2
import argparse
import yaml
from pathlib import Path
from collections import namedtuple


def filterDevices(device):
    # Devices that do not have all three DDR, PORT, PIN registers for each port
    names = device.name not in (
        'ATmega8HVA',
        'ATmega16HVA',
        'ATmega16HVB',
        'ATmega16HVBrevB',
        'ATmega32HVB',
        'ATmega32HVBrevB',
        'ATmega406',
    )
    # These devices have differend register arrangement
    archs = device.arch not in ('AVR8X', )
    return all((names, archs))


def filterModule(module):
    # No need for fuse and lock bits
    return module.attrib['name'].strip() not in ('FUSE', 'LOCKBIT')


def onlyGpio(reg):
    results = list()
    catch = ('PORT', 'DDR', 'PIN')
    for name in catch:
        result = reg['name'].startswith(name)
        results.append(result)
    return any(results)


def notGpio(reg):
    return not onlyGpio(reg)


here = str(Path(__file__).resolve().parent)


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
            if reg['name'].startswith(name):
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


def groupGPIO(registers):
    """Group registers by letter e.g. PORTA, PORTB etc."""
    found = filter(onlyGpio, registers)
    found = tuple(found)
    letters = set(reg['name'][-1:] for reg in found)
    for letter in letters:
        regs = tuple(reg for reg in found if reg['name'].endswith(letter))
        assert len(regs) == 3, "Number of registers != 3 {}".format(regs)
        yield GPIO(registers=regs, letter=letter)


Renderer.jenv.filters['notGPIO'] = lambda x: filter(notGpio, x)
Renderer.jenv.globals['groupGPIO'] = groupGPIO


def render(mcu, regs, template):
    return Renderer.jenv.get_template(template + '.j2').render(
        device=mcu,
        registers=regs,
        size_to_uint={
            1: 'uint8_t',
            2: 'uint16_t'
        },
    ).lstrip()


def write(dest_dir, content, file_name):
    dest_dir.mkdir(parents=True, exist_ok=True)
    dest_file = dest_dir / file_name
    dest_file.write_text(content)


def run(registers_dir, mcu, mcu_dir):
    mcu_yml = registers_dir / '{}.yml'.format(mcu)
    with mcu_yml.open(mode='r') as fobj:
        regs = yaml.load(fobj, Loader=yaml.FullLoader)
    for template in ('gpio', 'sfr'):
        file_name = "mcu_{}.h".format(template)
        content = render(mcu, regs, template)
        write(mcu_dir, content, file_name)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '-d',
        dest='registers_dir',
        required=True,
        help='Directory with yml registers.',
    )
    parser.add_argument(
        '--mcu-name',
        required=True,
        help='MCU name.',
    )
    parser.add_argument(
        '--mcu-dir',
        required=True,
        help='Destination for generated headers.',
    )
    args = parser.parse_args()
    run(
        registers_dir=Path(args.registers_dir),
        mcu=args.mcu_name,
        mcu_dir=Path(args.mcu_dir),
    )


if __name__ == '__main__':
    main()

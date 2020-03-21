import yaml
from pathlib import Path
import re

# admux = r'^ucsr[0-9]?[a-z]{1}$'

regs_parh = Path('../../avr-registers/registers/')
mcus = (str(f.stem).rstrip('.yml') for f in regs_parh.glob('*.yml'))


def load(mcu):
    regs_file = regs_parh / '{}.yml'.format(mcu)
    with regs_file.open(mode='r') as fobj:
        yield from yaml.load(fobj, Loader=yaml.FullLoader)


regs = set()

for m in mcus:
    for reg in load(m):
        if reg['name'].startswith('PCMSK'):
            regs.add(reg['name'])

print(regs)

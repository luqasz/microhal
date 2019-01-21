# -*- coding: UTF-8 -*-


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
    archs = device.arch not in ('AVR8X',)
    return all((names, archs))


def filterModule(module):
    # No need for fuse and lock bits
    return module.attrib['name'].strip() not in ('FUSE', 'LOCKBIT')


def filterRegister(reg):
    return reg.name not in ('SP',)


def filterInterrupt(irq):
    # No need for RESET interrupt
    return irq.name not in ('RESET',)


def onlyGpio(reg):
    results = list()
    catch = ('PORT', 'DDR', 'PIN')
    for name in catch:
        result = reg.name.startswith(name)
        results.append(result)
    return any(results)


def notGpio(reg):
    return not onlyGpio(reg)

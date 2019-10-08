# -*- coding: UTF-8 -*-

"""
Files can be downloaded from http://packs.download.atmel.com/
This version will not work for atxmega devices as they have different architecture, interrupts etc.


Known bugs:
* Timer pin naming mismatch. e.g. in datasheet OC1A, in PIC file OCA1
* Nearly all WGM bit fields are not named. e.g. WGM11 should exist, instead WGM1 with a mask field set to non power of two
"""


from zipfile import ZipFile
from xml.etree import ElementTree
from collections import defaultdict
from filters import (
    filterInterrupt,
    filterModule,
    filterRegister,
)


class Base:

    def __str__(self):
        return str(self.name)

    def __repr__(self):
        return "<{} {} at {}>".format(self.__class__.__name__, self.name, id(self))


class Hashable:

    def __hash__(self):
        return hash(self._hash_)

    def __eq__(self, other):
        return hash(self) == hash(other)


class Sortable:

    def __lt__(self, other):
        return self._lt_ < other._lt_


class BitField (Hashable, Base, Sortable):

    def __init__(self, name, description, mask):
        self.name = name
        self.description = description
        self.mask = mask
        self._hash_ = (self.name, self.mask)
        self._lt_ = mask


class Register (Hashable, Base, Sortable):

    def __init__(self, name, description, address, mask):
        self.name = name
        self.description = description
        self.address = address
        self.mask = mask
        self._hash_ = (self.name, self.address)
        self._lt_ = address

    @property
    def uint_type(self):
        if self.mask > 255:
            return 'uint16_t'
        else:
            return 'uint8_t'


class Interrupt(Hashable, Base, Sortable):

    def __init__(self, name, description, number):
        self.name = name
        self.description = description
        self.number = number
        self._hash_ = (self.name, self.number)
        self._lt_ = number


class EEPROM(Base):

    def __init__(self, start, size, page_size):
        self.start = start
        self.size = size
        self.page_size = page_size
        self.end = self.size - 1


class Device(Hashable, Base):

    def __init__(self, name, registers, arch, family, interrupts, eeprom):
        self.name = name
        self.registers = registers
        self.arch = arch
        self.family = family
        self.interrupts = interrupts
        self.eeprom = eeprom
        self._hash_ = (self.name, self.arch, self.family)


class AttrCast:
    def __init__(self, elem):
        self.elem = elem

    def attr(self, key):
        return self.elem.attrib[key].strip()

    def intAttr(self, key):
        return int(self.attr(key))

    def hexAttr(self, key):
        return int(self.attr(key), 16)

    @property
    def description(self):
        try:
            return self.attr('caption')
        except KeyError:
            return ""


def intSizeof(value):
    """Return how many bytes are needed to store value."""
    return int(log(value, 256)) + 1


def bitPositions(num):
    position = 0
    while (position < 8):
        if (num >> position) & 1:
            yield position
        position += 1


def isPowerOfTwo(number):
    return (number & (number - 1)) == 0


def calcMask(bit_fields):
    mask = 0
    for field in bit_fields:
        mask |= field.mask
    return mask


def createBitField(element):
    attrCast = AttrCast(element)
    return BitField(
        name=attrCast.attr('name'),
        mask=attrCast.hexAttr('mask'),
        description=attrCast.description,
    )


def createRegister(reg_element):
    attrCast = AttrCast(reg_element)
    try:
        mask = attrCast.hexAttr('mask')
    except KeyError:
        mask = 0
    return Register(
        name=attrCast.attr('name'),
        description=attrCast.description,
        mask=mask,
        address=attrCast.hexAttr('offset'),
    )


def createInterrupt(element):
    attrCast = AttrCast(element)
    return Interrupt(
        name=attrCast.attr('name'),
        number=attrCast.intAttr('index'),
        description=attrCast.description,
    )


def createEEPROM(element):
    if element:
        attrCast = AttrCast(element)
        pageCast = AttrCast(element.find('memory-segment'))
        return EEPROM(
            start=attrCast.hexAttr('start'),
            size=attrCast.hexAttr('size'),
            page_size=pageCast.hexAttr('pagesize'),
        )
    else:
        return None


def createDevice(dev_element, interrupts, registers):
    attrCast = AttrCast(dev_element)
    return Device(
        name=attrCast.attr('name'),
        arch=attrCast.attr('architecture'),
        family=attrCast.attr('family'),
        registers=registers,
        interrupts=interrupts,
        eeprom=createEEPROM(dev_element.find("address-spaces/address-space/[@name='eeprom']")),
    )


def splitBitField(field):
    attr = AttrCast(field)
    name = attr.attr('name')
    mask = attr.hexAttr('mask')
    for num, position in enumerate(bitPositions(mask)):
        yield BitField(
            name=name + str(num),
            mask=(1 << position),
            description=attr.description,
        )


def filterBitFields(fields):
    for field in fields:
        attr = AttrCast(field)
        if isPowerOfTwo(attr.hexAttr('mask')):
            yield createBitField(field)
        else:
            yield from splitBitField(field)


def findRegisters(root):
    found = root.findall('./modules/module')
    modules = filter(filterModule, found)
    for module in modules:
        yield from module.findall('register-group/register')


def makeDict(registers):
    mapping = defaultdict(list)
    for reg in registers:
        reg_obj = createRegister(reg)
        fields = reg.findall('bitfield')
        mapping[reg_obj].extend(fields)

    return mapping


def fixRegs(mapping):
    for reg, fields in mapping.items():
        bit_fields = set(filterBitFields(fields))
        reg.bit_fields = sorted(bit_fields)
        calculated = calcMask(bit_fields)
        reg.mask = reg.mask or calculated or 0xFF
        yield reg


def parseString(string):
    """Parse given atdf content as string and yield each device as a Device object."""
    root = ElementTree.fromstring(string)

    registers = findRegisters(root)
    registers = makeDict(registers)
    registers = fixRegs(registers)
    registers = filter(filterRegister, registers)
    registers = sorted(registers)

    for device in root.find('./devices'):
        interrupts = map(createInterrupt, device.find('interrupts'))
        interrupts = filter(filterInterrupt, interrupts)
        interrupts = sorted(interrupts)
        yield createDevice(device, interrupts, registers)


def fromZip(file_path):
    """Yield content of each * .atdf file found in a given zip file."""
    with ZipFile(file_path, mode='r') as zf:
        found = (elem for elem in zf.namelist() if elem.endswith('.atdf'))
        for file_name in found:
            lines = zf.open(name=file_name, mode='r').readlines()
            yield ''.join(line.decode() for line in lines)


def parseZip(file_path):
    for elem in fromZip(file_path):
        yield from parseString(elem)

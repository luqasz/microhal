#pragma once

#include "sfr.hpp"
#include "types.hpp"
#include "iomem.hpp"
#include "irq.hpp"

#ifdef MCU
#    if MCU == atmega32
#        include "mcu/atmega32/eeprom.hpp"
#    elif MCU == atmega328
#        include "mcu/atmega328/eeprom.hpp"
#    elif MCU == atmega2560
#        include "mcu/atmega2560/eeprom.hpp"
#    endif
#else
#    error "Unknown MCU."
#endif

namespace eeprom {

    static inline void
    write(const u8 byte, const u16 address)
    {
        // Wait for any previous write operation to finish.
        iomem::clear_bit_wait(REG_CTRL::address, WE);
        // Set EEPROM address to write to.
        iomem::write(REG_ADDR::address, address);
        // Set data to write.
        iomem::write(REG_DATA::address, byte);
        // Disable IRQ and restore it after finishing.
        auto state = RestoreIrq();
        // Set master write enable.
        iomem::set_bit(REG_CTRL::address, MWE);
        // Set write enable.
        iomem::set_bit(REG_CTRL::address, WE);
    }

    /*
    Function does not need to wait for EEPROM to finish.
    Just after setting read bit, data is available after 1 clock cycle.
    */
    static inline u8
    read(const u16 address)
    {
        // Wait for any previous write operation to finish.
        iomem::clear_bit_wait(REG_CTRL::address, WE);
        // Set EEPROM address to read from.
        iomem::write(REG_ADDR::address, address);
        // Set read enable bit.
        iomem::set_bit(REG_CTRL::address, RE);
        return iomem::read<u8>(REG_DATA::address);
    }

}

#ifndef ds1337_h
#define ds1337_h

#include "datetime.h"
#include "i2c.h"

#include <stdint.h>

class DS1337 {
    I2C::Master i2c_bus;

public:
    DS1337(I2C::Master &);

    void
    getDateTime(DateTime &);

    void
    setDateTime(DateTime &);
};

#endif

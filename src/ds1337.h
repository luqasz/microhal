#ifndef ds1337_H_
#define ds1337_H_

#include "time.h"

#include <stdint.h>

void
ds1337_write_time(
    date_time * time);

void
ds1337_read_time(
    date_time * time);

#endif

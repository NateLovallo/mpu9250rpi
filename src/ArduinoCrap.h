#pragma once

#include <math.h>

#include "util/arduino_mpu9250_i2c.h"

#define PI M_PI

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

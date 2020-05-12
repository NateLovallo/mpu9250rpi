#pragma once

#include <stdarg.h>
#include <math.h>

#if defined(__cplusplus) 
extern "C" {
#endif

#define PI M_PI

// This is an Arduino define
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

int rpi_i2c_write(unsigned char slave_addr, unsigned char reg_addr,
                       unsigned char length, unsigned char * data);

int rpi_i2c_read(unsigned char slave_addr, unsigned char reg_addr,
                       unsigned char length, unsigned char * data);
                       
int rpi_get_clock_ms(unsigned long *count);
int rpi_delay_ms(unsigned long num_ms);

#if defined(__cplusplus) 
}
#endif

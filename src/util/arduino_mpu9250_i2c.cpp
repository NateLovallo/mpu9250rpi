/******************************************************************************
arduino_mpu9250_i2c.cpp - MPU-9250 Digital Motion Processor Arduino Library 
Jim Lindblom @ SparkFun Electronics
original creation date: November 23, 2016
https://github.com/sparkfun/SparkFun_MPU9250_DMP_Arduino_Library

This library implements motion processing functions of Invensense's MPU-9250.
It is based on their Emedded MotionDriver 6.12 library.
	https://www.invensense.com/developers/software-downloads/

Development environment specifics:
Arduino IDE 1.6.12
SparkFun 9DoF Razor IMU M0

Supported Platforms:
- ATSAMD21 (Arduino Zero, SparkFun SAMD21 Breakouts)
******************************************************************************/
#include "arduino_mpu9250_i2c.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <i2c/smbus.h>
#include <errno.h>

int i2c_init()
{

	
	return 0; 
}

int arduino_i2c_write(unsigned char slave_addr, unsigned char reg_addr,
                       unsigned char length, unsigned char * data)
{
	int retval = 0;
	fprintf(stderr, "write \t%x \t%x \t%u\n", slave_addr, reg_addr, length);
	
	
	int i2c_fd = open("/dev/i2c-1",O_RDWR);
	assert(i2c_fd != -1);

	struct i2c_msg msgs[2];
	
	// register address
	msgs[0].addr = slave_addr;
	msgs[0].flags = 0; //RDWR?
	msgs[0].len = 1;
	msgs[0].buf = &reg_addr;
	
	// actual data
	msgs[1].addr = slave_addr;
	msgs[1].flags = 0; //RDWR?
	msgs[1].len = length;
	msgs[1].buf = data;
	
	struct i2c_rdwr_ioctl_data msgset;
	msgset.nmsgs = 2;
	msgset.msgs = msgs;

	if (ioctl(i2c_fd, I2C_RDWR, &msgset) < 0)
	{
		fprintf(stderr, "Oh shit write %d %s\n", errno, strerror(errno));
		retval = -1;
	}
	
	close(i2c_fd);
	
	return retval;
}

int arduino_i2c_read(unsigned char slave_addr, unsigned char reg_addr,
                       unsigned char length, unsigned char * data)
{
	int retval = 0;
	
	fprintf(stderr, "read \t%x \t%x \t%u\n", slave_addr, reg_addr, length);
	
	int i2c_fd = open("/dev/i2c-1",O_RDWR);
	assert(i2c_fd != -1);
	
	struct i2c_msg msgs[2];
	
	// register address
	msgs[0].addr = slave_addr;
	msgs[0].flags = 0; //RDWR?
	msgs[0].len = 1;
	msgs[0].buf = &reg_addr;
	
	// actual data
	msgs[1].addr = slave_addr;
	msgs[1].flags = I2C_M_RD; 
	msgs[1].len = length;
	msgs[1].buf = data;
	
	struct i2c_rdwr_ioctl_data msgset;
	msgset.nmsgs = 2;
	msgset.msgs = msgs;

	if (ioctl(i2c_fd, I2C_RDWR, &msgset) < 0)
	{
		fprintf(stderr, "Oh shit read %d %s\n", errno, strerror(errno));
		retval = -1;
	}
	
	close(i2c_fd);
			
	return retval;
}

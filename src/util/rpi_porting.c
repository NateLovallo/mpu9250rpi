#include "rpi_porting.h"
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
#include <time.h>
#include <stdarg.h>

///////////////////////////////////////////////////////////////////////////////
int rpi_i2c_write(unsigned char slave_addr, unsigned char reg_addr,
                       unsigned char length, unsigned char * data)
{
	int retval = 0;
	fprintf(stderr, "write \t0x%x \t0x%x \t%u\n", slave_addr, reg_addr, length);
	
	unsigned char send_data[256+1] = {};

	int i2c_fd = open("/dev/i2c-1",O_RDWR);
	assert(i2c_fd != -1);

	struct i2c_msg msg;
	
	// All the messages in a write need to be sent in one packet with not start condition
	// after the address
	//
	// So prepend the address
	// 
	send_data[0] = reg_addr;

	memcpy(&send_data[1], data, length);

	length++;

	msg.addr = slave_addr;
	msg.flags = 0; //RDWR?
	msg.len = length;
	msg.buf = send_data;
	
	struct i2c_rdwr_ioctl_data msgset;
	msgset.nmsgs = 1;
	msgset.msgs = &msg;

	if (ioctl(i2c_fd, I2C_RDWR, &msgset) < 0)
	{
		fprintf(stderr, "Write Failure! %d %s\n", errno, strerror(errno));
		retval = -1;
	}
	
	close(i2c_fd);
	
	return retval;
}

///////////////////////////////////////////////////////////////////////////////
int rpi_i2c_read(unsigned char slave_addr, unsigned char reg_addr,
                       unsigned char length, unsigned char * data)
{
	int retval = 0;
	
	fprintf(stderr, "read \t%x \t%x \t%u\n", slave_addr, reg_addr, length);
	
	int i2c_fd = open("/dev/i2c-1",O_RDWR);
	assert(i2c_fd != -1);
	
	// when doing a read, write the address first then read the stuff as a read
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
		fprintf(stderr, "Read failure! %d %s\n", errno, strerror(errno));
		retval = -1;
	}

	close(i2c_fd);

	return retval;
}

///////////////////////////////////////////////////////////////////////////////
int rpi_get_clock_ms(unsigned long *count)
{
	struct timespec elapsed;
	
	int retval = clock_gettime(CLOCK_MONOTONIC, &elapsed);
	
	*count = (elapsed.tv_sec * 1000) + (elapsed.tv_nsec / 1000000);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
int rpi_delay_ms(unsigned long num_ms)
{
	usleep(num_ms*1000);
	return 0;
}

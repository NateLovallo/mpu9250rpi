#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "SparkFunMPU9250-DMP.h"

int main(int argc, char* args[])
{
	printf("test\n");

	MPU9250_DMP myDmp;
	
	if (myDmp.begin() != INV_SUCCESS)
	{
		printf("Oh no!\n");
	}
	
	while (1)
	{
		if (myDmp.update(UPDATE_TEMP | UPDATE_ACCEL)  != INV_SUCCESS)
		{
			printf("couldnt update\n");
		}
		else
		{
			printf(
				"t: %d \tax: %x \tay: %x \taz:%x\n", 
				myDmp.temperature, 
				myDmp.ax, 
				myDmp.ay, 
				myDmp.az
			);
		}
		usleep(1000*200);
	}
	
	
	
	return 0;
}

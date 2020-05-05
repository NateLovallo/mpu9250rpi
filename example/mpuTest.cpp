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

	myDmp.setSensors(INV_XYZ_GYRO | INV_XYZ_ACCEL | INV_XYZ_COMPASS);
	
	while (1)
	{
		if (myDmp.update(UPDATE_TEMP | UPDATE_ACCEL | UPDATE_GYRO | UPDATE_COMPASS)  != INV_SUCCESS)
		{
			printf("couldnt update\n");
		}
		else
		{
			printf(
				"t: %d\n", 
				myDmp.temperature / (65536)
			);

			printf(
				"ax: %d \tay: %d \taz:%d\n",
				myDmp.temperature / (65536),
				myDmp.ax,
				myDmp.ay,
				myDmp.az
			);

			printf(
				"gx: %d \tgy: %d \tgz:%d\n",
				myDmp.temperature / (65536),
				myDmp.gx,
				myDmp.gy,
				myDmp.gz
			);

			printf(
				"mx: %d \tmy: %d \tmz:%d\n",
				myDmp.temperature / (65536),
				myDmp.mx,
				myDmp.my,
				myDmp.mz
			);

		}
		usleep(1000*200);
	}
	
	
	
	return 0;
}

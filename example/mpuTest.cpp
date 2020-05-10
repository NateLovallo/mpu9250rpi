#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "SparkFunMPU9250-DMP.h"

#include "Mpu9250.h"

int main(int argc, char* args[])
{
	printf("test\n");


	Mpu9250 test;

	

	while (1)
	{
		test.SampleAccelerometer();
		test.SampleTemperature();
		usleep(500 * 1000);
	}


	/*
	MPU9250_DMP myDmp;
	
	if (myDmp.begin() != INV_SUCCESS)
	{
		printf("Oh no!\n");
	}

	myDmp.setSensors(INV_XYZ_GYRO | INV_XYZ_ACCEL | INV_XYZ_COMPASS);
	
	while (1)
	{
		if (myDmp.update(UPDATE_TEMP | UPDATE_ACCEL | UPDATE_GYRO | UPDATE_COMPASS) != INV_SUCCESS)
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
				"ax: %f G \tay: %f G\taz:%f G\n",
				myDmp.calcAccel(myDmp.ax),
				myDmp.calcAccel(myDmp.ay),
				myDmp.calcAccel(myDmp.az)
			);

			printf(
				"mx: %d \tmy: %d \tmz:%d \t Heading: %f\n",
				myDmp.mx,
				myDmp.my,
				myDmp.mz,
				myDmp.computeCompassHeading()
			);



		}
		usleep(1000*200);
	}
	
	*/
	
	return 0;
}

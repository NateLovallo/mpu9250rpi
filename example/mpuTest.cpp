#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "SparkFunMPU9250-DMP.h"

#include "Mpu9250.h"

int main(int argc, char* args[])
{
	printf("test\n");


	Mpu9250 test;

	for (int i = 0; i < 10; i++)
	{
		test.SampleAccelerometer();
		test.SampleTemperature();
		usleep(500 * 1000);
	}

	printf("RESET-------------\n");
	test.ResetSignalPath();

	for (;;)
	{
		test.SampleAccelerometer();
		test.SampleTemperature();
		usleep(500 * 1000);
	}

	
	return 0;
}

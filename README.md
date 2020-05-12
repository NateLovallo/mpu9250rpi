This is a fork of Sparkfun's Arduino library for the MPU9250 IMU
https://github.com/sparkfun/SparkFun_MPU-9250-DMP_Arduino_Library

It's a port to the Raspberry Pi as a static library using CMAKE

The I2C IO is handled using /dev/i2c-1
Sleeps are handled by usleep()
Time comes from clock_gettime(CLOCK_MONOTONIC,...)
All logs go to printf

I *think* it works, but it needs more formal testing
Let me know if you find it useful

To build:
```
mkdir build

cd build

cmake ../ -G Ninja

ninja
```
To run test:

```
./mpuTest
```

Dependencies:

```
sudo apt install libi2c-dev cmake ninja-build
```

This is a fork of Sparkfun's Arduino library for the MPU9250 IMU

I am attempting to port it to the Raspberry Pi as a static library using CMAKE

It doesn't work yet

The goal is to use /dev/i2c-1 for a simple user space driver with no interrupts

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

Ideally I want to figure out how to use IIO subsystem built into linux but the interrupts need to be figured out

This is a fork of Sparkfun's Arduino library for the MPU9250 IMU, ported to the Raspberry Pi using CMAKE and libi2c

It doesn't work yet

The goal is to use /dev/i2c-1 for a simple user space driver with no interrupts

Dependencies:
libi2c-dev
(sudo apt install libi2c-dev)

Ideally I want to figure out how to use IIO subsystem built into linux but the interrupts need to be figured out

# CMAKELists

cmake_minimum_required (VERSION 3.1)
project (mpu9250)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
set(CMAKE_CXX_STANDARD 17)

include_directories (include)
#link_directories (${GLIB2_LIBRARY_DIRS} ${GIO_LIBRARY_DIRS} ${GTKMM_INCLUDE_DIRS_LIBRARY_DIRS})

set(PROJECT_SOURCES
"src/SparkFunMPU9250-DMP.cpp"
"src/util/arduino_mpu9250_clk.c"
"src/util/arduino_mpu9250_i2c.cpp"
"src/util/arduino_mpu9250_log.cpp"
"src/util/inv_mpu.c"
"src/util/inv_mpu_dmp_motion_driver.c"
)

add_library (mpu9250 ${PROJECT_SOURCES})

target_link_libraries (mpu9250 LINK_PUBLIC m libi2c)

# CMAKELists

cmake_minimum_required (VERSION 3.1)
project (libmpu9250)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
set(CMAKE_CXX_STANDARD 17)

include_directories (src)

set(LIBRARY_SOURCES
"src/SparkFunMPU9250-DMP.cpp"
"src/util/rpi_porting.c"
"src/util/inv_mpu.c"
"src/util/inv_mpu_dmp_motion_driver.c"
)

add_library (mpu9250 ${LIBRARY_SOURCES})

target_link_libraries (mpu9250 m)

set(EXAMPLE_SOURCES
"example/mpuTest.cpp"
)
add_executable (mpuTest ${EXAMPLE_SOURCES})

target_link_libraries (mpuTest LINK_PUBLIC mpu9250)

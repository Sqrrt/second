cmake_minimum_required(VERSION 3.21)
project(olegg C)

set(CMAKE_C_STANDARD 99)

add_executable(olegg main.c matrix.c matrix.h RINGINFO.c RINGINFO.h main.c)

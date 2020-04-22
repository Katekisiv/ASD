cmake_minimum_required(VERSION 3.15)
project(ASD C)

set(CMAKE_C_STANDARD 99)

add_executable(ASD main.c helpers.c helpers.h task.c task.h)
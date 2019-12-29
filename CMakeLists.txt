cmake_minimum_required(VERSION 2.15)
project(Coding)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCE_SRC "src/*.cpp")

add_executable(Coding main.cpp ${SOURCE_SRC} src/DynamicProgramming.cpp include/DynamicProgramming.h)
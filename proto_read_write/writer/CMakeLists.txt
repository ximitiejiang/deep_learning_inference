cmake_minimum_required(VERSION 3.14)
project(writer)

set(CMAKE_CXX_STANDARD 14)
include_directories(../data)
include_directories(/home/ubuntu/anaconda3/include)
add_executable(writer writer.cpp)
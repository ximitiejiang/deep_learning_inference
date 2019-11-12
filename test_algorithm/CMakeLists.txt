cmake_minimum_required(VERSION 3.14)
project(teat)

set(CMAKE_CXX_STANDARD 14)
include_directories(./algorithms)
include_directories(./utils)

file(GLOB Sources *.cpp)
file(GLOB Includes *.h)
add_executable(test ${Sources} ${Includes})
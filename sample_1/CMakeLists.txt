cmake_minimum_required(VERSION 3.14)
project(sample_1)
set(CMAKE_CXX_STANDARD 14)
add_subdirectory(src)

#　由于cuda主编译器打印出来为空，暂时注释掉
#set(CMAKE_CUDA_HOST_COMPILER ${CMAKE_CXX_COMPILIER})
#message(STATUS "cuda host compiler: ${CMAKE_CXX_COMPILIER}")




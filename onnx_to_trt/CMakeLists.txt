# 来自tensorRTc++堆里遭找到的
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(onnx_mnist)

# Enable all compile warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -Wno-deprecated-declarations")
# Use C++11
set(CMAKE_CXX_STANDARD 11)

# 自定义了一个宏指令：set_ifndef，用来操作当var不存在时，设置默认的val值
macro(set_ifndef var val)
    if (NOT ${var})
        set(${var} ${val})
    endif()
    message(STATUS "Configurable variable ${var} set to ${${var}}")
endmacro()

# -------- CONFIGURATION --------
find_package(CUDA REQUIRED)

set(TRT_LIB /home/ubuntu/TensorRT-6.0.1.5/lib)         # 存放libnvinfer.so等动态库
set(TRT_INCLUDE /home/ubuntu/TensorRT-6.0.1.5/include) # 存放NvInfer.h等头文件
set(CUDA_ROOT /usr/local/cuda-9.0)

#set_ifndef(TRT_LIB /usr/lib/x86_64-linux-gnu)
#set_ifndef(TRT_INCLUDE /usr/include/x86_64-linux-gnu)
#set_ifndef(CUDA_ROOT /usr/local/cuda)

# Find dependencies:
message("\nThe following variables are derived from the values of the previous variables unless provided explicitly:\n")

# TensorRT's nvinfer lib
find_library(_NVINFER_LIB nvinfer HINTS ${TRT_LIB} PATH_SUFFIXES lib lib64)
set_ifndef(NVINFER_LIB ${_NVINFER_LIB})

# cuBLAS
find_library(_CUBLAS_LIB cublas HINTS ${CUDA_ROOT} PATH_SUFFIXES lib lib64)
set_ifndef(CUBLAS_LIB ${_CUBLAS_LIB})

# CUDA include dir
find_path(_CUDA_INC_DIR cuda_runtime_api.h HINTS ${CUDA_ROOT} PATH_SUFFIXES include)
set_ifndef(CUDA_INC_DIR ${_CUDA_INC_DIR})

# common include
#set(COMMON_INC_DIR /home/ubuntu/TensorRT-6.0.1.5/samples/common)
set(COMMON_INC_DIR ../common)

# -------- BUILDING --------
#include_directories(${TRT_INCLUDE} ${CUDA_INC_DIR})
#add_library(flattenconcat MODULE
#    ${CMAKE_SOURCE_DIR}/plugin/FlattenConcat.cpp
#)

file(GLOB Sources *.cpp)        # 查找cpp文件和h头文件作为接下来可执行文件生成的支持文件
file(GLOB Includes include/*.h)

add_executable(onnx_mnist ${Sources} ${Includes})
# Link TensorRT's nvinfer lib
#target_link_libraries(flattenconcat PRIVATE ${NVINFER_LIB} ${CUBLAS_LIB})
target_include_directories(onnx_mnist PRIVATE ${TRT_INCLUDE} ${CUDA_INC_DIR} ${COMMON_INC_DIR})
target_link_libraries(onnx_mnist ${NVINFER_LIB} ${CUBLAS_LIB})



#target_include_directories(onnx_mnist PUBLIC ${CUDA_INCLUDE_DIRS} ${TENSORRT_INCLUDE_DIR})
#target_link_libraries(onnx_mnist ${CUDA_LIBRARIES} ${TENSORRT_LIBRARY} ${CUDA_CUBLAS_LIBRARIES} ${CUDA_cudart_static_LIBRARY} ${OpenCV_LIBS})

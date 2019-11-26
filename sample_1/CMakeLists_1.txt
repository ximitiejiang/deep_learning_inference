cmake_minimum_required(VERSION 3.14)
project(onnx_to_trt)
set(CMAKE_CXX_STANDARD 14)             # 相当于-std=gnu++11
set(CMAKE_CUDA_HOST_COMPILER ${CMAKE_CXX_COMPILIER})  # 设置主编译器
find_package(CUDA)       # 查找CUDA cmake module进行调用

# 修改显卡计算能力

set(PROJECT_OUTPUT_DIR ${PROJECT_BINARY_DIR}/${CMAKE_SYSTEM_PROCESSOR})  # 项目输出路径？  cmake系统处理器？
set(PROJECT_INCLUDE_DIR ${PROJECT_OUTPUT_DIR}/include)          # 项目include路径?

file(MAKE_DIRECTORY ${PROJECT_INCLUDE_DIR})             # 创建项目include路径
file(MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR}/bin)          # 创建项目输出路径

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/bin)  # .exe .dll 可执行文件生成路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)  # .dll .so  动态库生成路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)  # .lib .a   静态库生成路径

include_directories(${PROJECT_INCLUDE_DIR})         # 包含项目include路径？
include_directories(${PROJECT_SOURCE_DIR}/include)  # 包含项目路径

file(GLOB Sources *.cpp)        # 查找cpp文件和h头文件作为接下来可执行文件生成的支持文件
file(GLOB Includes include/*.h)

foreach(include ${Includes})    #  include ?   configure_file ?
    message("-- Copying ${include}")
    configure_file(${include} ${PROJECT_INCLUDE_DIR} COPYONLY)
endforeach()

find_package(Protobuf)            # 查找protobuf的cmake module，并输出其版本等信息
if(PROTOBUF_FOUND)
    message(STATUS "    version: ${Protobuf_VERSION}")
    message(STATUS "    libraries: ${PROTOBUF_LIBRARIES}")
    message(STATUS "    include path: ${PROTOBUF_INCLUDE_DIR}")
else()
    message(WARNING "Protobuf not found, onnx model convert tool won't be built")
endif()

set(TENSORRT_ROOT /home/ubuntu/TensorRT-6.0.1.5)   # 设置tensorRT安装路径
# 在tensorRT的include路径中查找NvInfer.h头文件
find_path(TENSORRT_INCLUDE_DIR NvInfer.h
        HINTS ${TENSORRT_ROOT} ${CUDA_TOOLKIT_ROOT_DIR}
        PATH_SUFFIXES include)

#
find_library(TENSORRT_LIBRARY_INFER nvinfer
        HINTS ${TENSORRT_ROOT} ${TENSORRT_BUILD} ${CUDA_TOOLKIT_ROOT_DIR}
        PATH_SUFFIXES lib lib64 lib/x64)

find_library(TENSORRT_LIBRARY_INFER_PLUGIN nvinfer_plugin
        HINTS  ${TENSORRT_ROOT} ${TENSORRT_BUILD} ${CUDA_TOOLKIT_ROOT_DIR}
        PATH_SUFFIXES lib lib64 lib/x64)

set(TENSORRT_LIBRARY ${TENSORRT_LIBRARY_INFER} ${TENSORRT_LIBRARY_INFER_PLUGIN})
MESSAGE(STATUS "Find TensorRT libs at ${TENSORRT_LIBRARY}")


include_directories(../common)
include_directories(/home/ubuntu/TensorRT-6.0.1.5/include)
include_directories(/usr/local/cuda-9.0/include)




cuda_add_executable(tensorrt benchmark.cpp)

target_include_directories(tensorrt PUBLIC ${CUDA_INCLUDE_DIRS} ${TENSORRT_INCLUDE_DIR})
target_link_libraries(tensorrt ${CUDA_LIBRARIES} ${TENSORRT_LIBRARY} ${CUDA_CUBLAS_LIBRARIES} ${CUDA_cudart_static_LIBRARY} ${OpenCV_LIBS})
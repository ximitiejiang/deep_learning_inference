find_package(CUDA REQUIRED)
#set(TRT_LIB /home/ubuntu/TensorRT-6.0.1.5/lib)         # 存放libnvinfer.so等动态库
#set(TRT_INCLUDE /home/ubuntu/TensorRT-6.0.1.5/include) # 存放NvInfer.h等头文件

set(CUDA_ROOT /usr/local/cuda-9.0)
set(TRT_ROOT /home/ubuntu/TensorRT-6.0.1.5)
#set(COMMON_ROOT /home/ubuntu/suliang_git/deep_learning_inference/onnx_to_trt/common)

# --- find library ---
find_library(NVINFER_LIB nvinfer HINTS ${TRT_ROOT}/lib PATH_SUFFIXES lib lib64)
find_library(CUBLAS_LIB cublas HINTS ${CUDA_ROOT} PATH_SUFFIXES lib lib64)
message(STATUS "nvinfer lib: ${NVINFER_LIB}")
message(STATUS "cublas lib: ${CUBLAS_LIB}")
find_library(CUDART_LIB cudart HINTS ${CUDA_ROOT} PATH_SUFFIXES lib lib64)
message(STATUS "cudart lib: ${CUDART_LIB}")
# TODO: common的lib似乎没有看到，所以gLogInfo找不到

# --- find include dir ---
find_path(CUDA_INC_DIR cuda_runtime_api.h HINTS ${CUDA_ROOT} PATH_SUFFIXES include)
find_path(TRT_INC_DIR NvInfer.h HINTS ${TRT_ROOT}/include)
message(STATUS "cuda include dir: ${CUDA_INC_DIR}")
message(STATUS "trt include dir: ${TRT_INC_DIR}")
#find_path(COMMON_INC_DIR logger.h HINTS ${COMMON_ROOT})
#message(STATUS "common root: ${COMMON_ROOT}")
#message(STATUS "common_include_dir: ${COMMON_INC_DIR}")


# --- build ---
include_directories(${TRT_INC_DIR} ${CUDA_INC_DIR})  # 强制指定头文件和对应cpp文件从本目录下去找
file(GLOB Sources *.cpp)
file(GLOB Includes include/*.h)
message(STATUS "cpp file: ${Sources}")
message(STATUS "head file: ${Includes}")
add_executable(onnx_mnist ${Sources} ${Includes})
target_link_libraries(onnx_mnist ${NVINFER_LIB} ${CUBLAS_LIB} ${CUDART_LIB})

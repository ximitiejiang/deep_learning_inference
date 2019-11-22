//
// Created by ubuntu on 19-11-21.
//

#include "argsParser.h"
#include "buffers.h"
#include "common.h"
#include "logger.h"
#include "parserOnnxConfig.h"

#include "NvInfer.h"
#include <cuda_runtime_api.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>


#include <string>

const std::string gSampleName = "TensorRT.sample_onnx_mnist";


// 定义一个项目作为一个类
class SampleOnnxMNIST{

    //定义别名给智能指针，指向
    // SampleCommon为命名空间，位于argsParser.h
    template <typename T>
    using SampleUniquePtr = std::unique_ptr<T, samplesCommon::InferDeleter>;

public:
    SampleOnnxMNIST(){}
    bool build();
    bool infer();

private:
    // 参数
    mParams;
    // 创建网络
    bool constructNetwork();
    // 处理输入
    bool processInput();
    // 验证输出
    bool verifyOutput();

};

// --------------------------------------------
bool SampleOnnxMNIST::build(){

}

bool SampleOnnxMNIST::infer(){

}

bool SampleOnnxMNIST::constructNetwork() {

}

bool SampleOnnxMNIST::processInput() {

}

bool SampleOnnxMNIST::verifyOutput() {

}


// 初始化参数
void initializeSampleParams(){


}
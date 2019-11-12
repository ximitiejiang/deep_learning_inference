//
// Created by ubuntu on 19-11-12.
//

#ifndef TEAT_TEST_CLASS_H
#define TEAT_TEST_CLASS_H

#include "arg_parse.h"

// 尝试写一个结构体没有声明是否可以加方法

struct sParams{
    int a{1};
    int b{-1};
    std::vector<std::string> dataDirs;
};


sParams initializeParams(Args &args){
    sParams params;
    std::cout << "this is sParams initialize." << std::endl;
    return params;
}
#endif //TEAT_TEST_CLASS_H

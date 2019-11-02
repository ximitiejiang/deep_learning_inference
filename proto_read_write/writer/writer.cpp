#include "addressbook.pb.h"
#include <iostream>
#include <fstream>
using namespace std;


// 这部分代码用来基于自定义的protobuf数据结构，往一个数据文件中写入数据
int main() {
    lm::helloworld msg1;     // 创建一个自定义的数据结构类
    msg1.set_id(205);        // 对该类的属性进行赋值
    msg1.set_str("hello");

    fstream output("./log", ios::out | ios::trunc | ios::binary);  // 把该
    if (!msg1.SerializeToOstream(&output)) {
        cerr << "Failed to write msg." << endl;
        return -1;
    }
    return 0;
}
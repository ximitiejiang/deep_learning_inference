//
// Created by ubuntu on 19-11-12.
//

#ifndef TEAT_ARG_PARSE_H
#define TEAT_ARG_PARSE_H

#include <string>
#include <getopt.h>

// 初始参数结构体
struct Args{
    std::string work_dir{"/home/ubuntu/mytrain/"};
    std::string dataset_dir;
    std::string model_dir;
    bool useGPU{true};
};


// 参数解析器: 用在main函数中协助进行命令行参数解析
//1. 针对短选项(也就是以-开头)，getopt(argc, argv, optstring)传入3个部分：argc为参数个数，argv为参数字符串指针数组，optstring为选项，
// 比如ab:c::d:表示-a,-b,-c,-d，其中-a可以不跟参数，其他有冒号的都要跟参数，一个冒号说明参数与选项之间有一个空格或没有，两个冒号说明参数与选项之间不能有空格
// 所以输入命令行参数应该类似于：./a.out -a -b st1 -cst2 -d st3
//
//2. 针对长选项(也就是以--开头)，getopt_long(argc, argv, optstring, longopts, longindex):
// - argc为参数个数，argv为参数字符串指针数组，
// - optstring为选项，optstring设为NULL或空则只支持长选项，否则optstring设置为短选项名。
// - longopts代表定义struct option结构体，在getopt.h中有定义，包括{const char *name; int has_arg; int *flag; int val;} 中间name为长选项名，
// has_arg设置为no_argument或0为不带参，required_argument或1为带参，flag=0则返回0，否则返回val。 val为返回值，一般设置为短选项
// 注意该struct option结构体最后一行需要为全0
// - longindex代表输出参数的指针，返回的是struct option的索引
// - 返回值：识别为短选项时则返回短选项，识别为长选项时返回val(flag=NULL)或者0(flag!=NULL)，解析结束返回-1， 不能识别返回?
//
//3. 对应的全局变量：
// - extern char *optarg指向当前选项所带参数
// -

bool argParser(Args &args, int argc, char *argv[]){  // 传入的args对象用来存放从命令行来的参数
    int arg;
    while(true){
        // 定义命令行参数
        static struct option long_options[] = {
                {"datasetdir", required_argument, 0, 'd'},
                {"model_dir",  required_argument, 0, 'm'},
                {0,            0,                 0,  0 }
        };
        // 定义参数返回值
        int option_index = 0;
        arg = getopt_long(argc, argv, "d:m:", long_options, &option_index); // 函数的返回值每次返回一个参数的
        // 提取命令行参数
        if(arg == -1)
            break;
        switch (arg){
            case 'd':
                args.dataset_dir = optarg;
                break;
            case 'm':
                args.model_dir = optarg;
                break;
            default:
                return false;
        }
    }
    return true;
}


#endif //TEAT_ARG_PARSE_H

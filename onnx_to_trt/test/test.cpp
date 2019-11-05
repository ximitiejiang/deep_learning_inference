//
// Created by ubuntu on 19-10-31.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <cstdlib>
#include <memory>
#include <stdio.h>

// 该类参考CP-405，用于验证智能指针
class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;  // 定义一个类型
    StrBlob();  // 构造函数

    StrBlob(std::initializer_list<std::string> il);  // 自定义构造函数：从而可以接受花括号列表初始化
    size_type size() const{    // 创建获取size的函数，const类型
        return data->size();
    }
    bool empty() const{        // 创建判断你是否为空函数
        return data->empty();
    }
    void push_back(const std::string &t){   // 创建增加元素的函数
        data->push_back(t);
    }
    void pop_back();
    std::string &front();
    std::string &back();

private:
    std::shared_ptr<std::vector<std::string>> data;  // 创建一个data智能指针
    void check(size_type i, const std::string &msg) const;  // 创建一个检查是否合法的函数

};


int main()
{
//    // 数组的创建和初始化，输出合理，是指针地址
//    int arr1[] =  {1,2,3};
//    int *arr2 = arr1;
//    std::cout << arr1 << std::endl;
//    std::cout << arr2 << std::endl;
    int *p1 = ;

    // 字符串
    char *p0 = "abc";      // p0是一个指针，相当于P0[4]
    printf("p0 address: %d", p0);  //p0

    std::cout << p0 << std::endl;
    std::cout << p0[1] << std::endl;

    char *str[3] = {"hello", "world", "lake"};
    std::cout << str[2];    //用字符指针输出：居然就是字符串

    char str0;

    std::cin >> str0;
    std::cout << "this is str0 input: " << str0 << std::endl;

    int *ip[5];
//    int (*ipp)[5] = {1,2,3,4,5};

    return 0;

}
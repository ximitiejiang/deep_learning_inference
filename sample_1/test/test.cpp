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

// 结论：char *argv[]的写法，argv是一个数组名，里边存放字符指针。而字符指针可以指向一个字符，也可以指向一个字符串(也就是字符数组)
// 也就是char* p 与char q[]是基本类似的用法，虽然两者有一些差别。
void testArgv(){
    char * argv[] = {"hello", "world"};
    std::cout << argv[0] << " " << sizeof(argv[0]) << std::endl ;
    std::cout << argv[1] << " " << sizeof(argv[1]) << std::endl;
}


int main()
{
    testArgv();


    return 0;

}
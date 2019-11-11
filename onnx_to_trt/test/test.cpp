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

class Base{
public:
    int a1 = 0;
private:
    int a2 = 1;
protected:
    int a3 = 3;
};

class Drive : public Base{
public:
    void print(){
        std::cout << a1 << " ";
//        std::cout << a2 << " "; // 派生类不可访问private
        std::cout << a3 << " ";  // 派生类内可访问protected
    }
};

int main()
{
    Base b;
    Drive d;
    d.print();
    b.a1;
//    b.a2;  // 类外不可访问private
//    b.a3;  // 类外不可访问protected
    std::cout << d.a1;  // 派生类外
    std::cout << d.a3;


    return 0;

}
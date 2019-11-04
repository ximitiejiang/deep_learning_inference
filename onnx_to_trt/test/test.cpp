//
// Created by ubuntu on 19-10-31.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <cstdlib>

// 该类参考CP-405，用于验证智能指针
class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;  // 定义一个类型
    strBlob();  // 构造函数
    strBlob(std::initializer_list<std::string> il);  // 自定义构造函数：从而可以接受花括号列表初始化
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
    char *str[] = {"hi", "there"};
    cout << *(str[0]+1) << endl;


    srand(4);
    int num = rand() %(5+1); // 0-5的随机数
    cout << num << endl;
    num = rand() %(5+1);
    cout << num << endl;
    num = rand() %(5+1);
    cout << num << endl;
    num = rand() %(5+1);
    cout << num << endl;


    return 0;

}
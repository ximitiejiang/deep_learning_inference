# C++编程cheat sheet

### 关于clion
1. 打开clion: 创建快捷方式
2. 创建md文件：new/file, xxx.md直接指定后缀名即可，clion自带md预览
3. 创建cpp文件：new/file, xxx.cpp
4. 创建cmakelist: 
5. 输入中文：clion安装好后不能输入中文，需要修改clion.sh：在Run the IDE段落前面添加(不能添加到最后，否则也没效果)：
```
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx
```
6. 调试：几个核心快捷键(可以考虑自定义快捷键把n, c, s, u, d设置出来???)
```
ctrl + /        //表示多行注释
F8              //单步=n
F7              //进入子函数=s
shift + F8      //返回=u
F9              //运行到断点=c
```


### 关于CmakeLists
1. cmakelists的功能，就是自动生成makefile，如果有cmakelists，则编译过程就是如下：
这是典型out_source方式，也就是外部搜索，然后生成文件到当前指定文件夹下，避免大量文件干扰代码目录。
而在clion中则不需要考虑out_source，他会自动把根目录下cmakelists生成的makefile等文件放入一个cmake-build-debug文件夹中
```
mkdir build
cd build
cmake ..       //这里两个点表示在上层文件夹下寻找cmakelists生成makefile和相关文件
make           //执行makefile
make install   //安装
```
2. 在一个大项目下面，可以有独立的小项目，每个独立小项目都对应一个独立cmakelists：
- 创建小项目文件夹，里边生成小项目cmakelists, cpp, .h文件
- 右键点击任何一个cmakelists，都可以看到2个选项之一：如果已经是当前cmakelists，会看到reload cmakelists选项。
而如果不是当前cmakelists，则会看到load cmakelists选项，点击以后就会切换到该cmakelists对应的子项目中，并且能独立运行。

3.默认cmakelists包含4部分(但最简就是2句，project + add_executable)
```
cmake_minimum_required(VERSION 3.14)   //optional, 定义cmake最低版本
project(onnx_to_trt)                   //项目名称，默认是项目文件夹名称
set(CMAKE_CXX_STANDARD 14)             //optional, 设置c++14为标准
add_executable(onnx_to_trt main.cpp)   //定义生成的可执行文件名和支持文件
```
3. 如果要增加c++11的相关特性，比如nullptr，则增加该句，放在add_executable()前面：
```
add_definitions(-std=c++11)
```
4. 如果要单独一个src子文件夹放置.cpp和.h文件，则需要在根路径的cmakelists增加这句，同时src文件夹下增加额外cmakelists文件。
参考Teris源码。此时，主目录下的cmakelists主要用来包含src文件夹，并没有生成可执行文件，而src里边的cmakelists则会有生成可执行文件。
```
add_subdirectory(src)
```
5. 如果要包含.so库文件，则需要增加这句：
```
link_libraries(/usr/lib/xxx.so /usr/lib/xxx.so)
```
6. 如果要包含头文件搜索目录，则需要增加这句
```
include_directories(./common)
```

### 关于c++11的新特性
1. 如果要用c++11的新特性，需要编译时增加一句话：
```add_definitions(-std=c++11)```

2. c++11的新特性包括：
```
auto aa = 25.0/7;   //auto类型
```

### 关于头文件
1. c语言的头文件，一般带有h后缀名<abc.h>，比如<stdio.h>, <string.h>
   c++的头文件，一般是直接的不带后缀名<abc>, 比如<iostream>, <string>

2. 自定义的头文件开头必须增加如下语句：目的是防止同一个头文件因为被不同cpp文件所包含导致被重复编译而造成错误
```
#ifndef xxx
#define xxx
#endif
```
这句也可以用一句代替：但该句在有的老编译器不支持，所以前面3句用得更多。
```#pragma once```
3. 头文件中，尽量不要包含using namespace类型语句，因为他会把这句带入所有引用他的源文件而源文件却没有意识到。


### 关于命名方式
1. 如果是类，则首字母大写，每个单词首字母也大写：GraduateStudent，对应头文件.h和对应源码文件.cpp的名称跟类名一致
2. 如果变量名、函数名，则首字母小写，剩下单词首字母大写
3. 


### 关于创建变量和常量和命名方式：

1. 创建普通变量：
`int a = 1;`
3. 创建自动推断类型变量：
```auto aa = 25.0/7;```
4. 创建某种变量的别名：这样便于统一修改这类变量的类型，直接修改typedef的定义就可以一次性修改所有同类变量的类型
```
typedef double db;
db aa = 3.24;
```
5. 创建常量：
```
const float a=3.14   // 这种定义会在编译的时候处理，进行数据语法检查
#define aa 3.14      // 这种定义在预编译的时候处理，只进行纯字符串替换，不做语法检查(可能导致后期报错)
```


### 关于名称空间
- 标准名称空间的应用方式为std::cout
- 整个名称空间导入的方式using std, 这样std下面所有名称都可以直接用，省去输入std，但可能有重名风险
- 部分名称空间导入的方式using std::cout，从而cout可以直接用
- 自定义名称空间：namespace abc {}
```
namespace abc 
{
    int    
}
```

### 关于输入输出语句
1. 如果是用c++的类型，则包含iostream，且不需要考虑类型
```
#include <iostream>
cout << "hello" << endl;
```
2. 如果是用c的类型，则包含stdio.h, 且需要自己指定数据类型
```$xslt
#include <stdio.h>
printf("a=%d", d)
```


### 关于结构体
1. 结构体跟类的声明基本一样，唯2的两个差别：关键字不同(struct, class), 默认访问权限不同(结构体public, 类private)
2. 结构体声明：
```$xslt
struct Account
{
    int a;
    Account(int m, int n){}
};
```

### 关于数组
1. 使用静态数组，也就是c++默认的数组
缺点是：必须在初始化固定长度，且不能增加长度
```
int a[4] = {1,2,3};
cout << a[1] << endl;
sizeof(a)/sizeof(*a)   // 获取数组元素个数

```
2. 使用动态数组，也即是STL库里边的vector，
优点是: 可以直接用a.size()获得长度，可存放任何别的数据类型，初始化后，可以用push_back()增加长度
注意：如果要增加长度，就不能用在for循环，因为会导致for循环不知道循环次数
```
#include <vector>
vector<int> a;      //空数组
vector<int> a(10);
vector<int> a(10, 3);  
vector<int> a={1,2,3};  //甚至可以写成vector<int> a{1,2,3}; 但不过是c++11的特性
vector<string> b = {"ab", "cd", "hello"}
a.push_back(3)
vector vb(va.begin()+1, va.begin()+3);   //vector切片
```

### 关于字符串
0. 在c++中单字符用单引号'c'，字符串用双引号"ccc"

1. 使用c风格字符串: 一般包含<cstring>这是c++为c的string准备的新库，对应原来的<string.h>
缺点是：
```
#include <csring>
char str1[] = "hello";
```
2. 使用c++风格字符串：一般包含<string>
优点是：可以直接获得长度a.size()和a.empty()的结果
```
#include <string>
string aa = "hello world";
string aa("hello world");    // 既可以用传统等号赋值，也可以用对象的方式赋值
string aa(10, 'c')
s.size();
s[2];
s1+s2;
s1==s2;
s.substr(start, len);       // 字符串切片

#include <cctype>
isalnum(a)  # 判断是alpha单字母或者数字
isalpha(a)
islower(a)
isspace(a)
isupper(a)
```


### 基本运算
```
c = a + b
a / 5                           // 取整
a % 2                           // 取余
a ++; ++a; a--; --a;            // ++在前则先加后运算，++在后则先运算后加
a *= 2;
true; false; a && b; a|| b; !a;  // 逻辑操作
a & b; a|b; ~a; ^a; a << 10;     // 按位操作
```

### 基本语句
1. c++的语句中，没有冒号，都被大括号{}代替作为分割语句的标识
```
if(){}
if()            //如果if之后只有一句，则不用写中括号
else if(){}
else{}

while() {}

for(int i=0;i<5;i++){}
for(int &a : aa) {a *= 2}   // 类似于python更高效的写法，无需引入flag，但是c++11的特性


switch(){
case 0: break;
case 1: break;
default:
}
```


### 关于数据格式变换
```
int b = (int)a;
```



### 关于引用和指针
0. c++之所以要有引用和指针，因为c++中所有传入数据都是新建内存方式，跟原来数据无关，但c++为了强调节省内存，所以提供引用和指针避免新建内存。
而在别的语言比如python，常规数据对象也都是不可变对象(如int/str/tuple)，却没有相应节省内存的指针引用，所以消耗内存肯定比c++大。
*号原本是，&原本是取地址操作符

1. 引用是原来变量的别名，指向同一内存地址。优点是作为函数形参从而函数体内无需创建新内存。
```
int& b = &a;
```
2. 指针是原来变量的地址，
```
int* p = &age;

```
3. 区别常量指针和指针常量


4. 数组名和指针名完全等价，都是指针，所以既可以用数组的方式调用，也可以用指针的方式调用
```

```

### 关于函数
1. 定义函数
```
int func(int x, int y)
{   return 0
}
```
2. 形参：

3. 函数重载： 函数名相同，但形参不同，即构成函数重载

4. 内联函数：可减小cpu开销而不用call，缺点是导致代码大小增加，适合一些简单函数
```
inline float getPi(){
    return 3.14
}
```

### 关于类和对象
1. 定义类时，注意分号写法：每句最后需要分号，如果函数定义之后也需要分号，如果函数实现之后则不需要分号，
2. 类定义的内部，可以什么都没有，默认是private模式，写成结构体struct类，则默认是public形式
```
class solution{
public:                 //为了让这个最简单类可用，至少得让函数public化，否则无法调用
    int func(){
        return 0;
    }
}

struct solution{       //或者用struct方式来定义一个类，则不需要写关键字public也可以调用
    int func(){
        return 0;
    }
}
```
2. 类的初始化：要么有定义构造函数，要么就必须用new



### 关于模板
1. 可以用模板方便地扩展一些基本库的功能：
```
template<typename T>
std::vector<T> copyto(std::vector<T> v, int startIndex, int count){
    return std::vector<T>(v.begin()+ startIndex, v.begine()+count);
}
```




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
6. 调试：几个核心快捷键(是否可以考虑自定义快捷键把n, c, s, u, d设置出来???)
```
ctrl + /        //表示多行注释
F8              //单步=n
F7              //进入子函数=s
shift + F8      //返回=u
F9              //运行到断点=c
```
7. 寻找关联文件：
- c++的项目有个问题，就是include之后，头文件里边所有类/命名空间都可以随便用，所以在main文件里边，甚至不知道每个类/命名空间来自于哪个头文件。
这跟python不同，python是可以通过import看得到module的名字，从而知道该类来自哪个module（也可以在IDE中链接过去）。
- 在c++里边，如要知道某个类来自哪个头文件，需要用clion自带搜索快捷键(shift+shift)，可以找到每个类的原始出处。
也可以找到每个namespace的原始出处(如果有多个namespace原始出处，则都会列出来)，非常方便。


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
6. 如果要包含头文件搜索目录，则需要增加这句: 注意如果不确定路径地址可以在终端用locate xxx.h把头文件所在文件夹搜索出来。
该句功能相当于g++中-I的作用。
```
include_directories(./common)
```
7. 如果要自动搜索所有支持文件，则可以考虑自动搜索命令
```
file(GLOB Sources *.cpp)
file(GLOB Includes *.h)
add_executable(Cars ${Sources} ${Includes})
```
8. 如果要


### 关于c++11的新特性
1. 如果要用c++11的新特性，需要编译时增加一句话：
```add_definitions(-std=c++11)```

2. c++11的新特性包括：
```
auto aa = 25.0/7;   //auto类型
```

### 关于头文件
1. c语言的头文件，一般带有h后缀名<abc.h>，比如<stdio.h>, <string.h>，
   c++的头文件，一般是直接的不带后缀名<abc>, 比如<iostream>, <string>，
   在c++代码中，常用头文件包括：
   - `<iostream>` 负责输入输出，必须配合using namespace std;
   - `<string>` 负责新字符串
   - `<vector>` 负责新数组

2. 自定义的头文件开头必须增加如下语句：目的是防止同一个头文件因为被不同cpp文件所包含导致被重复编译而造成错误
```
#ifndef xxx
#define xxx
...
#endif
```
这句也可以用一句代替：但该句在有的老编译器不支持，所以前面3句用得更多。
```#pragma once```
3. 头文件中，尽量不要包含using namespace类型语句，因为他会把这句带入所有引用他的源文件而源文件却没有意识到。



### 关于名称空间
1. 标准名称空间的应用方式为std::cout
2. 整个名称空间导入的方式using std, 这样std下面所有名称都可以直接用，省去输入std，但可能有重名风险
3. 部分名称空间导入的方式using std::cout，从而cout可以直接用
4. 注意：c++中的几个核心库都是在std名称空间之下，比如：
    - `<vector>`库: std::vector
    - `<string>`库: std::string
    - `<iostream>`库: std::cout
5. 自定义名称空间：namespace abc {}
注意：为什么要自定义名称空间，目的是防止名称冲突。常用做法是一个总的代码包定义一个总的命名空间，比如namespace cvpk{},
从而所有自己定义的类和方法的声明都放在里边，程序员保证这个大包内部不会命名冲突而该命名空间保证这个大包不会跟外部冲突。
6. 注意：可对比下python的做法：
    - python在import common之后，其实相当于common就是他的命令空间，需要用common.xx来调用。也就相当于导入module集成了namespace的功能。
    - c++在include "common.h"之后，就能直接用里边的所有模块，中间缺少命名空间的隔离，所以需要用namespace来隔离。
    - c++代码实践时，如果只是自己用在这个项目里，不用自定义namespace也可以，但如果要打包给别人用，最好统一一个namespace。
```
namespace AAA     // 命名空间内可以声明变量/函数/类然后外部实现，也可以同时声明和实现，跟类的方式一样
{
    int aaa=10;     
    void func(){}   
}
```


### 关于命名方式
1. 如果是类，则首字母大写，每个单词首字母也大写：GraduateStudent，对应头文件.h和对应源码文件.cpp的名称跟类名一致
2. 如果变量名、函数名，则首字母小写，剩下单词首字母大写
3. 如果是类的内部变量的命名
例如：
```
class OnnxResNet(){       // 类名称：首字母大写，每个单词首字母大写
public:
    void processInput();  // 函数名：首字母小写，每个单词首字母大写
}

```



### 关于创建变量和常量和命名方式：
1. c++的变量类型
    - int: 4个字节(32位)，这是建议的整形数据类型
    - long：(32位)
    - long long：(64位)，如果int位数不够，建议用longlong而不是long，因为long一般跟int有相同尺寸
    - float：6位有效数字(32位)，单精度
    - double：10位有效数字(64位)，双精度，这是建议的浮点运算类型，因为float往往位数不够，而double的计算代价跟float相差无几
    - bool: true, false
    - char: 字符(8位)
2. 创建普通变量：
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

### 关于变量的类型转换
1. 赋值时bool与int会隐性转换：false/0, true/1
```
if(1){}; if(34){}     //都是为真
if(0){}; if(false){}  //都是为假
```
2. 赋值时浮点与int会隐性转换：浮点赋值给int自动去掉小数点后(不会四舍五入)，int赋值给浮点自动加小数点后的0
3. 计算时的自动转换：原则是尽量避免损失精度，所有低精度的会先转换成高精度的再进行计算
```
int a = 3.14 + 3;  // 先计算时自动转换3为double, 然后赋值给a时再转换为int
```
4. 强制类型转换(显式类型转换)
```
int a=0; int b=1;
double c = a + b;   // 新定义一个类型达到强制转换效果
(double)a+b;        // c语言风格的强制类型转换
double(a+b)         // c++早期函数式强制类型转换
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
2. 在很多情况下，用结构体构建一个简单模块，比用class方便，因为不区分public
3. 结构体声明：
```$xslt
struct Account
{
    int a;
    Account(int m, int n){}
};
```

### 关于迭代器
1. 迭代器的操作是后边vector, map这些顺序容器，关联容器操作的基础，所以必须准确掌握迭代器的通用操作。
迭代器本质就是指针，所以操作跟指针类似。
2. 获取迭代器
```
auto it = v.begin();
auto it = v.end();
```
3. 操作迭代器
```
*it;      // 获取迭代器指向的值
it->mem   // 等效于*it.mem，即用箭头符号代替星号+点号，获取指针指向对象的属性
++iter;
it + 2;
it1 >= it2;
it1 == it2;
it1 != it2;
for(auto it=v.begin();it!=v.end();++iter){}   //迭代器用！=代替<，是因为迭代器都实现了!=，但只有少部分实现<

```


### 关于数组
1. 使用静态数组，也就是c++默认的数组
缺点是：必须在初始化固定长度，且不能增加长度
```
int a[10] = {1,2,3};      // 数组尺寸固定不能修改，可以只初始化其中部分，其他自动用0初始化
int a[] = {1,2,3};        // 数组尺寸不指定，但会根据初始化情况固定，比如这里尺寸会固定成3.
string a[3] = {"hello", "world", "hey"};  // 数组中可以存放任何类型对象
char a[] = {'a','b','c'}; // 字符数组初始化，不会引入\0
char a[] = "abc";         // 一种特殊字符串初始化，此时字符串会引入\0

int *p[10];   // 存放的是10个指针
int (*p)[10]; // 存放的是10个int，但数组名是指针
int (&p)[10]; // 存放的是10个int, 但数组名是引用

for()
sizeof(a)/sizeof(*a)   // 获取数组元素个数

```
2. 使用动态数组，也即是STL库里边的vector，
优点是: 可以直接用a.size()获得长度，可存放任何别的数据类型，初始化后，可以用push_back()增加长度
注意：如果要增加长度，就不能用在for循环，因为会导致for循环不知道循环次数
注意：vector虽然可以下标访问，但决不能访问未初始化的值。
```
#include <vector>
vector<int> a;      //空数组
vector<int> a(10);
vector<int> a(10, 3);  
vector<int> a={1,2,3};  //甚至可以写成vector<int> a{1,2,3}; 但不过是c++11的特性
vector<string> b = {"ab", "cd", "hello"}
a.push_back(3)
vector vb(va.begin()+1, va.begin()+3);   //vector切片

swap(v1, v2)  // 交换两个vector
v2.assign(v1.begin(), v1.begin()+2)//用v2的元素替换v1，但注意：不能用自己的替换自己的，因为自己的指针不能被覆盖


```

### 关于字符串
0. 在c++中单字符用单引号'c'，字符串用双引号"ccc"

1. 使用c风格字符串: 可以看成是字符数组，作为数组来理解
```
char str1[] = {'a','b','c'};  // 数组的方式，长度是3
char str2[] = "abc";          // 字符串方式，长度4，尾部带\0
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


### 关于map和multimap
1. 前面的容器称为顺序容器(vector/string)，而map称为关联容器，也就是key-value关联的字典，通常用来做hash表。
2. map中关键字是唯一的，而multimap的关键字则不唯一。
2. 关联容器的操作跟顺序容器有很多不同
```
map<string, int> person = {{'jack', 14},{'leo',37}};
multimap<string,int>mperson = {{'jack',16},{'jack',25}}  // 可重名
person.insert({key,value});
person.begin()->first;
person.end()->second;       // map里边每个元素是一个pair类型，pair类型可以用.first,.second提取
person.erase(key)
person.erase(iter)   // 迭代器操作
person.find(key)     // 返回迭代器，他比下标访问方法好，不会增加进去 
mperson.count(key)   // 返回个数，如果是map则只会返回0或1
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
for(auto i: data){}      // 简化的for循环写法，类似python
for(auto& i : data){}    // 默认是不能修改源数据，采用引用则能修改
 

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
下面是引用和指针的最基础用法。
```
int& b = a;   // 声明时&代表创建引用，注意引用不是对象，所以指定引用之后不能再改变。
p = &a;       // 使用时&代表获取地址

int* p = &a;  // 声明时*代表创建指针，注意指针也是对象，所以指针指向的对象能够再改变。
c = *p;       // 使用时*代表获取指针指向的值

c = p->empty() // 箭头符号是指针操作，等效于*p.empty()，即用箭头符号等效代替星号+点号
```

1. 区别常量指针和指针常量，以及常量引用：
- 关键理解1：符号*和&作为一个分割符，左边代表所指向容器的类型，右边代表自己的类型。容器的类型决定了能放什么数据，自己的类型决定了有没有修改权限
- 关键理解2：在用等号赋值时，需要左右两边容器相同，或者把低级别容器放入高级别容器，但不能把高级别容器放低级别容器。
  比如在const int *p 的容器中放入普通int或者const int都可以，但在int *p 中不能放入const int。
- 关键理解3：const int &q是指向常量的引用，可以用普通int或常量int放入该引用，但该引用不能修改原引用
```
const int *p = &a;       // 普通指针，指向常量int，
int *const p = &a;       // 常量指针，指向普通int，
const int *const p = &a; // 常量指针，指向常量int，
```

2. 数组名和指针名完全等价，都是指针，所以既可以用数组的方式调用，也可以用指针的方式调用
```

```
3. 创建空指针: 以下三种方法等效，都能创建
``` 
int *p = nullptr; // c++推荐的方式创建空指针
int *p = 0;      // 早期做法
int *p = NULL;   // c之前做法，需要include <cstdlib>
if(p){}          // 如果指针不为空相当于true，如果指针为空则相当于false
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

### 算法中的时间复杂度和空间复杂度
1. 时间复杂度：是指循环整个数据n的总次数，通常遍历一次为n, 嵌套遍历为O(n2)
- O(1): 是指在固定次数的循环中就能完成，跟总个数n没有关系。
- O(logn): 理解logn是指2为底的对数值，相当于执行了n/2/2/2/...次，也就是循环每次执行剩余一半的数据进行遍历，这比进行一轮总计n次的遍历高效一些。
主要是在二分类型的算法中体现，比如二分搜索。
- O(n)：就是一轮完整遍历(一个for循环)
- O(nlogn): 就是嵌套两轮遍历，但其中一轮每次执行剩余一半数据的遍历，另一轮执行完整遍历。
- O(n2)：就是嵌套两轮完整遍历(两个for循环)
- O(n3)：就是嵌套三轮完整遍历(三个for循环)
- O(2^n)：就是指数次遍历

2. 通常来说O(1) < O(logn) < O(n) < O(n2) < O(n3) < O(2^n), 相当于O(n)是线性的一象限45度分割线，他下面的线是O(logn), 他上面的是O(n2)...

3. 算法中最常用计算时间的方式：
```
#include <time.h>
clock_t start, end;   // 定义两变量
start = clock();
...
end = clock();        // 计时
elaps = (end - start)/CLOCK_PER_SEC;  // 计算结果
```
4. 算法中最常用交换2个数：
```
std::swap(a, b)
```

### 算法中的排序(3大核心问题之一)
1. 用函数sort()进行排序
2. 


### 算法中的搜索(3大核心问题之一)
1. 顺序搜索：也就是一个循环去搜索，通常时间复杂度为O(n)
```

```
2. 二叉树搜索：先进行排序，然后二叉搜索(也叫二分搜索)，此时时间复杂度O(log2(n))
```
def search(vector<int> & nums, target){
    snums = sorted(nums)
    int left =0;int right=nums.size()-1;
    while(left <= right){
        mid = (left + right) / 2;
        if(target == snums[mid])
            return mid;
        else if(target < snums[mid])
            right = mid;
        else if(target > snums[mid]
            left = mid;
}
```


### 算法中的动态规划方法
1. 动态规划问题特点：为了得到结果状态，需要循环求解每个子状态，
而递归问题的特点：为了得到结果状态，需要递归求解每个子状态，
2. 动态规划问题思路：
- 定义一个状态：通常就是求解结果的状态
- 对状态进行递推，得到递推公式
- 进行初始化，然后递推
3. 案例：爬楼梯，贴瓷砖

### 算法中的hash表空间换时间
1. 使用hash表目的是通过存储部分数据，内存占用增多，但时间复杂度下降。
2. 

### 算法中的二叉树




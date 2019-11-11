# C++编程cheat sheet

主要参考C++ Prime(第5版)，例如标记检索CP-76就代表c++ prime的第76页

### 关于clion
1. 打开clion: 创建快捷方式
2. 创建md文件：new/file, xxx.md直接指定后缀名即可，clion自带md预览插件
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
make install   //(optional)安装
```
2. 在一个大项目下面，可以有独立的小项目，每个独立小项目都对应一个独立cmakelists：
- 创建小项目文件夹，里边生成小项目cmakelists, cpp, .h文件
- 右键点击任何一个cmakelists，都可以看到2个选项之一：如果已经是当前cmakelists，会看到reload cmakelists选项。
而如果不是当前cmakelists，则会看到load cmakelists选项，点击以后就会切换到该cmakelists对应的子项目中，并且能独立运行。

3.默认cmakelists包含4部分(但最简就是2句，project + add_executable).
其中add_开头的就表示生成，add_execuable()就是生成可执行文件，add_library()就是生成静态或动态库。
其他就是支持生成的辅助文件，比如link_libraries(),include_directories()。
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
8. 如果


### 关于最容易犯的简单错误
1. 在include vector/string之后，一定要using namespace std; 因为这些库都是基于std命名空间，否则无法调用。
2. 通常每个独立语句后边都要分号，而大括号是包括多个语句的功能块则后边不要分号。
   但类的声明属于语句(省略了对象的声明)所以大括号后边要分号，而函数的申明属于大括号内多个独立语句所以大括号后边不要分号。


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
1. 标准名称空间的应用方式如果不声明，就可以直接用
`std::cout; std::vector<int>;`
2. 整个名称空间所有对象都导入的方式using namespace std, 这样std下面所有名称都可以直接用，省去输入std，但可能有重名风险
3. 部分名称空间导入的方式using std::cout，从而cout可以直接用。
```
using namespace std;   // 声明命名空间名称，要带关键字namespace
using std::vector;     // 声明命名空间下面的子对象，不要带关键字namespace
```
4. 注意：c++中的标准库都是在std名称空间之下，比如：vector, string...
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

using namespace AAA;
```


### 关于命名方式
1. 如果是类，则首字母大写，每个单词首字母也大写：GraduateStudent，对应头文件.h和对应源码文件.cpp的名称跟类名一致
2. 如果变量名、函数名，则首字母小写，剩下单词首字母大写
3. 如果是类的内部变量的命名以m_类型+名称来命名，且由于变量名算第二个单词，则等同函数名命名方式即该变量名首字母大写：
                       
例如：
```
class OnnxResNet(){       // 类名称：首字母大写，每个单词首字母大写
public:
    void processInput();  // 函数名：首字母小写，每个单词首字母大写
    stuName;              // 
private:
    int m_iAge;           // s
    string m_sName;
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
6. 变量类型
- 全局变量：定义在main()函数之外，具有文件作用域，也就是在整个文件可见，并且其他文件在声明extern 变量后也可见。
- 局部变量：定义在函数体内，或者定义在某个语句块内，则具有函数作用域或语句块作用域
- 静态全局变量：在全局变量前面添加static，从而把作用域收缩到本文件，其他文件即使声明extern也不可见。
- 静态局部变量：在局部变量前面添加static，从而把作用域收缩到局部，其他函数或者位置块都不可见。
- 静态成员：静态成员是类的成员而不是对象成员，也不会被实例化，但可以被对象访问。
  无论是静态变量、静态函数、静态成员，都是单独放在静态存储区，因为已经地址固定，所以必然会被初始化为0。
  相比之下，其他变量由于是放在动态存储区(栈区)，所以初始化值是随机的，最好自己手动初始化。
- 其中extern表示该部分已经声明过，这里要直接使用；其中static表示该部分会放在静态存储区而不是在栈区。
```
int a = 3;     // 全局变量：本文件可访问，其他文件声明后可访问，extern int a;
void func(){   // 全局函数：本文件可访问，其他文件声明后可访问，extern void func;
}

static int b = 5;   // 静态全局变量：在本文件可访问，其他文件不可访问

int main(){
}
```
- (核心原因)数据在内存中存放地址有4种
    - 正文段：存放机器指令，为只读，不可修改
    - 数据段：存放静态变量(static)
    - 栈区：存放自动局部变量(普通变量)
    - 堆区：存放动态内存分配(new/delete)

静态变量在编译完成后地址就固定了，初始化值要么是程序指定的，要么统一会初始化为0。
而在栈和堆中的变量由于地址都是不确定的，也就不会去初始化，所以值是随机的。
```
static int sum;  // 这个值会初始化为0
int sum;         // 这个值随机。
```

7. 一些特殊数据类型(CP-103)
- size_t类型
- size_type类型

### 关于变量的初始化(CP-39-76-88)
1. 变量初始化定义: 虽然初始化方法之一是用=号，但初始化并不是赋值，因为赋值是擦除之前值用新值代替，而初始化是创建时给出的初始值。
2. 初始化语法:
    - 值初始化：用小括号，是调用对象的构造函数，可以有不同的输入形式，主要是定义元素个数和元素值
    - 列表初始化: 用大括号，是提供一组初始化值。(可以写成带等号的拷贝初始化，或不带等号的直接初始化)
```
int a;     //此时没有初始化，采用的是默认初始化，但不同情况的默认初始化可能不同，所以不建议。而是对任何内置变量手动初始化

int a = 0;                // 用等号的初始化，叫拷贝初始化，是把数据拷贝给变量。
vector<int> a1 = {1,2,3}; // 拷贝初始化

int a(8);           // 不用等号而用括号，叫直接初始化(也叫值初始化)，是调用对象的构造函数，所以括号内可能有不同形式，对应不同的重载构造函数。
string s("hello");  // 直接初始化，其中一种构造函数
string s(8, 'c');   // 直接初始化，另一种构造函数
vector<string> sv2(sv1) //
vector<int> b1(3);     // 直接初始化：得到的是3个0
vector<int> b3(3, 10);

vector<int> c0{3};     // 列表初始化，此时得到的是一个3，而不是3个0
vector<string> c1{"hello"};     // 列表初始化
vector<string> c2(3, "hello");  // 直接初始化
vector<string> c3{"hello", "world", "hey"};  // 列表初始化
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
4. 强制类型转换(显式类型转换: 都是c语言的类型转换)
c语言的类型转换缺点是转换不够明确，不能进行错误检查。
```
int a=0; int b=1;
double c = a + b;   // 新定义一个类型达到强制转换效果
(double)a+b;        // c语言风格的强制类型转换
double(a+b)         // c++早期函数式强制类型转换
```
5. c++的类型转换
```

```



### 对比c与c++的输入输出语句
1. 如果是用c的类型，则包含stdio.h, 且需要自己指定数据类型
```
#include <stdio.h>
printf("a=%d", a)
```
2. 如果是用c++的类型，则包含iostream，且不需要考虑类型
```
#include <iostream>
cout << "hello" << endl;
// 输出
char *ch = "hello"
cout << ch << endl;    // 注意: 输出符号<<如果遇到地址，会输出字符串而不是输出地址，这是因为对<<进行了重载
// 输入
cin >> ch;    // 以什么为完成输入的标记
cin.getline()  // 以换行作为完成输入的标记
```

### 关于输入输出的类型
0. 输入输出可以通过3条路径：流，文件，???，对应c++中3个库

`<iostream>`库：这是最核心的库，可定义3个类型，istream, ostream, iostream
`<fstream>`库：这个库里的类型继承自前面的库，生成3种继承类型，ifstream, ofstream, fstream
`<sstream>`库：这个库里的类型继承自前面的库，生成3种继承类型，istringstream, ostringstream, stringstream

1. 类型1(流的读写)，采用的对象是cin(istream类型)， cout(ostream类型)

2. 类型2(文件的读写)，文件读写依靠创建3种类型的对象完成： ifstream, ofstream, fstream
```
// 打开一个文件，可以用obj.open()，也可用fstream的构造函数
ofstream out("xxx.txt", ios::out);
out.open("xxx.txt", ios::out);      // 用open()函数打开跟用构造函数打开是等效的。
```
- 其中读写模式包括：
    - ios::in
    - ios::out
    - ios::app (代表append从文件末尾开始读写)
    - ios::binary (二进制)
    - ios::trunc (打开并清除)
    - ios::ate (代表at the end位于文件末尾)
- 其中流对象的基本操作包括：
```
obj<<           // 通用输出运算符
obj>>           // 通用输出运算符
out.open(str);  // 打开一个文件
out.close();   // 关闭当前文件
out.is_open()  // 判断是否打开
out.eof()      // 判断是否到达文件末尾end of file
```
- 写入文件
```
ofstream out("test.txt");  // 创建对象和打开文件可以写成一句 ofstream out("test.txt", ios::out); 好处是这个out可以带着文件信息作为参数传递。
if(out.is_open()){         // 判断是否打开
    out<<"write success.\n";  // 写入
    out.close();           // 关闭文件
}
```
- 读取文件
```
ifstream in("test.txt", ios::in);
string str;
if(in.is_open()){
    in>>str;
    in.close();
}
```

3. 类型3(字符串读写)


### 关于结构体
1. 结构体跟类的声明基本一样，唯2的两个差别：关键字不同(struct, class), 默认访问权限不同(结构体public, 类private)
2. 在很多情况下，用结构体构建一个简单模块，比用class方便，因为不区分public
3. 结构体声明：
```
struct Account
{
    int a;
    Account(int m, int n){}
};
```

### 关于迭代器(CP-95)
1. 迭代器的操作是后边vector, map这些顺序容器，关联容器操作的基础，所以必须准确掌握迭代器的通用操作。
迭代器跟指针相似但并不完全是指针，但操作跟指针基本一致。
2. 获取迭代器，最常用的类型是用auto，因为迭代器类型一般比较长，比如vector<int>::iterator类型，
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
0. 核心：数组中可以放任何对象，比如int,char,string，也就对应数值数组，字符数组，字符串数组
- 数组名一般等于指针名，所以可以用指针方式操作数组名，也可用数组方式操作指针名
```
char a[] = {'a','b','c'};  // 创建字符数组
char *p = {'a','b','c'};   // 创建字符数组
a+2;   // 用指针方式来操作数组
p[2];  // 用数组方式来操作指针 
```
- 数组名并不等于指针名：指针名可以变换成字符串常量，数组名可以变成带长度的数组名
```
char c[] = "hello";    // 初始化一个数组，此时数组长度6, 取出c[0]合法，c[0]='H'也合法
char *p = "hello";     // 指针指向一个字符串常量，所以常量不可修改，此时取出p[1]合法但赋值p[1]='c'不合法。

cout << p;   // 此时输出指针p并不是输出地址，而是输出整个字符串，因为cout专门针对字符串指针重载了<<，输出字符串
cout << *p;  // 此时是按指针特性，输出第一个字符。
```
- 数组名代表指向数组下标为0元素的指针，但长度却是跟元素个数相关的。而指针名长度只是类型长度。
说明是可以把数组名看成一个变量名。
```
int arr1[4];
int *arr2;
sizeof(arr1);    // 数组名虽然是指针，但在sizeof里边得到的却是整个数组长度，这样设计的好处是计算长度可以统一用sizeof(arr1)/sizeof(int)
sizeof(arr2);    // 而指针名却只是类型长度。
```

1. 使用静态数组，也就是c++默认的数组，数组中可以放任何对象，比如char,string...
缺点是：必须在初始化固定长度，且不能增加长度
- 数组基本用法
```
// 数值数组初始化
int a[10] = {1,2,3};      // 数组尺寸固定不能修改，可以只初始化其中部分，其他自动用0初始化
int a[] = {1,2,3};        // 数组尺寸不指定，但会根据初始化情况固定，比如这里尺寸会固定成3.
// 字符串数组初始化
char a[] = {'a','b','c'}; // 字符数组初始化，不会引入\0
string a[] = {"hello", "world"};  // 字符串数组
char a[] = "abc";         // 一种特殊字符数组初始化，此时字符串会引入\0
// 指针数组初始化：[]的优先级高于*，所以首先是个数组，然后是字符
int *p[10];   // 存放的是10个指针。注意：这里下标运算优先，所以先是10个元素的的数组，然后再因为星号定义每个元素都是指针。
int (*p)[10]; // 存放的是10个int，但数组名是指针
int (&p)[10]; // 存放的是10个int, 但数组名是引用

// 数组使用迭代器
int *be = begin(arr)    // 由于数组不是容器，没有.begin()和.end()来获得迭代器，但可以通过begin()/end()函数获得指针
int *en = end(arr)
// 数组循环
for(d:arr){};           // 可以提取元素

sizeof(a)/sizeof(*a)   // 获取数组元素个数
```
- 数组不能被拷贝和赋值：所以也不能在函数中返回数组，因为返回的操作就是一个拷贝操作，因此如果要返回数组，则需要返回数组的引用或者数组的指针。
```
// 如果要拷贝数组：可以用std:copy()函数实现
std::copy(std::begin(a), std::end(a), );  // 也就是把数组a的开头到结尾的元素拷贝到数组b
// 如果要拷贝数组：可以改成vector，它支持拷贝

// 如果要拷贝数组：可以用指针或者引用，但为了返回一个数组指针或者引用的最简单方式是：
int *func(int *a, int *b);     // 这是返回一个指针
int (*func())[10];             // 这是返回10个int元素的数组
int *func()[10];               // 如果不加括号，就会变成返回10个指针的数组

using aten = int[10];            // 等价于typedef int aten[10], 用typedef不太好理解，用using比较直观 (CP-205) 
aten *func(int *a, int *b)       // 为了免去写数组的维度，可以先用using定义一个带维度的别名，从而函数能够返回一个数组。

```

2. 使用动态数组，也即是STL库里边的vector，他是顺序容器的代表(CP-292)
优点是: 可以直接用a.size()获得长度，可存放任何别的数据类型，初始化后，可以用push_back()增加长度
注意：如果要增加长度，就不能用在for循环，因为会导致for循环不知道循环次数
注意：vector虽然可以下标访问，但决不能访问未初始化的值。
```
#include <vector>
// 初始化
vector<int> a;      //空数组
vector<int> a(10);
vector<int> a(10, 3);  
vector<int> a={1,2,3};  //甚至可以写成vector<int> a{1,2,3}; 但不过是c++11的特性
vector<string> b = {"ab", "cd", "hello"}
// 基本操作
a.push_back(3)                           //末尾插入元素
vector v2(v1.begin()+1, v1.begin()+3);   //切片
v2.assign(v1.begin(), v1.begin()+2)      //切片2：用v2的元素替换v1，但注意：不能用自己的替换自己的，因为自己的指针不能被覆盖
// 相关函数操作
swap(v1, v2)  //交换两个vector
v1.at(ind);  // 某位置元素
v1.front();  // 首位置元素
v1.back();   // 尾位置元素
v1[ind];     // 某位置元素

```


### 关于字符串
0. 在c++中单字符用单引号'c'，字符串用双引号"ccc"

1. 使用c风格字符串: 可以看成是字符串数组，作为数组来理解
```
char str1[] = {'a','b','c'};  // 数组初始化方式１，长度是3
char str2[] = "abc";          // 数组初始化方式２，长度4，尾部带\0

char *str[] = {“hello”, "world"}  // 定义的是一个指针数组，每个元素都是一个字符指针，指向的是一个字符char
                                  // 因此即使是字符串也只是指向字符串第一个字符，但可通过指针运算访问字符串每个字符。 
                                  // 相当于一个指针数组，每个指针元素指向一个数组的首元素
char *str = 
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
### 语句中类型别名定义：typedef/using
1. 定义类型别名目的是让某些非常长的类型更简洁，容易理解，有2种方法可以定义：
```
typedef vector<string> vs;   // 早期最常见的用法
vs  a1(2, "hello");

using vs = vector<string>;   // using在c++新标准中也可以用来定义类型别名，并且更加容易理解，也更多被人使用
vs a1{"hello","hello"}
```


### 语句中的using
1. using可以用来定义命名空间
```
using namespace std;
using namespace algorithm;
```
2. using可以用来给模板定义一个别名：
这种方式类似于typedef的作用，但比typedef的写法更容易看懂，并且
```
template <typename T>;
using new_vec = MyVector<T, >;    // 定义一个模板的别名，创建模板变量时就能简洁很多。    
new_vec<int> vec;                 // 创建了一个模板变量
```
3. using还可以用来在子类中继承父类的方法
```
class Child : public Base{
public:
    using Base::func;    // 利用using继承父类的同名函数，这样就避免父类同名函数被子类同名函数所覆盖
    void func(){}        // 子类新的同名函数
}
```


### 基本函数
```
#include<cmath>  // 这是c++的头文件，也可以用c的<math.h>
ceil(x);
floor(x);
sqrt(x);
sin(x);
log(x);
pow(x,y);  // x^y
abs(x);    // 整数的绝对值
fabs(x);   // 浮点数绝对值

#include<cstdlib>
srand(seed);  // 先生成随机种子，如果种子相同，就能获得相同的随机数。注意如果没有定义srand()，系统会自动固定一个seed.
rand();       // 生成随机数
int range[] = {0, max};
num = rand()%(max+1);       // 获得[0,max]之间的随机数，相当于取余数
int range[] = {min,max};
num = rand()%(max-min) + a; // 获得[min,max]之间的随机数，本质是先获得0-delta之间随机数，然后平移。
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
int *p = new int()  // 创建指针最快的方式是new，因为new能够直接返回地址，而不需要先新建对象然后取地址。
delete p; p = nullptr; // 但用new创建的动态内存需要手动删除，防止内存泄露。

c = p->empty() // 箭头符号是指针操作，等效于*p.empty()，即用箭头符号等效代替星号+点号
```
0. 既然指针和引用都可以在不拷贝时调用原对象，两者有什么区别
- 指针是对象，而引用只是别名
- sizeof(指针)是类型大小，而sizeof(引用)则是对象大小
- 指针绑定对象后是可以换的，但引用绑定对象后不能改变。
- 指针在操作对象前需要用*解引用，而引用操作对象更方便，直接操作。

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

2. 数组名并不完全等于指针名：指针名可以变换成字符串常量，数组名可以变成带长度的数组名
```
char c[] = "hello";    // 初始化一个数组，此时数组长度6, 取出c[0]合法，c[0]='H'也合法
char *p = "hello";     // 指针指向一个字符串常量，所以常量不可修改，此时取出p[1]合法但赋值p[1]='c'不合法。

cout << p;   // 此时输出指针p并不是输出地址，而是输出整个字符串，因为cout专门针对字符串指针重载了<<，输出字符串
cout << *p;  // 此时是按指针特性，输出第一个字符。
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
- 关键1：采用const int a, const int* p, const int& q这三种能够起到输入放大输入，且避免修改输入的效果。
- 关键2：最优的方式是const int& q，因为可避免拷贝，可传入任何数据，不可修改输入，不影响接口。
而采用const指针则需要修改输入接口，而采用const int a则需要额外拷贝增加内存，所以建议用const int& q为主。

```
// 传入指针或引用
void func(int *p);            // 传入指针： 此时不可传入常量的地址func(&ci), 不可传入字面值常量func(32); 
void func(int &q);            // 传入引用: 此时不可传入常量引用func(&ci), 不可传入字面值常量func(32);

// 推荐的形参定义方式：采用引用
void func(const int& d1, const int& d2);
// 传入数组
void func(const int* arr);     // 传入数组的方式有如下三种等效，都是传入数组指针
void func(const int arr[]);
void func(const int arr[10]);
// 如果传入数组指针，为了避免指针越界有3种管理数组长度的方式：
void func(const char str[]);                 // 利用字符串数组尾端的\0来管理数组长度
void func(const int* begin, const int* end); // 利用头尾指针(建议的方法)
void func(const int arr[], size_t size);     // 利用额外传入一个数组长度变量(以前的c/c++使用)
```

3. 关于main函数的形参
```
int main(int argc, char *argv[]) // 其中argc代表参数个数，argv代表字符串参数

int main(int argc, char **argv) // 另一种写法
```
4. 如果希望同一个函数能够适用在不同输入变量组，有如下方式：
- 如果形参个数不同，可以用函数重载：函数名相同，但形参不同，即构成函数重载
```
void func(const int*cp);
void func(const int*cp, const int size); // 两个函数名相同，但可以传入不同参数个数
```
- 如果形参类型不同，可以用函数模板：
```
template <typename T>     // 这里定义一个模板参数T
void swap(T &t1, T &t2){  // 然后实现基于模板参数的函数模板： 交换两个数
    T tmp;
    tmp = t1;
    t1 = t2;
    t2 = tmp;
}
swap<float>(num1, num2);   // 调用函数模板
```

5. 内联函数：可减小cpu开销而不用call，缺点是导致代码大小增加，适合一些简单函数
```
inline float getPi(){
    return 3.14
}
```
6. const函数：也就是函数本身不能修改任何类的数据成员，并且也只能调用同类的const函数。
```
class Stack{
    int getData() const; // 类的成员函数，且不能修改类中任何数据成员  
}
```

### 关于函数的返回值(CP-199)
0. 函数返回值可以是函数体内的局部对象，此时相当于局部对象的拷贝值被返回，但不能返回局部对象的指针或者引用，因为局部对象在函数退出之后就自动销毁。
因此返回的是指针或引用一般都是形参传入的指针或者引用，此时要保证形参类型跟返回类型一致。
1. 函数返回值如果是指针或者引用，则需要在声明时注明：
且由于返回的指针或者引用不能是局部变量的，所以此时返回的指针或引用应该都是函数形参上的。
```
const string &get_string(const string &s1, const string &s2);  // 返回的指针不是局部对象的指针，而是原来形参传入的指针。 
```
2. 如果要返回数组，此时不能直接返回，因为数组无法被拷贝(数组本质上是指针，不能被拷贝)
```
// 返回数组指针的声明方式
int *func(int *a, int *b);     // 这是返回一个指针
int (*func())[10];             // 这是返回10个int元素的数组
int *func()[10];               // 如果不加括号，就会变成返回10个指针的数组

using aten = int[10];            // 等价于typedef int aten[10], 用typedef不太好理解，用using比较直观 (CP-205) 
aten *func(int *a, int *b)       // 简便的返回数组指针方法：为了免去写数组的维度，可以先用using定义一个带维度的别名，从而函数能够返回一个数组。
```


### 关于用new/delete管理动态内存(CP-407-423)
1. 数据在内存中存放地址有4种
   - 正文段：存放机器指令，为只读，不可修改
   - 数据段：存放静态变量(static)
   - 栈区：存放自动局部变量(普通变量)
   - 堆区：存放动态内存分配(new/delete)

2. 管理动态内存有2种方式： 
    - new/delete方式: 这种方法的缺点是容易忘记写delete p，或者因为前面语句报异常而没有执行delete p语句，
    导致该内存一致占用，也就是内存泄露。所以最好采用方式2智能指针来代替方式1.可以避免这种问题。
    - 智能指针方式

3. new/delete方式的用法：
用new初始化也是3种方式：不带括号是默认初始化，带小括号是直接初始化，带大括号是列表初始化
```
// new方式初始化变量：跟变量初始化一样，只是对象不是变量名，而是类名。
vector<int> va{1,2,3};                     // 这是常规创建变量，针对的是变量名
vector<int> *vp = new vector<int>{1,2,3};  // 这是new创建变量指针，针对的是类名，new生成的是地址

// 初始化方式也有3种主要方式(默认初始化不带括号，值初始化带小括号，列表初始化带大括号)
string *sp = new string;                     // 默认初始化
string *sp = new string(3, "hello");         // 直接初始化
vector<int> *vp = new vector<int>{1,2,3};    // 列表初始化
```

### 关于用智能指针管理动态内存(CP-400)

```
int *p = new int;        // 创建一个内存空间，未初始化
int *p = new int(42);   // 创建并用了值初始化
vector<int> *pv = new vector<int>{0,1,2,3}; // 创建并列表初始化 
const int *cp = new const int(42);          // 创建const

int *p = new (nothrow) int;  //默认状态new申请内存失败会报异常错误，而用这种方式则不会报错，会返回一个空指针。

delete p;   // 删除指针，则释放内存
```
- 方式2：采用智能指针来创建和释放动态内存：
这种方式的好处就是智能指针其实是一种对象，通过运算符重载具有指针属性(包装成一个指针，具有*和->操作符)。
他预先定义了在析构函数自动释放内存，所以只要智能指针创建，最后就会自动释放内存。
其中unique_ptr只会让一个指针指向一个对象，指针失效就马上释放内存；
而shared_ptr会有多个指针指向同一对象，所以该指针内部会有个计数器，只有当所有指针都失效才会释放内存，从而确保不会在有指针还在用的时候就释放内存。
```
#include<memory>     // 智能指针所在头文件
// 智能指针的类模板定义：T是指针指向的对象，D是销毁对象调用的方法，可传入自定义的删除器，也可用他的默认实现
template <class T, class D = default_delete<T>> class unique_ptr; 
```

2. 智能指针的使用: 
```
// 所有智能指针公用方法
shared_ptr<string> p1; // 创建指针对象
*p1;                   // 指针操作符
p1->mem;               // 箭头操作符，等效于*p1.mem

p1.get();              // 获得智能指针内部真实的裸指针
if(p1.get()){};        // 注意： 智能指针本质是对象而不是指针，所以不能直接if(p1)来判断是否为空，因为必然为true,而必须用.get()先获得裸指针再判断是否为空。        

swap(p,q);             // 交换两个指针

// 专门针对shared_pt
shared_ptr<T> p1 = make_shared<T>(args)  // 指针指向一个对象，同时用args初始化这个对象
p1.unique();                             // 是否只有一个指针指向该对象
p1.use_count();                          // 返回指向该对象的shared_ptr个数

// 专门针对unique_ptr

```

3. 智能指针是否会内存泄露？
- 如果两个对象内部各自定义了shared_ptr指向对方，会产生循环引用，造成计数失效导致内存泄露
- 解决方案是采用weak_ptr弱指针，他的构造函数不会修改引用计数的值，不会对对象进行内存管理，但可以检测到所指向对象是否已经释放。


### 关于类的封装(面向对象3大特性-封装：高内聚，低耦合。也就是内部整合可随意更改而不影响外部)
0. 类的创建：类的创建本质上是声明一个类，属于一个语句，所以最后要有分号，并且可以在创建的最后增加对象名。
注意：通常每个独立语句后边都要分号，而大括号是包括多个语句的功能块则后边不要分号。
但类的声明属于语句(省略了对象的声明)所以大括号后边要分号，而函数的申明属于大括号内多个独立语句所以大括号后边不要分号。
```
using namespace std;  // 带分号
class AAA{
public:
    int a = 1;
    void func();
} aaa;               // 一般大括号后边不用分号了，但类定义这里其实省略了对象名，所以本质上是一句语句，要带分号。

void AAA::func(){}   // 函数声明，大括号后边也就不需要分号了。 

```

1. 类与结构体的区别：只有2个区别，一个是关键字不同(struct, class)，一个是默认访问权限不同(struct默认public, 而class默认private)。
所以常用的方式是：只要定义的成员都是public则用struct，而如果有private则用class。
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
2. 构造函数：用来初始化类成员，从而也让从构造函数传入的形参赋值给类成员，从而能让类的所有函数使用。
- 构造函数类型：一种是默认构造函数(如果没有自定义则系统会生成一个默认的)，一种是自定义构造函数。
注意：自定义构造函数后，系统就不会再生成默认构造函数，此时可通过default命令保留默认构造函数：
```
Queue() = default;
Queue(const int a, const int b);
```
- 构造函数有初始化方法，一种是在构造函数内对类成员赋值，另一种是使用初始化列表对类成员赋值(CP-258)
注意：如果是第二种方法使用初始化列表，则必须在构造函数声明的同时进行实现，即要加大括号进行实施，不能只有声明。
```
Queue(int a, int b){mA = a; mB = b};   //这个是在构造函数内部赋值初始化
Queue(int a, int b) : mA(a), mB(b) {}; //这个是初始化列表对类成员函数赋值，必须声明的同时加大括号实施。
```
3. 访问权限控制：(CP-240)
- public：类内，类外都可访问
- private：类内开放，类外关闭。(友元函数开放)
- protect：等同于private，类内开放，类外关闭。(派生类内开放，类外关闭，友元函数开放)

4. 友元的定义：用来给其他类和对象访问private数据提供通道，可以定义友元函数和友元类
- 某个类的友元函数，需要在类的成员函数声明处声明一个友元函数，而对该外部函数则完全没有影响(相当于改了锁，用户名就不用改了)
- 友元函数：能够访问原类的私有成员。
```
friend int add(const int a, const int b); 
```
- 友元类：
```

```

5. 内联函数成员的定义：用于节省运行时间(但增加代码量，空间换时间)，适合很小的函数。
- 可以放在声明处声明一个内联函数，也可以放在类的外部实施处。
```
inline int add(int a, int b){return a+b;}
```
6. 类的this指针: 代表该对象的地址指针，操作方式与指针一致。
```
this->mem();    // 调用对象成员函数
return *this;   // 代表返回该对象本身  
```
6. 类的静态成员：用于声明成员只跟类相关，而跟对象无关。
- 类的静态成员包括静态成员变量，和静态成员函数
- 静态成员也可以分布在public, private, protect之间
- 声明static静态成员，关键字只能用在类内（貌似static, friend, inline都是用在类内）
```
static double rate(){return }
```
7. 类的const函数： 代表不能修改类成员的函数。
```

```

### 关于拷贝构造函数(CP-440)

### 关于析构函数(CP-445)
1. 析构函数主要任务：用于释放在构造函数中申请的堆内存
```
class Base{
public:
    Base(){int *p = new int;}
    ~Base(){delete p; p = nullptr;}  // 析构函数：删除指针，并把指针置为空指针
};
```
2. 析构函数还能用于虚函数??
```

```


### 关于类的继承(面向对象3大特性-继承：代码复用)
1. 类的继承包括public, private, protected。而访问权限受到2个因素限制：成员本身的访问符，派生类的继承访问符。(CP-542)
- public继承：则权限不变
- private继承：则所有权限都变成private权限
- protected继承：public/protected权限都变成protected, 而private权限依然是private权限

2. 派生类的初始化：派生类本质上由2部分组成，一部分是从基类继承得到的成员，另一部分是自己新建的成员。所以初始化需要同时初始化基类和派生类
```
class Derive : public Base{
public:
    Derive(int a, int b, int c, int d) : Base(a, b), mC(c), mD(d) {}  // 这个派生类的4个形参，前两个给基类进行基类初始化，后两个给自己成员初始化。
}

```
3. 派生类对象访问基类
```

```
4. 派生类继承基类static静态成员: 此时静态成员也只存在唯一实例，可通过基类或者派生类对象去访问静态成员，没有区别。(CP-532)
```
baseP->state_func();
deriveP->state_func();
```
5. 友元关系不能被继承：基类的友元不能访问派生类，派生类的友元也不能访问基类

6. 如果某个类不希望被继承，则采用final关键字在类名后边。
```
class AAA final{
};
```
如果类的某个函数不希望被覆盖，也可宜采用final关键字在函数声明的后边。此时派生类的同名函数不可覆盖基类该函数，否则报错。
```
class AAA{
public:
    void get_char() final;  // 这个函数不可以被派生类同名函数覆盖，即派生类不可以有同名函数。
}
```



3. 多继承与菱形继承


## 关于类的的多态(面向对象3大特性-多态：？？？)

1. 基类把类成员分2类，一类是不希望派生类修改的，另一类是要求派生类取修改覆盖的，第二类就会声明为virtual(虚函数).
- 虚函数定义的目的：
- 虚函数执行过程(CP-530)：首先是应用函数的形参必须是基类的指针或引用，然后应用函数调用时形参可以传入一个基类，也可传入一个派生类。如果传入派生类则会根据形参类型进行派生类到基类的类型转换。
  然后该形参指针就会绑定到该派生类对象的基类部分上，也就可以把该派生类当成基类类型使用，然后该指针调用某虚函数时，虚函数才会进行动态绑定(也称运行时绑定)，此时
  由于该指针指向的是派生类对象，所以调用的就会使派生类对象的虚函数。
- 只有把派生类向基类转换，不能基类向派生类转换：因为派生类还是包含基类的，所以派生类可转换成基类，而基类不包含派生类所以不能转换成派生类。
- 基类的虚函数在派生类中可以重写也可以不写，如果不写就是沿用基类虚函数。
- 注意：虚函数必须是采用指针或引用来进行调用，才能实现动态绑定。
- 虚函数关键字virtual只能在类内声明体现，不能在类外函数定义出现
- 在基类被声明成虚函数，则在派生类中可以不声明，但默认也是虚函数，但为了保证能够覆盖基类虚函数，最好加关键字override
```
class Base{
public:
    virtual void get_char();  // 声明一个基类的虚函数，就是在函数声明前面加virtual。
};
```
- 派生类的虚函数只有跟基类虚函数在形参个数和类型上完全一致，才能覆盖基类的虚函数。从而实现基类指针的动态绑定。
但是：如果一不小心把派生类虚函数定义错了，比如形参个数不同或者形参类型不同，就会被认为是2个函数，无法覆盖基类虚函数，也就无法动态绑定。
一个好的避免错误的方法是采用override符号在虚函数定义的末尾，即手动指定他为虚函数，此时形参个数和形参类型都可以不一样，并且也能覆盖基类同名虚函数实现动态绑定。
注意：override只用于虚函数覆盖，其他函数的覆盖只要函数名相同就会覆盖。
```
class Drived{
public
    void get_char(string a, string b) override;  // 这个get_char()虽然形参个数跟基类不同，但也是虚函数。
}
```
- 有时需要避免多态，也就是希望自己能够手动指定调用哪个虚函数，此时可以用作用域运算符::
```
string result = baseP->Base::get_char();  // 这里是用基类指针调用虚函数，并用::指定是调用的基类的虚函数
```

2. 纯虚函数：也就是在虚函数声明时，另虚函数等于0，即得到纯虚函数。拥有纯虚函数的类叫做抽象基类，相当于python中的MetaABC，抽象基类不能实例化对象，只能用于继承。
```
class Base{
public:
    virtual void get_char() = 0;  // 纯虚函数
};
```
3. 多态的核心意义: 可以用同一个形参(基类指针)，接收不同的输入类型(基类和派生类)，并调用不同的类型(基类和派生类的虚函数)，达到规避类型严格匹配的问题，简化代码。
```
// 假定一个游戏编程： 此时由于形参类型的严格匹配，每种类型形参都需要一个函数对应，非常麻烦，扩展性也不好
class Dragon{
public:
    void attack(Wolf *p);  // 攻击狼: 由于每种对手对应攻击
    void attack(Tiger *p); // 攻击虎：需要重写新的attack()
    void hurted(Wolf *p);  // 受到狼攻击：
    void hurted(Tiger *p); // 收到虎攻击：不能与狼攻击共用一个hurted()函数，因为形参类型不同。
private:
    int power;
    int life;
};
// 如果用多态写法： 用基类指针来做基础匹配，调用的函数统一成虚函数，就规避了c++类型严格匹配问题。
class Dragon{
public:
    void attack(Base *p) override;  //
    void hurted(Base *p) override;
};
// 如果用python写法: 由于形参类型obj可以代表不同的对象，所以无需再用基类指针取调用虚函数。
class Dragon()
    def __init__(power, life):
        self.power = 100;
        self.life = 100;
    def attack(obj):
        obj.life - = self.power
    def hurted(obj);
        self.life -= obj.power
```

### 关于运算符重载



### 关于模板
模板有2大类，一类函数模板，一类是类模板
1. 函数模板: 就是通过定义函数模板参数T,来得到一个函数模板，相应的函数名就变为func<T>.
```
template <typename T>     // 先定义一个函数模板的参数T
void swap(T &t1, T &t2){  // 然后基于模板参数来定义函数模板： 交换两个数
    T tmp;
    tmp = t1;
    t1 = t2;
    t2 = tmp;
}
swap<float>(num1, num2);   // 调用函数模板
```

2. 类模板: 也是通过定义类模板参数T, 来得到类模板。相应的类名就变为cName<T>
```
template <class T>            // 先定义一个类模板的参数T
class AAA{
public:
    vector<T> elem;           // 然后基于模板参数来定义类
    void push(const T& elem)
    void pop();
}

template <class T>                 // 每一个实现的成员函数前面都要包含类模板参数的说明
void AAA<T>::push(const T& elem){} // 类的名称也需要变为cName<T>, 类似于vector<T>

template <class T>
void AAA<T>::pop(){}

AAA<T> aaa;                        // 调用类创建对象
```

3. 可以用模板方便地扩展一些基本库的功能：
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
2. 二分法搜索：先进行排序，然后二叉搜索(也叫二分搜索)，此时时间复杂度O(log2(n))
- 大部分已排序的题目都是用二分法
- 二分法的中间点求取最好用不溢出的方式
```
def search(vector<int> & nums, target){
    snums = sorted(nums)
    int left =0;int right=nums.size()-1;
    while(left <= right){
        mid = left + (right - left) / 2;  // 这种获取中间值的方式不会溢出，而(left+right)/2在left,right很大时可能溢出
        if(target == snums[mid])
            return mid;
        else if(target < snums[mid])
            right = mid - 1;
        else if(target > snums[mid]
            left = mid + 1;
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




# 模型onnx转trt

### 关于clion
- 打开clion: 创建快捷方式
- 创建md文件：new/file, xxx.md直接指定后缀名即可，clion自带md预览
- 创建cpp文件：new/file, xxx.cpp
- 创建cmakelist: 
- 输入中文：clion安装好后不能输入中文，需要修改clion.sh：在Run the IDE段落前面添加(不能添加到最后，否则也没效果)：
```
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx
```
- 调试：几个核心快捷键(可以考虑自定义快捷键把n, c, s, u, d设置出来???)


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
2. 默认cmakelists包含4部分(但最简就是2句，project + add_executable)
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
参考Teris源码。
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

### 关于头文件


### 关于名称空间
- 标准名称空间的应用方式为std::cout
- 整个名称空间导入的方式using std, 这样std下面所有名称都可以直接用，省去输入std，但可能有重名风险
- 部分名称空间导入的方式using std::cout，从而cout可以直接用
- 自定义名称空间：
```
namespace abc 
{
    int    
}
```





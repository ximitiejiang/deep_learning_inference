# deep_learning_inference
inference and deploy with c++


### 关于protobuf
0. 参考：https://www.ibm.com/developerworks/cn/linux/l-cn-gpb/index.html
1. protobuf是google出品的与平台，语言无关的，高效序列化数据结构协议。可以用protobuf设计一种数据结构的协议，然后
用语言去读取或者写入，通常用c++。
2. protobuf的存储虽然用xml,json都能完成，但protobuf特点是更简单、更小，更快。
实现方式就是用protobuf编译器将proto文件生成对应的数据访问类，然后对数据进行序列化(用来保存的格式)和反序列化(用于使用的格式)。
3. protobuf具有向后兼容性，可以把老数据改造成新数据，完成对数据结构的升级。
4. 缺点：功能简单，是以二进制保存，如果不知道定义，就无法独处protobuf的任何内容。
5. protobuf细节
- proto文件中采用的语法基本跟c++一样，通常至少包括2部分: 
第一部分是变量syntax用来定义采用什么语法，可以是proto2/proto3，默认proto2, 不写会warning.
第二部分是Message也就是具体的数据结构，相当于一个c++的结构体。
可选第三部分package相当于命名空间。
```
syntax = "proto2";
package lm;
message helloworld
{
    ...
}
```
- 编译proto文件：采用proto自己的编译器protoc，可生成filename.pb.cc和filename.pb.h两个文件。
这就是自己定义的一个数据结构，其中.h文件include进自己的c++代码中即可。 
```
protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/addressbook.proto
protoc --cpp_out=./ addressbook.proto    // 第二种写法：当前路径下有proto文件，并生成到当前路径
```
- 使用自定义的protobuf数据结构
```
// 针对每个message里边的字段的方法：
has_name();
set_name();
clear_name();

// 针对message本身的方法：
IsInitialized();
Clear();

// 针对读写的方法：
SerializeToString(string* output);
SerializeToOstream(const string& data);
ParseFromString(ostream* output);
ParseFromIstream(istream* input);
```
- 编译带proto数据的c++文件时：源文件需要包含.pb.h文件，编译的cmakelists需要include directories对应路径。
这里需要注意的是，如果是手动编译安装的protobuf，则路径是自己之前安装时设置的prefix，而如果是anaconda安装的则路径是在
anaconda3/include里边。可以通过locate google/protobuf去找一下。


### 关于onnx模型
1. onnx模型就是基于protobuf开发的。
参考：https://oldpan.me/archives/talk-about-onnx

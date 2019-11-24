//
// Created by ubuntu on 19-11-12.
//

#include <iostream>
#include "queue.h"
#include "node.h"
#include "link_list.h"
#include "tree.h"
#include "arg_parse.h"
#include "vector_op.h"
#include "test_class.h"
#include <fstream>

using namespace std;

void testQueue(){
    algorithms::Queue *p = new algorithms::Queue(5);

    // 检查插入是否成功
    p->insert(100);
    p->insert(200);
    p->insert(300);
    p->insert(400);
    p->insert(500);
    p->insert(600);  // 超出部分不会被打印出来
    p->traverse();
    // 检查弹出是否成功
    int out = 0;
    p->pop(out);
    cout << out << endl;
    p->traverse();
    // 删除动态内存
    delete p;
    p = nullptr;
}

void testLinkList(){
    algorithms::LinkList *p = new algorithms::LinkList();
    // 创建node
    Node n1("Leo", nullptr);
    Node n2("Winnie", nullptr);
    Node n3("Eason");
    Node n4("Jack");
    // 插入node
    p->insert(0, &n1);
    p->insert(1, &n2);
    p->insert(2, &n3);
    p->insert(1, &n4);
    // 遍历node
    p->traverse();
    cout << endl;
    // 逆序操作
    p->reverse();
    p->traverse();

    delete p;
    p = nullptr;
}

void testListTree(){
    algorithms::ListTree *p = new algorithms::ListTree();
//    TNode n1(3);
//    TNode n2(2);
//    TNode n3(1);
}

void testsizeof(){
    // 结论：元素的sizeof跟元素类型相关，int=4,float=4,char=1,数组等于每个元素字节之和，字符串等于字符+1
    int a1 = 3;
    float a2 = 3.14;
    char a3 = 'b';
    int a4[4] = {1,2,3,4};
    char a5[] = "b";

    // 指针：sizeof相等，都等于8，唯一的例外是数组名指针，被重载为数组元素字节数之和(p4为指针字节为8，a4为数组名字节为4*4)
    int *p1 = &a1;
    float *p2 = &a2;
    char *p3 = &a3;
    int *p4 = a4;
    cout << "a1:"<<sizeof(a1)<<",a2:"<<sizeof(a2)<<",a3:"<<sizeof(a3)<<",a4:"<<sizeof(a4)<<",a5:"<< sizeof(a5)<<endl;
    cout << "p1:"<<sizeof(p1)<<",p2:"<<sizeof(p2)<<",p3:"<<sizeof(p3)<<",p4:"<<sizeof(p4)<<endl;

    // 结论：指针的指针也是8字节，二维数组名则被重载为元素总的字节和。
    int a24[2][4] = {{1,2,3,4},{5,6,7,8}};
    int (*p24)[4] = a24;
    cout << "a24:"<<sizeof(a24)<<",p24:"<<sizeof(p24)<<endl;
}

// 测试元素指针和数组指针
void testptr(){
    int a = 32;
    int b[3] = {1,2,3};
    int c[2][3] = {{1,2,3},{4,5,6}};  // c是数组指针，也就是指向数组的指针
    cout << "b:" << b << endl;

    // 数组名：本身代表首元素地址，也就是元素指针。同时可以对数组名取地址
    int *b1 = b;
    char *b3;
    int (*b2)[3]=&b;

    cout << *b1 << " " << **b2 << endl;
    cout << sizeof(b) << " " << sizeof(b1) << sizeof(b3) << sizeof(b2) << endl;  // b是数组名(元素指针)所有元素所占字节数，b1是元素指针所占字节8

    int *p1 = &a;
    int *p2 = b;        // b是数组名，是元素指针
    int (*p3)[3] = c;   // p3是数组指针
    p3 = &b;
    int *p4[3] = {&a,b};    // p4是元素类型指针

    cout << *p1 << " " << *p2 << " "<< **p3 <<" "<< *p4<<endl;

}


// 测试字符串指针和字符串数组
void testchar(){
    char a1[] = "hello";
    char *a2 = "hello";

    cout << "a1:" << a1 << ", size:"<< sizeof(a1) << endl;  // a1是字符数组名，该数组名可直接输出字符串常量，可见字符数组唯一跟其他数组不同的是，数组名/字符串指针名都可以代表字符串常量
    cout << "*a1:" << *a1 << ", size:"<< sizeof(a1) << endl; // a1也是元素指针，所以*a1返回第一个元素
    cout << "a2:" << a2 << ", size:"<< sizeof(a2) << endl;    // a2是元素指针，所以*a2返回也是第一个元素
    cout << "*a2:" << *a2 << ", size:"<< sizeof(a2) << endl;
}

int main(int argc, char *argv[]){
    testptr();
    testchar();

//    vector<int> nums{01,2,3,4,5,6}; int target = 4;
//    int result = searchInsertPosition(nums, target);
//    cout << result << endl;


//    bool argOK = argParser(args, argc, argv);
//    cout << args.model_dir << endl;
//    cout << args.dataset_dir << endl;

//    testLinkList();


    cout << "finished!" << endl;
    return 0;
}
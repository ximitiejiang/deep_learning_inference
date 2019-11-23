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

// 测试元素指针和数组指针
void testptr(){
    int a = 32;
    int b[3] = {1,2,3};
    int c[2][3] = {{1,2,3},{4,5,6}};  // c是数组指针，也就是指向数组的指针

    // 数组名：本身代表首元素地址，也就是元素指针。同时可以对数组名取地址
    int *b1 = b;
    int (*b2)[3]=&b;

    cout << *b1 << " " << **b2 << endl;

    int *p1 = &a;
    int *p2 = b;        // b是数组名，是元素指针
    int (*p3)[3] = c;   // p3是数组指针
    p3 = &b;
    int *p4[3] = {&a,b};    // p4是元素类型指针

    cout << *p1 << " " << *p2 << " "<< **p3 <<" "<< *p4<<endl;

}


int main(int argc, char *argv[]){
    testptr();

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
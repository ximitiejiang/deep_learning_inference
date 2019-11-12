//
// Created by ubuntu on 11/9/19.
//

#ifndef A03_CLASS_LINKED_LIST_H
#define A03_CLASS_LINKED_LIST_H

#include "node.h"

namespace algorithms {

// 链表结构特点：
// 1. 数据独立放在node, 每个node只能链接到下一个node(相当于战争时期地下党，单线联系)，无法排序无法索引。
// 2. 第一个节点无数据：数据为0，指向第二个节点；最后一个节点有数据，但指向为nullptr。
// 3. 操作插入或者弹出时，要指定一个index位置，代表第几个node。
// 4. 需要保存第一个节点的指针，通过他可以顺序搜索到每一个节点。
// 5. 总的节点数需要保存，每个节点是有顺序的，用户通过顺序号可以确定提取哪个节点。
// 6. 链表的最大优点：不受空间限制，可以无限制的扩充子节点，所以很适合用来做数据库这种事先不知道长度的场景。

class LinkList {
public:
    LinkList();
    ~LinkList();
    // 用于插入数据
    bool insert(int index, Node *node);
    // 用于弹出数据
    bool pop(int index, Node *node);
    // 用于遍历打印
    void traverse();
    // 用于判定是否为空
    bool isEmpty();
    // 用于判定是为满
    bool isFull();
    // 用于计算已存放元素个数
    int len();
    // 用于请空数据
    void clear();

    // 反转链表
    void reverse();

private:
    Node *mHead;
    int mLen=0;
};

LinkList::LinkList(){
    //创建头结点
    mHead = new Node("none", nullptr);
}

LinkList::~LinkList(){
    delete mHead;
    mHead = nullptr;
}

bool LinkList::insert(int index, Node *node){
    if(index < 0 || index > mLen)  // 确保位置
        return false;
    Node *tmpNode = mHead;     // 获取零节点
    for(int i=0; i < index; i++)   // 搜索到index位置
        tmpNode = tmpNode->next;
    Node *newNode = node;
    newNode->data = node->data;   // 更新新节点
    newNode->next = tmpNode->next;// 新节点链接到下一节点
    tmpNode->next = newNode;      // 上一节点链接到新节点
    mLen ++;
    return true;
}

bool LinkList::pop(int index, Node *node) {
    if(index < 0 || index > mLen)  // 确保位置
        return false;
    Node *tmpNode = mHead;
    for(int i=0; i<index; i++)
        tmpNode = tmpNode->next;
    node->data = tmpNode->data;
    return true;
}

void LinkList::traverse() {
    Node *tmpNode = mHead->next;
    for(int i=0; i < mLen; i++) {
        std::cout << tmpNode->data << " ";  // 从第二个node开始输出
        tmpNode = tmpNode->next;
    }
}

int LinkList::len() {
    return mLen;
}

bool LinkList::isEmpty(){
    if(mLen==0)
        return true;
    else
        return false;
}

bool LinkList::isFull() {
    return false;   // 链表可以无限增加，永远不会满。
}

void LinkList::clear(){
    mLen = 0;
    mHead->next = nullptr;
}

// 反转链表：如果只是简单取出每一个放在另一个新的list里边，那么空间O(n)，但如果要求空间复杂度O(1),那么就需要动态移动节点。
// 如下：就是按顺序把后边每一个元素轮流换到第二个node的位置，zeroNode位置保持不变
void LinkList::reverse(){
    Node *p = mHead->next;
    Node *q = mHead->next->next;
    Node *tmp;
    while(q){  // 只要q没有移到尾端为空，则一直循环
        tmp = q->next;     // 预存放q后边的链表
        q->next = p;       //q前移动
        mHead->next = q;   //
        p = q;             //
        q = tmp;           //
    }
}

}  // end of namespace
#endif //A03_CLASS_LINKED_LIST_H

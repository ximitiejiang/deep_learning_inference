//
// Created by ubuntu on 11/10/19.
//

#ifndef A03_CLASS_TREE_H
#define A03_CLASS_TREE_H

#include <vector>
#include <iostream>
// 这里的树主要指二叉树，也就是一个node下面固定有2个分支，其结构特点为：
//1. 根节点也叫树根root
//2. 每个节点下面包含2个分支，如果没有分支，则存放NULL
//3. 数据在树中存放的方式有两种：由于list与linklist的差异, 对应了ListTree和LinkListTree
//    - 采用list存放所有树的节点，这种树叫做线性二叉树ListTree
//    - 采用链表存放所有树的节点，这种树叫做链式二叉树LinkListTree
//4. 二叉树的定位: 通常需要先通过index定位根节点，然后再定义是该根节点的左还是右子节点，所以需要index和direction
//   注意：根据父节点的index来计算左右子节点的公式是[2*index+1, 2*index+2]

namespace  algorithms{

// -----------------------列表二叉树----------------------------------------------------------
class ListTree{
public:
    ListTree() = default;
    ListTree(int capacity);
    ~ListTree();
    // 用于插入数据
    bool insert(int index, int direction, int x);  // 插入元素到树，需要知道父节点index以及插入到左还是右子节点(左=0，右=1)
    // 用于弹出数据
    bool pop(int &x);
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
    // 用于搜索某个节点
    int *search();

private:
    int mCapacity = 0;
    int mLen = 0;
    std::vector<int> *root;

};

ListTree::ListTree(int capacity) {
    mCapacity = capacity;
    std::vector<int> *root = new std::vector<int>(mCapacity);
}

ListTree::~ListTree(){
    delete root;
    root = nullptr;
}

bool ListTree::insert(int index, int direction, int x) {
    if(index < 0)
        return false;
    if(direction == 0)
        root->at(index * 2 + 1) = x;
    else if(direction == 1)
        root->at(index * 2 + 2) = x;
    mLen++;
    return true;
}

void ListTree::traverse() {
    for(int i=0;i<mLen;i++)
        std::cout << root->at(i) << " ";
}

// -----------------------链式二叉树----------------------------------------------------------
class LinkTree : public ListTree{
public:
    LinkTree();
    ~LinkTree();
};



}   // end of namespace
#endif //A03_CLASS_TREE_H

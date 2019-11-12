//
// Created by ubuntu on 19-11-9.
//

#ifndef A03_CLASS_NODE_H
#define A03_CLASS_NODE_H

#include <map>

// 普通Node
class Node{
public:
    Node() = default;                   // 保留默认构造函数
    Node(std::string st) : data(st){}   // 输入单个形参的构造函数
    Node(std::string st, Node *nt) : data(st), next(nt){}  // 输入2个形参的构造函数

    std::string data;
    Node *next = nullptr;
    void printNode();
};

void Node::printNode(){
    std::cout << "Node data: " << data;
}

// 用于二叉树链表的node
class TNode{
public:
    TNode(int d) : data(d){};
    ~TNode();
    int data = 0;
    TNode *left = nullptr;
    TNode *right = nullptr;
};

#endif //A03_CLASS_NODE_H

//
// Created by ubuntu on 11/10/19.
//

#ifndef A03_CLASS_LIST_H
#define A03_CLASS_LIST_H

namespace algorithms {

// 列表结构特点
//1. 可通过index在任何位置存入或者取出
//2. 固定长度，能够切片

class List {
public:
    List(int capacity);

    ~List();
    // 用于插入数据
    bool insert(int x);
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

private:
    int mCapacity = 0;
};

}  // end of namespace
#endif //A03_CLASS_LIST_H

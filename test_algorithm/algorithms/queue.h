//
// Created by ubuntu on 19-11-6.
//
//类的定义过程
//1. 先声明成员和成员函数：因为编译是先编译声明部分，然后才编译实现部分，所以声明部分是最先定义

#ifndef A03_CLASS_QUEUE_H
#define A03_CLASS_QUEUE_H

namespace algorithms {

// 队列结构特点：
// 1. 队尾进，队头出，先进先出。
// 2. 可以循环存取，充分利用整个存放空间。
class Queue {
public:
    Queue(int capacity);
    virtual ~Queue();
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
    int *mBuffer;
    int mLen = 0;
    int mCapacity = 0;
    int mHead = 0;
    int mTail = 0;
};

Queue::Queue(int capacity) {
    mCapacity = capacity;
    mBuffer = new int[mCapacity];   // 创建静态数组，没有初始化而是默认初始化

}

Queue::~Queue() {
    delete[]mBuffer;
    mBuffer = nullptr;
}


int Queue::len() {
    return mLen;
}

bool Queue::isFull() {
    if (mLen == mCapacity)
        return true;
    else
        return false;
}

bool Queue::isEmpty() {
    if (mLen == 0 && mCapacity >= 0)
        return true;
    else
        return false;
}

bool Queue::insert(int x) {
    if (isFull())
        return false;
    else if (isEmpty()) {
        mBuffer[mTail] = x;
        mLen++;
        return true;
    } else {
        mBuffer[mTail + 1] = x;  // 队尾+1插入元素
        mTail++;                 // 队尾自增
        mLen++;
        mTail = mTail % mCapacity; // 如果++之后超出了capacity的值，说明尾部没有空间，但头部有，就把m_tail指向到头部
        return true;
    }
}

bool Queue::pop(int &x) {
    if (isEmpty())
        return false;
    else {
        x = mBuffer[mHead];
        mHead++;
        mLen--;
        mHead = mHead % mCapacity; // 如果++之后超出了capacity的值，说明尾部没有空间，但头部有，就把m_head指向到头部
        return true;
    }

}

void Queue::clear() {
    mHead = 0;
    mTail = 0;
    mLen = 0;

}

void Queue::traverse() {
    for (int i = 0; i < mLen; i++)
        std::cout << mBuffer[i] << " ";
        std::cout << std::endl;
}

}  // end of namespace

#endif //A03_CLASS_QUEUE_H

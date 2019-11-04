//
// Created by ubuntu on 19-10-31.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
using namespace std;

template <typename T, typename U>
U func(const T* cp, U cq){

    T result = cp[1];
    cq = cq + 1;
    return cq;
}

int main()
{
    int char[] = "hello";

    return 0;

}
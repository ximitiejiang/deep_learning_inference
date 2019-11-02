//
// Created by ubuntu on 19-10-31.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

namespace AAA{
    int aaa = 111;
    void showme(){
        std::cout << "I am showme!" << std::endl;
    }
}


namespace HAPPY{
    int alpha = 10;
    void printme();
}

void HAPPY::printme() {
    std::cout << "I am printme!" << std::endl;
}


using namespace std;

using namespace HAPPY;
using namespace AAA;

int main()
{
    int a = 1;
    int b = 2;
    int c = a + b;
    cout << double(a+b) << endl;
    cout << (double)a+b << endl;

    printme();
    showme();
    cout << "aaa = " << aaa << endl;
    cout << "alpha = " << alpha << endl;
}
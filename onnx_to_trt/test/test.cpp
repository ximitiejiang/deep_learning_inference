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
    char str1[] = "hello";
    char str2[] = {'h','e','l','l','o'};

    printme();
    showme();
    cout << "aaa = " << aaa << endl;
    cout << "alpha = " << alpha << endl;
}
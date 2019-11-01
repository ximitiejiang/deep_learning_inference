//
// Created by ubuntu on 19-10-31.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
int main()
{
    vector<int> data1 = {9, -1, 6, 0, 5, 3};
    vector<int> data2 = {100, 300};
    swap(data1, data2);

//    data1.assign(data1.begin(), data.begin()+1);

    for(auto& i : data1)
        cout << i << " ";
    cout << endl;

    map<string, int> person = {{"leo", 12}, {"jack", 25}};


}
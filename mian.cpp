#include <bits/stdc++.h>
#include "Vector.h"

using namespace std;


int main(){
    vector<string>v(10);
    v[0] = "hello world";

    v.clear();
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    for(auto &vv: v){
        cout << vv << endl;
    }
    cout << "======================" << endl;
    XYVector<string> vec(5);
    vec.push_back("Hello world");
    for (int i = 0; i < vec.get_size(); ++i) {
        cout << vec[i] << endl;
    }
    vec.clear();
    cout << "Size: ";
    cout << vec.get_size() << endl;
    cout << "Capacity: ";
    cout << vec.get_capacity() << endl;
    for (int i = 0; i < vec.get_size(); ++i) {
        cout << vec[i] << endl;
    }
}

/**
 * @file main.cpp
 * @author george _ abdalah
 * @brief  this is tha main file
 * @version 1
 * @date 2022-12-22
 * @details this code is training on templates
 * @copyright Copyright (c) 2022
**/

#include <bits/stdc++.h>
#include "Vector.h"

using namespace std;

/**
 * @brief this is the start of code
 * @return int 
 */
int main(){
    /*vector<string>v(10);
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
    }*/

    /*XYVector<int>v(5);
    int * itr = v.begin() + 1;
    XYVector<int>v2;
    cout << *itr << endl;
    v2.push_back(5);
    v2.push_back(6);
    itr = v2.begin();
    cout << *itr << endl;
        if(v < v2){
        cout << "TRUE";
    } else
        cout << "False";*/
    XYVector<int> vec(5);
    vec.push_back(6);
    vec.push_back(0);
    vec.push_back(6);
    vec.push_back(6);
    vec.push_back(7);// 6 7 8
    vec.push_back(8);// 6 0 6 6 7 8
    auto it1 = vec.begin();
    auto it2 = vec.begin()+ 3;
    vec.pop_back();
    cout << vec << endl;
    //vec.erase(vec.begin() + 4, vec.begin());
   /* cout << vec.get_capacity() << endl;
    cout << vec.get_size() << endl << endl;
    // cout << * itr << endl << itr << endl;
    for (int i = 0; i < vec.get_size(); ++i) {
        cout << vec[i] << endl;
    }*/


 /* vector<int> vec{1,2,3};
  auto itr = vec.begin();
  cout << &itr << endl;*/
  return 0;
}
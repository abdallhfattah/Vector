/**
 * @file main.cpp
 * @author george _ abdallah
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
 /*   XYVector<int> vec(5);
    vec.push_back(6);
    vec.push_back(0);
    vec.push_back(6);
    vec.push_back(6);
    vec.push_back(7);// 6 7 8
    vec.push_back(8);// 6 0 6 6 7 8*/
    XYVector<string> vec(5);
    vec.push_back("Hello");
    vec.push_back("world");
    vec.push_back("Hello");
    vec.push_back("Hel");
    vec.pop_back();
    cout << vec << endl;

    return 0;
}
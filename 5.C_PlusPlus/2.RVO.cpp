/*************************************************************************
	> File Name: 2.RVO.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 五  2/25 11:00:15 2022
 ************************************************************************/

#include <iostream>
using namespace std;

struct A {
    A() {
        cout << this << endl;
        cout << "default constructor" << endl;
    }
    A(const string a) {
        str = a;
        cout << this << endl;
        cout << "constructor with parameters" << endl;
    }
    A(const A &obj) {
        cout << this << endl;
        cout << "copy constructor" << endl;
    }
    ~A() {}
    string str;
};

A func() {
    A temp_a("hello world");
    cout << "&temp_a = " << &temp_a << endl;
    return temp_a;
}

int main() {
    A a = func();
    cout << "&a = " << &a << endl;
    return 0;
}

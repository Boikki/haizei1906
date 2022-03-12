/*************************************************************************
	> File Name: 7.c++11_override_final_virtual.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Sat Mar 12 14:15:10 2022
 ************************************************************************/

#include <iostream>
using namespace std;

struct A final {

    virtual void func1() {
        cout << "class A func1" << endl;
    }
    void funcl() {
        cout << "class A funclllll" << endl;
    }
};

struct B : A {
    void func1() override {
        cout << "class B funcl" << endl;
    }
    
};
int main() {
    B b;
    A *a;
    a->funcl();
    return 0;
}

/*************************************************************************
	> File Name: 8.c++11_dynamic_cast.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Tue Mar 15 09:38:03 2022
 ************************************************************************/

#include <iostream>
using namespace std;

struct A {
    virtual ~A() {}
};

struct B : A {
    B() { x = 123; }
    void say() {
        cout << "class B : " << x << endl;
    }
    int x;
};

struct C : A {
    C() { x = 123.45; }
    void say() {
        cout << "class C : " << x << endl;
    }
    double x;
};

struct D : A {
    D() { x = "hello world."; }
    void say() {
        cout << "class D : " << x << endl;
    }
    string x;
};

struct E : A {
    E() { x = new int; }
    void say() {
        cout << "class E : " << x << endl;
    }
    int *x;
};
int main() {
    srand(time(0));
    A *pa = nullptr;
    if (rand() % 2) {
        pa = new B();
    } else {
        pa = new C();
    }
    if (dynamic_cast<B *>(pa)) {
        ((B *)(pa))->say();
    } else if (dynamic_cast<C *>(pa)) {
        ((C*)(pa))->say();
    } else if (dynamic_cast<D *>(pa)) {
        ((D *)(pa))->say();
    } else if (dynamic_cast<E *>(pa)) {
        ((E *)(pa))->say();
    }
    return 0;
}


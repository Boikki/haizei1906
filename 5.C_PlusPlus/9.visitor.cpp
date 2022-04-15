/*************************************************************************
	> File Name: 9.visitor.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Fri Apr 15 09:20:38 2022
 ************************************************************************/

#include <iostream>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

class A {
public :
    virtual ~A() {}
};

class B : public A {};
class C : public A {};
class D : public A {};

int main() {
    A *arr[10];
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        switch (rand() % 3) {
            case 0 : arr[i] = new B(); break;
            case 1 : arr[i] = new C(); break;
            case 2 : arr[i] = new D(); break;
        } 
    }
    for (int i = 0; i < 10; i++) {
        if (dynamic_cast<B *>(arr[i])) {
            cout << "this is a class B obj" << endl;
        } else if (dynamic_cast<C *>(arr[i])) {
            cout << "this is a class C obj" << endl;
        } else if (dynamic_cast<C *>(arr[i])) {
            cout << "this is a class D obj" << endl;
        } else {
            cout << "this is a class A obj" << endl;
        }
    }

    return 0;
}

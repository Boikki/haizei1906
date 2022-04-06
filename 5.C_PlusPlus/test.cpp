/*************************************************************************
	> File Name: test.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Wed Apr  6 20:55:14 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Animal {
    void run() { cout << "Animal can't run" << endl; }
    int x;
    float y;
};

struct Cat : public Animal {
    void run() { cout << "Cat can run" << endl; }
};

int main() {
    Cat a;
    Animal b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
    cout << &a << endl;
    cout << &b << endl;
    cout << c << endl;
    cout << sizeof(Cat) << endl;
    cout << sizeof(Animal) << endl;

    return 0;
}

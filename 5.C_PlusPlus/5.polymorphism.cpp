/*************************************************************************
	> File Name: 5.polymorphism.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 四  3/ 3 10:45:06 2022
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public :
    Animal(const string &name) : __name(name) {}
    void run() {
        cout << "Animal can't run" << endl;
    };
protected :
    string __name;
};

class Cat : public Animal {
public :
    Cat() : Animal("Cat") {}
    void run() {
        cout << "I can run" << endl;
        return ;
    }
};

int main() {
    Cat a;
    Animal &b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
    return 0;
}

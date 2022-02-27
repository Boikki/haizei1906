/*************************************************************************
	> File Name: 3.inheritance.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 日  2/27 10:40:29 2022
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public :
    Animal(char *name) : _name(name) {
        cout << "Animal : " << this << endl;
    }
    const char *name() const { return this->_name; }
    void say() {
        cout << "I am Animal" << endl;
    }
    int x, y;

private :
    char *_name;
};

class Cat : public Animal{
public :
    Cat() : Animal("hello kitty") {
        cout << "Cat : " << this << endl;
    }
    void say() {
        cout << "I am Cat" << endl;
    }
    int z;

};

class Dog : public Animal {
public :
    Dog() : Animal("Anby") {
    }
    void say() { 
    cout << "I am a dog" << endl;
    }
};
class Monkey : public Animal {
public :
    Monkey() : Animal("Monkey 666") {}
};

ostream &operator<<(ostream &out, const Cat &a) {
    out << "<Class Cat> : ";
    out << a.name() << &a.x << " " << &a.y << " " << &a.z << endl;;
    return out;
}

ostream &operator<<(ostream &out, const Dog &a) {
    out << "<Class Dog> : ";
    out << a.name();
    return out;
}

ostream &operator<<(ostream &out, const Monkey &a) {
    out << "<Class Cat> : ";
    out << a.name();
    return out;
}
int main() {
    Cat a;
    Dog b;
    Monkey c;

    cout << a.name() << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << sizeof(a) << endl;
    Animal *p;
    if (rand() % 2) {
        p = &a;
    } else {
        p = &b;
    }
    a.say();
    p->say();
    return 0;
}

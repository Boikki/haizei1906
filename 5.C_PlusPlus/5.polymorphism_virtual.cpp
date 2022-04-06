/*************************************************************************
	> File Name: 5.polymorphism_virtual.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 四  3/ 3 13:47:55 2022
 ************************************************************************/

#include <iostream>
using namespace std;

struct Animal {
    /*
    virtual void run() {
        cout << "I can't run" << endl;
        return ;
    }
    */
    virtual void run() = 0;
    virtual void test(int x) {
        cout << this << endl;
        cout << x << endl;
        cout << "Animal test" << endl;
    }
};

struct Cat : Animal {
    void run() {
        cout << "Cat can run" << endl;
    }
    void test() {
        cout << "Cat test" << endl;
    }
};

struct Dog : Animal {
    void run() {
        cout << "Dog can run" << endl;
    }
    virtual void test() {
        cout << "Dog test" << endl;
    }
    
};

struct Bat : Animal {
    int age;
};

typedef void (*func_t)();
typedef void (*func_t1)(void *, int);

int main() {
    Cat b;
    Dog c;


    Animal *arr[10];
    for (int i = 0; i < 10; i++) {
        if (rand() % 2) arr[i] = new Cat;
        else arr[i] = new Dog;
    }
    arr[8]->run();
    cout << sizeof(Bat) << endl;

    cout << "______________" << endl;
    Cat a;
    ((func_t **)(&a))[0][0]();
    ((func_t1 **)(&a))[0][1](&a, 123);
    return 0;
}

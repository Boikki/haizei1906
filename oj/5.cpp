/*************************************************************************
	> File Name: 5.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 六  7/30 13:07:31 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class A {
public :
    A(int Egg) : Egg(Egg) {}
    int Egg = 11;
};

class B {
public : 
    B(int Apple) : Apple(Apple) {}
    int Apple = 10;
};

void swapObj(A &a, B &b) {
    b.Apple = a.Egg ^ b.Apple;
    a.Egg = a.Egg ^ b.Apple;
    b.Apple = a.Egg ^ b.Apple;
    return ;
}

int main() {
    A a(11);
    B b(10);
    swapObj(a, b);
    return 0;
}



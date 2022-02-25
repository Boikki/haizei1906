/*************************************************************************
	> File Name: 2.defaut_and_delete.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 三  2/23 15:14:07 2022
 ************************************************************************/

#include <iostream>
using namespace std;

class T {
    T() = delete;
};

class A {
public :
    A() = default;
    A(const A &) 
    void say() { cout << "hello haizei" << endl; }
    T t;

};

int main() {
    A a;
    return 0;
}

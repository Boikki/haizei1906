/*************************************************************************
	> File Name: 2.defaut_and_delete.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 三  2/23 15:14:07 2022
 ************************************************************************/

#include <iostream>
using namespace std;


class A {
public :
    A() : z(0) {}
    A(const A &a) {
        this->x = a.x;
        this->y = a.y;
        this->z = a.z;
    } 
    void say() { cout << "hello haizei" << endl; }

private :
    int x, y;
    const int z;
};

int main() {
    A a;
    return 0;
}

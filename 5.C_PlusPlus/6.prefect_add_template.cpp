/*************************************************************************
	> File Name: 6.prefect_add_template.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 一  3/ 7 09:36:41 2022
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    A(int x) : x(x) {}
    int operator+(const int y) {
        return this->x + y;
    }
    int operator+(const A &a) {
        return this->x + a.x;
    }
private :
    int x;
};
/*
template<typename T, typename U>
auto ((*((T *)0)) + (*((U *)0)) add(T &a, U &b) {
    return a + b;
}
*/
template<typename T, typename U>
auto  add(T &a, U &b) -> decltype(a + b) {
    return a + b;
}


int main() {
    int a = 3, b = 4;
    double c = 4.5;
    A d(2);
    cout << add<decltype(a  +b)>(a, b) << endl;
    //decltype 用来确定表达式的值，比如有一个exp的值我们不好确定，可以用decltype(exp()) x;
    //的形式声明一个同类型的x
    cout << add(a, b) << endl;
    cout << add(d, a) << endl;
    return 0;
}

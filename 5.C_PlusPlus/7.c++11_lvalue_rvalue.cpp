/*************************************************************************
	> File Name: 7.c++11_lvalue_rvalue.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Mon Mar 14 11:11:11 2022
 ************************************************************************/

#include <iostream>
using namespace std;

#define P(a) { \
    printf("judge : %s\n", #a); \
    func(a); \
}

void judge(int &a) {
    cout << "judge = left : " << a << endl;
    return ;
}
void judge(int &&a) {
    cout << "judge = right : " << a << endl;
    return ;
}
void func(int &a) {
    cout << "left value : " << a << endl;
    judge(a);
    return ;
}
void func(int &&a) {
    cout << "right value : " << a << endl;
    judge(move(a));
    return ;
}

int main() {
    int a, b = 12, c = 13;
    a = 123;
    P(a);
    P(b + c);
    P(12 + 13);
    P(++a);
    P(a++);
    return 0;
}

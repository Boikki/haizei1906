/*************************************************************************
	> File Name: 6.type_template.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 二  3/ 8 12:31:33 2022
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>
void my_swap(T &&a, T &&b) {
    typename remove_reference<T>::type c;
    c = a;
    a = b;
    b = c;
    return ;
}

template<typename T>
void add(T &&a, T &&b) {
    a += 3;
    b += 4;
    return ;
}

//void func(function<void(int &, int &)> f, int &a, int &b);

void func(void (*p)(int &, int &), int &a, int &b) {
    p(a, b);
    return ;
}

int main() {
    int a = 123, b = 456;
    my_swap(a, b);
    cout << a << " " << b << endl;
    my_swap(move(a), move(b));
    cout << a << " " << b << endl;
    func(add, a, b);
    cout << a << " " << b << endl;
    return 0;
}

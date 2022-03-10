/*************************************************************************
	> File Name: 6.bind_template.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 三  3/ 9 10:58:59 2022
 ************************************************************************/

#include <iostream>
using namespace std;

void func(int x, int y, int z) {
    cout << x + y << " is a number. " << endl;
    cout << "z " << z << endl;
    return ;
}

struct A {
    const void say() {
        cout << this << " : saying" << endl;
        return ;
    }
    void run() {
        cout << "run" << endl;
    }
};

void count_function_times(function<void()> &p, int &cnt) {
    p();
    cnt++;
    return ;
}

int main() {
    function<void(int, int)> f = bind(func, 123, placeholders::_2, placeholders::_1);
    f(100, 101);
    f(200, 201);
    A a;
    cout << &a << endl;
    function<void()> f2 = bind(&A::say, ref(a));
    f2();
    function<void()> f3 = bind(&A::run, ref(a));
    int cnt = 0;
    function<void()> f4 = bind(count_function_times, ref(f3), ref(cnt));
    for (int i = 0; i < rand() % 10; i++) {
        f4();
    }
    cout << cnt << endl;
    return 0;
}

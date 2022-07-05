/*************************************************************************
	> File Name: main.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Fri May  6 16:39:24 2022
 ************************************************************************/

#include "thread_pool.h"
using std::cin;
using std::cout;
using std::endl;

void foo(int x, int &y) {
    y += 2;
    cout << x << y << endl;
}
int main() {
    int n = 123;
    haizei::Task t(foo, 1, std::ref(n));
    t.run();
    cout << n << endl;
    return 0;
}

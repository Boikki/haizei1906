/*************************************************************************
	> File Name: 7.c++11_constexpr.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Sat Mar 12 10:53:18 2022
 ************************************************************************/

#include <iostream>
using namespace std;

constexpr int add(int x) {
    return x * 3;
}

struct ClassA {
    constexpr ClassA(int x, int y) : x(x), y(y) {}
    int x, y;
};
int main() {

    int n;
    cin >> n;
    const int x = 1 + n;
    constexpr int y = 1;
    const int z = 1 + add(6);
    constexpr int w = 1 + add(6);
    cout << x << y << endl;
    constexpr ClassA a(1, 3);
}

/*************************************************************************
	> File Name: 185.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Sat Jun 18 15:49:02 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int fib(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}
int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

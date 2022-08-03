/*************************************************************************
	> File Name: 4.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 六  7/30 12:53:30 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 28657
#define MAX_M 46368
int reverse_fib(int n, int m) {
    if (n == 0) return 0;
    cout << m - n << endl;
    return reverse_fib(m - n, n);
}

int main() {
    reverse_fib(MAX_N, MAX_M);
    return 0;
}

/*************************************************************************
	> File Name: 183.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Sat Jun 18 14:49:34 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int f(int x) {
    if (x <= 0) return 0;
    else if (x == 1) return 1;
    else if (x > 1 && (x % 2 == 0)) return 3 * f(x >> 1) - 1;
    else if (x > 1 && (x % 2)) return 3 * f((x + 1) / 2) - 1;
}

int main() {
    int x;
    cin >> x;
    cout << f(x) << endl;
    return 0;
}

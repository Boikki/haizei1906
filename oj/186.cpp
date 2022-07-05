/*************************************************************************
	> File Name: 186.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Sun Jun 19 10:54:46 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 100000

int n;
int a[MAX_N + 5];

int f(int x, int p) {
    if (p >= n) return x - 1;
    return f(x + 1, p + a[p]);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << f(1, 0) << endl;
    return 0;
}

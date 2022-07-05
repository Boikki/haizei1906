/*************************************************************************
	> File Name: 184.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Sat Jun 18 14:58:59 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int peach(int x, int n) {
    if (n == 1) return x;
    return peach((x + 1) << 1, n - 1);
}
int main() {
    int n;
    cin >> n;
    cout << peach(1, n) << endl;
    return 0;
}

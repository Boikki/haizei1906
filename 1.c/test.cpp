/*************************************************************************
	> File Name: test.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Wed Sep 22 20:38:46 2021
 ************************************************************************/

#include <iostream>
using namespace std;
int x;

int s(int n) {
    int sum = 0; 
    if(n == 0) sum = 0;
    else {
        cin >> x;
        sum = s(n - 1) + x;
    }
    cout << "n = " << n << ";sum = "  << sum << endl;
    return sum;
}

int main() {
    s(4);
    return 0;
}

/*************************************************************************
	> File Name: EP33.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 六 11/13 15:16:04 2021
 ************************************************************************/

#include <iostream>
using namespace std;


int gcd(int j, int i) {
    if (i == 0) return j;
    else return gcd(i, j % i);
}


int main() {
    int s = 1, t = 1;
    for (int i = 11; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (j / 10 == i % 10) {
                if (j % 10 * i == i / 10 * j) {
                    cout << i << "/" << j << endl;
                    s *= i / 10;
                    t *= j % 10;
                }
            }
        }
    }
    cout << s / gcd(t, s) << "/" << t / gcd(t, s) << endl;
    return 0;

}

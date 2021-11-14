/*************************************************************************
	> File Name: EP09.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日 11/14 19:41:20 2021
 ************************************************************************/

#include <stdio.h>
#include <math.h>


int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    for (int n = 1; n <= 33; n++) {
        for (int m = n + 1; m * m + n * n <= 1000; m++) {
            if (gcd(n, m) != 1) continue;
            int a = 2 * m * n;
            int b = m * m - n * n;
            int c = m * m + n * n;
            if (a + b + c == 1000) printf("%d\n", a * b * c);
            // ???????? 为什么要1000 % a啊，题上不是说的a + b + c == 1000吗
        }
    }
    return 0;
}

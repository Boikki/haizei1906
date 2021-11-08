/*************************************************************************
	> File Name: EP05.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Thu Oct 21 10:09:36 2021
 ************************************************************************/
//descripion 最小公倍数

#include <stdio.h>

int gcd(int a, int b) {
    if (!b) return a;
    if (!(a - b)) return a;
    return gcd(b, a % b);
    // return (b ? gcd(b, b % a) : a);
}

int main() {
    int ans = 1;
    for (int i = 1; i < 21; i++) {
        if (!(ans % i)) continue;
        ans = ans / gcd(ans, i) * i;

    }
    printf("%d", ans);


    return 0;
}
